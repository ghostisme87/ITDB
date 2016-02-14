#pragma once
#include <fstream>
class CFileRW
{
public:
	CFileRW();
	~CFileRW();

	bool Open(void*, int size);
	bool Write(void*, int);
};

