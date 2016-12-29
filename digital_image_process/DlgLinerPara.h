#if !defined(AFX_DLGLINERPARA_H__CA65EBE3_E61B_4E4B_9C27_716F1FD13500__INCLUDED_)
#define AFX_DLGLINERPARA_H__CA65EBE3_E61B_4E4B_9C27_716F1FD13500__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CDlgLinerPara : public CDialog
{
// Construction
public:
	BOOL    m_bDrawed;			// ��ʶ�Ƿ��Ѿ�������Ƥ����
	CPoint  m_p1;				// ��������������ʱ��λ��
	CPoint  m_p2;				// ��������϶�ʱ��λ��
	BOOL    m_bIsDraging;		// ��ǰ����϶�״̬��TRUE��ʾ�����϶�
	CRect   m_MouseRect;		// ��Ӧ����¼��ľ�������
	CDlgLinerPara(CWnd* pParent = NULL); // standard constructor

// Dialog Data
//{{AFX_DATA(CDlgLinerPara)
	enum { IDD = IDD_DLG_LinerPara };
	double   m_fA;				// ���Ա任��б��
	double   m_fB;				// ���Ա任�Ľؾ�
	//}}AFX_DATA


// Overrides
// ClassWizard generated virtual function overrides
//{{AFX_VIRTUAL(CDlgLinerPara)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CDlgLinerPara)
	afx_msg void OnPaint();
	afx_msg void OnKillfocusEditA();
	afx_msg void OnKillfocusEditB();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	virtual BOOL OnInitDialog();//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
//{{AFX_INSERT_LOCATION}}
#endif // !defined(AFX_DLGLINERPARA_H__CA65EBE3_E61B_4E4B_9C27_716F1FD13500__INCLUDED_)