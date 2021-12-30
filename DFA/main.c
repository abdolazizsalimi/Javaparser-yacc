#include <stdio.h>


void checked_both_even( int EE, int OE, int OO, int EO)
{
    char input;
    int state = 0 ;
    printf("Enter a string of a and b: ");
    while (1)
    {
        scanf("%c", &input);
        if (input == '\n')
            break;
        if ( (input != 'a') && (input != 'b') )
        {
            break;
        }
        if (state == 0 )
        {
            if (input == 'a' )
            {
                state = OO ;
            }
            else
            {
                state = OE ;
            }

        }
        else if(state == 1)
        {
            if (input == 'a' )
            {
                state = EO ;
            }
            else
            {
                state = EE ;
            }
        }
        else if (state==2)
        {
            if(input == 'a')
            {
                state = EE ;
            }
            else
            {
                state = EO ;
            }

        }
        else
        {
            if(input == 'a')
            {
                state = OE ;
            }
            else
            {
                state = OO ;
            }
        }
    };
    if (input == '\n')
    {
        if (state == EE )
            printf("Input accepted\n");
        else
            printf("Input rejected\n");
    }

}


void check_a_b(int A, int B, int C, int D, int E, int F )
{

    char input;
    int trap = 6;
    int state = 0 ;
    printf("Enter a string of a and b: ");

    while (1)
    {
        scanf("%c", &input);
        if (input == '\n')
            break;
        if ( (input != 'a') && (input != 'b') )
        {
            break;
        }
        if (state == 0 )
        {
            if (input == 'a' )
            {
                state = B ;
            }
            else
            {
                state = D ;
            }

        }
        else if(state == 1)
        {
            if (input == 'a' )
            {
                state = B ;
            }
            else
            {
                state = C ;
            }
        }
        else if (state==2)
        {
            if(input == 'a')
            {
                state = C ;
            }
            else
            {
                state = E ;
            }

        }
        else if (state == 3 )
        {
            if(input == 'a')
            {
                state = C ;
            }
            else
            {
                state = F ;
            }
        }
        else if (state == 4 )
        {
            if(input == 'a')
            {
                state = E ;
            }
            else
            {
                state = trap ;
            }

        }
        else if (state == 5)
        {
            if(input == 'a')
            {
                state = E ;
            }
            else
            {
                state = trap ;
            }
        }
        else
        {
            printf("input rejected dfa in trap ");
            break;
        }
    };
    if (input == '\n')
    {
        if (state == E )
            printf("Input accepted\n");
        else
            printf("Input rejected\n");
    }


}



int main(void)
{

    int EE=0, OE=1, OO=2, EO=3;
    int A = 0, B = 1, C = 2, D = 3, E = 4,F = 5;

//1.
   // checked_both_even(EE,OE,OO,EO);



//2.
  //  check_a_b(A,B,C,D,E,F);

        return 0 ;

}
