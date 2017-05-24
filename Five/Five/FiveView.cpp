
// FiveView.cpp : CFiveView ���ʵ��
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
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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

// CFiveView ����/����

CFiveView::CFiveView()
	: CFormView(IDD_FIVE_FORM)
	, month(0)
	, day(0)
	, m_x(0)
	, m_y(0)
	, fileName(_T(""))
{
	// TODO: �ڴ˴���ӹ������

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
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

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


// CFiveView ���

#ifdef _DEBUG
void CFiveView::AssertValid() const
{
	CFormView::AssertValid();
}

void CFiveView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CFiveDoc* CFiveView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFiveDoc)));
	return (CFiveDoc*)m_pDocument;
}
#endif //_DEBUG




// CFiveView ��Ϣ�������
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
	// TODO: �ڴ���������������
}


void CFiveView::OnFileChange()
{
	UpdateData(true);
	string m_fileName = LPCSTR(fileName);
	ofstream file(m_fileName);
	if (!file)
	{
		AfxMessageBox(__T("�����ڸ��ļ�����ѯʧ��"));
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
		AfxMessageBox(__T("�����ڸ��ļ�����ѯʧ��"));
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
	
	
	// TODO: �ڴ���������������
}
