// StuMainpage.cpp : 实现文件
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
#include "Mod.h"
using namespace std; 
#include <sstream>
#include <iostream>
#include <stdlib.h> 
// StuMainpage 对话框

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
	dwStyle |= LVS_EX_FULLROWSELECT;//选中某行使整行高亮（只适用与report风格的listctrl）
	//dwStyle |= LVS_EX_GRIDLINES;//网格线（只适用与report风格的listctrl）
//	dwStyle |= LVS_EX_CHECKBOXES;//item前生成checkbox控件
	showlist.SetExtendedStyle(dwStyle);
	return true;
}


BEGIN_MESSAGE_MAP(StuMainpage, CDialogEx)
	ON_BN_CLICKED(IDC_SEARCHBTN, &StuMainpage::OnBnClickedSearchbtn)
	ON_BN_CLICKED(IDC_BORROW, &StuMainpage::OnBnClickedBorrow)
	ON_BN_CLICKED(IDC_GIVEBACK, &StuMainpage::OnBnClickedGiveback)
	ON_COMMAND(ID_32792, &StuMainpage::relogin)
	ON_COMMAND(ID_32793, &StuMainpage::onexit)
	ON_COMMAND(ID_32794, &StuMainpage::modself)
END_MESSAGE_MAP()


// StuMainpage 消息处理程序


void StuMainpage::OnBnClickedSearchbtn()
{
	// TODO: 在此添加控件通知处理程序代码
	clearlist();
	this->showlist.InsertColumn(0,"ID",LVCFMT_LEFT,80,0);    //设置列
	this->showlist.InsertColumn(1,"书名",LVCFMT_LEFT,80,1);
	this->showlist.InsertColumn(2,"现有数量",LVCFMT_LEFT,80,2);
	this->showlist.InsertColumn(3,"总数",LVCFMT_LEFT,80,3);
	this->showlist.InsertColumn(4,"入库日期",LVCFMT_LEFT,80,4);

		char data[20];
		this->ce_searchinfo.GetWindowTextA(data,19);
		long data1;
		data1 = (long)atoi(data);
		int ids=this->bkmgt.AllNumber();
		//ids=this->bkmgt.IDNumber(data1,ids);
		CBook *bookid = new CBook [ids];
		int nums;
		if(((CButton *)GetDlgItem(IDC_BYID))->GetCheck()){
		//to do 按id搜索
			this->bkmgt.BookIDSearch(data1,bookid,ids);
			nums=this->bkmgt.IDNumber(data1,ids);
		}else if (((CButton *)GetDlgItem(IDC_BYDATE))->GetCheck()){
		//to do 按时间搜索
			string year(data,0,4);
			string month(data,4,2);
			string day(data,6,2);
			this->bkmgt.BookDateSearch(atoi(year.c_str()),atoi(month.c_str()),atoi(day.c_str()),bookid,ids);
			nums=this->bkmgt.DateNumber(atoi(year.c_str()),atoi(month.c_str()),atoi(day.c_str()),ids);
		}else{
		//to do 按名字搜索
			this->bkmgt.BookNameSearch(data,bookid,ids);
			nums=this->bkmgt.NameNumber(data,ids);
		}
		//this->bkmgt.ShowAllNumber(bookid,ids);
		for (int i=0;i<nums ;i++){
			this->showlist.InsertItem(i,LPCTSTR(getstring(bookid[i].GetbookID()).c_str()));       //插入
			this->showlist.SetItemText(i,1,LPCTSTR((bookid[i].GetbookName()).c_str()));    //设置该行的不同列的显示字符
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
	// TODO: 在此添加控件通知处理程序代码
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
	// TODO: 在此添加控件通知处理程序代码
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
	// TODO: 在此添加命令处理程序代码
	CDialogEx::OnOK();
	CbooksysDlg bsd;
	bsd.DoModal();
}


void StuMainpage::onexit()
{
	// TODO: 在此添加命令处理程序代码
	CDialogEx::OnOK();
}


void StuMainpage::modself()
{
	// TODO: 在此添加命令处理程序代码
			Mod modfrm;
			modfrm.id=this->curstu.sentID();
			modfrm.pwd=this->stumgt.IDfind(this->curstu.sentID()).sentpassword();
			modfrm.name=this->curstu.sentname();
			modfrm.sex=this->curstu.sentsex();
			modfrm.age=this->curstu.sentage();
			modfrm.stuchanging=true;
			modfrm.DoModal();
}
