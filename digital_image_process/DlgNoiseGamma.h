#pragma once
// CDlgNoiseGamma �Ի���
class CDlgNoiseGamma : public CDialog
{
	DECLARE_DYNAMIC(CDlgNoiseGamma)
public:
	CDlgNoiseGamma(CWnd* pParent = NULL);				// ��׼���캯��
	virtual ~CDlgNoiseGamma();
	enum { IDD = IDD_DLG_NOISE_GAMMA };					// �Ի�������
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	DECLARE_MESSAGE_MAP()
public:
	double m_dA, m_dB;									// ٤����������������ֵ�ͷ���
};