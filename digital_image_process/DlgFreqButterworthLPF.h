#pragma once
// CDlgFreqGaussLPF �Ի���
class CDlgFreqButterworthLPF : public CDialog
{
	DECLARE_DYNAMIC(CDlgFreqButterworthLPF)
public:
	CDlgFreqButterworthLPF(CWnd* pParent = NULL);		// ��׼���캯��
	virtual ~CDlgFreqButterworthLPF();
	enum { IDD = IDD_DLG_FREQ_BUTTERWORTHLPF };			// �Ի�������
protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��
	DECLARE_MESSAGE_MAP()
public:
	int m_nFreq;										// ������˹�˲�����ֹƵ��
	int n;												// ������˹�˲�������
};