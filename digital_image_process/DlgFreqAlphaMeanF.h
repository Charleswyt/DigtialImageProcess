#pragma once
// DlgFreqAlphaMeanF.h �Ի���

class CDlgFreqAlphaMeanF : public CDialog
{
	DECLARE_DYNAMIC(CDlgFreqAlphaMeanF)
public:
	CDlgFreqAlphaMeanF(CWnd* pParent = NULL);			// ��׼���캯��
	virtual ~CDlgFreqAlphaMeanF();
	enum { IDD = IDD_DLG_FREQ_ALPHAMEANF };				// �Ի�������
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	DECLARE_MESSAGE_MAP()
public:
	int m_iSize, m_iMove, m_iDotCount;					// ������������ֵ�˲����ߴ磬ƽ�ƴ�С����ȥ����
};