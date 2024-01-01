
#ifndef HTMLHELP_H
#define HTMLHELP_H

#undef HtmlHelp

class HtmlHelp;

class HelpListener{
public:
	virtual void helpOpen( HtmlHelp *help,const std::string &file )=0;
	virtual void helpTitleChange( HtmlHelp *help,const std::string &title )=0;
};

class HtmlHelp : public CHtmlView{
public:
	HtmlHelp( HelpListener *l ):listener(l){}

	std::string getTitle();

DECLARE_DYNAMIC( HtmlHelp )
DECLARE_MESSAGE_MAP()

	afx_msg BOOL OnEraseBkgnd( CDC *dc );

private:
	virtual void OnTitleChange( LPCTSTR t );
	virtual void OnBeforeNavigate2( LPCTSTR lpszURL, DWORD nFlags, LPCTSTR lpszTargetFrameName, CByteArray& baPostedData, LPCTSTR lpszHeaders, BOOL* pbCancel );

	std::string title;
	HelpListener *listener;
};

#endif
