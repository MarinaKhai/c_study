//draw 2 adjacent pyramids with two-spaces gap between them using iteration

#include <stdio.h>
#include <cs50.h>

//function's prototype
void draw(int h);

int     main(void)
{
    int height = 1;
    int height = get_int("Height: ");
    reprompt until the user cooperate
    do
    {
        get_int("Height: ");
    }
    while (height <= 0);
    draw pyramid
    draw(height);
    return (0);    
}

//this is how we draw a pyramid of #'s
void draw(int h)
{
   for (int i = 0; i < h; i++)
   {
       //draw spaces before #'s to make the pyramid go left-to-right
       for (int k = 0; k < h - i - 1; k++)
       {
           printf(" ");
       }
       //draw #'s that is pyramid actual row of bricks
       for (int j = 0; j <= i; j++)
       {
           printf("#");
       }
       //draw a gap
       printf("  ");
       //draw second pyramid
       for (int j = 0; j <= i; j++)
       {
           printf("#");
       }
       for (int k = 0; k < h - i - 1; k++)
       {
            printf(" ");
       }
       printf("\n");
   }
}
