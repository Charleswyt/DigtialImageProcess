#pragma once
// DlgEnhaLpf3.h �Ի���

class CDlgEnhaLpf3 : public CDialog
{
	DECLARE_DYNAMIC(CDlgEnhaLpf3)
public:
	CDlgEnhaLpf3(CWnd* pParent = NULL);					// ��׼���캯��
	virtual ~CDlgEnhaLpf3();
	enum { IDD = IDD_DLG_ENHA_LPF3 };					// �Ի�������
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	DECLARE_MESSAGE_MAP()
public:
	int m_iSize, m_iMove;								// �ݶȵ�����Ȩ��ֵ�˲����ߴ磬ƽ�ƴ�С
};