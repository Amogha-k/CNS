#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(int key, char *pt, char *ct) {
    int line, i, length = strlen(pt), j = 0, k = 0, skip;
    for (line = 0; line < key - 1; line++) {
        skip = 2 * (key - line - 1);
        k = 0;
        for (i = line; i < length;) {
            ct[j] = pt[i];
            i += (line == 0 || k % 2 == 0) ? skip : 2 * (key - 1) - skip;
            j++;
            k++;
        }
    }
    // Loop for the last line
    for (i = line; i < length; i += 2 * (key - 1)) {
        ct[j++] = pt[i];
    }
    ct[j] = '\0'; // Null-terminate the cipher text
}

void decrypt(int key, char *ct, char *pt) {
    int line, i, length = strlen(ct), j, k = 0, skip;
    for (line = 0; line < key - 1; line++) {
        skip = 2 * (key - line - 1);
        j = 0;
        for (i = line; i < length;) {
            pt[i] = ct[k++];
            i += (line == 0 || j % 2 == 0) ? skip : 2 * (key - 1) - skip;
            j++;
        }
    }
    // Loop for the last line
    for (i = line; i < length; i += 2 * (key - 1)) {
        pt[i] = ct[k++];
    }
    pt[length] = '\0'; // Null-terminate the plain text
}

int main() {
    char pt[100];
    int key;
    printf("Enter the text to encrypt: ");
    scanf(" %[^\n]", pt); // Read up to 99 characters to avoid buffer overflow
    printf("Enter the key: ");
    scanf("%d", &key);
    
    char *ct = malloc(strlen(pt) + 1);
    char *res = malloc(strlen(pt) + 1);
    
    if (ct == NULL || res == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    
    encrypt(key, pt, ct);
    decrypt(key, ct, res);
    
    printf("Original text: %s\nCipher text: %s\nDecrypted text: %s\n", pt, ct, res);
    
    free(ct);
    free(res);
    return 0;
}
