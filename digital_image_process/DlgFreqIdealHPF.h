#pragma once
// CDlgFreqIdealHPF �Ի���
class CDlgFreqIdealHPF : public CDialog
{
	DECLARE_DYNAMIC(CDlgFreqIdealHPF)
public:
	CDlgFreqIdealHPF(CWnd* pParent = NULL);				// ��׼���캯��
	virtual ~CDlgFreqIdealHPF();
	enum { IDD = IDD_DLG_FREQ_IDEALHPF };				// �Ի�������

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	DECLARE_MESSAGE_MAP()
public:
	int m_nFreq;		// ��ֹƵ��
};