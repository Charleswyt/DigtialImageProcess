#pragma once
// DlgEnhaLpf7.h �Ի���

class CDlgEnhaLpf7 : public CDialog
{
	DECLARE_DYNAMIC(CDlgEnhaLpf7)
public:
	CDlgEnhaLpf7(CWnd* pParent = NULL);					// ��׼���캯��
	virtual ~CDlgEnhaLpf7();
	enum { IDD = IDD_DLG_ENHA_LPF7 };					// �Ի�������
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	DECLARE_MESSAGE_MAP()
public:
	int m_iSize, m_iMove;								// г����ֵ�˲����ߴ磬ƽ�ƴ�С
};