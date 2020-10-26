/* This program calculates the  number of wallpaper rolls needed for a room of user's size
(the average sizes of 1 window and a single-leaf door are taken into account and their 
areas are substracted*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h> // to round a real number

int main(int argc, char **argv)
{
    float walls; /* for calculating the total area of walls in a room excluding a door's and one window's areas*/
	
    if (argc != 3 && argc != 2)
    {
        printf("Enter your room's area in square meters (one number) or your room's width and length in meters (two numbes)");
        return 1;
    }
	if (argc == 2)
	{
		float sq = atof(argv[1]);
		printf("You will need %.0f rolls (including one spare roll).\n", round(2.7 * sq / (1.05 * 10)) + 1);
	}
	else if (argc == 3)
	{
        float h = atof(argv[1]); // string to float conversion
        float w = atof(argv[2]);
        walls = (h * 2.7 * 2) + (w * 2.7 * 2) - 2 - (1.2 * 1.2);
        printf("You'll need %.0f rolls (including one spare roll).\n" round(walls / (1.05 * 10)) + 1);
    }
	return 0;
}
