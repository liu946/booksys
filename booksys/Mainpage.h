#pragma once
#include "afxwin.h"
#include <string>
#include "Studentmanagement.h"
#include "afxcmn.h"
#include "CBookMangement.h"
#include "Officermanagement.h"
using namespace std;
// Mainpage 对话框

class Mainpage : public CDialogEx
{
	DECLARE_DYNAMIC(Mainpage)

public:
	Mainpage(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Mainpage();
	Studentmanagement Stumgt;
	CBookMangement bkmgt;
	//加载菜单
	CMenu m_menu;
	//用户数据
	string name;
// 对话框数据
	Officermanagement offmgt;
	enum { IDD = IDD_MAINPAGE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	void clearlist();
	DECLARE_MESSAGE_MAP()
public:
	CEdit search;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void On32780();
	virtual BOOL OnInitDialog();
	//CListBox showlist;
	afx_msg void On32771();
	afx_msg void On32772();
	afx_msg void On32775();
	afx_msg void On32781();
	CListCtrl showlist;
	afx_msg void OnBnClickedDel();
	int byname;
	int byid;
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedMod();
	afx_msg void On32773();
	afx_msg void On32789();
	afx_msg void On32779();
	afx_msg void On32790();
	afx_msg void On32791();
	afx_msg void On_newbook();
	afx_msg void On32786();
	afx_msg void offshow();
	bool showingstu;
	afx_msg void On32797();
	afx_msg void On32798();
	afx_msg void outofficer();
	afx_msg void instudent();
	afx_msg void inofficer();
	bool isadminlogin;
	string getstring(int n);
	Officer curper;
	afx_msg void outbook();
	afx_msg void inbook();
};
