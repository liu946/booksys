// Mainpage.cpp : 实现文件
//

#include "stdafx.h"
#include "booksys.h"
#include "Mainpage.h"
#include "afxdialogex.h"
#include "booksysDlg.h"
#include "AddStudent.h"


// Mainpage 对话框

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


// Mainpage 消息处理程序



void Mainpage::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
		char strBuf[101]="哈尔滨工业大学图书馆";
	this->search.SetWindowText(LPCTSTR(strBuf));

}


void Mainpage::On32780()
{
	// TODO: 在此添加命令处理程序代码
	CDialogEx::OnOK();
	CbooksysDlg bsd;
	bsd.DoModal();
}


BOOL Mainpage::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	//加载菜单
	m_menu.LoadMenu(IDR_MENUADMIN);
	SetMenu(&m_menu);
	//加载
	for(int i=0;i<30;i++){
		this->showlist.AddString(LPCTSTR("123"));
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void Mainpage::On32771()
{
	// TODO: 在此添加命令处理程序代码
	AddStudent adds;
	adds.DoModal();
}
