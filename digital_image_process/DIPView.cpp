#include "stdafx.h"
#include "DIP.h"

#include "DIPDoc.h"
#include "DIPView.h"
#include "mainfrm.h"

#include "DlgFileInfoShow.h"
#include "DlgLinerPara.h"
#include "DlgPointThre.h"
#include "DlgPointWin.h"
#include "DlgPointThre.h"
#include "DlgGeoTran.h"
#include "DlgGeoZoom.h"
#include "DlgGeoZoom2.h"
#include "DlgGeoRota.h"
#include "DlgProjRestore.h"
#include "DlgSmooth.h"
#include "DlgMidFilter.h"
#include "DlgSharpThre.h"
#include "DlgColor.h"

#include "DlgHist.h"
#include "DlgLinTrans.h"
#include "DlgLog.h"
#include "DlgGamma.h"
#include "DlgWndTran.h"
#include "DlgGrayScaling.h"
#include "DlgFreqGaussBRF.h"
#include "DlgFreqGaussHPF.h"
#include "DlgFreqGaussLPF.h"
#include "DlgFreqHighGain.h"
#include "DlgFreqIdealLPF.h"
#include "DlgEdgeSobelPrewitt.h"
#include "DlgHough.h"
#include "DlgNoiseGauss.h"
#include "DlgNoiseSaltPepper.h"
#include "DlgNoiseGamma.h"
#include "DlgNOiseExp.h"
#include "DlgNoiseUniform.h"
#include "DlgNoiseRayleigh.h"
#include "DlgEdgeSimpthre.h"
#include "DlgFreqButterworthLPF.h"
#include "DlgFreqButterworthHPF.h"
#include "DlgFreqExpLPF.h"
#include "DlgFreqExpHPF.h"
#include "DlgFreqInvHarmonicF.h"
#include "DlgFreqAlphaMeanF.h"
#include "DlgEnhaLpf1.h"
#include "DlgEnhaLpf2.h"
#include "DlgEnhaLpf3.h"
#include "DlgEnhaLpf4.h"
#include "DlgEnhaLpf5.h"
#include "DlgEnhaLpf6.h"
#include "DlgEnhaLpf7.h"
#include "DlgEnhaHpf1.h"
#include "DlgEnhaHpf2.h"
#include "DlgEnhaMediaF.h"
#include "DlgEnhaMinF.h"
#include "DlgEnhaMaxF.h"
#include "DlgEnhaMidF.h"
#include "DlgEnhaAdapativeMediaF.h"
#include "DlgEnhaEnhanceF.h"
#include "DlgEnhaAdapativeSmooth.h"
#include "DlgEnhaGaussianF.h"
#include "DlgRGBHist.h"
#include "DlgFreqLadderLpf.h"
#include "DlgFreqLadderHpf.h"

#include "DlgMorph.h"
#include "DlgMorphErosion.h"
#include "DlgMorphDilation.h"
#include "DlgMorphOpen.h"
#include "DlgMorphClose.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**********************************************/
// CDIPView

IMPLEMENT_DYNCREATE(CDIPView, CScrollView)

BEGIN_MESSAGE_MAP(CDIPView, CScrollView)
	//{{AFX_MSG_MAP(CDIPView)
	ON_WM_ERASEBKGND()
	ON_COMMAND(ID_GEOM_TRAN, OnGeomTran)
	ON_COMMAND(ID_GEOM_MIRV, OnGeomMirv)
	ON_COMMAND(ID_GEOM_MIRH, OnGeomMirh)
	ON_COMMAND(ID_GEOM_ROTA, OnGeomRota)
	ON_COMMAND(ID_GEOM_TRPO, OnGeomTrpo)
	ON_COMMAND(ID_GEOM_ZOOM1, OnGeomZoom1)
	ON_COMMAND(ID_GEOM_ZOOM2, OnGeomZoom2)
	ON_COMMAND(ID_POINT_EQUA, OnPointEqua)
	ON_COMMAND(ID_POINT_LINER, OnPointLiner)
	ON_COMMAND(ID_POINT_WIND, OnPointWind)
	ON_COMMAND(ID_VIEW_INTENSITY, OnViewIntensity)
	ON_COMMAND(ID_VIEW_RGB_HIST, OnViewRGBIntensity)
	ON_COMMAND(ID_BITLAYER_I, OnGetBitLayerI)
	ON_COMMAND(ID_BITLAYER_II, OnGetBitLayerII)
	ON_COMMAND(ID_BITLAYER_III, OnGetBitLayerIII)
	ON_COMMAND(ID_BITLAYER_IV, OnGetBitLayerIV)
	ON_COMMAND(ID_BITLAYER_V, OnGetBitLayerV)
	ON_COMMAND(ID_BITLAYER_VI, OnGetBitLayerVI)
	ON_COMMAND(ID_BITLAYER_VII, OnGetBitLayerVII)
	ON_COMMAND(ID_BITLAYER_VIII, OnGetBitLayerVIII)
	ON_COMMAND(ID_FREQ_FOUR, OnFreqFour)
	ON_COMMAND(ID_FREQ_IFOUR, OnFreqIFour)
	ON_COMMAND(ID_FREQ_DCT, OnFreqDct)
	ON_COMMAND(ID_FREQ_IDCT, OnFreqIdct)
	ON_COMMAND(ID_POINT_THRE, OnPointThre)
	ON_COMMAND(ID_ENHA_SMOOTH, OnEnhaSmooth)
	ON_COMMAND(ID_ENHA_MidianF, OnEnhaMidianF)
	ON_COMMAND(ID_ENHA_MINF, OnEnhaMinF)
	ON_COMMAND(ID_ENHA_MAXF, OnEnhaMaxF)
	
	ON_COMMAND(ID_ENHA_LPF1, OnEnhaLPF1)
	ON_COMMAND(ID_ENHA_LPF2, OnEnhaLPF2)
	ON_COMMAND(ID_ENHA_LPF3, OnEnhaLPF3)
	ON_COMMAND(ID_ENHA_LPF4, OnEnhaLPF4)
	ON_COMMAND(ID_ENHA_LPF5, OnEnhaLPF5)
	ON_COMMAND(ID_ENHA_LPF6, OnEnhaLPF6)
	ON_COMMAND(ID_ENHA_LPF7, OnEnhaLPF7)
	ON_COMMAND(ID_ENHA_LPF8, OnEnhaLPF8)
	ON_COMMAND(ID_ENHA_LPF9, OnEnhaLPF9)
	ON_COMMAND(ID_ENHA_MIDF, OnEnhaMidF)

	ON_COMMAND(ID_ENHA_HPF1, OnEnhaHPF1)
	ON_COMMAND(ID_ENHA_HPF2, OnEnhaHPF2)
	ON_COMMAND(ID_ENHA_AdaptMidianF, OnENHAAdaptMidianF)
	ON_COMMAND(ID_ENHA_HIGHENHA, OnEnhaHighenha)
	ON_COMMAND(ID_ENHA_GAUSSIANF, OnEnhaGaussianF)
	ON_COMMAND(ID_ENHA_ADAPATIVE_SMOOTH, OnEnhaAdapativeSmooth)

	ON_COMMAND(ID_PIC_ADD, OnPicAdd)
	ON_COMMAND(ID_PIC_SUB, OnPicSub)
	ON_COMMAND(ID_PIC_MUL, OnPicMul)
	
	ON_COMMAND(ID_ENHA_GRADSHARP, OnEnhaGradsharp)
	ON_COMMAND(ID_MORPH_EROSION, OnMorphErosion)
	ON_COMMAND(ID_MORPH_DILATION, OnMorphDilation)
	ON_COMMAND(ID_MORPH_OPEN, OnMorphOpen)
	ON_COMMAND(ID_MORPH_CLOSE, OnMorphClose)
	ON_COMMAND(ID_MORPH_THINING, OnMorphThining)
	ON_COMMAND(ID_GEOM_CALI, OnGeomCali)
	ON_COMMAND(ID_FILE_CLEAN, OnFileClean)
	ON_COMMAND(ID_FILE_SHOWINFO, OnFileInfoShow)
	ON_COMMAND(ID_COLOR_RGB2GRAY_MAX, OnColorRGB2GrayMax)
	ON_COMMAND(ID_COLOR_RGB2GRAY_EVEN, OnColorRGB2GrayEven)
	ON_COMMAND(ID_COLOR_RGB2GRAY_WEIGHT, OnColorRGB2GrayWeight)
	ON_COMMAND(ID_COLOR_GRAY2RGB_PSEUDO, OnColorGray2RGBPseudo)
	ON_COMMAND(ID_COLOR_GRAY2RGB_RAINBOW, OnColorGray2RGBRainbow)
	ON_COMMAND(ID_COLOR_RGBLEVEL_R, OnColorGetRLevel)
	ON_COMMAND(ID_COLOR_RGBLEVEL_G, OnColorGetGLevel)
	ON_COMMAND(ID_COLOR_RGBLEVEL_B, OnColorGetBLevel)
	ON_COMMAND(ID_COLOR_RGB2CMY, OnColorRGB2CMY)
	ON_COMMAND(ID_COLOR_CMY2RGB, OnColorCMY2RGB)
	ON_COMMAND(ID_COLOR_RGB2HSI, OnColorRGB2HSI)
	ON_COMMAND(ID_COLOR_HSI2RGB, OnColorHSI2RGB)
	ON_COMMAND(ID_COLOR_RGB2HSV, OnColorRGB2HSV)
	ON_COMMAND(ID_COLOR_HSV2RGB, OnColorHSV2RGB)
	ON_COMMAND(ID_COLOR_RGB2YUV, OnColorRGB2YUV)
	ON_COMMAND(ID_COLOR_YUV2RGB, OnColorYUV2RGB)
	ON_COMMAND(ID_COLOR_RGB2YIQ, OnColorRGB2YIQ)
	ON_COMMAND(ID_COLOR_YIQ2RGB, OnColorYIQ2RGB)
	
	ON_COMMAND(ID_REC_TEMPLATE, OnRecTemplate)
	ON_COMMAND(ID_FEA_GRAYMAT, OnFeaGraymat)
	ON_COMMAND(ID_MORPH_TRACE, OnMorphTrace)
	ON_COMMAND(ID_FILE_REVERSE, OnFileReverse)
	ON_COMMAND(ID_MORPH_FILLRGN, OnMorphFillrgn)
	ON_COMMAND(ID_MORPH_LABELCONNRGN, OnMorphLabelconnrgn)
	ON_COMMAND(ID_MORPH_PIXEL, OnMorphPixel)
	ON_COMMAND(ID_MORPH_CONVEX, OnMorphConvex)
	ON_COMMAND(ID_MORPH_GRAYDILATE, OnMorphGraydilate)
	ON_COMMAND(ID_MORPH_GRAYERODE, OnMorphGrayerode)
	ON_COMMAND(ID_MORPH_GRAYOPEN, OnMorphGrayopen)
	ON_COMMAND(ID_MORPH_GRAYCLOSE, OnMorphGrayclose)
	ON_COMMAND(ID_MORPH_TOPHAT, OnMorphTophat)
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(ID_FILE_PRINT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CScrollView::OnFilePrintPreview)
	ON_COMMAND(ID_POINT_STDLIN, CDIPView::OnPointStdlin)
	ON_COMMAND(ID_POINT_LOG, CDIPView::OnPointLog)
	ON_COMMAND(ID_POINT_GAMMA, CDIPView::OnPointGamma)
	ON_COMMAND(ID_POINT_HISTST, CDIPView::OnPointHistst)
	ON_COMMAND(ID_FILE_ROTATE, CDIPView::OnFileRotate)
	ON_COMMAND(ID_EDGE_ROBERT, CDIPView::OnEdgeRobert)
	ON_COMMAND(ID_EDGE_SOBEL, CDIPView::OnEdgeSobel)
	ON_COMMAND(ID_EDGE_PREWITT, CDIPView::OnEdgePrewitt)
	ON_COMMAND(ID_EDGE_LOG, CDIPView::OnEdgeLog)
	ON_COMMAND(ID_EDGE_SIMPTHRE, CDIPView::OnEdgeSimpthre)
	ON_COMMAND(ID_EDGE_AUTOTHRE, CDIPView::OnEdgeAutothre)
	ON_COMMAND(ID_NOISE_GAUSS, CDIPView::OnAddGaussian)
	ON_COMMAND(ID_NOISE_SALTPEPPER, CDIPView::OnAddSalt)
	ON_COMMAND(ID_NOISE_RAYLEIGH, CDIPView::OnAddRayleigh)
	ON_COMMAND(ID_NOISE_GAMMA, CDIPView::OnAddGamma)
	ON_COMMAND(ID_NOISE_EXP, CDIPView::OnAddExp)
	ON_COMMAND(ID_NOISE_UNIFORM, CDIPView::OnAddUniform)
	ON_COMMAND(ID_FREQ_IDEALLPF, CDIPView::OnFreqIdeallpf)
	ON_COMMAND(ID_FREQ_IDEALHPF, CDIPView::OnFreqIdealhpf)
	ON_COMMAND(ID_FREQ_BUTTERWORTHLPF, CDIPView::OnFreqButterworthlpf)
	ON_COMMAND(ID_FREQ_BUTTERWORTHHPF, CDIPView::OnFreqButterworthhpf)
	ON_COMMAND(ID_FREQ_GAUSSLPF, CDIPView::OnFreqGausslpf)
	ON_COMMAND(ID_FREQ_GAUSSHPF, CDIPView::OnFreqGausshpf)
	ON_COMMAND(ID_FREQ_EXPLPF, CDIPView::OnFreqExplpf)
	ON_COMMAND(ID_FREQ_EXPHPF, CDIPView::OnFreqExphpf)
	ON_COMMAND(ID_FREQ_LADDER_LPF, CDIPView::OnFreqLadderlpf)
	ON_COMMAND(ID_FREQ_LADDER_HPF, CDIPView::OnFreqLadderhpf)
	ON_COMMAND(ID_FREQ_LAPL, CDIPView::OnFreqLapl)
	ON_COMMAND(ID_FREQ_GAUSSBR, CDIPView::OnFreqGaussbr)
	ON_COMMAND(ID_EDGE_CANNY, CDIPView::OnEdgeCanny)
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_EDGE_REGION_GROW, CDIPView::OnEdgeRegionGrow)
	ON_COMMAND(ID_EDGE_HOUGH, CDIPView::OnEdgeHough)
	ON_COMMAND(ID_FILE_CONVERTGRAY, CDIPView::OnFileConvertgray)
	ON_COMMAND(ID_MATCHING_RGB_HIST, CDIPView::OnMatchingRGBHist)

END_MESSAGE_MAP()

/**********************************************/
// CDIPView construction/destruction

CDIPView::CDIPView() : m_bLBtnDblClkSrv(0)
{

}

CDIPView::~CDIPView()
{

}

BOOL CDIPView::PreCreateWindow(CREATESTRUCT& cs)
{
	return CView::PreCreateWindow(cs);
}

/**********************************************/
// CDIPView drawing

void CDIPView::OnDraw(CDC* pDC)
{
	BeginWaitCursor();								// ��ʾ�ȴ����
	CDIPDoc* pDoc = GetDocument();					// ��ȡ�ĵ�
	ASSERT_VALID(pDoc);

	if (pDoc->m_Image.IsValidate())
	{
		CPalette* pOldPalette;
		CPalette* pPalette = pDoc->GetDocPalette();

		if (pPalette != NULL)
		{
			pOldPalette = pDC->SelectPalette(pPalette, FALSE);
			pDC->RealizePalette();					//����ϵͳ��ɫ��
		}
		pDoc->m_Image.Draw(pDC);					//����ͼ��

		if (pPalette != NULL)
			pDC->SelectPalette(pOldPalette, FALSE);
	}
	EndWaitCursor();								// �ָ��������
}

void CDIPView::OnDraw2(CDC* pDC)
{
	BeginWaitCursor();								// ��ʾ�ȴ����
	CDIPDoc* pDoc = GetDocument();					// ��ȡ�ĵ�
	ASSERT_VALID(pDoc);

	if (pDoc->m_Image.IsValidate())
		pDoc->m_Image.Draw2(pDC);					//����ͼ��

	EndWaitCursor();								// �ָ��������
}

BOOL CDIPView::OnPreparePrinting( CPrintInfo* pInfo)
{
	pInfo->SetMaxPage(1);							// ������ҳ��Ϊһ
	return DoPreparePrinting(pInfo);
}

void CDIPView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{

}

void CDIPView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	
}

#ifdef _DEBUG
void CDIPView::AssertValid() const
{
	CView::AssertValid();
}

void CDIPView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDIPDoc* CDIPView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDIPDoc)));
	return (CDIPDoc*)m_pDocument;
}
#endif //_DEBUG

/**********************************************/
// CDIPView message handlers

BOOL CDIPView::OnEraseBkgnd(CDC* pDC)
{
	// ��Ҫ��Ϊ�������Ӵ���Ĭ�ϵı���ɫ
	// ����ɫ���ĵ���Ա����m_refColorBKGָ��
	CDIPDoc* pDoc = GetDocument();			// ��ȡ�ĵ�
	CBrush brush(pDoc->m_refColorBKG);		// ����һ��Brush
	CBrush* pOldBrush = pDC->SelectObject(&brush);	// ������ǰ��Brush
	CRect rectClip;							// ��ȡ�ػ�����
	pDC->GetClipBox(&rectClip);				// �ػ�
	pDC->PatBlt(rectClip.left, rectClip.top, rectClip.Width(), rectClip.Height(), PATCOPY);
	pDC->SelectObject(pOldBrush);			// �ָ���ǰ��Brush
	return TRUE;
}

void CDIPView::OnInitialUpdate()
{
	CView::OnInitialUpdate();
}

void CDIPView::CalcWindowRect(LPRECT lpClientRect, UINT nAdjustType)
{
	CScrollView::OnInitialUpdate();
	ASSERT(GetDocument() != NULL);
	SetScrollSizes(MM_TEXT, GetDocument()->GetDocSize());
}

void CDIPView::OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView)
{
	CScrollView::OnActivateView(bActivate, pActivateView, pDeactiveView);

	if (bActivate)
	{
		ASSERT(pActivateView == this);
		Invalidate();						// �������ͼʱ�����ػ�
	}
}

void CDIPView::OnViewIntensity()
{
	// �鿴��ǰͼ��Ҷ�ֱ��ͼ
	CDIPDoc* pDoc = GetDocument();			// ��ȡ�ĵ�
	CImgProcess imgInput = pDoc->m_Image;	// �������

	if (imgInput.m_pBMIH->biBitCount != 8)	// ���ͼ���ǻҶ�ͼ
	{
		AfxMessageBox(L"����8-bpp�Ҷ�ͼ���޷�����");
		return;
	}
	double hist[256];						// ֱ��ͼ����
	BeginWaitCursor();						// ����æ״̬
	imgInput.GenHist(hist);					// ��ȡֱ��ͼ����
	CDlgHist dlg;
	dlg.m_pdHist = hist;

	if (dlg.DoModal() != IDOK)
		return;								// ����

	pDoc->UpdateAllViews(NULL);				// ������ͼ
	EndWaitCursor();						// �ָ����
}

void CDIPView::OnViewRGBIntensity()
{
	// �鿴��ǰͼ��Ҷ�ֱ��ͼ
	CDIPDoc* pDoc = GetDocument();			// ��ȡ�ĵ�
	CImgProcess imgInput = pDoc->m_Image;	// �������

	if (imgInput.m_pBMIH->biBitCount != 24)	// ���ͼ���ǻҶ�ͼ
	{
		AfxMessageBox(L"����24-bppͼ���޷�����");
		return;
	}

	// ֱ��ͼ����
	double histR[256];
	double histG[256];
	double histB[256];
	
	BeginWaitCursor();						// ����æ״̬
	imgInput.GenRGBHist(histR, 1);			// ��R�����ֲ�ֱ��ͼ
	imgInput.GenRGBHist(histG, 2);			// ��G�����ֲ�ֱ��ͼ
	imgInput.GenRGBHist(histB, 3);			// ��B�����ֲ�ֱ��ͼ

	CDlgRGBHist dlg;
	dlg.m_pdHistR = histR;
	dlg.m_pdHistG = histG;
	dlg.m_pdHistB = histB;

	if (dlg.DoModal() != IDOK)
		return;								// ����

	pDoc->UpdateAllViews(NULL);				// ������ͼ
	EndWaitCursor();						// �ָ����
}

void CDIPView::OnMatchingRGBHist()
{
	CDIPDoc* pDoc = GetDocument();				// ��ȡ�ĵ�
	CImgProcess imgInput = pDoc->m_Image;		// �������
	CImgProcess* pStdImage = new CImgProcess();	// ��׼ͼ��

	// ͨ���򿪶Ի����ȡ��׼ͼ��
	CString filePath;							// �ļ�·��
	CFileDialog openDlg(TRUE, 0, 0, 4 | 2,
		L"Bitmap Files (*.bmp)||");				// ���ļ��Ի�������û����ȡ���򷵻�
	if (openDlg.DoModal() == IDOK)
		filePath = openDlg.GetPathName();
	else
		return;

	double* dResult1 = new double[9];
	double* dResult2 = new double[9];
	double dResult = 0;
	pStdImage->AttachFromFile(filePath);		// ��ȡ��׼ͼ��

	dResult1 = imgInput.StatisticRGBMoment(&imgInput);		// ��ȡͼ��1����ɫ�ؼ�����
	dResult2 = pStdImage->StatisticRGBMoment(pStdImage);	// ��ȡͼ��1����ɫ�ؼ�����

	for (int i = 0; i < 9; i++)
		dResult += abs(dResult2[i] - dResult1[i]);
	
	if(dResult == 0.0)
		AfxMessageBox(L"��ȫһ����");

	else if (dResult != 0 && dResult <= 200.0)
		AfxMessageBox(L"ʮ�����ƣ�");

	else if (dResult > 200.0 && dResult <= 400.0)
		AfxMessageBox(L"��Ϊ���ƣ�");

	else
		AfxMessageBox(L"�����ƣ�");

	pDoc->m_Image = *pStdImage;					// ��������ظ��ĵ���
	delete pStdImage;
	delete[] dResult1;
	delete[] dResult2;
}

