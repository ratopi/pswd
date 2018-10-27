/*
pswd.cc -- Generates passwords
by Ralf Th. Pietsch

Version 1.0

Create it with: gcc pswd.cc -o pswd

Copyright (C) 1995 Ralf Th. Pietsch

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

Contact:
Ralf Th. Pietsch <pietsch@iap.uni-frankfurt.de>
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define Number "0123456789"
#define Alpha "abcdefghijklmnopqrstuvwxyz"
#define Caps "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define Extra "!$%&/()=?*+'#;:,._-<>"

void printOne (const char symbols[])
{
	putchar (symbols[(long) ((random () * (float) strlen (symbols)) / RAND_MAX)]);
}

void printPasswordChar (char ch)
{
	switch (ch)
	{
	case 'n':
		printOne (Number);
		break;
	case 'a':
		printOne (Alpha);
		break;
	case 'A':
		printOne (Alpha Caps);
		break;
	case '+':
		printOne (Extra);
		break;
	case 'x':
		printOne (Number Alpha);
		break;
	case 'X':
		printOne (Number Alpha Caps);
		break;
	case 'y':
		printOne (Number Alpha Extra);
		break;
	case 'Y':
		printOne (Number Alpha Caps Extra);
		break;
	default:
		putchar (ch);
	}
}

void printPassword (char muster[])
{
	char *c;

	c = muster;
	while (*c != 0)
		printPasswordChar (*c++);
}

main (int argc, char *argv[])
{
	int i, n;

	srandom (time (0));

	if (argc < 2 || argc > 3)
	{
		printf ("Usage: %s <pattern> [number]\n", argv[0]);
		printf ("\n"
			"Please give a password pattern.\n"
			"<pattern> is a combination of the following letters:\n"
			"n: A digit\n"
			"a: A lowercase character\n"
			"A: A lowercase or uppercase character\n"
			"+: A Symbol\n"
			"x: A digit or a lowercase character\n"
			"X: A digit or a lowercase or uppercase character\n"
			"y: A digit or a lowercase character or a symbol\n"
			"Y: A digit or a lowercase or uppercase character or a symbol\n"
			"Letters which are not on this list will just printed.\n"
			"\n"
			"For beginning try 'pswd XXXXXX'.\n"
			"\n"
			"pswd version 1, Copyright (C) 1995 by Ralf Th. Pietsch\n"
			"pswd comes with ABSOLUTELY NO WARRANTY.\n"
			"This is free software, and you are welcome to redistribute it under\n"
			"the conditions of the GNU Public License.\n");
		return 1;
	}

	if (argc == 3)
	{
		n = atoi (argv[2]);
		if (n <= 0)
			n = 1;
	}
	else
		n = 1;

	for (i = 0; i < n; i++)
	{
		printPassword (argv[1]);
		putchar ('\n');
	}

	return 0;
}
