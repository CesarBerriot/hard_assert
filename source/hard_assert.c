#include "hard_assert.h"
#include <string.h>
#include <stdio.h>
#include <windows.h>
#include "message_formatter/message_formatter.h"

bool ha_require_user_interaction = true;

static char * application_name;

static void application_name_check(void);
static void message_validity_check(char message[]);
static void report_invalid_setup(char message[]);

void ha_set_application_name(char name[])
{	if(!name)
		report_invalid_setup("NULL application name.");
	if(application_name)
		free(application_name);
	application_name = strdup(name);
}

void ha_assert(bool condition, char message[])
{	if(!condition)
		ha_abort(message);
}

void ha_abort(char message[])
{	application_name_check();
	message_validity_check(message);
	char * formatted_message = format_message(application_name, message);
	if(ha_require_user_interaction)
		MessageBoxA(NULL, formatted_message, "Unrecoverable Error", MB_OK | MB_ICONERROR | MB_TOPMOST);
	else
		fputs(formatted_message, stderr);
	abort();
}

static void application_name_check(void)
{	if(!application_name)
		report_invalid_setup("Application name hasn't been set.");
}

static void message_validity_check(char message[])
{	if(!message)
		report_invalid_setup("NULL message.");
}

static void report_invalid_setup(char message[])
{	ha_set_application_name("hard_assert");
	ha_abort(message);
}