void CDIPView::OnGetBitLayerI()
{
	// ��ȡλ��I
	CDIPDoc* pDoc = GetDocument();			// ��ȡ�ĵ�
	CImgProcess imgInput = pDoc->m_Image;	// �������
	if (imgInput.m_pBMIH->biBitCount != 8)	// ���ͼ���ǻҶ�ͼ
	{
		AfxMessageBox(L"����8-bpp�Ҷ�ͼ���޷�����");
		return;
	}
	BeginWaitCursor();						// ���Ĺ����״
	CImgProcess imgOutput = imgInput;		// �������ʱ����
	imgInput.GetBitLayer(&imgOutput,1);		// ����VerMirror()����ʵ��ͼ����ֱ����
	pDoc->m_Image = imgOutput;				// ��������ظ��ĵ���
	pDoc->SetModifiedFlag(TRUE);			// �����޸ı�ʶ
	pDoc->UpdateAllViews(NULL);				// ������ͼ
	EndWaitCursor();						// �ָ����
}

void CDIPView::OnGetBitLayerII()
{
	// ��ȡλ��I
	CDIPDoc* pDoc = GetDocument();			// ��ȡ�ĵ�
	CImgProcess imgInput = pDoc->m_Image;	// �������
	if (imgInput.m_pBMIH->biBitCount != 8)	// ���ͼ���ǻҶ�ͼ
	{
		AfxMessageBox(L"����8-bpp�Ҷ�ͼ���޷�����");
		return;
	}
	BeginWaitCursor();						// ���Ĺ����״
	CImgProcess imgOutput = imgInput;		// �������ʱ����
	imgInput.GetBitLayer(&imgOutput, 2);	// ����VerMirror()����ʵ��ͼ����ֱ����
	pDoc->m_Image = imgOutput;				// ��������ظ��ĵ���
	pDoc->SetModifiedFlag(TRUE);			// �����޸ı�ʶ
	pDoc->UpdateAllViews(NULL);				// ������ͼ
	EndWaitCursor();						// �ָ����
}

void CDIPView::OnGetBitLayerIII()
{
	// ��ȡλ��I
	CDIPDoc* pDoc = GetDocument();			// ��ȡ�ĵ�
	CImgProcess imgInput = pDoc->m_Image;	// �������
	if (imgInput.m_pBMIH->biBitCount != 8)	// ���ͼ���ǻҶ�ͼ
	{
		AfxMessageBox(L"����8-bpp�Ҷ�ͼ���޷�����");
		return;
	}
	BeginWaitCursor();						// ���Ĺ����״
	CImgProcess imgOutput = imgInput;		// �������ʱ����
	imgInput.GetBitLayer(&imgOutput, 3);	// ����VerMirror()����ʵ��ͼ����ֱ����
	pDoc->m_Image = imgOutput;				// ��������ظ��ĵ���
	pDoc->SetModifiedFlag(TRUE);			// �����޸ı�ʶ
	pDoc->UpdateAllViews(NULL);				// ������ͼ
	EndWaitCursor();						// �ָ����
}

void CDIPView::OnGetBitLayerIV()
{
	// ��ȡλ��I
	CDIPDoc* pDoc = GetDocument();			// ��ȡ�ĵ�
	CImgProcess imgInput = pDoc->m_Image;	// �������
	if (imgInput.m_pBMIH->biBitCount != 8)	// ���ͼ���ǻҶ�ͼ
	{
		AfxMessageBox(L"����8-bpp�Ҷ�ͼ���޷�����");
		return;
	}
	BeginWaitCursor();						// ���Ĺ����״
	CImgProcess imgOutput = imgInput;		// �������ʱ����
	imgInput.GetBitLayer(&imgOutput, 4);	// ����VerMirror()����ʵ��ͼ����ֱ����
	pDoc->m_Image = imgOutput;				// ��������ظ��ĵ���
	pDoc->SetModifiedFlag(TRUE);			// �����޸ı�ʶ
	pDoc->UpdateAllViews(NULL);				// ������ͼ
	EndWaitCursor();						// �ָ����
}

void CDIPView::OnGetBitLayerV()
{
	// ��ȡλ��I
	CDIPDoc* pDoc = GetDocument();			// ��ȡ�ĵ�
	CImgProcess imgInput = pDoc->m_Image;	// �������
	if (imgInput.m_pBMIH->biBitCount != 8)	// ���ͼ���ǻҶ�ͼ
	{
		AfxMessageBox(L"����8-bpp�Ҷ�ͼ���޷�����");
		return;
	}
	BeginWaitCursor();						// ���Ĺ����״
	CImgProcess imgOutput = imgInput;		// �������ʱ����
	imgInput.GetBitLayer(&imgOutput, 5);	// ����VerMirror()����ʵ��ͼ����ֱ����
	pDoc->m_Image = imgOutput;				// ��������ظ��ĵ���
	pDoc->SetModifiedFlag(TRUE);			// �����޸ı�ʶ
	pDoc->UpdateAllViews(NULL);				// ������ͼ
	EndWaitCursor();						// �ָ����
}

void CDIPView::OnGetBitLayerVI()
{
	// ��ȡλ��I
	CDIPDoc* pDoc = GetDocument();			// ��ȡ�ĵ�
	CImgProcess imgInput = pDoc->m_Image;	// �������
	if (imgInput.m_pBMIH->biBitCount != 8)	// ���ͼ���ǻҶ�ͼ
	{
		AfxMessageBox(L"����8-bpp�Ҷ�ͼ���޷�����");
		return;
	}
	BeginWaitCursor();						// ���Ĺ����״
	CImgProcess imgOutput = imgInput;		// �������ʱ����
	imgInput.GetBitLayer(&imgOutput, 6);	// ����VerMirror()����ʵ��ͼ����ֱ����
	pDoc->m_Image = imgOutput;				// ��������ظ��ĵ���
	pDoc->SetModifiedFlag(TRUE);			// �����޸ı�ʶ
	pDoc->UpdateAllViews(NULL);				// ������ͼ
	EndWaitCursor();						// �ָ����
}

void CDIPView::OnGetBitLayerVII()
{
	// ��ȡλ��I
	CDIPDoc* pDoc = GetDocument();			// ��ȡ�ĵ�
	CImgProcess imgInput = pDoc->m_Image;	// �������
	if (imgInput.m_pBMIH->biBitCount != 8)	// ���ͼ���ǻҶ�ͼ
	{
		AfxMessageBox(L"����8-bpp�Ҷ�ͼ���޷�����");
		return;
	}
	BeginWaitCursor();						// ���Ĺ����״
	CImgProcess imgOutput = imgInput;		// �������ʱ����
	imgInput.GetBitLayer(&imgOutput, 7);	// ����VerMirror()����ʵ��ͼ����ֱ����
	pDoc->m_Image = imgOutput;				// ��������ظ��ĵ���
	pDoc->SetModifiedFlag(TRUE);			// �����޸ı�ʶ
	pDoc->UpdateAllViews(NULL);				// ������ͼ
	EndWaitCursor();						// �ָ����
}

void CDIPView::OnGetBitLayerVIII()
{
	// ��ȡλ��I
	CDIPDoc* pDoc = GetDocument();			// ��ȡ�ĵ�
	CImgProcess imgInput = pDoc->m_Image;	// �������
	if (imgInput.m_pBMIH->biBitCount != 8)	// ���ͼ���ǻҶ�ͼ
	{
		AfxMessageBox(L"����8-bpp�Ҷ�ͼ���޷�����");
		return;
	}
	BeginWaitCursor();						// ���Ĺ����״
	CImgProcess imgOutput = imgInput;		// �������ʱ����
	imgInput.GetBitLayer(&imgOutput, 8);	// ����VerMirror()����ʵ��ͼ����ֱ����
	pDoc->m_Image = imgOutput;				// ��������ظ��ĵ���
	pDoc->SetModifiedFlag(TRUE);			// �����޸ı�ʶ
	pDoc->UpdateAllViews(NULL);				// ������ͼ
	EndWaitCursor();						// �ָ����
}

void CDIPView::OnPointLiner()
{
	// ���Ա任
	CDIPDoc* pDoc = GetDocument();			// ��ȡ�ĵ�
	CImgProcess imgInput = pDoc->m_Image;	// �������

	// ���ͼ���ǻҶ�ͼ
	if (imgInput.m_pBMIH->biBitCount != 8)
	{
		AfxMessageBox(L"����8-bpp�Ҷ�ͼ���޷�����");
		return;
	}
	CDlgLinerPara dlgPara;					// �����Ի���
	double fA;								// ���Ա任��б��
	double fB;								// ���Ա任�Ľؾ�
	dlgPara.m_fA = 1.0;						// ��ʼ������ֵ
	dlgPara.m_fB = 0.0;
	if (dlgPara.DoModal() != IDOK)			// ��ʾ�Ի�����ʾ�û��趨����
		return;								// ����
	fA = dlgPara.m_fA;						// ��ȡ�û��趨�Ĳ���
	fB = dlgPara.m_fB;
	BeginWaitCursor();						// ���Ĺ����״
	CImgProcess imgOutput = imgInput;		// �������ʱ����
	imgInput.LinTran(&imgOutput, fA, fB);	// ����LinTran()�����������Ա任
	pDoc->m_Image = imgOutput;				// ��������ظ��ĵ���
	pDoc->SetModifiedFlag(TRUE);			// �����޸ı�ʶ
	pDoc->UpdateAllViews(NULL);				// ������ͼ
	EndWaitCursor();						// �ָ����
}

void CDIPView::OnPointThre()
{
	// ��ֵ�任
	CDIPDoc* pDoc = GetDocument();			// ��ȡ�ĵ�
	BYTE bThre;								// ��ֵ
	CImgProcess imgInput = pDoc->m_Image;	// �������

	// ���ͼ���ǻҶ�ͼ
	if (imgInput.m_pBMIH->biBitCount != 8)
	{
		AfxMessageBox(L"����8-bpp�Ҷ�ͼ���޷�����");
		return;
	}

	CDlgPointThre dlgPara;					// �����Ի���

	// ��ʾ�Ի�����ʾ�û��趨��ֵ
	if (dlgPara.DoModal() != IDOK)
		return;								// ����

	//bThre = dlgPara.m_bThre;				// ��ȡ�û��趨����ֵ
	BeginWaitCursor();						// ���Ĺ����״
	CImgProcess imgOutput = imgInput;		// �������ʱ����
	imgInput.Threshold(&imgOutput, 
		dlgPara.m_bThre);					// ����Threshold����������ֵ�任
	pDoc->m_Image = imgOutput;				// ��������ظ��ĵ���
	pDoc->SetModifiedFlag(TRUE);			// �����޸ı�ʶ
	pDoc->UpdateAllViews(NULL);				// ������ͼ
	EndWaitCursor();						// �ָ����
}

void CDIPView::OnPointWind()
{
	CDIPDoc* pDoc = GetDocument();
	CImgProcess imgInput = pDoc->m_Image;	// �������

	// ���ͼ���ǻҶ�ͼ
	if (imgInput.m_pBMIH->biBitCount != 8)
	{
		AfxMessageBox(L"����8-bpp�Ҷ�ͼ���޷�����");
		return;
	}

	double dpHist[256];						// ֱ��ͼ����
	CImgProcess imgOutput = imgInput;		// �������ʱ����
	imgInput.GenHist(dpHist);				// ��ȡֱ��ͼ����
	CDlgWndTran dlg;						// ������������Ի���
	dlg.m_bLower = 0;
	dlg.m_bUpper = 255;
	dlg.m_dHist = dpHist;

	if (dlg.DoModal() != IDOK)
		return;

	// ���ڱ任
	imgInput.WindowTran(&imgOutput, dlg.m_bLower, dlg.m_bUpper);
	// ��������ظ��ĵ���
	pDoc->m_Image = imgOutput;
	pDoc->SetModifiedFlag(true);
	pDoc->UpdateAllViews(NULL);
}

void CDIPView::OnPointEqua()
{
	CDIPDoc* pDoc = GetDocument();
	CImgProcess imgInput = pDoc->m_Image;	// �������

	// ���ͼ���ǻҶ�ͼ
	if (imgInput.m_pBMIH->biBitCount != 8)
	{
		AfxMessageBox(L"����8-bpp�Ҷ�ͼ���޷�����");
		return;
	}

	CImgProcess imgOutput = imgInput;		// �������ʱ����
	imgInput.Histeq(&imgOutput);			// ֱ��ͼ���⻯
	pDoc->m_Image = imgOutput;				// ��������ظ��ĵ���
	pDoc->SetModifiedFlag(true);
	pDoc->UpdateAllViews(NULL);
}

void CDIPView::OnGeomTran()
{
	CDIPDoc* pDoc = GetDocument();			// ��ȡ�ĵ�
	CImgProcess imgInput = pDoc->m_Image;	// �������

	LONG lXOffset;
	LONG lYOffset;
	CDlgGeoTran dlgPara;					// �����Ի���
	dlgPara.m_XOffset = 100;				// ��ʼ������ֵ
	dlgPara.m_YOffset = 100;

	// ��ʾ�Ի�����ʾ�û��趨����
	if (dlgPara.DoModal() != IDOK)
		return;// ����

	lXOffset = dlgPara.m_XOffset;			// ��ȡ�û��趨�Ĳ���
	lYOffset = dlgPara.m_YOffset;
	BeginWaitCursor();						// ���Ĺ����״
	CImgProcess imgOutput = imgInput;		// �������ʱ����
	imgInput.ImMove(&imgOutput,
		lXOffset, lYOffset);				// ����ImMove()����ʵ��ͼ��ƽ��
	pDoc->m_Image = imgOutput;				// ��������ظ��ĵ���
	pDoc->SetModifiedFlag(TRUE);			// �����޸ı�ʶ
	pDoc->UpdateAllViews(NULL);				// ������ͼ
	EndWaitCursor();						// �ָ����
}

void CDIPView::OnGeomMirv()
{
	// ��ֱ����
	CDIPDoc* pDoc = GetDocument();			// ��ȡ�ĵ�
	CImgProcess imgInput = pDoc->m_Image;	// �������
	
	BeginWaitCursor();						// ���Ĺ����״
	CImgProcess imgOutput = imgInput;		// �������ʱ����
	imgInput.VerMirror(&imgOutput);			// ����VerMirror()����ʵ��ͼ����ֱ����
	pDoc->m_Image = imgOutput;				// ��������ظ��ĵ���
	pDoc->SetModifiedFlag(TRUE);			// �����޸ı�ʶ
	pDoc->UpdateAllViews(NULL);				// ������ͼ
	EndWaitCursor();						// �ָ����
}

void CDIPView::OnGeomMirh()
{
	// ˮƽ����
	CDIPDoc* pDoc = GetDocument();			// ��ȡ�ĵ�
	CImgProcess imgInput = pDoc->m_Image;	// �������

	BeginWaitCursor();						// ���Ĺ����״
	CImgProcess imgOutput = imgInput;		// �������ʱ����
	imgInput.HorMirror(&imgOutput);			// ����HorMirror()����ʵ��ͼ��ˮƽ����
	pDoc->m_Image = imgOutput;				// ��������ظ��ĵ���
	pDoc->SetModifiedFlag(TRUE);			// �����޸ı�ʶ
	pDoc->UpdateAllViews(NULL);				// ������ͼ
	EndWaitCursor();						// �ָ����
}

void CDIPView::OnGeomTrpo()
{
	// ͼ��ת��
	CDIPDoc* pDoc = GetDocument();			// ��ȡ�ĵ�
	CImgProcess imgInput = pDoc->m_Image;	// �������

	BeginWaitCursor();						// ���Ĺ����״
	CImgProcess imgOutput = imgInput;		// �������ʱ����
	imgInput.Transpose(&imgOutput);			// ����Transpose()����ʵ��ͼ��ת��
	pDoc->m_Image = imgOutput;				// ��������ظ��ĵ���
	pDoc->SetModifiedFlag(TRUE);			// �����޸ı�ʶ
	pDoc->UpdateAllViews(NULL);				// ������ͼ
	EndWaitCursor();						// �ָ����
}

void CDIPView::OnGeomZoom1()
{
	// ͼ������
	CDIPDoc* pDoc = GetDocument();			// ��ȡ�ĵ�
	CImgProcess imgInput = pDoc->m_Image;	// �������
	
	double fZoomRatio;						// ���ű���
	CDlgGeoZoom dlgPara;					// �����Ի���

	if (dlgPara.DoModal() != IDOK)			// ��ʾ�Ի�����ʾ�û��趨����
		return;// ����

	fZoomRatio = dlgPara.m_Zoom;			// ��ȡ�û��趨�Ĳ���
	BeginWaitCursor();						// ���Ĺ����״
	CImgProcess imgOutput = imgInput;		// �������ʱ����
	imgInput.Scale1(&imgOutput, fZoomRatio);// ����Scale()����ʵ��ͼ������
	pDoc->m_Image = imgOutput;				// ��������ظ��ĵ���
	pDoc->SetModifiedFlag(TRUE);			// �����޸ı�ʶ
	pDoc->UpdateAllViews(NULL);				// ������ͼ
	EndWaitCursor();						// �ָ����
}

void CDIPView::OnGeomZoom2()
{
	// ͼ������
	CDIPDoc* pDoc = GetDocument();			// ��ȡ�ĵ�
	CImgProcess imgInput = pDoc->m_Image;	// �������

	double dZoomRatioX, dZoomRatioY;		// ���ű���
	CDlgGeoZoom2 dlgPara;					// �����Ի���

	if (dlgPara.DoModal() != IDOK)			// ��ʾ�Ի�����ʾ�û��趨����
		return;// ����

	dZoomRatioX = dlgPara.m_ZoomX;			// ��ȡ�û��趨�Ĳ���
	dZoomRatioY = dlgPara.m_ZoomY;			// ��ȡ�û��趨�Ĳ���
	BeginWaitCursor();						// ���Ĺ����״
	CImgProcess imgOutput = imgInput;		// �������ʱ����
	imgInput.Scale2(&imgOutput, 
		dZoomRatioX, dZoomRatioY);			// ����Scale()����ʵ��ͼ������
	pDoc->m_Image = imgOutput;				// ��������ظ��ĵ���
	pDoc->SetModifiedFlag(TRUE);			// �����޸ı�ʶ
	pDoc->UpdateAllViews(NULL);				// ������ͼ
	EndWaitCursor();						// �ָ����
}

void CDIPView::OnGeomRota()
{
	// ͼ����ת
	CDIPDoc* pDoc = GetDocument();			// ��ȡ�ĵ�
	CImgProcess imgInput = pDoc->m_Image;	// �������
	
	int iRotateAngle;						// ��ת�Ƕ�
	CDlgGeoRota dlgPara;					// �����Ի���
	dlgPara.m_iRotateAngle = 30;			// ��ʼ������ֵ
	if (dlgPara.DoModal() != IDOK)			// ��ʾ�Ի�����ʾ�û��趨��ת�Ƕ�
		return;// ����

	iRotateAngle = dlgPara.m_iRotateAngle;	// ��ȡ�û��趨�Ĳ���
	BeginWaitCursor();						// ���Ĺ����״
	CImgProcess imgOutput = imgInput;		// �������ʱ����
	imgInput.Rotate(&imgOutput,
		(double)iRotateAngle);				// ����Rotate()����ʵ��ͼ����ת
	pDoc->m_Image = imgOutput;				// ��������ظ��ĵ���
	pDoc->SetModifiedFlag(TRUE);			// ��������ظ��ĵ���
	pDoc->UpdateAllViews(NULL);				// ������ͼ
	EndWaitCursor();						// �ָ����
}

void CDIPView::OnGeomCali()
{
	// ͶӰУ��
	CDIPDoc* pDoc = GetDocument();			// ��ȡ�ĵ�
	CImgProcess imgInput = pDoc->m_Image;	// �������
	if (imgInput.m_pBMIH->biBitCount != 8)	// ���ͼ���ǻҶ�ͼ
	{
		AfxMessageBox(L"����8-bpp�Ҷ�ͼ���޷�����");
		return;
	}

	CImgProcess imgOutput = imgInput;		// �������ʱ����
	CPoint pBasePts[4];						// ��׼ͼ���׼������
	CPoint pSrcPts[4];						// ����ͼ���׼������
	CDlgProjRestore dlgPara;				// �����Ի���
	// ��ʼ������ͼ���׼��
	dlgPara.m_xPt1 = 108;
	dlgPara.m_yPt1 = 135;
	dlgPara.m_xPt2 = 274;
	dlgPara.m_yPt2 = 51;
	dlgPara.m_xPt3 = 295;
	dlgPara.m_yPt3 = 119;
	dlgPara.m_xPt4 = 158;
	dlgPara.m_yPt4 = 248;
	// ��ʼ����׼ͼ���׼��
	dlgPara.m_xBPt1 = 0;
	dlgPara.m_yBPt1 = 0;
	dlgPara.m_xBPt2 = 310;
	dlgPara.m_yBPt2 = 0;
	dlgPara.m_xBPt3 = 310;
	dlgPara.m_yBPt3 = 100;
	dlgPara.m_xBPt4 = 0;
	dlgPara.m_yBPt4 = 100;

	if (dlgPara.DoModal() != IDOK)			// ��ʾ�Ի�����ʾ�û��趨����
		return;								// ����

	// ��ȡ�û��趨�Ĳ���
	pBasePts[0] = CPoint(dlgPara.m_xBPt1, dlgPara.m_yBPt1);
	pBasePts[1] = CPoint(dlgPara.m_xBPt2, dlgPara.m_yBPt2);
	pBasePts[2] = CPoint(dlgPara.m_xBPt3, dlgPara.m_yBPt3);
	pBasePts[3] = CPoint(dlgPara.m_xBPt4, dlgPara.m_yBPt4);
	pSrcPts[0]  = CPoint(dlgPara.m_xPt1, dlgPara.m_yPt1);
	pSrcPts[1]  = CPoint(dlgPara.m_xPt2, dlgPara.m_yPt2);
	pSrcPts[2]  = CPoint(dlgPara.m_xPt3, dlgPara.m_yPt3);
	pSrcPts[3]  = CPoint(dlgPara.m_xPt4, dlgPara.m_yPt4);
	BeginWaitCursor();						// ���Ĺ����״
	imgInput.ImProjRestore(&imgOutput, pBasePts,
		pSrcPts, 1);						// ʹ��˫���Բ�ֵ��ͶӰУ��
	pDoc->m_Image = imgOutput;				// ��������ظ��ĵ���		
	pDoc->SetModifiedFlag(TRUE);			// �����޸ı�ʶ	
	pDoc->UpdateAllViews(NULL);				// ������ͼ	
	EndWaitCursor();						// �ָ����
}

