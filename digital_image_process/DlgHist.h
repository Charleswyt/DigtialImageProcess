#pragma once
// CDlgHist �Ի���

class CDlgHist : public CDialog
{
	DECLARE_DYNAMIC(CDlgHist)

public:
	CDlgHist(CWnd* pParent = NULL); // ��׼���캯��
	virtual ~CDlgHist();
	enum { IDD = IDD_DLG_Hist };	// �Ի�������

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnPaint();
	double* m_pdHist;				// ����ĻҶ�ֱ��ͼ����
};