// CDlgFreqHighGain.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DIP.h"
#include "DlgFreqHighGain.h"


// CDlgFreqGaussLPF �Ի���

IMPLEMENT_DYNAMIC(CDlgFreqHighGain, CDialog)

CDlgFreqHighGain::CDlgFreqHighGain(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgFreqHighGain::IDD, pParent), m_dCofficient(1.1)
{
}

CDlgFreqHighGain::~CDlgFreqHighGain()
{
}

void CDlgFreqHighGain::DoDataExchange(
	CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_dCofficient);
	DDV_MinMaxDouble(pDX, m_dCofficient, 0, 256);
}


BEGIN_MESSAGE_MAP(CDlgFreqHighGain, CDialog)
END_MESSAGE_MAP()


// CDlgFreqGaussLPF ��Ϣ�������
