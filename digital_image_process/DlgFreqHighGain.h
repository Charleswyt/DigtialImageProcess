#pragma once
// CDlgFreqHighGain �Ի���
class CDlgFreqHighGain : public CDialog
{
	DECLARE_DYNAMIC(CDlgFreqHighGain)
public:
	CDlgFreqHighGain(CWnd* pParent = NULL);				// ��׼���캯��
	virtual ~CDlgFreqHighGain();
	enum { IDD = IDD_DLG_ENHA_HPF2 };					// �Ի�������
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	DECLARE_MESSAGE_MAP()
public:
	double m_dCofficient;								// �������˲���ϵ��
};
