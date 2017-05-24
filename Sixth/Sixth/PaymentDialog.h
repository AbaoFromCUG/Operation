#pragma once
#include"HomeDialog.h"

// CPaymentDialog 对话框

class CPaymentDialog : public CDialog
{
	DECLARE_DYNAMIC(CPaymentDialog)

public:
	CPaymentDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CPaymentDialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG5 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	double much;
	CString shuo;
	afx_msg void OnBnClickedOk();
	CHomeDialog* cH;
};
