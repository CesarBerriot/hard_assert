#include "hard_assert.h"
#include <stdio.h>
#include <stdlib.h>
#include "message_formatter/message_formatter.h"

#ifdef WIN32
	#include <windows.h>
	#define user_notification(formatted_message) MessageBoxA(NULL, formatted_message, "Unrecoverable Error", MB_OK | MB_ICONERROR | MB_TOPMOST)
#else
	#define user_notification(formatted_message)															\
	fprintf																									\
	(	stderr,																								\
		"ha_assert warning : user interaction was required but isn't supported by the current platform.\n"	\
		"%s\n",																								\
		formatted_message																					\
	)
#endif

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
		user_notification(formatted_message);
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
