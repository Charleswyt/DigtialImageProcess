#pragma once
// DlgEnhaLpf2.h �Ի���

class CDlgEnhaLpf2 : public CDialog
{
	DECLARE_DYNAMIC(CDlgEnhaLpf2)
public:
	CDlgEnhaLpf2(CWnd* pParent = NULL);					// ��׼���캯��
	virtual ~CDlgEnhaLpf2();
	enum { IDD = IDD_DLG_ENHA_LPF2 };					// �Ի�������
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	DECLARE_MESSAGE_MAP()
public:
	int m_iSize, m_iMove;								// ������ֵ�˲����ߴ磬ƽ�ƴ�С
};