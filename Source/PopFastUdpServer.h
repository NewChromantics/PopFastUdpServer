#pragma once


__export int32_t			PopFastUdpServer_AllocateInstance(int32_t ListenPort);
__export void				PopFastUdpServer_FreeInstance(int32_t Instance);
__export int32_t			PopFastUdpServer_PeekData(int32_t Instance);
__export int32_t			PopFastUdpServer_PopData(int32_t Instance,uint8_t* Buffer,int32_t BufferSize);

