
// FingerDlg.h: 头文件
//

#pragma once
#include "CZKFPEngX.h"

// CFingerDlg 对话框
class CFingerDlg : public CDialogEx
{
// 构造
public:
	CFingerDlg(CWnd* pParent = nullptr);// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FINGER_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;
	CStatic m_staticInfo;
	CStatic m_picCTRL1;
	CStatic m_picCTRL2;
	CString m_name;
	CZKFPEngX m_zkfpEng;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	DECLARE_EVENTSINK_MAP()
	afx_msg void OnImageReceivedZkfpengx(BOOL FAR AImageValid);

public:
	afx_msg void OnBnClickedButtonStep1();
	afx_msg void OnBnClickedButtonStep5();
	afx_msg void OnBnClickedButtonStep2();
	afx_msg void OnBnClickedButtonStep3();
	afx_msg void OnBnClickedButtonStep4();
	afx_msg void OnBnClickedButtonStep6();
	afx_msg void OnBnClickedButtonStep7();
	afx_msg void OnBnClickedButtonStep8();
	afx_msg void OnBnClickedButtonStep9();
	afx_msg void OnBnClickedButtonStep10();
	afx_msg void OnBnClickedButtonStep11();
	afx_msg void OnBnClickedButtonStep12a();
	afx_msg void OnBnClickedButtonStep12b();
	afx_msg void OnBnClickedButtonAddImage();
	afx_msg void OnBnClickedButtonMatchImage();
	afx_msg void OnBnClickedButtonConnect();
	afx_msg void OnBnClickedButtonCapture();
	afx_msg void OnBnClickedButtonRegister();
	afx_msg void OnBnClickedButtonIdentify();
	afx_msg void OnBnClickedButtonDisconnect();
	afx_msg void OnBnClickedButtonDatabase();
	afx_msg void OnBnClickedCancel();
};
