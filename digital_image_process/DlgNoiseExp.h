#pragma once
// CDlgNoiseExp �Ի���
class CDlgNoiseExp : public CDialog
{
	DECLARE_DYNAMIC(CDlgNoiseExp)
public:
	CDlgNoiseExp(CWnd* pParent = NULL);					// ��׼���캯��
	virtual ~CDlgNoiseExp();
	enum { IDD = IDD_DLG_NOISE_EXP };					// �Ի�������
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	DECLARE_MESSAGE_MAP()
public:
	double m_dA;										// ָ��������ֵ�ͷ���
};