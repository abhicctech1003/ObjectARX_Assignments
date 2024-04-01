// Assignment1.cpp : Defines the initialization routines for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "arxHeaders.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// ~ main function
extern "C" AcRx::AppRetCode acrxEntryPoint(AcRx::AppMsgCode Msg, void* pkt)
{
	switch (Msg)
	{
	case AcRx::kInitAppMsg:
		acrxDynamicLinker->unlockApplication(pkt);
		acrxDynamicLinker->registerAppMDIAware(pkt);
		acutPrintf(L"\nLoading project...\n");
		break;

	case AcRx::kUnloadAppMsg:
		acutPrintf(_T("\nUnloading createLine project...\n"));
		acedRegCmds->removeGroup(_T("AUCommnds"));
		break;

	default:
		break;
	}
	return AcRx::kRetOK;
}
