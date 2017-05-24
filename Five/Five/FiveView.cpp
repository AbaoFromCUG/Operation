
// FiveView.cpp : CFiveView 类的实现
//

#include "stdafx.h"
#include<string>
#include<fstream>
#include<sstream>
using namespace std;
struct Demon {
	int month;
	int day;
	double x;
	double y;
};
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Five.h"
#endif

#include "FiveDoc.h"
#include "FiveView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFiveView

IMPLEMENT_DYNCREATE(CFiveView, CFormView)

BEGIN_MESSAGE_MAP(CFiveView, CFormView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_FILE_NEW, &CFiveView::OnCreatFile)
	ON_COMMAND(ID_FILE_OPEN, &CFiveView::OnFileChange)
	ON_COMMAND(ID_FILE_SAVE, &CFiveView::OnFileLook)
END_MESSAGE_MAP()

// CFiveView 构造/析构

CFiveView::CFiveView()
	: CFormView(IDD_FIVE_FORM)
	, month(0)
	, day(0)
	, m_x(0)
	, m_y(0)
	, fileName(_T(""))
{
	// TODO: 在此处添加构造代码

}

CFiveView::~CFiveView()
{
}

void CFiveView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, month);
	DDV_MinMaxInt(pDX, month, 1, 12);
	DDX_Text(pDX, IDC_EDIT2, day);
	DDV_MinMaxInt(pDX, day, 1, 31);
	DDX_Text(pDX, IDC_EDIT3, m_x);
	DDX_Text(pDX, IDC_EDIT4, m_y);
	DDX_Text(pDX, IDC_EDIT5, fileName);
}

BOOL CFiveView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CFormView::PreCreateWindow(cs);
}

void CFiveView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}

void CFiveView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CFiveView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CFiveView 诊断

#ifdef _DEBUG
void CFiveView::AssertValid() const
{
	CFormView::AssertValid();
}

void CFiveView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CFiveDoc* CFiveView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFiveDoc)));
	return (CFiveDoc*)m_pDocument;
}
#endif //_DEBUG




// CFiveView 消息处理程序
/*

int month;
int day;
double m_x;
double m_y;
CString fileName;
*/

void CFiveView::OnCreatFile()
{
	UpdateData(true);
	string m_fileName = LPCSTR(fileName);
	Demon  demon;
	demon.month = month;
	demon.day = day;
	demon.x = m_x;
	demon.y = m_y;
	fstream file(m_fileName, ios::out | ios::binary);
	file.write((char*)&demon, sizeof(demon));
	file.close();
	// TODO: 在此添加命令处理程序代码
}


void CFiveView::OnFileChange()
{
	UpdateData(true);
	string m_fileName = LPCSTR(fileName);
	ofstream file(m_fileName);
	if (!file)
	{
		AfxMessageBox(__T("不存在该文件，查询失败"));
	}
	else
	{
		Demon  demon;
		demon.month = month;
		demon.day = day;
		demon.x = m_x;
		demon.y = m_y;
		file.write((char*)&demon, sizeof(demon));
	}
}


void CFiveView::OnFileLook()
{
	UpdateData(true);
	string m_fileName = LPCSTR(fileName);
	ifstream file(m_fileName);
	if (!file)
	{
		AfxMessageBox(__T("不存在该文件，查询失败"));
	}
	else
	{
		Demon demon;
		file.read((char*)&demon, sizeof(demon));
		string stringAll;
		string str_mounth;
		string str_day;
		string str_x;
		string str_y;
		stringstream ss;
		ss << demon.month;
		ss >> str_mounth;

		stringstream ss_day;
		ss_day << demon.day;
		ss_day >> str_day;
		stringstream ss_x;
		ss_x << demon.x;
		ss_x >> str_x;
		stringstream ss_y;
		ss_y << demon.y;
		ss_y >> str_y;
		stringAll = str_day +"\n"+ str_mounth + "\n" + str_x + "\n" + str_y;
		
		AfxMessageBox(__T(&stringAll[0]));
	}
	
	
	// TODO: 在此添加命令处理程序代码
}
