#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    // Check for the correct number of command-line arguments
    if (argc != 2)
    {
        printf("usage: ./caesar key\n");
        return 1;
    }

    // Check if the key consists of digits
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("usage: ./caesar key\n");
            return 1;
        }
    }

    // Convert key from string to integer
    int k = atoi(argv[1]) % 26; // Ensure key is within 0-25 range

    // Get plaintext input from user
    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");

    // Encrypt the plaintext
    for (int j = 0; j < strlen(plaintext); j++)
    {
        if (isupper(plaintext[j]))
        {
            // Encrypt uppercase letters
            printf("%c", (plaintext[j] - 'A' + k) % 26 + 'A');
        }
        else if (islower(plaintext[j]))
        {
            // Encrypt lowercase letters
            printf("%c", (plaintext[j] - 'a' + k) % 26 + 'a');
        }
        else
        {
            // Print non-alphabetic characters unchanged
            printf("%c", plaintext[j]);
        }
    }

    printf("\n"); // Print a newline after the ciphertext
    return 0; // Return success
}

