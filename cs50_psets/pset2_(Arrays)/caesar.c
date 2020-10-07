//This is a simple encipher code which takes a string (plain text) and taken some key(number) to encrypt with, gives out cipher text.

// Good for training your logical thinking as much as basic programming skills: writing loops, conditional statements, data types usage, returns, command line arguments.

#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    //checking the number of arg-s and validness of the "key" arg
    if (argc == 2)
    {
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (!(isdigit(argv[1][i])))
            {
                printf("Usage: ./Caesar key\n");
                return 1;
            }
        }
    }
    else
    {
        printf("Usage: ./Caesar key\n");
        return 1;
    }
    //converting argv[1] into a number
    int k;
    k = atoi(argv[1]);
    //getting an imput str (plain text) from a user and encrypting it
    string p = get_string("plaintext: ");
    //encrypted string should be of equal size, so for now I only assign as follows:
    string cipher = p;
    printf("ciphertext: ");
    for (int i = 0, n = strlen(cipher); i < n; i++)
    {
        if (islower(p[i]))
        {
            //we calculate cipher letter's number in the alphabet and then trasphorm it to char
            cipher[i] = (p[i] - 'a' + k) % 26 + 'a';
            printf("%c", cipher[i]);
        }
        else if (isupper(p[i]))
        {
            cipher[i] = (p[i] - 'A' + k) % 26 + 'A';
            printf("%c", cipher[i]);
        }
        //non-alphbetical char-s
        else
        {
            cipher[i] = p[i];
            printf("%c", cipher[i]);
        }
    }
    printf("\n");
    return 0;
}
