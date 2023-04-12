// MFCLibrary2.cpp: определяет процедуры инициализации для библиотеки DLL.
//

#include "pch.h"
#include "framework.h"
#include "MFCLibrary2.h"
#include "MyDlg.h"
#include <Cpl.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO: если эта библиотека DLL динамически связана с библиотеками DLL MFC,
//		все функции, экспортированные из данной DLL-библиотеки, которые выполняют вызовы к
//		MFC, должны содержать макрос AFX_MANAGE_STATE в
//		самое начало функции.
//
//		Например:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// тело нормальной функции
//		}
//
//		Важно, чтобы данный макрос был представлен в каждой
//		функции до вызова MFC.  Это означает, что
//		должен стоять в качестве первого оператора в
//		функции и предшествовать даже любым объявлениям переменных объекта,
//		поскольку их конструкторы могут выполнять вызовы к MFC
//		DLL.
//
//		В Технических указаниях MFC 33 и 58 содержатся более
//		подробные сведения.
//

// CMFCLibrary2App

BEGIN_MESSAGE_MAP(CMFCLibrary2App, CWinApp)
END_MESSAGE_MAP()


// Создание CMFCLibrary2App

CMFCLibrary2App::CMFCLibrary2App()
{
	// TODO: добавьте код создания,
	// Размещает весь важный код инициализации в InitInstance
}


// Единственный объект CMFCLibrary2App

CMFCLibrary2App theApp;


// Инициализация CMFCLibrary2App

BOOL CMFCLibrary2App::InitInstance()
{
	/*MyDlg dlg;
	dlg.DoModal();*/
	return TRUE;
}

DWORD COUNTER = 0;
HWND ProgList[64];
extern "C" LONG CPlApplet(HWND hWndCpl, UINT msg, LPARAM lParam1, LPARAM lParam2)
{

	switch (msg)
	{
	case CPL_INIT:
	{
		ProgList[COUNTER] = hWndCpl;
		COUNTER++;

		return TRUE;
	}
	case CPL_GETCOUNT: return COUNTER;

	case CPL_INQUIRE:
	{
		CPLINFO* info = (CPLINFO*)lParam2;
		info->idIcon = IDI_ICON1;
		info->idInfo = IDS_DESCRIPTION;
		info->idName = IDS_NAME;
		info->lData = 123;
		break;
	}
	case CPL_DBLCLK:
	{
		theApp.CreateDlg();
		break;
	}
	default:break;
	}
}


void CMFCLibrary2App::CreateDlg()
{
	MyDlg dlg;
	dlg.DoModal();
}