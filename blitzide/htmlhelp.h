
#ifndef HTMLHELP_H
#define HTMLHELP_H

#undef HtmlHelp

#include <set>

class HtmlHelp;

class HelpListener {
public:
	virtual void helpOpen(HtmlHelp* help, const std::string& file) = 0;
	virtual void helpTitleChange(HtmlHelp* help, const std::string& title) = 0;
};

class HtmlHelp : public CHtmlView {
public:
	HtmlHelp(HelpListener* l) :listener(l) {}

	std::string getTitle();

	//Using this to prevent MFC from opening these on IE.
	std::set<std::string> specialUrls =
	{
		"https://github.com/Saalvage/Blitz3D/blob/sth/EXTENDING.md",
		"https://mojolabs.nz/",
		"https://www.syntaxbomb.com/index.php",
		"https://www.blitzcoder.org/forum/",
		"https://aestheticalz.github.io/BlitzDocs/index.htm"
	};

	DECLARE_DYNAMIC(HtmlHelp)
	DECLARE_MESSAGE_MAP()

	afx_msg BOOL OnEraseBkgnd(CDC* dc);

private:
	virtual void OnTitleChange(LPCTSTR t);
	virtual void OnBeforeNavigate2(LPCTSTR lpszURL, DWORD nFlags, LPCTSTR lpszTargetFrameName, CByteArray& baPostedData, LPCTSTR lpszHeaders, BOOL* pbCancel);

	std::string title;
	HelpListener* listener;
};

#endif
