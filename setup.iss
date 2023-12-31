[Setup]
OutputBaseFilename=Blitz3D TSS v1.125 Setup
OutputDir=.\

AppName=Blitz3D TSS
AppVerName=Blitz3D TSS 1.125
AppPublisher=Third Subdivision Studios (Original by BlitzResearch)
AppPublisherURL=https://github.com/Saalvage/Blitz3D
DefaultDirName={pf}\Blitz3D TSS
DefaultGroupName=Blitz3D TSS

AllowRootDirectory=yes
DisableStartupPrompt=no
DisableWelcomePage=no

[Icons]
Name: "{group}\Blitz3D TSS"; Filename: "{app}\Blitz3D.exe"; WorkingDir: "{app}";
Name: "{group}\Uninstall Blitz3D TSS"; Filename: "{uninstallexe}";

[Files]
Source: ".\_release\*"; DestDir: "{app}"; Flags: ignoreversion recursesubdirs

[Run]
Filename: "{app}\Blitz3D.exe"; Description: "Launch Blitz3D TSS"; Flags: postinstall nowait skipifsilent
