
// MFC_VisionView.cpp : CMFC_VisionView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "MFC_Vision.h"
#endif

#include "MFC_VisionDoc.h"
#include "MFC_VisionView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC_VisionView

IMPLEMENT_DYNCREATE(CMFC_VisionView, CView)

BEGIN_MESSAGE_MAP(CMFC_VisionView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFC_VisionView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMFC_VisionView 생성/소멸

CMFC_VisionView::CMFC_VisionView()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CMFC_VisionView::~CMFC_VisionView()
{
}

BOOL CMFC_VisionView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMFC_VisionView 그리기

void CMFC_VisionView::OnDraw(CDC* /*pDC*/)
{
	CMFC_VisionDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CMFC_VisionView 인쇄


void CMFC_VisionView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFC_VisionView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMFC_VisionView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMFC_VisionView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CMFC_VisionView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFC_VisionView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFC_VisionView 진단

#ifdef _DEBUG
void CMFC_VisionView::AssertValid() const
{
	CView::AssertValid();
}

void CMFC_VisionView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC_VisionDoc* CMFC_VisionView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC_VisionDoc)));
	return (CMFC_VisionDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFC_VisionView 메시지 처리기
