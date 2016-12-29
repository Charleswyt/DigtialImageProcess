#if !defined(AFX_IMAGE_H__D566CE6A_BA81_4157_8E6A_748DA096668F__INCLUDED_)
#define AFX_IMAGE_H__D566CE6A_BA81_4157_8E6A_748DA096668F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <vector>
#include "Img.h"
#include "math.h"
#include <complex>

using namespace std;

extern double Template_Log[];
extern double Template_VSobel[];
extern double Template_HSobel[];
extern double Template_Smooth_Gauss[];
extern double Template_Smooth_Avg[];
extern double Template_Laplacian1[];
extern double Template_Laplacian2[];

#define PI 3.141592654
#define e  2.7182818284

struct SLineInfo
{
	int nPixels;
	int nAngle;  // -180   +180
	int nDist;   // 0      +Max
	int GetLineAngle(SLineInfo *pLine)
	{

		int nRet = abs(pLine->GetAngle360() - GetAngle360());
		if (nRet > 180)
			nRet = 360 - nRet;

		if (nRet > 90)
			nRet = 180 - nRet;


		return abs(nRet);
	}

	int GetLineDist(SLineInfo *pLine)
	{
		if (nAngle * pLine->nAngle < 0)
			return abs(nDist + pLine->nDist);

		return abs(nDist - pLine->nDist);
	}

	void AddDistWithAngle(int nAdd, int n)
	{
		if (n < 0)
			nAdd *= -1;

		nDist += nAdd;
	}

	int GetDistWithAngle(int n)
	{
		int nRet = nDist;
		if (n < 0)
			nRet *= -1;

		return nRet;
	}

	int GetAngle360()
	{
		int nRet = nAngle;
		if (nAngle < 0)
			nRet = abs(nAngle + 180) + 180;
		return nRet;
	}

	int GetY(int x)
	{
		int nRet = 0;
		double fRadian = nAngle*PI / 180.0;


		if (sin(fRadian) != 0)
			nRet = (nDist - x*cos(fRadian)) / sin(fRadian);

		return nRet;

	}

	int GetX(int y)
	{
		int nRet = 0;
		double fRadian = nAngle*PI / 180.0;
		if (cos(fRadian) != 0)
			nRet = (nDist - y*sin(fRadian)) / cos(fRadian);

		return nRet;
	}

};

struct MYPOINT
{
	double x;
	double y;
};

// CImgProcess��װ�˸���ͼ����ı�׼�㷨
class CImgProcess : public CImg
{
public:
	CImgProcess();
	virtual ~CImgProcess();
	CImgProcess& operator = (CImg& img);							// �ӻ����ת��

	/*************** ͼ��ĵ�����*****************/
	BOOL GenHist(double * hist, int n = 256);						// ���ɻҶ�ֱ��ͼ
	BOOL GenRGBHist(double * hist, int iType, int n = 256);			// ����RGB����ɫֱ��ͼ
	BOOL ParLinTran(CImgProcess * pTo, BYTE x1, BYTE x2,
		BYTE y1, BYTE y2);											// �ֶ����Ա任
	BOOL LinTran(CImgProcess * pTo, double dFa, double dFb);		// ���Ա任
	BOOL LogTran(CImgProcess * pTo, double C);						// �����任
	BOOL GammaTran(CImgProcess * pTo, double gamma,
		double comp = 0);											// ָ���任
	BOOL WindowTran(CImgProcess * pTo, BYTE lowThre, BYTE highThre);// ���ڱ任
	BOOL Histeq(CImgProcess * pTo);									// �ҶȾ��⻯
	BOOL Histst(CImgProcess * pTo, double* pdStdHist);				// ֱ��ͼ�涨����ֱ��ƥ��ֱ��ͼ
	BOOL Histst(CImgProcess * pTo, CImgProcess* pStd);				// ֱ��ͼ�涨����ƥ���׼ͼ���ֱ��ͼ
	BOOL GetBitLayer(CImgProcess* pTo, int iLayerLevel);			// ��ȡ�Ҷ�ͼ�ĸ���λ��ͼ
	double* CImgProcess::StatisticRGBMoment(CImgProcess * pTo);		// ͳ��ͼ���RGB��ɫ��
	int* CImgProcess::StatisticRGBHist(CImgProcess * pTo, CImgProcess* pStd);	// ������ͼ���RGBֱ��ͼֱ�ӵĲ���

