// DlgEnhaMediaF.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DIP.h"
#include "DlgEnhaMediaF.h"
// CDlgEnhaMediaF �Ի���

IMPLEMENT_DYNAMIC(CDlgEnhaMediaF, CDialog)

CDlgEnhaMediaF::CDlgEnhaMediaF(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgEnhaMediaF::IDD, pParent), m_iSize(3), m_iMove(1)
{
}

CDlgEnhaMediaF::~CDlgEnhaMediaF()
{
}

void CDlgEnhaMediaF::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_iSize);
	DDV_MinMaxDouble(pDX, m_iSize, 0, 512);
	DDX_Text(pDX, IDC_EDIT2, m_iMove);
	DDV_MinMaxDouble(pDX, m_iMove, 0, 10);
}

BEGIN_MESSAGE_MAP(CDlgEnhaMediaF, CDialog)
END_MESSAGE_MAP()


// CDlgEnhaMediaF ��Ϣ�������
