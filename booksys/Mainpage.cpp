// Mainpage.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "booksys.h"
#include "Mainpage.h"
#include "afxdialogex.h"
#include "booksysDlg.h"
#include "AddStudent.h"
#include "Studentmanagement.h"
#include "Mod.h"


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
	ON_COMMAND(ID_32772, &Mainpage::On32772)
	ON_COMMAND(ID_32775, &Mainpage::On32775)
	ON_COMMAND(ID_32781, &Mainpage::On32781)
END_MESSAGE_MAP()


// Mainpage ��Ϣ�������



void Mainpage::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
		
		this->showlist.InsertColumn(0,"ID",LVCFMT_LEFT,80,0);    //������
		this->showlist.InsertColumn(1,"NAME",LVCFMT_LEFT,80,1);
		this->showlist.InsertColumn(2,"�Ա�",LVCFMT_LEFT,80,2);
		this->showlist.InsertColumn(3,"����",LVCFMT_LEFT,80,3);
		this->showlist.InsertColumn(4,"�������",LVCFMT_LEFT,80,4);
	char strBuf[21];
	this->search.GetWindowTextA(strBuf,20);
	this->Stumgt.finds(strBuf);
	bool flag=true;
	while(flag){
		Student tempstu;
		tempstu=this->Stumgt.nextname(flag);
		if(tempstu.sentname()=="")break;
		this->showlist.InsertItem(0,LPCTSTR(tempstu.sentID().c_str()));       //������
		this->showlist.SetItemText(0,1,LPCTSTR(tempstu.sentname().c_str()));    //���ø��еĲ�ͬ�е���ʾ�ַ�
		this->showlist.SetItemText(0,2,LPCTSTR(tempstu.sentsex().c_str()));    
		this->showlist.SetItemText(0,3,LPCTSTR(tempstu.sentage().c_str()));    
		this->showlist.SetItemText(0,4,LPCTSTR(tempstu.sentbook().c_str()));  
	}
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
	//����title
	this->SetWindowTextA(LPCTSTR("��ӭ"));
	//���ز˵�
	m_menu.LoadMenu(IDR_MENUADMIN);
	SetMenu(&m_menu);
	//����

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void Mainpage::On32771()
{
	// TODO: �ڴ���������������
	AddStudent adds;
	adds.DoModal();
}


void Mainpage::On32772()
{
	// TODO: �ڴ���������������
	bool endflag=true;
	Stumgt.file.open("student.dat",ios::in );
		this->showlist.InsertColumn(0,"ID",LVCFMT_LEFT,80,0);    //������
		this->showlist.InsertColumn(1,"NAME",LVCFMT_LEFT,80,1);
		this->showlist.InsertColumn(2,"�Ա�",LVCFMT_LEFT,80,2);
		this->showlist.InsertColumn(3,"����",LVCFMT_LEFT,80,3);
		this->showlist.InsertColumn(4,"�������",LVCFMT_LEFT,80,4);
		int i=0;
	while(endflag){
		Student tempstu;

		tempstu = Stumgt.show(endflag);
		if(!(tempstu.sentname() == "")){
			//string data = tempstu->sentID() +"\t" + tempstu->sentname()+"\t"+tempstu->sentsex()+"\t" + age +"\t"+tempstu->sentbook();
			//this->showlist.AddString(LPCTSTR(data.c_str()));


			this->showlist.InsertItem(i,LPCTSTR(tempstu.sentID().c_str()));       //������
			this->showlist.SetItemText(i,1,LPCTSTR(tempstu.sentname().c_str()));    //���ø��еĲ�ͬ�е���ʾ�ַ�
			this->showlist.SetItemText(i,2,LPCTSTR(tempstu.sentsex().c_str()));    
			this->showlist.SetItemText(i,3,LPCTSTR(tempstu.sentage().c_str()));    
			this->showlist.SetItemText(i,4,LPCTSTR(tempstu.sentbook().c_str()));    

		}
		i++;
	}

}


void Mainpage::On32775()
{
	// TODO: �ڴ���������������
}


void Mainpage::On32781()
{
	// TODO: �ڴ���������������
	Mod modpage;
	modpage.DoModal();
}
