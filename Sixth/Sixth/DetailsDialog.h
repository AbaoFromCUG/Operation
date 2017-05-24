#pragma once
#include "afxwin.h"


// CDetailsDialog 对话框

class CDetailsDialog : public CDialog
{
	DECLARE_DYNAMIC(CDetailsDialog)

public:
	CDetailsDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDetailsDialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG6 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListBox m_listBox;
	afx_msg void OnBnClickedOk();
	void refresh();
	afx_msg void OnBnClickedCancel();
};
