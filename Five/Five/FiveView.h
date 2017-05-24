
// FiveView.h : CFiveView 类的接口
//

#pragma once


class CFiveView : public CFormView
{
protected: // 仅从序列化创建
	CFiveView();
	DECLARE_DYNCREATE(CFiveView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_FIVE_FORM };
#endif

// 特性
public:
	CFiveDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~CFiveView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
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

#ifndef _DEBUG  // FiveView.cpp 中的调试版本
inline CFiveDoc* CFiveView::GetDocument() const
   { return reinterpret_cast<CFiveDoc*>(m_pDocument); }
#endif

