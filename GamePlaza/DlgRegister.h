#ifndef DLG_REGISTER_HEAD_FILE
#define DLG_REGISTER_HEAD_FILE

#pragma once

#include "Stdafx.h"
#include "Resource.h"
#include "WndValidateCode.h"

//////////////////////////////////////////////////////////////////////////////////

//ע�ᴰ��
class CDlgRegister : public CFGuiDialog
{
	//��֤����
public:
	bool							m_bQueryVerifyCode;					//��ѯ��֤��
	bool							m_bVerifyIndividual;				//��֤����
	WORD							m_wVerifyMask;						//У������							

	//��������
public:
	WORD							m_wFaceID;							//ͷ���ʶ
	BYTE							m_cbGender;							//�û��Ա�
	TCHAR							m_szAccounts[LEN_ACCOUNTS];			//ע���ʺ�
	TCHAR							m_szNickName[LEN_NICKNAME];			//ע���ǳ�
	TCHAR							m_szSpreader[LEN_ACCOUNTS];			//�Ƽ��ʺ�
	TCHAR							m_szLogonPass[LEN_PASSWORD];		//��¼����
	TCHAR							m_szInsurePass[LEN_PASSWORD];		//��������
	TCHAR							m_szPassPortID[LEN_PASS_PORT_ID];	//֤������
	TCHAR							m_szCompellation[LEN_COMPELLATION];	//��ʵ����
	TCHAR							m_szVerifyCode[LEN_VERIFY_CODE];	//��֤��

	//���ñ���
protected:
	BYTE							m_cbRemPassword;					//��ס����
	BYTE							m_cbLogonPassLevel;					//����ǿ��

	//�ؼ�����
protected:
	CBrush							m_brBrush;							//������ˢ
	CSkintDPI                       m_SkinDPI;                          //����DPI
	CFaceItemView					m_FaceItemView;						//ͷ����ͼ

	//�������
protected:
	CSkinLayered					m_SkinLayered;						//�ֲ㴰��
	CWndValidateCode				m_WndValidateCode;					//��֤�ؼ�
	CFaceSelectControlHelper		m_FaceSelectControl;				//ͷ��ѡ��

	//��������
public:
	//���캯��
	CDlgRegister();
	//��������
	virtual ~CDlgRegister();

	//���غ���
public:
	//�ؼ���
	virtual VOID DoDataExchange(CDataExchange * pDX);
	//��Ϣ����
	virtual BOOL PreTranslateMessage(MSG * pMsg);
	//���ú���
	virtual BOOL OnInitDialog();
	//ȷ������
	virtual VOID OnOK();
	//ȡ������
	virtual VOID OnCancel();

	//���ܺ���
public:
	//��������
	WORD ConstructRegisterPacket(BYTE cbBuffer[], WORD wBufferSize, BYTE cbValidateFlags);
	//У����
	VOID OnVerifypIndividualResult(WORD wVerifyMask,bool bVerifyPassage,LPCTSTR pszErrorMsg=NULL);
	//��ѯ��֤���
	VOID OnQueryVerifyCodeResult(LPCTSTR pszVerifyCode, UINT nMaxCount);

	//���غ���
public:
	//Ƥ������
	virtual LPCTSTR GetSkinFile() { return TEXT("DlgRegister.xml"); } 
	//��ʼ�ؼ�
	virtual void InitControlUI();
	//��Ϣ����
    virtual void Notify(TNotifyUI &  msg);

	//�滭�ӿ�
public:
	//�����滭
	virtual void OnEndPaintWindow(HDC hDC);

	//��������
private:
	//��ȡ��Ϣ
	bool GetInformation();
	//��֤����
	VOID PerformVerifyIndividual(WORD wVerifyMask);
	//��ѯ��֤��
	VOID PerformQueryVerifyCode();
	//��ȡ�ַ�
	VOID GetControlString(CControlUI * pControlUI,TCHAR szString[], WORD wMaxCount);

	//��Ϣ����
public:
	//�رհ�ť
	VOID OnBnClickedQuit();
	//��������
	VOID OnEnChangeLogonPass();
	//ͷ��ѡ��
	VOID OnBnClickedSelectFace();
	//������֤
	VOID OnBnClickedChangeValidate();
	//ͬ������
	VOID OnBnClickedAgrrArticle();

	//ϵͳ��Ϣ
protected:
	//�滭����
	BOOL OnEraseBkgnd(CDC * pDC);
	//�ؼ���ɫ
	HBRUSH OnCtlColor(CDC * pDC, CWnd * pWnd, UINT nCtlColor);

	DECLARE_MESSAGE_MAP()
};

//////////////////////////////////////////////////////////////////////////////////

#endif