void CDIPView::OnAddGaussian()				// ��˹����
{
	CDIPDoc* pDoc = GetDocument();
	CImgProcess imgInput = pDoc->m_Image;

	if (imgInput.m_pBMIH->biBitCount != 8)
	{
		AfxMessageBox(L"�Բ��𣬵�ǰ��δʵ�ֲ�ɫͼ��ļ��봦��");
		return;
	}

	CDlgNoiseGauss dlg;
	if (dlg.DoModal() != IDOK)
		return;

	CImgProcess imgOutput = imgInput;
	imgInput.AddGaussian(&imgOutput, dlg.m_dRate, dlg.m_dSigma);
	pDoc->m_Image = imgOutput;
	pDoc->SetModifiedFlag(TRUE);			// �����޸ı�ʶ
	pDoc->UpdateAllViews(NULL);				// ����ͼ����ʾ
}

void CDIPView::OnAddSalt()					// ��������
{
	CDIPDoc* pDoc = GetDocument();
	CImgProcess imgInput = pDoc->m_Image;

	if (imgInput.m_pBMIH->biBitCount != 8)
	{
		AfxMessageBox(L"�Բ��𣬵�ǰ��δʵ�ֲ�ɫͼ��ļ��봦��");
		return;
	}

	CDlgNoiseSaltPepper dlg;
	if (dlg.DoModal() != IDOK)
		return;

	if(dlg.m_dRate >= 0.5)
	{
		AfxMessageBox(L"������ǿ�ȳ���0.5�����������ã�");
		return;
	}
	CImgProcess imgOutput = imgInput;
	imgInput.AddSalt_Pepper(&imgOutput, dlg.m_dRate);
	pDoc->m_Image = imgOutput;
	pDoc->SetModifiedFlag(TRUE);			// �����޸ı�ʶ
	pDoc->UpdateAllViews(NULL);				// ����ͼ����ʾ
}

void CDIPView::OnAddRayleigh()				// ��������
{
	CDIPDoc* pDoc = GetDocument();
	CImgProcess imgInput = pDoc->m_Image;

	if (imgInput.m_pBMIH->biBitCount != 8)
	{
		AfxMessageBox(L"�Բ��𣬵�ǰ��δʵ�ֲ�ɫͼ��ļ��봦��");
		return;
	}

	CDlgNoiseRayleigh dlg;
	if (dlg.DoModal() != IDOK)
		return;

	CImgProcess imgOutput = imgInput;
	imgInput.AddRayleigh(&imgOutput,dlg.m_dRate,dlg.m_dSigma);
	pDoc->m_Image = imgOutput;
	pDoc->SetModifiedFlag(TRUE);			// �����޸ı�ʶ
	pDoc->UpdateAllViews(NULL);				// ����ͼ����ʾ
}

void CDIPView::OnAddGamma()					// ٤������
{
	CDIPDoc* pDoc = GetDocument();
	CImgProcess imgInput = pDoc->m_Image;

	if (imgInput.m_pBMIH->biBitCount != 8)
	{
		AfxMessageBox(L"�Բ��𣬵�ǰ��δʵ�ֲ�ɫͼ��ļ��봦��");
		return;
	}

	CDlgNoiseGamma dlg;
	if (dlg.DoModal() != IDOK)
		return;

	CImgProcess imgOutput = imgInput;
	imgInput.AddGamma(&imgOutput,dlg.m_dA,dlg.m_dB);
	pDoc->m_Image = imgOutput;
	pDoc->SetModifiedFlag(TRUE);			// �����޸ı�ʶ
	pDoc->UpdateAllViews(NULL);				// ����ͼ����ʾ
}

void CDIPView::OnAddExp()					// ָ������
{
	CDIPDoc* pDoc = GetDocument();
	CImgProcess imgInput = pDoc->m_Image;

	if (imgInput.m_pBMIH->biBitCount != 8)
	{
		AfxMessageBox(L"�Բ��𣬵�ǰ��δʵ�ֲ�ɫͼ��ļ��봦��");
		return;
	}

	CDlgNoiseExp dlg;
	if (dlg.DoModal() != IDOK)
		return;

	CImgProcess imgOutput = imgInput;
	imgInput.AddExp(&imgOutput,dlg.m_dA);
	pDoc->m_Image = imgOutput;
	pDoc->SetModifiedFlag(TRUE);			// �����޸ı�ʶ
	pDoc->UpdateAllViews(NULL);				// ����ͼ����ʾ
}

void CDIPView::OnAddUniform()				// ��������
{
	CDIPDoc* pDoc = GetDocument();
	CImgProcess imgInput = pDoc->m_Image;

	if (imgInput.m_pBMIH->biBitCount != 8)
	{
		AfxMessageBox(L"�Բ��𣬵�ǰ��δʵ�ֲ�ɫͼ��ļ��봦��");
		return;
	}

	CDlgNoiseUniform dlg;
	if (dlg.DoModal() != IDOK)
		return;

	CImgProcess imgOutput = imgInput;
	imgInput.AddUniform(&imgOutput, dlg.m_dLow, dlg.m_dHigh);
	pDoc->m_Image = imgOutput;
	pDoc->SetModifiedFlag(TRUE);			// �����޸ı�ʶ
	pDoc->UpdateAllViews(NULL);				// ����ͼ����ʾ
}

void CDIPView::OnEnhaSmooth()
{
	// ƽ���˲�
	CDIPDoc* pDoc = GetDocument();			// ��ȡ�ĵ�
	CImgProcess imgInput = pDoc->m_Image;	// �������

	if (imgInput.m_pBMIH->biBitCount != 8)	// ���ͼ���ǻҶ�ͼ
	{
		AfxMessageBox(L"����8-bpp�Ҷ�ͼ���޷�����");
		return;
	}

	CImgProcess imgOutput = imgInput;		// �������ʱ����
	int nTempH;								// ģ��߶�
	int nTempW;								// ģ����
	int nTempMX;							// ģ������Ԫ��X����
	int nTempMY;							// ģ������Ԫ��Y����
	double fTempC;							// ģ��ϵ��
	double aValue[25] =						// ģ��Ԫ�����鸳��ֵ��Ĭ��Ϊƽ��ģ�壩
	{ 1.0, 1.0, 1.0, 0.0, 0.0,
	  1.0, 1.0, 1.0, 0.0, 0.0,
	  1.0, 1.0, 1.0, 0.0, 0.0,
	  0.0, 0.0, 0.0, 0.0, 0.0,
	  0.0, 0.0, 0.0, 0.0, 0.0,
	};
	CDlgSmooth dlgPara;						// �����Ի���
	dlgPara.m_intType = 0;					// ��ʼ���Ի������ֵ
	dlgPara.m_iTempH = 3;
	dlgPara.m_iTempW = 3;
	dlgPara.m_iTempMX = 1;
	dlgPara.m_iTempMY = 1;
	dlgPara.m_fTempC = (double)(1.0 / 9.0);
	dlgPara.m_fpArray = aValue;

	if (dlgPara.DoModal() != IDOK)			// ��ʾ�Ի�����ʾ�û��趨����
		return;								// ����
	nTempH = dlgPara.m_iTempH;				// ��ȡ�û��趨�Ĳ���
	nTempW = dlgPara.m_iTempW;
	nTempMX = dlgPara.m_iTempMX;
	nTempMY = dlgPara.m_iTempMY;
	fTempC = dlgPara.m_fTempC;
	BeginWaitCursor();						// ���Ĺ����״
	imgInput.Template(&imgOutput, nTempH, nTempW,
		nTempMY, nTempMX, aValue, fTempC);	// ����Template()����ʵ��ƽ���˲�
	pDoc->m_Image = imgOutput;				// ��������ظ��ĵ���
	pDoc->SetModifiedFlag(TRUE);			// �����޸ı�ʶ
	pDoc->UpdateAllViews(NULL);				// ������ͼ
	EndWaitCursor();						// �ָ����
}

void CDIPView::OnEnhaMidianF()
{
	// ��ֵ�˲�
	CDIPDoc* pDoc = GetDocument();			// ��ȡ�ĵ�
	CImgProcess imgInput = pDoc->m_Image;	// �������
	if (imgInput.m_pBMIH->biBitCount != 8)	// ���ͼ���ǻҶ�ͼ
	{
		AfxMessageBox(L"����8-bpp�Ҷ�ͼ���޷�����");
		return;
	}

	BeginWaitCursor();						// ���Ĺ����״
	CImgProcess imgOutput = imgInput;		// �������ʱ����

	CDlgEnhaMediaF dlg;
	if (dlg.DoModal() != IDOK)
		return;

	if (dlg.m_iSize % 2 == 0 || dlg.m_iSize == 1)
	{
		AfxMessageBox(L"ģ��ߴ�ӦΪ����1��������");
		return;
	}

	if (dlg.m_iMove >= dlg.m_iSize - 1)
	{
		AfxMessageBox(L"ƽ�ƾ�����󣬺͵�ǰģ���С����ƥ�䣡");
		return;
	}

	int nFilterH = dlg.m_iSize;				// �˲����ĸ߶�
	int nFilterW = dlg.m_iSize;				// �˲����Ŀ��
	int nFilterMX = dlg.m_iMove;			// ����Ԫ�ص�X����
	int nFilterMY = dlg.m_iMove;			// ����Ԫ�ص�Y����

	imgInput.MedianFilter(&imgOutput, nFilterH, nFilterW,
		nFilterMY, nFilterMX);				// ����MedianFilter()������ֵ�˲�
	pDoc->m_Image = imgOutput;				// ��������ظ��ĵ���
	pDoc->SetModifiedFlag(TRUE);			// �����޸ı�ʶ
	pDoc->UpdateAllViews(NULL);				// ������ͼ
	EndWaitCursor();						// �ָ����
}

void CDIPView::OnEnhaLPF1()
{
	// �����ֵ�˲�
	CDIPDoc* pDoc = GetDocument();			// ��ȡ�ĵ�
	CImgProcess imgInput = pDoc->m_Image;	// �������
	if (imgInput.m_pBMIH->biBitCount != 8)	// ���ͼ���ǻҶ�ͼ
	{
		AfxMessageBox(L"����8-bpp�Ҷ�ͼ���޷�����");
		return;
	}
	
	BeginWaitCursor();						// ���Ĺ����״
	CImgProcess imgOutput = imgInput;		// �������ʱ����

	CDlgEnhaLpf1 dlg;
	if (dlg.DoModal() != IDOK)
		return;

	if (dlg.m_iSize % 2 == 0 || dlg.m_iSize == 1)
	{
		AfxMessageBox(L"ģ��ߴ�ӦΪ����1��������");
		return;
	}

	if (dlg.m_iMove >= dlg.m_iSize - 1)
	{
		AfxMessageBox(L"ƽ�ƾ�����󣬺͵�ǰģ���С����ƥ�䣡");
		return;
	}

	int nFilterH = dlg.m_iSize;				// �˲����ĸ߶�
	int nFilterW = dlg.m_iSize;				// �˲����Ŀ��
	int nFilterMX = dlg.m_iMove;			// ����Ԫ�ص�X����
	int nFilterMY = dlg.m_iMove;			// ����Ԫ�ص�Y����

	imgInput.LowFilter1(&imgOutput, nFilterH, nFilterW,
		nFilterMY, nFilterMX);				// ����LowFilter1()�����˲�
	pDoc->m_Image = imgOutput;				// ��������ظ��ĵ���
	pDoc->SetModifiedFlag(TRUE);			// �����޸ı�ʶ
	pDoc->UpdateAllViews(NULL);				// ������ͼ
	EndWaitCursor();						// �ָ����
}

void CDIPView::OnEnhaLPF2()
{
	// �򵥼�Ȩƽ����
	CDIPDoc* pDoc = GetDocument();			// ��ȡ�ĵ�
	CImgProcess imgInput = pDoc->m_Image;	// �������
	if (imgInput.m_pBMIH->biBitCount != 8)	// ���ͼ���ǻҶ�ͼ
	{
		AfxMessageBox(L"����8-bpp�Ҷ�ͼ���޷�����");
		return;
	}
	CDlgEnhaLpf2 dlg;
	if (dlg.DoModal() != IDOK)
		return;

	if (dlg.m_iSize != 3)
	{
		AfxMessageBox(L"��ǰ������˳ߴ�Ϊ3��ģ�壡");
		return;
	}

	if (dlg.m_iMove >= dlg.m_iSize - 1)
	{
		AfxMessageBox(L"ƽ�ƾ�����󣬺͵�ǰģ���С����ƥ�䣡");
		return;
	}

	int nFilterH = dlg.m_iSize;				// �˲����ĸ߶�
	int nFilterW = dlg.m_iSize;				// �˲����Ŀ��
	int nFilterMX = dlg.m_iMove;			// ����Ԫ�ص�X����
	int nFilterMY = dlg.m_iMove;			// ����Ԫ�ص�Y����

	BeginWaitCursor();						// ���Ĺ����״
	CImgProcess imgOutput = imgInput;		// �������ʱ����

	imgInput.LowFilter2(&imgOutput, nFilterH, nFilterW,
		nFilterMY, nFilterMX);				// ����LowFilter2()�����˲�
	pDoc->m_Image = imgOutput;				// ��������ظ��ĵ���
	pDoc->SetModifiedFlag(TRUE);			// �����޸ı�ʶ
	pDoc->UpdateAllViews(NULL);				// ������ͼ
	EndWaitCursor();						// �ָ����
}

void CDIPView::OnEnhaLPF3()
{
	// �ݶȵ�����Ȩƽ����
	CDIPDoc* pDoc = GetDocument();			// ��ȡ�ĵ�
	CImgProcess imgInput = pDoc->m_Image;	// �������
	if (imgInput.m_pBMIH->biBitCount != 8)	// ���ͼ���ǻҶ�ͼ
	{
		AfxMessageBox(L"����8-bpp�Ҷ�ͼ���޷�����");
		return;
	}

	BeginWaitCursor();						// ���Ĺ����״
	CImgProcess imgOutput = imgInput;		// �������ʱ����
	
	CDlgEnhaLpf3 dlg;
	if (dlg.DoModal() != IDOK)
		return;

	if (dlg.m_iSize % 2 == 0 || dlg.m_iSize == 1)
	{
		AfxMessageBox(L"ģ��ߴ�ӦΪ����1��������");
		return;
	}

	int nFilterH = dlg.m_iSize;				// �˲����ĸ߶�
	int nFilterW = dlg.m_iSize;				// �˲����Ŀ��
	int nFilterMX = dlg.m_iMove;			// ����Ԫ�ص�X����
	int nFilterMY = dlg.m_iMove;			// ����Ԫ�ص�Y����

	if (dlg.m_iSize % 2 == 0 || dlg.m_iSize == 1)
	{
		AfxMessageBox(L"ģ��ߴ�ӦΪ����1��������");
		return;
	}

	if (dlg.m_iMove >= dlg.m_iSize - 1)
	{
		AfxMessageBox(L"ƽ�ƾ�����󣬺͵�ǰģ���С����ƥ�䣡");
		return;
	}

	imgInput.LowFilter3(&imgOutput, nFilterH, nFilterW,
		nFilterMY, nFilterMX);				// ����LowFilter3()�����˲�
	pDoc->m_Image = imgOutput;				// ��������ظ��ĵ���
	pDoc->SetModifiedFlag(TRUE);			// �����޸ı�ʶ
	pDoc->UpdateAllViews(NULL);				// ������ͼ
	EndWaitCursor();						// �ָ����
}

void CDIPView::OnEnhaLPF4()
{
	// ���������ֵ�˲�
	CDIPDoc* pDoc = GetDocument();		// ��ȡ�ĵ�
	CImgProcess imgInput = pDoc->m_Image;	// �������
	if (imgInput.m_pBMIH->biBitCount != 8)	// ���ͼ���ǻҶ�ͼ
	{
		AfxMessageBox(L"����8-bpp�Ҷ�ͼ���޷�����");
		return;
	}

	BeginWaitCursor();						// ���Ĺ����״
	CImgProcess imgOutput = imgInput;		// �������ʱ����

	CDlgEnhaLpf4 dlg;
	if (dlg.DoModal() != IDOK)
		return;

	if (dlg.m_iSize % 2 == 0 || dlg.m_iSize == 1)
	{
		AfxMessageBox(L"ģ��ߴ�ӦΪ����1��������");
		return;
	}

	if (dlg.m_iMove >= dlg.m_iSize - 1)
	{
		AfxMessageBox(L"ƽ�ƾ�����󣬺͵�ǰģ���С����ƥ�䣡");
		return;
	}

	int nFilterH = dlg.m_iSize;				// �˲����ĸ߶�
	int nFilterW = dlg.m_iSize;				// �˲����Ŀ��
	int nFilterMX = dlg.m_iMove;			// ����Ԫ�ص�X����
	int nFilterMY = dlg.m_iMove;			// ����Ԫ�ص�Y����
	int nThreshold = dlg.m_iThreshold;		// �ҶȲ�ֵ

	imgInput.LowFilter4(&imgOutput, nFilterH, nFilterW,
		nFilterMY, nFilterMX, nThreshold);	// ����LowFilter4()�����˲�
	pDoc->m_Image = imgOutput;				// ��������ظ��ĵ���
	pDoc->SetModifiedFlag(TRUE);			// �����޸ı�ʶ
	pDoc->UpdateAllViews(NULL);				// ������ͼ
	EndWaitCursor();						// �ָ����
}

void CDIPView::OnEnhaLPF5()
{
	// �������޷�
	CDIPDoc* pDoc = GetDocument();			// ��ȡ�ĵ�
	CImgProcess imgInput = pDoc->m_Image;	// �������
	if (imgInput.m_pBMIH->biBitCount != 8)	// ���ͼ���ǻҶ�ͼ
	{
		AfxMessageBox(L"����8-bpp�Ҷ�ͼ���޷�����");
		return;
	}
	CDlgEnhaLpf5 dlg;
	if (dlg.DoModal() != IDOK)
		return;

	int nFilterH = dlg.m_iSize;				// �˲����ĸ߶�
	int nFilterW = dlg.m_iSize;				// �˲����Ŀ��
	int nFilterMX = dlg.m_iMove;			// ����Ԫ�ص�X����
	int nFilterMY = dlg.m_iMove;			// ����Ԫ�ص�Y����
	int nThreshold = dlg.m_iThreshold;		// �ҶȲ�ֵ
	int nCnt = dlg.m_iCnt;					// �������ֵ

	if (dlg.m_iSize % 2 == 0 || dlg.m_iSize == 1)
	{
		AfxMessageBox(L"ģ��ߴ�ӦΪ����1��������");
		return;
	}

	if (dlg.m_iMove >= dlg.m_iSize - 1)
	{
		AfxMessageBox(L"ƽ�ƾ�����󣬺͵�ǰģ���С����ƥ�䣡");
		return;
	}

	if(nCnt > (dlg.m_iSize * dlg.m_iSize + 1) / 2)
	{
		AfxMessageBox(L"�������������ֵ����ģ��ֵ��һ�룡");
		return;
	}

	BeginWaitCursor();						// ���Ĺ����״
	CImgProcess imgOutput = imgInput;		// �������ʱ����

	imgInput.LowFilter5(&imgOutput, nFilterH, nFilterW, nFilterMY, nFilterMX, 
		nThreshold, nCnt);					// ����LowFilter5()�����˲�
	pDoc->m_Image = imgOutput;				// ��������ظ��ĵ���
	pDoc->SetModifiedFlag(TRUE);			// �����޸ı�ʶ
	pDoc->UpdateAllViews(NULL);				// ������ͼ
	EndWaitCursor();						// �ָ����
}

