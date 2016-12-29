// CDlgEdgeSimpthre.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DIP.h"
#include "DlgEdgeSimpthre.h"


// CDlgFreqGaussLPF �Ի���

IMPLEMENT_DYNAMIC(CDlgEdgeSimpthre, CDialog)

CDlgEdgeSimpthre::CDlgEdgeSimpthre(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgEdgeSimpthre::IDD, pParent), m_iThreshold(128)
{
}

CDlgEdgeSimpthre::~CDlgEdgeSimpthre()
{
}

void CDlgEdgeSimpthre::DoDataExchange(
	CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_iThreshold);
	DDV_MinMaxDouble(pDX, m_iThreshold, 0, 256);
}

BEGIN_MESSAGE_MAP(CDlgEdgeSimpthre, CDialog)
END_MESSAGE_MAP()


// CDlgFreqGaussLPF ��Ϣ�������
