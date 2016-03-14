/*
OVERVIEW: Given a string, remove all spaces in it.
E.g.: Input: "abd scd". Output: "abdscd"

INPUTS: A string.

OUTPUT: Return string after removing spaces.

ERROR CASES: Return '\0' for invalid inputs.

NOTES: Don't create new string.
*/
#include<stdio.h>

char removeSpaces(char *str) 
{
	if (str == NULL)
		return '\0';
	if (str == "")
		return '\0';
	int i, len, p = 0;
	for (len = 0; str[len] != '\0'; len++)
	{
		if (str[len] != ' ')
			str[p++] = str[len];
	}
	str[p] = '\0';
	return '\0';
}