
# Blitz3D Y

To build Blitz3D Y you will need:

* Visual Studio Community (or Pro, whatever) 2019.
* "Desktop development with C++". 
* "C++ MFC for latest v142 build tools (x86 & x64)".
* "C++ ATL for latest v142 build tools (x86 & x64)".
* "ASP.NET and web development".

**Too lazy to build? Grab the prebuilt version from the Releases tab.**

## Building

1) Open blitz3d.sln in Visual Studio 2019.

2) Select Release or Debug config and rebuild the entire solution.

3) All done! You can find output files in the _release and _release/bin dirs. Feel free to delete .pdb and .ilk files here.

4) Note: Blitz3D TSS uses the dynamic version of the fmod audio lib. When redistributing programs built with Blitz3D TSS, you will need to also include the `fmod.dll` file found in the `bin` directory with your programs. This should be placed in the same directory as your program's executable.

## Extending Blitz3D Y
Please read [this document](EXTENDING.md).

## Acknowledgements 

**Blitz3D is released under the zlib/libpng license.**

**This is a fork of Blitz3D by Blitz Research.**

# The zlib/libpng License

Copyright (c) 2013 Blitz Research Ltd

This software is provided 'as-is', without any express or implied warranty. In no event will the authors be held liable for any damages arising from the use of this software.

Permission is granted to anyone to use this software for any purpose, including commercial applications, and to alter it and redistribute it freely, subject to the following restrictions:

1. The origin of this software must not be misrepresented; you must not claim that you wrote the original software. If you use this software in a product, an acknowledgment in the product documentation would be appreciated but is not required.

2. Altered source versions must be plainly marked as such, and must not be misrepresented as being the original software.

3. This notice may not be removed or altered from any source distribution.
