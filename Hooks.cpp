#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Hooks.h"

#include "amx\amx.h"
#include "plugincommon.h"


PLUGIN_EXPORT unsigned int PLUGIN_CALL Supports() 
{
	return SUPPORTS_VERSION | SUPPORTS_AMX_NATIVES;
}

PLUGIN_EXPORT bool PLUGIN_CALL Load(void **ppData) 
{
	pAMXFunctions = ppData[PLUGIN_DATA_AMX_EXPORTS];
	logprintf = (logprintf_t)ppData[PLUGIN_DATA_LOGPRINTF];

	logprintf("callhook");
	return true;
}

PLUGIN_EXPORT void PLUGIN_CALL Unload() 
{
	
}
cell AMX_NATIVE_CALL hook_CallHook(AMX* amx, cell* params)
{

	int i = (int)((params[0] / sizeof(cell)));
	int idx=0;
	int numstr=0;
	cell *addr[2] = { NULL };
	cell addr2[16] = { NULL };
	char * callback;
	char dcallback[32] = "H";

	AMX_HEADER *hdr = (AMX_HEADER *)amx->base;
	 
	amx_StrParam(amx, params[1], callback);

	if (callback == NULL) return 0;

	strcat_s(dcallback, sizeof(dcallback), callback);

	for (int idx = 0, num = (hdr->natives - hdr->publics) / hdr->defsize; idx < num; ++idx)
	{
		if (strpos(reinterpret_cast<char*>(amx->base
				+ reinterpret_cast<AMX_FUNCSTUBNT*>(hdr->publics
				+ amx->base)[idx].nameofs), dcallback) > 1)
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

								char * getstr;
								amx_StrParam(amx, params[i], getstr);

								if (getstr == NULL) getstr = " ";
								amx_PushString(amx, &addr2[numstr], NULL, getstr, NULL, NULL);
								
								numstr++;
								break;

							}
						

					}
				}
				amx_Exec(amx, 0, idx);
				while (numstr>0) amx_Release(amx, addr2[(numstr--, numstr)]);

			}
		}
	}

	return 1;
}
 


AMX_NATIVE_INFO PluginNatives[] =
{
	{ "HOOKS_CallHook", hook_CallHook },
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