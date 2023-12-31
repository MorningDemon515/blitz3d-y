
#ifndef STDAFX_H
#define STDAFX_H

#define _WIN32_WINNT 0x601

#pragma warning(disable:4786)

#include <afxwin.h>         // Core
#include <afxcmn.h>			// Common Controls
#include <afxrich.h>		// CRich edit

#include <map>
#include <set>
#include <list>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>


//some stuff that should be in std libs
int atoi(const std::string& s);
double atof(const std::string& s);
std::string itoa(int n);
std::string ftoa(float n);
std::string tolower(const std::string& s);
std::string toupper(const std::string& s);
std::string fullfilename(const std::string& t);
std::string filenamepath(const std::string& t);
std::string filenamefile(const std::string& t);

#endif