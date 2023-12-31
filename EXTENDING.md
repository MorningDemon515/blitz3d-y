# Extending Blitz3D TSS
Extending the engine is done by a "Userlib", which is a pair of files:

* A `.dll` file containing the userlib's code.
* A `.decls` file that tells BlitzBasic the module, and the exports of the module.

The `.decls` files are CRUCIAL. Without one, BlitzBasic won't be able to locate the functions you want to use from the DLL file.

## The .decls Format
Each `.decls` file should begin with a `.lib` directive, followed by a whitespace and the quoted name of the DLL file to be loaded. Example:

> .lib "mylib.dll"

Afterwards, you must define a list of functions you want to expose to BlitzBasic. There are a few exceptions:

* No default parameter values are allowed.

* If no function return type is specified, the function is a 'void' function - ie: it returns nothing.

* Instead of object parameters, you can only specify 'void*' parameters using a '*' type tag. Such
parameters can be assigned ANY object or bank, so BE CAREFUL!

* The declaration must be followed by the C decorated name. This takes form of a `:` followed by the quoted decorated name. Example:
```
MyFunction( text$ ):"_MyFunction@4"
VecDistance#( x1#, y1#, z1#, x2#, y2#, z2# ):"_VecDistance@24"
```

To get the list of exports from a DLL file, please check [this article](https://docs.microsoft.com/en-us/cpp/build/reference/dash-exports?view=msvc-170).

## Writing a DLL
Here's a list of rules:
* Functions **MUST** use the `_stdcall` convention.
* Floats are passed and returned as per standard C/C++ conventions.
* Strings **MUST** be in C format (`const char*`), no `std::string` allowed.
* Banks and objects can be passed into functions. The value passed is a pointer to the first byte of storage. No information is passed about the type or size of the memory though, so **PROCEED WITH EXTREME CAUTION**.
* Banks and objects cannot be returned from functions, and arrays are not supported in any way.
* C++ name mangling is not allowed, you must use `extern "C"`.

Now HERE is how we would write a DLL:
1. Open up Visual Studio and create a "Dynamic-Link Library" project.
2. Delete all the files, and turn "precompiled headers" off in the project settings.
3. Copy `runtime.lib` from the `userlibs` folder into the project's root directory, and link into it. This will allow you to call the BlitzBasic `DebugLog` and `RuntimeError` functions.
4. Write the code.
5. Build it.
6. Create the `.decls` file.
7. Place `MyLib.dll` and `MyLib.decls` in the `userlibs` folder of your Blitz3D TSS installation.
8. Done!

**ATTENTION!** When building a standalone executable for your game, you must place the userlib's DLL alongside the executable (you don't need the declarations file anymore, though).

## Sample Code

**MyLib.h**
```cpp
#pragma once

#include <math.h>
#include <string.h>
#include <stdlib.h>

//Convenience macro!
#define BLITZ3D(x) extern "C" __declspec(dllexport) x _stdcall

//BlitzBasic functions.
__declspec(dllimport) void __cdecl BlitzDebugLog(const char* msg);
__declspec(dllimport) void __cdecl BlitzRuntimeError(const char* msg);

BLITZ3D(float) VecDistance(float x1, float y1, float z1, float x2, float y2, float z2);
BLITZ3D(void) CrashLol(const char* str);
BLITZ3D(const char*) Ping();
```

**MyLib.cpp**
```cpp
#include "MyLib.h"

BLITZ3D(float) VecDistance(float x1, float y1, float z1, float x2, float y2, float z2)
{
	BlitzDebugLog("Hey! You called VecDistance inside MyLib.dll!");

	float dx = x1 - x2
	float dy = y1 - y2
	float dz = z1 - z2;
  
	return sqrtf(dx * dx + dy * dy + dz * dz);
}

BLITZ3D(void) CrashLol(const char* str)
{
	BlitzDebugLog("Haha im gonna crash now!!");
	BlitzRuntimeError(str);
}

BLITZ3D(const char*) Ping()
{
	BlitzDebugLog("Pong!");
	return "Pong";
}
```

**MyLib.decls**
```
.lib "MyLib.dll"

VecDistance#( x1#, y1#, z1#, x2#, y2#, z2# ):"_VecDistance@24"
CrashLol( str$ ):"_CrashLol@4"
Ping$():"_Ping@0"
```

Hopefully this guide will help you.

If you find any issues with this guide, please open an issue or contact Nora#6365 on the TSS discord server.
