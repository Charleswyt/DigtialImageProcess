#pragma once
// CDlgFreqLadderHPF �Ի���
class CDlgFreqLadderHPF : public CDialog
{
	DECLARE_DYNAMIC(CDlgFreqLadderHPF)
public:
	CDlgFreqLadderHPF(CWnd* pParent = NULL);			// ��׼���캯��
	virtual ~CDlgFreqLadderHPF();
	enum { IDD = IDD_DLG_FREQ_LADDERHPF };				// �Ի�������
protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��
	DECLARE_MESSAGE_MAP()
public:
	int m_nFreq;										// �����˲�����ֹƵ��D0
	int m_nF;											// �����˲���Ƶ��D1
};