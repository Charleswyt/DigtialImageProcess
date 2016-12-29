// DlgFreqIdealHPF.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DIP.h"
#include "DlgFreqIdealHPF.h"


// CDlgFreqIdealHPF �Ի���

IMPLEMENT_DYNAMIC(CDlgFreqIdealHPF, CDialog)

CDlgFreqIdealHPF::CDlgFreqIdealHPF(
	CWnd* pParent /*=NULL*/)
	: CDialog(CDlgFreqIdealHPF::IDD, pParent)
	, m_nFreq( 128 )
{
}

CDlgFreqIdealHPF::~CDlgFreqIdealHPF()
{
}

void CDlgFreqIdealHPF::DoDataExchange(
	CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_nFreq);
	DDV_MinMaxInt(pDX, m_nFreq, 0, 256);
}


BEGIN_MESSAGE_MAP(CDlgFreqIdealHPF, CDialog)
END_MESSAGE_MAP()


// CDlgFreqIdealLPF ��Ϣ�������
