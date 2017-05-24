// DetailsDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "Sixth.h"
#include "DetailsDialog.h"
#include "afxdialogex.h"
#include"HomeDialog.h"
#include<fstream>
#include<string >
using namespace std;
// CDetailsDialog 对话框

IMPLEMENT_DYNAMIC(CDetailsDialog, CDialog)

CDetailsDialog::CDetailsDialog(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DIALOG6, pParent)
{
//	refresh();
}

CDetailsDialog::~CDetailsDialog()
{
}

void CDetailsDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_listBox);
}


BEGIN_MESSAGE_MAP(CDetailsDialog, CDialog)
	ON_BN_CLICKED(IDOK, &CDetailsDialog::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CDetailsDialog::OnBnClickedCancel)
END_MESSAGE_MAP()


// CDetailsDialog 消息处理程序


void CDetailsDialog::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	//CDialog::OnOK();
	m_listBox.ResetContent();
	refresh();
	UpdateData(false);
}

void CDetailsDialog::refresh()
{
	User u = CHomeDialog::readCache();
	fstream file(u.getFile_path(), ios::in);
	string str;
	
	while (getline(file,str))
	{
		m_listBox.AddString(&str[0]);
	}

}


void CDetailsDialog::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialog::OnCancel();
}
