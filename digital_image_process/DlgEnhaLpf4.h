#pragma once
// DlgEnhaLpf4.h �Ի���

class CDlgEnhaLpf4 : public CDialog
{
	DECLARE_DYNAMIC(CDlgEnhaLpf4)
public:
	CDlgEnhaLpf4(CWnd* pParent = NULL);					// ��׼���캯��
	virtual ~CDlgEnhaLpf4();
	enum { IDD = IDD_DLG_ENHA_LPF4 };					// �Ի�������
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	DECLARE_MESSAGE_MAP()
public:
	int m_iSize, m_iMove;								// ���������˲����ߴ磬ƽ�ƴ�С����ȥ����
	int m_iThreshold;									// �ҶȲ�ֵ
};