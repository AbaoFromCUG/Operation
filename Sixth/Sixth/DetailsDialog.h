#pragma once
#include "afxwin.h"


// CDetailsDialog �Ի���

class CDetailsDialog : public CDialog
{
	DECLARE_DYNAMIC(CDetailsDialog)

public:
	CDetailsDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDetailsDialog();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG6 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CListBox m_listBox;
	afx_msg void OnBnClickedOk();
	void refresh();
	afx_msg void OnBnClickedCancel();
};
