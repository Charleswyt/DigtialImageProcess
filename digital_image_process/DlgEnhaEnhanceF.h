#pragma once
// DlgEnhaEnhanceF.h �Ի���

class CDlgEnhaEnhanceF : public CDialog
{
	DECLARE_DYNAMIC(CDlgEnhaEnhanceF)
public:
	CDlgEnhaEnhanceF(CWnd* pParent = NULL);				// ��׼���캯��
	virtual ~CDlgEnhaEnhanceF();
	enum { IDD = IDD_DLG_ENHA_ENHANCEF };				// �Ի�������
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	DECLARE_MESSAGE_MAP()
public:
	int m_iSize, m_iMove;								// �������˲����ߴ磬ƽ�ƴ�С
	int m_dGain;										// �������˲�ϵ��
};