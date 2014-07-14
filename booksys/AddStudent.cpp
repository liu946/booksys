// AddStudent.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "booksys.h"
#include "AddStudent.h"
#include "afxdialogex.h"
#include "Studentmanagement.h"

// AddStudent �Ի���

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


// AddStudent ��Ϣ�������


void AddStudent::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
		succmsg="���ѧ��"+succmsg+"�ɹ���";
		SetDlgItemText(IDC_ADDMESSAGE,LPCTSTR(succmsg.c_str()));
	}else{
		SetDlgItemText(IDC_ADDMESSAGE,LPCTSTR("id �Ѵ��ڣ�"));
	}
}


void AddStudent::OnEnKillfocusAddsid()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	char clistid[30];
	GetDlgItemText(IDC_ADDSID,LPTSTR(clistid),29);

	if (!this->stumgt.check1(clistid)){
		SetDlgItemText(IDC_ADDMESSAGE,LPCTSTR("id �Ѵ���"));
		addconfirmbtn.EnableWindow(false);
	}else{
		SetDlgItemText(IDC_ADDMESSAGE,LPCTSTR("�� id ����ʹ��"));
		addconfirmbtn.EnableWindow(true);	
	}
}


