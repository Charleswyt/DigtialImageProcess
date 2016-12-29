#include "stdafx.h"
#include "DIP.h"
#include "DlgColor.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CDlgColor::CDlgColor(CWnd* pParent /*=NULL*/) : CDialog(CDlgColor::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgColor)
	// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

void CDlgColor::DoDataExchange(CDataExchange*
	pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgColor)
	DDX_Control(pDX, IDC_COLOR_LIST, m_lstColor);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlgColor, CDialog)
	//{{AFX_MSG_MAP(CDlgColor)
	ON_LBN_DBLCLK(IDC_COLOR_LIST, OnDblclkColorList)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CDlgColor::OnInitDialog()
{
	int i;								// ѭ������
	CDialog::OnInitDialog();			// ����Ĭ��OnInitDialog����
	for (i = 0; i < m_nColorCount; i++)	// ���α��ɫ����
		m_lstColor.AddString(m_lpColorName + i * m_nNameLen);
	m_lstColor.SetCurSel(m_nColor);		// ѡ�г�ʼ�����
	
	return TRUE;
}

void CDlgColor::OnDblclkColorList()
{
	OnOK();								// ˫���¼���ֱ�ӵ���OnOK()��Ա����
}

void CDlgColor::OnOK()
{
	m_nColor = m_lstColor.GetCurSel();	// �û�����ȷ����ť
	CDialog::OnOK();					// ����Ĭ�ϵ�OnOK()����
}