#pragma once
// DlgEnhaLpf5.h �Ի���

class CDlgEnhaLpf5 : public CDialog
{
	DECLARE_DYNAMIC(CDlgEnhaLpf5)
public:
	CDlgEnhaLpf5(CWnd* pParent = NULL);					// ��׼���캯��
	virtual ~CDlgEnhaLpf5();
	enum { IDD = IDD_DLG_ENHA_LPF5 };					// �Ի�������
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	DECLARE_MESSAGE_MAP()
public:
	int m_iSize, m_iMove;								// �������޷���ֵ�˲����ߴ磬ƽ�ƴ�С����ȥ����
	int m_iCnt, m_iThreshold;							// ��������������������ֵ
};