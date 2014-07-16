#pragma once
#include "winioctl.h"  //windows i/o control
#include "Ioctl.h"    //i/o control

class CEppIO
{
public:
	CEppIO(void);
	~CEppIO(void);
	//Reset the ports
	bool resetPorts(void);
	void poll();
public:
	CHARTOSHORT rval;
	CHARTOSHORT lval;

	bool leftSwitch0State;
	bool leftSwitch1State;
	bool rightSwitch0State;
	bool rightSwitch1State;
private:
	HANDLE hParIo;
	HANDLE hEppIo;
	DWORD BytesReturned;
	DWORD lBytesReturned;

public:
	void pollLeft(void);
	void pollRight(void);
	bool home(void);
};
