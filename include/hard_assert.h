#pragma once

#include <stdbool.h>
#include <stdarg.h>

extern bool ha_require_user_interaction;

void ha_set_application_name(char[]);
void ha_assert(bool condition, char message[]);
void ha_abort(char message[]);