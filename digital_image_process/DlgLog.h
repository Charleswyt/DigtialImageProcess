#pragma once


// CDlgLog �Ի���

class CDlgLog : public CDialog
{
	DECLARE_DYNAMIC(CDlgLog)

public:
	CDlgLog(CWnd* pParent = NULL);	// ��׼���캯��
	virtual ~CDlgLog();
	enum { IDD = IDD_DIALOG_LOG };	// �Ի�������

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	DECLARE_MESSAGE_MAP()

public:
	double m_dC;
};
