/*
 *  cmd.c
 *  
 *
 *  Created by Pedro on 10/7/09.
 *
 */

#include <stdio.h>
#include <stdlib.h>

#include "cmd.h"


/* Just fill this structure and write you functions below */
const command_t commands[] = {
	{cmd_sos,  "sos",	"help"},
	{cmd_quit, "quit",	"sair"},
	{cmd_test, "test",	"<arg1> <arg2>   comando de teste"}
};

/*-------------------------------------------------------------------------+
 | Function: cmd_sos - provides a rudimentary help
 +--------------------------------------------------------------------------*/ 
int cmd_sos (int argc, char **argv)
{
	int i;
	
	puts(TITLEMSG);
	
	for (i=0; i < NCOMMANDS; i++)
		printf("%s %s\n", commands[i].cmd_name, commands[i].cmd_help);

	return 0; /* Do not leave command line */
}

/*-------------------------------------------------------------------------+
| Function: cmd_quit - leaves the command line
+--------------------------------------------------------------------------*/ 
int cmd_quit (int argc, char **argv)
{
	return 1; /* Leave command line */
}

/*-------------------------------------------------------------------------+
| Function: cmd_test - example
+--------------------------------------------------------------------------*/ 
int cmd_test (int argc, char** argv)
{
	int i;
	
	/* example -- display the arguments */
	for (i = 0; i < argc; i++)
		printf ("\nargv[%d] = %s", i, argv[i]);

	return 0; /* Do not leave command line */
}

