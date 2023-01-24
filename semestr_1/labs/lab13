/*
Есть ли во входных данных слово, состоящее только из гласных?
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#define VOWELS ((lu<<('a'-'a'))|(lu<<('e'-'a'))|(lu<<('i'-'a'))|(lu<<('o'-'a'))|(lu<<('u'-'a')))
int main(void)
{
    unsigned int lu = 1;
    char c;
    int k, k1, kol;
    kol = 0;
    k = 0;
    k1 = 0;
    while ((c = getchar()) != EOF) {
        if ((c != ' ') && (c != ',') && (c != '\n') && (c != '\t')) {
            c = tolower(c);
            if ((c >= 'a') && (c <= 'z')) {
                if (((VOWELS >> (c - 'a')) & 1u) != 0) {
                    k = k + 1;
                }
                k1 = k1 + 1;
            }
        }
        if ((c == ' ') || (c == ',') || (c == '\n') || (c == '\t') || (c == '\r')) {
            if ((k == k1) && (k1 != 0) && (k != 0)) {
                kol = 1;
            }
            k = 0;
            k1 = 0;
        }
    }
    if (kol == 1) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    return 0;
}
