#pragma once
// CDlgFreqExpLPF �Ի���
class CDlgFreqExpLPF : public CDialog
{
	DECLARE_DYNAMIC(CDlgFreqExpLPF)
public:
	CDlgFreqExpLPF(CWnd* pParent = NULL);				// ��׼���캯��
	virtual ~CDlgFreqExpLPF();
	enum { IDD = IDD_DLG_FREQ_EXPLPF };					// �Ի�������
protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��
	DECLARE_MESSAGE_MAP()
public:
	int m_nFreq;										// ָ���˲�����ֹƵ��
	int n;												// ָ���˲�������
};