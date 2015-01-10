#include <Windows.h>
#include <cstdio>
#include <iostream>

class MemoryHandler
{
public:
	HANDLE hProc; //the actual process stored
	void CloseMemoryHandler(); //Close the MemoryHandler
	bool InitializeMemoryHandler(); //Initializes the Memory Handler
};
