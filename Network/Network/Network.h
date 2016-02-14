// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the NETWORK_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// NETWORK_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef NETWORK_EXPORTS
#define NETWORK_API __declspec(dllexport)
#else
#define NETWORK_API __declspec(dllimport)
#endif

// This class is exported from the Network.dll
class NETWORK_API CNetwork {
public:
	CNetwork(void);
	// TODO: add your methods here.
};

extern NETWORK_API int nNetwork;

NETWORK_API int fnNetwork(void);
