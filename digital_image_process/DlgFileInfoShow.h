#pragma once
// CDlgFileInfoShow �Ի���
class CDlgFileInfoShow : public CDialog
{
	DECLARE_DYNAMIC(CDlgFileInfoShow)
public:
	CDlgFileInfoShow(CWnd* pParent = NULL);			// ��׼���캯��
	virtual ~CDlgFileInfoShow();
	enum { IDD = IDD_DLG_ShowInfo };				// �Ի�������

protected:
	virtual void DoDataExchange(CDataExchange* pDX);// DDX/DDV ֧��
	DECLARE_MESSAGE_MAP()
public:
	int m_iWidth;									// ͼ����
	int m_iHeight;									// ͼ��߶�
	int m_iBitCount;								// ͼ��λ��
	int m_iSize;									// ͼ���С
};