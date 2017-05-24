// SaveDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Sixth.h"
#include "SaveDialog.h"
#include "afxdialogex.h"
#include"URecord.h"
#include"HomeDialog.h"
#include<string>
using namespace std;

// CSaveDialog �Ի���

IMPLEMENT_DYNAMIC(CSaveDialog, CDialog)

CSaveDialog::CSaveDialog(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DIALOG4, pParent)
	, much(_T(""))
	, str(_T(" "))
{

}

CSaveDialog::~CSaveDialog()
{
}

void CSaveDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, much);
	DDX_Text(pDX, IDC_EDIT2, str);
}


BEGIN_MESSAGE_MAP(CSaveDialog, CDialog)
	
	ON_BN_CLICKED(IDOK, &CSaveDialog::OnBnClickedOk)
END_MESSAGE_MAP()


// CSaveDialog ��Ϣ�������



void CSaveDialog::OnBnClickedOk()
{


	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	string shuo = LPCSTR(str);
	double amuch = User::fun(LPCSTR(much));
	if (amuch <= 0)
	{
		AfxMessageBox(__T("������Ϸ�����Ҫ��������"));
		str = "";
		shuo = "";
		much = "";
		UpdateData(false);
		return;
	}

	CHomeDialog::readCache().doSomesthing(URecord::Do_Save, shuo, amuch);
	cH->refresh();
	cH->UpdateData(false);
	AfxMessageBox(__T("��Ǯ�ɹ�"));
	CDialog::OnCancel();
}
