#ifndef __GRAY_H__
#define __GRAY_H__

#include "math.h"

// ����ͼ�����

// �ڼ���ͼ���Сʱ�����ù�ʽ��biSizeImage = biWidth' �� biHeight��
// ��biWidth'��������biWidth�������biWidth'������4������������ʾ
// ���ڻ����biWidth�ģ���4�������������WIDTHBYTES������������
// biWidth'
#define WIDTHBYTES(bits)    (((bits) + 31) / 32 * 4)

//  0 -> 255  ��->��

class CImg
{
public:
	CImg();												// ���캯��
	CImg(CImg& gray);									// Copy���캯��
	// ���ء�=���������������µĶ���
	void operator = (CImg& gray);						// ͼ��ֵ
	BOOL operator == (CImg& gray) const;				// �ж�2��ͼ���Ƿ���ͬ
	CImg operator & (CImg& gray);						// ͼ��λ��
	CImg operator | (CImg& gray);						// ͼ��λ��
	CImg operator + (CImg gray);						// ͼ�����
	CImg operator - (CImg& gray);						// ͼ�����
	CImg operator ! ();									// ͼ��ɫ
	virtual ~CImg();									// ��������

public:
	BOOL IsValidate() const								// �ж�λͼ�Ƿ���Ч
	{
		return m_pBMIH != NULL;
	}

	void InitPixels(BYTE color);						// ���������ص�ֵ��ʼ��Ϊcolor
	BOOL AttachFromFile(LPCTSTR lpcPathName);			// ���ļ�����λͼ
	BOOL AttachFromFile(CFile &file);
	BOOL SaveToFile(LPCTSTR lpcPathName);				// ��λͼ���浽�ļ�
	BOOL SaveToFile(CFile &file);
	BOOL Draw(CDC* pDC);								// ��DC�ϻ����޸ĺ��ͼ
	BOOL Draw(CDC* pDC, CRect rt);
	BOOL Draw2(CDC* pDC);								// ��DC�ϻ���ԭʼͼ��
	BOOL Draw_originalPic(CDC* pDC);					// ��DC�ϻ���ԭͼ
	BOOL Draw_originalPic(CDC* pDC, CRect rt);
	void SetPixel(int x, int y, COLORREF color);		// �������ص�ֵ
	COLORREF GetPixel(int x, int y) const;				// ��ȡ���ص�ֵ
	BYTE GetGray(int x, int y) const;					// ��ȡ�Ҷ�ֵ
	int GetWidthByte() const;							// ��ȡһ�е��ֽ���
	int GetWidthPixel() const;							// ��ȡһ�е�������
	int GetHeight() const;								// ��ȡ�߶�
	void ImResize(int nHeight, int nWidth);				// �ı�λͼ�ĳߴ�
public:
	// �滭����
	void Line(POINT ptStart, POINT ptEnd);				// ����ֱ��
	void Line(POINT ptStart, int nLen, int nWide, BOOL bHor);
	void Rectangle(int x, int y, int r = 5);			// ���ƾ���
	void Rectangle(POINT ptLT, int r = 5);
	void Rectangle(POINT ptLT, POINT ptRB);
	void Circle(int x, int y, int r = 5) {};

public:
	BOOL IsBinaryImg() const;							// �ж��Ƿ��Ƕ�ֵͼ��
	BOOL IsIndexedImg() const;							// �ж��Ƿ�������ͼ��
	bool Index2Gray();									// 256ɫ����ͼ��ת�Ҷ�ͼ��
	LPVOID GetColorTable() const
	{
		return m_lpvColorTable;
	}
	int GetColorTableEntriesNum() const
	{
		return m_nColorTableEntries;
	}

private:
	void CleanUp();

public:
	// �ļ�����
	BITMAPINFOHEADER* m_pBMIH;
	LPBYTE*  m_lpData;
protected:
	int m_nColorTableEntries;
	LPVOID m_lpvColorTable;
};

