
// FiveView.h : CFiveView ��Ľӿ�
//

#pragma once


class CFiveView : public CFormView
{
protected: // �������л�����
	CFiveView();
	DECLARE_DYNCREATE(CFiveView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_FIVE_FORM };
#endif

// ����
public:
	CFiveDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~CFiveView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	//afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	int month;
	int day;
	double m_x;
	double m_y;
	CString fileName;
	afx_msg void OnCreatFile();
	afx_msg void OnFileChange();
	afx_msg void OnFileLook();
};

#ifndef _DEBUG  // FiveView.cpp �еĵ��԰汾
inline CFiveDoc* CFiveView::GetDocument() const
   { return reinterpret_cast<CFiveDoc*>(m_pDocument); }
#endif

