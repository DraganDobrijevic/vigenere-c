#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

string cl26[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};
string cu26[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};

int main(int argc, string argv[])
{
    while (argc <= 1 || argc > 2)
    {
        printf("Usage: ./vigenere keyword\n");
        return 1;
    }

    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("Usage: ./vigenere keyword\n");
            return 1;
        }
    }
    
    string plaintext = get_string("plaintext:  ");
    printf("ciphertext: ");
    
    int dn = strlen(argv[1]);
    int j = 0;
    int k;
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        
        if (isupper(plaintext[i]))
        {
            int x = argv[1][j];
            if (isupper(argv[1][j]))
            {
                k = argv[1][j] - 65; 
            }
            else
            {
                k = argv[1][j] - 97; 
            }
            int c = (plaintext[i] - 65 + k) % 26;
            printf("%s", cu26[c]);
            if (j < dn - 1)
            {
                j++;
            }
            else
            {
                j = 0;
            }
        }
        else if (islower(plaintext[i]))
        {
            if (isupper(argv[1][j]))
            {
                k = argv[1][j] - 65; 
            }
            else
            {
                k = argv[1][j] - 97; 
            }
           
            int c = (plaintext[i] - 97 + k) % 26;
            printf("%s", cl26[c]);
            
            if (j < dn - 1)
            {
                j++;
            }
            else
            {
                j = 0;
            }
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }

    printf("\n");  
}
