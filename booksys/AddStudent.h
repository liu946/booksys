#pragma once
#include "afxwin.h"
#include "Studentmanagement.h"

// AddStudent 对话框

class AddStudent : public CDialogEx
{
	DECLARE_DYNAMIC(AddStudent)

public:
	AddStudent(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~AddStudent();
	Studentmanagement stumgt;

// 对话框数据
	enum { IDD = IDD_ADDSTUDENT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnEnKillfocusAddsid();
	CButton addconfirmbtn;
};
