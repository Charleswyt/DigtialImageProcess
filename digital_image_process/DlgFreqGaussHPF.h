#pragma once
// CDlgFreqGaussHPF �Ի���
class CDlgFreqGaussHPF : public CDialog
{
	DECLARE_DYNAMIC(CDlgFreqGaussHPF)
public:
	CDlgFreqGaussHPF(CWnd* pParent = NULL);				// ��׼���캯��
	virtual ~CDlgFreqGaussHPF();
	enum { IDD = IDD_DLG_FREQ_GAUSSHPF };				// �Ի�������
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	DECLARE_MESSAGE_MAP()
public:
	double m_dSigma;									// ��˹�˲���Sigma����
};
