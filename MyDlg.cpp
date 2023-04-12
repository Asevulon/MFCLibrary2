// MyDlg.cpp: файл реализации
//

#include "pch.h"
#include "MFCLibrary2.h"
#include "afxdialogex.h"
#include "MyDlg.h"


// Диалоговое окно MyDlg

IMPLEMENT_DYNAMIC(MyDlg, CDialogEx)

MyDlg::MyDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{
}

MyDlg::~MyDlg()
{
}

void MyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MyDlg, CDialogEx)
END_MESSAGE_MAP()


// Обработчики сообщений MyDlg
