#include "3-calc.h"

/**
 * get_op_func - pointer to a function that performs an operation
 * 
 * @s: the operation
 * 
 * Return: a function that operates with two integers
 */

int (*get_op_func(char *s))(int, int)
{
    op_t ops[] = {
        {"+", op_add},
        {"-", op_sub},
        {"*", op_mul},
        {"/", op_div},
        {"%", op_mod},
        {NULL, NULL}
    };
    int i;

	for (i = 0; (ops[i].op[0] != s[0]) && i < 5; i++)
	{
		;
	}

	return (ops[i].f);
}
