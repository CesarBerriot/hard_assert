#include "hard_assert.h"
#include <stdio.h>
#include <windows.h>
#include "message_formatter/message_formatter.h"

bool ha_require_user_interaction = true;

static void perform_argument_checks(char module_name[], char message[]);
static void report_invalid_setup(char message[]);

void ha_assert(bool condition, char module_name[], char message[])
{	perform_argument_checks(module_name, message);
	if(!condition)
		ha_abort(module_name, message);
}

void ha_abort(char module_name[], char message[])
{	perform_argument_checks(module_name, message);
	char * formatted_message = format_message(module_name, message);
	if(ha_require_user_interaction)
		MessageBoxA(NULL, formatted_message, "Unrecoverable Error", MB_OK | MB_ICONERROR | MB_TOPMOST);
	else
		fputs(formatted_message, stderr);
	abort();
}

static void perform_argument_checks(char module_name[], char message[])
{	if(!module_name)
		report_invalid_setup("NULL module name.");
	if(!message)
		report_invalid_setup("NULL message.");
}

static void report_invalid_setup(char message[])
{	ha_abort("hard_assert", message);
}
