// TransferDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Sixth.h"
#include "TransferDialog.h"
#include "afxdialogex.h"
#include"HomeDialog.h"
#include"URecord.h"
// CTransferDialog �Ի���

IMPLEMENT_DYNAMIC(CTransferDialog, CDialog)

CTransferDialog::CTransferDialog(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DIALOG3, pParent)
	, aim_id(_T(""))
	, much(0)
	, description(_T(""))
{

}

CTransferDialog::~CTransferDialog()
{
}

void CTransferDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, aim_id);
	DDX_Text(pDX, IDC_EDIT2, much);
	DDX_Text(pDX, IDC_EDIT6, description);
}


BEGIN_MESSAGE_MAP(CTransferDialog, CDialog)
	ON_BN_CLICKED(IDOK, &CTransferDialog::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CTransferDialog::OnBnClickedCancel)
END_MESSAGE_MAP()


// CTransferDialog ��Ϣ�������


void CTransferDialog::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	try
	{
		UpdateData(true);
		string id = LPCSTR(aim_id);
		string str = LPCSTR(description);
		if (id=="")
		{
			MessageBox("�벻Ҫ��Ƥ���տ���IDΪ��", __T("�տ���IDΪ��"));
			return;
		}
		if (much<=0)
		{
			MessageBox("������Ϸ�����Ҫ��������",__T("������Ϸ�"));
			aim_id = "";
			description = "";
			much = 0;
			UpdateData(false);
			return;
		}
		if (!User(id).isId())
		{
			MessageBox("�벻Ҫ��Ƥ���տ���ID������", __T("�տ��˲�����"));
			return;
		}

		CHomeDialog::readCache().doSomesthing(URecord::Do_Transfer,str, id, much);
		MessageBox("�ţ������ĳɹ���",__T("ת�˳ɹ�"));
		cH->refresh();
		cH->UpdateData(false);
		CDialog::OnCancel();
	}
	catch (const std::exception&)
	{

	}
	catch (string str)
	{
		AfxMessageBox(__T(&str[0]));
	}
	catch (...)
	{
		AfxMessageBox(__T(""));
	}
}


void CTransferDialog::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	
	CDialog::OnCancel();
}
