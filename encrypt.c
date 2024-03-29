#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "encrypt.h"
/**************************************************************************
*   Turn char to int
*
*
*   inputs:
* - char c
*   outputs:
* - int
**************************************************************************/
int chartoasc(char c)
{
	int i = 0;
	i = c;
	return i;
}

/**************************************************************************
*  Do the substitution
*   inputs:
* - int
*   outputs:
* - int
**************************************************************************/
int xor(int i)
{
	int m = 27;
	int result = 0;
	if (59 == i || 100 == i)
	{
		return i;
	}
	result = i ^ m;
	return result;
}

/**************************************************************************
*   Turn int back to char
*
*   inputs:
* - int
*   outputs:
* - char
**************************************************************************/
char asctochar(int a)
{
	char c;
	c = a;
	return c;
}

/**************************************************************************
*   Encrypt the password
*
*   inputs:
* - const char* input, const unsigned int input_len, const unsigned int HASH_SIZE
*   outputs:
* - unsigned long
**************************************************************************/
unsigned long encrypt(const char* input, const unsigned int input_len, const unsigned int HASH_SIZE)
{
	char inputBuff[50];
	char cipherBuff[50];
	unsigned int i = 0;
	int asc = 0;
	char ch = 0;
	int x = 0;

	memset(inputBuff, 0, sizeof(inputBuff));
	memset(cipherBuff, 0, sizeof(cipherBuff));
	strcpy(inputBuff, input);
	for (i = 0; i < input_len; i++)
	{
		ch = inputBuff[i];
		asc = chartoasc(ch);
		x = xor (asc);
		cipherBuff[i] = asctochar(x);
	}
	cipherBuff[i] = '\0';

	char* hash = cipherBuff;

	unsigned long hash_value;
	for (hash_value = 0; *hash != '\0'; ++hash)
		hash_value = *hash + 31 * hash_value;

	/*
		Computes the size of hash required
		Perform typecast
	*/
	double size = pow(16, HASH_SIZE);
	char size_str[30];
	sprintf(size_str, "%f", size);

	/*Returns value mod the max size*/
	return (atol(size_str) <= 0) ? 0 : hash_value % atol(size_str);
}