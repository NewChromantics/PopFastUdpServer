#include "PopTemplate.h"


#if defined(TARGET_LUMIN) || defined(TARGET_ANDROID)
//const char* Platform::LogIdentifer = "PopTemplate";
#endif


#if defined(TARGET_WINDOWS)
BOOL APIENTRY DllMain(HMODULE /* hModule */, DWORD ul_reason_for_call, LPVOID /* lpReserved */)
{
	switch (ul_reason_for_call)
	{
		case DLL_PROCESS_ATTACH:
		case DLL_THREAD_ATTACH:
		case DLL_THREAD_DETACH:
		case DLL_PROCESS_DETACH:
			break;
	}
	
	//	hail mary cleanup for globals
	if ( ul_reason_for_call == DLL_PROCESS_DETACH)
	{
		//PopH264::Shutdown(true);
	}
	
	return TRUE;
}
#endif

#if !defined(TARGET_WINDOWS)
void __attribute__((destructor)) DllExit() 
{
}
#endif


__export int32_t PopTemplate_GetVersion()
{
	return 1;
}



__export void UnityPluginLoad(/*IUnityInterfaces*/void*)
{
}

__export void UnityPluginUnload()
{
}