/**************************************************
	inline int CImg::GetWidthByte()

	���ܣ�
	����CImgʵ���е�ͼ��ÿ��ռ�õ��ֽ���
	���ƣ�
	��

	������
	��
	����ֵ��
	int���ͣ�����ͼ��ÿ��ռ�õ��ֽ���
***************************************************/
inline int CImg::GetWidthByte() const
{
	return WIDTHBYTES((m_pBMIH->biWidth) * m_pBMIH->biBitCount);
}

/**************************************************
	inline int CImg::GetWidthPixel()

	���ܣ�
	����CImgʵ���е�ͼ��ÿ�е�������Ŀ��������ֱ��ʻ���
	���ƣ�
	��

	������
	��
	����ֵ��
	int���ͣ�����ͼ��ÿ�е�������Ŀ
***************************************************/
inline int CImg::GetWidthPixel() const
{
	return m_pBMIH->biWidth;
}

/**************************************************
	inline int CImg::GetHeight()

	���ܣ�
	����CImgʵ���е�ͼ��ÿ�е�������Ŀ��������ֱ��ʻ�߶�
	���ƣ�
	��

	������
	��
	����ֵ��
	int���ͣ�����ͼ��ÿ�е�������Ŀ
***************************************************/
inline int CImg::GetHeight() const
{
	return m_pBMIH->biHeight;
}

/**************************************************
	inline BYTE CImg::GetGray(int x, int y)

	���ܣ�
	����ָ������λ�����صĻҶ�ֵ

	������
	int x, int y
		ָ�������غᡢ������ֵ
	����ֵ��
	��������λ�õĻҶ�ֵ
***************************************************/
inline BYTE CImg::GetGray(int x, int y) const
{
	COLORREF ref = GetPixel(x, y);
	BYTE r, g, b, byte;
	r = GetRValue(ref);
	g = GetGValue(ref);
	b = GetBValue(ref);

	if (r == g && r == b)
		return r;

	double dGray = (0.299 * r + 0.587 * g + 0.114 * b);
	byte = (int)dGray;			// �ҶȻ�
	return byte;
}

/**************************************************
	inline COLORREF CImg::GetPixel(int x, int y)

	���ܣ�
	����ָ������λ�����ص���ɫֵ

	������
	int x, int y
		ָ������λ�õ�����
	����ֵ��
	COLERREF���ͣ�������RGB��ʽ��ʾ��ָ��λ�õ���ɫֵ
***************************************************/
inline COLORREF CImg::GetPixel(int x, int y) const
{
	if (m_pBMIH->biBitCount == 8)						 // 256ɫͼ
	{
		BYTE byte = m_lpData[m_pBMIH->biHeight - y - 1][x];
		return RGB(byte, byte, byte);
	}
	else
		if (m_pBMIH->biBitCount == 1)					// ��ɫͼ
		{
			BYTE ret = (1 << (7 - x % 8) & m_lpData[m_pBMIH->biHeight - y - 1][x / 8]);

			RGBQUAD* p = (RGBQUAD*)m_lpvColorTable;		// 0�����

			if (p[0].rgbBlue != 0)
				ret = !ret;

			if (ret)
				return RGB(255, 255, 255); // ��ɫ

			else
				return RGB(0, 0, 0);       // ��ɫ
		}

		else
			if (m_pBMIH->biBitCount == 24) // ���ͼ
			{
				COLORREF color = RGB(m_lpData[m_pBMIH->biHeight - y - 1][x * 3 + 2],
					m_lpData[m_pBMIH->biHeight - y - 1][x * 3 + 1],
					m_lpData[m_pBMIH->biHeight - y - 1][x * 3]);
				return color;
			}

			else
			{
				throw "not support now";
				return 0;
			}
}

inline BOOL CImg::IsBinaryImg() const
{
	int i, j;

	for (i = 0; i < m_pBMIH->biHeight; i++)
	{
		for (j = 0; j < m_pBMIH->biWidth; j++)
		{
			if ((GetGray(j, i) != 0) && (GetGray(j, i) != 255)) //����0��255֮��ĻҶ�ֵ
				return FALSE;
		}//for j
	}//for i

	return TRUE;
}

inline BOOL CImg::IsIndexedImg() const
{
	if ((m_lpvColorTable != NULL) && (m_nColorTableEntries != 0))
		return true;
	else
		return false;
}
#endif // __GRAY_H__