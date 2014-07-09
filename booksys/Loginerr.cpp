// Loginerr.cpp : 实现文件
//

#include "stdafx.h"
#include "booksys.h"
#include "Loginerr.h"
#include "afxdialogex.h"
#include "booksysDlg.h"


// Loginerr 对话框

IMPLEMENT_DYNAMIC(Loginerr, CDialogEx)

Loginerr::Loginerr(CWnd* pParent /*=NULL*/)
	: CDialogEx(Loginerr::IDD, pParent)
{

}

Loginerr::~Loginerr()
{
}

void Loginerr::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Loginerr, CDialogEx)
	ON_BN_CLICKED(IDOK, &Loginerr::OnBnClickedOk)
END_MESSAGE_MAP()


// Loginerr 消息处理程序


void Loginerr::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
	CbooksysDlg bookloginframe;
	bookloginframe.DoModal();
}
