// DlgRGBHist.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DIP.h"
#include "DlgRGBHist.h"

// CDlgRGBHist �Ի���

IMPLEMENT_DYNAMIC(CDlgRGBHist, CDialog)

CDlgRGBHist::CDlgRGBHist(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgRGBHist::IDD, pParent)
	, m_pdHistR(NULL), m_pdHistG(NULL), m_pdHistB(NULL)
{
}

CDlgRGBHist::~CDlgRGBHist()
{
}

void CDlgRGBHist::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgRGBHist, CDialog)
	ON_WM_PAINT()
END_MESSAGE_MAP()

void CDlgRGBHist::OnPaint()
{
	CPaintDC dc(this);
	CString str;
	CWnd* pWnd = GetDlgItem(IDC_HIST);						// ��ȡ��������Ŀؼ�
	CDC* pDC = pWnd->GetDC();								// ָ��
	pWnd->Invalidate();
	pWnd->UpdateWindow();
	pDC->Rectangle(0, 0, 320, 250);
	CPen* pPenBlack = new CPen;								// �������ʶ���
	pPenBlack->CreatePen(PS_SOLID, 1, RGB(0, 0, 0));		// ��ɫ����
	CPen* pPenRed = new CPen;								// �������ʶ���
	pPenRed->CreatePen(PS_SOLID, 1, RGB(255, 0, 0));		// ��ɫ����
	CPen* pPenBlue = new CPen;								// �������ʶ���
	pPenBlue->CreatePen(PS_SOLID, 1, RGB(0, 0, 255));		// ��ɫ����
	CPen* pPenGreen = new CPen;								// �������ʶ���
	pPenGreen->CreatePen(PS_SOLID, 1, RGB(0, 255, 0));		// ��ɫ����
	CGdiObject* pOldPen = pDC->SelectObject(pPenBlack);		// ѡ�е�ǰ��ɫ���ʣ���������ǰ�Ļ���
	
	/*************************** ��Ϸ��� ***************************/

	pDC->MoveTo(10, 10);									// ����������	
	pDC->LineTo(10, 240);									// ��ֱ��
	pDC->LineTo(310, 240);									// ˮƽ��

	// дX��̶�ֵ
	str.Format(L"0");
	pDC->TextOut(10, 243, str);
	str.Format(L"50");
	pDC->TextOut(60, 243, str);
	str.Format(L"100");
	pDC->TextOut(110, 243, str);
	str.Format(L"150");
	pDC->TextOut(160, 243, str);
	str.Format(L"200");
	pDC->TextOut(210, 243, str);
	str.Format(L"255");
	pDC->TextOut(260, 243, str);

	int i;
	for (i = 0; i < 256; i += 5)							// ����X��̶�
	{
		if ((i & 1) == 0)
		{
			// 10�ı���
			pDC->MoveTo(i + 10, 240);
			pDC->LineTo(i + 10, 234);
		}

		else
		{
			// 5�ı���
			pDC->MoveTo(i + 10, 240);
			pDC->LineTo(i + 10, 236);
		}
	}

	// ����X���ͷ
	pDC->MoveTo(305, 235);
	pDC->LineTo(310, 240);
	pDC->LineTo(305, 245);
	// ����X���ͷ
	pDC->MoveTo(10, 10);
	pDC->LineTo(5, 15);
	pDC->MoveTo(10, 10);
	pDC->LineTo(15, 15);
	
	double maxHistR = 0;
	double maxHistG = 0;
	double maxHistB = 0;

	for (i = 0; i < 256; i++)
	{
		maxHistR = max(maxHistR, m_pdHistR[i]);
		maxHistG = max(maxHistG, m_pdHistG[i]);
		maxHistB = max(maxHistB, m_pdHistB[i]);
	}

	pDC->SelectObject(pPenRed);

	for (i = 0; i < 256; i++)
	{
		pDC->MoveTo(i + 10, 240);
		pDC->LineTo(i + 10, int(240 - m_pdHistR[i] / maxHistB * 240));
	}

	pDC->SelectObject(pPenGreen);

	for (i = 0; i < 256; i++)
	{
		pDC->MoveTo(i + 10, 240);
		pDC->LineTo(i + 10, int(240 - m_pdHistG[i] / maxHistB * 240));
	}

	pDC->SelectObject(pPenBlue);

	for (i = 0; i < 256; i++)
	{
		pDC->MoveTo(i + 10, 240);
		pDC->LineTo(i + 10, int(240 - m_pdHistB[i] / maxHistB * 240));
	}

	// �ָ���ǰ�Ļ���
	pDC->SelectObject(pOldPen);



	/*************************** R���� ***************************/

	pDC->MoveTo(410, 10);									// ����������	
	pDC->LineTo(410, 240);									// ��ֱ��
	pDC->LineTo(710, 240);									// ˮƽ��

	// дX��̶�ֵ
	str.Format(L"0");
	pDC->TextOut(410, 243, str);
	str.Format(L"50");
	pDC->TextOut(460, 243, str);
	str.Format(L"100");
	pDC->TextOut(510, 243, str);
	str.Format(L"150");
	pDC->TextOut(560, 243, str);
	str.Format(L"200");
	pDC->TextOut(610, 243, str);
	str.Format(L"255");
	pDC->TextOut(660, 243, str);

	for (i = 0; i < 256; i += 5)							// ����X��̶�
	{
		if ((i & 1) == 0)
		{
			// 10�ı���
			pDC->MoveTo(i + 400, 240);
			pDC->LineTo(i + 400, 234);
		}

		else
		{
			// 5�ı���
			pDC->MoveTo(i + 400, 240);
			pDC->LineTo(i + 400, 236);
		}
	}

	// ����X���ͷ
	pDC->MoveTo(705, 235);
	pDC->LineTo(710, 240);
	pDC->LineTo(705, 245);
	// ����X���ͷ
	pDC->MoveTo(410, 10);
	pDC->LineTo(405, 15);
	pDC->MoveTo(410, 10);
	pDC->LineTo(415, 15);

	for (i = 0; i < 256; i++)
		maxHistR = max(maxHistR, m_pdHistG[i]);

	pDC->SelectObject(pPenRed);

	for (i = 0; i < 256; i++)
	{
		pDC->MoveTo(i + 400, 240);
		pDC->LineTo(i + 400, int(240 - m_pdHistR[i] / maxHistR * 240));
	}

	// �ָ���ǰ�Ļ���
	pDC->SelectObject(pOldPen);


	/*************************** G���� ***************************/

	pDC->MoveTo(10, 300);									// ����������	
	pDC->LineTo(10, 530);									// ��ֱ��
	pDC->LineTo(310, 530);									// ˮƽ��

															// дX��̶�ֵ
	str.Format(L"0");
	pDC->TextOut(10, 533, str);
	str.Format(L"50");
	pDC->TextOut(60, 533, str);
	str.Format(L"100");
	pDC->TextOut(110, 533, str);
	str.Format(L"150");
	pDC->TextOut(160, 533, str);
	str.Format(L"200");
	pDC->TextOut(210, 533, str);
	str.Format(L"255");
	pDC->TextOut(260, 533, str);

	for (i = 0; i < 256; i += 5)							// ����X��̶�
	{
		if ((i & 1) == 0)
		{
			// 10�ı���
			pDC->MoveTo(i + 10, 530);
			pDC->LineTo(i + 10, 524);
		}

		else
		{
			// 5�ı���
			pDC->MoveTo(i + 10, 530);
			pDC->LineTo(i + 10, 526);
		}
	}

	// ����X���ͷ
	pDC->MoveTo(305, 525);
	pDC->LineTo(310, 530);
	pDC->LineTo(305, 535);
	// ����X���ͷ
	pDC->MoveTo(10, 300);
	pDC->LineTo(5, 305);
	pDC->MoveTo(10, 300);
	pDC->LineTo(15, 305);

	for (i = 0; i < 256; i++)
		maxHistG = max(maxHistB, m_pdHistG[i]);

	pDC->SelectObject(pPenGreen);

	for (i = 0; i < 256; i++)
	{
		pDC->MoveTo(i + 10, 530);
		pDC->LineTo(i + 10, int(530 - m_pdHistG[i] / maxHistG * 240));
	}

	// �ָ���ǰ�Ļ���
	pDC->SelectObject(pOldPen);

	/*************************** B���� ***************************/

	pDC->MoveTo(410, 300);									// ����������	
	pDC->LineTo(410, 530);									// ��ֱ��
	pDC->LineTo(710, 530);									// ˮƽ��

	// дX��̶�ֵ
	str.Format(L"0");
	pDC->TextOut(410, 533, str);
	str.Format(L"50");
	pDC->TextOut(460, 533, str);
	str.Format(L"100");
	pDC->TextOut(510, 533, str);
	str.Format(L"150");
	pDC->TextOut(560, 533, str);
	str.Format(L"200");
	pDC->TextOut(610, 533, str);
	str.Format(L"255");
	pDC->TextOut(660, 533, str);

	for (i = 0; i < 256; i += 5)							// ����X��̶�
	{
		if ((i & 1) == 0)
		{
			// 10�ı���
			pDC->MoveTo(i + 410, 530);
			pDC->LineTo(i + 410, 524);
		}

		else
		{
			// 5�ı���
			pDC->MoveTo(i + 410, 530);
			pDC->LineTo(i + 410, 526);
		}
	}

	// ����X���ͷ
	pDC->MoveTo(705, 525);
	pDC->LineTo(710, 530);
	pDC->LineTo(705, 535);
	// ����X���ͷ
	pDC->MoveTo(410, 300);
	pDC->LineTo(405, 305);
	pDC->MoveTo(410, 300);
	pDC->LineTo(415, 305);
	

	for (i = 0; i < 256; i++)
		maxHistB = max(maxHistB, m_pdHistB[i]);

	pDC->SelectObject(pPenBlue);

	for (i = 0; i < 256; i++)
	{
		pDC->MoveTo(i + 410, 530);
		pDC->LineTo(i + 410, int(530 - m_pdHistB[i] / maxHistB * 240));
	}

	// �ָ���ǰ�Ļ���
	pDC->SelectObject(pOldPen);


	// ɾ���µĻ���
	delete pPenRed;
	delete pPenBlue;
	delete pPenGreen;
}
