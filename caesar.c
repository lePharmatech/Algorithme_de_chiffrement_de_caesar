#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// fonction de la boucle de chiffrement
void boucleChiffrement(string plaintext, int k);
int main(int argc, string argv[])
{
    // vérification de l'argument
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // ici je verifie voir si la valeur de l'argument est un entier(digit)
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    // Si la saisie de l'argument est bon
    // le décalage k
    int k = atoi(argv[1]);
    // printf("%i\n", k);

    // le massage clair entré par l'utilisateur
    string plaintext = get_string("plaintext:  ");

    // fonction de chiffrement
    boucleChiffrement(plaintext, k);

    // la valeur retourner si tout ce passe bien
    return 0;
}
// boucle de chiffrement
void boucleChiffrement(string plaintext, int k)
{
    printf("ciphertext: ");
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        if (isalpha(plaintext[i]))
        {
            if (isupper(plaintext[i]))
            {
                printf("%c", (plaintext[i] - 'A' + k) % 26 + 'A');
            }
            else if (islower(plaintext[i]))
            {
                printf("%c", (plaintext[i] - 'a' + k) % 26 + 'a');
            }
        }
        else
        {
            // s'il n'est pas alpha numerique
            printf("%c", plaintext[i]);
        }
    }

    printf("\n");
}
