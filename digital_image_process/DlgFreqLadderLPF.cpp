#include "stdafx.h"
#include "DIP.h"
#include "DlgFreqLadderLPF.h"

// CDlgFreqLadderHPF �Ի���
IMPLEMENT_DYNAMIC(CDlgFreqLadderLPF, CDialog)

CDlgFreqLadderLPF::CDlgFreqLadderLPF(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgFreqLadderLPF::IDD, pParent)
	, m_nFreq(128), m_nF(160)
{
}

CDlgFreqLadderLPF::~CDlgFreqLadderLPF()
{
}

void CDlgFreqLadderLPF::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_nFreq);
	DDV_MinMaxDouble(pDX, m_nFreq, 0, 256);
	DDX_Text(pDX, IDC_EDIT2, m_nF);
	DDV_MinMaxDouble(pDX, m_nF, 0, 256);
}


BEGIN_MESSAGE_MAP(CDlgFreqLadderLPF, CDialog)
END_MESSAGE_MAP()


// CDlgFreqGaussHPF ��Ϣ�������
