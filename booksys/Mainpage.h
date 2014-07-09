#pragma once
#include "afxwin.h"
#include <string>
using namespace std;
// Mainpage 对话框

class Mainpage : public CDialogEx
{
	DECLARE_DYNAMIC(Mainpage)

public:
	Mainpage(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Mainpage();
	//加载菜单
	CMenu m_menu;
	//用户数据
	string name;
// 对话框数据
	enum { IDD = IDD_MAINPAGE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CEdit search;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void On32780();
	virtual BOOL OnInitDialog();
	CListBox showlist;
	afx_msg void On32771();
	afx_msg void On32772();
};
