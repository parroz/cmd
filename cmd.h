/*
 *  cmd.h
 *  
 *
 *  Created by Pedro on 10/7/09.
 *
 */

#ifndef __cmd_h__
#define __cmd_h__



#define TITLEMSG	"Application Control Monitor"
#define INVALMSG	"Invalid command!"
#define PROMPT		"\nCmd> "
#define SOSMSG		"Type sos for help"

#define ARGVECSIZE	3	/* maximum number of arguments of your commands */
#define MAX_LINE	50	/* maximum input line length */
#define NCOMMANDS	3	/* number of commands that you have */
int cmd_quit (int, char** );
int cmd_sos  (int, char** );
int cmd_test (int, char** );



/* DO NOT CHANGE FROM THIS POINT */
typedef struct
{
	int (*cmd_fnct)();
	char *	cmd_name;
	char *	cmd_help;
} command_t;
extern const command_t commands[NCOMMANDS];


#endif /* __cmd_h__ */