	/*************** ͼ��ļ��α任 *****************/
	void ImMove(CImgProcess* pTo, int x, int y);					// ͼ��ƽ��
	void HorMirror(CImgProcess* pTo);								// ͼ��ˮƽ����
	void VerMirror(CImgProcess* pTo);								// ͼ��ֱ����
	void Transpose(CImgProcess* pTo);								// ͼ��ת��
	void Scale1(CImgProcess* pTo, double times);					// ͼ��ȱ�������
	void Scale2(CImgProcess* pTo, double xTimes, double yTimes);	// ͼ���������
	void Rotate(CImgProcess* pTo, double ang);						// ͼ����ת

	/************** ���� **************/
	void AddGaussian(CImgProcess *pTo, double dRate, double dSigma);// ��˹����
	void AddSalt_Pepper(CImgProcess *pTo, double dRate);			// ��������
	void AddRayleigh(CImgProcess *pTo,double dRata, double dSigma); // ��������
	void AddGamma(CImgProcess *pTo, double dA, double dB);			// ٤������
	void AddExp(CImgProcess *pTo, double dRate);					// ָ������
	void AddUniform(CImgProcess *pTo, double dLow, double dHigh);	// ��������

	/************** ͶӰ�任��ԭ ***************/
	int m_nBasePt;													// ��׼��Զ�����Ŀ
	BOOL ImProjRestore(CImgProcess* pTo, CPoint *pPointBase,
		CPoint *pPointSampl, bool bInterp);							// ͶӰ����У��
	void GetProjPara(CPoint *pPointBase, CPoint *pPointSampl,
		double *pDbProjPara);										// ���ݻ�׼��ȷ���任����
	BOOL InvMat(double** ppDbMat, int nLen);						// ��������
	void ProdMat(double** ppDbMat, double* pDbSrc2,
		double* pDbDest, int y, int x, int z);
	struct MYPOINT ProjTrans(CPoint pt, double* pDbProjPara);		// ���ݱ任�����Ե�ptʵʩͶӰ�任
	int InterpBilinear(double x, double y);							// ����(x,y)��˫���Բ�ֵ��ĻҶ�

