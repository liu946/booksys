// AddStudent.cpp : 实现文件
//

#include "stdafx.h"
#include "booksys.h"
#include "AddStudent.h"
#include "afxdialogex.h"
#include "Studentmanagement.h"

// AddStudent 对话框

IMPLEMENT_DYNAMIC(AddStudent, CDialogEx)

AddStudent::AddStudent(CWnd* pParent /*=NULL*/)
	: CDialogEx(AddStudent::IDD, pParent)
{

}

AddStudent::~AddStudent()
{
}

void AddStudent::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDOK, addconfirmbtn);
}


BEGIN_MESSAGE_MAP(AddStudent, CDialogEx)
	ON_BN_CLICKED(IDOK, &AddStudent::OnBnClickedOk)
	ON_EN_KILLFOCUS(IDC_ADDSID, &AddStudent::OnEnKillfocusAddsid)
END_MESSAGE_MAP()


// AddStudent 消息处理程序


void AddStudent::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	char clistid[30];
	char clistname[30];
	char clistpwd[30];
	string id(clistid);
	if(this->stumgt.check1(id)){
		GetDlgItemText(IDC_ADDSID,LPTSTR(clistid),29);
		GetDlgItemText(IDC_ADDSNAME,LPTSTR(clistname),29);
		GetDlgItemText(IDC_ADDSPWD,LPTSTR(clistpwd),29);
		stumgt.add1(clistid,clistpwd,clistname);
		string succmsg(clistname);
		succmsg="添加学生"+succmsg+"成功！";
		SetDlgItemText(IDC_ADDMESSAGE,LPCTSTR(succmsg.c_str()));
	}else{
		SetDlgItemText(IDC_ADDMESSAGE,LPCTSTR("id 已存在！"));
	}
}


void AddStudent::OnEnKillfocusAddsid()
{
	// TODO: 在此添加控件通知处理程序代码
	char clistid[30];
	GetDlgItemText(IDC_ADDSID,LPTSTR(clistid),29);

	if (!this->stumgt.check1(clistid)){
		SetDlgItemText(IDC_ADDMESSAGE,LPCTSTR("id 已存在"));
		addconfirmbtn.EnableWindow(false);
	}else{
		SetDlgItemText(IDC_ADDMESSAGE,LPCTSTR("此 id 可以使用"));
		addconfirmbtn.EnableWindow(true);	
	}
}


