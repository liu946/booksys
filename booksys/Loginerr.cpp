// Loginerr.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "booksys.h"
#include "Loginerr.h"
#include "afxdialogex.h"
#include "booksysDlg.h"


// Loginerr �Ի���

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


// Loginerr ��Ϣ�������


void Loginerr::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
	CbooksysDlg bookloginframe;
	bookloginframe.DoModal();
}
