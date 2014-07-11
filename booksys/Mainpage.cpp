// Mainpage.cpp : 实现文件
//

#include "stdafx.h"
#include "booksys.h"
#include "Mainpage.h"
#include "afxdialogex.h"
#include "booksysDlg.h"
#include "AddStudent.h"
#include "Studentmanagement.h"
#include "Mod.h"


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
	ON_COMMAND(ID_32772, &Mainpage::On32772)
	ON_COMMAND(ID_32775, &Mainpage::On32775)
	ON_COMMAND(ID_32781, &Mainpage::On32781)
END_MESSAGE_MAP()


// Mainpage 消息处理程序



void Mainpage::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
		
		this->showlist.InsertColumn(0,"ID",LVCFMT_LEFT,80,0);    //设置列
		this->showlist.InsertColumn(1,"NAME",LVCFMT_LEFT,80,1);
		this->showlist.InsertColumn(2,"性别",LVCFMT_LEFT,80,2);
		this->showlist.InsertColumn(3,"年龄",LVCFMT_LEFT,80,3);
		this->showlist.InsertColumn(4,"借书情况",LVCFMT_LEFT,80,4);
	char strBuf[21];
	this->search.GetWindowTextA(strBuf,20);
	this->Stumgt.finds(strBuf);
	bool flag=true;
	while(flag){
		Student tempstu;
		tempstu=this->Stumgt.nextname(flag);
		if(tempstu.sentname()=="")break;
		this->showlist.InsertItem(0,LPCTSTR(tempstu.sentID().c_str()));       //插入行
		this->showlist.SetItemText(0,1,LPCTSTR(tempstu.sentname().c_str()));    //设置该行的不同列的显示字符
		this->showlist.SetItemText(0,2,LPCTSTR(tempstu.sentsex().c_str()));    
		this->showlist.SetItemText(0,3,LPCTSTR(tempstu.sentage().c_str()));    
		this->showlist.SetItemText(0,4,LPCTSTR(tempstu.sentbook().c_str()));  
	}
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
	//加载title
	this->SetWindowTextA(LPCTSTR("欢迎"));
	//加载菜单
	m_menu.LoadMenu(IDR_MENUADMIN);
	SetMenu(&m_menu);
	//加载

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void Mainpage::On32771()
{
	// TODO: 在此添加命令处理程序代码
	AddStudent adds;
	adds.DoModal();
}


void Mainpage::On32772()
{
	// TODO: 在此添加命令处理程序代码
	bool endflag=true;
	Stumgt.file.open("student.dat",ios::in );
		this->showlist.InsertColumn(0,"ID",LVCFMT_LEFT,80,0);    //设置列
		this->showlist.InsertColumn(1,"NAME",LVCFMT_LEFT,80,1);
		this->showlist.InsertColumn(2,"性别",LVCFMT_LEFT,80,2);
		this->showlist.InsertColumn(3,"年龄",LVCFMT_LEFT,80,3);
		this->showlist.InsertColumn(4,"借书情况",LVCFMT_LEFT,80,4);
		int i=0;
	while(endflag){
		Student tempstu;

		tempstu = Stumgt.show(endflag);
		if(!(tempstu.sentname() == "")){
			//string data = tempstu->sentID() +"\t" + tempstu->sentname()+"\t"+tempstu->sentsex()+"\t" + age +"\t"+tempstu->sentbook();
			//this->showlist.AddString(LPCTSTR(data.c_str()));


			this->showlist.InsertItem(i,LPCTSTR(tempstu.sentID().c_str()));       //插入行
			this->showlist.SetItemText(i,1,LPCTSTR(tempstu.sentname().c_str()));    //设置该行的不同列的显示字符
			this->showlist.SetItemText(i,2,LPCTSTR(tempstu.sentsex().c_str()));    
			this->showlist.SetItemText(i,3,LPCTSTR(tempstu.sentage().c_str()));    
			this->showlist.SetItemText(i,4,LPCTSTR(tempstu.sentbook().c_str()));    

		}
		i++;
	}

}


void Mainpage::On32775()
{
	// TODO: 在此添加命令处理程序代码
}


void Mainpage::On32781()
{
	// TODO: 在此添加命令处理程序代码
	Mod modpage;
	modpage.DoModal();
}
