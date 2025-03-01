#pragma once

#ifndef _WINDOWS_
	#error hard_assert requires windows.h to be included
#endif

#define ha_assert(condition, application_name, message) do { if(!(condition)) ha_abort(application_name, message); } while(0)
#define ha_abort(application_name, message) do { MessageBoxA(NULL, application_name " unrecoverable error : '" message "'", "Unrecoverable Error", MB_OK | MB_ICONERROR | MB_TOPMOST); abort(); } while(0)
