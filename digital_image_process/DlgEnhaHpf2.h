#pragma once
// DlgEnhaHpf2.h �Ի���

class CDlgEnhaHpf2 : public CDialog
{
	DECLARE_DYNAMIC(CDlgEnhaHpf2)
public:
	CDlgEnhaHpf2(CWnd* pParent = NULL);					// ��׼���캯��
	virtual ~CDlgEnhaHpf2();
	enum { IDD = IDD_DLG_ENHA_HPF2 };					// �Ի�������
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	DECLARE_MESSAGE_MAP()
public:
	int m_iSize, m_iMove;								// �������˲����ߴ磬ƽ�ƴ�С
	int m_dGain;										// �������˲�ϵ��
};