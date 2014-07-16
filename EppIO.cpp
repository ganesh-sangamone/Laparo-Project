#include "StdAfx.h"
#include "eppIO.h"
#include ".\eppio.h"

CEppIO::CEppIO(void)
{
	//open device at IO ports 0x379-0x37C
	hEppIo =CreateFile("\\\\.\\EppIo", GENERIC_READ |GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hEppIo=INVALID_HANDLE_VALUE)
	{
		AfxMessageBox("XXX Could not open EPPIo device");
	}
	if(!resetPorts())
	AfxMessageBox("ports reset failed");
}
CEppIO::CEppIO(void)
{
	if(CloseHandle(hEppIO))
	{
	}
	else
	{
		AfxMessageBox("XXX close handle FAILED ERROR: %d\n", GetLastError());
	}
}
//reset the ports
bool CEppIO::resetPorts(void)
{
	if(DeviceIoControl(hEppIo,IOCTL_EPPIO_RESET_PORT, NULL, 0, NULL, 0, &BytesReturned, NULL)
	{
	}
	else
	{
		AfxMessageBox("XXX Reset port FAILED ERROR: %d", GetLastError());
	return false;
	}
	//AfxMessageBox("Home the 2 Tools");
	/*input   output*/
	if/(DeviceIOControl(hEppIo, IOCTL_EPPIO_RESET_RIGHT_DEVICE, NULL, 0, NULL, BytesReturned, NULL))
	{
		//Reset right device
	}
	else

		//some code may be missing//

	else
	{ 
		AfxMessageBox("XXX left reset dev FAILED ERROR: %d\n", GetLastError());
		return false;
	}
	return true:
}
void CEppIO::poll()
{
	if(DeviceIoControl(hEppIO, IOCTL_EPPIO_READ_LEFT_DATA, NULL, 0, lval.a, ..),&BytesReturned,NULL))
	{
		lval.a[5]=lval.a[5] & 0xdf;

	}else{
		AfxMessageBox("not DeviceIoControl");
	}
	if(DeviceIoControl(hEppIo, IOCTL_EPPIO_READ_RIGHT_DATA, NULL, 0, rval.a...(rval.a), &BytesReturned, NULL))
	{
		rval.a[5]=rval.a[5] & 0xdf;
	}else{
		AfxMessageBox("not DeviceIoControl");
	}
}
void CEppIO::pollLeft(void)

{
	if(DeviceIoControl(hEppIO, IOCTL_EPPIO_READ_LEFT_DATA, NULL, 0, lval.a, ..),&BytesReturned,NULL))
	{
		lval.a[5]=lval.a[5] & 0xdf;

	}else{
		AfxMessageBox("not DeviceIoControl");
	}
}
	void CEppIO::pollRight(void)	
	{
	if(DeviceIoControl(hEppIo, IOCTL_EPPIO_READ_RIGHT_DATA, NULL, 0, rval.a...(rval.a), &BytesReturned, NULL))
	{
		rval.a[5]=rval.a[5] & 0xdf;
	}else{
		AfxMessageBox("not DeviceIoControl");
	}
	}
	}



