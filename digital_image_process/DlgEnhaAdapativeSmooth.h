#pragma once
// DlgEnhaAdapativeSmooth.h �Ի���

class CDlgEnhaAdapativeSmooth : public CDialog
{
	DECLARE_DYNAMIC(CDlgEnhaAdapativeSmooth)
public:
	CDlgEnhaAdapativeSmooth(CWnd* pParent = NULL);		// ��׼���캯��
	virtual ~CDlgEnhaAdapativeSmooth();
	enum { IDD = IDD_DLG_ENHA_ADAPATIVE_SMOOTH };		// �Ի�������
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	DECLARE_MESSAGE_MAP()
public:
	int m_iSize, m_iMove;								// ����Ӧ��ֵ�˲����ߴ磬ƽ�ƴ�С
};