void CDIPView::OnEnhaLPF6()
{
	// ���ξ�ֵ�˲���
	CDIPDoc* pDoc = GetDocument();			// ��ȡ�ĵ�
	CImgProcess imgInput = pDoc->m_Image;	// �������
	if (imgInput.m_pBMIH->biBitCount != 8)	// ���ͼ���ǻҶ�ͼ
	{
		AfxMessageBox(L"����8-bpp�Ҷ�ͼ���޷�����");
		return;
	}

	CDlgEnhaLpf6 dlg;
	if (dlg.DoModal() != IDOK)
		return;
	
	if (dlg.m_iSize % 2 == 0 || dlg.m_iSize == 1)
	{
		AfxMessageBox(L"ģ��ߴ�ӦΪ����1��������");
		return;
	}

	if (dlg.m_iMove >= dlg.m_iSize - 1)
	{
		AfxMessageBox(L"ƽ�ƾ�����󣬺͵�ǰģ���С����ƥ�䣡");
		return;
	}

	int nFilterH = dlg.m_iSize;				// �˲����ĸ߶�
	int nFilterW = dlg.m_iSize;				// �˲����Ŀ��
	int nFilterMX = dlg.m_iMove;			// ����Ԫ�ص�X����
	int nFilterMY = dlg.m_iMove;			// ����Ԫ�ص�Y����

	BeginWaitCursor();						// ���Ĺ����״
	CImgProcess imgOutput = imgInput;		// �������ʱ����

	imgInput.LowFilter6(&imgOutput, nFilterH, nFilterW,
		nFilterMY, nFilterMX);				// ����LowFilter6()�������ξ�ֵ�˲�
	pDoc->m_Image = imgOutput;				// ��������ظ��ĵ���
	pDoc->SetModifiedFlag(TRUE);			// �����޸ı�ʶ
	pDoc->UpdateAllViews(NULL);				// ������ͼ
	EndWaitCursor();						// �ָ����
}

void CDIPView::OnEnhaLPF7()
{
	// г����ֵ�˲���
	CDIPDoc* pDoc = GetDocument();			// ��ȡ�ĵ�
	CImgProcess imgInput = pDoc->m_Image;	// �������
	if (imgInput.m_pBMIH->biBitCount != 8)	// ���ͼ���ǻҶ�ͼ
	{
		AfxMessageBox(L"����8-bpp�Ҷ�ͼ���޷�����");
		return;
	}
	
	CDlgEnhaLpf7 dlg;
	if (dlg.DoModal() != IDOK)
		return;

	if (dlg.m_iSize % 2 == 0 || dlg.m_iSize == 1)
	{
		AfxMessageBox(L"ģ��ߴ�ӦΪ����1��������");
		return;
	}

	if (dlg.m_iMove >= dlg.m_iSize - 1)
	{
		AfxMessageBox(L"ƽ�ƾ�����󣬺͵�ǰģ���С����ƥ�䣡");
		return;
	}

	int nFilterH = dlg.m_iSize;				// �˲����ĸ߶�
	int nFilterW = dlg.m_iSize;				// �˲����Ŀ��
	int nFilterMX = dlg.m_iMove;			// ����Ԫ�ص�X����
	int nFilterMY = dlg.m_iMove;			// ����Ԫ�ص�Y����

	BeginWaitCursor();						// ���Ĺ����״
	CImgProcess imgOutput = imgInput;		// �������ʱ����

	imgInput.LowFilter7(&imgOutput, nFilterH, nFilterW,
		nFilterMY, nFilterMX);				// ����LowFilter7()����г����ֵ�˲�
	pDoc->m_Image = imgOutput;				// ��������ظ��ĵ���
	pDoc->SetModifiedFlag(TRUE);			// �����޸ı�ʶ
	pDoc->UpdateAllViews(NULL);				// ������ͼ
	EndWaitCursor();						// �ָ����
}

void CDIPView::OnEnhaLPF8()
{
	// ��г����ֵ�˲���
	CDIPDoc* pDoc = GetDocument();			// ��ȡ�ĵ�
	CImgProcess imgInput = pDoc->m_Image;	// �������
	if (imgInput.m_pBMIH->biBitCount != 8)	// ���ͼ���ǻҶ�ͼ
	{
		AfxMessageBox(L"����8-bpp�Ҷ�ͼ���޷�����");
		return;
	}

	BeginWaitCursor();						// ���Ĺ����״
	CImgProcess imgOutput = imgInput;		// �������ʱ����

	CDlgFreqInvHarmonicF dlg;
	if (dlg.DoModal() != IDOK)
		return;

	if (dlg.m_iSize % 2 == 0 || dlg.m_iSize == 1)
	{
		AfxMessageBox(L"ģ��ߴ�ӦΪ����1��������");
		return;
	}

	if (dlg.m_iMove >= dlg.m_iSize - 1)
	{
		AfxMessageBox(L"ƽ�ƾ�����󣬺͵�ǰģ���С����ƥ�䣡");
		return;
	}

	int nFilterH = dlg.m_iSize;				// �˲����ĸ߶�
	int nFilterW = dlg.m_iSize;				// �˲����Ŀ��
	int nFilterMX = dlg.m_iMove;			// ����Ԫ�ص�X����
	int nFilterMY = dlg.m_iMove;			// ����Ԫ�ص�Y����

	imgInput.LowFilter8(&imgOutput, nFilterH, nFilterW,
		nFilterMY, nFilterMX, dlg.m_iLevel);// ����LowFilter8()������г����ֵ�˲�
	pDoc->m_Image = imgOutput;				// ��������ظ��ĵ���
	pDoc->SetModifiedFlag(TRUE);			// �����޸ı�ʶ
	pDoc->UpdateAllViews(NULL);				// ������ͼ
	EndWaitCursor();						// �ָ����
}

void CDIPView::OnEnhaLPF9()
{
	// ������������ֵ�˲���
	CDIPDoc* pDoc = GetDocument();			// ��ȡ�ĵ�
	CImgProcess imgInput = pDoc->m_Image;	// �������
	if (imgInput.m_pBMIH->biBitCount != 8)	// ���ͼ���ǻҶ�ͼ
	{
		AfxMessageBox(L"����8-bpp�Ҷ�ͼ���޷�����");
		return;
	}

	CDlgFreqAlphaMeanF dlg;
	if (dlg.DoModal() != IDOK)
		return;
	
	if (dlg.m_iSize % 2 == 0 || dlg.m_iSize == 1)
	{
		AfxMessageBox(L"ģ��ߴ�ӦΪ����1��������");
		return;
	}

	int iDotCount = (dlg.m_iSize * dlg.m_iSize + 1) / 2;
	
	if(dlg.m_iDotCount >= iDotCount)
	{
		AfxMessageBox(L"ɾȥ�������࣬ӦС��ģ��ֵ��һ�룡");
		return;
	}
	
	if (dlg.m_iMove >= dlg.m_iSize - 1)
	{
		AfxMessageBox(L"ƽ�ƾ�����󣬺͵�ǰģ���С����ƥ�䣡");
		return;
	}

	int nFilterH = dlg.m_iSize;				// �˲����ĸ߶�
	int nFilterW = dlg.m_iSize;				// �˲����Ŀ��
	int nFilterMX = dlg.m_iMove;			// ����Ԫ�ص�X����
	int nFilterMY = dlg.m_iMove;			// ����Ԫ�ص�Y����

	BeginWaitCursor();						// ���Ĺ����״
	CImgProcess imgOutput = imgInput;		// �������ʱ����

	imgInput.LowFilter9(&imgOutput, nFilterH, nFilterW, nFilterMY, 
		nFilterMX , dlg.m_iDotCount);		// ����LowFilter9()����������������ֵ�˲�
	pDoc->m_Image = imgOutput;				// ��������ظ��ĵ���
	pDoc->SetModifiedFlag(TRUE);			// �����޸ı�ʶ
	pDoc->UpdateAllViews(NULL);				// ������ͼ
	EndWaitCursor();						// �ָ����
}

void CDIPView::OnEnhaMidF()
{
	// �е��˲�
	CDIPDoc* pDoc = GetDocument();			// ��ȡ�ĵ�
	CImgProcess imgInput = pDoc->m_Image;	// �������
	if (imgInput.m_pBMIH->biBitCount != 8)	// ���ͼ���ǻҶ�ͼ
	{
		AfxMessageBox(L"����8-bpp�Ҷ�ͼ���޷�����");
		return;
	}

	CDlgEnhaMidF dlg;
	if (dlg.DoModal() != IDOK)
		return;

	if (dlg.m_iSize % 2 == 0 || dlg.m_iSize == 1)
	{
		AfxMessageBox(L"ģ��ߴ�ӦΪ����1��������");
		return;
	}

	if (dlg.m_iMove >= dlg.m_iSize - 1)
	{
		AfxMessageBox(L"ƽ�ƾ�����󣬺͵�ǰģ���С����ƥ�䣡");
		return;
	}

	int nFilterH = dlg.m_iSize;				// �˲����ĸ߶�
	int nFilterW = dlg.m_iSize;				// �˲����Ŀ��
	int nFilterMX = dlg.m_iMove;			// ����Ԫ�ص�X����
	int nFilterMY = dlg.m_iMove;			// ����Ԫ�ص�Y����

	BeginWaitCursor();						// ���Ĺ����״
	CImgProcess imgOutput = imgInput;		// �������ʱ����

	imgInput.MidFilter(&imgOutput, nFilterH, nFilterW,
		nFilterMY, nFilterMX);				// ����MedianFilter()�����е��˲�
	pDoc->m_Image = imgOutput;				// ��������ظ��ĵ���
	pDoc->SetModifiedFlag(TRUE);			// �����޸ı�ʶ
	pDoc->UpdateAllViews(NULL);				// ������ͼ
	EndWaitCursor();						// �ָ����
}

void CDIPView::OnEnhaHPF1()
{
	// ������ͨ�˲�
	CDIPDoc* pDoc = GetDocument();		// ��ȡ�ĵ�
	CImgProcess imgInput = pDoc->m_Image;	// �������
	if (imgInput.m_pBMIH->biBitCount != 8)	// ���ͼ���ǻҶ�ͼ
	{
		AfxMessageBox(L"����8-bpp�Ҷ�ͼ���޷�����");
		return;
	}

	CDlgEnhaHpf1 dlg;
	if (dlg.DoModal() != IDOK)
		return;

	if (dlg.m_iSize != 3 || dlg.m_iSize != 5)
	{
		AfxMessageBox(L"��ǰ������˳ߴ�Ϊ3��5��ģ�壡");
		return;
	}

	if (dlg.m_iMove >= dlg.m_iSize - 1)
	{
		AfxMessageBox(L"ƽ�ƾ�����󣬺͵�ǰģ���С����ƥ�䣡");
		return;
	}

	int nFilterH = dlg.m_iSize;				// �˲����ĸ߶�
	int nFilterW = dlg.m_iSize;				// �˲����Ŀ��
	int nFilterMX = dlg.m_iMove;			// ����Ԫ�ص�X����
	int nFilterMY = dlg.m_iMove;			// ����Ԫ�ص�Y����

	BeginWaitCursor();						// ���Ĺ����״
	CImgProcess imgOutput = imgInput;		// �������ʱ����

	imgInput.HighFilter1(&imgOutput, nFilterH, nFilterW,
		nFilterMY, nFilterMX);				// ����MedianFilter()������ֵ�˲�
	pDoc->m_Image = imgOutput;				// ��������ظ��ĵ���
	pDoc->SetModifiedFlag(TRUE);			// �����޸ı�ʶ
	pDoc->UpdateAllViews(NULL);				// ������ͼ
	EndWaitCursor();						// �ָ����
}

void CDIPView::OnEnhaHPF2()
{
	// �������˲�
	CDIPDoc* pDoc = GetDocument();		// ��ȡ�ĵ�
	CImgProcess imgInput = pDoc->m_Image;	// �������

	if (imgInput.m_pBMIH->biBitCount != 8)	// ���ͼ���ǻҶ�ͼ
	{
		AfxMessageBox(L"����8-bpp�Ҷ�ͼ���޷�����");
		return;
	}

	CDlgEnhaHpf2 dlg;
	if (dlg.DoModal() != IDOK)
		return;

	if (dlg.m_iSize != 3 || dlg.m_iSize != 5)
	{
		AfxMessageBox(L"��ǰ������˳ߴ�Ϊ3��5��ģ�壡");
		return;
	}
	

	if (dlg.m_iMove >= dlg.m_iSize - 1)
	{
		AfxMessageBox(L"ƽ�ƾ�����󣬺͵�ǰģ���С����ƥ�䣡");
		return;
	}

	int nFilterH = dlg.m_iSize;				// �˲����ĸ߶�
	int nFilterW = dlg.m_iSize;				// �˲����Ŀ��
	int nFilterMX = dlg.m_iMove;			// ����Ԫ�ص�X����
	int nFilterMY = dlg.m_iMove;			// ����Ԫ�ص�Y����

	if(dlg.m_dGain < 1)
	{
		AfxMessageBox(L"ϵ��ֵӦ����1");
		return;
	}

	BeginWaitCursor();						// ���Ĺ����״
	CImgProcess imgOutput = imgInput;		// �������ʱ����

	imgInput.HighFilter2(&imgOutput, nFilterH, nFilterW, nFilterMY, 
		nFilterMX, dlg.m_dGain);			// ����MedianFilter()������ֵ�˲�
	pDoc->m_Image = imgOutput;				// ��������ظ��ĵ���
	pDoc->SetModifiedFlag(TRUE);			// �����޸ı�ʶ
	pDoc->UpdateAllViews(NULL);				// ������ͼ
	EndWaitCursor();						// �ָ����
}

void CDIPView::OnENHAAdaptMidianF()
{
	// ����Ӧ��ֵ�˲�
	CDIPDoc* pDoc = GetDocument();		// ��ȡ�ĵ�
	CImgProcess imgInput = pDoc->m_Image;	// �������
	if (imgInput.m_pBMIH->biBitCount != 8)	// ���ͼ���ǻҶ�ͼ
	{
		AfxMessageBox(L"����8-bpp�Ҷ�ͼ���޷�����");
		return;
	}

	CDlgEnhaAdapativeMediaF dlg;
	if (dlg.DoModal() != IDOK)
		return;

	int nFilterH = dlg.m_iSize;				// �˲����ĸ߶�
	int nFilterW = dlg.m_iSize;				// �˲����Ŀ��
	int nFilterMX = dlg.m_iMove;			// ����Ԫ�ص�X����
	int nFilterMY = dlg.m_iMove;			// ����Ԫ�ص�Y����

	if (dlg.m_iSize % 2 == 0 || dlg.m_iSize == 1)
	{
		AfxMessageBox(L"ģ��ߴ�ӦΪ����1��������");
		return;
	}

	if (dlg.m_iMove >= dlg.m_iSize - 1)
	{
		AfxMessageBox(L"ƽ�ƾ�����󣬺͵�ǰģ���С����ƥ�䣡");
		return;
	}

	BeginWaitCursor();						// ���Ĺ����״
	CImgProcess imgOutput = imgInput;		// �������ʱ����
	imgInput.AdaptiveMedianFilter(&imgOutput, nFilterH, nFilterW,
		nFilterMX, nFilterMY);				// ����AdaptiveMedianFilter()��������Ӧ��ֵ�˲�
	pDoc->m_Image = imgOutput;				// ��������ظ��ĵ���
	pDoc->SetModifiedFlag(TRUE);			// �����޸ı�ʶ
	pDoc->UpdateAllViews(NULL);				// ������ͼ
	EndWaitCursor();						// �ָ����
}

void CDIPView::OnEnhaGaussianF()
{
	CDIPDoc* pDoc = GetDocument();		// ��ȡ�ĵ�
	CImgProcess imgInput = pDoc->m_Image;	// �������
	if (imgInput.m_pBMIH->biBitCount != 8)	// ���ͼ���ǻҶ�ͼ
	{
		AfxMessageBox(L"����8-bpp�Ҷ�ͼ���޷�����");
		return;
	}

	CDlgEnhaGaussianF dlg;
	if (dlg.DoModal() != IDOK)
		return;

	if (dlg.m_iSize != 3)
	{
		AfxMessageBox(L"��ǰֻ��Ƴ��ߴ�Ϊ3��ģ�壡");
		return;
	}

	if (dlg.m_iMove >= dlg.m_iSize - 1)
	{
		AfxMessageBox(L"ƽ�ƾ�����󣬺͵�ǰģ���С����ƥ�䣡");
		return;
	}

	int nFilterH = dlg.m_iSize;				// �˲����ĸ߶�
	int nFilterW = dlg.m_iSize;				// �˲����Ŀ��
	int nFilterMX = dlg.m_iMove;			// ����Ԫ�ص�X����
	int nFilterMY = dlg.m_iMove;			// ����Ԫ�ص�Y����

	BeginWaitCursor();						// ���Ĺ����״
	CImgProcess imgOutput = imgInput;		// �������ʱ����

	imgInput.EnhaGaussianF(&imgOutput, nFilterH, nFilterW,
		nFilterMY, nFilterMX);				// ����EnhaGaussianF()������ֵ�˲�
	pDoc->m_Image = imgOutput;				// ��������ظ��ĵ���
	pDoc->SetModifiedFlag(TRUE);			// �����޸ı�ʶ
	pDoc->UpdateAllViews(NULL);				// ������ͼ
	EndWaitCursor();						// �ָ����
}

void CDIPView::OnEnhaAdapativeSmooth()
{
	CDIPDoc* pDoc = GetDocument();		// ��ȡ�ĵ�
	CImgProcess imgInput = pDoc->m_Image;	// �������
	if (imgInput.m_pBMIH->biBitCount != 8)	// ���ͼ���ǻҶ�ͼ
	{
		AfxMessageBox(L"����8-bpp�Ҷ�ͼ���޷�����");
		return;
	}

	CDlgEnhaAdapativeSmooth dlg;
	if (dlg.DoModal() != IDOK)
		return;

	if (dlg.m_iSize != 3)
	{
		AfxMessageBox(L"��ǰֻ��Ƴ��ߴ�Ϊ3��ģ�壡");
		return;
	}

	if (dlg.m_iMove >= dlg.m_iSize - 1)
	{
		AfxMessageBox(L"ƽ�ƾ�����󣬺͵�ǰģ���С����ƥ�䣡");
		return;
	}

	int nFilterH = dlg.m_iSize;				// �˲����ĸ߶�
	int nFilterW = dlg.m_iSize;				// �˲����Ŀ��
	int nFilterMX = dlg.m_iMove;			// ����Ԫ�ص�X����
	int nFilterMY = dlg.m_iMove;			// ����Ԫ�ص�Y����

	BeginWaitCursor();						// ���Ĺ����״
	CImgProcess imgOutput = imgInput;		// �������ʱ����

	imgInput.EnhaAdaptiveSmooth(&imgOutput, nFilterH, nFilterW,
		nFilterMY, nFilterMX);				// ����EnhaAdaptiveSmooth()������ֵ�˲�
	pDoc->m_Image = imgOutput;				// ��������ظ��ĵ���
	pDoc->SetModifiedFlag(TRUE);			// �����޸ı�ʶ
	pDoc->UpdateAllViews(NULL);				// ������ͼ
	EndWaitCursor();						// �ָ����
}

void CDIPView::OnEnhaGradsharp()
{
	// Sobel�ݶ���
	CDIPDoc* pDoc = GetDocument();		// ��ȡ�ĵ�
	CImgProcess imgInput = pDoc->m_Image;	// �������
	if (imgInput.m_pBMIH->biBitCount != 8)	// ���ͼ���ǻҶ�ͼ
	{
		AfxMessageBox(L"����8-bpp�Ҷ�ͼ���޷�����");
		return;
	}
	BeginWaitCursor();						// ���Ĺ����״
	CImgProcess imgOutput = imgInput;		// �������ʱ����
	imgInput.FilterSobel(&imgOutput);		// ����FilterSobel()��������Sobel�ݶ���
	pDoc->m_Image = imgOutput;				// ��������ظ��ĵ���
	pDoc->SetModifiedFlag(TRUE);			// �����޸ı�ʶ
	pDoc->UpdateAllViews(NULL);				// ������ͼ
	EndWaitCursor();						// �ָ����
}

void CDIPView::OnEnhaMaxF()
{
	// ���ֵ�˲�
	CDIPDoc* pDoc = GetDocument();		// ��ȡ�ĵ�
	CImgProcess imgInput = pDoc->m_Image;	// �������
	if (imgInput.m_pBMIH->biBitCount != 8)	// ���ͼ���ǻҶ�ͼ
	{
		AfxMessageBox(L"����8-bpp�Ҷ�ͼ���޷�����");
		return;
	}

	CDlgEnhaMaxF dlg;
	if (dlg.DoModal() != IDOK)
		return;

	if (dlg.m_iSize % 2 == 0 || dlg.m_iSize == 1)
	{
		AfxMessageBox(L"ģ��ߴ�ӦΪ����1��������");
		return;
	}

	if (dlg.m_iMove >= dlg.m_iSize - 1)
	{
		AfxMessageBox(L"ƽ�ƾ�����󣬺͵�ǰģ���С����ƥ�䣡");
		return;
	}

	int nFilterH = dlg.m_iSize;				// �˲����ĸ߶�
	int nFilterW = dlg.m_iSize;				// �˲����Ŀ��
	int nFilterMX = dlg.m_iMove;			// ����Ԫ�ص�X����
	int nFilterMY = dlg.m_iMove;			// ����Ԫ�ص�Y����
	
	BeginWaitCursor();						// ���Ĺ����״
	CImgProcess imgOutput = imgInput;		// �������ʱ����

	imgInput.MaxFilter(&imgOutput, nFilterH, nFilterW, 
		nFilterMY, nFilterMX);				// ����MaxFilter()�������ֵ�˲�
	pDoc->m_Image = imgOutput;				// ��������ظ��ĵ���
	pDoc->SetModifiedFlag(TRUE);			// �����޸ı�ʶ
	pDoc->UpdateAllViews(NULL);				// ������ͼ
	EndWaitCursor();						// �ָ����
}

