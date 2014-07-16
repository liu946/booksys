// StuMainpage.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "booksys.h"
#include "StuMainpage.h"
#include "afxdialogex.h"
#include <stdlib.h>
#include "CBookMangement.h"
#include "CBook.h"
#include <stdlib.h>
#include "booksysDlg.h"
#include <string> 
using namespace std; 
#include <sstream>
#include <iostream>
#include <stdlib.h> 
// StuMainpage �Ի���

IMPLEMENT_DYNAMIC(StuMainpage, CDialogEx)

StuMainpage::StuMainpage(CWnd* pParent /*=NULL*/)
	: CDialogEx(StuMainpage::IDD, pParent)
{

}

StuMainpage::~StuMainpage()
{
}

void StuMainpage::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, showlist);
	DDX_Control(pDX, IDC_SEARCHINFO, ce_searchinfo);
}

BOOL StuMainpage::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	showlist.ModifyStyle(0L,LVS_SHOWSELALWAYS);
	DWORD dwStyle = showlist.GetExtendedStyle();
	dwStyle |= LVS_EX_FULLROWSELECT;//ѡ��ĳ��ʹ���и�����ֻ������report����listctrl��
	//dwStyle |= LVS_EX_GRIDLINES;//�����ߣ�ֻ������report����listctrl��
//	dwStyle |= LVS_EX_CHECKBOXES;//itemǰ����checkbox�ؼ�
	showlist.SetExtendedStyle(dwStyle);
	return true;
}


BEGIN_MESSAGE_MAP(StuMainpage, CDialogEx)
	ON_BN_CLICKED(IDC_SEARCHBTN, &StuMainpage::OnBnClickedSearchbtn)
	ON_BN_CLICKED(IDC_BORROW, &StuMainpage::OnBnClickedBorrow)
	ON_BN_CLICKED(IDC_GIVEBACK, &StuMainpage::OnBnClickedGiveback)
	ON_COMMAND(ID_32792, &StuMainpage::relogin)
	ON_COMMAND(ID_32793, &StuMainpage::onexit)
END_MESSAGE_MAP()


// StuMainpage ��Ϣ�������


void StuMainpage::OnBnClickedSearchbtn()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	clearlist();
	this->showlist.InsertColumn(0,"ID",LVCFMT_LEFT,80,0);    //������
	this->showlist.InsertColumn(1,"����",LVCFMT_LEFT,80,1);
	this->showlist.InsertColumn(2,"��������",LVCFMT_LEFT,80,2);
	this->showlist.InsertColumn(3,"����",LVCFMT_LEFT,80,3);
	this->showlist.InsertColumn(4,"�������",LVCFMT_LEFT,80,4);

		char data[20];
		this->ce_searchinfo.GetWindowTextA(data,19);
		long data1;
		data1 = (long)atoi(data);
		int ids=this->bkmgt.AllNumber();
		//ids=this->bkmgt.IDNumber(data1,ids);
		CBook *bookid = new CBook [ids];
		int nums;
		if(((CButton *)GetDlgItem(IDC_BYID))->GetCheck()){
		//to do ��id����
			this->bkmgt.BookIDSearch(data1,bookid,ids);
			nums=this->bkmgt.IDNumber(data1,ids);
		}else if (((CButton *)GetDlgItem(IDC_BYDATE))->GetCheck()){
		//to do ��ʱ������
			string year(data,0,4);
			string month(data,4,2);
			string day(data,6,2);
			this->bkmgt.BookDateSearch(atoi(year.c_str()),atoi(month.c_str()),atoi(day.c_str()),bookid,ids);
			nums=this->bkmgt.DateNumber(atoi(year.c_str()),atoi(month.c_str()),atoi(day.c_str()),ids);
		}else{
		//to do ����������
			this->bkmgt.BookNameSearch(data,bookid,ids);
			nums=this->bkmgt.NameNumber(data,ids);
		}
		//this->bkmgt.ShowAllNumber(bookid,ids);
		for (int i=0;i<nums ;i++){
			this->showlist.InsertItem(i,LPCTSTR(getstring(bookid[i].GetbookID()).c_str()));       //����
			this->showlist.SetItemText(i,1,LPCTSTR((bookid[i].GetbookName()).c_str()));    //���ø��еĲ�ͬ�е���ʾ�ַ�
			this->showlist.SetItemText(i,2,LPCTSTR(getstring(bookid[i].GetbookNowNumber()).c_str()));    
			this->showlist.SetItemText(i,3,LPCTSTR(getstring(bookid[i].GetbookAllNumber()).c_str()));
			this->showlist.SetItemText(i,4,LPCTSTR((getstring(bookid[i].GetbookDateyear())+"-"+getstring(bookid[i].GetbookDatemonth())+"-"+getstring(bookid[i].GetbookDateday())).c_str()));   
		}
		delete [] bookid;

	

}
void StuMainpage::clearlist(){
		showlist.DeleteAllItems();
		while(showlist.DeleteColumn(0));
}

string StuMainpage::getstring (int n )

{

	stringstream newstr;
	newstr<<n;
	return newstr.str();

}
void StuMainpage::OnBnClickedBorrow()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//this->curstu.borrow("123");
		POSITION pos = showlist.GetFirstSelectedItemPosition();
	if (pos == NULL) {
		AfxMessageBox(_T("No items were selected!\n"));
	}
	else {
		while(pos) {
			int nItem = showlist.GetNextSelectedItem(pos);
			char id[20];
			char bookname[29];
			showlist.GetItemText(nItem,0,id,19);
			showlist.GetItemText(nItem,1,bookname,29);
			bool _x(true);
			this->bkmgt.BookSent(_x,atoi(id));
			this->curstu.borrow(id);
			// you could do your own processing on nItem here
		}
	}
}

void StuMainpage::OnBnClickedGiveback()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//this->curstu.lent("123");
	POSITION pos = showlist.GetFirstSelectedItemPosition();
	if (pos == NULL) {
		AfxMessageBox(_T("No items were selected!\n"));
	}
	else {
		while(pos) {
			int nItem = showlist.GetNextSelectedItem(pos);
			char id[20];
			char bookname[29];
			showlist.GetItemText(nItem,0,id,19);
			showlist.GetItemText(nItem,1,bookname,29);
			bool _x(true);
			this->bkmgt.BookReturn(_x,atoi(id));
			this->curstu.lent(id);
			// you could do your own processing on nItem here
		}
	}
}

void StuMainpage::relogin()
{
	// TODO: �ڴ���������������
	CDialogEx::OnOK();
	CbooksysDlg bsd;
	bsd.DoModal();
}


void StuMainpage::onexit()
{
	// TODO: �ڴ���������������
	CDialogEx::OnOK();
}
