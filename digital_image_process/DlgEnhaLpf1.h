#pragma once
// DlgEnhaLpf1.h �Ի���

class CDlgEnhaLpf1 : public CDialog
{
	DECLARE_DYNAMIC(CDlgEnhaLpf1)
public:
	CDlgEnhaLpf1(CWnd* pParent = NULL);					// ��׼���캯��
	virtual ~CDlgEnhaLpf1();
	enum { IDD = IDD_DLG_ENHA_LPF1 };					// �Ի�������
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	DECLARE_MESSAGE_MAP()
public:
	int m_iSize, m_iMove;								// ������ֵ�˲����ߴ磬ƽ�ƴ�С
};