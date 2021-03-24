#include "PopTemplate.h"
#include "SoyDebug.h"
#include "PopFastUdpServer.h"
#include "TFastUdpServer.h"


namespace PopFastUdpServer
{
	std::map<int32_t,std::shared_ptr<TFastUdpServer>>	gInstanceMap;
	int32_t												gLastInstanceId = 1000;
	
	int32_t			AllocateInstance(TParams Params);
	void			FreeInstance(int32_t Instance);
	TFastUdpServer&	GetInstance(int32_t Instance);
}

int32_t SafeExec(std::function<int32_t()> Lambda,int32_t ErrorResult,const char* Context)
{
	try
	{
		return Lambda();
	}
	catch(std::exception& e)
	{
		std::Debug << Context << "Exception: " << e.what() << std::endl;
		return ErrorResult;
	}
	catch(...)
	{
		std::Debug << Context << "Unknown Exception." << std::endl;
		return ErrorResult;
	}
}


__export int32_t PopFastUdpServer_AllocateInstance(int32_t ListenPort)
{
	auto Run = [&]()
	{
		TParams Params;
		Params.mListenPort = ListenPort;
		return PopFastUdpServer::AllocateInstance(Params);
	};
	return SafeExec( Run, -1, __PRETTY_FUNCTION__ );
}

__export void PopFastUdpServer_FreeInstance(int32_t Instance)
{
	auto Run = [&]()
	{
		PopFastUdpServer::FreeInstance(Instance);
		return 0;
	};
	SafeExec( Run, 0, __PRETTY_FUNCTION__ );
}

__export int32_t PopFastUdpServer_PeekData(int32_t Instance)
{
	auto Run = [&]()
	{
		auto& TheInstance = PopFastUdpServer::GetInstance(Instance);
		return TheInstance.GetPendingDataSize();
	};
	return SafeExec( Run, -1, __PRETTY_FUNCTION__ );
}

__export int32_t PopFastUdpServer_PopData(int32_t Instance,uint8_t* Buffer,int32_t BufferSize)
{
	auto Run = [&]()
	{
		auto& TheInstance = PopFastUdpServer::GetInstance(Instance);
		return TheInstance.PopData(Buffer,BufferSize);
	};
	return SafeExec( Run, -1, __PRETTY_FUNCTION__ );
}

