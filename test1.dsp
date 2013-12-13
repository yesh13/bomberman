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

SOURCE=".\res\宝宝4.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\宝宝5.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\宝宝6.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\宝宝7.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\宝宝往上走1.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\宝宝往上走2.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\草丛.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\地面.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\积木地面.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\空地.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\上水柱尽头.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\树.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\水泥地面.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\水柱上.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\水柱下.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\水柱右.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\水柱中心.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\水柱左.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\往上走1 (2).bmp"
# End Source File
# Begin Source File

SOURCE=".\res\往上走1.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\往上走2 (2).bmp"
# End Source File
# Begin Source File

SOURCE=".\res\往上走2.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\往上走3 (2).bmp"
# End Source File
# Begin Source File

SOURCE=".\res\往上走3.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\往上走4 (2).bmp"
# End Source File
# Begin Source File

SOURCE=".\res\往上走4.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\往上走5 (2).bmp"
# End Source File
# Begin Source File

SOURCE=".\res\往上走5.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\往下走1  (2).bmp"
# End Source File
# Begin Source File

SOURCE=".\res\往下走1.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\往下走2 (2).bmp"
# End Source File
# Begin Source File

SOURCE=".\res\往下走2.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\往下走3 (2).bmp"
# End Source File
# Begin Source File

SOURCE=".\res\往下走3.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\往下走4 (2).bmp"
# End Source File
# Begin Source File

SOURCE=".\res\往下走4.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\往下走5 (2).bmp"
# End Source File
# Begin Source File

SOURCE=".\res\往下走5.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\往右走1 (2).bmp"
# End Source File
# Begin Source File

SOURCE=".\res\往右走1.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\往右走2 (2).bmp"
# End Source File
# Begin Source File

SOURCE=".\res\往右走2.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\往右走3-1 (2).bmp"
# End Source File
# Begin Source File

SOURCE=".\res\往右走3-1.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\往右走4 (2).bmp"
# End Source File
# Begin Source File

SOURCE=".\res\往右走4.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\往右走5-1 (2).bmp"
# End Source File
# Begin Source File

SOURCE=".\res\往右走5-1.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\往左走1 (2).bmp"
# End Source File
# Begin Source File

SOURCE=".\res\往左走1.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\往左走2 (2).bmp"
# End Source File
# Begin Source File

SOURCE=".\res\往左走2.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\往左走3-1 (2).bmp"
# End Source File
# Begin Source File

SOURCE=".\res\往左走3-1.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\往左走4 (2).bmp"
# End Source File
# Begin Source File

SOURCE=".\res\往左走4.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\往左走5-1 (2).bmp"
# End Source File
# Begin Source File

SOURCE=".\res\往左走5-1.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\下水柱尽头.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\箱子.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\鞋子.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\新建 BMP 图像.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\右水柱尽头.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\炸弹1.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\炸弹2 .bmp"
# End Source File
# Begin Source File

SOURCE=".\res\炸弹3.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\砖块.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\砖块2.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\左水柱尽头.bmp"
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
