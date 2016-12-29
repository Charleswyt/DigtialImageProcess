#if !defined(AFX_DLGPOINTWIN_H__E76A76B4_7F31_421A_9EB3_2AD952C0F009__INCLUDED_)
#define AFX_DLGPOINTWIN_H__E76A76B4_7F31_421A_9EB3_2AD952C0F009__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgPointWin.h : header file
//
/**********************************************/
// CDlgPointWin dialog
class CDlgPointWin : public CDialog
{
// Construction
public:

	// ��ǰ����϶�״̬��0��ʾδ�϶���1��ʾ�����϶����ޣ�2��ʾ�����϶����ޡ�
	int     m_iIsDraging;
	CRect   m_MouseRect;				// ��Ӧ����¼��ľ�������

	CDlgPointWin(CWnd* pParent = NULL); // standard constructor

// Dialog Data
//{{AFX_DATA(CDlgPointWin)
	enum { IDD = IDD_DLG_PointWin };
	BYTE    m_bLow;						// ���ڵ�����
	BYTE    m_bUp;						// ���ڵ�����
	//}}AFX_DATA


// Overrides
// ClassWizard generated virtual function overrides
//{{AFX_VIRTUAL(CDlgPointWin)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgPointWin)
	afx_msg void OnKillfocusEDITLow();
	afx_msg void OnKillfocusEDITUp();
	virtual void OnOK();
	afx_msg void OnPaint();
	virtual BOOL OnInitDialog();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
//{{AFX_INSERT_LOCATION}}
#endif // !defined(AFX_DLGPOINTWIN_H__E76A76B4_7F31_421A_9EB3_2AD952C0F009__INCLUDED_)
