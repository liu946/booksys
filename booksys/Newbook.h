#pragma once
#include "afxwin.h"
#include "CBookMangement.h"

// Newbook 对话框

class Newbook : public CDialogEx
{
	DECLARE_DYNAMIC(Newbook)

public:
	Newbook(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Newbook();
	CBookMangement bkmgt;

// 对话框数据
	enum { IDD = IDD_NEWBOOK };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CEdit msg;
	CEdit ce_id;
	CEdit ec_name;
	CEdit ec_num;
	CEdit ec_year;
	CEdit ec_month;
	CEdit ec_day;
	afx_msg void OnBnClickedOk();
};
