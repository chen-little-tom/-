
// FingerDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "Finger.h"
#include "FingerDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFingerDlg 对话框



CFingerDlg::CFingerDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_FINGER_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFingerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_Info,m_staticInfo);
	DDX_Control(pDX, IDC_STATIC_IMG_1, m_picCTRL1);
	DDX_Control(pDX, IDC_STATIC_IMG_2, m_picCTRL2);
	DDX_Text(pDX, IDC_EDIT_Name, m_name);
	DDX_Control(pDX, IDC_ZKFPENGX1, m_zkfpEng);
}

BEGIN_MESSAGE_MAP(CFingerDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_Step_1, &CFingerDlg::OnBnClickedButtonStep1)
	ON_BN_CLICKED(IDC_BUTTON_Step_5, &CFingerDlg::OnBnClickedButtonStep5)
	ON_BN_CLICKED(IDC_BUTTON_Step_2, &CFingerDlg::OnBnClickedButtonStep2)
	ON_BN_CLICKED(IDC_BUTTON_Step_3, &CFingerDlg::OnBnClickedButtonStep3)
	ON_BN_CLICKED(IDC_BUTTON_Step_4, &CFingerDlg::OnBnClickedButtonStep4)
	ON_BN_CLICKED(IDC_BUTTON_Step_6, &CFingerDlg::OnBnClickedButtonStep6)
	ON_BN_CLICKED(IDC_BUTTON_Step_7, &CFingerDlg::OnBnClickedButtonStep7)
	ON_BN_CLICKED(IDC_BUTTON_Step_8, &CFingerDlg::OnBnClickedButtonStep8)
	ON_BN_CLICKED(IDC_BUTTON_Step_9, &CFingerDlg::OnBnClickedButtonStep9)
	ON_BN_CLICKED(IDC_BUTTON_Step_10, &CFingerDlg::OnBnClickedButtonStep10)
	ON_BN_CLICKED(IDC_BUTTON_Step_11, &CFingerDlg::OnBnClickedButtonStep11)
	ON_BN_CLICKED(IDC_BUTTON_Step_12B, &CFingerDlg::OnBnClickedButtonStep12b)
	ON_BN_CLICKED(IDC_BUTTON_Step_12A, &CFingerDlg::OnBnClickedButtonStep12a)
	ON_BN_CLICKED(IDC_BUTTON_ADD_IMAGE, &CFingerDlg::OnBnClickedButtonAddImage)
	ON_BN_CLICKED(IDC_BUTTON_MATCH_IMAGE, &CFingerDlg::OnBnClickedButtonMatchImage)
	ON_BN_CLICKED(IDC_BUTTON_CONNECT, &CFingerDlg::OnBnClickedButtonConnect)
	ON_BN_CLICKED(IDC_BUTTON_CAPTURE, &CFingerDlg::OnBnClickedButtonCapture)
	ON_BN_CLICKED(IDC_BUTTON_REGISTER, &CFingerDlg::OnBnClickedButtonRegister)
	ON_BN_CLICKED(IDC_BUTTON_IDENTIFY, &CFingerDlg::OnBnClickedButtonIdentify)
	ON_BN_CLICKED(IDC_BUTTON_DISCONNECT, &CFingerDlg::OnBnClickedButtonDisconnect)
	ON_BN_CLICKED(IDC_BUTTON_DATABASE, &CFingerDlg::OnBnClickedButtonDatabase)
	ON_BN_CLICKED(IDCANCEL, &CFingerDlg::OnBnClickedCancel)
END_MESSAGE_MAP()

BEGIN_EVENTSINK_MAP(CFingerDlg, CDialog)
	ON_EVENT(CFingerDlg,IDC_ZKFPENGX1,8,OnImageReceivedZkfpengx,VTS_PBOOL)
END_EVENTSINK_MAP()


// CFingerDlg 消息处理程序

BOOL CFingerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CFingerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CFingerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CFingerDlg::OnImageReceivedZkfpengx(BOOL FAR AImageValid) {
	HDC hdc = this->GetDC()->m_hDC;   //获得显示设备上下文环境的句柄
	int x = 160;        //图像绘制区域左上角横坐标
	int y = 80;         //图像绘制区域左上角纵坐标
	int width = m_zkfpEng.get_ImageWidth();   //图像绘制区宽度
	int height = m_zkfpEng.get_ImageHeight(); //图像绘制区高度
	m_zkfpEng.PrintImageAt(int(hdc), x, y, width, height); //绘制图像

}

wchar_t* ToWideChar(char* str) {
	int num = MultiByteToWideChar(0, 0, str, -1, NULL, 0);
	wchar_t* wideStr = new wchar_t[num];
	MultiByteToWideChar(0, 0, str, -1, wideStr, num);
	return wideStr;
}


int ShowImageInCtrl(CStatic& picCtrl, char* filename) {
	CImage image;
	HRESULT hResult = image.Load(ToWideChar(filename));

	int width = image.GetWidth();
	int height = image.GetHeight();
	CRect rect;
	picCtrl.GetClientRect(&rect);
	CDC* pDc = picCtrl.GetWindowDC();
	SetStretchBltMode(pDc->m_hDC, STRETCH_HALFTONE);
	image.StretchBlt(pDc->m_hDC, rect, SRCCOPY);
	picCtrl.Invalidate(false);
	image.Destroy();
	picCtrl.ReleaseDC(pDc);
	return 0;
}

void CFingerDlg::OnBnClickedButtonStep1()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CFingerDlg::OnBnClickedButtonStep2()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CFingerDlg::OnBnClickedButtonStep3()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CFingerDlg::OnBnClickedButtonStep4()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CFingerDlg::OnBnClickedButtonStep5()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CFingerDlg::OnBnClickedButtonStep6()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CFingerDlg::OnBnClickedButtonStep7()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CFingerDlg::OnBnClickedButtonStep8()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CFingerDlg::OnBnClickedButtonStep9()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CFingerDlg::OnBnClickedButtonStep10()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CFingerDlg::OnBnClickedButtonStep11()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CFingerDlg::OnBnClickedButtonStep12a()
{
	// TODO: 在此添加控件通知处理程序代码
}

void CFingerDlg::OnBnClickedButtonStep12b()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CFingerDlg::OnBnClickedButtonAddImage()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CFingerDlg::OnBnClickedButtonMatchImage()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CFingerDlg::OnBnClickedButtonConnect()
{
	// TODO: 在此添加控件通知处理程序代码
	int isConnected = m_zkfpEng.InitEngine();
	if (isConnected == 0) {
		GetDlgItem(IDC_BUTTON_CONNECT)->EnableWindow(FALSE);
		MessageBox(_T("采集器连接成功."), _T("提示:"));  //采集器连接成功
	}
	else {
		MessageBox(_T("未能成功连接，请重试！"), _T("提示:"));  //采集器连接失败
	}
	
}


void CFingerDlg::OnBnClickedButtonCapture()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CFingerDlg::OnBnClickedButtonRegister()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CFingerDlg::OnBnClickedButtonIdentify()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CFingerDlg::OnBnClickedButtonDisconnect()
{
	// TODO: 在此添加控件通知处理程序代码
	m_zkfpEng.EndEngine();
	GetDlgItem(IDC_BUTTON_CONNECT)->EnableWindow(TRUE);
}


void CFingerDlg::OnBnClickedButtonDatabase()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CFingerDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}
