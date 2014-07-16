#include "Officermanagement.h"
#pragma once


// AddOfficer 对话框

class AddOfficer : public CDialogEx
{
	DECLARE_DYNAMIC(AddOfficer)

public:
	AddOfficer(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~AddOfficer();
	CButton addconfirmbtn;
// 对话框数据
	enum { IDD = IDD_ADDOFFICER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk2();
	Officermanagement offmgt;
	afx_msg void OnEnKillfocusAddsid();

	afx_msg void OnBnClickedCancel2();
};
