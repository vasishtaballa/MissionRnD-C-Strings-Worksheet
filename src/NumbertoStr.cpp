/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include <stdio.h>
int string(int p, char *str, int afterdecimal);

void number_to_str(float number, char *str,int afterdecimal)
{
	int len = 0, p;
	p = (int)number;
	float f = number - (float)p;
	if (f < 0)
		f = f * (-1);
	int i = string(p, str, afterdecimal);
	if (afterdecimal >= 1)
	{
		str[i] = '.';
		while (afterdecimal > 0)
		{
			f = f * 10;
			afterdecimal--;
		}
		string((int)f, str + i + 1, afterdecimal);
	}
}

int string(int p, char *str, int afterdecimal)
{
	int rem, len = 0, i = 0, number;
	number = p;
	if (p > 0)
	{
		while (p != 0)
		{
			len++;
			p /= 10;
		}
		while (i < len)
		{
			rem = number % 10;
			number /= 10;
			str[len - (i + 1)] = rem + '0';
			i++;
		}
		str[i] = '\0';
	}
	else if (p < 0)
	{
		i = 1;
		p = p*(-1);
		number = number*(-1);
		while (p != 0)
		{
			len++;
			p /= 10;
		}
		while (i < len + 1)
		{
			rem = number % 10;
			number /= 10;
			str[len + 1 - (i)] = rem + '0';
			i++;
		}
		str[0] = '-';
		str[i] = '\0';
	}
	return i;
}