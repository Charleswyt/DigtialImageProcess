#pragma once
// DlgEnhaMidF.h �Ի���

class CDlgEnhaMidF : public CDialog
{
	DECLARE_DYNAMIC(CDlgEnhaMidF)
public:
	CDlgEnhaMidF(CWnd* pParent = NULL);					// ��׼���캯��
	virtual ~CDlgEnhaMidF();
	enum { IDD = IDD_DLG_ENHA_MIDF };					// �Ի�������
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	DECLARE_MESSAGE_MAP()
public:
	int m_iSize, m_iMove;								// ��ֵ�˲����ߴ磬ƽ�ƴ�С
};