// Mod.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "booksys.h"
#include "Mod.h"
#include "afxdialogex.h"


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
