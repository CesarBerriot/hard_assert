extern "C" {
	#include "message_formatter.h"
}
#include <string>
#include <sstream>

char * format_message(char application_name[], char message[])
{	static thread_local std::string result;
	result = (std::stringstream() << application_name << " unrecoverable error : '" << message << "'").str();
	return (char*)result.data();
}