void CDIPView::OnEnhaMinF()
{
	// ��Сֵ�˲�
	CDIPDoc* pDoc = GetDocument();		// ��ȡ�ĵ�
	CImgProcess imgInput = pDoc->m_Image;	// �������
	if (imgInput.m_pBMIH->biBitCount != 8)	// ���ͼ���ǻҶ�ͼ
	{
		AfxMessageBox(L"����8-bpp�Ҷ�ͼ���޷�����");
		return;
	}

	CDlgEnhaMinF dlg;
	if (dlg.DoModal() != IDOK)
		return;

	if (dlg.m_iSize % 2 == 0 || dlg.m_iSize == 1)
	{
		AfxMessageBox(L"ģ��ߴ�ӦΪ����1��������");
		return;
	}

	if (dlg.m_iMove >= dlg.m_iSize - 1)
	{
		AfxMessageBox(L"ƽ�ƾ�����󣬺͵�ǰģ���С����ƥ�䣡");
		return;
	}

	int nFilterH = dlg.m_iSize;				// �˲����ĸ߶�
	int nFilterW = dlg.m_iSize;				// �˲����Ŀ��
	int nFilterMX = dlg.m_iMove;			// ����Ԫ�ص�X����
	int nFilterMY = dlg.m_iMove;			// ����Ԫ�ص�Y����
	
	BeginWaitCursor();						// ���Ĺ����״
	CImgProcess imgOutput = imgInput;		// �������ʱ����

	imgInput.MinFilter(&imgOutput, nFilterH, nFilterW,
		nFilterMY, nFilterMX);				// ����MinFilter()������С�˲�
	pDoc->m_Image = imgOutput;				// ��������ظ��ĵ���
	pDoc->SetModifiedFlag(TRUE);			// �����޸ı�ʶ
	pDoc->UpdateAllViews(NULL);				// ������ͼ
	EndWaitCursor();						// �ָ����
}

void CDIPView::OnEnhaSharp()
{
	// ������˹��
	CDIPDoc* pDoc = GetDocument();				// ��ȡ�ĵ�
	CImgProcess imgInput = pDoc->m_Image;		// �������
	if (imgInput.m_pBMIH->biBitCount != 8)		// ���ͼ���ǻҶ�ͼ
	{
		AfxMessageBox(L"����8-bpp�Ҷ�ͼ���޷�����");
		return;
	}
	CImgProcess imgOutput = imgInput;			// �������ʱ����
	int nTempH;									// �˲����ĸ߶�
	int nTempW;									// �˲����Ŀ��
	int nTempMX;								// ����Ԫ�ص�X����
	int nTempMY;								// ����Ԫ�ص�Y����
	double   fCoef;								// ģ��ϵ��
	BeginWaitCursor();							// ���Ĺ����״
	nTempW = 3;									// ����������˹ģ�����
	nTempH = 3;
	fCoef = 1.0;
	nTempMX = 1;
	nTempMY = 1;

	imgInput.Template(&imgOutput, nTempH, nTempW, nTempMY, nTempMX,
		Template_Laplacian2, fCoef);			// ����Template()������������˹ģ����
	pDoc->m_Image = imgOutput;					// ��������ظ��ĵ���
	pDoc->SetModifiedFlag(TRUE);				// �����޸ı�ʶ
	pDoc->UpdateAllViews(NULL);					// ������ͼ
	EndWaitCursor();							// �ָ����
}

void CDIPView::OnEnhaHighenha()
{
	// ����3*3��Laplacianģ��ĸ������˲�
	CDIPDoc* pDoc = GetDocument();				// ��ȡ�ĵ�
	CImgProcess imgInput = pDoc->m_Image;		// �������
	if (imgInput.m_pBMIH->biBitCount != 8)		// ���ͼ���ǻҶ�ͼ
	{
		AfxMessageBox(L"����8-bpp�Ҷ�ͼ���޷�����");
		return;
	}

	CDlgEnhaEnhanceF dlg;
	if (dlg.DoModal() != IDOK)
		return;

	if (dlg.m_iSize != 3)
	{
		AfxMessageBox(L"��ǰ������˳ߴ�Ϊ3��ģ�壡");
		return;
	}

	if (dlg.m_iMove >= dlg.m_iSize - 1)
	{
		AfxMessageBox(L"ƽ�ƾ�����󣬺͵�ǰģ���С����ƥ�䣡");
		return;
	}

	int nFilterH = dlg.m_iSize;					// �˲����ĸ߶�
	int nFilterW = dlg.m_iSize;					// �˲����Ŀ��
	int nFilterMX = dlg.m_iMove;				// ����Ԫ�ص�X����
	int nFilterMY = dlg.m_iMove;				// ����Ԫ�ص�Y����
	double dGain = dlg.m_dGain;					// ��ز����趨

	BeginWaitCursor();							// ���Ĺ����״
	CImgProcess imgOutput = imgInput;			// �������ʱ����
	
	imgInput.EnhanceFilter(&imgOutput, dGain, nFilterH, nFilterW, nFilterMY, nFilterMX,
		Template_Laplacian2, 1);				// ����EnhanceFilter()�������и������˲�������3*3��Laplacianģ�壬���ϵ��Ϊ1.8
	pDoc->m_Image = imgOutput;					// ��������ظ��ĵ���
	pDoc->SetModifiedFlag(TRUE);				// �����޸ı�ʶ
	pDoc->UpdateAllViews(NULL);					// ������ͼ
	EndWaitCursor();							// �ָ����
}

/**********************************************/
// ͼ�������任
void CDIPView::OnFreqFour()
{
	CDIPDoc* pDoc = GetDocument();				// ���ٸ���Ҷ�任
	CImgProcess imgInput = pDoc->m_Image;		// �������
	if (imgInput.m_pBMIH->biBitCount != 8)		// ���ͼ���ǻҶ�ͼ
	{
		AfxMessageBox(L"����8-bpp�Ҷ�ͼ���޷�����");
		return;
	}
	BeginWaitCursor();
	CImgProcess imgOutput = imgInput;			// �������ʱ����
	imgInput.FFT2(&imgOutput, 1);				// ִ��FFT2
	pDoc->m_Image = imgOutput;					// ��������ظ��ĵ���
	pDoc->SetModifiedFlag(true);
	pDoc->UpdateAllViews(NULL);
	EndWaitCursor();							// �ָ����
}

void CDIPView::OnFreqIFour()
{
	CDIPDoc* pDoc = GetDocument();				// ���ٸ���Ҷ�任
	CImgProcess imgInput = pDoc->m_Image;		// �������

	if (imgInput.m_pBMIH->biBitCount != 8)		// ���ͼ���ǻҶ�ͼ
	{
		AfxMessageBox(L"����8-bpp�Ҷ�ͼ���޷�����");
		return;
	}

	BeginWaitCursor();
	CImgProcess imgOutput = imgInput;			// �������ʱ����
	
	imgInput.FFT2(&imgOutput, 1);				// ִ��FFT2
	pDoc->m_Image = imgOutput;					// ��������ظ��ĵ���
	pDoc->SetModifiedFlag(true);
	pDoc->UpdateAllViews(NULL);
	EndWaitCursor();							// �ָ����
}

void CDIPView::OnFreqDct()
{
	CDIPDoc* pDoc = GetDocument();				// ��ɢ���ұ任
	CImgProcess imgInput = pDoc->m_Image;		// �������
	if (imgInput.m_pBMIH->biBitCount != 8)		// ���ͼ���ǻҶ�ͼ
	{
		AfxMessageBox(L"����8-bpp�Ҷ�ͼ���޷�����");
		return;
	}
	BeginWaitCursor();
	CImgProcess imgOutput = imgInput;			// �������ʱ����
	imgInput.DCT(&imgOutput);					// ִ��DCT
	pDoc->m_Image = imgOutput;					// ��������ظ��ĵ���
	pDoc->SetModifiedFlag(true);
	pDoc->UpdateAllViews(NULL);
	EndWaitCursor();							// �ָ����
}

void CDIPView::OnFreqIdct()
{
	CDIPDoc* pDoc = GetDocument();				// ��ɢ���ҷ��任
	CImgProcess imgInput = pDoc->m_Image;		// �������
	if (imgInput.m_pBMIH->biBitCount != 8)		// ���ͼ���ǻҶ�ͼ
	{
		AfxMessageBox(L"����8-bpp�Ҷ�ͼ���޷�����");
		return;
	}
	BeginWaitCursor();
	CImgProcess imgOutput = imgInput;			// �������ʱ����
	imgInput.IDCT(&imgOutput);					// ִ��IDCT
	pDoc->m_Image = imgOutput;					// ��������ظ��ĵ���
	pDoc->SetModifiedFlag(true);
	pDoc->UpdateAllViews(NULL);
	EndWaitCursor();							// �ָ����
}

/**********************************************/
//  ��̬ѧ�任
void CDIPView::OnMorphErosion()
{
	// ��ʴ����
	CDIPDoc* pDoc = GetDocument();				// ��ȡ�ĵ�
	CImgProcess imgInput = pDoc->m_Image;		// ����ͼ��
	if (!imgInput.IsBinaryImg())				// ���ͼ���Ƕ�ֵͼ
	{
		AfxMessageBox(L"���Ƕ�ֵͼ���޷�����");
		return;
	}
	CDlgMorph dlgPara;							// �����Ի���
	if (dlgPara.DoModal() != IDOK)				// ��ʾ�Ի�����ʾ�û��趨�ṹԪ��
		return;									// ����
	int se[3][3];								// 3*3�ṹԪ��
	se[0][0] = dlgPara.m_se00;					//�����û������趨�ṹԪ��
	se[0][1] = dlgPara.m_se01;
	se[0][2] = dlgPara.m_se02;
	se[1][0] = dlgPara.m_se10;
	se[1][1] = dlgPara.m_se11;
	se[1][2] = dlgPara.m_se12;
	se[2][0] = dlgPara.m_se20;
	se[2][1] = dlgPara.m_se21;
	se[2][2] = dlgPara.m_se22;
	BeginWaitCursor();							// ���Ĺ����״
	CImgProcess imgOutput = imgInput;			// �������ʱ����
	imgInput.Erode(&imgOutput, se);				// ����Erode()ʵ��ͼ��ʴ
	pDoc->m_Image = imgOutput;					// ��������ظ��ĵ���
	pDoc->SetModifiedFlag(true);
	pDoc->UpdateAllViews(NULL);
	EndWaitCursor();							// �ָ����
}

void CDIPView::OnMorphOpen()
{
	// ������
	CDIPDoc* pDoc = GetDocument();				// ��ȡ�ĵ�
	CImgProcess imgInput = pDoc->m_Image;		// ����ͼ��
	if (!imgInput.IsBinaryImg())				// ���ͼ���Ƕ�ֵͼ
	{
		AfxMessageBox(L"���Ƕ�ֵͼ���޷�����");
		return;
	}
	CDlgMorph dlgPara;							// �����Ի���
	if (dlgPara.DoModal() != IDOK)				// ��ʾ�Ի�����ʾ�û��趨�ṹԪ��
		return;									// ����
	int se[3][3];								// 3*3�ṹԪ��
	//�����û������趨�ṹԪ��
	se[0][0] = dlgPara.m_se00;
	se[0][1] = dlgPara.m_se01;
	se[0][2] = dlgPara.m_se02;
	se[1][0] = dlgPara.m_se10;
	se[1][1] = dlgPara.m_se11;
	se[1][2] = dlgPara.m_se12;
	se[2][0] = dlgPara.m_se20;
	se[2][1] = dlgPara.m_se21;
	se[2][2] = dlgPara.m_se22;

	BeginWaitCursor();							// ���Ĺ����״
	CImgProcess imgOutput = imgInput;			// �������ʱ����
	imgInput.Open(&imgOutput, se);				// ����Open()ʵ��ͼ��ʴ
	pDoc->m_Image = imgOutput;					// ��������ظ��ĵ���
	pDoc->SetModifiedFlag(true);
	pDoc->UpdateAllViews(NULL);
	EndWaitCursor();							// �ָ����
}

void CDIPView::OnMorphTrace()
{
	// �߽����
	CDIPDoc* pDoc = GetDocument();				// ��ȡ�ĵ�
	CImgProcess imgInput = pDoc->m_Image;		// ����ͼ��
	if (!imgInput.IsBinaryImg())				// ���ͼ���Ƕ�ֵͼ
	{
		AfxMessageBox(L"���Ƕ�ֵͼ���޷�����");
		return;
	}
	BeginWaitCursor();							// ���Ĺ����״
	CImgProcess imgOutput = imgInput;			// �������ʱ����
	imgInput.TraceBoundary(&imgOutput);			// ����TraceBoundary()����ʵ�ֱ߽����
	pDoc->m_Image = imgOutput;					// ��������ظ��ĵ���
	pDoc->SetModifiedFlag(true);
	pDoc->UpdateAllViews(NULL);
	EndWaitCursor();							// �ָ����
}

void CDIPView::OnMorphFillrgn()
{
	// ������������
	CDIPDoc* pDoc = GetDocument();				// ��ȡ�ĵ�
	CImgProcess imgInput = pDoc->m_Image;		// ����ͼ��
	if (!imgInput.IsBinaryImg())				// ���ͼ���Ƕ�ֵͼ
	{
		AfxMessageBox(L"���Ƕ�ֵͼ���޷�����");
		return;
	}
	BeginWaitCursor();							// ���Ĺ����״
	CImgProcess imgOutput = imgInput;			// �������ʱ����
	// ��Ҫ����ʵ������������ӵ�����꣬����򵥵�ȡ���ӵ�Ϊͼ������ĵ�
	POINT ptStart;
	ptStart.x = imgInput.GetWidthPixel() / 2;
	ptStart.y = imgInput.GetHeight() / 2;
	imgInput.FillRgn(&imgOutput, ptStart);		// ����FillRgn()����ʵ���������
	//POINT�Ͳ���ptStartΪ���ӵ㣬�����������е�����һ��
	pDoc->m_Image = imgOutput;					// ��������ظ��ĵ���
	pDoc->SetModifiedFlag(true);
	pDoc->UpdateAllViews(NULL);
	EndWaitCursor();							// �ָ����
}

void CDIPView::OnMorphLabelconnrgn()
{
	// ��ע��ͨ����
	CDIPDoc* pDoc = GetDocument();				// ��ȡ�ĵ�
	CImgProcess imgInput = pDoc->m_Image;		// ����ͼ��
	if (!imgInput.IsBinaryImg())				// ���ͼ���Ƕ�ֵͼ
	{
		AfxMessageBox(L"���Ƕ�ֵͼ���޷�����");
		return;
	}
	BeginWaitCursor();							// ���Ĺ����״
	CImgProcess imgOutput = imgInput;			// �������ʱ����
	imgInput.LabelConnRgn(&imgOutput);			// ����LabelConnRgn()������ע��ͨ����
	pDoc->m_Image = imgOutput;					// ��������ظ��ĵ���
	pDoc->SetModifiedFlag(true);
	pDoc->UpdateAllViews(NULL);
	EndWaitCursor();							// �ָ����
}

void CDIPView::OnMorphThining()
{
	//ϸ��
	CDIPDoc* pDoc = GetDocument();				// ��ȡ�ĵ�
	CImgProcess imgInput = pDoc->m_Image;		// ����ͼ��
	if (!imgInput.IsBinaryImg())				// ���ͼ���Ƕ�ֵͼ
	{
		AfxMessageBox(L"���Ƕ�ֵͼ���޷�����");
		return;
	}
	BeginWaitCursor();							// ���Ĺ����״
	CImgProcess imgOutput = imgInput;			// �������ʱ����
	imgOutput.Thining();						// ����Thining()ʵ��ͼ��ϸ��
	pDoc->m_Image = imgOutput;					// ��������ظ��ĵ���
	pDoc->SetModifiedFlag(true);
	pDoc->UpdateAllViews(NULL);
	EndWaitCursor();							// �ָ����
}

void CDIPView::OnMorphPixel()
{
	// ���ػ�
	CDIPDoc* pDoc = GetDocument();				// ��ȡ�ĵ�
	CImgProcess imgInput = pDoc->m_Image;		// ����ͼ��
	if (!imgInput.IsBinaryImg())				// ���ͼ���Ƕ�ֵͼ
	{
		AfxMessageBox(L"���Ƕ�ֵͼ���޷�����");
		return;
	}
	int nLowThres;								// ��ͨ�����ڴ���ֵ����ͨ�����˳�
	int nHighThres;								// ��ͨ�����ڴ���ֵ����ͨ�����˳�
	BeginWaitCursor();							// ���Ĺ����״
	CImgProcess imgOutput = imgInput;			// �������ʱ����
	//�����趨����ֵΪ10������ֵΪ100,��ͨ��<10����ͨ��>300����ͨ�����˳���֮��ı����ػ�
	nLowThres = 10;
	nHighThres = 300;
	imgInput.PixelImage(&imgOutput, nLowThres,
		nHighThres);							// ����PixelImage()ʵ��ͼ��ϸ��
	pDoc->m_Image = imgOutput;					// ��������ظ��ĵ���
	pDoc->SetModifiedFlag(true);
	pDoc->UpdateAllViews(NULL);
	EndWaitCursor();							// �ָ����
}

void CDIPView::OnMorphConvex()
{
	// ͹��
	CDIPDoc* pDoc = GetDocument();				// ��ȡ�ĵ�
	CImgProcess imgInput = pDoc->m_Image;		// ����ͼ��
	if (!imgInput.IsBinaryImg())				// ���ͼ���Ƕ�ֵͼ
	{
		AfxMessageBox(L"���Ƕ�ֵͼ���޷�����");
		return;
	}
	BeginWaitCursor();							// ���Ĺ����״
	CImgProcess imgOutput = imgInput;			// �������ʱ����
	imgInput.Convex(&imgOutput, 1);				// ����Convex()��������͹��
	//��2������Ϊ1��ʾ��Ҫ����͹�ǵ�����
	pDoc->m_Image = imgOutput;					// ��������ظ��ĵ���
	pDoc->SetModifiedFlag(true);
	pDoc->UpdateAllViews(NULL);
	EndWaitCursor();							// �ָ����
}

void CDIPView::OnMorphClose()
{
	// ������
	CDIPDoc* pDoc = GetDocument();				// ��ȡ�ĵ�
	CImgProcess imgInput = pDoc->m_Image;		// ����ͼ��
	if (!imgInput.IsBinaryImg())
	{
		AfxMessageBox(L"���Ƕ�ֵͼ���޷�����");
		return;
	}
	CDlgMorph dlgPara;							// �����Ի���
	if (dlgPara.DoModal() != IDOK)				// ��ʾ�Ի�����ʾ�û��趨�ṹԪ��
		return;									// ����

	int se[3][3];								// 3*3�ṹԪ��
	//�����û������趨�ṹԪ��
	se[0][0] = dlgPara.m_se00;
	se[0][1] = dlgPara.m_se01;
	se[0][2] = dlgPara.m_se02;
	se[1][0] = dlgPara.m_se10;
	se[1][1] = dlgPara.m_se11;
	se[1][2] = dlgPara.m_se12;
	se[2][0] = dlgPara.m_se20;
	se[2][1] = dlgPara.m_se21;
	se[2][2] = dlgPara.m_se22;

	BeginWaitCursor();							// ���Ĺ����״
	CImgProcess imgOutput = imgInput;			// �������ʱ����
	imgInput.Close(&imgOutput, se);				// ����Close()ʵ��ͼ�������
	pDoc->m_Image = imgOutput;					// ��������ظ��ĵ���
	pDoc->SetModifiedFlag(true);
	pDoc->UpdateAllViews(NULL);

	EndWaitCursor();							// �ָ����
}

void CDIPView::OnMorphDilation()
{
	// ��������
	CDIPDoc* pDoc = GetDocument();				// ��ȡ�ĵ�
	CImgProcess imgInput = pDoc->m_Image;		// ����ͼ��
	if (!imgInput.IsBinaryImg())				// ���ͼ���Ƕ�ֵͼ
	{
		AfxMessageBox(L"���Ƕ�ֵͼ���޷�����");
		return;
	}
	CDlgMorph dlgPara;							// �����Ի���
	if (dlgPara.DoModal() != IDOK)				// ��ʾ�Ի�����ʾ�û��趨�ṹԪ��
		return;									// ����

	int se[3][3];								// 3*3�ṹԪ��
	//�����û������趨�ṹԪ��
	se[0][0] = dlgPara.m_se00;
	se[0][1] = dlgPara.m_se01;
	se[0][2] = dlgPara.m_se02;
	se[1][0] = dlgPara.m_se10;
	se[1][1] = dlgPara.m_se11;
	se[1][2] = dlgPara.m_se12;
	se[2][0] = dlgPara.m_se20;
	se[2][1] = dlgPara.m_se21;
	se[2][2] = dlgPara.m_se22;

	BeginWaitCursor();							// ���Ĺ����״

	CImgProcess imgOutput = imgInput;			// �������ʱ����

	imgInput.Dilate(&imgOutput, se);			//����Dilate()ʵ��ͼ������

	pDoc->m_Image = imgOutput;					// ��������ظ��ĵ���
	pDoc->SetModifiedFlag(true);
	pDoc->UpdateAllViews(NULL);

	EndWaitCursor();							// �ָ����
}

