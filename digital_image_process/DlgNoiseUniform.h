#pragma once
// CDlgNoiseUniform �Ի���
class CDlgNoiseUniform : public CDialog
{
	DECLARE_DYNAMIC(CDlgNoiseUniform)
public:
	CDlgNoiseUniform(CWnd* pParent = NULL);				// ��׼���캯��
	virtual ~CDlgNoiseUniform();
	enum { IDD = IDD_DLG_NOISE_UNIFORM };				// �Ի�������
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	DECLARE_MESSAGE_MAP()
public:
	double m_dLow, m_dHigh;								// ���������Ͻ���½�
};