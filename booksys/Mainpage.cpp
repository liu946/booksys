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
#include "Rollback.h"
#include "Newbook.h"

// Mainpage �Ի���

IMPLEMENT_DYNAMIC(Mainpage, CDialogEx)

Mainpage::Mainpage(CWnd* pParent /*=NULL*/)
	: CDialogEx(Mainpage::IDD, pParent)
	, byname(0)
	, byid(0)
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

void Mainpage::clearlist(){
		showlist.DeleteAllItems();
		while(showlist.DeleteColumn(0));
}

BEGIN_MESSAGE_MAP(Mainpage, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &Mainpage::OnBnClickedButton2)
	ON_COMMAND(ID_32780, &Mainpage::On32780)
	ON_COMMAND(ID_32771, &Mainpage::On32771)
	ON_COMMAND(ID_32772, &Mainpage::On32772)
	ON_COMMAND(ID_32775, &Mainpage::On32775)
	ON_COMMAND(ID_32781, &Mainpage::On32781)
	ON_BN_CLICKED(IDC_DEL, &Mainpage::OnBnClickedDel)
	ON_BN_CLICKED(IDC_MOD, &Mainpage::OnBnClickedMod)
	ON_COMMAND(ID_32773, &Mainpage::On32773)
	ON_COMMAND(ID_32789, &Mainpage::On32789)
	ON_COMMAND(ID_32779, &Mainpage::On32779)
	ON_COMMAND(ID_32790, &Mainpage::On32790)
	ON_COMMAND(ID_32791, &Mainpage::On32791)
	ON_COMMAND(ID_32785, &Mainpage::On_newbook)
END_MESSAGE_MAP()


// Mainpage ��Ϣ�������


//finds
void Mainpage::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	    //this->showlist.DeleteAllItems();
		//this->showlist.DeleteColumn(0);
		//this->showlist.DeleteColumn(1);
		//this->showlist.DeleteColumn(2);

		clearlist();
		this->showlist.InsertColumn(0,"ID",LVCFMT_LEFT,80,0);    //������
		this->showlist.InsertColumn(1,"NAME",LVCFMT_LEFT,80,1);
		this->showlist.InsertColumn(2,"�Ա�",LVCFMT_LEFT,80,2);
		this->showlist.InsertColumn(3,"����",LVCFMT_LEFT,80,3);
		this->showlist.InsertColumn(4,"�������",LVCFMT_LEFT,80,4);
	char strBuf[21];
	this->search.GetWindowTextA(strBuf,20);
	this->Stumgt.finds(strBuf);
	bool flag=true;
	int i=0;
	while(flag){
		Student tempstu;
		if(((CButton *)GetDlgItem(IDC_BYNAME))->GetCheck()){
			tempstu=this->Stumgt.nextname(flag);
		}else{
			tempstu=this->Stumgt.nextid(flag);
		}
		if(tempstu.sentname()=="")break;
		this->showlist.InsertItem(i,LPCTSTR(tempstu.sentID().c_str()));       //������
		this->showlist.SetItemText(i,1,LPCTSTR(tempstu.sentname().c_str()));    //���ø��еĲ�ͬ�е���ʾ�ַ�
		this->showlist.SetItemText(i,2,LPCTSTR(tempstu.sentsex().c_str()));    
		this->showlist.SetItemText(i,3,LPCTSTR(tempstu.sentage().c_str()));    
		this->showlist.SetItemText(i,4,LPCTSTR(tempstu.sentbook().c_str()));  
		i++;
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

	//����list
	showlist.ModifyStyle(0L,LVS_SHOWSELALWAYS);
	DWORD dwStyle = showlist.GetExtendedStyle();
	dwStyle |= LVS_EX_FULLROWSELECT;//ѡ��ĳ��ʹ���и�����ֻ������report����listctrl��
	//dwStyle |= LVS_EX_GRIDLINES;//�����ߣ�ֻ������report����listctrl��
//	dwStyle |= LVS_EX_CHECKBOXES;//itemǰ����checkbox�ؼ�
	showlist.SetExtendedStyle(dwStyle);
	//�����б���
	//InsertColumn����������������ΪLVCFMT_LEFT, LVCFMT_RIGHT, or LVCFMT_CENTER
	//�����һ��ʼ�տ��������
	//showlist.DeleteColumn(0);
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
	clearlist();
	bool endflag=true;
	Stumgt.file.open("student.dat",ios::in );
	if(!this->Stumgt.file){this->Stumgt.file.close();return;}
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


void Mainpage::OnBnClickedDel()
{
	// TODO: Add your control notification handler code here
	POSITION pos = showlist.GetFirstSelectedItemPosition();
	if (pos == NULL) {
		AfxMessageBox(_T("No items were selected!\n"));
	}
	else {
		while(pos) {
			int nItem = showlist.GetNextSelectedItem(pos);
			char buf[20];
			showlist.GetItemText(nItem,0,buf,19);
			this->Stumgt.delet(buf);
			this->showlist.DeleteItem(nItem);
			// you could do your own processing on nItem here
		}
	}
}





void Mainpage::OnBnClickedMod()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	POSITION pos = showlist.GetFirstSelectedItemPosition();
	if (pos == NULL) {
		AfxMessageBox(_T("No items were selected!\n"));
	}
	else {
		while(pos) {
			int nItem = showlist.GetNextSelectedItem(pos);
			char id[20];
			char name[30];
			char sex[5];
			char age[4];
			showlist.GetItemText(nItem,0,id,19);
			showlist.GetItemText(nItem,1,name,29);
			showlist.GetItemText(nItem,2,sex,4);
			showlist.GetItemText(nItem,3,age,3);
			Mod modfrm;
			modfrm.id=id;
			modfrm.pwd=this->Stumgt.IDfind(id).sentpassword();
			modfrm.name=name;
			modfrm.sex=sex;
			modfrm.age=age;
			modfrm.DoModal();
			// you could do your own processing on nItem here
		}
	}
}


void Mainpage::On32773()
{
	// TODO: �ڴ���������������
	CString FilePathName;
	CFileDialog dlg(FALSE,"dat","student");///TRUEΪOPEN�Ի���FALSEΪSAVE AS�Ի���
	if(dlg.DoModal()==IDOK)
	FilePathName=dlg.GetPathName();
	string file(FilePathName);
	this->Stumgt.backup(file);
}


void Mainpage::On32789()
{
	// TODO: �ڴ���������������
	Rollback rbfrm;
	rbfrm.DoModal();
}


void Mainpage::On32779()
{
	// TODO: �ڴ���������������
	CDialogEx::OnOK();
}


void Mainpage::On32790()
{
	// TODO: �ڴ���������������
	this->Stumgt.mysort(true);
	this->On32772();
}


void Mainpage::On32791()
{
	// TODO: �ڴ���������������
	this->Stumgt.mysort(false);
	this->On32772();
}


void Mainpage::On_newbook()
{
	// TODO: �ڴ���������������
	Newbook nbfrm;
	nbfrm.DoModal();

}
