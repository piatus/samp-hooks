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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Hooks.h"

#include "amx/amx.h"
#include "plugincommon.h"


PLUGIN_EXPORT unsigned int PLUGIN_CALL Supports() 
{
	return SUPPORTS_VERSION | SUPPORTS_AMX_NATIVES;
}

PLUGIN_EXPORT bool PLUGIN_CALL Load(void **ppData) 
{
	pAMXFunctions = ppData[PLUGIN_DATA_AMX_EXPORTS];
	logprintf = (logprintf_t)ppData[PLUGIN_DATA_LOGPRINTF];

	logprintf("Callback hook's by mrdrifter loaded");
	return true;
}

PLUGIN_EXPORT void PLUGIN_CALL Unload() 
{
	logprintf("Callback hook's by mrdrifter unloaded");
	
	pAMXFunctions = NULL;
	logprintf = NULL;
}
cell AMX_NATIVE_CALL hook_CallHook(AMX* amx, cell* params)
{

	int i = (int)((params[0] / sizeof(cell)));
	int idx = 0;
	int len = NULL;
	cell amx_ret = 1;
	int numstr = 0;
	cell  addr2[16] = { NULL };
	cell *addr[2] = { NULL, NULL };
	char dcallback[32] = "H";
	char* data = NULL;

	 
	AMX_HEADER *hdr = (AMX_HEADER *)amx->base;

	amx_GetAddr(amx, params[1], &addr[0]);
	amx_StrLen(addr[0], &len);

	if (!len || !addr[0] || ((data) = (char*)alloca((len + 1) * sizeof(*(data)))) == NULL) return -1;

	amx_GetString((char*)(data), addr[0], sizeof(*(data))>1, len + 1);
	#if defined WIN32 || defined _WIN32 || defined __WIN32__
		strcat_s(dcallback, sizeof(dcallback), data);
	#else
		strcat(dcallback, data);
	#endif

	for (int idx = 0, num = (hdr->natives - hdr->publics) / hdr->defsize; idx < num; ++idx)
	{
		if (strpos(reinterpret_cast<char*>(amx->base
			+ reinterpret_cast<AMX_FUNCSTUBNT*>(hdr->publics
			+ amx->base)[idx].nameofs), dcallback) >= 1)
		{
			i = (int)((params[0] / sizeof(cell)));
			if (i > 2)
			{

				for (; i >= 2; i -= 2)
				{

					amx_GetAddr(amx, params[i - 1], &addr[0]);
					amx_GetAddr(amx, params[i], &addr[1]);

					if (addr[0] && params[i])
					{
						switch (*addr[0])
						{
						case H_BOOL:
							amx_Push(amx, static_cast<cell>((*((bool*)*&addr[1]))));
							break;
						case H_INT:
							amx_Push(amx, static_cast<cell>(*addr[1]));
							break;
						case H_FLOAT:
							amx_Push(amx, static_cast<cell>(amx_ftoc(*addr[1])));
							break;
						case H_STRING:

							int
								ret = NULL;
							len = NULL,
							data = NULL;

							amx_StrLen(addr[1], &len);
							if (!len || !addr[1] || ((data) = (char*)alloca((len + 1) * sizeof(*(data)))) == NULL) amx_PushString(amx, &addr2[numstr], NULL, "", NULL, NULL);
							else
							{
								amx_GetString((char*)(data), addr[1], sizeof(*(data))>1, len + 1);
								amx_PushString(amx, &addr2[numstr], NULL, data, NULL, NULL);
							}
							numstr++;

							break;

						}
					}
				}
			}
		
			amx_Exec(amx, &amx_ret, idx);

			while (numstr>0) amx_Release(amx, addr2[(numstr--, numstr)]);

			if (!amx_ret) return 0;
		}
	}

	return amx_ret;
}

cell AMX_NATIVE_CALL hook_CallLocalFunction(AMX* amx, cell* params)
{

	int i = (int)((params[0] / sizeof(cell)));
	int idx = 0;
	int len = NULL;
	cell amx_ret = 1;
	int numstr = 0;
	cell  addr2[16] = { NULL };
	cell *addr[2] = { NULL, NULL };
	char* data = NULL;


	AMX_HEADER *hdr = (AMX_HEADER *)amx->base;

	amx_GetAddr(amx, params[1], &addr[0]);
	amx_StrLen(addr[0], &len);

	if (!len || !addr[0] || ((data) = (char*)alloca((len + 1) * sizeof(*(data)))) == NULL) return -1;

	amx_GetString((char*)(data), addr[0], sizeof(*(data))>1, len + 1);

	for (int idx = 0, num = (hdr->natives - hdr->publics) / hdr->defsize; idx < num; ++idx)
	{
		if (strcmp(reinterpret_cast<char*>(amx->base
			+ reinterpret_cast<AMX_FUNCSTUBNT*>(hdr->publics
			+ amx->base)[idx].nameofs), data) != -1)
		{
			i = (int)((params[0] / sizeof(cell)));
			if (i > 2)
			{

				for (; i >= 2; i -= 2)
				{

					amx_GetAddr(amx, params[i - 1], &addr[0]);
					amx_GetAddr(amx, params[i], &addr[1]);

					if (addr[0] && params[i])
					{
						switch (*addr[0])
						{
						case H_BOOL:
							amx_Push(amx, static_cast<cell>((*((bool*)*&addr[1]))));
							break;
						case H_INT:
							amx_Push(amx, static_cast<cell>(*addr[1]));
							break;
						case H_FLOAT:
							amx_Push(amx, static_cast<cell>(amx_ftoc(*addr[1])));
							break;
						case H_STRING:

							int
								ret = NULL;
							len = NULL,
								data = NULL;

							amx_StrLen(addr[1], &len);
							if (!len || !addr[1] || ((data) = (char*)alloca((len + 1) * sizeof(*(data)))) == NULL) amx_PushString(amx, &addr2[numstr], NULL, "", NULL, NULL);
							else
							{
								amx_GetString((char*)(data), addr[1], sizeof(*(data))>1, len + 1);
								amx_PushString(amx, &addr2[numstr], NULL, data, NULL, NULL);
							}
							numstr++;

							break;

						}
					}
				}
			}

			amx_Exec(amx, &amx_ret, idx);

			while (numstr>0) amx_Release(amx, addr2[(numstr--, numstr)]);
			return amx_ret;
		}
	}

	return -1;
}

cell AMX_NATIVE_CALL hook_GetVersion(AMX* amx, cell* params)
{
	return _VERSION;
}
 


AMX_NATIVE_INFO PluginNatives[] =
{
	{ "HOOKS_CallHook", hook_CallHook },
	{ "HOOKS_CallLocalFunction", hook_CallLocalFunction },
	{ "HOOKS_GetVersion", hook_GetVersion },
	{ 0, 0 }
};

PLUGIN_EXPORT int PLUGIN_CALL AmxLoad(AMX *amx)
{
	return amx_Register(amx, PluginNatives, -1);
}
PLUGIN_EXPORT int PLUGIN_CALL AmxUnload(AMX *amx)
{
	return AMX_ERR_NONE;
}
int strpos(char *haystack, char *needle)
{
	char *p = strstr(haystack, needle);
	if (p)
		return p - haystack;
	return 0;
}