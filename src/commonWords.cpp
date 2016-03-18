/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".

INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/

#include <stdio.h>

#include <malloc.h>

char ** commonWords(char *str1, char *str2);
bool check(char temp[100], char *str2);
bool compare(char *temp1, char *temp);
void * copy(char *str1, char *str2);

#define SIZE 31

char ** commonWords(char *str1, char *str2) 
{
	if (str1 == NULL&&str2 == NULL)
		return NULL;
	int len1, len2, i, j, p = 0, k = 0;
	char **res = (char **)malloc(sizeof(char)* 31);
	for (i = 0; i < 31; i++)
		res[i] = (char *)malloc(sizeof(char)* 31);
	char *temp = (char *)malloc(sizeof(temp)* 31);
	for (len1 = 0; str1[len1] != '\0'; len1++);
	for (len2 = 0; str2[len2] != '\0'; len2++);
	for (i = 0; str1[i] != '\0'; i++)
	{
		if (str1[i] == ' ' || str1[i] == '\0')
		{
			temp[p] = '\0';
			if (check(temp, str2))
			{
				copy(res[k], temp);
				k++;
			}
			p = 0;
		}
		else
		{
			temp[p] = str1[i];
			p++;
		}
	}
	temp[p] = '\0';
	if (check(temp, str2))
	{
		copy(res[k], temp);
		k++;
	}
	for (i = 0; i < k; i++)
		puts(res[i]);
	if (k == 0)
		return NULL;
	else
		return res;
}

bool check(char *temp, char *str2)
{
	if (temp[0] == '\0')
		return false;
	int i, p = 0, len;
	char *temp1;
	temp1 = (char *)malloc(sizeof(char)* 31);
	for (len = 0; temp[len] != '\0'; len++);
	for (i = 0; str2[i] != '\0'; i++)
	{
		if (str2[i] == ' ' || str2[i] == '\0')
		{
			temp1[p] = '\0';
			if (compare(temp1, temp))
				return true;
			p = 0;
		}
		else
		{
			temp1[p] = str2[i];
			p++;
		}
	}
	temp1[p] = '\0';
	if (compare(temp1, temp))
		return true;
	return false;
}

bool compare(char *temp1, char *temp)
{
	int i = 0;
	while (temp[i] != '\0')
	{
		if (temp[i] != temp1[i])
			return false;
		i++;
	}
	if (temp1[i] != '\0')
		return false;
	else
		return true;
}

void * copy(char *str1, char *str2)
{
	int i;
	for (i = 0; str2[i] != '\0'; i++)
	{
		str1[i] = str2[i];
	}
	str1[i] = '\0';
	return str1;
}
