#ifndef SKIN_CONTROL_HEAD_FILE
#define SKIN_CONTROL_HEAD_FILE

//////////////////////////////////////////////////////////////////////////////////
//�����ļ�

#include <afxtempl.h>

//ƽ̨�ļ�
#include "..\..\ȫ�ֶ���\Platform.h"

//����ļ�
#include "..\ͼ��ؼ�\WHImageHead.h"
#include "..\..\�������\ServiceCoreHead.h"
#include "..\ͼ�ι���\FGuimfcFactoryHead.h"

//////////////////////////////////////////////////////////////////////////////////
//��������

//��������
#ifndef SKIN_CONTROL_CLASS
	#ifdef  SKIN_CONTROL_DLL
		#define SKIN_CONTROL_CLASS _declspec(dllexport)
	#else
		#define SKIN_CONTROL_CLASS _declspec(dllimport)
	#endif
#endif

//ģ�鶨��
#ifndef _DEBUG
	#define SKIN_CONTROL_DLL_NAME	TEXT("SkinControl.dll")			//�������
#else
	#define SKIN_CONTROL_DLL_NAME	TEXT("SkinControlD.dll")		//�������
#endif

//////////////////////////////////////////////////////////////////////////////////
//�����ļ�

#ifndef SKIN_CONTROL_DLL
	#include "SkinEdit.h"
	#include "SkinMenu.h"
	#include "SkinDpi.h"
	#include "SkinDialog.h"
	#include "SkinButton.h"
	#include "SkinTabCtrl.h"
	#include "SkinSplitter.h"
	#include "SkinComboBox.h"
	#include "SkinEncircle.h"
	#include "SkinListCtrl.h"
	#include "SkinRichEdit.h"
	#include "SkinScrollBar.h"
	#include "SkinHyperLink.h"
	#include "SkinRenderManager.h"
	#include "SkinResourceManager.h"
#endif

//////////////////////////////////////////////////////////////////////////////////

#endif