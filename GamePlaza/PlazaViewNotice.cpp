#include "Stdafx.h"
#include "PlazaViewNotice.h"
#include "PlatformFrame.h"

//////////////////////////////////////////////////////////////////////////////////

//��ʱ��
#define  IDE_EVENT_MOVE			1000		//�ƶ�����

//////////////////////////////////////////////////////////////////////////////////

//�ı�����
const TCHAR * szLabelNoticeText = TEXT( "LabelNoticeText" );
const TCHAR * szNoticeText = 
	TEXT( "��ϲ���JD...��ֵ500.00Ԫ�ɹ�" );

//////////////////////////////////////////////////////////////////////////////////

BEGIN_MESSAGE_MAP(CPlazaViewNotice, CFGuiWnd)

	//ϵͳ��Ϣ
	ON_WM_SIZE()
	ON_WM_TIMER()
	ON_WM_CREATE()

END_MESSAGE_MAP()

//////////////////////////////////////////////////////////////////////////////////

//���캯��
CPlazaViewNotice::CPlazaViewNotice()
{
	m_nFixedWidth = 300;
	m_nFixedHeight = 20;

	m_nCurrentX = 0;
	m_nCurrentY = 0;
	m_nCurrentW = 0;

	m_nMainWidth = 0;
	m_nSumWidth = 0;

	m_nMoveUint = 2;
}

//��������
CPlazaViewNotice::~CPlazaViewNotice()
{

}

	//���ӹ���
void CPlazaViewNotice::AddNotice(CContainerUI * pParent, TCHAR * szNotice)
{
	//������ǩ
	CLabelUI * pLabel = (CLabelUI *) CLabelUI::Create(&m_PaintManager,pParent,TEXT(""));
	if( pLabel==NULL ) return;

	//�������
	m_wndNoticeArray.Add(pLabel);

	//�����ı�;
	pLabel->SetFont(3);
	pLabel->SetTextColor(0xFFFFC76B);
	pLabel->SetText(szNotice);

	//����λ��
	pLabel->SetPos(m_nCurrentX,m_nCurrentY);
	m_nCurrentX+=m_nFixedWidth;

	//���ø߿�
	pLabel->SetFixedWidth(m_nCurrentX+m_nFixedWidth);
	pLabel->SetFixedHeight(m_nCurrentY+m_nFixedHeight);

	//��󳤶�
	m_nMaxCount = m_wndNoticeArray.GetCount();
	m_nSumWidth += m_nFixedWidth;
}


//��ʼ����
void CPlazaViewNotice::InitControlUI()
{
	//��ȡ����
	CContainerUI * pParent = static_cast<CContainerUI *>(m_PaintManager.GetRoot());
	
	//��������
	AddNotice(pParent, TEXT( "��ϲ���JD...��ֵ500.00Ԫ�ɹ�" ) );
	AddNotice(pParent, TEXT( "��ϲ���wcj...��ֵ2000.00Ԫ�ɹ�" ) );
	AddNotice(pParent, TEXT( "��ϲ���Kim...��ֵ100.00Ԫ�ɹ�" ) );
	AddNotice(pParent, TEXT( "��ϲ���Joy...��ֵ500.00Ԫ�ɹ�" ) );
	AddNotice(pParent, TEXT( "��ϲ��Ҵ�...��ֵ1000.00Ԫ�ɹ�" ) );
	AddNotice(pParent, TEXT( "��ϲ���Jel...��ֵ1300.00Ԫ�ɹ�" ) );
	
	//��ʼ��λ��
	m_nCurrentX = 0;
	m_nCurrentY = 0;
	m_nCurrentW = m_nSumWidth;

	//��ʱ��
	SetTimer(IDE_EVENT_MOVE,50,NULL);

}

//��Ϣ����
void CPlazaViewNotice::Notify(TNotifyUI &  msg)
{
	CControlUI * pControlUI = msg.pSender;

	//����¼�
	if (lstrcmp(msg.sType, TEXT("click")) == 0)
	{
		// �����ֹͣ
	}
}

//ʱ����Ϣ
VOID CPlazaViewNotice::OnTimer(UINT nIDEvent)
{
	if(IDE_EVENT_MOVE==nIDEvent) 
	{
		//���¹�λ
		if(m_nCurrentW<0)
		{
			m_nCurrentW = m_nSumWidth;
			m_nCurrentX = m_nMainWidth;
			for(int i=0; i<m_nMaxCount; i++)
			{
				CLabelUI * pLabel = m_wndNoticeArray[i];
				if (pLabel!=NULL)
				{
					pLabel->SetPos(m_nCurrentX,m_nCurrentY);
					pLabel->SetFixedWidth(m_nCurrentX+m_nFixedWidth);
					pLabel->SetFixedHeight(m_nCurrentY+m_nFixedHeight);
				}
				m_nCurrentX += m_nFixedWidth;
			}
			return;
		}

		//�����ƶ�
		if(m_nMaxCount!=0)
		{
			m_nCurrentW -= m_nMoveUint;
			int nFristPosX = m_wndNoticeArray[0]->GetX();
			for(int i=0; i<m_nMaxCount; i++)
			{
				CLabelUI * pLabel = m_wndNoticeArray[i];
				if (pLabel!=NULL)
				{
					nFristPosX -= m_nMoveUint;
					pLabel->SetPos(nFristPosX,m_nCurrentY);
					pLabel->SetFixedWidth(nFristPosX+m_nFixedWidth);
					pLabel->SetFixedHeight(m_nCurrentY+m_nFixedHeight);
					nFristPosX += m_nFixedWidth;
				}
			}
		}
	}

	__super::OnTimer(nIDEvent);
}

//λ����Ϣ
VOID CPlazaViewNotice::OnSize(UINT nType, INT cx, INT cy)
{
	__super::OnSize(nType, cx, cy);
}

//������Ϣ
INT CPlazaViewNotice::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (__super::OnCreate(lpCreateStruct) == -1)
		return -1;

	//������Դ
	CPngImage ImageBack;
	ImageBack.LoadImage(GetModuleHandle(PLATFORM_RESOURCE_DLL_NAME),TEXT("PLAZA_NOTICE_BK"));

	//���ô�С
	CSize SizeWindow(ImageBack.GetWidth(),ImageBack.GetHeight());
	SetWindowPos(NULL, 0, 0,SizeWindow.cx,SizeWindow.cy,SWP_NOZORDER|SWP_NOMOVE|SWP_NOREDRAW);

	//������С
	m_nMainWidth = ImageBack.GetWidth();

	return 0;
}