#pragma once
#include "afxwin.h"
#include "Studentmanagement.h"

// Rollback 对话框

class Rollback : public CDialogEx
{
	DECLARE_DYNAMIC(Rollback)

public:
	Rollback(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Rollback();
	Studentmanagement stumgt;
// 对话框数据
	enum { IDD = IDD_ROLLBACK };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CEdit ec_rollbackid;
	CEdit ec_rollbackmsg;
};
