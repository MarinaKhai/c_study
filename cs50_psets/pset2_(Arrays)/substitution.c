//Another enscryption program, with a bit more tricky key

//I practiced strings/arrays, iteration, general program design and logic

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    string key = argv[1];
    int repeated = 0;
    //if number of arguments is invalid
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    //in case of proper number of arguments
    else
    {
        if (strlen(key) != 26)
        {
            printf("Key should contain 26 characters.\n");
            return 1;
        }
        for (int i = 0; key[i] != '\0'; i++)
        {
            //check if there are any non-alpha char-s
            if (!(isalpha(key[i])))
            {
                printf("The key should only contain alphabetical characters\n");
                return 1;
            }
            //check if a letter occures more than ones
            repeated = 0;
            for (int letter = 0; key[letter] != '\0'; letter++)
            {
                if (key[i] == key[letter])
                {
                    repeated++;
                }
                if (repeated > 1)
                {
                    printf("Letter %c is repeated\n", key[letter]);
                    return 1;
                }
            }
        }
        //make all letters in key lowercase
        for (int i = 0, n = strlen(key); key[i] != 0; i++)
        {
            if (isupper(key[i]))
            {
                key[i] += 32;
            }
        }
    }
    string p = get_string("plaintext: ");
    string cipher = p;
    printf("ciphertext: ");
    //for alphabetical index
    int ai = 0;
    //make substitution from plain text to cipher text
    for (int i = 0, n = strlen(cipher); i < n; i++)
    {
        if (isupper(p[i]))
        {
            ai = p[i] - 65;
            cipher[i] = key[ai] - 32; //transphorm key's lowercase letters to uppercase ones in ciphertext
        }
        else if (islower(p[i]))
        {
            ai = p[i] - 97;
            cipher[i] = key[ai];
        }
        //for any non-alphabetical characters
        else
        {
            cipher[i] = p[i];
        }
        printf("%c", cipher[i]);
    }
    printf("\n");
    return 0;
}
