// Rollback.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "booksys.h"
#include "Rollback.h"
#include "afxdialogex.h"


// Rollback �Ի���

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


// Rollback ��Ϣ�������


void Rollback::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	char id[30];
	this->ec_rollbackid.GetWindowTextA(id,29);
	CString FilePathName;
	CFileDialog dlg(TRUE);///TRUEΪOPEN�Ի���FALSEΪSAVE AS�Ի���
	if(dlg.DoModal()==IDOK)
	FilePathName=dlg.GetPathName();
	string file(FilePathName);
	if(this->stumgt.rollback(id,file)){
		CDialogEx::OnOK();
	}else{
		this->ec_rollbackmsg.SetWindowTextA(LPCTSTR("��ԭ����û�д�ѧ����"));	
	}
}