	/*************** �����˲� *****************/
	void Template(CImgProcess *pTo, int nTempH, int nTempW,
		int nTempMY, int nTempMX, double *pfArray, double fCoef);	// ͨ��ģ�����
	int GetGraySum(int * pAryGray, int nFilterLen);					// ȡ��ģ�崰���ڻҶ�ֵ�ĺ�ֵ
	int GetMedianValue(int * pAryGray, int nFilterLen);				// ȡ��ģ�崰����ֵ
	int GetMidValue(int * pAryGray, int nFilterLen);				// ȡ��ģ�崰���е�ֵ
	int GetMeanValue(int * pAryGray, int nFilterLen);				// ȡ��ģ�崰�ھ�ֵ
	int GetGeoMeanValue(int * pAryGray, int nFilterLen);			// ȡ��ģ�崰�ڼ��ξ�ֵ
	int GetHarmonicMeanValue(int * pAryGray, int nFilterLen);		// ȡ��ģ�崰��г����ֵ
	int GetInvHarmonicMeanValue(int * pAryGray, int nFilterLen, 
		int Q);														// ȡ��ģ�崰����г����ֵ��QΪ��ֵ
	int GetAlphaMeanValue(int * pAryGray, int nFilterLen, int d);	// ȡ��ģ�崰�ڰ�������ֵ��dΪ��Ҫɾȥ�����ص�ĸ���
	int GetMaxValue(int * pAryGray, int nFilterLen);				// ȡ��ģ�崰�����ֵ
	int GetMinValue(int * pAryGray, int nFilterLen);				// ȡ��ģ�崰����Сֵ
	double GetGradientSum(double* pAryGradient, int nFilterLen);	// ȡ��ģ�崰���ڵ��ݶ�֮��
	void LowFilter1(CImgProcess *pTo, int nFilterH, int nFilterW,
		int nFilterMY, int nFilterMX);								// �����ֵ�˲�
	void LowFilter2(CImgProcess *pTo, int nFilterH, int nFilterW,
		int nFilterMY, int nFilterMX);								// �򵥼�Ȩ��ֵ�˲�
	void LowFilter3(CImgProcess *pTo, int nFilterH, int nFilterW,
		int nFilterMY, int nFilterMX);								// �ݶȼ�Ȩ��ֵ�˲�
	void LowFilter4(CImgProcess *pTo, int nFilterH, int nFilterW,
		int nFilterMY, int nFilterMX, int iThreshold);				// ���������ֵ�˲�
	void LowFilter5(CImgProcess *pTo, int nFilterH, int nFilterW,
		int nFilterMY, int nFilterMX, int iThreshold, int iCnt);	// ���������˲�
	void LowFilter6(CImgProcess *pTo, int nFilterH, int nFilterW,
		int nFilterMY, int nFilterMX);								// ���ξ�ֵ�˲���
	void LowFilter7(CImgProcess *pTo, int nFilterH, int nFilterW,
		int nFilterMY, int nFilterMX);								// г����ֵ�˲���
	void LowFilter8(CImgProcess *pTo, int nFilterH, int nFilterW,
		int nFilterMY, int nFilterMX, int Q);						// ��г����ֵ�˲���
	void LowFilter9(CImgProcess *pTo, int nFilterH, int nFilterW,
		int nFilterMY, int nFilterMX, int d);						// ������������ֵ�˲���
	void MidFilter(CImgProcess *pTo, int nFilterH, int nFilterW,
		int nFilterMY, int nFilterMX);								// �е��˲���
	void HighFilter1(CImgProcess *pTo, int nFilterH, int nFilterW,
		int nFilterMY, int nFilterMX);								// ������ͨ�˲�
	void HighFilter2(CImgProcess *pTo, int nFilterH, int nFilterW,
		int nFilterMY, int nFilterMX, double dGain);				// �������˲�
	void MedianFilter(CImgProcess *pTo, int nFilterH, int nFilterW,
		int nFilterMY, int nFilterMX);								// ��ֵ�˲�
	void MaxFilter(CImgProcess *pTo, int nFilterH, int nFilterW,
		int nFilterMY, int nFilterMX);								// ���ֵ�˲�
	void MinFilter(CImgProcess *pTo, int nFilterH, int nFilterW,
		int nFilterMY, int nFilterMX);								// ��Сֵ�˲�
	void AdaptiveMedianFilter(CImgProcess *pTo, int nFilterH,
		int nFilterW, int nFilterMY, int nFilterMX);				// ����Ӧ��ֵ�˲�
	void FilterSobel(CImgProcess *pTo);								// Sobel�ݶ���
	void EnhanceFilter(CImgProcess *pTo, double dProportion, int nTempH, int nTempW,
		int nTempMY, int nTempMX, double *pfArray, double fCoef);	// �������˲�
	void EnhaGaussianF(CImgProcess *pTo, int nFilterH, int nFilterW,
		int nFilterMY, int nFilterMX);								// ��˹ƽ���˲�
	void EnhaAdaptiveSmooth(CImgProcess *pTo, int nFilterH,
		int nFilterW, int nFilterMY, int nFilterMX);				// ����Ӧ��ֵ�˲�

	/*************** Ƶ��������˲� *****************/
private:

	void FFT(complex<double> * TD, complex<double> * FD, int r);	// FFT
	void IFFT(complex<double> * FD, complex<double> * TD, int r);	// IFFT
	void dct8x8(double *in, double *out);							// 8*8DCT
	void idct8x8(double *in, double *out);							// IDCT
	void quant(double *in, int *out);								// ����
	void iquant(int *in, double *out);								// ������
	int Quant_table[8][8]											// DCT�������� 
	=	{ 16,11,10,16,24,40,51,61,
		12,12,14,19,26,58,60,55,
		14,13,16,24,40,57,69,56,
		14,17,22,29,51,87,80,62,
		18,22,37,56,68,109,103,77,
		24,35,55,64,81,104,113,92,
		49,64,78,87,103,121,120,101,
		72,92,95,98,112,100,103,99 };

public:

