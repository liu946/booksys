
// booksysDlg.h : 头文件
//

#pragma once
#include "afxwin.h"


// CbooksysDlg 对话框
class CbooksysDlg : public CDialogEx
{
// 构造
public:
	CbooksysDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_BOOKSYS_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CEdit login_name;
	CEdit login_pwd;
	afx_msg void On32780();
	afx_msg void OnBnClickedExit();
};
