// AddOfficer.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "booksys.h"
#include "AddOfficer.h"
#include "afxdialogex.h"
#include <string>
using namespace std;


// AddOfficer �Ի���

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


// AddOfficer ��Ϣ�������


void AddOfficer::OnBnClickedOk2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
		succmsg="��ӹ�����Ա"+succmsg+"�ɹ���";
		SetDlgItemText(IDC_ADDMESSAGE,LPCTSTR(succmsg.c_str()));
	}else{
		SetDlgItemText(IDC_ADDMESSAGE,LPCTSTR("id �Ѵ��ڣ�"));
	}
}


void AddOfficer::OnEnKillfocusAddsid()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	char clistid[30];
	GetDlgItemText(IDC_ADDSID,LPTSTR(clistid),29);

	if (!this->offmgt.check1(clistid)){
		SetDlgItemText(IDC_ADDMESSAGE,LPCTSTR("id �Ѵ���"));
		::EnableWindow(GetDlgItem(IDOK2)->m_hWnd,false);
	}else{
		SetDlgItemText(IDC_ADDMESSAGE,LPCTSTR("�� id ����ʹ��"));
		addconfirmbtn.EnableWindow(true);	
	}
}


void AddOfficer::OnBnClickedCancel2()
{
	CDialogEx::OnOK();
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
