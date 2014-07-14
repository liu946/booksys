// Rollback.cpp : 实现文件
//

#include "stdafx.h"
#include "booksys.h"
#include "Rollback.h"
#include "afxdialogex.h"


// Rollback 对话框

IMPLEMENT_DYNAMIC(Rollback, CDialogEx)

Rollback::Rollback(CWnd* pParent /*=NULL*/)
	: CDialogEx(Rollback::IDD, pParent)
{

}

Rollback::~Rollback()
{
}

void Rollback::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_ROLLBACKID, ec_rollbackid);
	DDX_Control(pDX, IDC_ROLLABCKMSG, ec_rollbackmsg);
}


BEGIN_MESSAGE_MAP(Rollback, CDialogEx)
	ON_BN_CLICKED(IDOK, &Rollback::OnBnClickedOk)
END_MESSAGE_MAP()


// Rollback 消息处理程序


void Rollback::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	char id[30];
	this->ec_rollbackid.GetWindowTextA(id,29);
	CString FilePathName;
	CFileDialog dlg(TRUE);///TRUE为OPEN对话框，FALSE为SAVE AS对话框
	if(dlg.DoModal()==IDOK)
	FilePathName=dlg.GetPathName();
	string file(FilePathName);
	if(this->stumgt.rollback(id,file)){
		CDialogEx::OnOK();
	}else{
		this->ec_rollbackmsg.SetWindowTextA(LPCTSTR("还原错误，没有此学生！"));	
	}
}
