// DlgFreqIdealLPF.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DIP.h"
#include "DlgFreqIdealLPF.h"


// CDlgFreqIdealLPF �Ի���

IMPLEMENT_DYNAMIC ( CDlgFreqIdealLPF, CDialog )

CDlgFreqIdealLPF::CDlgFreqIdealLPF (
    CWnd* pParent /*=NULL*/ )
    : CDialog ( CDlgFreqIdealLPF::IDD, pParent )
    , m_nFreq ( 128 )
{
}

CDlgFreqIdealLPF::~CDlgFreqIdealLPF()
{
}

void CDlgFreqIdealLPF::DoDataExchange (
    CDataExchange* pDX )
{
    CDialog::DoDataExchange ( pDX );
    DDX_Text ( pDX, IDC_EDIT1, m_nFreq );
    DDV_MinMaxInt ( pDX, m_nFreq, 0, 256 );
}


BEGIN_MESSAGE_MAP ( CDlgFreqIdealLPF, CDialog )
END_MESSAGE_MAP()


// CDlgFreqIdealLPF ��Ϣ�������
