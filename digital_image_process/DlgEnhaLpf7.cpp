// DlgEnhaLpf7.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DIP.h"
#include "DlgEnhaLpf7.h"
// CDlgEnhaLpf7 �Ի���

IMPLEMENT_DYNAMIC(CDlgEnhaLpf7, CDialog)

CDlgEnhaLpf7::CDlgEnhaLpf7(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgEnhaLpf7::IDD, pParent), m_iSize(3), m_iMove(1)
{
}

CDlgEnhaLpf7::~CDlgEnhaLpf7()
{
}

void CDlgEnhaLpf7::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_iSize);
	DDV_MinMaxDouble(pDX, m_iSize, 0, 512);
	DDX_Text(pDX, IDC_EDIT2, m_iMove);
	DDV_MinMaxDouble(pDX, m_iMove, 0, 10);
}

BEGIN_MESSAGE_MAP(CDlgEnhaLpf7, CDialog)
END_MESSAGE_MAP()


// CDlgEnhaLpf7 ��Ϣ�������
