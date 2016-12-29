#include "stdafx.h"
#include "DIP.h"

#include "DIPDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNCREATE(CDIPDoc, CDocument)

BEGIN_MESSAGE_MAP(CDIPDoc, CDocument)
	//{{AFX_MSG_MAP(CDIPDoc)
	ON_COMMAND(ID_FILE_REOPEN, OnFileReopen)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

CDIPDoc::CDIPDoc()
{
	m_sizeDoc = CSize(1, 1);
	m_pPalette = NULL;
	// Ĭ�ϱ���ɫ����ɫ
	m_refColorBKG = 0x00808080;
}

CDIPDoc::~CDIPDoc()
{
	
	if (m_pPalette != NULL)				// �жϵ�ɫ���Ƿ����
	{
		
		delete m_pPalette;// �����ɫ��
	}
}

BOOL CDIPDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	return TRUE;
}

#ifdef _DEBUG
void CDIPDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDIPDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

BOOL CDIPDoc::CanCloseFrame(CFrameWnd* pFrame)
{
	return CDocument::CanCloseFrame(pFrame);
}

void CDIPDoc::DeleteContents()
{
	if (m_pPalette != NULL)
		m_pPalette->DeleteObject();

	CDocument::DeleteContents();
}


void CDIPDoc::Init()
{
	if (!m_Image.IsValidate())								// ���ͼ����Ч��ֱ�ӷ���
		return;

	// �����ĵ���С
	m_sizeDoc = CSize(m_Image.GetWidthPixel(), m_Image.GetHeight());

	if (m_pPalette != NULL)									// �жϵ�ɫ���Ƿ�Ϊ��
	{
		delete m_pPalette;									// ɾ����ɫ�����
		m_pPalette = NULL;									// ���õ�ɫ��Ϊ��
	}

	CClientDC dc(NULL);										// ���ǵ�ɫ����ʾģʽ����ֱ�ӷ���
	if ((dc.GetDeviceCaps(RASTERCAPS) & RC_PALETTE) == 0)
		return;

	m_pPalette = new CPalette;								// �����µ�ɫ��
	int nEntries = m_Image.GetColorTableEntriesNum();

	if (nEntries == 0)
		return;

	LOGPALETTE* lpPal = (LOGPALETTE*) new BYTE[sizeof(LOGPALETTE)
		+ (sizeof(PALETTEENTRY) * (nEntries - 1))];

	lpPal->palVersion = 0x300;								// ���ð汾��

	lpPal->palNumEntries = (WORD)nEntries;
	RGBQUAD* pPal = (RGBQUAD*)(m_Image.GetColorTable());	// ������ɫ��Ŀ
	int i;

	for (i = 0; i < nEntries; i++)							// ������ɫ��
	{
		lpPal->palPalEntry[i].peRed = pPal[i].rgbRed;		// ��ȡ��ɫ����
		lpPal->palPalEntry[i].peGreen = pPal[i].rgbGreen;	// ��ȡ��ɫ����
		lpPal->palPalEntry[i].peBlue = pPal[i].rgbBlue;		// ��ȡ��ɫ����
		lpPal->palPalEntry[i].peFlags = 0;					// ����λ
	}
	m_pPalette->CreatePalette(lpPal);						// �����߼���ɫ�崴����ɫ�壬������ָ��
	delete[] lpPal;
}


BOOL CDIPDoc::OnOpenDocument(LPCTSTR lpszPathName)
{
	DeleteContents();
	BeginWaitCursor();										// ���Ĺ����״
	if (!m_Image.AttachFromFile(lpszPathName))				// ��ȡͼ�񲢸��ӵ�m_Image��
	{
		EndWaitCursor();
		AfxMessageBox(L"���ļ�ʱ����!��ȷ����ȷ��λͼ(*.bmp)�ļ����͡�");
		return FALSE;
	}
	EndWaitCursor();										// �ָ������״
	if (!m_Image.m_lpData)									// �ж϶�ȡ�ɹ���
	{
		CString strMsg;
		strMsg = L"��ȡͼ��ʱ���������ǲ�֧�ָ����͵�ͼ���ļ���";
		MessageBox(NULL, strMsg, L"ϵͳ��ʾ",
			MB_ICONINFORMATION | MB_OK);					// ��ʾ����
		return FALSE;										// ����FALSE
	}

	Init();													// ��ͼ��ĳߴ�͵�ɫ����Ϣ���г�ʼ��
	SetPathName(lpszPathName);								// �����ļ�����
	m_OImage = m_Image;										// ������ǰm_Image��m_OImage
	SetModifiedFlag(FALSE);									// ��ʼ���ͱ��ΪFALSE
	return TRUE;											// ����TRUE
}

void CDIPDoc::OnFileReopen()							// ���´�ͼ�񣬷��������޸�
{
	if (IsModified())										// �жϵ�ǰͼ���Ƿ��Ѿ����Ķ�
		if (MessageBox(NULL,								// ��ʾ�û��ò�������ʧ���е�ǰ���޸�
			L"���´�ͼ�񽫶�ʧ���иĶ����Ƿ������",
			L"ϵͳ��ʾ", MB_ICONQUESTION | MB_YESNO) == IDNO)
			return;											// �û�ȡ��������ֱ�ӷ���

	CString strPathName;
	strPathName = GetPathName();							// ��ȡ��ǰ�ļ�·��
	BeginWaitCursor();										// ���Ĺ����״
	if (!m_Image.AttachFromFile(strPathName))
	{
		EndWaitCursor();
		AfxMessageBox(L"���ļ�ʱ����!��ȷ����ȷ��λͼ(*.bmp)�ļ����͡�");
		return;
	}

	if (!m_Image.m_lpData)									// �ж϶�ȡ�ɹ���
	{
		CString strMsg;										// ʧ�ܣ����ܷ�BMP��ʽ
		strMsg = L"��ȡͼ��ʱ���������ǲ�֧�ָ����͵�ͼ���ļ���";
		MessageBox(NULL, strMsg, L"ϵͳ��ʾ",
			MB_ICONINFORMATION | MB_OK);					// ��ʾ����

		return;												// ����
	}
	Init();													//��ͼ��ĳߴ�͵�ɫ����Ϣ���г�ʼ��
	SetModifiedFlag(FALSE);									// ��ʼ���޸ı�ʶΪFALSE
	UpdateAllViews(NULL);									// ˢ��
	EndWaitCursor();										// �ָ������״
	return;													// ����
}

BOOL CDIPDoc::OnSaveDocument(LPCTSTR lpszPathName)
{
	if (!m_Image.SaveToFile(lpszPathName))
	{
		CString strMsg;
		strMsg = L"�޷�����BMPͼ��";

		MessageBox(NULL, strMsg, L"ϵͳ��ʾ",
			MB_ICONINFORMATION | MB_OK);					// ��ʾ����
		return FALSE;
	}
	EndWaitCursor();										// �ָ������״
	SetModifiedFlag(FALSE);									// �����ͱ��ΪFALSE
	return TRUE;
}