#pragma once
// CDlgGamma �Ի���
class CDlgGamma : public CDialog 
{
	DECLARE_DYNAMIC(CDlgGamma)
public:
	CDlgGamma(CWnd* pParent = NULL);// ��׼���캯��
	virtual ~CDlgGamma();
	enum { IDD = IDD_DLG_GAMMA };	// �Ի�������

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	double m_dEsp;	// ����ϵ��
	double m_dGamma;// ָ��ϵ��
};
