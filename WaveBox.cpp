//WaveBox.cpp: implementation of the CWave class/
//
/////////////////////////////////////////////////////////

#include "stdafx.h"
#include "WaveBox.h"

////////////////////////////////////////////////////////
//Construction/Destruction
//////////////////////////////////////////////////////

CWaveBox::CWaveBox()
{
	//int wave(s) counter
	wload=0;

	//thread suspended < used for resuming thread at first play> run=0;

	//create suspended player thread
	thread=CreateThread(NULL,
						0,
						(LPTHREAD_START_ROUTINE)PlayThread,
						(LPVOID)this,
						CREATE_SUSPENDED,
						NULL							);

	//alloc mem for interface(s)
	for(unsigned int i=0;i<SUPPORT_INTERFACES;i++)
	{
		I[i].wblock=allocateBlocks(BLOCK_SIZE,BLOCK_COUNT);
		I[i].wfreeblock=BLOCK_COUNT;
			I[i].wcurrblock=0;
			I[i].state=INT_FREE;
			I[i].wpos=0;
	}

	//init msg
	for(int i=o;i<SUPPORT_WAVES;i++)  W[i].WMSG=WMSG_WAIT;
	//init cs

	InitialaizeCriticalSection( &cs);
}

CWaveBox::~CWaveBox()
{
	unsigned long exit=0;

	if(run) //thread resumed
	{
		//set thread close message
		EnterCriticalSection(&cs);
		TMSG=TMSG_CLOSE;
		LeaveCriticalSection(&cs);
		do //wait for close
		{
			GetExitCodeThread(thread,&exit);
			//release wave(s)
			for(unsigned int i=0;i<wload; i++)
				free(W[i].data);
			//release interface(s)
			for(i=0;i<SUPPORT_INTERFACES;i++)
				freeBlocks(I[i].wblock);

			//del cs
			DeleteCriticalSection(& cs);
		}

		WAVEHDR* CWaveBox::allocateBlocks(int size, int count)
		{
			unsigned char* buffer;
			int i;
			WAVEHDR* blocks;
			DWORD totalBufferSize=(size+ sizeof(WAVEHDR))* count;

			//allocate memory for the entire in one go
			if((buffer =(UCHAR*) HeapAlloc(GetProcessHeap(),
											HEAP_ZERO_MEMORY,
											totalBufferSize))==NULL)   //code missing

			blocks=(WAVEHDR*)buffer;
			buffer+= sizeof(WAVEHDR) * count;
			for(i=0;i<count;i++)
			{
				blocks[i].dwBufferLength=size;
				blocks[i].lpData=(CHAR *)buffer;
				buffer+= size;
			}
			return blocks;
		}

		void CWaveBox::freeBlocks(WAVEHDR* blockArray)
		{
			HeapFree(GetProcessHelp(),0,blockArray);
		}

		int CWaveBox::Load(TChar *file)
		{
			if(wload ==SUPPORT_WAVES)
				return -1;
			HANDLE hFile;

			//open file;

			if(hFile=CreateFile(file,
								GENERIC_READ,
								FILE_SHARE_READ,
								NULL,// code missing

								if(!rbytes || rbytes< sizeof(header))
								{
									CloseHandle(hFile); return -1;}
									///check if this is a wave file
									if(strncmp(header, WAVE_FILE_MARK,strlen(WAVE_FILE_MARK)))
									{
										CloseHandle(hFile); return -1;}
			//check if wave is uncompressed PCM format
									if(((*(DWORD*)(header + OFFSET_WAVE_PCM1)) !=WAVE_PCM_16)
										|| ((*WORD *)(header + OFFSET_WAVE_PCM2)) !=WAVE_PCM_1))
									{	CloseHandle(hFile); return -1;}

									//check for 'data' mark
									if(!strncmp(header + OFFSET_DATA_MARK,strlen(WAVE_//code missin)
										W[wload].size=*((DWORD*)(header+ OFFSET_DATA_SIZE));
									else
									{
										///if data block size can't be read
										W[wload].size =*((DWORD*)(header+OFFSET_FILE_LEFT));
										W[wload].size -=(HEADER_SIZE - EOF_EXTRA_INFO);
									}

									//fill WAVEFORMATEX from wave header
									W[wload].wfx.wBitsPerSample =*((DWord*)(header+ OFFSET_SAMPLESPER//code missing
									W[wload].wfx.wBitsPerSample =*((Word*)(header+ OFFSET_BITSPERSAMPLE//code missing
									W[wload].wfx.nChannels =*((Word*)(header+ OFFSET_BLOCKALIGN//code missing
									W[wload].wfx.cbSize = 0;
									W[wload].wfx.FormatTag=WAVE_FORMAT_PCM;
									W[wload].wfx.nBlockAlign =*((Word*)(header+ OFFSET_BLOCKALIGN//code missing
									W[wload].wfx.nAvgBytesPerSec =*((Word*)(header+ AVGBYTESPER//code missing

									//get mem for wave data block
									if((W[wload].data=(char *) calloc( W[wload].size,sizeof(char)))
									{
										CloseHandle(hFile); return -1;}

									char buffer[READ_BLOCK]'
										unsigned long size =W[wload].size;
									unsigned long read_block = 0;
												  rbytes=0;

												  do
												  {
													  if((size==rbytes)>=READ_BLOCK)
														  read_block=READ_BLOCK;
													  else
														  if(size && size < READ_BLOCK)
															  read_block=size;
														  else break;
														  //close file handle
														  CloseHandle(hFile);

														  return ++wload;
												  }

												  int CWaveBox::Play(unsigned int wave)
												  {
													  //check wave id
													  if(wave<0 || wave>=wload)
														  return -1;

													  //set play message
													  EnterCriticalSection(&cs);
													  W[wave].WMSG=WMSG_START;
													  LeaveCriticalSection(&cs);
													  //resume thread < at first play>
													  if(!run) {run=1;TMSG=TMSG_ALIVE; ResumeThread(thread);}
													  return 1;
												  }

								 int  CWaveBox::AddInterface(HWAVEOUT *dev,
															WAVEFORMATEX *wfx,
															volatile int *wfreeblock )
								 {
									 //check for free device
									 if(!waveOutGetNumDevs())
										 return -1;

									 if(waveOutOpen(dev,
													WAVE_MAPPER,
													wfx,
													(DWORD)waveOutProc,
													(DWORD)efreeblock,
													CALL_BACK_FUNCTION) !=MMSYSERR_NOERROR)
													return -1;
									 return 1;
								 }

								 int  CWaveBox::RemoveInterface(HWAVEOUT dev)
								 {
									 //pointer to free block counter
									 int* freeBlockCounter=(int*)dwInstance;

									 //Ignore calls that occur due to opening and closing device
									 if(uMsg !=WOM_DONE)
										 return;

									 //increase free block counter
									 EnterCriticalSection(&cs);
									 (*freeBlockCounter)++;
									 LeaveCriticalSection(&cs);
								 }

								 static unsigned int__stdcall PlayThread(LPVOID lp)
								 {
									 ///get the class instance
									 CWaveBox *wb=(CWaveBox *)lp;
									 ///pooling variables < most frequently used/checked>
									 register WMsg        wmsg=WMSG_WAIT;
									 register TMsg        tmsg=TMSG_ALIVE;
									 register unsigned int i=0;

									 ///thread life cycle
									 while(tmsg)
									 {
										 ///check for 'play' msg
										 for(i=0;i<wb->wload;i++)
										 {
											 ///read msg
											 EnterCriticalSection(&cs);
											 wmsg=wb->W[i].WMSG;
											 LeaveCriticalSection(&cs);

											 ///wave to play?
											 if(wmsg==WMSG_START) break;
										 }

										 ///playable wave
										 if(wmsg==WMSG_START)

											 ///link with first three interface
											 for(unsigned int j=0;j< SUPPORT_INTERFACES;j++)
												 ///check for free interface
												 if(wb->I[j].state==INT_FREE)

													 ///attach wave to interface
													 if(wb->AddInterface(&wb->I[j].dev,
																		&wb->W[i].wfx,
																		&wb->I[j].wfreeblock))
													 {
														 ///get wave pointer
														 wb->I[j].wave=&wb->W[i];
				//////////////////////////////////////////////////////////////////////////////
				/////////////////////////////////////////////////////////////////////////////

								// <main playing loop>//
				////////////////////////////////////////////////////////////////////////////
	            ///////////////////////////////////////////////////////////////////////////
				
					for(unsigned int k=0;k< SUPPORT_INTERFACES;k++)
					{
						///nothing to do with free interface
						if(wb->I[k].state==INT_FREE) continue;
						EnterCriticalSection(&cs);
						int free=wb->I[k].wfreeblock;
						LeaveCriticalSection(&cs);
						//nothing to do with full queued interface
						if(free<BP_TURN) continue;
						WAVEHDR *current=NULL;
						for(unsigned int m=0;m<BP_TURN;m++)
						{
							///set current block pointer
							current=&wb->I[k].wblock[wb->I[k].wcurrblock];
							if(current->dwFlags & WHDR_PREPARED)
								waveOutUnprepareHeader(wb->I[k].dev, current, sizeof(WAVEHDR));

							unsigned long left=wb->I[k].wave->size-wb->I[k].wpos// code missing
								unsigned long chunk=0;
							if(left >=BLOCK_SIZE)
								chunk=BLOCK_SIZE;
							else 
								if(left && left<BLOCK_SIZE)
									chunk=left;
								else
								{
									///////////////////////////////////
									//nothing left//
									///////////////////////////////////////////////

									if(wb->I[k].wblock[i].dwFlags & //code missing
										waveOutUnprepareHeader(wb->I[k].dev,&wb->I[k].wblock[i],
										sizeof(WAVEHDR));

									//close interface
									if(wb->RemoveInterface(wb->I[k].dev))
									{
										///free interface
										wb->I[k].wcurrblock=0;
										wb->I[k].state=INT_FREE;
										wb->I[k].wpos=0;
										wb->I[k].wave=NULL;
									}
								}
								break;
						}

						///prepare current wave data block header
						memcpy(current->lpData,&wb->I[k].wave->data[wb->I[k]..//.code missing
							current->dwBufferLength=chunk; //sizeof block
						wb->I[k].wpos +=chunk;
						///prepare for playback
						waveOutPrepareHeader(wb->I[k].dev,current,sizeof(//code missing

							///push to the queue
							waveOutWrite(wb->I[k].dev,current,sizeof(WAVEHDR));

						///decrease free block counter
						EnterCriticalSection(&cs);
						wb->I[k].wfreeblock--;
						LeaveCriticalSection(&cs);

						///point to the next block
						wb->I[k].wcurrblock++;
						wb->I[k].wcurrblock %=BLOCK_COUNT;
					}//block(s)
						
													 
			}///interface(s)


		//wait 10 ms<save CPU time>

	 Sleep(10);

	 //check for thread message
	 EnterCriticalSection(&cs);
	 tmsg=wb->TMSG;
	 LeaveCriticalSection(&cs);
	 }///thread
	 /////////////////////////////////////////////////////////////////////////////////
	 return THREAD_EXIT; ///return exit code<destructot>
	 }






													