#pragma once
// DlgFreqInvHarmonicF.h �Ի���

class CDlgFreqInvHarmonicF : public CDialog
{
	DECLARE_DYNAMIC(CDlgFreqInvHarmonicF)
public:
	CDlgFreqInvHarmonicF(CWnd* pParent = NULL);			// ��׼���캯��
	virtual ~CDlgFreqInvHarmonicF();
	enum { IDD = IDD_DLG_FREQ_INVHARMONICF };			// �Ի�������
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	DECLARE_MESSAGE_MAP()
public:
	int m_iSize, m_iMove, m_iLevel;						// ��г����ֵ�˲����ߴ磬ƽ�ƾ���ͽ���
};