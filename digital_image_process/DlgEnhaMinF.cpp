// DlgEnhaMinF.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DIP.h"
#include "DlgEnhaMinF.h"
// DlgEnhaMidF �Ի���

IMPLEMENT_DYNAMIC(CDlgEnhaMinF, CDialog)

CDlgEnhaMinF::CDlgEnhaMinF(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgEnhaMinF::IDD, pParent), m_iSize(3), m_iMove(1)
{
}

CDlgEnhaMinF::~CDlgEnhaMinF()
{
}

void CDlgEnhaMinF::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_iSize);
	DDV_MinMaxDouble(pDX, m_iSize, 0, 512);
	DDX_Text(pDX, IDC_EDIT2, m_iMove);
	DDV_MinMaxDouble(pDX, m_iMove, 0, 10);
}

BEGIN_MESSAGE_MAP(CDlgEnhaMinF, CDialog)
END_MESSAGE_MAP()


// CDlgEnhaMinF ��Ϣ�������
