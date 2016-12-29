// DlgPointWin.cpp : implementation file
#include "stdafx.h"
#include "DIP.h"
#include "DlgPointWin.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**********************************************/
// CDlgPointWin dialog

CDlgPointWin::CDlgPointWin(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgPointWin::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgPointWin)
	m_bLow = 0;
	m_bUp = 0;
	//}}AFX_DATA_INIT
}

void CDlgPointWin::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgPointWin)
	DDX_Text(pDX, IDC_EDIT_Low, m_bLow);
	DDV_MinMaxByte(pDX, m_bLow, 0, 255);
	DDX_Text(pDX, IDC_EDIT_Up, m_bUp);
	DDV_MinMaxByte(pDX, m_bUp, 0, 255);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlgPointWin, CDialog)
	//{{AFX_MSG_MAP(CDlgPointWin)
	ON_EN_KILLFOCUS(IDC_EDIT_Low, OnKillfocusEDITLow)
	ON_EN_KILLFOCUS(IDC_EDIT_Up, OnKillfocusEDITUp)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/**********************************************/
// CDlgPointWin message handlers

BOOL CDlgPointWin::OnInitDialog()
{
	// ����Ĭ��OnInitDialog����
	CDialog::OnInitDialog();
	// ��ȡ����ֱ��ͼ�ı�ǩ
	CWnd* pWnd = GetDlgItem(IDC_COORD);
	// �����������¼�����Ч����
	pWnd->GetClientRect(m_MouseRect);
	pWnd->ClientToScreen(&m_MouseRect);
	CRect rect;
	GetClientRect(rect);
	ClientToScreen(&rect);
	m_MouseRect.top -= rect.top;
	m_MouseRect.left -= rect.left;
	// ���ý�������¼�����Ч����
	m_MouseRect.top += 25;
	m_MouseRect.left += 10;
	m_MouseRect.bottom = m_MouseRect.top + 255;
	m_MouseRect.right = m_MouseRect.left + 256;
	m_iIsDraging = 0;											// ��ʼ���϶�״̬
	return TRUE;
}

void CDlgPointWin::OnKillfocusEDITLow()
{
	UpdateData(TRUE);											// ����
	if (m_bLow > m_bUp)											// �ж��Ƿ����޳�������
	{
		// ����
		BYTE bTemp = m_bLow;
		m_bLow = m_bUp;
		m_bUp = bTemp;
		
		UpdateData(FALSE);										// ����
	}

	InvalidateRect(m_MouseRect, TRUE);							// �ػ�
}

void CDlgPointWin::OnKillfocusEDITUp()
{
	
	UpdateData(TRUE);											// ����
	if (m_bLow > m_bUp)											// �ж��Ƿ����޳�������
	{
		// ����
		BYTE bTemp = m_bLow;
		m_bLow = m_bUp;
		m_bUp = bTemp;
		
		UpdateData(FALSE);										// ����
	}

	InvalidateRect(m_MouseRect, TRUE);							// �ػ�
}

void CDlgPointWin::OnLButtonDown(UINT nFlags, CPoint point)
{
	if (m_MouseRect.PtInRect(point))							// ���û�������������ʼ�϶�
	{
		if (point.x == (m_MouseRect.left + m_bLow))
		{
			m_iIsDraging = 1;									// �����϶�״̬1���϶�����
			::SetCursor(::LoadCursor(NULL, IDC_SIZEWE));		// ���Ĺ��
		}

		else
			if (point.x == (m_MouseRect.left + m_bUp))
			{
				m_iIsDraging = 2;								// �����϶�״̬Ϊ2���϶�����
				::SetCursor(::LoadCursor(NULL, IDC_SIZEWE));	// ���Ĺ��
			}
	}

	// Ĭ�ϵ��������������¼�
	CDialog::OnLButtonDown(nFlags, point);
}

void CDlgPointWin::OnMouseMove(UINT nFlags, CPoint point)
{
	if (m_MouseRect.PtInRect(point))							// �жϵ�ǰ����Ƿ��ڻ�������
	{
		if (m_iIsDraging != 0)									// �ж��Ƿ������϶�
		{
			if (m_iIsDraging == 1)								// �ж������϶����޻�������
			{
				if (point.x - m_MouseRect.left < m_bUp)			// �ж��Ƿ�����<����
					m_bLow = (BYTE)(point.x - m_MouseRect.left);// ��������

				else
				{
					m_bLow = m_bUp - 1;							// �����Ϲ����ޣ�����Ϊ����-1
					point.x = m_MouseRect.left + m_bUp - 1;		// �������λ��
				}
			}

			else
			{
				// �����϶�����
				if (point.x - m_MouseRect.left > m_bLow)		// �ж��Ƿ�����>����					
					m_bUp = (BYTE)(point.x - m_MouseRect.left);	// ��������

				else
				{
					m_bUp = m_bLow + 1;							// �����Ϲ����ޣ�����Ϊ���ޣ�1
					point.x = m_MouseRect.left + m_bLow + 1;	// �������λ��
				}
			}
			::SetCursor(::LoadCursor(NULL, IDC_SIZEWE));		// ���Ĺ��
			UpdateData(FALSE);									// ����
			InvalidateRect(m_MouseRect, TRUE);					// ����
		}

		else
			if (point.x == (m_MouseRect.left + m_bLow) || point.x == (m_MouseRect.left + m_bUp))
				::SetCursor(::LoadCursor(NULL, IDC_SIZEWE));	// ���Ĺ��
	}

	CDialog::OnMouseMove(nFlags, point);						// Ĭ������ƶ������¼�
}

