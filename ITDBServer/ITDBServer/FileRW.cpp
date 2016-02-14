#include "stdafx.h"
#include "FileRW.h"


CFileRW::CFileRW()
{
}


CFileRW::~CFileRW()
{
}

bool CFileRW::Write(void *data, int size)
{
	/*std::ofstream file;
	file.open("file.txt", std::ios::binary);
	if (!file)
	{
		return false;
	}

	file.write(reinterpret_cast<char*>(data), size);
	file.close();*/
	FILE *f;
	f = fopen("file.txt", "wb");
	fwrite(data, size, 1, f);
	fclose(f);

	return true;
}

bool CFileRW::Open(void *data, int size)
{
	/*std::ifstream file;
	file.open("file.txt", std::ios::binary);
	int s;

	file.seekg(file.end);
	s = file.tellg();
	file.seekg(file.beg);

	file.read(reinterpret_cast<char*>(data), s);
	file.close();*/
	FILE *f;
	f = fopen("file.txt", "rb");
	fseek(f, SEEK_SET, SEEK_END);
	int s = ftell(f);
	fseek(f, 0, 0);
	fread(data, size, s, f);
	fclose(f);
	return true;
}