void CDIPView::OnMorphGraydilate()
{
	// �Ҷ�����
	CDIPDoc* pDoc = GetDocument();				// ��ȡ�ĵ�
	CImgProcess imgInput = pDoc->m_Image;		// ����ͼ��
	if (imgInput.m_pBMIH->biBitCount != 8)		// ���ͼ���ǻҶ�ͼ
	{
		AfxMessageBox(L"����8-bpp�Ҷ�ͼ���޷�����");
		return;
	}
	CDlgMorph dlgPara;							// �����Ի���
	if (dlgPara.DoModal() != IDOK)				// ��ʾ�Ի�����ʾ�û��趨�ṹԪ��
		return;									// ����

	int** se;									// �ṹԪ��
	se = new int*[3];

	for (int i = 0; i < 3; i++)
		se[i] = new int[3];

	//�����û������趨�ṹԪ��
	se[0][0] = dlgPara.m_se00;
	se[0][1] = dlgPara.m_se01;
	se[0][2] = dlgPara.m_se02;
	se[1][0] = dlgPara.m_se10;
	se[1][1] = dlgPara.m_se11;
	se[1][2] = dlgPara.m_se12;
	se[2][0] = dlgPara.m_se20;
	se[2][1] = dlgPara.m_se21;
	se[2][2] = dlgPara.m_se22;
	BeginWaitCursor();							// ���Ĺ����״
	CImgProcess imgOutput = imgInput;			// �������ʱ����
	imgInput.GrayDilate(&imgOutput, 3, 3, 1,
		1, se);									// ����GrayDilate()ʵ�ֻҶ�����
	//����se��һ��int **ָ�룬��ʾ�ṹԪ�ء����������3*3ԭ��λ�����ĵĽṹԪ��
	pDoc->m_Image = imgOutput;					// ��������ظ��ĵ���
	pDoc->SetModifiedFlag(true);
	pDoc->UpdateAllViews(NULL);
	EndWaitCursor();							// �ָ����
}

void CDIPView::OnMorphGrayerode()
{
	// �Ҷȸ�ʴ
	CDIPDoc* pDoc = GetDocument();				// ��ȡ�ĵ�
	CImgProcess imgInput = pDoc->m_Image;		// ����ͼ��
	if (imgInput.m_pBMIH->biBitCount != 8)		// ���ͼ���ǻҶ�ͼ
	{
		AfxMessageBox(L"����8-bpp�Ҷ�ͼ���޷�����");
		return;
	}
	CDlgMorph dlgPara;							// �����Ի���
	if (dlgPara.DoModal() != IDOK)				// ��ʾ�Ի�����ʾ�û��趨�ṹԪ��
		return;									// ����

	int** se;									//�ṹԪ��
	se = new int*[3];

	for (int i = 0; i < 3; i++)
		se[i] = new int[3];

	//�����û������趨�ṹԪ��
	se[0][0] = dlgPara.m_se00;
	se[0][1] = dlgPara.m_se01;
	se[0][2] = dlgPara.m_se02;
	se[1][0] = dlgPara.m_se10;
	se[1][1] = dlgPara.m_se11;
	se[1][2] = dlgPara.m_se12;
	se[2][0] = dlgPara.m_se20;
	se[2][1] = dlgPara.m_se21;
	se[2][2] = dlgPara.m_se22;

	BeginWaitCursor();							// ���Ĺ����״
	CImgProcess imgOutput = imgInput;			// �������ʱ����
	imgInput.GrayErode(&imgOutput, 3, 3,
		1, 1, se);								// ����GrayErode()ʵ�ֻҶȸ�ʴ
	//����se��һ��int **ָ�룬��ʾ�ṹԪ�ء����������3*3ԭ��λ�����ĵĽṹԪ��
	pDoc->m_Image = imgOutput;					// ��������ظ��ĵ���
	pDoc->SetModifiedFlag(true);
	pDoc->UpdateAllViews(NULL);
	EndWaitCursor();							// �ָ����
}

void CDIPView::OnMorphGrayopen()
{
	// �Ҷȿ�����
	CDIPDoc* pDoc = GetDocument();				// ��ȡ�ĵ�
	CImgProcess imgInput = pDoc->m_Image;		// ����ͼ��
	if (imgInput.m_pBMIH->biBitCount != 8)		// ���ͼ���ǻҶ�ͼ
	{
		AfxMessageBox(L"����8-bpp�Ҷ�ͼ���޷�����");
		return;
	}
	CDlgMorph dlgPara;							// �����Ի���
	if (dlgPara.DoModal() != IDOK)				// ��ʾ�Ի�����ʾ�û��趨�ṹԪ��
		return;									// ����

	int** se;									// �ṹԪ��
	se = new int*[3];
	for (int i = 0; i < 3; i++)
		se[i] = new int[3];

	//�����û������趨�ṹԪ��
	se[0][0] = dlgPara.m_se00;
	se[0][1] = dlgPara.m_se01;
	se[0][2] = dlgPara.m_se02;
	se[1][0] = dlgPara.m_se10;
	se[1][1] = dlgPara.m_se11;
	se[1][2] = dlgPara.m_se12;
	se[2][0] = dlgPara.m_se20;
	se[2][1] = dlgPara.m_se21;
	se[2][2] = dlgPara.m_se22;
	BeginWaitCursor();							// ���Ĺ����״
	CImgProcess imgOutput = imgInput;			// �������ʱ����
	imgInput.GrayOpen(&imgOutput, 3, 3, 1, 1, se);//����GrayOpen()ʵ�ֻҶȿ�
	//����se��һ��int **ָ�룬��ʾ�ṹԪ�ء����������3*3ԭ��λ�����ĵĽṹԪ��
	pDoc->m_Image = imgOutput;					// ��������ظ��ĵ���
	pDoc->SetModifiedFlag(true);
	pDoc->UpdateAllViews(NULL);
	EndWaitCursor();							// �ָ����
}

void CDIPView::OnMorphGrayclose()
{
	//�Ҷȱ�����
	CDIPDoc* pDoc = GetDocument();				// ��ȡ�ĵ�
	CImgProcess imgInput = pDoc->m_Image;		// ����ͼ��
	if (imgInput.m_pBMIH->biBitCount != 8)		// ���ͼ���ǻҶ�ͼ
	{
		AfxMessageBox(L"����8-bpp�Ҷ�ͼ���޷�����");
		return;
	}
	CDlgMorph dlgPara;							// �����Ի���
	if (dlgPara.DoModal() != IDOK)				// ��ʾ�Ի�����ʾ�û��趨�ṹԪ��
		return;									// ����
	int** se;									// �ṹԪ��
	se = new int*[3];
	for (int i = 0; i < 3; i++)
		se[i] = new int[3];

	//�����û������趨�ṹԪ��
	se[0][0] = dlgPara.m_se00;
	se[0][1] = dlgPara.m_se01;
	se[0][2] = dlgPara.m_se02;
	se[1][0] = dlgPara.m_se10;
	se[1][1] = dlgPara.m_se11;
	se[1][2] = dlgPara.m_se12;
	se[2][0] = dlgPara.m_se20;
	se[2][1] = dlgPara.m_se21;
	se[2][2] = dlgPara.m_se22;
	BeginWaitCursor();							// ���Ĺ����״
	CImgProcess imgOutput = imgInput;			// �������ʱ����
	imgInput.GrayClose(&imgOutput, 3, 3, 1, 1, se);//����GrayClose()ʵ�ֻҶȱ�
	//����se��һ��int **ָ�룬��ʾ�ṹԪ�ء����������3*3ԭ��λ�����ĵĽṹԪ��
	pDoc->m_Image = imgOutput;					// ��������ظ��ĵ���
	pDoc->SetModifiedFlag(true);
	pDoc->UpdateAllViews(NULL);
	EndWaitCursor();							// �ָ����
}

void CDIPView::OnMorphTophat()
{
	// ��ñ�任
	CDIPDoc* pDoc = GetDocument();				// ��ȡ�ĵ�
	CImgProcess imgInput = pDoc->m_Image;		// ����ͼ��
	if (imgInput.m_pBMIH->biBitCount != 8)		// ���ͼ���ǻҶ�ͼ
	{
		AfxMessageBox(L"����8-bpp�Ҷ�ͼ���޷�����");
		return;
	}
	CDlgMorph dlgPara;							// �����Ի���
	if (dlgPara.DoModal() != IDOK)				// ��ʾ�Ի�����ʾ�û��趨�ṹԪ��
		return;									// ����
	int** se;									// �ṹԪ��
	se = new int*[3];

	for (int i = 0; i < 3; i++)
		se[i] = new int[3];
	//�����û������趨�ṹԪ��
	se[0][0] = dlgPara.m_se00;
	se[0][1] = dlgPara.m_se01;
	se[0][2] = dlgPara.m_se02;
	se[1][0] = dlgPara.m_se10;
	se[1][1] = dlgPara.m_se11;
	se[1][2] = dlgPara.m_se12;
	se[2][0] = dlgPara.m_se20;
	se[2][1] = dlgPara.m_se21;
	se[2][2] = dlgPara.m_se22;
	BeginWaitCursor();							// ���Ĺ����״
	CImgProcess imgOutput = imgInput;			// �������ʱ����
	imgInput.Tophat(&imgOutput, 3, 3, 1, 1, se);// ����Tophat()ʵ�ֶ�ñ�任
	//����se��һ��int **ָ�룬��ʾ�ṹԪ�ء����������3*3ԭ��λ�����ĵĽṹԪ��
	pDoc->m_Image = imgOutput;					// ��������ظ��ĵ���
	pDoc->SetModifiedFlag(true);
	pDoc->UpdateAllViews(NULL);

	EndWaitCursor();							// �ָ����
}

void CDIPView::OnPicAdd()
{
	CDIPDoc* pDoc = GetDocument();				// ��ȡ�ĵ�
	CImgProcess imgInput = pDoc->m_Image;		// �������
	CImgProcess* pStdImage = new CImgProcess();	// ��׼ͼ��

	// ͨ���򿪶Ի����ȡ��׼ͼ��
	CString filePath;							// �ļ�·��
	CFileDialog openDlg(TRUE, 0, 0, 4 | 2,
		L"Bitmap Files (*.bmp)||");				// ���ļ��Ի�������û����ȡ���򷵻�
	if (openDlg.DoModal() == IDOK)
		filePath = openDlg.GetPathName();
	else
		return;

	pStdImage->AttachFromFile(filePath);		// ��ȡ��׼ͼ��

	if (imgInput.m_pBMIH->biWidth != pStdImage->m_pBMIH->biWidth
		|| imgInput.m_pBMIH->biHeight != pStdImage->m_pBMIH->biHeight)
		AfxMessageBox(L"���ѣ�ͼ��ߴ粻һ�£�Ч�����ܲ����룡");

	if (   (imgInput.m_pBMIH->biBitCount == 8 && pStdImage->m_pBMIH->biBitCount != 8)
		|| (imgInput.m_pBMIH->biBitCount == 24 && pStdImage->m_pBMIH->biBitCount != 24))
	{
		AfxMessageBox(L"ͼ��λ������ƥ�䣬������ӣ�");
		return;
	}

	CImgProcess imgOutput = imgInput;			// �������ʱ����
	imgInput.PicAdd(&imgOutput, pStdImage);		// ͼ�����
	pDoc->m_Image = imgOutput;					// ��������ظ��ĵ���
	delete pStdImage;
	pDoc->SetModifiedFlag(true);
	pDoc->UpdateAllViews(NULL);
}

void CDIPView::OnPicSub()
{
	CDIPDoc* pDoc = GetDocument();				// ��ȡ�ĵ�
	CImgProcess imgInput = pDoc->m_Image;		// �������
	CImgProcess* pStdImage = new CImgProcess();	// ��׼ͼ��

	// ͨ���򿪶Ի����ȡ��׼ͼ��
	CString filePath;							// �ļ�·��
	CFileDialog openDlg(TRUE, 0, 0, 4 | 2,
		L"Bitmap Files (*.bmp)||");				// ���ļ��Ի�������û����ȡ���򷵻�
	if (openDlg.DoModal() == IDOK)
		filePath = openDlg.GetPathName();
	else
		return;

	pStdImage->AttachFromFile(filePath);		// ��ȡ��׼ͼ��
	
	if (imgInput.m_pBMIH->biWidth != pStdImage->m_pBMIH->biWidth
		|| imgInput.m_pBMIH->biHeight != pStdImage->m_pBMIH->biHeight)
		AfxMessageBox(L"���ѣ�ͼ��ߴ粻һ�£�Ч�����ܲ����룡");

	if (imgInput.m_pBMIH->biBitCount == 8 && pStdImage->m_pBMIH->biBitCount != 8
		|| imgInput.m_pBMIH->biBitCount == 24 && pStdImage->m_pBMIH->biBitCount != 24)
	{
		AfxMessageBox(L"λ������ƥ�䣬������ӣ�");
		return;
	}

	CImgProcess imgOutput = imgInput;			// �������ʱ����
	imgInput.PicSub(&imgOutput, pStdImage);		// ͼ�����
	pDoc->m_Image = imgOutput;					// ��������ظ��ĵ���
	delete pStdImage;
	pDoc->SetModifiedFlag(true);
	pDoc->UpdateAllViews(NULL);
}

void CDIPView::OnPicMul()
{
	CDIPDoc* pDoc = GetDocument();				// ��ȡ�ĵ�
	CImgProcess imgInput = pDoc->m_Image;		// �������
	CImgProcess* pStdImage = new CImgProcess();	// ��׼ͼ��

												// ͨ���򿪶Ի����ȡ��׼ͼ��
	CString filePath;							// �ļ�·��
	CFileDialog openDlg(TRUE, 0, 0, 4 | 2,
		L"Bitmap Files (*.bmp)||");				// ���ļ��Ի�������û����ȡ���򷵻�
	if (openDlg.DoModal() == IDOK)
		filePath = openDlg.GetPathName();
	else
		return;

	pStdImage->AttachFromFile(filePath);		// ��ȡ��׼ͼ��
	
	if (imgInput.m_pBMIH->biWidth != pStdImage->m_pBMIH->biWidth
		|| imgInput.m_pBMIH->biHeight != pStdImage->m_pBMIH->biHeight)
		AfxMessageBox(L"���ѣ�ͼ��ߴ粻һ�£�Ч�����ܲ����룡");
	
	if (!pStdImage->IsBiImg(pStdImage))
	{
		AfxMessageBox(L"��ǰͼ���Ƕ�ֵͼ������ˣ�");
		return;
	}

	CImgProcess imgOutput = imgInput;			// �������ʱ����
	imgInput.PicSub(&imgOutput, pStdImage);		// ͼ�����
	pDoc->m_Image = imgOutput;					// ��������ظ��ĵ���
	delete pStdImage;
	pDoc->SetModifiedFlag(true);
	pDoc->UpdateAllViews(NULL);
}

void CDIPView::OnPointStdlin()
{
	CDIPDoc* pDoc = GetDocument();				// ��ȡ�ĵ�
	CImgProcess imgInput = pDoc->m_Image;		// �������
	if (imgInput.m_pBMIH->biBitCount != 8)		// ���ͼ���ǻҶ�ͼ
	{
		AfxMessageBox(L"����8-bpp�Ҷ�ͼ���޷�����");
		return;
	}
	CDlgLinTrans dlg;							// ������������Ի���
	dlg.m_bS1 = 64;
	dlg.m_bS2 = 192;
	dlg.m_bT1 = 32;
	dlg.m_bT2 = 224;

	if (dlg.DoModal() != IDOK)
		return;
	CImgProcess imgOutput = imgInput;			// �������ʱ����
	imgInput.ParLinTran(&imgOutput, dlg.m_bS1,
		dlg.m_bS2, dlg.m_bT1, dlg.m_bT2);		// �ֶ����Ա任
	pDoc->m_Image = imgOutput;					// ��������ظ��ĵ���
	pDoc->SetModifiedFlag(true);
	pDoc->UpdateAllViews(NULL);
}
void CDIPView::OnPointLog()
{
	CDIPDoc* pDoc = GetDocument();				// ��ȡ�ĵ�
	CImgProcess imgInput = pDoc->m_Image;		// �������
	if (imgInput.m_pBMIH->biBitCount != 8)		// ���ͼ���ǻҶ�ͼ
	{
		AfxMessageBox(L"����8-bpp�Ҷ�ͼ���޷�����");
		return;
	}
	CDlgLog dlg;								// ������������Ի���
	dlg.m_dC = 20;
	if (dlg.DoModal() != IDOK)
		return;
	CImgProcess imgOutput = imgInput;			// �������ʱ����
	imgInput.LogTran(&imgOutput, dlg.m_dC);		// ʹ�ö����任����
	pDoc->m_Image = imgOutput;					// ��������ظ��ĵ���
	pDoc->SetModifiedFlag(true);
	pDoc->UpdateAllViews(NULL);
}

void CDIPView::OnPointGamma()
{
	CDIPDoc* pDoc = GetDocument();				// ��ȡ�ĵ�
	CImgProcess imgInput = pDoc->m_Image;		// �������
	if (imgInput.m_pBMIH->biBitCount != 8)		// ���ͼ���ǻҶ�ͼ
	{
		AfxMessageBox(L"����8-bpp�Ҷ�ͼ���޷�����");
		return;
	}
	CDlgGamma dlg;								// ������������Ի���
	dlg.m_dEsp = 0;
	dlg.m_dGamma = 1;
	if (dlg.DoModal() != IDOK)
		return;
	CImgProcess imgOutput = imgInput;			// �������ʱ����
	imgInput.GammaTran(&imgOutput, dlg.m_dGamma,
		dlg.m_dEsp);							// ����GammaTran����ִ��٤��任
	pDoc->m_Image = imgOutput;					// ��������ظ��ĵ���
	pDoc->SetModifiedFlag(true);
	pDoc->UpdateAllViews(NULL);
}

void CDIPView::OnPointHistst()
{
	CDIPDoc* pDoc = GetDocument();				// ��ȡ�ĵ�
	CImgProcess imgInput = pDoc->m_Image;		// �������
	if (imgInput.m_pBMIH->biBitCount != 8)		// ���ͼ���ǻҶ�ͼ
	{
		AfxMessageBox(L"����8-bpp�Ҷ�ͼ���޷�����");
		return;
	}
	CImgProcess* pStdImage = new CImgProcess();	// ��׼ͼ��
	double pdStdHist[256];						// �����׼ͼ���ԭͼ��ĻҶ�ֱ��ͼ������
	// ͨ���򿪶Ի����ȡ��׼ͼ��
	CString filePath;							// �ļ�·��
	CFileDialog openDlg(TRUE, 0, 0, 4 | 2,
		L"Bitmap Files (*.bmp)||");				// ���ļ��Ի�������û����ȡ���򷵻�
	if (openDlg.DoModal() == IDOK)
		filePath = openDlg.GetPathName();
	else
		return;
	pStdImage->AttachFromFile(filePath);		// ��ȡ��׼ͼ��
	if (pStdImage->m_pBMIH->biBitCount != 8)	// ���ͼ���ǻҶ�ͼ
	{
		AfxMessageBox(L"����8-bpp�Ҷ�ͼ���޷�����");
		return;
	}
	pStdImage->GenHist(pdStdHist);				// ���㲢��ʾ��׼ͼ���ֱ��ͼ������û����ȡ���򷵻�
	CDlgHist histDlg;
	histDlg.m_pdHist = pdStdHist;
	if (histDlg.DoModal() != IDOK)
		return;
	delete histDlg;
	CImgProcess imgOutput = imgInput;			// �������ʱ����
	imgInput.Histst(&imgOutput, pdStdHist);		// ֱ��ͼ�涨��
	pDoc->m_Image = imgOutput;					// ��������ظ��ĵ���
	delete pStdImage;
	pDoc->SetModifiedFlag(true);
	pDoc->UpdateAllViews(NULL);
}

void CDIPView::OnFileRotate()
{
	CDIPDoc* pdoc = GetDocument();				// ����ǰ����̨ͼ��
	CImgProcess tmp = pdoc->m_Image;
	pdoc->m_Image = pdoc->m_OImage;
	pdoc->m_OImage = tmp;
	delete &tmp;
	pdoc->SetModifiedFlag(true);
	pdoc->UpdateAllViews(NULL);
}

void CDIPView::OnFileReverse()
{
	// ͼ��ɫ
	CDIPDoc* pDoc = GetDocument();				// ��ȡ�ĵ�
	CImgProcess imgInput = pDoc->m_Image;		// ����ͼ��
	if (imgInput.m_pBMIH->biBitCount != 8)		// ���ͼ���ǻҶ�ͼ
	{
		AfxMessageBox(L"����8-bpp�Ҷ�ͼ���޷�����");
		return;
	}
	BeginWaitCursor();							// ���Ĺ����״
	CImgProcess imgOutput = imgInput;			// �������ʱ����
	imgOutput = !imgOutput;
	pDoc->m_Image = imgOutput;
	pDoc->SetModifiedFlag(true);
	pDoc->UpdateAllViews(NULL);
	EndWaitCursor();							// �ָ����
}

void CDIPView::OnEdgeRobert()
{
	CDIPDoc* pDoc = GetDocument();
	CImgProcess imgInput = pDoc->m_Image;		// �������
	if (imgInput.m_pBMIH->biBitCount != 8)		// ���ͼ���ǻҶ�ͼ
	{
		AfxMessageBox(L"����8-bpp�Ҷ�ͼ���޷�����");
		return;
	}

	CDlgEdgeSobelPrewitt dlg;
	dlg.isRobert = true;
	if (dlg.DoModal() != IDOK)
		return;

	CImgProcess imgOutput = imgInput;			// �������ʱ����
	imgInput.EdgeRoberts(&imgOutput, dlg.m_bThre, dlg.m_nEdgeType, dlg.m_bThining,
		dlg.m_bGratOnly);
	pDoc->m_Image = imgOutput;
	pDoc->SetModifiedFlag(true);
	pDoc->UpdateAllViews(NULL);
}

