#pragma once
// CDlgRGBHist �Ի���

class CDlgRGBHist : public CDialog
{
	DECLARE_DYNAMIC(CDlgRGBHist)

public:
	CDlgRGBHist(CWnd* pParent = NULL);					// ��׼���캯��
	virtual ~CDlgRGBHist();
	enum { IDD = IDD_DLG_HIST_RGB };					// �Ի�������

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnPaint();
	// ����ĻҶ�ֱ��ͼ����
	double* m_pdHistR;
	double* m_pdHistG;
	double* m_pdHistB;	
};