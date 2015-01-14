/*
samp-hooks
Copyright (C) 2015, mrdrifter

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
( at your option ) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

<Pawno.pl>, <forum.sa-mp.com>, <4fun-serv.pl>;
*/

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

#define VERSION "1.2.3"
#define _VERSION 0x010203

#endif