void CDIPView::OnEdgeSobel()
{
	CDIPDoc* pDoc = GetDocument();
	CImgProcess imgInput = pDoc->m_Image;		// �������
	if (imgInput.m_pBMIH->biBitCount != 8)		// ���ͼ���ǻҶ�ͼ
	{
		AfxMessageBox(L"����8-bpp�Ҷ�ͼ���޷�����");
		return;
	}

	CDlgEdgeSobelPrewitt dlg;
	if (dlg.DoModal() != IDOK)
		return;

	BeginWaitCursor();
	CImgProcess imgOutput = imgInput;			// �������ʱ����
	imgInput.EdgeSobel(&imgOutput, dlg.m_bThre, dlg.m_nEdgeType, dlg.m_bThining,
		dlg.m_bGratOnly);						// Sobel��Ե���
	pDoc->m_Image = imgOutput;					// ��������ظ��ĵ���
	pDoc->SetModifiedFlag(true);
	pDoc->UpdateAllViews(NULL);
	EndWaitCursor();							// �ָ����
}

void CDIPView::OnEdgePrewitt()
{
	CDIPDoc* pDoc = GetDocument();
	CImgProcess imgInput = pDoc->m_Image;		// �������
	if (imgInput.m_pBMIH->biBitCount != 8)		// ���ͼ���ǻҶ�ͼ
	{
		AfxMessageBox(L"����8-bpp�Ҷ�ͼ���޷�����");
		return;
	}
	CDlgEdgeSobelPrewitt dlg;
	if (dlg.DoModal() != IDOK)
		return;
	BeginWaitCursor();
	CImgProcess imgOutput = imgInput;			// �������ʱ����
	imgInput.EdgePrewitt(&imgOutput, dlg.m_bThre, dlg.m_nEdgeType, dlg.m_bThining,
		dlg.m_bGratOnly);
	pDoc->m_Image = imgOutput;					// ��������ظ��ĵ���
	pDoc->SetModifiedFlag(true);
	pDoc->UpdateAllViews(NULL);
	EndWaitCursor();							// �ָ����
}

void CDIPView::OnEdgeLog()
{
	CDIPDoc* pDoc = GetDocument();
	CImgProcess imgInput = pDoc->m_Image;		// �������
	if (imgInput.m_pBMIH->biBitCount != 8)		// ���ͼ���ǻҶ�ͼ
	{
		AfxMessageBox(L"����8-bpp�Ҷ�ͼ���޷�����");
		return;
	}
	BeginWaitCursor();
	CImgProcess imgOutput = imgInput;			// �������ʱ����
	imgInput.EdgeLoG(&imgOutput);
	pDoc->m_Image = imgOutput;					// ��������ظ��ĵ���
	pDoc->SetModifiedFlag(true);
	pDoc->UpdateAllViews(NULL);
	EndWaitCursor();
}

void CDIPView::OnEdgeSimpthre()
{
	CDIPDoc* pDoc = GetDocument();				// ����ֵ�ָ�
	CImgProcess imgInput = pDoc->m_Image;		// �������
	if (imgInput.m_pBMIH->biBitCount != 8)		// ���ͼ���ǻҶ�ͼ
	{
		AfxMessageBox(L"����8-bpp�Ҷ�ͼ���޷�����");
		return;
	}

	CDlgEdgeSimpthre dlg;
	if (dlg.DoModal() != IDOK)
		return;

	CImgProcess imgOutput = imgInput;			// �������ʱ����
	imgInput.SimpThreshold(&imgOutput, 
		dlg.m_iThreshold);						// �ֶ����Ա任
	pDoc->m_Image = imgOutput;					// ��������ظ��ĵ���
	pDoc->SetModifiedFlag(true);
	pDoc->UpdateAllViews(NULL);
}

void CDIPView::OnEdgeAutothre()
{
	CDIPDoc* pDoc = GetDocument();				// �Զ���ֵ�ָ�
	CImgProcess imgInput = pDoc->m_Image;		// �������
	if (imgInput.m_pBMIH->biBitCount != 8)		// ���ͼ���ǻҶ�ͼ
	{
		AfxMessageBox(L"����8-bpp�Ҷ�ͼ���޷�����");
		return;
	}
	CImgProcess imgOutput = imgInput;			// �������ʱ����
	imgInput.AutoThreshold(&imgOutput);			// �Զ���ֵ��
	pDoc->m_Image = imgOutput;					// ��������ظ��ĵ���
	pDoc->SetModifiedFlag(true);
	pDoc->UpdateAllViews(NULL);
}

void CDIPView::OnFreqIdeallpf()
{
	CDIPDoc* pDoc = GetDocument();
	CImgProcess imgInput = pDoc->m_Image;		// �������
	if (imgInput.m_pBMIH->biBitCount != 8)		// ���ͼ���ǻҶ�ͼ
	{
		AfxMessageBox(L"����8-bpp�Ҷ�ͼ���޷�����");
		return;
	}
	CDlgFreqIdealLPF dlg;
	if (dlg.DoModal() != IDOK)
		return;
	BeginWaitCursor();
	CImgProcess imgOutput = imgInput;			// �������ʱ����
	LONG w = imgInput.GetFreqWidth();			// ������Ҫ�����˾��Ŀ��
	LONG h = imgInput.GetFreqHeight();			// ������Ҫ�����˾��ĸ߶�
	double* pdFreqFilt = new double[w * h];		// ����Ƶ���˾�
	imgInput.FreqIdealLPF(pdFreqFilt, dlg.m_nFreq);
	imgInput.FreqFilt(&imgOutput, pdFreqFilt);	//��Ӧ���˾�
	pDoc->m_Image = imgOutput;					// ��������ظ��ĵ���
	delete[] pdFreqFilt;						// ɾ����ʱ����
	pDoc->SetModifiedFlag(true);
	pDoc->UpdateAllViews(NULL);
	EndWaitCursor();
}

void CDIPView::OnFreqIdealhpf()
{
	CDIPDoc* pDoc = GetDocument();
	CImgProcess imgInput = pDoc->m_Image;		// �������
	if (imgInput.m_pBMIH->biBitCount != 8)		// ���ͼ���ǻҶ�ͼ
	{
		AfxMessageBox(L"����8-bpp�Ҷ�ͼ���޷�����");
		return;
	}
	CDlgFreqIdealLPF dlg;
	if (dlg.DoModal() != IDOK)
		return;
	BeginWaitCursor();
	CImgProcess imgOutput = imgInput;			// �������ʱ����
	LONG w = imgInput.GetFreqWidth();			// ������Ҫ�����˾��Ŀ��
	LONG h = imgInput.GetFreqHeight();			// ������Ҫ�����˾��ĸ߶�
	double* pdFreqFilt = new double[w * h];		// ����Ƶ���˾�
	imgInput.FreqIdealHPF(pdFreqFilt, dlg.m_nFreq);
	imgInput.FreqFilt(&imgOutput, pdFreqFilt);	//��Ӧ���˾�
	pDoc->m_Image = imgOutput;					// ��������ظ��ĵ���
	delete[] pdFreqFilt;						// ɾ����ʱ����
	pDoc->SetModifiedFlag(true);
	pDoc->UpdateAllViews(NULL);
	EndWaitCursor();
}

void CDIPView::OnFreqGausslpf()
{
	CDIPDoc* pDoc = GetDocument();				// ��˹��ͨ�˲�
	CImgProcess imgInput = pDoc->m_Image;		// �������
	if (imgInput.m_pBMIH->biBitCount != 8)		// ���ͼ���ǻҶ�ͼ
	{
		AfxMessageBox(L"����8-bpp�Ҷ�ͼ���޷�����");
		return;
	}
	CDlgFreqGaussLPF dlg;
	if (dlg.DoModal() != IDOK)
		return;
	BeginWaitCursor();
	CImgProcess imgOutput = imgInput;			// �������ʱ����
	LONG w = imgInput.GetFreqWidth();			// ������Ҫ�����˾��Ŀ��
	LONG h = imgInput.GetFreqHeight();			// ������Ҫ�����˾��ĸ߶�
	double* pdFreqFilt = new double[w * h];		// ����Ƶ���˾�
	imgInput.FreqGaussLPF(pdFreqFilt, dlg.m_dSigma);
	imgInput.FreqFilt(&imgOutput, pdFreqFilt);	//��Ӧ���˾�
	pDoc->m_Image = imgOutput;					// ��������ظ��ĵ���
	delete[] pdFreqFilt;						// ɾ����ʱ����
	pDoc->SetModifiedFlag(true);
	pDoc->UpdateAllViews(NULL);
	EndWaitCursor();
}

void CDIPView::OnFreqGausshpf()
{
	CDIPDoc* pDoc = GetDocument();				// ��˹��ͨ�˲�
	CImgProcess imgInput = pDoc->m_Image;		// �������
	if (imgInput.m_pBMIH->biBitCount != 8)		// ���ͼ���ǻҶ�ͼ
	{
		AfxMessageBox(L"����8-bpp�Ҷ�ͼ���޷�����");
		return;
	}
	CDlgFreqGaussHPF dlg;
	if (dlg.DoModal() != IDOK)
		return;
	BeginWaitCursor();							// �������ʱ����
	CImgProcess imgOutput = imgInput;			// ������Ҫ�����˾��Ĵ�С
	LONG w = imgInput.GetFreqWidth();
	LONG h = imgInput.GetFreqHeight();
	double* pdFreqFilt = new double[w * h];		// ����Ƶ���˾�
	imgInput.FreqGaussHPF(pdFreqFilt, dlg.m_dSigma);
	imgInput.FreqFilt(&imgOutput, pdFreqFilt);	//��Ӧ���˾�
	pDoc->m_Image = imgOutput;					// ��������ظ��ĵ���
	delete[] pdFreqFilt;						// ɾ����ʱ����
	pDoc->SetModifiedFlag(true);
	pDoc->UpdateAllViews(NULL);
	EndWaitCursor();
}

void CDIPView::OnFreqExplpf()
{
	CDIPDoc* pDoc = GetDocument();				// ָ����ͨ�˲�
	CImgProcess imgInput = pDoc->m_Image;		// �������
	if (imgInput.m_pBMIH->biBitCount != 8)		// ���ͼ���ǻҶ�ͼ
	{
		AfxMessageBox(L"����8-bpp�Ҷ�ͼ���޷�����");
		return;
	}
	CDlgFreqExpLPF dlg;
	if (dlg.DoModal() != IDOK)
		return;
	BeginWaitCursor();
	CImgProcess imgOutput = imgInput;			// �������ʱ����
	LONG w = imgInput.GetFreqWidth();			// ������Ҫ�����˾��Ŀ��
	LONG h = imgInput.GetFreqHeight();			// ������Ҫ�����˾��ĸ߶�
	double* pdFreqFilt = new double[w * h];		// ����Ƶ���˾�
	imgInput.FreqExpLPF(pdFreqFilt, dlg.m_nFreq, dlg.n);
	imgInput.FreqFilt(&imgOutput, pdFreqFilt);	//��Ӧ���˾�
	pDoc->m_Image = imgOutput;					// ��������ظ��ĵ���
	delete[] pdFreqFilt;						// ɾ����ʱ����
	pDoc->SetModifiedFlag(true);
	pDoc->UpdateAllViews(NULL);
	EndWaitCursor();
}

void CDIPView::OnFreqExphpf()
{
	CDIPDoc* pDoc = GetDocument();				// ָ����ͨ�˲�
	CImgProcess imgInput = pDoc->m_Image;		// �������
	if (imgInput.m_pBMIH->biBitCount != 8)		// ���ͼ���ǻҶ�ͼ
	{
		AfxMessageBox(L"����8-bpp�Ҷ�ͼ���޷�����");
		return;
	}
	CDlgFreqExpHPF dlg;
	if (dlg.DoModal() != IDOK)
		return;
	BeginWaitCursor();							// �������ʱ����
	CImgProcess imgOutput = imgInput;			// ������Ҫ�����˾��Ĵ�С
	LONG w = imgInput.GetFreqWidth();
	LONG h = imgInput.GetFreqHeight();
	double* pdFreqFilt = new double[w * h];		// ����Ƶ���˾�
	imgInput.FreqExpHPF(pdFreqFilt, dlg.m_nFreq, dlg.n);
	imgInput.FreqFilt(&imgOutput, pdFreqFilt);	//��Ӧ���˾�
	pDoc->m_Image = imgOutput;					// ��������ظ��ĵ���
	delete[] pdFreqFilt;						// ɾ����ʱ����
	pDoc->SetModifiedFlag(true);
	pDoc->UpdateAllViews(NULL);
	EndWaitCursor();
}

void CDIPView::OnFreqLadderlpf()
{
	CDIPDoc* pDoc = GetDocument();				// ָ����ͨ�˲�
	CImgProcess imgInput = pDoc->m_Image;		// �������
	if (imgInput.m_pBMIH->biBitCount != 8)		// ���ͼ���ǻҶ�ͼ
	{
		AfxMessageBox(L"����8-bpp�Ҷ�ͼ���޷�����");
		return;
	}
	CDlgFreqLadderLPF dlg;
	if (dlg.DoModal() != IDOK)
		return;

	if (dlg.m_nFreq > dlg.m_nF)
	{
		AfxMessageBox(L"��ֹƵ�ʴ��ڿɵ�Ƶ�ʣ����������ã�");
		return;
	}

	BeginWaitCursor();							// �������ʱ����
	CImgProcess imgOutput = imgInput;			// ������Ҫ�����˾��Ĵ�С
	LONG w = imgInput.GetFreqWidth();
	LONG h = imgInput.GetFreqHeight();
	double* pdFreqFilt = new double[w * h];		// ����Ƶ���˾�
	imgInput.FreqLadderLPF(pdFreqFilt, dlg.m_nFreq, dlg.m_nF);
	imgInput.FreqFilt(&imgOutput, pdFreqFilt);	//��Ӧ���˾�
	pDoc->m_Image = imgOutput;					// ��������ظ��ĵ���
	delete[] pdFreqFilt;						// ɾ����ʱ����
	pDoc->SetModifiedFlag(true);
	pDoc->UpdateAllViews(NULL);
	EndWaitCursor();
}

void CDIPView::OnFreqLadderhpf()
{
	CDIPDoc* pDoc = GetDocument();				// ָ����ͨ�˲�
	CImgProcess imgInput = pDoc->m_Image;		// �������
	if (imgInput.m_pBMIH->biBitCount != 8)		// ���ͼ���ǻҶ�ͼ
	{
		AfxMessageBox(L"����8-bpp�Ҷ�ͼ���޷�����");
		return;
	}
	CDlgFreqLadderHPF dlg;
	if (dlg.DoModal() != IDOK)
		return;

	if (dlg.m_nFreq > dlg.m_nF)
	{
		AfxMessageBox(L"��ֹƵ�ʴ��ڿɵ�Ƶ�ʣ����������ã�");
		return;
	}

	BeginWaitCursor();							// �������ʱ����
	CImgProcess imgOutput = imgInput;			// ������Ҫ�����˾��Ĵ�С
	LONG w = imgInput.GetFreqWidth();
	LONG h = imgInput.GetFreqHeight();
	double* pdFreqFilt = new double[w * h];		// ����Ƶ���˾�
	imgInput.FreqLadderHPF(pdFreqFilt, dlg.m_nFreq, dlg.m_nF);
	imgInput.FreqFilt(&imgOutput, pdFreqFilt);	//��Ӧ���˾�
	pDoc->m_Image = imgOutput;					// ��������ظ��ĵ���
	delete[] pdFreqFilt;						// ɾ����ʱ����
	pDoc->SetModifiedFlag(true);
	pDoc->UpdateAllViews(NULL);
	EndWaitCursor();
}

void CDIPView::OnFreqButterworthlpf()
{
	CDIPDoc* pDoc = GetDocument();				// ������˹��ͨ�˲�
	CImgProcess imgInput = pDoc->m_Image;		// �������
	if (imgInput.m_pBMIH->biBitCount != 8)		// ���ͼ���ǻҶ�ͼ
	{
		AfxMessageBox(L"����8-bpp�Ҷ�ͼ���޷�����");
		return;
	}
	CDlgFreqButterworthLPF dlg;
	if (dlg.DoModal() != IDOK)
		return;
	BeginWaitCursor();
	CImgProcess imgOutput = imgInput;			// �������ʱ����
	LONG w = imgInput.GetFreqWidth();			// ������Ҫ�����˾��Ŀ��
	LONG h = imgInput.GetFreqHeight();			// ������Ҫ�����˾��ĸ߶�
	double* pdFreqFilt = new double[w * h];		// ����Ƶ���˾�
	imgInput.FreqButterworthLPF(pdFreqFilt, dlg.m_nFreq, dlg.n);
	imgInput.FreqFilt(&imgOutput, pdFreqFilt);	//��Ӧ���˾�
	pDoc->m_Image = imgOutput;					// ��������ظ��ĵ���
	delete[] pdFreqFilt;						// ɾ����ʱ����
	pDoc->SetModifiedFlag(true);
	pDoc->UpdateAllViews(NULL);
	EndWaitCursor();
}

void CDIPView::OnFreqButterworthhpf()
{
	CDIPDoc* pDoc = GetDocument();				// ������˹��ͨ�˲�
	CImgProcess imgInput = pDoc->m_Image;		// �������
	if (imgInput.m_pBMIH->biBitCount != 8)		// ���ͼ���ǻҶ�ͼ
	{
		AfxMessageBox(L"����8-bpp�Ҷ�ͼ���޷�����");
		return;
	}
	CDlgFreqButterworthHPF dlg;
	if (dlg.DoModal() != IDOK)
		return;
	BeginWaitCursor();							// �������ʱ����
	CImgProcess imgOutput = imgInput;			// ������Ҫ�����˾��Ĵ�С
	LONG w = imgInput.GetFreqWidth();
	LONG h = imgInput.GetFreqHeight();
	double* pdFreqFilt = new double[w * h];		// ����Ƶ���˾�
	imgInput.FreqButterworthHPF(pdFreqFilt, dlg.m_nFreq, dlg.n);
	imgInput.FreqFilt(&imgOutput, pdFreqFilt);	//��Ӧ���˾�
	pDoc->m_Image = imgOutput;					// ��������ظ��ĵ���
	delete[] pdFreqFilt;						// ɾ����ʱ����
	pDoc->SetModifiedFlag(true);
	pDoc->UpdateAllViews(NULL);
	EndWaitCursor();
}

void CDIPView::OnFreqLapl()
{
	CDIPDoc* pDoc = GetDocument();
	CImgProcess imgInput = pDoc->m_Image;		// �������
	if (imgInput.m_pBMIH->biBitCount != 8)		// ���ͼ���ǻҶ�ͼ
	{
		AfxMessageBox(L"����8-bpp�Ҷ�ͼ���޷�����");
		return;
	}
	BeginWaitCursor();
	CImgProcess imgOutput = imgInput;			// �������ʱ����
	LONG w = imgInput.GetFreqWidth();			// ������Ҫ�����˾��ĸ߶�
	LONG h = imgInput.GetFreqHeight();			// ������Ҫ�����˾��Ŀ��
	double* pdFreqFilt = new double[w * h];		// ����Ƶ���˾�
	imgInput.FreqLaplace(pdFreqFilt);
	imgInput.FreqFilt(&imgOutput, pdFreqFilt);	//��Ӧ���˾�
	pDoc->m_Image = imgOutput;					// ��������ظ��ĵ���
	delete[] pdFreqFilt;						// ɾ����ʱ����
	pDoc->SetModifiedFlag(true);
	pDoc->UpdateAllViews(NULL);
	EndWaitCursor();
}

void CDIPView::OnFreqGaussbr()
{
	CDIPDoc* pDoc = GetDocument();
	CImgProcess imgInput = pDoc->m_Image;		// �������

	if (imgInput.m_pBMIH->biBitCount != 8)		// ���ͼ���ǻҶ�ͼ
	{
		AfxMessageBox(L"����8-bpp�Ҷ�ͼ���޷�����");
		return;
	}
	CDlgFreqGaussBRF dlg;
	dlg.m_nFreq = 0;
	dlg.m_nWidth = 0;
	if (dlg.DoModal() != IDOK)
		return;
	BeginWaitCursor();
	CImgProcess imgOutput = imgInput;			// �������ʱ����
	LONG w = imgInput.GetFreqWidth();			// ������Ҫ�����˾��ĸ߶�
	LONG h = imgInput.GetFreqHeight();			// ������Ҫ�����˾��Ŀ��
	double* pdFreqFilt = new double[w * h];		// ����Ƶ���˾�
	imgInput.FreqGaussBRF(pdFreqFilt, dlg.m_nFreq, dlg.m_nWidth);
	imgInput.FreqFilt(&imgOutput, pdFreqFilt);	// Ӧ���˾�
	pDoc->m_Image = imgOutput;					// ��������ظ��ĵ���
	delete[] pdFreqFilt;						// ɾ����ʱ����
	pDoc->SetModifiedFlag(true);
	pDoc->UpdateAllViews(NULL);
	EndWaitCursor();
}

void CDIPView::OnEdgeCanny()
{
	CDIPDoc* pDoc = GetDocument();				// ��ȡ�ĵ�����
	CImgProcess imgInput = pDoc->m_Image;		// �������

	if (imgInput.m_pBMIH->biBitCount != 8)		// ���ͼ���ǻҶ�ͼ
	{
		AfxMessageBox(L"����8-bpp�Ҷ�ͼ���޷�����");
		return;
	}
	BeginWaitCursor();
	CImgProcess imgOutput = imgInput;			// �������ʱ����
	imgInput.EdgeCanny(&imgOutput);
	pDoc->m_Image = imgOutput;					// ��������ظ��ĵ���
	pDoc->SetModifiedFlag(true);
	pDoc->UpdateAllViews(NULL);
	EndWaitCursor();
}

