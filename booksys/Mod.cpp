// Mod.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "booksys.h"
#include "Mod.h"
#include "afxdialogex.h"
#include "Mainpage.h"
#include "StuMainpage.h"

// Mod �Ի���

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
	DDX_Control(pDX, IDC_MODID, tx_id);
	DDX_Control(pDX, IDC_MODPWD, tx_pwd);
	DDX_Control(pDX, IDC_MODNAME, tx_name);
	DDX_Control(pDX, IDC_MODSEX, tx_sex);
	DDX_Control(pDX, IDC_MODAGE, tx_age);
}


BEGIN_MESSAGE_MAP(Mod, CDialogEx)
	ON_BN_CLICKED(IDOK, &Mod::OnBnClickedOk)
END_MESSAGE_MAP()


// Mod ��Ϣ�������

void Mod::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//���ĸ�����Ϣ
	char id[30];
	char name[30];
	char age[30];
	char pwd[30];
	char sex[30];
	tx_id.GetWindowTextA(id,29);
	tx_name.GetWindowTextA(name,29);
	tx_age.GetWindowTextA(age,29);
	tx_pwd.GetWindowTextA(pwd,29);
	tx_sex.GetWindowTextA(sex,29);
	if(!this->stuchanging){
		if(((Mainpage*)this->GetParent())->showingstu){
			this->stumgt.modify(id,pwd,name,sex,age);
			((Mainpage*)this->GetParent())->On32772();
		}else{
			this->offmgt.modify(id,pwd,name,sex,age);
			((Mainpage*)this->GetParent())->offshow();
		}
	}else{
		this->stumgt.modify(id,pwd,name,sex,age);
		((StuMainpage)this->GetParent()).curstu=this->stumgt.IDfind(id);
	}
	//����һ����Ϣ�������б�
	CDialogEx::OnOK();
}


BOOL Mod::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	tx_id.SetWindowTextA(LPCTSTR(id.c_str()));
	tx_name.SetWindowTextA(LPCTSTR(name.c_str()));
	tx_age.SetWindowTextA(LPCTSTR(age.c_str()));
	tx_pwd.SetWindowTextA(LPCTSTR(pwd.c_str()));
	tx_sex.SetWindowTextA(LPCTSTR(sex.c_str()));
	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}
