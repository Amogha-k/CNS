#include <stdio.h>
#include <ctype.h>
#include <string.h>

void encrypt()
{
    char plaintext[128];
    char key[16];
    printf("\nEnter the plaintext (up to 128 characters): ");
    scanf(" %s", plaintext); // Read input with spaces
    printf("Enter the key (up to 16 characters): ");
    scanf(" %s", key);

    printf("\nMessage : %s\n", plaintext);

    printf("Cipher Text: ");
    for (int i = 0, j = 0; i < strlen(plaintext); i++, j++)
    {
        if (j >= strlen(key))
        {
            j = 0;
        }
        int shift = toupper(key[j]) - 'A';
        int curr = toupper(plaintext[i]) - 'A';
        char encryptedChar = ((curr + shift) % 26) + 'A';
        printf("%c", encryptedChar);
    } printf("\n");
}

void decrypt()
{
    char ciphertext[128];
    char key[16];
    printf("\nEnter the ciphertext: ");
    scanf(" %s", ciphertext);
    printf("Enter the key: ");
    scanf(" %s", key);

    printf("\nDeciphered Text: ");
    for (int i = 0, j = 0; i < strlen(ciphertext); i++, j++)
    {
        if (j >= strlen(key))
        {
            j = 0;
        }
        int shift = toupper(key[j]) - 'A';
        int curr = toupper(ciphertext[i]) - 'A';
        char decryptedChar = ((curr - shift + 26) % 26) + 'A';
        printf("%c", decryptedChar);
    }
    printf("\n");
}

int main()
{
    encrypt();
    decrypt();

    return 0;
}