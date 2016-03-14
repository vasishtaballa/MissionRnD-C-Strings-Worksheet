/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>
#include <string.h>
void reverse_word(char *input, int start, int end);

void str_words_in_rev(char *input, int len)
{
	int i = 0, j = len - 1, k = 0;
	char temp;
	while (i < j)
	{
		temp = input[i];
		input[i] = input[j];
		input[j] = temp;
		i++;
		j--;
	}
	for (i = 0; i < len; i++)
	{
		if (input[i] == ' ')
		{
			reverse_word(input, k, i - 1);
			k = i + 1;
		}
		if (i == len - 1)
		{
			reverse_word(input, k, i);
			k = i + 1;
		}
	}
}

void reverse_word(char *input, int start, int end)
{
	int i = start, j = end;
	char temp;
	while (i < j)
	{
		temp = input[i];
		input[i] = input[j];
		input[j] = temp;
		i++;
		j--;
	}
}