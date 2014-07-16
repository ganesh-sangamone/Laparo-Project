// WaveBox.h: interface for the CWAve class

#if !defined(AFX_WAVEBOX_H__DE24CFE1_7501_4DA3_AF18_667A845AAE49_INCLUDED//code missing
#define AFX_WAVEBOX_H__DE24CFE1_7501_4DA3_AF18_667A845AAE49__INCLUDED_//code missing

#if _MSC_VER>1000
#pragma once
#endif //_MSC_VER >1000


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


by Zen '05
	///
	///																			WaveBox class v0.95
	///																			~~~~~~~~~~~~~~~~~~~
	///																			( PCM multiwave player)
	///																			play & joy
	///
	///
	///
	///

	///precompiler

#include <Windows.h>
#include <MMSystem.h>

	///wave & PCM marks

#define WAVE_FILE_MARK			"RIFF"
#define WAVE_HEAD_MARK			"WAVEfmt"
#define WAVE_DATA_MARK			"data"
#define WAVE_PCM_16				16
#define WAVE_PCM_1				1

	/////wfx header offsets
#define OFFSET_FILE_LEFT		4
#define OFFSET_HEAD_MARK		8
#define OFFSET_WAVE_PCM1		16
#define OFFSET_WAVE_PCM2		20
#define OFFSET_CHANNELS			22
#define OFFSET_SAMPLESPERSEC	24
#define OFFSET_AVGBYTESPERSEC	28
#define OFFSET_BLOCKALIGN		32
#define OFFSET_BITSPERSAMPLE    34
#define OFFSET_DATA_MARK		36
#define OFFSET_DATA_SIZE		40
#define OFFSET_WAVEDATA			44
#define HEADER_SIZE				OFFSET_WAVEDATA
#define EOF_EXTRA_INFO			60

	////MESSAGES	
	typedef unsigned int		WMsg;//wave messages
	typedef unsigned int		TMsg;//thread messages

#define  SUPPORT_INTERFACES		10  //predefined interface count

	///buffering
#define READ_BLOCK				8192 //read wave(file) block size
#define BLOCK_SIZE				8192 //queue block size
#define BLOCK_COUNT				20 //queue block count
#define BP_TURN					1 //blocks per turn

static CRITICAL_SECTION     cs;  //critical section

static unsigned int_stdcall PlayThread(LPVOID lp);
	thread
		static void CALLBACK waveOutProc(HWAVEOUT hWaveOut,
		prototype						
										UINT   uMsg
										DWORD  dwInstance
										DWORD  dwParam1,
										DWORD  dwParam2 );

	class CWaveBox
	{
		struct WAVE
		{
			char			*data; //Wave
			unsigned long	size;	//size
			WAVEFORMATEX	wfx;	//wfx
			WMsg			WMSG;   //{0,1} wait/play
		};

		struct INTERFACE
		{
			///interface
			HWAVEOUT    dev;		///device handle
			unsigned int state;		///{0,1} free/used

			///wave
			WAVE        *wave;		///current wave

			///wave interface

			unsigned long  wpos;  //current play position
			WAVEHDR*		wblock; //wave block

			volatile int wfreeblock; //free blocks left
			int          wcurrblock ///current block
		};

	public:
		///members
		INTERFACE              I[SUPPORT_INTERFACES];
		WAVE				   W[SUPPORT_WAVES];
		unsigned int			wload;
		TMsg					TMSG;

		//prototypes

		int Load(TCHAR   *file);
		int Play(unsigned int Wave);
		int RemoveInterface(HWAVEOUT dev);

	protected:

		HANDLE thread;
		unsigned int run;

		///prototypes
		WAVEHDR*  allocateBlocks(int size,int count);
		void freeBlocks(WAVEHDR* blockArray);
	};

#endif //!defined(AFX_WAVEBOX_H_DE24CFE1_7501_4DA3_AF18_667A845AAE49// Code missing
