#pragma once


// Mod 对话框

class Mod : public CDialogEx
{
	DECLARE_DYNAMIC(Mod)

public:
	Mod(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Mod();

// 对话框数据
	enum { IDD = IDD_MOD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
