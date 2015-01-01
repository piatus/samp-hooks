#ifndef _HOOKS_H
#define _HOOKS_H

#if defined WIN32 || defined _WIN32 || defined __WIN32__
	#include <malloc.h> 
#else

	#if !defined alloca
		#define alloca __builtin_alloca
	#endif

#endif

#define amx_StrParam(amx,param,result)                                      \
    do {                                                                    \
      cell *amx_cstr_; int amx_length_;                                     \
      amx_GetAddr((amx), (param), &amx_cstr_);                              \
      amx_StrLen(amx_cstr_, &amx_length_);                                  \
      if (amx_length_ > 0 &&                                                \
          ((result) = (char*)alloca((amx_length_ + 1) * sizeof(*(result)))) != NULL) \
        amx_GetString((char*)(result), amx_cstr_, sizeof(*(result))>1, amx_length_ + 1); \
	        else (result) = NULL;                                                 \
	    } while (0)

int strpos(char *haystack, char *needle);

typedef void(*logprintf_t)(char* format, ...);

logprintf_t logprintf;
extern void *pAMXFunctions;

enum hooks_data
{
	H_NULL,
	H_INT,
	H_FLOAT,
	H_BOOL,
	H_STRING
};
#endif
