#pragma once
// CDlgFreqButterworthHPF �Ի���
class CDlgFreqButterworthHPF : public CDialog
{
	DECLARE_DYNAMIC(CDlgFreqButterworthHPF)
public:
	CDlgFreqButterworthHPF(CWnd* pParent = NULL);			// ��׼���캯��
	virtual ~CDlgFreqButterworthHPF();
	enum { IDD = IDD_DLG_FREQ_BUTTERWORTHHPF };				// �Ի�������
protected:
	virtual void DoDataExchange(CDataExchange* pDX);		// DDX/DDV ֧��
	DECLARE_MESSAGE_MAP()
public:
	int m_nFreq;											// ������˹�˲�����ֹƵ��
	int n;													// ������˹�˲�������
};