
#ifndef DEBUGGERAPP_H
#define DEBUGGERAPP_H

#include "mainframe.h"

#pragma comment(linker,"\"/manifestdependency:type='win32' \
	name='Microsoft.Windows.Common-Controls' version='6.0.0.0' \
	processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

class DebuggerApp : public CWinApp {
	MainFrame* main_frame;

public:
	~DebuggerApp();

	virtual BOOL InitInstance();
	virtual int ExitInstance();

	MainFrame* mainFrame();
};

extern DebuggerApp debuggerApp;

#endif