#include <stdio.h>
#include <string.h>
void encrypt(int a[3][3], unsigned int *c, unsigned int *d, int len) {
 int t, i, j, k = 0;
 for (k = 0; k < len; k += 3) {
 for (i = 0; i < 3; i++) {
 t = 0;
 for (j = 0; j < 3; j++) {
 t += a[i][j] * c[k + j];
 }
 d[k + i] = t % 26;
 }}}
void decrypt(int b[3][3], unsigned int *d, unsigned int *c, int len) {
 int t, i, j, k = 0;
 for (k = 0; k < len; k += 3) {
 for (i = 0; i < 3; i++) {
 t = 0;
 for (j = 0; j < 3; j++) {
 t += b[i][j] * d[k + j];
 }
 c[k + i] = t % 26;
 }}}
int main() {
 unsigned int a[3][3] = {{6, 24, 1}, {13, 16, 10}, {20, 17, 15}};
 unsigned int b[3][3] = {{8, 5, 10}, {21, 8, 21}, {21, 12, 8}};
 unsigned int c[100], d[100];
 char msg[100];
 int original_len, padded_len, i;
 printf("Enter the plaintext: ");
 scanf("%s", msg);
 original_len = strlen(msg);
 padded_len = original_len;
 while (padded_len % 3 != 0) {
 msg[padded_len] = 'X';
 padded_len++;
 }
 msg[padded_len] = '\0';
 for (i = 0; i < padded_len; i++)
 c[i] = msg[i] - 65;
 encrypt(a, c, d, padded_len);
 printf("\nEncrypted cipher text: ");
 for (i = 0; i < padded_len; i++) 
 printf("%c", d[i] + 65);
 decrypt(b, d, c, padded_len);
 printf("\nDecrypted cipher text: ");
 for (i = 0; i < original_len; i++) 
 printf("%c", c[i] + 65);
 printf("\n");
 return 0;
}