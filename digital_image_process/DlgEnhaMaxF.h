#pragma once
// DlgEnhaMaxF.h �Ի���

class CDlgEnhaMaxF : public CDialog
{
	DECLARE_DYNAMIC(CDlgEnhaMaxF)
public:
	CDlgEnhaMaxF(CWnd* pParent = NULL);					// ��׼���캯��
	virtual ~CDlgEnhaMaxF();
	enum { IDD = IDD_DLG_ENHA_MAXF };					// �Ի�������
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	DECLARE_MESSAGE_MAP()
public:
	int m_iSize, m_iMove;								// ���ֵ�˲����ߴ磬ƽ�ƴ�С
};