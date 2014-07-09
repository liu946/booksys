#pragma once


// Loginerr 对话框

class Loginerr : public CDialogEx
{
	DECLARE_DYNAMIC(Loginerr)

public:
	Loginerr(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Loginerr();

// 对话框数据
	enum { IDD = IDD_LOGINERR };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
