# Microsoft Developer Studio Project File - Name="test1" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=test1 - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "test1.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "test1.mak" CFG="test1 - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "test1 - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "test1 - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "test1 - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "test1 - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "test1 - Win32 Release"
# Name "test1 - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\AI.cpp
# End Source File
# Begin Source File

SOURCE=.\Block.cpp
# End Source File
# Begin Source File

SOURCE=.\Bomb.cpp
# End Source File
# Begin Source File

SOURCE=.\Character.cpp
# End Source File
# Begin Source File

SOURCE=.\DoubleGameView.cpp
# End Source File
# Begin Source File

SOURCE=.\MainFrm.cpp
# End Source File
# Begin Source File

SOURCE=.\MainSet.cpp
# End Source File
# Begin Source File

SOURCE=.\Map.cpp
# End Source File
# Begin Source File

SOURCE=.\ResourceMap.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "test1 - Win32 Release"

# ADD CPP /Yc"stdafx.h"

!ELSEIF  "$(CFG)" == "test1 - Win32 Debug"

# ADD CPP /Yc"StdAfx.h"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\test1.cpp
# End Source File
# Begin Source File

SOURCE=.\test1.rc
# End Source File
# Begin Source File

SOURCE=.\test1Doc.cpp
# End Source File
# Begin Source File

SOURCE=.\test1View.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\AI.h
# End Source File
# Begin Source File

SOURCE=.\Block.h
# End Source File
# Begin Source File

SOURCE=.\Bomb.h
# End Source File
# Begin Source File

SOURCE=.\Character.h
# End Source File
# Begin Source File

SOURCE=.\DoubleGameView.h
# End Source File
# Begin Source File

SOURCE=.\MainFrm.h
# End Source File
# Begin Source File

SOURCE=.\MainSet.h
# End Source File
# Begin Source File

SOURCE=.\Map.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\ResourceMap.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\test1.h
# End Source File
# Begin Source File

SOURCE=.\test1Doc.h
# End Source File
# Begin Source File

SOURCE=.\test1View.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\number.bmp
# End Source File
# Begin Source File

SOURCE=.\res\range.bmp
# End Source File
# Begin Source File

SOURCE=.\res\range1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\range2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\test1.ico
# End Source File
# Begin Source File

SOURCE=.\res\test1.rc2
# End Source File
# Begin Source File

SOURCE=.\res\test1Doc.ico
# End Source File
# Begin Source File

SOURCE=.\res\Toolbar.bmp
# End Source File
# Begin Source File

SOURCE=".\res\����4.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\����5.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\����6.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\����7.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\����������1.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\����������2.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\�ݴ�.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\����.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\��ľ����.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\�յ�.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\��ˮ����ͷ.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\��.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\ˮ�����.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\ˮ����.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\ˮ����.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\ˮ����.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\ˮ������.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\ˮ����.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\������1 (2).bmp"
# End Source File
# Begin Source File

SOURCE=".\res\������1.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\������2 (2).bmp"
# End Source File
# Begin Source File

SOURCE=".\res\������2.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\������3 (2).bmp"
# End Source File
# Begin Source File

SOURCE=".\res\������3.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\������4 (2).bmp"
# End Source File
# Begin Source File

SOURCE=".\res\������4.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\������5 (2).bmp"
# End Source File
# Begin Source File

SOURCE=".\res\������5.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\������1  (2).bmp"
# End Source File
# Begin Source File

SOURCE=".\res\������1.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\������2 (2).bmp"
# End Source File
# Begin Source File

SOURCE=".\res\������2.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\������3 (2).bmp"
# End Source File
# Begin Source File

SOURCE=".\res\������3.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\������4 (2).bmp"
# End Source File
# Begin Source File

SOURCE=".\res\������4.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\������5 (2).bmp"
# End Source File
# Begin Source File

SOURCE=".\res\������5.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\������1 (2).bmp"
# End Source File
# Begin Source File

SOURCE=".\res\������1.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\������2 (2).bmp"
# End Source File
# Begin Source File

SOURCE=".\res\������2.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\������3-1 (2).bmp"
# End Source File
# Begin Source File

SOURCE=".\res\������3-1.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\������4 (2).bmp"
# End Source File
# Begin Source File

SOURCE=".\res\������4.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\������5-1 (2).bmp"
# End Source File
# Begin Source File

SOURCE=".\res\������5-1.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\������1 (2).bmp"
# End Source File
# Begin Source File

SOURCE=".\res\������1.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\������2 (2).bmp"
# End Source File
# Begin Source File

SOURCE=".\res\������2.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\������3-1 (2).bmp"
# End Source File
# Begin Source File

SOURCE=".\res\������3-1.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\������4 (2).bmp"
# End Source File
# Begin Source File

SOURCE=".\res\������4.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\������5-1 (2).bmp"
# End Source File
# Begin Source File

SOURCE=".\res\������5-1.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\��ˮ����ͷ.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\����.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\Ь��.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\�½� BMP ͼ��.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\��ˮ����ͷ.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\ը��1.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\ը��2 .bmp"
# End Source File
# Begin Source File

SOURCE=".\res\ը��3.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\ש��.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\ש��2.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\��ˮ����ͷ.bmp"
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
