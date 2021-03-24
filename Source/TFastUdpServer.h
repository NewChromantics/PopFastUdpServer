#pragma once

#include "SoySocket.h"

class TParams
{
public:
	uint16_t	mListenPort = 0;
};

class TFastUdpServer
{
public:
	TFastUdpServer(TParams Params);
	~TFastUdpServer();
	
	int32_t			GetPendingDataSize();
	int32_t			PopData(uint8_t* Buffer,int32_t BufferSize);
	
	SoySocket		mSocket;
};
