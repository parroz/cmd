/***************************************************************************
| File: monitor.c
|
| Autor: Pedro Serra after from work by
|		 Carlos Almeida (IST), from work by Jose Rufino (IST/INESC), 
|        from an original by Leendert Van Doorn
| Data:  Nov 2002
***************************************************************************/
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <ctype.h>

#include "monitor.h"
#include "cmd.h"

int getline (char** argv, int argvsize)
{
	static char line[MAX_LINE];
	char *p;
	int argc;

	fgets(line, MAX_LINE, stdin);
	/* Break command line into an o.s. like argument vector,
	 i.e. compliant with the (int argc, char **argv) specification */
	
	for (argc = 0, p = line; (*line != '\0') && (argc < argvsize); p = NULL, argc++)
	{
		p = strtok(p, " \t\n");
		argv[argc] = p;
		if (p == NULL)
			return argc;
	}
	
	argv[argc] = p;
	return argc;
}

void monitor ()
{
	static char * argv[ARGVECSIZE+1];
	int argc, i;
	
	puts(TITLEMSG);
	puts(SOSMSG);
	
	for (;;)
	{
		printf(PROMPT);
		
		/* Reading and parsing command line */
		if ((argc = getline(argv, ARGVECSIZE)) > 0)
		{
			for (i = 0; i < NCOMMANDS; i++)
			{
				if (strcasecmp(argv[0], commands[i].cmd_name) == 0)
					break;
			}
			
			/* Executing commands */
			if (i < NCOMMANDS)
			{
				if (commands[i].cmd_fnct(argc, argv))
					return;
			}
			else
				puts(INVALMSG);
			
		} /* if getline */
		
	} /* forever */
}
