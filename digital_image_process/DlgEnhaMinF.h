#pragma once
// DlgEnhaMinF.h �Ի���

class CDlgEnhaMinF : public CDialog
{
	DECLARE_DYNAMIC(CDlgEnhaMinF)
public:
	CDlgEnhaMinF(CWnd* pParent = NULL);					// ��׼���캯��
	virtual ~CDlgEnhaMinF();
	enum { IDD = IDD_DLG_ENHA_MINF };					// �Ի�������
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	DECLARE_MESSAGE_MAP()
public:
	int m_iSize, m_iMove;								// ��Сֵ�˲����ߴ磬ƽ�ƴ�С
};