
#ifndef LIBS_H
#define LIBS_H

extern int linker_ver, runtime_ver;

void	initLibs();
std::string	quickHelp(const std::string& kw);
bool	isMediaFile(const std::string& file);

#endif
