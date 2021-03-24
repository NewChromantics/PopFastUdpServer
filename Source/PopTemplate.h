#pragma once

/*
	gr: this header should be C
	it probably isn't strict C at the moment, but no classes, namespaces etc.
*/

#include <stdint.h>


#if !defined(__export)

#if defined(_MSC_VER) && !defined(TARGET_PS4)
#define __export			extern "C" __declspec(dllexport)
#else
#define __export			extern "C"
#endif

#endif



__export int32_t			PopTemplate_GetVersion_Major();
__export int32_t			PopTemplate_GetVersion_Minor();
__export int32_t			PopTemplate_GetVersion_Patch();

__export int32_t			PopFastUdpServer_AllocateInstance(int32_t ListenPort);
__export void				PopFastUdpServer_FreeInstance(int32_t Instance);
__export int32_t			PopFastUdpServer_PeekData(int32_t Instance);
__export int32_t			PopFastUdpServer_PopData(int32_t Instance,uint8_t* Buffer,int32_t BufferSize);
