#pragma once
// DlgEnhaAdapativeMediaF.h �Ի���

class CDlgEnhaAdapativeMediaF : public CDialog
{
	DECLARE_DYNAMIC(CDlgEnhaAdapativeMediaF)
public:
	CDlgEnhaAdapativeMediaF(CWnd* pParent = NULL);		// ��׼���캯��
	virtual ~CDlgEnhaAdapativeMediaF();
	enum { IDD = IDD_DLG_ENHA_ADAPATIVEMEDIAF };		// �Ի�������
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	DECLARE_MESSAGE_MAP()
public:
	int m_iSize, m_iMove;								// ����Ӧ��ֵ�˲����ߴ磬ƽ�ƴ�С
};