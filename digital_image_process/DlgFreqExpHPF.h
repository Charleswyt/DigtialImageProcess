#pragma once
// CDlgFreqExpHPF �Ի���
class CDlgFreqExpHPF : public CDialog
{
	DECLARE_DYNAMIC(CDlgFreqExpHPF)
public:
	CDlgFreqExpHPF(CWnd* pParent = NULL);			// ��׼���캯��
	virtual ~CDlgFreqExpHPF();
	enum { IDD = IDD_DLG_FREQ_EXPHPF };				// �Ի�������
protected:
	virtual void DoDataExchange(CDataExchange* pDX);// DDX/DDV ֧��
	DECLARE_MESSAGE_MAP()
public:
	int m_nFreq;										// ָ���˲�����ֹƵ��
	int n;												// ָ���˲�������
};