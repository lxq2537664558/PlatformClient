#pragma once

//////////////////////////////////////////////////////////////////////////////////
#ifndef _SECURE_ATL 
#define _SECURE_ATL 1 
#endif

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN
#endif

#include "targetver.h"

#ifndef WINVER
#define WINVER 0x0501
#endif

#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0501
#endif

#ifndef _WIN32_WINDOWS
#define _WIN32_WINDOWS 0x0510
#endif

#ifndef _WIN32_IE
#define _WIN32_IE 0x0400
#endif

#define _ATL_ATTRIBUTES
#define _AFX_ALL_WARNINGS
#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS

//////////////////////////////////////////////////////////////////////////////////

//MFC �ļ�
#include <AfxWin.h>
#include <AfxExt.h>
#include <AfxCmn.h>
#include <AfxDisp.h>


//MFC �ļ�
#include <Nb30.h>
#include <AfxInet.h>

//////////////////////////////////////////////////////////////////////////////////
//ƽ̨�ļ�

//ƽ̨�ļ�
#include "..\..\ȫ�ֶ���\Platform.h"

//��������
#include "..\..\��Ϣ����\CMD_Commom.h"
#include "..\..\��Ϣ����\CMD_GameServer.h"
#include "..\..\��Ϣ����\CMD_LogonServer.h"

//��������
#include "..\..\��Ϣ����\IPC_GameFrame.h"

//����ļ�
#include "..\..\�������\ServiceCoreHead.h"
#include "..\..\���̿���\ProcessControlHead.h"

//����ļ�
#include "..\ͼ��ؼ�\WHImageHead.h"
#include "..\�������\DownLoadHead.h"
#include "..\����ؼ�\SkinControlHead.h"
#include "..\�û�����\UserServiceHead.h"
#include "..\ƽ̨����\PlatformDataHead.h"
#include "..\��Ϸ�ؼ�\ShareControlHead.h"
#include "..\��Ϸ����\GamePropertyHead.h"
#include "..\�������\AvatarControlHead.h"
#include "..\��Ϸ����\GameEngineHead.h"

//////////////////////////////////////////////////////////////////////////////////
//���Ӵ���

//��ý���
#pragma comment (lib,"Winmm.lib")

#ifndef _DEBUG
	#ifndef _UNICODE
		#pragma comment (lib,"../../���ӿ�/Ansi/WHImage.lib")
		#pragma comment (lib,"../../���ӿ�/Ansi/FGuilib.lib")
		#pragma comment (lib,"../../���ӿ�/Ansi/DownLoad.lib")
		#pragma comment (lib,"../../���ӿ�/Ansi/ServiceCore.lib")
		#pragma comment (lib,"../../���ӿ�/Ansi/SkinControl.lib")
		#pragma comment (lib,"../../���ӿ�/Ansi/GameProperty.lib")
		#pragma comment (lib,"../../���ӿ�/Ansi/ShareControl.lib")
		#pragma comment (lib,"../../���ӿ�/Ansi/PlatformData.lib")
		#pragma comment (lib,"../../���ӿ�/Ansi/AvatarControl.lib")
		#pragma comment (lib,"../../���ӿ�/Ansi/GameEngine.lib")
		#pragma comment (lib,"../../���ӿ�/Ansi/FGuimfcFactory.lib")	
	#else
		#pragma comment (lib,"../../���ӿ�/Unicode/WHImage.lib")
		#pragma comment (lib,"../../���ӿ�/Unicode/FGuilib.lib")
		#pragma comment (lib,"../../���ӿ�/Unicode/DownLoad.lib")
		#pragma comment (lib,"../../���ӿ�/Unicode/ServiceCore.lib")
		#pragma comment (lib,"../../���ӿ�/Unicode/SkinControl.lib")
		#pragma comment (lib,"../../���ӿ�/Unicode/GameProperty.lib")
		#pragma comment (lib,"../../���ӿ�/Unicode/ShareControl.lib")
		#pragma comment (lib,"../../���ӿ�/Unicode/PlatformData.lib")
		#pragma comment (lib,"../../���ӿ�/Unicode/AvatarControl.lib")
		#pragma comment (lib,"../../���ӿ�/Unicode/GameEngine.lib")
		#pragma comment (lib,"../../���ӿ�/Unicode/FGuimfcFactory.lib")	
	#endif
#else
	#ifndef _UNICODE
		#pragma comment (lib,"../../���ӿ�/Ansi/WHImageD.lib")
		#pragma comment (lib,"../../���ӿ�/Ansi/FGuilibD.lib")
		#pragma comment (lib,"../../���ӿ�/Ansi/DownLoadD.lib")
		#pragma comment (lib,"../../���ӿ�/Ansi/ServiceCoreD.lib")
		#pragma comment (lib,"../../���ӿ�/Ansi/SkinControlD.lib")
		#pragma comment (lib,"../../���ӿ�/Ansi/GamePropertyD.lib")
		#pragma comment (lib,"../../���ӿ�/Ansi/ShareControlD.lib")
		#pragma comment (lib,"../../���ӿ�/Ansi/PlatformDataD.lib")
		#pragma comment (lib,"../../���ӿ�/Ansi/AvatarControlD.lib")
		#pragma comment (lib,"../../���ӿ�/Ansi/GameEngineD.lib")
		#pragma comment (lib,"../../���ӿ�/Ansi/FGuimfcFactoryD.lib")	
	#else
		#pragma comment (lib,"../../���ӿ�/Unicode/WHImageD.lib")
		#pragma comment (lib,"../../���ӿ�/Unicode/FGuilibD.lib")
		#pragma comment (lib,"../../���ӿ�/Unicode/DownLoadD.lib")
		#pragma comment (lib,"../../���ӿ�/Unicode/ServiceCoreD.lib")
		#pragma comment (lib,"../../���ӿ�/Unicode/SkinControlD.lib")
		#pragma comment (lib,"../../���ӿ�/Unicode/GamePropertyD.lib")
		#pragma comment (lib,"../../���ӿ�/Unicode/ShareControlD.lib")
		#pragma comment (lib,"../../���ӿ�/Unicode/PlatformDataD.lib")
		#pragma comment (lib,"../../���ӿ�/Unicode/AvatarControlD.lib")
		#pragma comment (lib,"../../���ӿ�/Unicode/GameEngineD.lib")
		#pragma comment (lib,"../../���ӿ�/Unicode/FGuimfcFactoryD.lib")
	#endif
#endif

//////////////////////////////////////////////////////////////////////////////////