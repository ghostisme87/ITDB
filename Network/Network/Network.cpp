// Network.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "Network.h"


// This is an example of an exported variable
NETWORK_API int nNetwork=0;

// This is an example of an exported function.
NETWORK_API int fnNetwork(void)
{
    return 42;
}

// This is the constructor of a class that has been exported.
// see Network.h for the class definition
CNetwork::CNetwork()
{
    return;
}

