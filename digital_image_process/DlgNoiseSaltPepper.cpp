// CDlgNoiseSaltPepper.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DIP.h"
#include "DlgNoiseSaltPepper.h"


// CDlgFreqGaussLPF �Ի���

IMPLEMENT_DYNAMIC(CDlgNoiseSaltPepper, CDialog)

CDlgNoiseSaltPepper::CDlgNoiseSaltPepper(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgNoiseSaltPepper::IDD, pParent), m_dRate(0.02)
{
}

CDlgNoiseSaltPepper::~CDlgNoiseSaltPepper()
{
}

void CDlgNoiseSaltPepper::DoDataExchange(
	CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_dRate);
	DDV_MinMaxDouble(pDX, m_dRate, 0, 1);
}

BEGIN_MESSAGE_MAP(CDlgNoiseSaltPepper, CDialog)
END_MESSAGE_MAP()


// CDlgFreqGaussLPF ��Ϣ�������
