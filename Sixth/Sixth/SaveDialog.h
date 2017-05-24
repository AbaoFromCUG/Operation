#pragma once
#include"HomeDialog.h"

// CSaveDialog 对话框

class CSaveDialog : public CDialog
{
	DECLARE_DYNAMIC(CSaveDialog)

public:
	CSaveDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSaveDialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP();
public:
	CHomeDialog* cH;
	CString much;
	CString str;
	afx_msg void OnBnClickedOk();
};