	BOOL FFT2(CImgProcess * pTo, BOOL bExpand = FALSE,
		complex<double> * pOutput = NULL, BYTE bFillColor = 255);	// FFT2
	BOOL IFFT2(CImgProcess * pTo, complex<double> * pInput, long lWidth,
		long lHeight, long lOutW = 0, long lOutH = 0);				// IFFT2
	BOOL fft2(CImgProcess * pTo);									// FFT2
	BOOL ifft2(CImgProcess * pTo);									// IFFT2
	BOOL DCT(CImgProcess *pTo);										// DCT
	BOOL IDCT(CImgProcess *pTo);									// IDCT

	BOOL FreqFilt(CImgProcess * pTo, double * pdFilter,
		BYTE bFillColor = 255);										// Ƶ���˲�
	BOOL FreqIdealLPF(double * pdFilter, int nFreq);				// Ƶ�������ͨ�˲���
	BOOL FreqIdealHPF(double * pdFilter, int nFreq);				// Ƶ�������ͨ�˲���
	BOOL FreqGaussLPF(double * pdFilter, double dSigma);			// Ƶ���˹��ͨ�˲���
	BOOL FreqGaussHPF(double * pdFilter, double dSigma);			// Ƶ���˹��ͨ�˲���
	BOOL FreqButterworthLPF(double * pdFilter, int nFreq, int n);	// Ƶ�������˹��ͨ�˲���
	BOOL FreqButterworthHPF(double * pdFilter, int nFreq, int n);	// Ƶ�������˹��ͨ�˲���
	BOOL FreqExpLPF(double * pdFilter, int nFreq, int n);			// Ƶ��ָ����ͨ�˲���
	BOOL FreqExpHPF(double * pdFilter, int nFreq, int n);			// Ƶ��ָ����ͨ�˲���
	BOOL FreqLadderLPF(double * pdFilter, int nFreq, int nF);		// Ƶ�����ε�ͨ�˲���
	BOOL FreqLadderHPF(double * pdFilter, int nFreq, int nF);		// Ƶ�����θ�ͨ�˲���
	BOOL FreqLaplace(double * pdFilter);							// Ƶ��������˹�˲���
	BOOL FreqGaussBRF(double * pdFilter, int nFreq, int nWidth);	// Ƶ���˹�����˲���

	inline LONG GetFreqWidth(BOOL isExtending = true)
	{
		LONG w = 1;

		while (w * 2 <= GetWidthPixel())
			w *= 2;

		// �����Ҫ��չͼ���ȣ���ͼ���Ȳ�ǡ����2�����ݣ���
		if ((w != GetWidthPixel()) && (isExtending))
			w *= 2;

		return w;
	}

	inline LONG GetFreqHeight(BOOL isExtending = true)
	{
		LONG h = 1;

		while (h * 2 <= GetHeight())
			h *= 2;

		// �����Ҫ��չͼ��߶ȣ���ͼ��߶Ȳ�ǡ����2�����ݣ���
		if ((h != GetHeight()) && (isExtending))
			h *= 2;

		return h;
	}

	/*************** ��ɫ�ռ�任 *****************/
	void CMY2RGB(CImgProcess *pTo);									// CMYתRGB
	void RGB2CMY(CImgProcess *pTo);									// RGBתCMY
	void RGB2HSI(CImgProcess* pTo);									// RGBתHSI
	void HSI2RGB(CImgProcess *pTo);									// HSIתRGB
	void RGB2Gray(CImgProcess *pTo, int iType);						// RGBת�Ҷ�
	void Gray2RGB(CImgProcess *pTo, int iType);						// �Ҷ�תRGB
	void GetRGBLevel(CImgProcess *pTo, int iType);					// ��ȡRGBƽ�棬R-1 G-2 B-3
	void YIQ2RGB(CImgProcess *pTo);									// YIQתRGB
	void RGB2YIQ(CImgProcess *pTo);									// RGBתYIQ
	void YUV2RGB(CImgProcess *pTo);									// YUVתRGB
	void RGB2YUV(CImgProcess *pTo);									// RGBתYUV
	void HSV2RGB(CImgProcess *pTo);									// HSVתRGB
	void RGB2HSV(CImgProcess *pTo);									// RGBתHSV

