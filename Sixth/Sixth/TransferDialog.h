#pragma once
#include"HomeDialog.h"
#include<string>
using namespace std;

// CTransferDialog 对话框

class CTransferDialog : public CDialog
{
	DECLARE_DYNAMIC(CTransferDialog)

public:
	CTransferDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CTransferDialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString aim_id;
	double much;
	CString description;
	afx_msg void OnBnClickedOk();
	CHomeDialog* cH;
	afx_msg void OnBnClickedCancel();
};
