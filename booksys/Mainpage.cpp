// Mainpage.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "booksys.h"
#include "Mainpage.h"
#include "afxdialogex.h"
#include "booksysDlg.h"
#include "AddStudent.h"


// Mainpage �Ի���

IMPLEMENT_DYNAMIC(Mainpage, CDialogEx)

Mainpage::Mainpage(CWnd* pParent /*=NULL*/)
	: CDialogEx(Mainpage::IDD, pParent)
{
	//m_menu.LoadMenu(IDR_MENU1);
	//SetMenu(&m_menu);
	//this->search.GetWindowTextW();
}

Mainpage::~Mainpage()
{
}

void Mainpage::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SEARCH, search);
	DDX_Control(pDX, IDC_LIST1, showlist);
}


BEGIN_MESSAGE_MAP(Mainpage, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &Mainpage::OnBnClickedButton2)
	ON_COMMAND(ID_32780, &Mainpage::On32780)
	ON_COMMAND(ID_32771, &Mainpage::On32771)
END_MESSAGE_MAP()


// Mainpage ��Ϣ�������



void Mainpage::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
		char strBuf[101]="��������ҵ��ѧͼ���";
	this->search.SetWindowText(LPCTSTR(strBuf));

}


void Mainpage::On32780()
{
	// TODO: �ڴ���������������
	CDialogEx::OnOK();
	CbooksysDlg bsd;
	bsd.DoModal();
}


BOOL Mainpage::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	//���ز˵�
	m_menu.LoadMenu(IDR_MENUADMIN);
	SetMenu(&m_menu);
	//����
	for(int i=0;i<30;i++){
		this->showlist.AddString(LPCTSTR("123"));
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void Mainpage::On32771()
{
	// TODO: �ڴ���������������
	AddStudent adds;
	adds.DoModal();
}
