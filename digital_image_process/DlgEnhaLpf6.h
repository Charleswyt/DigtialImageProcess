#pragma once
// DlgEnhaLpf6.h �Ի���

class CDlgEnhaLpf6 : public CDialog
{
	DECLARE_DYNAMIC(CDlgEnhaLpf6)
public:
	CDlgEnhaLpf6(CWnd* pParent = NULL);					// ��׼���캯��
	virtual ~CDlgEnhaLpf6();
	enum { IDD = IDD_DLG_ENHA_LPF6 };					// �Ի�������
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	DECLARE_MESSAGE_MAP()
public:
	int m_iSize, m_iMove;								// ���ξ�ֵ�˲����ߴ磬ƽ�ƴ�С
};