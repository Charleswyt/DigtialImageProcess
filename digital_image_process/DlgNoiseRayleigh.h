#pragma once
// CDlgNoiseRayleigh �Ի���
class CDlgNoiseRayleigh : public CDialog
{
	DECLARE_DYNAMIC(CDlgNoiseRayleigh)
public:
	CDlgNoiseRayleigh(CWnd* pParent = NULL);			// ��׼���캯��
	virtual ~CDlgNoiseRayleigh();
	enum { IDD = IDD_DLG_NOISE_RAYLEIGH };				// �Ի�������
protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��
	DECLARE_MESSAGE_MAP()
public:
	double m_dRate, m_dSigma;							// ָ��������ֵ�ͷ���
};