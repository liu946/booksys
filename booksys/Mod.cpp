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