void CDIPView::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	CDIPDoc* pDoc = GetDocument();
	CImgProcess imgInput = pDoc->m_Image;		// �������

	if (imgInput.m_pBMIH->biBitCount != 8)		// ���ͼ���ǻҶ�ͼ
	{
		AfxMessageBox(L"����8-bpp�Ҷ�ͼ���޷�����");
		return;
	}
	CImgProcess imgOutput = imgInput;			// �������ʱ����
	CDlgPointThre* dlgPara;						// �����Ի���

	switch (m_bLBtnDblClkSrv)
	{
	case 0:
		break;

	case 1:
		BYTE    bThre;							// ��ֵ
		dlgPara = new CDlgPointThre();			// ��ʼ���Ի���ͱ���
		dlgPara->m_bThre = 16;
		if (dlgPara->DoModal() != IDOK)			// ��ʾ�Ի�����ʾ�û��趨��ֵ
			return;								// ����

		bThre = dlgPara->m_bThre;				// ��ȡ�û��趨����ֵ
		delete dlgPara;							// ɾ���Ի���
		imgInput.RegionGrow(&imgOutput, point.x, point.y, bThre);// ִ����������
		break;

	default:
		AfxMessageBox((LPCTSTR)L"����Ĳ������ã�����趨�ķ������");
	}

	pDoc->m_Image = imgOutput;
	pDoc->SetModifiedFlag(true);
	pDoc->UpdateAllViews(NULL);
	m_bLBtnDblClkSrv = 0;
	CScrollView::OnLButtonDblClk(nFlags, point);
}

void CDIPView::OnEdgeRegionGrow()
{
	// ��������
	AfxMessageBox((LPCTSTR)L"˫��ͼ���е��������趨����������ʼ�㡣");
	m_bLBtnDblClkSrv = 1;						//��1ʹ��˫����Ϣ������������
}

void CDIPView::OnEdgeHough()
{
	CDIPDoc* pDoc = GetDocument();				// ��ȡ�ĵ�����
	CImgProcess imgInput = pDoc->m_Image;		// �������
	if (!imgInput.IsBinaryImg())				// ���ͼ���Ƕ�ֵͼ��
	{
		AfxMessageBox(L"���Ƕ�ֵͼ���޷�����");
		return;
	}
	CDlgHough dlg;
	dlg.m_nNum = 0;

	if (dlg.DoModal() != IDOK)
		return;
	int nLineCount = dlg.m_nNum;					// Ҫ�ҵ���ֱ����Ŀ
	SLineInfo* pLines = new SLineInfo[nLineCount];	// ֱ�߱�����ʱ����
	CImgProcess imgOutput = imgInput;				// �������ʱ����
	imgInput.Hough(pLines, nLineCount);				// Hough�任

	// ������
	for (int k = 0; k < nLineCount; k++)			//�����k��ֱ��
	{
		//ɨ��ͼ�����ֱ��
		for (int i = 0; i < imgInput.GetHeight(); i++)
		{
			for (int j = 0; j < imgInput.GetWidthPixel(); j++)
			{
				int nDist;
				nDist = (int)(j * cos(pLines[k].nAngle * PI / 180.0) 
					+ i * sin(pLines[k].nAngle * PI 
						/ 180.0));				// ����theta����rho
				if (nDist == pLines[k].nDist)	//����㣨j, i����ֱ����
					imgOutput.SetPixel(j, i, RGB(255, 255, 255));
			}//for j
		}//for i
	}//for k
	pDoc->m_Image = imgOutput;					// ��������ظ��ĵ���
	pDoc->SetModifiedFlag(true);
	pDoc->UpdateAllViews(NULL);
}

void CDIPView::OnFileConvertgray()
{
	CDIPDoc* pDoc = GetDocument();				// ��ȡ�ĵ�����
	CImgProcess imgInput = pDoc->m_Image;		// �������
	if (imgInput.m_pBMIH->biBitCount != 8)		// ���ͼ����256ɫͼ
	{
		AfxMessageBox(L"����256ɫͼ���޷�����");
		return;
	}
	imgInput.Index2Gray();						// 256ɫ����ͼת�Ҷ�
	pDoc->m_Image = imgInput;					// ��������ظ��ĵ���
	pDoc->SetModifiedFlag(true);
	pDoc->UpdateAllViews(NULL);
}


void CDIPView::OnFileClean()
{
	CDIPDoc* pDoc = GetDocument();				// ��ȡ�ĵ�����
	CImgProcess imgInput = pDoc->m_Image;		// �������
	
	imgInput.InitPixels(0x00808080);			// ���ͼ�񣨺ͱ�����ɫ��ͬ��
	pDoc->m_Image = imgInput;					// ��������ظ��ĵ���
	pDoc->SetModifiedFlag(true);				// �������־
	pDoc->UpdateAllViews(NULL);					// ���ÿͻ�������Ч�������ػ��¼�
}

void CDIPView::OnFileInfoShow()
{
	CDIPDoc* pDoc = GetDocument();				// ����ĵ���ָ��
	CImgProcess imgInput = pDoc->m_Image;		// �������
	int iWidth, iHeight, iBitCount, iSize;		// ͼ��Ŀ�ȡ��߶ȡ�λ��ʹ�С
	iWidth = imgInput.m_pBMIH->biWidth;			// ͼ����
	iHeight = imgInput.m_pBMIH->biHeight;		// ͼ��߶�
	iBitCount = imgInput.m_pBMIH->biBitCount;	// λ��
	iSize = imgInput.m_pBMIH->biSize;			// �ߴ�

	CDlgFileInfoShow dlg;
	if (dlg.DoModal() != IDOK)
		return;

}

void CDIPView::OnColorRGB2GrayMax()
{
	CDIPDoc* pDoc = GetDocument();				// ����ĵ���ָ��
	CImgProcess imgInput = pDoc->m_Image;		// �������
	if (imgInput.m_pBMIH->biBitCount != 24)		// ���ͼ����RGBͼ��
	{
		AfxMessageBox(L"����RGBͼ���޷�����");
		return;
	}
	CImgProcess imgOutput = imgInput;			// �������ʱ����
	imgInput.RGB2Gray(&imgOutput,1);			// RGB2Gray
	pDoc->m_Image = imgOutput;					// ��������ظ��ĵ���
	pDoc->SetModifiedFlag(true);
	pDoc->UpdateAllViews(NULL);
}

void CDIPView::OnColorRGB2GrayEven()
{
	CDIPDoc* pDoc = GetDocument();				// ����ĵ���ָ��
	CImgProcess imgInput = pDoc->m_Image;		// �������
	if (imgInput.m_pBMIH->biBitCount != 24)		// ���ͼ����RGBͼ��
	{
		AfxMessageBox(L"����RGBͼ���޷�����");
		return;
	}
	CImgProcess imgOutput = imgInput;			// �������ʱ����
	imgInput.RGB2Gray(&imgOutput, 2);			// RGB2Gray
	pDoc->m_Image = imgOutput;					// ��������ظ��ĵ���
	pDoc->SetModifiedFlag(true);
	pDoc->UpdateAllViews(NULL);
}

void CDIPView::OnColorRGB2GrayWeight()
{
	CDIPDoc* pDoc = GetDocument();				// ����ĵ���ָ��
	CImgProcess imgInput = pDoc->m_Image;		// �������
	if (imgInput.m_pBMIH->biBitCount != 24)		// ���ͼ����RGBͼ��
	{
		AfxMessageBox(L"����RGBͼ���޷�����");
		return;
	}
	CImgProcess imgOutput = imgInput;			// �������ʱ����
	imgInput.RGB2Gray(&imgOutput, 3);			// RGB2Gray
	pDoc->m_Image = imgOutput;					// ��������ظ��ĵ���
	pDoc->SetModifiedFlag(true);
	pDoc->UpdateAllViews(NULL);
}

void CDIPView::OnColorGray2RGBPseudo()
{
	CDIPDoc* pDoc = GetDocument();				// ����ĵ���ָ��
	CImgProcess imgInput = pDoc->m_Image;		// �������
	if (imgInput.m_pBMIH->biBitCount != 8)		// ���ͼ����24λͼ��
	{
		AfxMessageBox(L"���ǻҶ�ͼ���޷�����");
		return;
	}
	CImgProcess imgOutput = imgInput;			// �������ʱ����
	imgInput.Gray2RGB(&imgOutput,1);			// Gray2RGB
	pDoc->m_Image = imgOutput;					// ��������ظ��ĵ���
	pDoc->SetModifiedFlag(true);
	pDoc->UpdateAllViews(NULL);
}

void CDIPView::OnColorGray2RGBRainbow()
{
	CDIPDoc* pDoc = GetDocument();				// ����ĵ���ָ��
	CImgProcess imgInput = pDoc->m_Image;		// �������
	if (imgInput.m_pBMIH->biBitCount != 8)		// ���ͼ����24λͼ��
	{
		AfxMessageBox(L"���ǻҶ�ͼ���޷�����");
		return;
	}
	CImgProcess imgOutput = imgInput;			// �������ʱ����
	imgInput.Gray2RGB(&imgOutput,2);			// Gray2RGB
	pDoc->m_Image = imgOutput;					// ��������ظ��ĵ���
	pDoc->SetModifiedFlag(true);
	pDoc->UpdateAllViews(NULL);
}

void CDIPView::OnColorGetRLevel()
{
	CDIPDoc* pDoc = GetDocument();				// ����ĵ���ָ��
	CImgProcess imgInput = pDoc->m_Image;		// �������
	if (imgInput.m_pBMIH->biBitCount != 24)		// ���ͼ����24λͼ��
	{
		AfxMessageBox(L"����24λͼ���޷�����");
		return;
	}
	CImgProcess imgOutput = imgInput;			// �������ʱ����
	imgInput.GetRGBLevel(&imgOutput, 1);		// ��ȡR��G��Bƽ��
	pDoc->m_Image = imgOutput;					// ��������ظ��ĵ���
	pDoc->SetModifiedFlag(true);
	pDoc->UpdateAllViews(NULL);
}

void CDIPView::OnColorGetGLevel()
{
	CDIPDoc* pDoc = GetDocument();				// ����ĵ���ָ��
	CImgProcess imgInput = pDoc->m_Image;		// �������
	if (imgInput.m_pBMIH->biBitCount != 24)		// ���ͼ����24λͼ��
	{
		AfxMessageBox(L"����24λͼ���޷�����");
		return;
	}
	CImgProcess imgOutput = imgInput;			// �������ʱ����
	imgInput.GetRGBLevel(&imgOutput, 2);		// ��ȡR��G��Bƽ��
	pDoc->m_Image = imgOutput;					// ��������ظ��ĵ���
	pDoc->SetModifiedFlag(true);
	pDoc->UpdateAllViews(NULL);
}

void CDIPView::OnColorGetBLevel()
{
	CDIPDoc* pDoc = GetDocument();				// ����ĵ���ָ��
	CImgProcess imgInput = pDoc->m_Image;		// �������
	if (imgInput.m_pBMIH->biBitCount != 24)		// ���ͼ����24λͼ��
	{
		AfxMessageBox(L"����24λͼ���޷�����");
		return;
	}
	CImgProcess imgOutput = imgInput;			// �������ʱ����
	imgInput.GetRGBLevel(&imgOutput, 3);		// ��ȡR��G��Bƽ��
	pDoc->m_Image = imgOutput;					// ��������ظ��ĵ���
	pDoc->SetModifiedFlag(true);
	pDoc->UpdateAllViews(NULL);
}

void CDIPView::OnColorRGB2CMY()
{
	CDIPDoc* pDoc = GetDocument();				// ����ĵ���ָ��
	CImgProcess imgInput = pDoc->m_Image;		// �������
	if (imgInput.m_pBMIH->biBitCount != 24)		// ���ͼ����24λͼ��
	{
		AfxMessageBox(L"����24λͼ���޷�����");
		return;
	}
	CImgProcess imgOutput = imgInput;			// �������ʱ����
	imgInput.RGB2CMY(&imgOutput);				// RGB2CMY
	pDoc->m_Image = imgOutput;					// ��������ظ��ĵ���
	pDoc->SetModifiedFlag(true);
	pDoc->UpdateAllViews(NULL);
}

void CDIPView::OnColorCMY2RGB()
{
	CDIPDoc* pDoc = GetDocument();				// ����ĵ���ָ��
	CImgProcess imgInput = pDoc->m_Image;		// �������
	if (imgInput.m_pBMIH->biBitCount != 24)		// ���ͼ����24λͼ��
	{
		AfxMessageBox(L"����24λͼ���޷�����");
		return;
	}
	CImgProcess imgOutput = imgInput;			// �������ʱ����
	imgInput.CMY2RGB(&imgOutput);				// CMY2RGB
	pDoc->m_Image = imgOutput;					// ��������ظ��ĵ���
	pDoc->SetModifiedFlag(true);
	pDoc->UpdateAllViews(NULL);
}

void CDIPView::OnColorRGB2HSI()
{
	CDIPDoc* pDoc = GetDocument();				// ����ĵ���ָ��
	CImgProcess imgInput = pDoc->m_Image;		// �������
	if (imgInput.m_pBMIH->biBitCount != 24)		// ���ͼ����RGBͼ��
	{
		AfxMessageBox(L"����RGBͼ���޷�����");
		return;
	}
	CImgProcess imgOutput = imgInput;			// �������ʱ����
	imgInput.RGB2HSI(&imgOutput);				// RGB2HSI
	pDoc->m_Image = imgOutput;					// ��������ظ��ĵ���
	pDoc->SetModifiedFlag(true);
	pDoc->UpdateAllViews(NULL);
}

void CDIPView::OnColorHSI2RGB()
{
	CDIPDoc* pDoc = GetDocument();				// ����ĵ���ָ��
	CImgProcess imgInput = pDoc->m_Image;		// �������
	if (imgInput.m_pBMIH->biBitCount != 24)		// ���ͼ����24λͼ��
	{
		AfxMessageBox(L"����24λͼ���޷�����");
		return;
	}
	CImgProcess imgOutput = imgInput;			// �������ʱ����
	imgInput.HSI2RGB(&imgOutput);				// HSI2RGB
	pDoc->m_Image = imgOutput;					// ��������ظ��ĵ���
	pDoc->SetModifiedFlag(true);
	pDoc->UpdateAllViews(NULL);
}

void CDIPView::OnColorRGB2HSV()
{
	CDIPDoc* pDoc = GetDocument();				// ����ĵ���ָ��
	CImgProcess imgInput = pDoc->m_Image;		// �������
	if (imgInput.m_pBMIH->biBitCount != 24)		// ���ͼ����RGBͼ��
	{
		AfxMessageBox(L"����RGBͼ���޷�����");
		return;
	}
	CImgProcess imgOutput = imgInput;			// �������ʱ����
	imgInput.RGB2HSV(&imgOutput);				// RGB2HSV
	pDoc->m_Image = imgOutput;					// ��������ظ��ĵ���
	pDoc->SetModifiedFlag(true);
	pDoc->UpdateAllViews(NULL);
}

void CDIPView::OnColorHSV2RGB()
{
	CDIPDoc* pDoc = GetDocument();				// ����ĵ���ָ��
	CImgProcess imgInput = pDoc->m_Image;		// �������
	if (imgInput.m_pBMIH->biBitCount != 24)		// ���ͼ����24λͼ��
	{
		AfxMessageBox(L"����24λͼ���޷�����");
		return;
	}
	CImgProcess imgOutput = imgInput;			// �������ʱ����
	imgInput.HSV2RGB(&imgOutput);				// HSV2RGB
	pDoc->m_Image = imgOutput;					// ��������ظ��ĵ���
	pDoc->SetModifiedFlag(true);
	pDoc->UpdateAllViews(NULL);
}

void CDIPView::OnColorRGB2YUV()
{
	CDIPDoc* pDoc = GetDocument();				// ����ĵ���ָ��
	CImgProcess imgInput = pDoc->m_Image;		// �������
	if (imgInput.m_pBMIH->biBitCount != 24)		// ���ͼ����RGBͼ��
	{
		AfxMessageBox(L"����RGBͼ���޷�����");
		return;
	}
	CImgProcess imgOutput = imgInput;			// �������ʱ����
	imgInput.RGB2YUV(&imgOutput);				// RGB2YUV
	pDoc->m_Image = imgOutput;					// ��������ظ��ĵ���
	pDoc->SetModifiedFlag(true);
	pDoc->UpdateAllViews(NULL);
}

void CDIPView::OnColorYUV2RGB()
{
	CDIPDoc* pDoc = GetDocument();				// ����ĵ���ָ��
	CImgProcess imgInput = pDoc->m_Image;		// �������
	if (imgInput.m_pBMIH->biBitCount != 24)		// ���ͼ����24λͼ��
	{
		AfxMessageBox(L"����24λͼ���޷�����");
		return;
	}
	CImgProcess imgOutput = imgInput;			// �������ʱ����
	imgInput.YUV2RGB(&imgOutput);				// YUV2RGB
	pDoc->m_Image = imgOutput;					// ��������ظ��ĵ���
	pDoc->SetModifiedFlag(true);
	pDoc->UpdateAllViews(NULL);
}

void CDIPView::OnColorRGB2YIQ()
{
	CDIPDoc* pDoc = GetDocument();				// ����ĵ���ָ��
	CImgProcess imgInput = pDoc->m_Image;		// �������
	if (imgInput.m_pBMIH->biBitCount != 24)		// ���ͼ����RGBͼ��
	{
		AfxMessageBox(L"����RGBͼ���޷�����");
		return;
	}
	CImgProcess imgOutput = imgInput;			// �������ʱ����
	imgInput.RGB2YIQ(&imgOutput);				// RGB2YIQ
	pDoc->m_Image = imgOutput;					// ��������ظ��ĵ���
	pDoc->SetModifiedFlag(true);
	pDoc->UpdateAllViews(NULL);
}

void CDIPView::OnColorYIQ2RGB()
{
	CDIPDoc* pDoc = GetDocument();				// ����ĵ���ָ��
	CImgProcess imgInput = pDoc->m_Image;		// �������
	if (imgInput.m_pBMIH->biBitCount != 24)		// ���ͼ����24λͼ��
	{
		AfxMessageBox(L"����24λͼ���޷�����");
		return;
	}
	CImgProcess imgOutput = imgInput;			// �������ʱ����
	imgInput.YIQ2RGB(&imgOutput);				// YIQ2RGB
	pDoc->m_Image = imgOutput;					// ��������ظ��ĵ���
	pDoc->SetModifiedFlag(true);
	pDoc->UpdateAllViews(NULL);
}

void CDIPView::OnRecTemplate()
{
	//ģ��ƥ��
	CDIPDoc* pDoc = GetDocument();				// ����ĵ���ָ��
	CImgProcess imgInput = pDoc->m_Image;		// �������
	if (imgInput.m_pBMIH->biBitCount != 8)		// ���ͼ���ǻҶ�ͼ��
	{
		AfxMessageBox(L"����8-bpp�Ҷ�ͼ���޷�����");
		return;
	}
	CImgProcess imgOutput = imgInput;			// �������ʱ����
	CImgProcess TplImage;						// ģ��ͼ��
	CFileDialog dlg(TRUE, L"bmp", L"*.bmp");	// �����Ի������û�ѡ��ģ��ͼ��
	if (dlg.DoModal() == IDOK)
	{
		CString strPathName;
		strPathName = dlg.GetPathName();
		TplImage.AttachFromFile(strPathName);
	}
	else
		return;
	int nHeight = imgInput.GetHeight();
	int nWidth = imgInput.GetWidthPixel();
	int nTplHeight = TplImage.GetHeight();
	int nTplWidth = TplImage.GetWidthPixel();
	if (nTplHeight > nHeight || nTplWidth > nWidth)
	{
		// ��ʾ�û�
		MessageBox(L"ģ��ߴ����Դͼ��ߴ磡", L"ϵͳ��ʾ", MB_ICONINFORMATION | MB_OK);
		return;
	}
	BeginWaitCursor();							// ���Ĺ����״
	imgInput.TemplateMatch(&imgOutput,
		&TplImage);								// ����ģ��ƥ��
	pDoc->m_Image = imgOutput;					// ��������ظ��ĵ���
	pDoc->SetModifiedFlag(true);
	pDoc->UpdateAllViews(NULL);
	EndWaitCursor();							// �ָ������״
}

void CDIPView::OnFeaGraymat()
{
	//����Ҷȹ��־���
	CDIPDoc* pDoc = GetDocument();				// ����ĵ���ָ��
	CImgProcess imgInput = pDoc->m_Image;		// �������
	if (imgInput.m_pBMIH->biBitCount != 8)		// ���ͼ���ǻҶ�ͼ��
	{
		AfxMessageBox(L"����8-bpp�Ҷ�ͼ���޷�����");
		return;
	}
	POINT ptD1, ptD2;							//�趨�������λ�ù�ϵ
	/*  //ˮƽ�Ҷȹ��־���
		ptD1.x = 1;
		ptD1.y = 0;
		ptD2.x = -1;
		ptD2.y = 0;
	*/
	//+45�ȻҶȹ��־���
	ptD1.x = +1;
	ptD1.y = -1;
	ptD2.x = -1;
	ptD2.y = +1;
	//����Ҷȹ��־���
	vector<vector<int>> GrayMat = imgInput.GetGrayMatrix(ptD1, ptD2);
	CString str;
	int m = GrayMat.size();
	int n = GrayMat[0].size();
	//�����Ի�����ʾ�Ҷȹ��־���
	str.Format(L"{%d %d %d;%d %d %d;%d %d %d}",
		GrayMat[0][0], GrayMat[0][1], GrayMat[0][2],
		GrayMat[1][0], GrayMat[1][1], GrayMat[1][2],
		GrayMat[2][0], GrayMat[2][1], GrayMat[2][2]);
	AfxMessageBox(str);
}