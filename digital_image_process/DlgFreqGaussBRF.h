#pragma once
// CDlgFreqGaussBRF �Ի���
class CDlgFreqGaussBRF : public CDialog
{
	DECLARE_DYNAMIC(CDlgFreqGaussBRF)
public:
	CDlgFreqGaussBRF(CWnd* pParent = NULL);			// ��׼���캯��
	virtual ~CDlgFreqGaussBRF();
	enum { IDD = IDD_DLG_FREQ_GAUSSBRF };			// �Ի�������

protected:
	virtual void DoDataExchange(CDataExchange* pDX);// DDX/DDV ֧��
	DECLARE_MESSAGE_MAP()
public:
	int m_nFreq;	// �������Ƶ��
	int m_nWidth;	// ������
};