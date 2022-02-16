// dllmain.cpp : Implementation of DllMain.

#include "pch.h"
#include "framework.h"
#include "resource.h"
#include "IntelliDataHandlers_i.h"
#include "dllmain.h"
#include "xdlldata.h"

CIntelliDataHandlersModule _AtlModule;

class CIntelliDataHandlersApp : public CWinApp
{
public:

// Overrides
	virtual BOOL InitInstance();
	virtual int ExitInstance();

	DECLARE_MESSAGE_MAP()
};

BEGIN_MESSAGE_MAP(CIntelliDataHandlersApp, CWinApp)
END_MESSAGE_MAP()

CIntelliDataHandlersApp theApp;

BOOL CIntelliDataHandlersApp::InitInstance()
{
	if (!PrxDllMain(m_hInstance, DLL_PROCESS_ATTACH, nullptr))
		return FALSE;
	return CWinApp::InitInstance();
}

int CIntelliDataHandlersApp::ExitInstance()
{
	return CWinApp::ExitInstance();
}
