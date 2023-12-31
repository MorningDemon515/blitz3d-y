
#include "stdafx.h"
#include "htmlhelp.h"
#include "mainframe.h"
#include "libs.h"

IMPLEMENT_DYNAMIC(HtmlHelp, CHtmlView)
BEGIN_MESSAGE_MAP(HtmlHelp, CHtmlView)
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()

std::string HtmlHelp::getTitle() {
	return title;
}

void HtmlHelp::OnTitleChange(LPCTSTR t) {
	listener->helpTitleChange(this, title = t);
}

void HtmlHelp::OnBeforeNavigate2(LPCTSTR url, DWORD flags, LPCTSTR target, CByteArray& posted, LPCTSTR headers, BOOL* cancel) {
	std::string t(url);
	int attr = GetFileAttributes(url); if(attr == -1) attr = 0;

	//Is the URL a special URL? If so, open it in the user's default web browser instead of IE.
	if(specialUrls.find(url) != specialUrls.end()) {
		ShellExecute(0, 0, url, 0, 0, SW_SHOW);
		*cancel = true;
		return;
	}

	if((attr & FILE_ATTRIBUTE_DIRECTORY) ||
		(t.rfind(".bb") + 3 == t.size()) ||
		(isMediaFile(t))) {

		listener->helpOpen(this, t);
		*cancel = true;
		return;
	}

	*cancel = false;
}

BOOL HtmlHelp::OnEraseBkgnd(CDC* dc) {
	return true;
}

