#pragma once
// CDlgNoiseSaltPepper �Ի���

class CDlgNoiseSaltPepper : public CDialog
{
	DECLARE_DYNAMIC(CDlgNoiseSaltPepper)
public:
	CDlgNoiseSaltPepper(CWnd* pParent = NULL);			// ��׼���캯��
	virtual ~CDlgNoiseSaltPepper();
	enum { IDD = IDD_DLG_NOISE_SALTPEPPER };				// �Ի�������
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	DECLARE_MESSAGE_MAP()
public:
	double m_dRate;										// ��������ǿ��
};