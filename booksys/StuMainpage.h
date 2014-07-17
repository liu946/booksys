#pragma once
#include "afxcmn.h"
#include "afxwin.h"
#include "CBookMangement.h"
#include "Studentmanagement.h"
#include "Student.h"
// StuMainpage 对话框

class StuMainpage : public CDialogEx
{
	DECLARE_DYNAMIC(StuMainpage)

public:
	StuMainpage(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~StuMainpage();
	virtual BOOL OnInitDialog();

// 对话框数据
	enum { IDD = IDD_STUMAINPAGE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedSearchbtn();
	CListCtrl showlist;
	void clearlist();
	CEdit ce_searchinfo;
	CBookMangement bkmgt;
	Studentmanagement stumgt;
	afx_msg void OnBnClickedBorrow();
	Student curstu;
	afx_msg void OnBnClickedGiveback();

	afx_msg void relogin();
	afx_msg void onexit();
	string getstring (int n );
	afx_msg void modself();
	afx_msg void myborrowinfo();
	afx_msg void helpdoc();
};
