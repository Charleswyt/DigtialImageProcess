#pragma once
// DlgEnhaHpf1.h �Ի���

class CDlgEnhaHpf1 : public CDialog
{
	DECLARE_DYNAMIC(CDlgEnhaHpf1)
public:
	CDlgEnhaHpf1(CWnd* pParent = NULL);					// ��׼���캯��
	virtual ~CDlgEnhaHpf1();
	enum { IDD = IDD_DLG_ENHA_HPF1 };					// �Ի�������
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	DECLARE_MESSAGE_MAP()
public:
	int m_iSize, m_iMove;								// ������ͨ�˲����ߴ磬ƽ�ƴ�С
};