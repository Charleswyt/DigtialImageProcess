#pragma once
// CDlgNoiseGauss �Ի���
class CDlgNoiseGauss : public CDialog
{
	DECLARE_DYNAMIC(CDlgNoiseGauss)
public:
	CDlgNoiseGauss(CWnd* pParent = NULL);				// ��׼���캯��
	virtual ~CDlgNoiseGauss();
	enum { IDD = IDD_DLG_NOISE_GAUSS };					// �Ի�������
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	DECLARE_MESSAGE_MAP()
public:
	double m_dRate, m_dSigma;							// ��˹������ֵ�ͷ���
};