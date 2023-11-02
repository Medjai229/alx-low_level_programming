#include "main.h"
#include <stdio.h>
#include <string.h>

/**
 * _isdigit - checks if character is digit
 * @c: the character to check
 *
 * Return: 1 if digit, 0 otherwise
 */

int _isdigit(int ch) {
    return (ch >= '0' && ch <= '9');
}

/**
 * _strlen - returns the length of a string
 * @s: the string whose length to check
 *
 * Return: integer length of string
 */
int _strlen(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}

/**
 * multiply - multiply two big number strings
 * @str1: the first big number string
 * @str2: the second big number string
 *
 * Return: the product big number string
 */
char *multiply(char *str1, char *str2) {
    int l1 = _strlen(str1);
    int l2 = _strlen(str2);
    char *res = malloc(l1 + l2 + 1);

    if (res == NULL) {
        printf("Error\n");
        exit(98);
    }

    for (int i = 0; i < l1 + l2; i++) {
        res[i] = '0';
    }
    res[l1 + l2] = '\0';

    for (int i = l1 - 1; i >= 0; i--) {
        if (!_isdigit(str1[i])) {
            free(res);
            printf("Error\n");
            exit(98);
        }

        int a = str1[i] - '0';
        int carry = 0;

        for (int j = l2 - 1; j >= 0; j--) {
            if (!_isdigit(str2[j])) {
                free(res);
                printf("Error\n");
                exit(98);
            }

            int b = str2[j] - '0';
            int product = (res[i + j + 1] - '0') + a * b + carry;
            res[i + j + 1] = (product % 10) + '0';
            carry = product / 10;
        }

        res[i] += carry;
    }

    while (*res == '0' && *(res + 1) != '\0') {
        res++;
    }

    return res;
}

/**
 * main - multiply two big number strings
 * @argc: the number of arguments
 * @argv: the argument vector
 *
 * Return: Always 0 on success.
 */
int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Error: Usage: %s <number1> <number2>\n", argv[0]);
        return 1;
    }

    char *result = multiply(argv[1], argv[2]);

    if (*result == '\0') {
        putchar('0');
    } else {
        printf("%s\n", result);
    }

    free(result);

    return 0;
}
