#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool only_digits(string s);
char rotate(char c, int key);

int main(int argc, string argv[])
{
    if (argc != 2 || !only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    int key = atoi(argv[1]);
    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        printf("%c", rotate(plaintext[i], key));
    }
    printf("\n");

    return 0;
}
    bool only_digits(string s)
    {
        for (int i = 0, n = strlen(s); i < n; i++)
        {
            if (!isdigit(s[i]))
            {
                return false;
            }
        }
        return true;
}
    char rotate(char c, int key)
    {
        if (isupper(c))
        {
            return (c - 'A' + key) % 26 + 'A';
        }
        else if (islower(c))
        {
            return (c - 'a' + key) % 26 + 'a';
        }
        else
        {
            return c;
        }
    }
