// DlgEnhaLpf2.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DIP.h"
#include "DlgEnhaLpf3.h"


// CDlgEnhaLpf3 �Ի���

IMPLEMENT_DYNAMIC(CDlgEnhaLpf3, CDialog)

CDlgEnhaLpf3::CDlgEnhaLpf3(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgEnhaLpf3::IDD, pParent), m_iSize(3), m_iMove(1)
{
}

CDlgEnhaLpf3::~CDlgEnhaLpf3()
{
}

void CDlgEnhaLpf3::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_iSize);
	DDV_MinMaxDouble(pDX, m_iSize, 0, 512);
	DDX_Text(pDX, IDC_EDIT2, m_iMove);
	DDV_MinMaxDouble(pDX, m_iMove, 0, 10);
}

BEGIN_MESSAGE_MAP(CDlgEnhaLpf3, CDialog)
END_MESSAGE_MAP()


// CDlgEnhaLpf3 ��Ϣ�������
