
// MFC_VisionView.cpp : CMFC_VisionView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
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
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFC_VisionView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMFC_VisionView ����/�Ҹ�

CMFC_VisionView::CMFC_VisionView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CMFC_VisionView::~CMFC_VisionView()
{
}

BOOL CMFC_VisionView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CMFC_VisionView �׸���

void CMFC_VisionView::OnDraw(CDC* /*pDC*/)
{
	CMFC_VisionDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CMFC_VisionView �μ�


void CMFC_VisionView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFC_VisionView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CMFC_VisionView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CMFC_VisionView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
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


// CMFC_VisionView ����

#ifdef _DEBUG
void CMFC_VisionView::AssertValid() const
{
	CView::AssertValid();
}

void CMFC_VisionView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC_VisionDoc* CMFC_VisionView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC_VisionDoc)));
	return (CMFC_VisionDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFC_VisionView �޽��� ó����
