// AddOfficer.cpp : 实现文件
//

#include "stdafx.h"
#include "booksys.h"
#include "AddOfficer.h"
#include "afxdialogex.h"
#include <string>
using namespace std;


// AddOfficer 对话框

IMPLEMENT_DYNAMIC(AddOfficer, CDialogEx)

AddOfficer::AddOfficer(CWnd* pParent /*=NULL*/)
	: CDialogEx(AddOfficer::IDD, pParent)
{

}

AddOfficer::~AddOfficer()
{
}

void AddOfficer::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDOK2, addconfirmbtn);
}


BEGIN_MESSAGE_MAP(AddOfficer, CDialogEx)
	ON_BN_CLICKED(IDOK2, &AddOfficer::OnBnClickedOk2)
	ON_EN_KILLFOCUS(IDC_ADDSID, &AddOfficer::OnEnKillfocusAddsid)
	ON_BN_CLICKED(IDCANCEL2, &AddOfficer::OnBnClickedCancel2)
END_MESSAGE_MAP()


// AddOfficer 消息处理程序


void AddOfficer::OnBnClickedOk2()
{
	// TODO: 在此添加控件通知处理程序代码
		char clistid[30];
	char clistname[30];
	char clistpwd[30];
	string id(clistid);
	if(this->offmgt.check1(id)){
		GetDlgItemText(IDC_ADDSID,LPTSTR(clistid),29);
		GetDlgItemText(IDC_ADDSNAME,LPTSTR(clistname),29);
		GetDlgItemText(IDC_ADDSPWD,LPTSTR(clistpwd),29);
		offmgt.add1(clistid,clistpwd,clistname);
		string succmsg(clistname);
		succmsg="添加工作人员"+succmsg+"成功！";
		SetDlgItemText(IDC_ADDMESSAGE,LPCTSTR(succmsg.c_str()));
	}else{
		SetDlgItemText(IDC_ADDMESSAGE,LPCTSTR("id 已存在！"));
	}
}


void AddOfficer::OnEnKillfocusAddsid()
{
	// TODO: 在此添加控件通知处理程序代码
	char clistid[30];
	GetDlgItemText(IDC_ADDSID,LPTSTR(clistid),29);

	if (!this->offmgt.check1(clistid)){
		SetDlgItemText(IDC_ADDMESSAGE,LPCTSTR("id 已存在"));
		::EnableWindow(GetDlgItem(IDOK2)->m_hWnd,false);
	}else{
		SetDlgItemText(IDC_ADDMESSAGE,LPCTSTR("此 id 可以使用"));
		addconfirmbtn.EnableWindow(true);	
	}
}


void AddOfficer::OnBnClickedCancel2()
{
	CDialogEx::OnOK();
	// TODO: 在此添加控件通知处理程序代码
}
