#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // check if there are two arguemnts, and second one is a positive integer
    if (argc == 2)
    {
        int n = strlen(argv[1]);

        for (int i = 0; i < n; i++)
        {
            if (!isdigit(argv[1][i]))
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }
        // printf("Success!\n");
    }
    else
    {
        puts("argument is missing");
        return 1;
    }

    // Get text from user to encrypt
    string plain_text = get_string("plaintext: ");

    int m = strlen(plain_text);
    int key = atoi(argv[1]);

    // check if key is over 26, if so, remove the full cycles of alphabet
    key = key % 26;

    // encrypyt the text
    for (int j = 0; j < m; j++)
    {
        if (isalpha(plain_text[j]))
        {
            // printf("Current letter: %c\n", plain_text[j]);
            int plain_text_as_number = plain_text[j];

            if (islower(plain_text[j]))
            {
                if (plain_text_as_number + key <= 122)
                {
                    plain_text_as_number += key;
                }
                else
                {
                    plain_text_as_number = 96 + ((plain_text_as_number + key) % 122); // 96 + (98 + 65) % 122 = 96 + 163 % 122 =
                }
            }
            else if (isupper(plain_text[j]))
            {
                if (plain_text_as_number + key <= 90)
                {
                    plain_text_as_number += key;
                }
                else
                {
                    plain_text_as_number = 64 + ((plain_text_as_number + key) % 90);
                }
            }
            plain_text[j] = plain_text_as_number;
        }
    }
    printf("ciphertext: %s\n", plain_text);
    return 0;
}