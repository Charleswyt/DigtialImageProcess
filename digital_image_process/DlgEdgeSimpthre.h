#pragma once
// CDlgEdgeSimpthre �Ի���

class CDlgEdgeSimpthre : public CDialog
{
	DECLARE_DYNAMIC(CDlgEdgeSimpthre)
public:
	CDlgEdgeSimpthre(CWnd* pParent = NULL);				// ��׼���캯��
	virtual ~CDlgEdgeSimpthre();
	enum { IDD = IDD_DLG_EDGE_SIMPTHRE };				// �Ի�������
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	DECLARE_MESSAGE_MAP()
public:
	double m_iThreshold;								// ��ֵ
};