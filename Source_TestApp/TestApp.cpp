#include "PopTemplate.h"
#include <iostream>
#include <thread>

int main()
{
	int Version[] = { PopTemplate_GetVersion_Major(), PopTemplate_GetVersion_Minor(), PopTemplate_GetVersion_Patch() };
	
	std::cout << "Version " << Version[0] << "." << Version[1] << "." << Version[2] << std::endl;
	
	int Port = 5432;
	auto Instance = PopFastUdpServer_AllocateInstance(Port);
	int DataTotal = 0;
	uint8_t Buffer[10*1024];
	
	for ( int i=0;	i<10*1000;	i++ )
	{
		auto PendingData = PopFastUdpServer_PeekData(Instance);
		std::cout << "Pending Data: " << PendingData << std::endl;
		
		if ( PendingData < 0 )
			break;
		if ( PendingData == 0 )
		{
			std::this_thread::sleep_for( std::chrono::milliseconds(500) );
			continue;
		}
		
		auto DataRead = PopFastUdpServer_PopData( Instance, Buffer, std::size(Buffer) );
		DataTotal += DataRead;
	
		//	report data read/per second
		std::cout << "Total Data: " << DataTotal << std::endl;
	}
	PopFastUdpServer_FreeInstance(Instance);
	
	return 0;
}

