#pragma once
// CDlgFreqLadderLPF �Ի���
class CDlgFreqLadderLPF : public CDialog
{
	DECLARE_DYNAMIC(CDlgFreqLadderLPF)
public:
	CDlgFreqLadderLPF(CWnd* pParent = NULL);			// ��׼���캯��
	virtual ~CDlgFreqLadderLPF();
	enum { IDD = IDD_DLG_FREQ_LADDERLPF };				// �Ի�������
protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��
	DECLARE_MESSAGE_MAP()
public:
	int m_nFreq;										// �����˲�����ֹƵ��D0
	int m_nF;											// �����˲���Ƶ��D1
};