#pragma once
// DlgEnhaMediaF.h �Ի���

class CDlgEnhaMediaF : public CDialog
{
	DECLARE_DYNAMIC(CDlgEnhaMediaF)
public:
	CDlgEnhaMediaF(CWnd* pParent = NULL);				// ��׼���캯��
	virtual ~CDlgEnhaMediaF();
	enum { IDD = IDD_DLG_ENHA_MEDIAF };					// �Ի�������
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	DECLARE_MESSAGE_MAP()
public:
	int m_iSize, m_iMove;								// ��ֵ�˲����ߴ磬ƽ�ƴ�С
};