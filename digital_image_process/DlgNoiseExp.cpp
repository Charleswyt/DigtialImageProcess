// DlgNoiseExp.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DIP.h"
#include "DlgNoiseExp.h"


// CDlgNoiseGauss �Ի���

IMPLEMENT_DYNAMIC(CDlgNoiseExp, CDialog)

CDlgNoiseExp::CDlgNoiseExp(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgNoiseExp::IDD, pParent), m_dA(0.5)
{
}

CDlgNoiseExp::~CDlgNoiseExp()
{
}

void CDlgNoiseExp::DoDataExchange(
	CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_dA);
	DDV_MinMaxDouble(pDX, m_dA, 0, 256);
}


BEGIN_MESSAGE_MAP(CDlgNoiseExp, CDialog)
END_MESSAGE_MAP()


// CDlgFreqGaussLPF ��Ϣ�������
