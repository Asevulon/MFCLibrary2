// MFCLibrary2.h: основной файл заголовка для библиотеки DLL MFCLibrary2
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CMFCLibrary2App
// Реализацию этого класса см. в файле MFCLibrary2.cpp
//

class CMFCLibrary2App : public CWinApp
{
public:
	CMFCLibrary2App();

// Переопределение
public:
	virtual BOOL InitInstance();
	void CreateDlg();
	DECLARE_MESSAGE_MAP()
};