void CDlgPointWin::OnLButtonUp(UINT nFlags, CPoint point)
{
	if (m_iIsDraging != 0)										// ���û��ͷ�������ֹͣ�϶�
		m_iIsDraging = 0;										// �����϶�״̬

	CDialog::OnLButtonUp(nFlags, point);						// Ĭ���ͷ������������¼�
}

void CDlgPointWin::OnPaint()
{
	CString str;												// �ַ���
	CPaintDC dc(this);											// �豸������
	CWnd* pWnd = GetDlgItem(IDC_COORD);							// ��ȡ����������ı���
	CDC* pDC = pWnd->GetDC();									// ָ��
	pWnd->Invalidate();
	pWnd->UpdateWindow();
	pDC->Rectangle(0, 0, 330, 300);
	CPen* pPenRed = new CPen;									// �������ʶ���
	pPenRed->CreatePen(PS_SOLID, 2, RGB(0, 0, 0));				// ��ɫ����
	CPen* pPenBlue = new CPen;// �������ʶ���
	pPenBlue->CreatePen(PS_SOLID, 2, RGB(0, 0, 0));				// ��ɫ����
	CPen* pPenGreen = new CPen;									// �������ʶ���
	pPenGreen->CreatePen(PS_DOT, 1, RGB(0, 0, 0));				// ��ɫ����
	CGdiObject* pOldPen = pDC->SelectObject(pPenRed);			// ѡ�е�ǰ��ɫ���ʣ���������ǰ�Ļ���
	pDC->MoveTo(10, 10);										// ����������
	pDC->LineTo(10, 280);										// ��ֱ��
	pDC->LineTo(320, 280);										// ˮƽ��
	str.Format(L"0");											// д����
	pDC->TextOut(10, 281, str);
	str.Format(L"255");
	pDC->TextOut(265, 281, str);
	pDC->TextOut(11, 25, str);
	pDC->LineTo(315, 275);										// ����X���ͷ
	pDC->MoveTo(320, 280);
	pDC->LineTo(315, 285);
	pDC->MoveTo(10, 10);										// ����X���ͷ
	pDC->LineTo(5, 15);
	pDC->MoveTo(10, 10);
	pDC->LineTo(15, 15);
	pDC->SelectObject(pPenGreen);								// ���ĳ���ɫ����
	pDC->MoveTo(m_bLow + 10, 25);								// ���ƴ���������
	pDC->LineTo(m_bLow + 10, 280);
	pDC->MoveTo(m_bUp + 10, 25);
	pDC->LineTo(m_bUp + 10, 280);
	pDC->SelectObject(pPenBlue);								// ���ĳ���ɫ����
	str.Format(L"(%d, %d)", m_bLow, m_bLow);					// ��������ֵ
	pDC->TextOut(m_bLow + 10, 281 - m_bLow, str);
	str.Format(L"(%d, %d)", m_bUp, m_bUp);
	pDC->TextOut(m_bUp + 10, 281 - m_bUp, str);
	pDC->MoveTo(10, 280);										// �����û�ָ���Ĵ��ڣ�ע��ת������ϵ��
	pDC->LineTo(m_bLow + 10, 280);
	pDC->LineTo(m_bLow + 10, 280 - m_bLow);
	pDC->LineTo(m_bUp + 10, 280 - m_bUp);
	pDC->LineTo(m_bUp + 10, 25);
	pDC->LineTo(265, 25);
	pDC->SelectObject(pOldPen);									// �ָ���ǰ�Ļ���
	pDC->MoveTo(10, 25);										// ���Ʊ�Ե
	pDC->LineTo(265, 25);
	pDC->LineTo(265, 280);

	delete pPenRed;												// ɾ���µĻ���
	delete pPenBlue;
	delete pPenGreen;
}

void CDlgPointWin::OnOK()
{
	// �ж��Ƿ����޳�������
	if (m_bLow > m_bUp)											// ����
	{
		BYTE bTemp = m_bLow;
		m_bLow = m_bUp;
		m_bUp = bTemp;
	}
	CDialog::OnOK();											// Ĭ�ϴ����¼�
}

