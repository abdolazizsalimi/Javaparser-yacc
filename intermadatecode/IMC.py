import sys, getopt, os
from enum import Enum
from collections import OrderedDict

line = 1
token = Token(None, None, None)
programName = ''
quadcode = list()
nextlabel = 0
nextTemp = 1
tempvars = dict()
inRepeat = []
exitRepeat = []
have_subprogram_or_function = False




def nextquad():
    return nextlabel

def genquad(op=None, x='_', y='_', z='_'):
    global nextlabel
    label = nextlabel
    nextlabel += 1
    newquad = Quad(label, op, x, y, z)
    quadcode.append(newquad)

def newtemp():
    global tmpvars, nextTemp
    temp = 'T_'+str(nextTemp)
    tempvars[temp] = None
    nextTemp += 1
    return temp

def emptylist():
    return list()

def makelist(label):
    newlist = list()
    newlist.append(label)
    return newlist

def merge(list1, list2):
    return list1 + list2

def backpatch(list, z):
    global quadcode
    for quad in quadcode:
        if quad.label in list:
            quad.res = z

def generate_int_code():
    for quad in quadcode:
        intFile.write(quad.tofile() + '\n')
    intFile.close()

def find_var_decl(quad):
    vars = dict()
    index = quadcode.index(quad) + 1
    while True:
        q = quadcode[index]
        if q.op == 'end_block':
            break
        if q.arg2 not in ('CV', 'REF', 'RET') and q.op != 'call':
            if isinstance(q.arg1, str) and not q.arg1.isdigit():
                vars[q.arg1] = 'int'
            if isinstance(q.arg2, str) and not q.arg2.isdigit():
                vars[q.arg2] = 'int'
            if isinstance(q.res, str):
                vars[q.res] = 'int'
        index += 1
    if '_' in vars:
        del vars['_']
    return OrderedDict(sorted(vars.items()))

def transform_decls(vars):
    retval = '\n\tint '
    for var in vars:
        retval += var + ', '
    if len(vars) > 0:
        return retval[:-2] + ';'
    else:
        return ''

def transform_to_c(quad):
    addlabel = True
    if quad.op == 'jump':
        retval = 'goto L_' + str(quad.res) + ';'
    elif quad.op in ('=', '<>', '<', '<=', '>', '>='):
        op = quad.op
        if op == '=':
            op = '=='
        elif op == '<>':
            op = '!='
        retval = 'if (' + str(quad.arg1) + ' ' + op + ' ' + \
            str(quad.arg2) + ') goto L_' + str(quad.res) + ';'
    elif quad.op == ':=':
        retval = quad.res + ' = ' + str(quad.arg1) + ';'
    elif quad.op in ('+', '-', '*', '/'):
        retval = quad.res + ' = ' + str(quad.arg1) + ' ' + \
            str(quad.op) + ' ' + str(quad.arg2) + ';'
    elif quad.op == 'out':
        retval = 'printf("%d\\n", ' + str(quad.arg1) + ');'
    elif quad.op == 'retv':
        retval = 'return (' + str(quad.arg1) + ');'
    elif quad.op == 'begin_block':
        addlabel = False
        if quad.arg1 == programName:
            retval = 'int main(void)\n{'
        else: # Should never reach else.
            retval = 'int ' + quad.arg1 + '()\n{'
        vars = find_var_decl(quad)
        retval += transform_decls(vars)
        retval += '\n\tL_' + str(quad.label) + ':'
    elif quad.op == 'call':
        # Should never reach this line.
        retval = quad.arg1 + '();'
    elif quad.op == 'end_block':
        addlabel = False
        retval = '\tL_' + str(quad.label) + ': {}\n'
        retval += '}\n'
    elif quad.op == 'halt':
        retval = 'return 0;' # change to exit() if arbitrary
                             # halt statements are enabled
                             # at a later time.
    else:
        return None
    if addlabel == True:
        retval = '\tL_' + str(quad.label) + ': ' + retval
    return retval

def generate_c_code_file():
    ceqFile.write('#include <stdio.h>\n\n')
    for quad in quadcode:
        tmp = transform_to_c(quad)
        if tmp != None:
            ceqFile.write(tmp + '\n')
    ceqFile.close()





def main(argv):
    # using a parser and passing it to 
    #      Intermediate Code        #
    #         Generation            #
    # parser
    return





if __name__ == "__main__":
    main(sys.argv[1:])