	/************** ��̬ѧ���� ********************/
	void FillRgn(CImgProcess *pTo, POINT ptStart);					// ��������㷨
	void TraceBoundary(CImgProcess *pTo);							// �߽�����㷨
	void Thining();													// ϸ���㷨
	void Erode(CImgProcess* pTo, int se[3][3]);						// ��ʴ�㷨
	void Dilate(CImgProcess* pTo, int se[3][3]);					// �����㷨
	void Convex(CImgProcess* pTo, BOOL bConstrain);					// ����͹��
	void Open(CImgProcess* pTo, int se[3][3]);						// ������
	void Close(CImgProcess* pTo, int se[3][3]);						// ������
	void PixelImage(CImgProcess* pTo, int lowerThres, int upperThres);
	int TestConnRgn(CImgProcess* pImage, LPBYTE lpVisited, int nWidth,
		int nHeight, int x, int y, CPoint ptVisited[], int lowerThres, int upperThres, int &curLianXuShu);
	void LabelConnRgn(CImgProcess* pTo, int nConn = 8);				// ��ע��ͨ����

	//�Ҷ���̬ѧ
	void GrayDilate(CImgProcess* pTo, int nTempH, int nTempW,
		int nTempMY, int nTempMX, int** se);						// �Ҷ�����
	void GrayErode(CImgProcess* pTo, int nTempH, int nTempW,
		int nTempMY, int nTempMX, int** se);						// �Ҷȸ�ʴ
	void GrayOpen(CImgProcess* pTo, int nTempH, int nTempW,
		int nTempMY, int nTempMX, int** se);						// �Ҷȿ�����
	void GrayClose(CImgProcess* pTo, int nTempH, int nTempW,
		int nTempMY, int nTempMX, int** se);						//�Ҷȱ�����
	void Tophat(CImgProcess* pTo, int nTempH, int nTempW,
		int nTempMY, int nTempMX, int** se);						// ��ñ�任

	/********************* ͼ��ָ� ********************/

	BOOL EdgeRoberts(CImgProcess * pTo, BYTE bThre = 0, BYTE bEdgeType = 0,
		BOOL bThinning = true, BOOL bGOnly = false);				// Roberts��ԵѰ��
	BOOL EdgeSobel(CImgProcess * pTo, BYTE bThre = 0, BYTE bEdgeType = 0,
		BOOL bThinning = true, BOOL bGOnly = false);				// Sobel��ԵѰ��
	BOOL EdgePrewitt(CImgProcess * pTo, BYTE bThre = 0, BYTE bEdgeType = 0,
		BOOL bThinning = true, BOOL bGOnly = false);				// Prewitt��ԵѰ��
	void EdgeLoG(CImgProcess * pTo);								// ��˹������˹��ԵѰ��
	BOOL EdgeCanny(CImgProcess * pTo, BYTE bThreL = 0, BYTE bThreH = 0,
		BOOL bThinning = true);										// Canny�㷨
	BOOL Hough(SLineInfo *pInfoRet, int nLineRet);					// Hough�任 ����ֱ��
	void Threshold(CImgProcess *pTo, BYTE bThre);					// ��ֵ�ָ�
	int DetectThreshold(int nMaxIter, int &nDiffRet);				// ������ȡ���ŷ�ֵ
	void SimpThreshold(CImgProcess *pTo, int iThreshold);			// ����ֵ�ָ�					 
	void AutoThreshold(CImgProcess *pTo);							// �Զ���ֵ�ָ�							 
	BOOL RegionGrow(CImgProcess * pTo, int nSeedX, int nSeedY,
		BYTE bThre);												// ���������㷨

	/*************** ������ȡ *****************/
	vector< vector<int> > GetGrayMatrix(POINT ptD1, POINT ptD2);	// ����Ҷȹ��־���

	/*************** ����ƥ�� *****************/
	void TemplateMatch(CImgProcess* pTo, CImgProcess* pTemplate);	// ģ��ƥ��

	/*************** ͼ���������� *****************/
	BOOL IsBiImg(CImgProcess * pTo);								// �жϵ�ǰ�Ƿ�Ϊ�����ֵͼ��λ��Ϊ1����ֻ��������ɫ��
	void PicAdd(CImgProcess * pTo, CImgProcess* pStd);				// ͼ�����
	void PicSub(CImgProcess * pTo, CImgProcess* pStd);				// ͼ�����
	void PicMul(CImgProcess * pTo, CImgProcess* pStd);				// ͼ�����

};//class CImgProcess
#endif // !defined(AFX_IMAGE_H__D566CE6A_BA81_4157_8E6A_748DA096668F__INCLUDED_)