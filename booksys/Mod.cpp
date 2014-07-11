// Mod.cpp : 实现文件
//

#include "stdafx.h"
#include "booksys.h"
#include "Mod.h"
#include "afxdialogex.h"


// Mod 对话框

IMPLEMENT_DYNAMIC(Mod, CDialogEx)

Mod::Mod(CWnd* pParent /*=NULL*/)
	: CDialogEx(Mod::IDD, pParent)
{

}

Mod::~Mod()
{
}

void Mod::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Mod, CDialogEx)
	ON_BN_CLICKED(IDOK, &Mod::OnBnClickedOk)
END_MESSAGE_MAP()


// Mod 消息处理程序


void Mod::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	//更改个人信息
	CDialogEx::OnOK();
}
