#pragma once
// DlgEnhaGaussianF.h �Ի���

class CDlgEnhaGaussianF : public CDialog
{
	DECLARE_DYNAMIC(CDlgEnhaGaussianF)
public:
	CDlgEnhaGaussianF(CWnd* pParent = NULL);			// ��׼���캯��
	virtual ~CDlgEnhaGaussianF();
	enum { IDD = IDD_DLG_ENHA_GAUSSIANF };				// �Ի�������
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	DECLARE_MESSAGE_MAP()
public:
	int m_iSize, m_iMove;								// ��˹ƽ���˲����ߴ磬ƽ�ƴ�С
};