// DlgFileInfoShow.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DIP.h"
#include "DlgFileInfoShow.h"


// CDlgFileInfoShow �Ի���

IMPLEMENT_DYNAMIC(CDlgFileInfoShow, CDialog)

CDlgFileInfoShow::CDlgFileInfoShow(
	CWnd* pParent /*=NULL*/)
	: CDialog(CDlgFileInfoShow::IDD, pParent)
{
}

CDlgFileInfoShow::~CDlgFileInfoShow()
{
}

void CDlgFileInfoShow::DoDataExchange( CDataExchange* pDX )
{
	CDialog::DoDataExchange(pDX);
	/*DDX_Text(pDX, IDC_EDIT1, m_nFreq);
	DDV_MinMaxInt(pDX, m_nFreq, 0, 65535);
	DDX_Text(pDX, IDC_EDIT2, m_nWidth);
	DDV_MinMaxInt(pDX, m_nWidth, 0, 32767);*/
}


BEGIN_MESSAGE_MAP(CDlgFileInfoShow, CDialog)
END_MESSAGE_MAP()


// CDlgFreqGaussBRF ��Ϣ�������
