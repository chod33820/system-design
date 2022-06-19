
#include "stdafx.h"
#include "math.h"
#include "220404_2017132036_test.h"
#include "220404_2017132036_testDlg.h"
#include "afxdialogex.h"
#include "windows.h"
#include <iostream>
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <string>

using namespace cv;
using namespace std;

// ++ =============================================================
// >> AXL(AjineXtek Library) ���� Header���� ���Խ�ŵ�ϴ�.
// �� [CAUTION] ������ �����Ͽ� �ٸ� ��ġ���� ����� ������� ������ �ʿ��մϴ�.
// ---------------------------------------------------------------
#include "C:/Program Files (x86)/EzSoftware UC/AXL(Library)/C, C++/AXL.h"
#include "C:/Program Files (x86)/EzSoftware UC/AXL(Library)/C, C++/AXM.h"
#include "C:/Program Files (x86)/EzSoftware UC/AXL(Library)/C, C++/AXDev.h"
#include "C:/Program Files (x86)/EzSoftware UC/AXL(Library)/C, C++/AXHS.h" 

// ++ =============================================================
// >> AXL(AjineXtek Library) ���� Library������ Link��ŵ�ϴ�.
// �� [CAUTION] ������ �����Ͽ� �ٸ� ��ġ���� ����� ������� ������ �ʿ��մϴ�.
// ----------------------------------------------------------------
#ifdef _M_X64
#pragma comment(lib, "C:/Program Files (x86)/EzSoftware UC/AXL(Library)/Library/64Bit/AxL.lib")
#else
#pragma comment(lib, "C:/Program Files (x86)/EzSoftware UC/AXL(Library)/Library/32Bit/AxL.lib")
#endif 

// 220404_2017132036_testDlg.cpp : ���� ����
//



#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define TM_DISPLAY 100
#define TM_X_HOME_INFO 101
#define TM_Y_HOME_INFO 102
#define DEFAULT_VEL 30
#define DEFAULT_ACC 40
#define DEFAULT_DEC 40
#define DEFAULT_HOME_VEL_FIRST 10
#define DEFAULT_HOME_ACC_FIRST 40
#define DEFAULT_AXIS_NUMBER_X 0
#define DEFAULT_AXIS_NUMBER_Y 1
#define MARGIN 30
#define GAIN_MAIN_ADDRESS_P 0x3100
#define GAIN_MAIN_ADDRESS_D 0x3101
#define GAIN_MAIN_ADDRESS_I 0x3102
#define GAIN_SUB_ADDRESS 0
#define DEFAULT_UNIT 1250 //���� 1250 ������ 10���� ����
#define DEFAULT_PULSE 1048576
#define DEFAULT_REVISION_X 199.1
#define DEFAULT_REVISION_Y 194.7
#define DEFAULT_INPUT 1.0

// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	CFont m_tFont1;
	CBrush m_tBrush;

	// �����Դϴ�.
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();

	//m_tFont1.CreateFont(30, 10, 0, 0, 1000, 1, 0, 0, 0, OUT_DEFAULT_PRECIS, 0, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, _T("����"));
	//GetDlgItem(IDC_STATIC1)->SetFont(&m_tFont1);


};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CAboutDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CMy220404_2017132036_testDlg ��ȭ ����



CMy220404_2017132036_testDlg::CMy220404_2017132036_testDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMy220404_2017132036_testDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy220404_2017132036_testDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SLI_Y, m_sliY);
	DDX_Control(pDX, IDC_SLI_X, m_sliX);
	DDX_Control(pDX, IDC_EDT_X_INPUT_VEL, m_edtXInputVel);
	DDX_Control(pDX, IDC_EDT_X_INPUT_ACC, m_edtXInputAcc);
	DDX_Control(pDX, IDC_EDT_X_INPUT_DEC, m_edtXInputDec);
	DDX_Control(pDX, IDC_STC_X_COMMAND_POS, m_stcXCommPos);
	DDX_Control(pDX, IDC_STC_X_FEEDBACK_POS, m_stcXFeedPos);
	DDX_Control(pDX, IDC_STC_X_FEEDBACK_VEL, m_stcXFeedVel);
	DDX_Control(pDX, IDC_CHK_X_SERVO_ON, m_chkXServoOn);
	DDX_Control(pDX, IDC_CHK_X_IN_MOTION, m_chkXInMotion);
	DDX_Control(pDX, IDC_CHK_X_ALARM, m_chkXAlarm);
	DDX_Control(pDX, IDC_CHK_X_HOME_SIGNAL, m_chkXHomeSignal);
	DDX_Control(pDX, IDC_CHK_X_IN_POSITION, m_chkXInPosition);
	DDX_Control(pDX, IDC_CHK_X_LIMIT_P, m_chkXLimitP);
	DDX_Control(pDX, IDC_CHK_X_LIMIT_N, m_chkXLimitN);
	DDX_Control(pDX, IDC_CHK_X_EMG, m_chkXEmg);
	DDX_Control(pDX, IDC_PRG_X_HOME_RATE, m_prgXHomeRate);
	DDX_Control(pDX, IDC_STC_X_P, m_stcXP);
	DDX_Control(pDX, IDC_STC_X_I, m_stcXI);
	DDX_Control(pDX, IDC_STC_X_D, m_stcXD);
	DDX_Control(pDX, IDC_EDT_Y_INPUT_VEL, m_edtYInputVel);
	DDX_Control(pDX, IDC_EDT_Y_INPUT_ACC, m_edtYInputAcc);
	DDX_Control(pDX, IDC_EDT_Y_INPUT_DEC, m_edtYInputDec);
	DDX_Control(pDX, IDC_STC_Y_COMMAND_POS, m_stcYCommPos);
	DDX_Control(pDX, IDC_STC_Y_FEEDBACK_POS, m_stcYFeedPos);
	DDX_Control(pDX, IDC_STC_Y_FEEDBACK_VEL, m_stcYFeedVel);
	DDX_Control(pDX, IDC_CHK_Y_SERVO_ON, m_chkYServoOn);
	DDX_Control(pDX, IDC_CHK_Y_IN_MOTION, m_chkYInMotion);
	DDX_Control(pDX, IDC_CHK_Y_ALARM, m_chkYAlarm);
	DDX_Control(pDX, IDC_CHK_Y_HOME_SIGNAL, m_chkYHomeSignal);
	DDX_Control(pDX, IDC_CHK_Y_IN_POSTION, m_chkYInPosition);
	DDX_Control(pDX, IDC_CHK_Y_LIMIT_P, m_chkYLimitP);
	DDX_Control(pDX, IDC_CHK_Y_LIMIT_N, m_chkYLimitN);
	DDX_Control(pDX, IDC_CHK_Y_EMG, m_chkYEmg);
	DDX_Control(pDX, IDC_PRG_Y_HOME_RATE, m_prgYHomeRate);
	DDX_Control(pDX, IDC_STC_Y_P, m_stcYP);
	DDX_Control(pDX, IDC_STC_Y_I, m_stcYI);
	DDX_Control(pDX, IDC_STC_Y_D, m_stcYD);
	DDX_Control(pDX, IDC_EDT_X_MOVE_POS, m_edtXMovePos);
	DDX_Control(pDX, IDC_EDT_Y_MOVE_POS, m_edtYMovePos);
	DDX_Control(pDX, IDC_BTN_X_ALARM_CLEAR, m_btnXAlarmClear);
	DDX_Control(pDX, IDC_BTN_X_HOME_SEARCH, m_btnXHomeSearch);
	DDX_Control(pDX, IDC_BTN_X_POS_CLEAR, m_btnXPosClear);
	DDX_Control(pDX, IDC_BTN_X_SSTOP, m_btnXSStop);
	DDX_Control(pDX, IDC_BTN_X_ESTOP, m_btnXEStop);
	DDX_Control(pDX, IDC_CHK_Y_ALARM_CLEAR, m_btnYAlarmClear);
	DDX_Control(pDX, IDC_BTN_Y_HOME_SEARCH, m_btnYHomeSearch);
	DDX_Control(pDX, IDC_BTN_Y_POS_CLEAR, m_btnYPosClear);
	DDX_Control(pDX, IDC_BTN_Y_SSTOP, m_btnYSStop);
	DDX_Control(pDX, IDC_BTN_Y_ESTOP, m_btnYEStop);
	DDX_Control(pDX, IDC_BTN_LOAD_FILE, m_btnLoadFile);
	DDX_Control(pDX, IDC_BTN_BOTH_HOME_SEARCH, m_btnBothHomeSearch);
	DDX_Control(pDX, IDC_BTN_MOVE_ZERO_POS, m_btnMoveZeroPos);
	DDX_Control(pDX, IDC_BTN_BOTH_ESTOP, m_btnBothEStop);
	DDX_Control(pDX, IDC_PC_STAGE, m_pcstage);
	DDX_Control(pDX, IDC_BTN_POS_MOVE, m_btnPosMove);
	DDX_Control(pDX, IDC_EDIT1, inputnum);
	//DDX_Control(pDX, IDC_MODE, mode);
	DDX_Control(pDX, IDC_CHECK2, vmode);
	DDX_Control(pDX, IDC_VISION, _vision);
}

BEGIN_MESSAGE_MAP(CMy220404_2017132036_testDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//	ON_BN_CLICKED(X_stage, &CMy220404_2017132036_testDlg::OnBnClickedstage)
	ON_BN_CLICKED(IDC_CHK_X_SERVO_ON, &CMy220404_2017132036_testDlg::OnBnClickedChkXServoOn)
	ON_BN_CLICKED(IDC_BTN_X_ALARM_CLEAR, &CMy220404_2017132036_testDlg::OnBnClickedBtnXAlarmClear)
	ON_BN_CLICKED(IDC_BTN_X_HOME_SEARCH, &CMy220404_2017132036_testDlg::OnBnClickedBtnXHomeSearch)
	ON_BN_CLICKED(IDC_BTN_X_POS_CLEAR, &CMy220404_2017132036_testDlg::OnBnClickedBtnXPosClear)
	ON_BN_CLICKED(IDC_BTN_X_SSTOP, &CMy220404_2017132036_testDlg::OnBnClickedBtnXSstop)
	ON_BN_CLICKED(IDC_BTN_X_ESTOP, &CMy220404_2017132036_testDlg::OnBnClickedBtnXEstop)
	ON_BN_CLICKED(IDC_CHK_Y_SERVO_ON, &CMy220404_2017132036_testDlg::OnBnClickedChkYServoOn)
	ON_BN_CLICKED(IDC_CHK_Y_ALARM_CLEAR, &CMy220404_2017132036_testDlg::OnBnClickedChkYAlarmClear)
	ON_BN_CLICKED(IDC_BTN_Y_HOME_SEARCH, &CMy220404_2017132036_testDlg::OnBnClickedBtnYHomeSearch)
	ON_BN_CLICKED(IDC_BTN_Y_POS_CLEAR, &CMy220404_2017132036_testDlg::OnBnClickedBtnYPosClear)
	ON_BN_CLICKED(IDC_BTN_Y_SSTOP, &CMy220404_2017132036_testDlg::OnBnClickedBtnYSstop)
	ON_BN_CLICKED(IDC_BTN_Y_ESTOP, &CMy220404_2017132036_testDlg::OnBnClickedBtnYEstop)
	ON_BN_CLICKED(IDC_BTN_POS_MOVE, &CMy220404_2017132036_testDlg::OnBnClickedBtnPosMove)
	ON_WM_CLOSE()
	ON_WM_DESTROY()
	ON_WM_HSCROLL()
	ON_WM_LBUTTONDOWN()
	ON_WM_TIMER()
	ON_WM_VSCROLL()
	ON_BN_CLICKED(IDC_BTN_LOAD_FILE, &CMy220404_2017132036_testDlg::OnBnClickedBtnLoadFile)
	ON_BN_CLICKED(IDC_BTN_BOTH_HOME_SEARCH, &CMy220404_2017132036_testDlg::OnBnClickedBtnBothHomeSearch)
	ON_BN_CLICKED(IDC_BTN_MOVE_ZERO_POS, &CMy220404_2017132036_testDlg::OnBnClickedBtnMoveZeroPos)
	ON_BN_CLICKED(IDC_BTN_BOTH_ESTOP, &CMy220404_2017132036_testDlg::OnBnClickedBtnBothEstop)
	//ON_BN_CLICKED(IDC_RADIO1, &CMy220404_2017132036_testDlg::OnBnClickedRadio1)
	//ON_BN_CLICKED(IDC_RADIO_RECT2, &CMy220404_2017132036_testDlg::OnBnClickedRadioRect2)
	ON_BN_CLICKED(IDC_RADIO_PTP, &CMy220404_2017132036_testDlg::OnBnClickedRadioPtp)
	ON_BN_CLICKED(IDC_RADIO_RECT, &CMy220404_2017132036_testDlg::OnBnClickedRadioRect)
	ON_BN_CLICKED(IDC_RADIO_HEART, &CMy220404_2017132036_testDlg::OnBnClickedRadioHeart)
	ON_BN_CLICKED(IDC_RADIO_STAR, &CMy220404_2017132036_testDlg::OnBnClickedRadioStar)
	ON_BN_CLICKED(IDC_RADIO_CP, &CMy220404_2017132036_testDlg::OnBnClickedRadioCp)
	ON_BN_CLICKED(IDC_RADIO_SIGN, &CMy220404_2017132036_testDlg::OnBnClickedRadioSign)
	ON_BN_CLICKED(IDC_RADIO_VISION, &CMy220404_2017132036_testDlg::OnBnClickedRadioVision)
	ON_BN_CLICKED(IDC_RADIO_PENTAGON, &CMy220404_2017132036_testDlg::OnBnClickedRadioPentagon)
	ON_BN_CLICKED(IDC_CHECK2, &CMy220404_2017132036_testDlg::OnBnClickedCheck2)
	ON_WM_KEYDOWN()
	ON_BN_CLICKED(IDC_VISION, &CMy220404_2017132036_testDlg::OnBnClickedVision)
END_MESSAGE_MAP()


// CMy220404_2017132036_testDlg �޽��� ó����

BOOL CMy220404_2017132036_testDlg::OnInitDialog()
{

	DWORD dwRetCode = 0;
	DWORD dwOnOff = 0;
	CString strResult;
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// �� ��ȭ ������ �������� �����մϴ�. ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	CDialog::OnInitDialog();

	SetIcon(m_hIcon, TRUE);
	SetIcon(m_hIcon, FALSE);

	InitState();

	m_chkXServoOn.SetCheck(BST_CHECKED);
	m_chkYServoOn.SetCheck(BST_CHECKED);

	OnBnClickedChkXServoOn();
	OnBnClickedChkYServoOn();

	Sleep(500);
	OnBnClickedBtnXHomeSearch();
	OnBnClickedBtnYHomeSearch();
	dwOnOff = IsDlgButtonChecked(IDC_CHK_X_SERVO_ON);
	dwRetCode = AxmSignalServoOn(m_lAxisNoX, dwOnOff);
	if (dwRetCode != AXT_RT_SUCCESS)
	{
		strResult = TranslateAxmResult(dwRetCode);
		AfxMessageBox("X Axis AxmSignalServoOn fail.\nError Msg : " + strResult);
	}
	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CMy220404_2017132036_testDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�. ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CMy220404_2017132036_testDlg::OnPaint()
{
	CString strPosX, strPosY, strEndPos;
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ

		SendMessage(WM_ICONERASEBKGND,
			reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
		CClientDC dc(this);

		// XY Stage ����� �׸��ϴ�.
		dc.Rectangle(&m_rectStage);

		// XY Stage�� ���� ���鿡�� MARGIN����ŭ ������ ��ġ�� Y�� ���ؼ��� �׸��ϴ�.
		dc.MoveTo(m_rectStage.left + MARGIN, m_rectStage.top + MARGIN);
		dc.LineTo(m_rectStage.left + MARGIN, m_rectStage.bottom - MARGIN);

		// XY Stage�� �ϴ� ���鿡�� MARGIN����ŭ ������ ��ġ�� X�� ���ؼ��� �׸��ϴ�.
		dc.MoveTo(m_rectStage.left + MARGIN, m_rectStage.bottom - MARGIN);
		dc.LineTo(m_rectStage.right - MARGIN, m_rectStage.bottom - MARGIN);

		// �� ���� ������(0,0)�� ǥ���մϴ�.
		dc.TextOut(m_rectStage.left + MARGIN - 15, m_rectStage.bottom - MARGIN + 5,
			"(0, 0)");

		// X���� �� ����(?, 0)�� ǥ���մϴ�.
		strEndPos.Format("(%d, 0)", (int)((double)((m_rectStage.right - m_rectStage.left)
			- (MARGIN * 2)) * m_posRevisionX));
		dc.TextOut(m_rectStage.right - MARGIN - 30, m_rectStage.bottom - MARGIN + 5,
			strEndPos);
		strEndPos.Format("(0, %d)", (int)((double)((m_rectStage.bottom -
			m_rectStage.top) - (MARGIN * 2)) * m_posRevisionY));
		dc.TextOut(m_rectStage.left + MARGIN - 15, m_rectStage.top + MARGIN - 20,
			strEndPos);

		// point ��ġ�� ��Ÿ���� ���� �簢���� �׸��ϴ�. Y��ǥ�� ���� ������ �����մϴ�.
		int iNewPointY = (m_rectStage.bottom - m_rectStage.top - (MARGIN * 2)) -
			m_pointY;
		dc.Rectangle((m_rectStage.left + MARGIN + m_pointX) + 5, (m_rectStage.top +
			MARGIN + iNewPointY) + 5,
			(m_rectStage.left + MARGIN + m_pointX) - 5, (m_rectStage.top + MARGIN +
				iNewPointY) - 5);

		// ������ ��ġ ���� �ϴܿ� �۰� ��ǥ�� ǥ���մϴ�.
		strPosX.Format("X:%d", m_realPointX);
		strPosY.Format("Y:%d", m_realPointY);
		dc.TextOut((m_rectStage.left + MARGIN + m_pointX) + 5, (m_rectStage.top +
			MARGIN + iNewPointY) + 5, strPosX);
		dc.TextOut((m_rectStage.left + MARGIN + m_pointX) + 5, (m_rectStage.top +
			MARGIN + iNewPointY) + 20, strPosY);


		if (ptp_btn == 1)
		{
			int iNewPointRectY[PTP_MAX];
			for (int i = 0; i < ptp_click_count; i++)
			{
				iNewPointRectY[i] = (m_rectStage.bottom - m_rectStage.top - (MARGIN * 2)) - ptp_points[i][1];
				if (iNewPointRectY[i] > 0)
				{
					//Ŭ���� ������ �簢�� ǥ��
					dc.Rectangle((m_rectStage.left + MARGIN + ptp_points[i][0]) + 5,
						(m_rectStage.top + MARGIN + iNewPointRectY[i]) + 5,
						(m_rectStage.left + MARGIN + ptp_points[i][0]) - 5,
						(m_rectStage.top + MARGIN + iNewPointRectY[i]) - 5);
					//������ ��ġ ���� �ϴܿ� ������ ���� ��ǥ�� ǥ��
					strPosX.Format("X:%d", (int)(ptp_points[i][0] * m_posRevisionX)); 			strPosY.Format("Y:%d", (int)(ptp_points[i][1] * m_posRevisionY));
					dc.TextOut((m_rectStage.left + MARGIN + ptp_points[i][0]) + 5, (m_rectStage.top + MARGIN + iNewPointRectY[i]) + 5, strPosX);
					dc.TextOut((m_rectStage.left + MARGIN + ptp_points[i][0]) + 5, (m_rectStage.top + MARGIN + iNewPointRectY[i]) + 20, strPosY);
				}
			}
			if (ptp_click_count == 2)
			{
				for (int i = 0; i < ptp_click_count - 1; i++)
				{
					//2ȸ Ŭ�� �� �� ������ �������� �׷� ����
					dc.MoveTo(m_rectStage.left + MARGIN + ptp_points[i][0], m_rectStage.top + MARGIN + iNewPointRectY[i]);
					dc.LineTo(m_rectStage.left + MARGIN + ptp_points[i + 1][0], m_rectStage.top + MARGIN + iNewPointRectY[i + 1]);
					//click_count = 0;//Ŭ�� Ƚ�� �ʱ�ȭ				
				}
			}
		}
		else if (cp_btn == 1)
		{
			int iNewPointY = (m_rectStage.bottom - m_rectStage.top - (MARGIN * 2)) - cp_dispos[1];
			if (click_count == 1) {
				dc.Ellipse((m_rectStage.left + MARGIN + cp_dispos[0]) - cp_radious, (m_rectStage.top +
					MARGIN + iNewPointY) - cp_radious,
					(m_rectStage.left + MARGIN + cp_dispos[0]) + cp_radious, (m_rectStage.top + MARGIN +
						iNewPointY) + cp_radious);

				dc.Rectangle((m_rectStage.left + MARGIN + cp_dispos[0]) - 5,
					(m_rectStage.top + MARGIN + iNewPointY) - 5,
					(m_rectStage.left + MARGIN + cp_dispos[0]) + 5,
					(m_rectStage.top + MARGIN + iNewPointY) + 5);

				// ������ ��ġ ���� �ϴܿ� �۰� ��ǥ�� ǥ���մϴ�.
				strPosX.Format("X:%d", (int)(ptp_points[1][0] * m_posRevisionX));
				strPosY.Format("Y:%d", (int)(ptp_points[1][1] * m_posRevisionY));
				dc.TextOut((m_rectStage.left + MARGIN + cp_dispos[0]) + 5, (m_rectStage.top +
					MARGIN + iNewPointY) + 5, strPosX);
				dc.TextOut((m_rectStage.left + MARGIN + cp_dispos[0]) + 5, (m_rectStage.top +
					MARGIN + iNewPointY) + 20, strPosY);
			}
		}
		else if (heart_btn == 1)
		{

			HWND hWnd = ::GetActiveWindow();
			HDC hdc = ::GetDC(hWnd);
			double input = GetDlgItemDouble(IDC_EDIT1);
			if (input > 10 || input <= 0) {
				input = 1;
				SetDlgItemDouble(IDC_EDIT1, DEFAULT_INPUT, 1);
			}

			int iNewPointY = (m_rectStage.bottom - m_rectStage.top - (MARGIN * 2)) - cp_dispos[1];
			if (click_count == 1) {

				GetDlgItem(IDC_RADIO_CP)->EnableWindow(FALSE);
				GetDlgItem(IDC_RADIO_PTP)->EnableWindow(FALSE);
				GetDlgItem(IDC_EDIT1)->EnableWindow(FALSE);
				GetDlgItem(IDC_CHECK2)->EnableWindow(FALSE);

				// XY Stage ����� �׸��ϴ�.
				dc.Rectangle(&m_rectStage);

				// XY Stage�� ���� ���鿡�� MARGIN����ŭ ������ ��ġ�� Y�� ���ؼ��� �׸��ϴ�.
				dc.MoveTo(m_rectStage.left + MARGIN, m_rectStage.top + MARGIN);
				dc.LineTo(m_rectStage.left + MARGIN, m_rectStage.bottom - MARGIN);

				// XY Stage�� �ϴ� ���鿡�� MARGIN����ŭ ������ ��ġ�� X�� ���ؼ��� �׸��ϴ�.
				dc.MoveTo(m_rectStage.left + MARGIN, m_rectStage.bottom - MARGIN);
				dc.LineTo(m_rectStage.right - MARGIN, m_rectStage.bottom - MARGIN);

				// �� ���� ������(0,0)�� ǥ���մϴ�.
				dc.TextOut(m_rectStage.left + MARGIN - 15, m_rectStage.bottom - MARGIN + 5,
					"(0, 0)");

				// X���� �� ����(?, 0)�� ǥ���մϴ�.
				strEndPos.Format("(%d, 0)", (int)((double)((m_rectStage.right - m_rectStage.left)
					- (MARGIN * 2)) * m_posRevisionX));
				dc.TextOut(m_rectStage.right - MARGIN - 30, m_rectStage.bottom - MARGIN + 5,
					strEndPos);
				strEndPos.Format("(0, %d)", (int)((double)((m_rectStage.bottom -
					m_rectStage.top) - (MARGIN * 2)) * m_posRevisionY));
				dc.TextOut(m_rectStage.left + MARGIN - 15, m_rectStage.top + MARGIN - 20,
					strEndPos);

				float fx, fy;
				const float a = 30;

				COLORREF color = RGB(0, 0, 0);

				if (vmode.GetCheck())
				{
					for (int i = 0; i < 360; i++)
					{
						fx = (float)((1 + (10 * sin(input * i * 3.141592 / 180.0))) + cp_dispos[0] + 84);
						fy = (float)(100 * cos(i * 3.141592 / 180.0) + iNewPointY + MARGIN + 104);
						SetPixel(hdc, (int)fx, (int)fy, color);
					}


					dc.Rectangle((m_rectStage.left + MARGIN + cp_dispos[0]) - 2,
						(m_rectStage.top + MARGIN + iNewPointY) - 2,
						(m_rectStage.left + MARGIN + cp_dispos[0]) + 2,
						(m_rectStage.top + MARGIN + iNewPointY) + 2);
					// ������ ��ġ ���� �ϴܿ� �۰� ��ǥ�� ǥ���մϴ�.
					strPosX.Format("X:%d", (int)(ptp_points[1][0] /** m_posRevisionX*/));
					strPosY.Format("Y:%d", (int)(ptp_points[1][1] /** m_posRevisionY*/));
					dc.TextOut((m_rectStage.left + MARGIN + cp_dispos[0]) + 5, (m_rectStage.top +
						MARGIN + iNewPointY) + 5, strPosX);
					dc.TextOut((m_rectStage.left + MARGIN + cp_dispos[0]) + 5, (m_rectStage.top +
						MARGIN + iNewPointY) + 20, strPosY);
				}
				else
				{
					for (int i = 0; i < 360; i++)
					{
						fx = (float)(100 * cos(i * 3.141592 / 180.0) + cp_dispos[0] + 84);
						fy = (float)((1 + (10 * sin(input * i * 3.141592 / 180.0))) + iNewPointY + MARGIN + 104);
						SetPixel(hdc, (int)fx, (int)fy, color);

						dc.Rectangle((m_rectStage.left + MARGIN + cp_dispos[0]) - 2,
							(m_rectStage.top + MARGIN + iNewPointY) - 2,
							(m_rectStage.left + MARGIN + cp_dispos[0]) + 2,
							(m_rectStage.top + MARGIN + iNewPointY) + 2);
						// ������ ��ġ ���� �ϴܿ� �۰� ��ǥ�� ǥ���մϴ�.
						strPosX.Format("X:%d", (int)(ptp_points[1][0] * m_posRevisionX));
						strPosY.Format("Y:%d", (int)(ptp_points[1][1] * m_posRevisionY));
						dc.TextOut((m_rectStage.left + MARGIN + cp_dispos[0]) + 5, (m_rectStage.top +
							MARGIN + iNewPointY) + 5, strPosX);
						dc.TextOut((m_rectStage.left + MARGIN + cp_dispos[0]) + 5, (m_rectStage.top +
							MARGIN + iNewPointY) + 20, strPosY);
					}
				}

			}
			else {
				GetDlgItem(IDC_RADIO_CP)->EnableWindow(TRUE);
				GetDlgItem(IDC_RADIO_PTP)->EnableWindow(TRUE);
				GetDlgItem(IDC_EDIT1)->EnableWindow(TRUE);
				GetDlgItem(IDC_CHECK2)->EnableWindow(TRUE);
			}
		}
		else if (btn_vision == 1)
		{

		}
	}
	// Y���� �� ����(0, ?)�� ǥ���մϴ�.
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CMy220404_2017132036_testDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

BOOL CMy220404_2017132036_testDlg::InitState()
{
	long lAxisCount = 0;
	DWORD dwRetCode = 0;
	DWORD dwOnOff = 0;
	long lPulse = 0;
	CString strResult;
	int nSliderEndPosX, nSliderEndPosY;

	click_count = 0;
	IposSize = 2;
	ICoordinate = 0;
	IAxis[0] = 0;
	IAxis[1] = 1;

	cp_radious = 30;

	//cv::Mat mat = cv::imread("C:/Users/abc/Desktop/imo.jpg");
	/*cv::imshow("mat", mat);*/
	// AXL �ʱ�ȭ
	if ((AxlIsOpened() == FALSE))
	{
		if (AxlOpenNoReset(7) != AXT_RT_SUCCESS)
		{
			AfxMessageBox("AxlOpen Fail");
			return FALSE;
		}
	}

	// ���� ���忡�� �ν��� �� �ִ� �ִ� ����� 2�� �̻��� �ƴϸ� ������ ����մϴ�.
	dwRetCode = AxmInfoGetAxisCount(&lAxisCount);
	if (dwRetCode != AXT_RT_SUCCESS)
	{
		strResult = TranslateAxmResult(dwRetCode);
		AfxMessageBox("AxmInfoGetAxisCount fail.\nError Msg : " + strResult);
		return FALSE;
	}
	else if (lAxisCount < 2)
	{
		AfxMessageBox("Please connect 2 Axis");
		return FALSE;
	}

	// X��� Y���� ��ȣ�� ���Ƿ� �����մϴ�.
	m_lAxisNoX = DEFAULT_AXIS_NUMBER_X;
	m_lAxisNoY = DEFAULT_AXIS_NUMBER_Y;

	// ��ǥ�� �ʱ�ȭ�մϴ�.
	m_pointX = 0;
	m_pointY = 0;
	m_realPointX = 0;
	m_realPointY = 0;

	// ������� �ʴ� Emergency ��ȣ�� UNUSED�� ����
	dwRetCode = AxmSignalSetStop(m_lAxisNoX, EMERGENCY_STOP, UNUSED);
	dwRetCode = AxmSignalSetStop(m_lAxisNoY, EMERGENCY_STOP, UNUSED);

	// Limit Level�� HIGH�� �����մϴ�. (������ LOW)
	dwRetCode = AxmSignalSetLimit(m_lAxisNoX, EMERGENCY_STOP, HIGH, HIGH);
	dwRetCode = AxmSignalSetLimit(m_lAxisNoY, EMERGENCY_STOP, HIGH, HIGH);

	// Unit Per Pulse�� 1250:1048576���� �����մϴ�. (������ 10)
	dwRetCode = AxmMotSetMoveUnitPerPulse(m_lAxisNoX, 1250, 1048576);
	dwRetCode = AxmMotSetMoveUnitPerPulse(m_lAxisNoY, 1250, 1048576);

	// Edit Contorl�� �ʱⰪ�� �����մϴ�.
	SetDlgItemDouble(IDC_EDT_X_INPUT_VEL, DEFAULT_VEL, 1);
	SetDlgItemDouble(IDC_EDT_X_INPUT_ACC, DEFAULT_ACC, 1);
	SetDlgItemDouble(IDC_EDT_X_INPUT_DEC, DEFAULT_DEC, 1);
	SetDlgItemDouble(IDC_EDT_Y_INPUT_VEL, DEFAULT_VEL, 1);
	SetDlgItemDouble(IDC_EDT_Y_INPUT_ACC, DEFAULT_ACC, 1);
	SetDlgItemDouble(IDC_EDT_Y_INPUT_DEC, DEFAULT_DEC, 1);
	SetDlgItemDouble(IDC_EDIT1, DEFAULT_INPUT, 1);

	m_edtXMovePos.SetWindowText("0");
	m_edtYMovePos.SetWindowText("0");

	// �����˻� �������� ǥ���� ���α׷����ٸ� �ʱ�ȭ�մϴ�.
	m_prgXHomeRate.SetRange(0, 100);
	m_prgXHomeRate.SetStep(1);
	m_prgXHomeRate.SetPos(0);
	m_prgXHomeRate.EnableWindow(FALSE);
	m_prgYHomeRate.SetRange(0, 100);
	m_prgYHomeRate.SetStep(1);
	m_prgYHomeRate.SetPos(0);
	m_prgYHomeRate.EnableWindow(FALSE);

	// Dialog�������� XY Stage�� ��ġ�� �����մϴ�.
	m_pcstage.GetWindowRect(&m_rectStage);
	ScreenToClient(&m_rectStage);

	// X, Y�� �����̴��� �ʱ�ȭ�մϴ�.
	nSliderEndPosX = m_rectStage.right - m_rectStage.left - (MARGIN * 2);
	nSliderEndPosY = m_rectStage.bottom - m_rectStage.top - (MARGIN * 2);
	m_sliX.SetRange(0, nSliderEndPosX, FALSE);
	m_sliY.SetRange(0, nSliderEndPosY, FALSE);
	m_sliX.SetPos(0);
	m_sliY.SetPos(nSliderEndPosY);

	// X, Y���� �̵� Ȯ�� ������ �ʱ�ȭ�մϴ�.
	m_bXIsMoving = FALSE;
	m_bYIsMoving = FALSE;

	// Stop ��� Ȯ�� ������ �ʱ�ȭ�մϴ�.
	m_bXStop = FALSE;
	m_bYStop = FALSE;

	// ��ǥ ����ġ���� ����մϴ�.
	m_posRevisionX = DEFAULT_REVISION_X / (m_rectStage.right - m_rectStage.left -
		(MARGIN * 2));
	m_posRevisionY = DEFAULT_REVISION_Y / (m_rectStage.bottom - m_rectStage.top -
		(MARGIN * 2));

	// X, Y���� ���� ��ġ�� ���� ���°��� �ֱ������� ǥ���� Ÿ�̸Ӹ� Ȱ��ȭ�մϴ�.
	SetTimer(TM_DISPLAY, 100, NULL);

	return TRUE;
}

void  CMy220404_2017132036_testDlg::SetDlgItemDouble(int nID, double value, int nPoint)
{
	CString sTemp, sTemp2;
	sTemp2.Format("%%.%df", nPoint);
	sTemp.Format(sTemp2, value);
	GetDlgItem(nID)->SetWindowText(sTemp);
}

double CMy220404_2017132036_testDlg::GetDlgItemDouble(int nID)
{
	double dRet;
	CString sTemp;
	GetDlgItem(nID)->GetWindowText(sTemp);
	dRet = atof((LPCTSTR)sTemp);
	return dRet;
}

CString CMy220404_2017132036_testDlg::TranslateAxmResult(DWORD dwAxmResult)
{
	CString strResult;

	switch (dwAxmResult)
	{
	case AXT_RT_SUCCESS: strResult.Format("[0000] API�Լ� ���� ����"); break;
	case AXT_RT_OPEN_ERROR: strResult.Format("[1001] ���̺귯���� ���µǾ� ���� ����"); break;
	case AXT_RT_OPEN_ALREADY: strResult.Format("[1002] ���̺귯���� ���µǾ� �ְ� ��� ����"); break;
	case AXT_RT_NOT_OPEN: strResult.Format("[1053] ���̺귯�� �ʱ�ȭ ����"); break;
	case AXT_RT_NOT_SUPPORT_VERSION: strResult.Format("[1054] �������� �ʴ� �ϵ����"); break;
	case AXT_RT_NETWORK_ERROR: strResult.Format("[1152] ��Ʈ��ũ�� ����� �����̺� ��� ������� �ʾҰų� ������°� �ҷ���"); break;
	case AXT_RT_MOTION_OPEN_ERROR: strResult.Format("[4001] ��� ���̺귯�� Open ����"); break;
	case AXT_RT_MOTION_NOT_MODULE: strResult.Format("[4051] �ý��ۿ� ������ ��� ����� ����"); break;
	case AXT_RT_MOTION_INVALID_AXIS_NO: strResult.Format("[4101] �ش� ���� �������� ����"); break;
	case AXT_RT_MOTION_INVALID_METHOD: strResult.Format("[4102] �ش� �� ������ �ʿ��� ������ �߸���"); break;
	case AXT_RT_MOTION_INVALID_VELOCITY: strResult.Format("[4113] ��� ���� �ӵ����� 0���� �����Ǿ� ��� ���� �߻�"); break;
	case AXT_RT_MOTION_INVALID_ACCELTIME: strResult.Format("[4114] ��� ���� ���� �ð� ���� 0���� �����Ǿ� ��� ���� �߻�"); break;
	case AXT_RT_MOTION_ERROR_IN_MOTION: strResult.Format("[4152] ��� ���� �߿� �ٸ� ��� ���� �Լ��� ������"); break;
	case AXT_RT_MOTION_ERROR: strResult.Format("[4153] ���� ���� ���� �Լ� ���� �� ���� �߻���"); break;
	case AXT_RT_MOTION_HOME_SEARCHING: strResult.Format("[4201] Ȩ�� ã�� �ִ� ���� �� �ٸ� ��� �Լ��� �����"); break;
	case AXT_RT_MOTION_SETTING_ERROR: strResult.Format("[4255] �ӵ�, ���ӵ� �� ������ �߸���"); break;
	case AXT_RT_PROTECTED_DURING_SERVOON: strResult.Format("[4260] ���� �� ���¿��� ����� �� ���� �Լ� �Ǵ� �Է� ���� ����Ͽ���"); break;
	case AXT_RT_HW_ACCESS_ERROR: strResult.Format("[4261] ������ H/W ���� ������ �߻���"); break;
	default: strResult.Format("��Ÿ�����߻�"); break;
	}

	return strResult;
}

void CMy220404_2017132036_testDlg::OnBnClickedstage()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CMy220404_2017132036_testDlg::OnBnClickedChkXServoOn()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	DWORD dwOnOff, dwRetCode;
	CString strResult;

	dwOnOff = IsDlgButtonChecked(IDC_CHK_X_SERVO_ON);
	// ���� ���� Servo On/Off ��ȣ�� ����մϴ�.
	dwRetCode = AxmSignalServoOn(m_lAxisNoX, dwOnOff);
	if (dwRetCode != AXT_RT_SUCCESS)
	{
		strResult = TranslateAxmResult(dwRetCode);
		AfxMessageBox("X Axis AxmSignalServoOn fail.\nError Msg : " + strResult);
	}
}


void CMy220404_2017132036_testDlg::OnBnClickedBtnXAlarmClear()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	DWORD dwRetCode = 0;
	CString strResult;

	dwRetCode = AxmSignalServoAlarmReset(m_lAxisNoX, ENABLE);
	if (dwRetCode != AXT_RT_SUCCESS) {
		strResult = TranslateAxmResult(dwRetCode);
		AfxMessageBox("X Axis Alarm Clear fail.\nError Msg : " + strResult);
		return;
	}
}


void CMy220404_2017132036_testDlg::OnBnClickedBtnXHomeSearch()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	double dHomeVelFirst, dHomeVelSecond, dHomeVelThird, dHomeVelLast, dHomeAccFirst, dHomeAccSecond;
	DWORD dwRetCode = 0, dwStatus = 0;
	CString strResult, strVel, strAcc;

	// X���� Servo Off�̸� �� �۾��� �������� �ʽ��ϴ�.
	dwRetCode = AxmSignalIsServoOn(m_lAxisNoX, &dwStatus);
	if (dwRetCode != AXT_RT_SUCCESS || dwStatus == FALSE)
	{
		return;
	}

	// X���� ���� ���̸� �� �۾��� �������� �ʽ��ϴ�.
	// AxmStatusReadMotion : ���� ���� ��� ���� ���� ���� ��ȯ�մϴ�.
	// - dwStatus ��Ʈ���� �ǹ� : (0x00000001) 0 bit. ����̺� ���� ��
	// (0x00000002) 1 bit. ���� ��
	// - �� ���� ������ AXM �Ŵ����� �����Ͻñ� �ٶ��ϴ�.
	dwRetCode = AxmStatusReadMotion(m_lAxisNoX, &dwStatus);
	if (dwRetCode != AXT_RT_SUCCESS || dwStatus & QIDRIVE_STATUS_0)
	{
		return;
	}

	// Stop Ȯ�� ������ �ʱ�ȭ�մϴ�.
	m_bXStop = FALSE;

	// Edit control���� �ӵ�, ���ӵ� ���� �޾ƿɴϴ�.
	SetDlgItemDouble(IDC_EDT_X_INPUT_VEL, 10, 1);
	m_edtXInputVel.GetWindowText(strVel);
	strVel = strVel.Trim();
	dHomeVelFirst = atof(strVel);
	if (dHomeVelFirst < DEFAULT_HOME_VEL_FIRST)
	{
		dHomeVelFirst = DEFAULT_HOME_VEL_FIRST;
	}
	dHomeVelSecond = dHomeVelFirst;
	dHomeVelThird = dHomeVelSecond / 2;
	dHomeVelLast = dHomeVelThird / 3;

	m_edtXInputAcc.GetWindowText(strAcc);
	strAcc = strAcc.Trim();
	dHomeAccFirst = atof(strAcc);
	if (dHomeAccFirst < DEFAULT_HOME_ACC_FIRST)
	{
		dHomeAccFirst = DEFAULT_HOME_ACC_FIRST;
	}
	dHomeAccSecond = dHomeAccFirst;
	// �����˻��� ���Ǵ� �˻������ �����մϴ�.
	dwRetCode = AxmHomeSetMethod(m_lAxisNoX, DIR_CCW, Signal_HomeSensor,
		UNUSED, 1000, 0);

	// �����˻��� ���Ǵ� �ܰ躰 �ӵ��� �����մϴ�.
	dwRetCode = AxmHomeSetVel(m_lAxisNoX, dHomeVelFirst, dHomeVelSecond,
		dHomeVelThird, dHomeVelLast,
		dHomeAccFirst, dHomeAccSecond);
	if (dwRetCode != AXT_RT_SUCCESS) {
		strResult = TranslateAxmResult(dwRetCode);
		AfxMessageBox("X Axis Home Search velocity set fail.\nError Msg : " + strResult);
	}

	// X�� �����˻��� �����մϴ�.
	m_prgXHomeRate.EnableWindow(TRUE);
	dwRetCode = AxmHomeSetStart(m_lAxisNoX);
	if (dwRetCode != AXT_RT_SUCCESS) {
		strResult = TranslateAxmResult(dwRetCode);
		AfxMessageBox("X Axis Home Search fail.\nError Msg : " + strResult);
		m_prgXHomeRate.EnableWindow(FALSE);
		return;
	}

	// ���� �˻� ���� ��Ȳ�� ǥ���� Ÿ�̸Ӹ� �����մϴ�.
	m_bXIsMoving = TRUE;
	SetTimer(TM_X_HOME_INFO, 200, NULL); // ������ �ֱ�� ����Ǵ� �����˻� ���������� Control�� �ݿ��� Ÿ�̸Ӹ� �����մϴ�. 
	//SetDlgItemDouble(IDC_EDT_X_INPUT_VEL, 30, 1);
}


void CMy220404_2017132036_testDlg::OnBnClickedBtnXPosClear()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	DWORD dwRetCode;
	CString strResult;

	// Command��ġ�� Actual��ġ�� ������ ������ �����մϴ�.
	dwRetCode = AxmStatusSetPosMatch(m_lAxisNoX, 0.0);
	if (dwRetCode != AXT_RT_SUCCESS)
	{
		strResult = TranslateAxmResult(dwRetCode);
		AfxMessageBox("X Axis AxmStatusSetPosMatch fail.\nError Msg : " + strResult);
	}
}


void CMy220404_2017132036_testDlg::OnBnClickedBtnXSstop()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	AxmMoveSStop(m_lAxisNoX);
	m_bXIsMoving = FALSE;
	m_bXStop = TRUE;
}


void CMy220404_2017132036_testDlg::OnBnClickedBtnXEstop()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	AxmMoveEStop(m_lAxisNoX);
	m_bXIsMoving = FALSE;
	m_bXStop = TRUE;
}


void CMy220404_2017132036_testDlg::OnBnClickedChkYServoOn()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	DWORD dwOnOff, dwRetCode;
	CString strResult;

	dwOnOff = IsDlgButtonChecked(IDC_CHK_Y_SERVO_ON);
	// ���� ���� Servo On/Off ��ȣ�� ����մϴ�.
	dwRetCode = AxmSignalServoOn(m_lAxisNoY, dwOnOff);
	if (dwRetCode != AXT_RT_SUCCESS)
	{
		strResult = TranslateAxmResult(dwRetCode);
		AfxMessageBox("Y Axis AxmSignalServoOn fail.\nError Msg : " + strResult);
	}
}


void CMy220404_2017132036_testDlg::OnBnClickedChkYAlarmClear()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	DWORD dwRetCode = 0;
	CString strResult;

	dwRetCode = AxmSignalServoAlarmReset(m_lAxisNoY, ENABLE);
	if (dwRetCode != AXT_RT_SUCCESS) {
		strResult = TranslateAxmResult(dwRetCode);
		AfxMessageBox("Y Axis Alarm Clear fail.\nError Msg : " + strResult);
		return;
	}
}


void CMy220404_2017132036_testDlg::OnBnClickedBtnYHomeSearch()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	double dHomeVelFirst, dHomeVelSecond, dHomeVelThird, dHomeVelLast, dHomeAccFirst, dHomeAccSecond;
	DWORD dwRetCode = 0, dwStatus = 0;
	CString strResult, strVel, strAcc;

	// Y���� Servo Off�̸� �� �۾��� �������� �ʽ��ϴ�.
	dwRetCode = AxmSignalIsServoOn(m_lAxisNoY, &dwStatus);
	if (dwRetCode != AXT_RT_SUCCESS || dwStatus == FALSE)
	{
		return;
	}

	// Y���� ���� ���̸� �� �۾��� �������� �ʽ��ϴ�.
	// AxmStatusReadMotion : ���� ���� ��� ���� ���� ���� ��ȯ�մϴ�.
	// - dwStatus ��Ʈ���� �ǹ� : (0x00000001) 0 bit. ����̺� ���� ��
	// (0x00000002) 1 bit. ���� ��
	// - �� ���� ������ AXM �Ŵ����� �����Ͻñ� �ٶ��ϴ�.
	dwRetCode = AxmStatusReadMotion(m_lAxisNoY, &dwStatus);
	if (dwRetCode != AXT_RT_SUCCESS || dwStatus & QIDRIVE_STATUS_0)
	{
		return;
	}

	// Stop Ȯ�� ������ �ʱ�ȭ�մϴ�.
	m_bYStop = FALSE;

	// Edit control���� �ӵ�, ���ӵ� ���� �޾ƿɴϴ�.
	SetDlgItemDouble(IDC_EDT_Y_INPUT_VEL, 10, 1);
	m_edtYInputVel.GetWindowText(strVel);
	strVel = strVel.Trim();
	dHomeVelFirst = atof(strVel);
	if (dHomeVelFirst < DEFAULT_HOME_VEL_FIRST)
	{
		dHomeVelFirst = DEFAULT_HOME_VEL_FIRST;
	}
	dHomeVelSecond = dHomeVelFirst;
	dHomeVelThird = dHomeVelSecond / 2;
	dHomeVelLast = dHomeVelThird / 3;

	m_edtYInputAcc.GetWindowText(strAcc);
	strAcc = strAcc.Trim();
	dHomeAccFirst = atof(strAcc);
	if (dHomeAccFirst < DEFAULT_HOME_ACC_FIRST)
	{
		dHomeAccFirst = DEFAULT_HOME_ACC_FIRST;
	}
	dHomeAccSecond = dHomeAccFirst;

	// �����˻��� ���Ǵ� �˻������ �����մϴ�.
	dwRetCode = AxmHomeSetMethod(m_lAxisNoY, DIR_CCW, Signal_HomeSensor, UNUSED, 1000, 0);

	// �����˻��� ���Ǵ� �ܰ躰 �ӵ��� �����մϴ�.
	dwRetCode = AxmHomeSetVel(m_lAxisNoY, dHomeVelFirst, dHomeVelSecond, dHomeVelThird, dHomeVelLast, dHomeAccFirst, dHomeAccSecond);
	if (dwRetCode != AXT_RT_SUCCESS) {
		strResult = TranslateAxmResult(dwRetCode);
		AfxMessageBox("Y Axis Home Search velocity set fail.\nError Msg : " + strResult);
	}

	// Y�� �����˻��� �����մϴ�.
	m_prgYHomeRate.EnableWindow(TRUE);
	dwRetCode = AxmHomeSetStart(m_lAxisNoY);
	if (dwRetCode != AXT_RT_SUCCESS) {
		strResult = TranslateAxmResult(dwRetCode);
		AfxMessageBox("Y Axis Home search fail.\nError Msg : " + strResult);
		m_prgYHomeRate.EnableWindow(FALSE);
		return;
	}

	// ���� �˻� ���� ��Ȳ�� ǥ���� Ÿ�̸Ӹ� �����մϴ�.
	m_bYIsMoving = TRUE;
	SetTimer(TM_Y_HOME_INFO, 200, NULL); // ������ �ֱ�� ����Ǵ� �����˻� ���������� Control�� �ݿ��� Ÿ�̸Ӹ� �����մϴ�. 
	//SetDlgItemDouble(IDC_EDT_Y_INPUT_VEL, 30, 1);
}


void CMy220404_2017132036_testDlg::OnBnClickedBtnYPosClear()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	DWORD dwRetCode;
	CString strResult;

	// Command��ġ�� Actual��ġ�� ������ ������ �����մϴ�.
	dwRetCode = AxmStatusSetPosMatch(m_lAxisNoY, 0.0);
	if (dwRetCode != AXT_RT_SUCCESS)
	{
		strResult = TranslateAxmResult(dwRetCode);
		AfxMessageBox("Y Axis AxmStatusSetPosMatch fail.\nError Msg : " + strResult);
	}
}


void CMy220404_2017132036_testDlg::OnBnClickedBtnYSstop()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	AxmMoveSStop(m_lAxisNoY);
	m_bYIsMoving = FALSE;
	m_bYStop = TRUE;
}


void CMy220404_2017132036_testDlg::OnBnClickedBtnYEstop()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	AxmMoveEStop(m_lAxisNoY);
	m_bYIsMoving = FALSE;
	m_bYStop = TRUE;
}


void CMy220404_2017132036_testDlg::OnBnClickedBtnPosMove()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString strMovePosX, strMovePosY, strMsg;
	int iMovePosX, iMovePosY, iLimitPosX, iLimitPosY;
	double dPosX, dPosY;
	int nSliderEndPosY = m_sliY.GetRangeMax();
	// XY Stage���� �̵� �Ѱ����� ����մϴ�.
	iLimitPosX = (int)((m_rectStage.right - m_rectStage.left - (MARGIN * 2)) *
		m_posRevisionX);
	iLimitPosY = (int)((m_rectStage.bottom - m_rectStage.top - (MARGIN * 2)) *
		m_posRevisionX);

	// Edit Control���� �Է� ��ǥ ���� �޾ƿɴϴ�.
	m_edtXMovePos.GetWindowText(strMovePosX);
	strMovePosX = strMovePosX.Trim();
	iMovePosX = atoi(strMovePosX);
	// �Է¹��� ��ǥ�� XY Stage�� ��� ��ǥ�̸� ���� �˾��� ����ϰ� �̵����� �ʽ��ϴ�.
	if (iMovePosX < 0 || iMovePosX > iLimitPosX)
	{
		strMsg.Format("��ȿ�� X��ǥ ���� �Է��ϼ���. (�Է¹��� : 0 ~ %d)", iLimitPosX);
		AfxMessageBox(strMsg);
		return;
	}

	m_edtYMovePos.GetWindowText(strMovePosY);
	strMovePosY = strMovePosY.Trim();
	iMovePosY = atoi(strMovePosY);
	// �Է¹��� ��ǥ�� XY Stage�� ��� ��ǥ�̸� ���� �˾��� ����ϰ� �̵����� �ʽ��ϴ�.
	if (iMovePosY < 0 || iMovePosY > iLimitPosY)
	{
		strMsg.Format("��ȿ�� Y��ǥ ���� �Է��ϼ���. (�Է¹��� : 0 ~ %d)", iLimitPosY);
		AfxMessageBox(strMsg);
		return;
	}

	// �ش� ��ǥ�� �̵��մϴ�.
	m_pointX = (int)((double)iMovePosX / (m_posRevisionX));
	m_pointY = (int)((double)iMovePosY / (m_posRevisionY));
	Invalidate();
	m_sliX.SetPos(m_pointX);
	m_sliY.SetPos(nSliderEndPosY - m_pointY);

	dPosX = iMovePosX;
	m_realPointX = iMovePosX;
	AxmMoveStartPos(m_lAxisNoX, dPosX,
		GetDlgItemDouble(IDC_EDT_X_INPUT_VEL),
		GetDlgItemDouble(IDC_EDT_X_INPUT_ACC),
		GetDlgItemDouble(IDC_EDT_X_INPUT_DEC));

	dPosY = iMovePosY;
	m_realPointY = iMovePosY;
	AxmMoveStartPos(m_lAxisNoY, dPosY,
		GetDlgItemDouble(IDC_EDT_Y_INPUT_VEL),
		GetDlgItemDouble(IDC_EDT_Y_INPUT_ACC),
		GetDlgItemDouble(IDC_EDT_Y_INPUT_DEC));
}



void CMy220404_2017132036_testDlg::OnClose()
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	// "���� �Ͻðڽ��ϱ�?" Ȯ�� �˾� â�� ����Ͽ� ���� ���θ� �� �� �� Ȯ���մϴ�.
	if (AfxMessageBox("���� �Ͻðڽ��ϱ�?", MB_OKCANCEL) == IDCANCEL)
	{
		return;
	}
	vision_btn = 0;
	Sleep(500);
	CDialogEx::OnClose();

	m_chkXServoOn.SetCheck(BST_UNCHECKED);
	m_chkYServoOn.SetCheck(BST_UNCHECKED);

	OnBnClickedChkXServoOn();
	OnBnClickedChkYServoOn();
}


void CMy220404_2017132036_testDlg::OnDestroy()
{
	CDialogEx::OnDestroy();
	// ���� ó���� ���Ͽ� AXL ���̺귯���� ���� ������ �ݽ��ϴ�.
	if (AxlIsOpened())
	{
		AxlClose();
	}
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
}


void CMy220404_2017132036_testDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	double dVel = 0.0, dAcc = 0.0, dDec = 0.0;
	DWORD dwRetCode = 0, dwStatus = 0;
	CString strResult;
	CSliderCtrl* pSlider = (CSliderCtrl*)pScrollBar;
	double dPosX = 0.0;

	// �� �̺�Ʈ���� ���������� �ڵ�ȣ��Ǵ� �̺�Ʈ���� �۾��� �����մϴ�.
	if (nSBCode != SB_ENDSCROLL)
	{
		return;
	}

	// X���� ���� ���̸� �� �۾��� �������� �ʽ��ϴ�.
	// AxmStatusReadMotion(..) : ���� ���� ��� ���� ���� ���� ��ȯ�մϴ�.
	// - dwStatus ��Ʈ���� �ǹ� : (0x00000001) 0 bit. ����̺� ���� ��
	// (0x00000002) 1 bit. ���� ��
	// ...
	dwRetCode = AxmStatusReadMotion(m_lAxisNoX, &dwStatus);
	if (dwRetCode != AXT_RT_SUCCESS || dwStatus & QIDRIVE_STATUS_0)
	{
		return;
	}

	switch (pSlider->GetDlgCtrlID())
	{
	case IDC_SLI_X:
		m_pointX = pSlider->GetPos();
		break;
	}
	Invalidate();

	UpdateData(TRUE);

	dPosX = m_pointX * m_posRevisionX;
	m_realPointX = (int)dPosX;
	dVel = GetDlgItemDouble(IDC_EDT_X_INPUT_VEL);
	dAcc = GetDlgItemDouble(IDC_EDT_X_INPUT_ACC);
	dDec = GetDlgItemDouble(IDC_EDT_X_INPUT_DEC);

	// Absolute ��ǥ�� �̵����� �����մϴ�.
	AxmMotSetAbsRelMode(m_lAxisNoX, POS_ABS_MODE);

	// �̵��� �����մϴ�.
	dwRetCode = AxmMoveStartPos(m_lAxisNoX, dPosX, dVel, dAcc, dDec);
	if (dwRetCode != AXT_RT_SUCCESS)
	{
		strResult = TranslateAxmResult(dwRetCode);
		AfxMessageBox("X Axis AxmMoveStartPos fail.\nError Msg : " + strResult);
	}

	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}


void CMy220404_2017132036_testDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	double dPosX = 0.0, dPosY = 0.0;
	DWORD dwRetCode = 0, dwStatus = 0;
	CString strResult;
	int nSliderEndPosY = m_sliY.GetRangeMax();

	CWinThread* pWinThread; // ������ ����

	if (m_bXIsMoving || m_bYIsMoving)
	{
		return;
	}

	// ���� �Ǵ�
	CRect rect1(&m_rectStage);
	CRect rect2(m_rectStage.left + MARGIN, m_rectStage.top + MARGIN, m_rectStage.right - MARGIN, m_rectStage.bottom - MARGIN);

	if (rect1.PtInRect(point))
	{
		if (rect2.PtInRect(point))
		{
			Set_Cursor = 2;
		}
		else
		{
			Set_Cursor = 1;
		}
	}
	else
	{
		Set_Cursor = 0;
	}

	if (Set_Cursor == 1)
	{
		AfxMessageBox("ǥ���� �� ���� ��ġ�Դϴ�.");
	}
	else if (Set_Cursor == 2)
	{
		if (rect_btn == 1)
		{
		}//if (rect_btn == 1)  rect��ư Ŭ����
		else if (ptp_btn == 1)
		{
			//ptp ��� 0
			ptp_points[ptp_click_count][0] = point.x - (m_rectStage.left + MARGIN);//Ŭ���� x��ǥ
			ptp_points[ptp_click_count][1] = (m_rectStage.bottom - m_rectStage.top - (MARGIN * 2)) - (point.y - (m_rectStage.top + MARGIN));//Ŭ���� y��ǥ
			Invalidate();
			//Ŭ���� ����(m_point)�� ���� �����̵� �� ǥ��

			m_sliX.SetPos(ptp_points[ptp_click_count][0]);
			m_sliY.SetPos(nSliderEndPosY - ptp_points[ptp_click_count][1]);//��������
			ptp_click_count++;//Ŭ�� ī��Ʈ ����
			if (ptp_click_count == PTP_MAX)//�ִ� Ŭ����(==�ִ� ��ǥ ���� ��)�� �����ϸ�
			{
				Invalidate();
				UpdateWindow();

				DWORD StatusX = FALSE, StatusY = FALSE;
				IAxis[0] = 0;  IAxis[1] = 1;

				//Queue�� ����� ������ ��� ������ �ʱ�ȭ
				AxmContiWriteClear(ICoordinate);
				//������ ��� ��ǥ�� ����
				AxmContiSetAxisMap(ICoordinate, IposSize, IAxis);
				//�����ġ, ������ġ ������� ����
				AxmContiSetAbsRelMode(ICoordinate, 0);
				//������ �۾��� ��� ����
				AxmContiBeginNode(ICoordinate);
				for (int i = 0; i < PTP_MAX; i++)
				{
					//dPos[0] = m_ptp_points[i].x * m_posRevisionX;
					//dPos[1] = m_ptp_points[i].y * m_posRevisionY;

					dPos[0] = ptp_points[i][0] * m_posRevisionX;
					dPos[1] = ptp_points[i][1] * m_posRevisionY;

					AxmLineMove(ICoordinate, dPos, GetDlgItemDouble(IDC_EDT_X_INPUT_VEL), GetDlgItemDouble(IDC_EDT_X_INPUT_ACC), GetDlgItemDouble(IDC_EDT_X_INPUT_DEC));
				}

				pWinThread = AfxBeginThread(ThreadStart, this);

				//������ �۾��� ����� ����
				AxmContiEndNode(ICoordinate);
				//���Ӻ�����������
				AxmContiStart(ICoordinate, 0, 0);
				ptp_click_count = 0;//Ŭ�� ī��Ʈ�� �������� ���������Ƿ� �ʱ�ȭ
				return;//�Լ� ����
			}
		}//else if (ptp_btn == 1). ptp��ư Ŭ����
		else if (heart_btn == 1)
		{
			double input = GetDlgItemDouble(IDC_EDIT1);
			if (input > 10 || input <= 0) {
				input = 1;
				SetDlgItemDouble(IDC_EDIT1, DEFAULT_INPUT, 1);
			}

			IAxis[0] = 0;
			IAxis[1] = 1;

			ptp_points[1][0] = point.x - (m_rectStage.left + MARGIN);
			ptp_points[1][1] = (m_rectStage.bottom - m_rectStage.top - (MARGIN * 2)) - (point.y - (m_rectStage.top + MARGIN));
			click_count++;
			Invalidate();
			//Ŭ���� ����(m_point)�� ���� �����̵� �� ǥ��
			m_sliX.SetPos(ptp_points[1][0]);
			m_sliY.SetPos(nSliderEndPosY - ptp_points[1][1]);//��������

			cp_dispos[0] = ptp_points[1][0];
			cp_dispos[1] = ptp_points[1][1];

			Invalidate();
			UpdateWindow();

			DWORD StatusX = FALSE, StatusY = FALSE;
			IAxis[0] = 0;  IAxis[1] = 1;

			//Queue�� ����� ������ ��� ������ �ʱ�ȭ
			AxmContiWriteClear(ICoordinate);
			//������ ��� ��ǥ�� ����
			AxmContiSetAxisMap(ICoordinate, IposSize, IAxis);
			//�����ġ, ������ġ ������� ����
			AxmContiSetAbsRelMode(ICoordinate, 0);
			//������ �۾��� ��� ����
			AxmContiBeginNode(ICoordinate);

			//((CButton*)GetDlgItem(IDC_MODE))->GetCheck() == TRUE
			if (vmode.GetCheck())
			{

				for (int i = 0; i < 360; i++)
				{
					dPos[0] = (ptp_points[1][0] + (10 * sin(input * i * (PI / 180)))) * m_posRevisionX;
					dPos[1] = (ptp_points[1][1] + (100 * cos(i * (PI / 180)))) * m_posRevisionY;

					if (dPos[0] < 0 || dPos[0]>199 || dPos[1] < 0 || dPos[1]>194)
					{
						AfxMessageBox("ǥ���� �� ���� ��ġ�Դϴ�.");
						territory = 2;
						click_count = 0;
					}

					else {
						territory = 1;
						if (i == 0)
						{
							cp_start[0] = dPos[0];
							cp_start[1] = dPos[1];
						}
						AxmLineMove(ICoordinate, dPos, GetDlgItemDouble(IDC_EDT_X_INPUT_VEL), GetDlgItemDouble(IDC_EDT_X_INPUT_ACC), GetDlgItemDouble(IDC_EDT_X_INPUT_DEC));
					}
				}

				if (territory == 1) {
					//������ �۾��� ����� ����
					AxmContiEndNode(ICoordinate);
					//���Ӻ�����������
					AxmContiStart(ICoordinate, 0, 0);
					click_count = 0;
					pWinThread = AfxBeginThread(ThreadStart, this);
				}

				end = 1;
			}

			else
			{
				for (int i = 0; i < 360; i++)
				{
					dPos[0] = (ptp_points[1][0] + (100 * cos(i * (PI / 180)))) * m_posRevisionX;
					dPos[1] = (ptp_points[1][1] + (10 * sin(input * i * (PI / 180)))) * m_posRevisionY;

					if (dPos[0] < 0 || dPos[0]>199 || dPos[1] < 0 || dPos[1]>194)
					{
						AfxMessageBox("ǥ���� �� ���� ��ġ�Դϴ�.");
						territory = 2;
						click_count = 0;
						break;
					}

					else {
						territory = 1;
						if (i == 0)
						{
							cp_start[0] = dPos[0];
							cp_start[1] = dPos[1];
						}
						AxmLineMove(ICoordinate, dPos, GetDlgItemDouble(IDC_EDT_X_INPUT_VEL), GetDlgItemDouble(IDC_EDT_X_INPUT_ACC), GetDlgItemDouble(IDC_EDT_X_INPUT_DEC));
					}
				}

				if (territory == 1) {
					//������ �۾��� ����� ����
					AxmContiEndNode(ICoordinate);
					//���Ӻ�����������
					AxmContiStart(ICoordinate, 0, 0);
					click_count = 0;
					pWinThread = AfxBeginThread(ThreadStart, this);
				}

				end = 1;
			}
			//}
			return;//�Լ� ����
		}//else if (heart_btn == 1)
		else if (star_btn == 1)
		{

		}//else if (star_btn == 1)
		else if (cp_btn == 1)
		{

			IAxis[0] = 0;
			IAxis[1] = 1;

			ptp_points[1][0] = point.x - (m_rectStage.left + MARGIN);
			ptp_points[1][1] = (m_rectStage.bottom - m_rectStage.top - (MARGIN * 2)) - (point.y - (m_rectStage.top + MARGIN));
			click_count++;
			Invalidate();
			//Ŭ���� ����(m_point)�� ���� �����̵� �� ǥ��
			m_sliX.SetPos(ptp_points[1][0]);
			m_sliY.SetPos(nSliderEndPosY - ptp_points[1][1]);//��������

			cp_dispos[0] = ptp_points[1][0];
			cp_dispos[1] = ptp_points[1][1];

			Invalidate();
			UpdateWindow();

			DWORD StatusX = FALSE, StatusY = FALSE;
			IAxis[0] = 0;  IAxis[1] = 1;

			//Queue�� ����� ������ ��� ������ �ʱ�ȭ
			AxmContiWriteClear(ICoordinate);
			//������ ��� ��ǥ�� ����
			AxmContiSetAxisMap(ICoordinate, IposSize, IAxis);
			//�����ġ, ������ġ ������� ����
			AxmContiSetAbsRelMode(ICoordinate, 0);
			//������ �۾��� ��� ����
			AxmContiBeginNode(ICoordinate);

			for (int i = 0; i < 360; i++)
			{
				dPos[0] = (ptp_points[1][0] + cos(i * (PI / 180)) * cp_radious) * m_posRevisionX;
				dPos[1] = (ptp_points[1][1] + sin(i * (PI / 180)) * cp_radious) * m_posRevisionY;

				if (i == 0)
				{
					cp_start[0] = dPos[0];
					cp_start[1] = dPos[1];
				}
				AxmLineMove(ICoordinate, dPos, GetDlgItemDouble(IDC_EDT_X_INPUT_VEL), GetDlgItemDouble(IDC_EDT_X_INPUT_ACC), GetDlgItemDouble(IDC_EDT_X_INPUT_DEC));
			}

			//������ �۾��� ����� ����
			AxmContiEndNode(ICoordinate);
			//���Ӻ�����������
			AxmContiStart(ICoordinate, 0, 0);
			click_count = 0;
			pWinThread = AfxBeginThread(ThreadStart, this);
			return;//�Լ� ����
		}//else if (cp_btn == 1)
		else if (sign_btn == 1)
		{

		}//else if (sign_btn == 1)
		else if (vision_btn == 1)
		{

		}//else if (vision_btn == 1)
		else if (penta_btn == 1)
		{

		}//else if (penta_btn == 1)


		CDialogEx::OnLButtonDown(nFlags, point);
	}
}


void CMy220404_2017132036_testDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	double dXCommPos = 0.0, dXFeedPos = 0.0, dXFeedVel = 0.0;
	double dYCommPos = 0.0, dYFeedPos = 0.0, dYFeedVel = 0.0;
	DWORD dwRetCode = 0, dwValue = 0, dwStepMain = 0, dwStepSub = 0;
	WORD wGainP = 0, wGainI = 0, wGainD = 0;
	long lCheck = 0;
	CString strResult;
	CString strGainXP, strGainXI, strGainXD, strGainYP, strGainYI, strGainYD;

	switch (nIDEvent) {
	case TM_DISPLAY:
		// X, Y���� ����(Command)��ġ�� ��ȯ�մϴ�.
		AxmStatusGetCmdPos(m_lAxisNoX, &dXCommPos);
		if (m_dXOldCommPos != dXCommPos) {
			SetDlgItemDouble(IDC_STC_X_COMMAND_POS, dXCommPos);
			m_dXOldCommPos = dXCommPos;
		}
		AxmStatusGetCmdPos(m_lAxisNoY, &dYCommPos);
		if (m_dYOldCommPos != dYCommPos) {
			SetDlgItemDouble(IDC_STC_Y_COMMAND_POS, dYCommPos);
			m_dYOldCommPos = dYCommPos;
		}

		// X, Y���� ����(Feedback)��ġ�� ��ȯ�մϴ�.
		AxmStatusGetActPos(m_lAxisNoX, &dXFeedPos);
		if (m_dXOldFeedPos != dXFeedPos) {
			SetDlgItemDouble(IDC_STC_X_FEEDBACK_POS, dXFeedPos);
			m_dXOldFeedPos = dXFeedPos;
		}
		AxmStatusGetActPos(m_lAxisNoY, &dYFeedPos);
		if (m_dYOldFeedPos != dYFeedPos) {
			SetDlgItemDouble(IDC_STC_Y_FEEDBACK_POS, dYFeedPos);
			m_dYOldFeedPos = dYFeedPos;
		}

		// X, Y���� ���� �ӵ��� ��ȯ�մϴ�.
		AxmStatusReadVel(m_lAxisNoX, &dXFeedVel);
		if (m_dXOldFeedVel != dXFeedVel) {
			SetDlgItemDouble(IDC_STC_X_FEEDBACK_VEL, dXFeedVel);
			m_dXOldFeedVel = dXFeedVel;
		}
		AxmStatusReadVel(m_lAxisNoY, &dYFeedVel);
		if (m_dYOldFeedVel != dYFeedVel) {
			SetDlgItemDouble(IDC_STC_Y_FEEDBACK_VEL, dYFeedVel);
			m_dYOldFeedVel = dYFeedVel;
		}

		// X�� �ܺ� ���� �� ���� ���� ��ȣ���� ���¸� �����ɴϴ�.
		dwRetCode = AxmStatusReadMechanical(m_lAxisNoX, &dwValue);
		if (dwRetCode == AXT_RT_SUCCESS)
		{
			// + Limit
			lCheck = dwValue & 0x1;
			CheckDlgButton(IDC_CHK_X_LIMIT_P, lCheck);

			// - Limit
			lCheck = (dwValue >> 1) & 0x1;
			CheckDlgButton(IDC_CHK_X_LIMIT_N, lCheck);

			// Alarm
			lCheck = (dwValue >> 4) & 0x1;
			CheckDlgButton(IDC_CHK_X_ALARM, lCheck);

			// Inposition
			lCheck = (dwValue >> 5) & 0x1;
			CheckDlgButton(IDC_CHK_X_IN_POSITION, lCheck);

			// Emergency
			lCheck = (dwValue >> 6) & 0x1;
			CheckDlgButton(IDC_CHK_X_EMG, lCheck);

			// Home
			lCheck = (dwValue >> 7) & 0x1;
			CheckDlgButton(IDC_CHK_X_HOME_SIGNAL, lCheck);
		}

		// In Motion
		dwRetCode = AxmStatusReadMotion(m_lAxisNoX, &dwValue);
		if (dwRetCode == AXT_RT_SUCCESS)
		{
			lCheck = dwValue & QIDRIVE_STATUS_0;
			CheckDlgButton(IDC_CHK_X_IN_MOTION, lCheck);
			// �̵� ���̸� �̵� ���� ��Ʈ���� ��Ȱ��ȭ�ϰ�, �̵��� �����ϸ� Ȱ��ȭ�մϴ�.
			if (lCheck)
			{
				m_bXIsMoving = TRUE;
				m_sliX.EnableWindow(FALSE);
				m_btnXHomeSearch.EnableWindow(FALSE);
				m_btnPosMove.EnableWindow(FALSE);
			}
			else
			{
				m_bXIsMoving = FALSE;
				m_sliX.EnableWindow(TRUE);
				m_btnXHomeSearch.EnableWindow(TRUE);
			}
		}

		// Servo On
		dwRetCode = AxmSignalIsServoOn(m_lAxisNoX, &dwValue);
		CheckDlgButton(IDC_CHK_X_SERVO_ON, dwValue);

		// X���� P ���� Ʃ�װ��� ǥ���մϴ�.
		dwRetCode = AxlECatReadSdoFromAxisWord(m_lAxisNoX,
			GAIN_MAIN_ADDRESS_P, GAIN_SUB_ADDRESS, &wGainP);
		strGainXP.Format("%d", (wGainP / 10));
		m_stcXP.SetWindowText(strGainXP);

		// X���� D ���� Ʃ�װ��� ǥ���մϴ�.
		dwRetCode = AxlECatReadSdoFromAxisWord(m_lAxisNoX,
			GAIN_MAIN_ADDRESS_D, GAIN_SUB_ADDRESS, &wGainD);
		strGainXD.Format("%d", (wGainD / 10));
		m_stcXD.SetWindowText(strGainXD);
		// X���� I ���� Ʃ�װ��� ǥ���մϴ�.
		dwRetCode = AxlECatReadSdoFromAxisWord(m_lAxisNoX,
			GAIN_MAIN_ADDRESS_I, GAIN_SUB_ADDRESS, &wGainI);
		strGainXI.Format("%d", (wGainI / 10));
		m_stcXI.SetWindowText(strGainXI);

		// Y�� �ܺ� ���� �� ���� ���� ��ȣ���� ���¸� �����ɴϴ�.
		dwRetCode = AxmStatusReadMechanical(m_lAxisNoY, &dwValue);
		if (dwRetCode == AXT_RT_SUCCESS)
		{
			// + Limit
			lCheck = dwValue & 0x1;
			CheckDlgButton(IDC_CHK_Y_LIMIT_P, lCheck);

			// - Limit
			lCheck = (dwValue >> 1) & 0x1;
			CheckDlgButton(IDC_CHK_Y_LIMIT_N, lCheck);

			// Alarm
			lCheck = (dwValue >> 4) & 0x1;
			CheckDlgButton(IDC_CHK_Y_ALARM, lCheck);

			// Inposition
			lCheck = (dwValue >> 5) & 0x1;
			CheckDlgButton(IDC_CHK_Y_IN_POSTION, lCheck);

			// Emergency
			lCheck = (dwValue >> 6) & 0x1;
			CheckDlgButton(IDC_CHK_Y_EMG, lCheck);

			// Home
			lCheck = (dwValue >> 7) & 0x1;
			CheckDlgButton(IDC_CHK_Y_HOME_SIGNAL, lCheck);
		}
		// In Motion
		dwRetCode = AxmStatusReadMotion(m_lAxisNoY, &dwValue);
		if (dwRetCode == AXT_RT_SUCCESS)
		{
			lCheck = dwValue & QIDRIVE_STATUS_0;
			CheckDlgButton(IDC_CHK_Y_IN_MOTION, lCheck);
			// �̵� ���̸� �̵� ���� ��Ʈ���� ��Ȱ��ȭ�ϰ�, �̵��� �����ϸ� Ȱ��ȭ�մϴ�.
			if (lCheck)
			{
				m_bYIsMoving = TRUE;
				m_sliY.EnableWindow(FALSE);
				m_btnYHomeSearch.EnableWindow(FALSE);
				m_btnPosMove.EnableWindow(FALSE);
			}
			else
			{
				m_bYIsMoving = FALSE;
				m_sliY.EnableWindow(TRUE);
				m_btnYHomeSearch.EnableWindow(TRUE);
			}
		}

		// Servo On
		dwRetCode = AxmSignalIsServoOn(m_lAxisNoY, &dwValue);
		CheckDlgButton(IDC_CHK_Y_SERVO_ON, dwValue);

		// Y���� P ���� Ʃ�װ��� ǥ���մϴ�.
		dwRetCode = AxlECatReadSdoFromAxisWord(m_lAxisNoY,
			GAIN_MAIN_ADDRESS_P, GAIN_SUB_ADDRESS, &wGainP);
		strGainYP.Format("%d", (wGainP / 10));
		m_stcYP.SetWindowText(strGainYP);

		// Y���� D ���� Ʃ�װ��� ǥ���մϴ�.
		dwRetCode = AxlECatReadSdoFromAxisWord(m_lAxisNoY,
			GAIN_MAIN_ADDRESS_D, GAIN_SUB_ADDRESS, &wGainD);
		strGainYD.Format("%d", (wGainD / 10));
		m_stcYD.SetWindowText(strGainYD);

		// Y���� I ���� Ʃ�װ��� ǥ���մϴ�.
		dwRetCode = AxlECatReadSdoFromAxisWord(m_lAxisNoY,
			GAIN_MAIN_ADDRESS_I, GAIN_SUB_ADDRESS, &wGainI);
		strGainYI.Format("%d", (wGainI / 10));
		m_stcYI.SetWindowText(strGainYI);

		// X��� Y���� �̵��� ����Ǹ� ��ǥ�̵� ��ư�� Ȱ��ȭ
		if ((m_btnPosMove.IsWindowEnabled() == FALSE) && (m_bXIsMoving == FALSE)
			&& (m_bYIsMoving == FALSE))
		{
			m_btnPosMove.EnableWindow(TRUE);

			// ���� ��ġ�� �������� ��ǥ�� �̵��մϴ�.
			m_pointX = (int)(dXFeedPos / m_posRevisionX);
			m_pointY = (int)(dYFeedPos / m_posRevisionY);
			m_realPointX = (int)(dXFeedPos);
			m_realPointY = (int)(dYFeedPos);
			m_sliX.SetPos(m_pointX);
			m_sliY.SetPos(m_sliY.GetRangeMax() - m_pointY);
			Invalidate();
		}

		break;

	case TM_X_HOME_INFO:
		// ��� ������ ������ ���� ó���� �մϴ�.
		if (m_bXStop)
		{
			m_prgXHomeRate.EnableWindow(FALSE);
			m_bXIsMoving = FALSE;
			m_bXStop = FALSE;
			KillTimer(TM_X_HOME_INFO);
			AfxMessageBox("X Axis Home Search Stop.", MB_OK | MB_ICONQUESTION);
			m_prgXHomeRate.SetPos(0);
			break;
		}

		// X���� �����˻� �������� Ȯ���մϴ�.
		dwRetCode = AxmHomeGetRate(m_lAxisNoX, &dwStepMain, &dwStepSub);
		if (dwRetCode == AXT_RT_SUCCESS) {
			m_prgXHomeRate.SetPos(dwStepSub);
		}

		// X���� �����˻� ����� Ȯ���մϴ�.
		dwRetCode = AxmHomeGetResult(m_lAxisNoX, &dwValue);
		if (dwRetCode == AXT_RT_SUCCESS && ((dwValue == HOME_SUCCESS) ||
			(dwValue == HOME_SEARCHING)))
		{
			if (dwValue == HOME_SUCCESS)
			{
				// ���� �˻� �۾��� ���������� �����Կ� ���� �ļ� ó���� �մϴ�.
				m_prgXHomeRate.EnableWindow(FALSE);
				m_bXIsMoving = FALSE;
				KillTimer(TM_X_HOME_INFO);
				AfxMessageBox("X Axis Home Search Success.");
			}
		}
		else
		{
			// ���� �˻� �۾��� ������������ �����Կ� ���� �ļ� ó���� �մϴ�.
			strResult = TranslateAxmResult(dwRetCode);
			m_bXIsMoving = FALSE;
			m_prgXHomeRate.EnableWindow(FALSE);
			KillTimer(TM_X_HOME_INFO);
			AfxMessageBox("X Axis Home Search fail.\nError Msg : " + strResult, MB_OK
				| MB_ICONQUESTION);
			m_prgXHomeRate.SetPos(0);
		}
		break;

	case TM_Y_HOME_INFO:
		// ��� ������ ������ ���� ó���� �մϴ�.
		if (m_bYStop)
		{
			m_prgYHomeRate.EnableWindow(FALSE);
			m_bYIsMoving = FALSE;
			m_bYStop = FALSE;
			KillTimer(TM_Y_HOME_INFO);
			AfxMessageBox("Y Axis Home Search Stop.", MB_OK | MB_ICONQUESTION);
			m_prgYHomeRate.SetPos(0);
			break;
		}

		// Y���� �����˻� �������� Ȯ���մϴ�.
		dwRetCode = AxmHomeGetRate(m_lAxisNoY, &dwStepMain, &dwStepSub);
		if (dwRetCode == AXT_RT_SUCCESS) {
			m_prgYHomeRate.SetPos(dwStepSub);
		}

		// Y���� �����˻� ����� Ȯ���մϴ�.
		dwRetCode = AxmHomeGetResult(m_lAxisNoY, &dwValue);
		if (dwRetCode == AXT_RT_SUCCESS && ((dwValue == HOME_SUCCESS) ||
			(dwValue == HOME_SEARCHING)))
		{
			if (dwValue == HOME_SUCCESS)
			{
				// ���� �˻� �۾��� ���������� �����Կ� ���� �ļ� ó���� �մϴ�.
				m_prgYHomeRate.EnableWindow(FALSE);
				m_bYIsMoving = FALSE;
				KillTimer(TM_Y_HOME_INFO);
				AfxMessageBox("Y Axis Home Search Success.");
			}
		}
		else
		{
			// ���� �˻� �۾��� ������������ �����Կ� ���� �ļ� ó���� �մϴ�.
			strResult = TranslateAxmResult(dwRetCode);
			m_bYIsMoving = FALSE;
			m_prgYHomeRate.EnableWindow(FALSE);
			KillTimer(TM_Y_HOME_INFO);
			AfxMessageBox("Y Axis Home Search fail.\nError Msg : " + strResult, MB_OK
				| MB_ICONQUESTION);
			m_prgYHomeRate.SetPos(0);
		}
		break;
	}
	CDialogEx::OnTimer(nIDEvent);
}


void CMy220404_2017132036_testDlg::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	double dVel = 0.0, dAcc = 0.0, dDec = 0.0;
	DWORD dwRetCode = 0, dwStatus = 0;
	CString strResult;

	CSliderCtrl* pSlider = (CSliderCtrl*)pScrollBar;
	double dPosY = 0.0;
	int nSliderEndPosY = pSlider->GetRangeMax();
	if (nSBCode != SB_ENDSCROLL)
	{
		return;
	}

	// Y���� ���� ���̸� �� �۾��� �������� �ʽ��ϴ�.
	// AxmStatusReadMotion(..) : ���� ���� ��� ���� ���� ���� ��ȯ�մϴ�.
	// - dwStatus ��Ʈ���� �ǹ� : (0x00000001) 0 bit. ����̺� ���� ��
	// (0x00000002) 1 bit. ���� ��
	// ...
	dwRetCode = AxmStatusReadMotion(m_lAxisNoY, &dwStatus);
	if (dwRetCode != AXT_RT_SUCCESS || dwStatus & QIDRIVE_STATUS_0)
	{
		return;
	}

	switch (pSlider->GetDlgCtrlID())
	{
	case IDC_SLI_Y:
		m_pointY = nSliderEndPosY - pSlider->GetPos();
		break;
	}
	Invalidate();

	UpdateData(TRUE);

	dPosY = m_pointY * m_posRevisionY;
	m_realPointY = (int)dPosY;

	// �̵� �������� �� Edit Control���� �о�ɴϴ�.
	dVel = GetDlgItemDouble(IDC_EDT_Y_INPUT_VEL);
	dAcc = GetDlgItemDouble(IDC_EDT_Y_INPUT_ACC);
	dDec = GetDlgItemDouble(IDC_EDT_Y_INPUT_DEC);

	// Absolute ��ǥ�� �̵����� �����մϴ�.
	AxmMotSetAbsRelMode(m_lAxisNoY, POS_ABS_MODE);
	// �̵��� �����մϴ�.
	dwRetCode = AxmMoveStartPos(m_lAxisNoY, dPosY, dVel, dAcc, dDec);
	if (dwRetCode != AXT_RT_SUCCESS)
	{
		strResult = TranslateAxmResult(dwRetCode);
		AfxMessageBox("Y Axis AxmMoveStartPos fail.\nError Msg : " + strResult);
	}

	CDialog::OnVScroll(nSBCode, nPos, pScrollBar);
}


BOOL CMy220404_2017132036_testDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	// EscŰ �Է¿� ���� ó���� �մϴ�.
	if (((pMsg->message == WM_KEYDOWN) || (pMsg->message == WM_SYSKEYDOWN)) && (pMsg->wParam == VK_ESCAPE))
	{
		// �� �࿡ ���� ESTOP ����� �����մϴ�.

		OnBnClickedBtnBothEstop();

		return TRUE;
	}

	// EnterŰ �Է¿� ���� ó���� �մϴ�.
	if (((pMsg->message == WM_KEYDOWN) || (pMsg->message == WM_SYSKEYDOWN)) && (pMsg->wParam == VK_RETURN))
	{
		// �ƹ� �͵� �������� �ʽ��ϴ�.
		return TRUE;
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}


void CMy220404_2017132036_testDlg::OnBnClickedBtnLoadFile()
{
	CString temp;
	CFileDialog dlg(TRUE, "Mot", NULL, OFN_HIDEREADONLY, "AXM File (*.mot)|*.mot|AllFiles (*.*)|*.*||");

	if (dlg.DoModal() == IDOK) {
		LPTSTR strFilename;
		temp = dlg.GetPathName();
		strFilename = temp.GetBuffer(0);

		// �Լ� ���� ������ ������ Mot������ ���������� ����� ������ �ϰ� ����˴�
		if (AxmMotLoadParaAll(strFilename) != AXT_RT_SUCCESS)
		{
			AfxMessageBox("File load fail!");
		}
		else
		{
			AfxMessageBox("File load success!");
			UpdateState();
		}
	}
}


void CMy220404_2017132036_testDlg::OnBnClickedBtnBothHomeSearch()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	OnBnClickedBtnXHomeSearch();
	OnBnClickedBtnYHomeSearch();
}


void CMy220404_2017132036_testDlg::OnBnClickedBtnMoveZeroPos()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	double dPosX = 0.0, dPosY = 0.0;
	int nSliderEndPosY = m_sliY.GetRangeMax();

	// (0, 0) ��ǥ�� �̵��մϴ�.
	m_pointX = 0;
	m_pointY = 0;
	m_realPointX = 0;
	m_realPointY = 0;
	Invalidate();
	m_sliX.SetPos(m_pointX);
	m_sliY.SetPos(nSliderEndPosY - m_pointY);

	AxmMoveStartPos(m_lAxisNoX, dPosX,
		GetDlgItemDouble(IDC_EDT_X_INPUT_VEL),
		GetDlgItemDouble(IDC_EDT_X_INPUT_ACC),
		GetDlgItemDouble(IDC_EDT_X_INPUT_DEC));

	AxmMoveStartPos(m_lAxisNoY, dPosY,
		GetDlgItemDouble(IDC_EDT_Y_INPUT_VEL),
		GetDlgItemDouble(IDC_EDT_Y_INPUT_ACC),
		GetDlgItemDouble(IDC_EDT_Y_INPUT_DEC));
}


void CMy220404_2017132036_testDlg::OnBnClickedBtnBothEstop()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	OnBnClickedBtnXEstop();
	OnBnClickedBtnYEstop();
	GetDlgItem(IDC_RADIO_CP)->EnableWindow(TRUE);
	GetDlgItem(IDC_RADIO_PTP)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT1)->EnableWindow(TRUE);
	GetDlgItem(IDC_CHECK2)->EnableWindow(TRUE);
	GetDlgItem(IDC_VISION)->EnableWindow(TRUE);
	GetDlgItem(IDC_RADIO_HEART)->EnableWindow(TRUE);
}

BOOL CMy220404_2017132036_testDlg::UpdateState()
{
	DWORD dwRetCode = 0;
	double dUnit = 0.0, dMaxRangeX = 0.0, dMaxRangeY = 0.0;
	long lPulse = 0;

	// ��ǥ ����ġ���� ����մϴ�.
	dwRetCode = AxmMotGetMoveUnitPerPulse(m_lAxisNoX, &dUnit, &lPulse);
	dMaxRangeX = DEFAULT_REVISION_X * (double)(DEFAULT_PULSE / DEFAULT_UNIT) * (dUnit / lPulse);
	m_posRevisionX = dMaxRangeX / (m_rectStage.right - m_rectStage.left - (MARGIN * 2));

	dwRetCode = AxmMotGetMoveUnitPerPulse(m_lAxisNoY, &dUnit, &lPulse);
	dMaxRangeY = DEFAULT_REVISION_Y * (double)(DEFAULT_PULSE / DEFAULT_UNIT) * (dUnit / lPulse);
	m_posRevisionY = dMaxRangeY / (m_rectStage.bottom - m_rectStage.top - (MARGIN * 2));

	Invalidate();

	return TRUE;
}

void CMy220404_2017132036_testDlg::OnBnClickedRadioPtp()
{
	//��ư���� �÷��� ����
	ptp_btn = 1;
	rect_btn = 0;
	heart_btn = 0;
	star_btn = 0;
	cp_btn = 0;
	sign_btn = 0;
	vision_btn = 0;
	penta_btn = 0;
	btn_vision = false;
	vision_btn = 0;
	flag_vt = 0;
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	AfxMessageBox("�� ��ǥ�� �մ� ������ �׸��ϴ�.");

}


void CMy220404_2017132036_testDlg::OnBnClickedRadioRect()
{
	//��ư���� �÷��� ����
	ptp_btn = 0;
	rect_btn = 1;
	heart_btn = 0;
	star_btn = 0;
	cp_btn = 0;
	sign_btn = 0;
	vision_btn = 0;
	penta_btn = 0;
	btn_vision = false;
	vision_btn = 0;
	flag_vt = 0;
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CMy220404_2017132036_testDlg::OnBnClickedRadioHeart()
{
	//��ư���� �÷��� ����
	ptp_btn = 0;
	rect_btn = 0;
	heart_btn = 1;
	star_btn = 0;
	cp_btn = 0;
	sign_btn = 0;
	vision_btn = 0;
	penta_btn = 0;
	btn_vision = false;
	vision_btn = 0;
	flag_vt = 0;
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	AfxMessageBox("��ǥ�� �������� ������ �׸��ϴ�.");
}


void CMy220404_2017132036_testDlg::OnBnClickedRadioStar()
{//��ư���� �÷��� ����
	ptp_btn = 0;
	rect_btn = 0;
	heart_btn = 0;
	star_btn = 1;
	cp_btn = 0;
	sign_btn = 0;
	vision_btn = 0;
	penta_btn = 0;
	btn_vision = false;
	vision_btn = 0;
	flag_vt = 0;
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CMy220404_2017132036_testDlg::OnBnClickedRadioCp()
{//��ư���� �÷��� ����
	ptp_btn = 0;
	rect_btn = 0;
	heart_btn = 0;
	star_btn = 0;
	cp_btn = 1;
	sign_btn = 0;
	vision_btn = 0;
	penta_btn = 0;
	btn_vision = false;
	vision_btn = 0;
	flag_vt = 0;
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	AfxMessageBox("��ǥ�� �������� ���� �׸��ϴ�.");

}


void CMy220404_2017132036_testDlg::OnBnClickedRadioSign()
{//��ư���� �÷��� ����
	ptp_btn = 0;
	rect_btn = 0;
	heart_btn = 0;
	star_btn = 0;
	cp_btn = 0;
	sign_btn = 1;
	vision_btn = 0;
	penta_btn = 0;
	btn_vision = false;
	vision_btn = 0;
	flag_vt = 0;
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CMy220404_2017132036_testDlg::OnBnClickedRadioVision()
{
	//��ư���� �÷��� ����
	ptp_btn = 0;
	rect_btn = 0;
	heart_btn = 0;
	star_btn = 0;
	cp_btn = 0;
	sign_btn = 0;
	vision_btn = 1;
	penta_btn = 0;
	btn_vision = false;
	vision_btn = 0;
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CMy220404_2017132036_testDlg::OnBnClickedRadioPentagon()
{
	//��ư���� �÷��� ����
	ptp_btn = 0;
	rect_btn = 0;
	heart_btn = 0;
	star_btn = 0;
	cp_btn = 0;
	sign_btn = 0;
	vision_btn = 0;
	penta_btn = 1;
	btn_vision = false;
	vision_btn = 0;
	flag_vt = 0;
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}

UINT CMy220404_2017132036_testDlg::ThreadStart(LPVOID pParam)
{
	CMy220404_2017132036_testDlg* line_thread = (CMy220404_2017132036_testDlg*)AfxGetApp()->m_pMainWnd;
	double m_posrevX = 0.504051;
	double m_posrevY = 0.492911;

	CWnd* pWnd = AfxGetMainWnd();
	HWND hWnd = pWnd->m_hWnd;
	HDC h_screen_dc = ::GetDC(hWnd);
	CDC* dc = CDC::FromHandle(h_screen_dc);

	int kk = 0;
	kk = (line_thread->m_rectStage.left) + MARGIN;

	CPen pen;
	pen.CreatePen(PS_SOLID, 5, RGB(255, 0, 0));
	CPen* oldPen = dc->SelectObject(&pen);

	if (line_thread->ptp_btn)
	{
		int flag = 0;
		double dreal_posX = 0, dreal_posY = 0;
		double velocity_x1 = 0.0;
		double velocity_x2 = 0.0;
		double velocity_y1 = 0.0;
		double velocity_y2 = 0.0;

		while (1)
		{
			AxmStatusGetActPos(0, &dreal_posX);
			AxmStatusGetActPos(1, &dreal_posY);

			if (abs(line_thread->ptp_points[0][0] * line_thread->m_posRevisionX - dreal_posX) < 1.0 &&
				abs(line_thread->ptp_points[0][1] * line_thread->m_posRevisionX - dreal_posY) < 1.0)
			{
				if (flag == 0)
					flag = 1;
			}
			if (flag == 1)
			{
				dc->MoveTo((dreal_posX / m_posrevX) + kk, 532 - (dreal_posY / m_posrevY));
				dc->LineTo((dreal_posX / m_posrevX) + kk, 532 - (dreal_posY / m_posrevY));
			}
			AxmStatusReadVel(0, &velocity_x1);
			AxmStatusReadVel(1, &velocity_y1);

			Sleep(10);
			AxmStatusReadVel(1, &velocity_x2);
			AxmStatusReadVel(1, &velocity_y2);

			if ((velocity_x1 == 0 && velocity_x2 == 0) && (velocity_y1 == 0 && velocity_y2 == 0))
				break;
		}
	}
	else if (line_thread->cp_btn)
	{
		int flag = 0;
		double dreal_posX = 0, dreal_posY = 0;
		double velocity_x1 = 0.0;
		double velocity_x2 = 0.0;
		double velocity_y1 = 0.0;
		double velocity_y2 = 0.0;

		while (1)
		{
			AxmStatusGetActPos(0, &dreal_posX);
			AxmStatusGetActPos(1, &dreal_posY);

			printf("%.2f : %.2f    %.2f : %.2f\n", dreal_posX, line_thread->cp_start[0], dreal_posY, line_thread->cp_start[1]);

			if (abs(line_thread->cp_start[0] - dreal_posX) < 1.0 && abs(line_thread->cp_start[1] - dreal_posY) < 1.0)
			{
				if (flag == 0)
					flag = 1;
			}
			if (flag == 1)
			{
				dc->MoveTo((dreal_posX / m_posrevX) + kk, 532 - (dreal_posY / m_posrevY));
				dc->LineTo((dreal_posX / m_posrevX) + kk, 532 - (dreal_posY / m_posrevY));
			}
			AxmStatusReadVel(0, &velocity_x1);
			AxmStatusReadVel(1, &velocity_y1);

			Sleep(10);
			AxmStatusReadVel(1, &velocity_x2);
			AxmStatusReadVel(1, &velocity_y2);

			if ((velocity_x1 == 0 && velocity_x2 == 0) && (velocity_y1 == 0 && velocity_y2 == 0))
				break;
		}
	}
	else if (line_thread->heart_btn)
	{
		int flag = 0;
		double dreal_posX = 0, dreal_posY = 0;
		double velocity_x1 = 0.0;
		double velocity_x2 = 0.0;
		double velocity_y1 = 0.0;
		double velocity_y2 = 0.0;

		while (1)
		{
			AxmStatusGetActPos(0, &dreal_posX);
			AxmStatusGetActPos(1, &dreal_posY);

			printf("%.2f : %.2f    %.2f : %.2f\n", dreal_posX, line_thread->cp_start[0], dreal_posY, line_thread->cp_start[1]);

			if (abs(line_thread->cp_start[0] - dreal_posX) < 1.0 && abs(line_thread->cp_start[1] - dreal_posY) < 1.0)
			{
				if (flag == 0)
					flag = 1;
			}
			if (flag == 1)
			{
				dc->MoveTo((dreal_posX / m_posrevX) + kk, 532 - (dreal_posY / m_posrevY));
				dc->LineTo((dreal_posX / m_posrevX) + kk, 532 - (dreal_posY / m_posrevY));
			}
			AxmStatusReadVel(0, &velocity_x1);
			AxmStatusReadVel(1, &velocity_y1);

			Sleep(10);
			AxmStatusReadVel(1, &velocity_x2);
			AxmStatusReadVel(1, &velocity_y2);

			if ((velocity_x1 == 0 && velocity_x2 == 0) && (velocity_y1 == 0 && velocity_y2 == 0))
				break;
		}
	}
	else if (line_thread->vision_btn)
	{
		int flag = 0;
		double dreal_posX = 0, dreal_posY = 0;
		double velocity_x1 = 0.0;
		double velocity_x2 = 0.0;
		double velocity_y1 = 0.0;
		double velocity_y2 = 0.0;

		while (1)
		{
			AxmStatusGetActPos(0, &dreal_posX);
			AxmStatusGetActPos(1, &dreal_posY);

			printf("%.2f : %.2f    %.2f : %.2f\n", dreal_posX, line_thread->cp_start[0], dreal_posY, line_thread->cp_start[1]);

			if (abs(line_thread->cp_start[0] - dreal_posX) < 1.0 && abs(line_thread->cp_start[1] - dreal_posY) < 1.0)
			{
				if (flag == 0)
					flag = 1;
			}
			if (flag == 1)
			{
				dc->MoveTo((dreal_posX / m_posrevX) + kk, 532 - (dreal_posY / m_posrevY));
				dc->LineTo((dreal_posX / m_posrevX) + kk, 532 - (dreal_posY / m_posrevY));
			}
			AxmStatusReadVel(0, &velocity_x1);
			AxmStatusReadVel(1, &velocity_y1);

			Sleep(10);
			AxmStatusReadVel(1, &velocity_x2);
			AxmStatusReadVel(1, &velocity_y2);

			if ((velocity_x1 == 0 && velocity_x2 == 0) && (velocity_y1 == 0 && velocity_y2 == 0))
				break;
		}
		return 0;
	}
}


void CAboutDlg::OnBnClickedOk()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CDialogEx::OnOK();
}

void CMy220404_2017132036_testDlg::OnBnClickedMode()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

}


void CMy220404_2017132036_testDlg::OnBnClickedCheck2()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	mode = true;
}


void CMy220404_2017132036_testDlg::OnBnClickedBtDown()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CMy220404_2017132036_testDlg::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CWnd::OnKeyDown(nChar, nRepCnt, nFlags);
	switch (nChar)
	{
	case VK_SHIFT:
		OnBnClickedBtnBothEstop();
		AfxMessageBox(_T("KEY_UP"));
		break;
	}
	CDialogEx::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CMy220404_2017132036_testDlg::OnBnClickedVision()
{
	flag_bt = 1;
	GetDlgItem(IDC_RADIO_CP)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO_PTP)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT1)->EnableWindow(FALSE);
	GetDlgItem(IDC_CHECK2)->EnableWindow(FALSE);
	GetDlgItem(IDC_VISION)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO_HEART)->EnableWindow(FALSE);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	ptp_btn = 0;
	rect_btn = 0;
	heart_btn = 0;
	star_btn = 0;
	cp_btn = 0;
	sign_btn = 0;
	vision_btn = 0;
	penta_btn = 0;
	btn_vision = true;
	vision_btn = 1;
	capture = cvCaptureFromCAM(0);
	image = 0;
	flag = 0;

	double dPosX = 0.0, dPosY = 0.0;
	DWORD dwRetCode = 0, dwStatus = 0;
	CString strResult;
	int nSliderEndPosY = m_sliY.GetRangeMax();

	CWinThread* pWinThread; // ������ ����

	IAxis[0] = 0;
	IAxis[1] = 1;

	if (flag_align != 1)
	{
		ptp_points[1][0] = 208;
		ptp_points[1][1] = 207;
		Invalidate();
		m_sliX.SetPos(ptp_points[1][0]);
		m_sliY.SetPos(nSliderEndPosY - ptp_points[1][1]);//��������

		cp_dispos[0] = ptp_points[1][0];
		cp_dispos[1] = ptp_points[1][1];

		Invalidate();
		UpdateWindow();

		DWORD StatusX = FALSE, StatusY = FALSE;
		IAxis[0] = 0;  IAxis[1] = 1;

		//Queue�� ����� ������ ��� ������ �ʱ�ȭ
		AxmContiWriteClear(ICoordinate);
		//������ ��� ��ǥ�� ����
		AxmContiSetAxisMap(ICoordinate, IposSize, IAxis);
		//�����ġ, ������ġ ������� ����
		AxmContiSetAbsRelMode(ICoordinate, 0);
		//������ �۾��� ��� ����
		AxmContiBeginNode(ICoordinate);
		for (int i = 0; i < 360; i++)
		{
			dPos[0] = (ptp_points[1][0] + (170 * sin(5.0 * i * (PI / 180)))) * m_posRevisionX;
			dPos[1] = (ptp_points[1][1] + (170 * cos(i * (PI / 180)))) * m_posRevisionY;

			if (i == 0)
			{
				cp_start[0] = dPos[0];
				cp_start[1] = dPos[1];
			}
			AxmLineMove(ICoordinate, dPos, GetDlgItemDouble(IDC_EDT_X_INPUT_VEL), GetDlgItemDouble(IDC_EDT_X_INPUT_ACC), GetDlgItemDouble(IDC_EDT_X_INPUT_DEC));
		}
		AxmContiEndNode(ICoordinate);
		//���Ӻ�����������
		AxmContiStart(ICoordinate, 0, 0);
	}

	//pWinThread = AfxBeginThread(ThreadStart, this);
	if (flag_vt == 0)
	{
		CWinThread* pWinThreadW = AfxBeginThread(VisionWThreadStart, this);
	}
	CWinThread* pWinThreadP = AfxBeginThread(VisionPThreadStart, this);
	flag_vt++;
	return;//�Լ� ����
}

UINT CMy220404_2017132036_testDlg::VisionWThreadStart(LPVOID pParam)
{
	CMy220404_2017132036_testDlg* line_thread = (CMy220404_2017132036_testDlg*)AfxGetApp()->m_pMainWnd;
	CString strMsg;

	VideoCapture cap(0);
	cap.open(0);
	if (cap.isOpened())
	{
		while (line_thread->btn_vision)
		{

			Mat mat, img_out;
			Mat align;
			Mat diode;
			Mat Cs;
			Mat tft;
			Mat tft2;
			Mat whole;
			Mat result[6];

			cap.read(mat);

			double min_val[6], max_val[6];
			Point min_loc[6], max_loc[6];

			int w;
			int h;
			int tx;
			int ty;
			align = imread("C:/align.jpg", -1);
			w = align.cols;
			h = align.rows;
			mat.copyTo(img_out);

			cvtColor(mat, mat, COLOR_BGR2GRAY);
			cvtColor(align, align, COLOR_BGR2GRAY);
			matchTemplate(align, mat, result[0], TM_CCOEFF_NORMED); //TM_CCOEFF_NORMED //TM_SQDIFF //TM_SQDIFF_NORMED //TM_CCORR_NORMED

			minMaxLoc(result[0], &min_val[0], &max_val[0], &min_loc[0], &max_loc[0]);

			imshow("Vision", img_out);

			if (max_val[0] > 0.85)
			{
				Point top_left = max_loc[0];
				Point bottom_right = Point(top_left.x + w, top_left.y + h);
				tx = top_left.x;
				ty = top_left.y;
				string xs = to_string(top_left.x);
				string ys = to_string(top_left.y);
				string xy = "(" + xs + "," + ys + ")";
				rectangle(img_out, top_left, bottom_right, RGB(0, 0, 0), 2);
				putText(img_out, xy, Point(bottom_right), 1, 2, Scalar(0, 0, 0), 1, 8);
			}
			if (line_thread->flag == 0)
			{
				Point top_left = max_loc[0];
				Point bottom_right = Point(top_left.x + w, top_left.y + h);
				tx = top_left.x;
				ty = top_left.y;
				if (max_val[0] > 0.88)
				{
					Point top_left = max_loc[0];
					Point bottom_right = Point(top_left.x + w, top_left.y + h);

					line_thread->OnBnClickedBtnBothEstop();
					line_thread->delay();
					line_thread->flag_align = 1;
					if (((123 - tx) < 0) && ((130 - ty) < 0))
					{
						line_thread->mx = line_thread->m_realPointX / line_thread->m_posRevisionX - (((double)tx - 123) / 1.3);
						line_thread->my = line_thread->m_realPointY / line_thread->m_posRevisionY - (((double)ty - 130) / 1.1);

					}
					else if (((123 - tx) < 0) && ((130 - ty) > 0))
					{
						line_thread->mx = line_thread->m_realPointX / line_thread->m_posRevisionX - (((double)tx - 123) / 1.3);
						line_thread->my = line_thread->m_realPointY / line_thread->m_posRevisionY + (((double)130 - ty) / 1.1);
					}
					else if (((123 - tx) > 0) && ((130 - ty) > 0))
					{
						line_thread->mx = line_thread->m_realPointX / line_thread->m_posRevisionX + (((double)123 - tx) / 1.3);
						line_thread->my = line_thread->m_realPointY / line_thread->m_posRevisionY + (((double)130 - ty) / 1.1);
					}
					else if (((123 - tx) > 0) && ((130 - ty) < 0))
					{
						line_thread->mx = line_thread->m_realPointX / line_thread->m_posRevisionX + (((double)123 - tx) / 2);
						line_thread->my = line_thread->m_realPointY / line_thread->m_posRevisionY - (((double)ty - 130) / 1.1);
					}
					line_thread->aligned();
					line_thread->flag++;
				}
			}

			if (line_thread->flag == 1)
			{
				diode = imread("C:/diode.jpg", -1);
				Cs = imread("C:/Cs.jpg", -1);
				tft = imread("C:/tft.jpg", -1);
				tft2 = imread("C:/tft2.jpg", -1);
				whole = imread("C:/whole.jpg", -1);
				resize(mat, mat, Size(mat.cols / 2, mat.rows / 2));
				resize(diode, diode, Size(diode.cols / 2, diode.rows / 2));
				resize(Cs, Cs, Size(Cs.cols / 2, Cs.rows / 2));
				resize(tft, tft, Size(tft.cols / 2, tft.rows / 2));
				resize(tft2, tft2, Size(tft2.cols / 2, tft2.rows / 2));
				resize(whole, whole, Size(whole.cols / 2, whole.rows / 2));
				cvtColor(diode, diode, COLOR_BGR2GRAY);
				cvtColor(Cs, Cs, COLOR_BGR2GRAY);
				cvtColor(tft, tft, COLOR_BGR2GRAY);
				cvtColor(tft2, tft2, COLOR_BGR2GRAY);
				cvtColor(whole, whole, COLOR_BGR2GRAY);

				matchTemplate(diode, mat, result[1], TM_CCOEFF_NORMED);
				matchTemplate(Cs, mat, result[2], TM_CCOEFF_NORMED);
				matchTemplate(tft, mat, result[3], TM_CCOEFF_NORMED);
				matchTemplate(tft2, mat, result[4], TM_CCOEFF_NORMED);
				matchTemplate(whole, mat, result[5], TM_CCOEFF_NORMED);
				for (int i = 1; i < 6; i++) {
					minMaxLoc(result[i], &min_val[i], &max_val[i], &min_loc[i], &max_loc[i]);
				}
				if (max_val[1] > 0.8)
				{
					w = diode.cols;
					h = diode.rows;
					Point top_left = max_loc[1] * 2;
					Point bottom_right = Point(top_left.x + (w * 2), top_left.y + (h * 2));
					putText(img_out, "diode", bottom_right, 1, 2, Scalar(0, 0, 0), 1, 1);
					rectangle(img_out, top_left, bottom_right, Scalar(0, 255, 0), 2);
				}
				if (max_val[2] > 0.8)
				{
					w = Cs.cols;
					h = Cs.rows;
					Point top_left = max_loc[2] * 2;
					Point bottom_right = Point(top_left.x + (w * 2), top_left.y + (h * 2));
					putText(img_out, "Cs", bottom_right, 1, 2, Scalar(0, 0, 0), 1, 1);
					rectangle(img_out, top_left, bottom_right, Scalar(0, 255, 0), 2);
				}
				if (max_val[3] > 0.8)
				{
					w = tft.cols;
					h = tft.rows;
					Point top_left = max_loc[3] * 2;
					Point bottom_right = Point(top_left.x + (w * 2), top_left.y + (h * 2));
					putText(img_out, "tft", bottom_right, 1, 2, Scalar(0, 0, 0), 1, 1);
					rectangle(img_out, top_left, bottom_right, Scalar(0, 255, 0), 2);
				}
				if (max_val[4] > 0.8)
				{
					w = tft2.cols;
					h = tft2.rows;
					Point top_left = max_loc[4] * 2;
					Point bottom_right = Point(top_left.x + (w * 2), top_left.y + (h * 2));
					putText(img_out, "tft2", bottom_right, 1, 2, Scalar(0, 0, 0), 1, 1);
					rectangle(img_out, top_left, bottom_right, Scalar(0, 255, 0), 2);
				}
				if (max_val[1] > 0.8 && max_val[2] > 0.8 && max_val[3] > 0.8 && max_val[4] > 0.8)
				{
					w = whole.cols;
					h = whole.rows;
					Point top_left = max_loc[5] * 2;
					Point bottom_right = Point(top_left.x + (w * 2), top_left.y + (h * 2));
					rectangle(img_out, top_left, bottom_right, Scalar(0, 255, 0), 2);
				}
				else if (max_val[5] > 0.88 && max_val[1] < 0.8 && max_val[2] > 0.8 && max_val[3] > 0.8 && max_val[4] > 0.8)
				{
					w = whole.cols;
					h = whole.rows;
					Point top_left = max_loc[5] * 2;
					Point bottom_right = Point(top_left.x + (w * 2), top_left.y + (h * 2));
					rectangle(img_out, top_left, bottom_right, Scalar(0, 0, 255), 2);
					strMsg.Format("no diode!");
					AfxMessageBox(strMsg);
				}
				else if (max_val[5] > 0.88 && max_val[1] > 0.8 && max_val[2] < 0.8 && max_val[3] > 0.8 && max_val[4] > 0.8)
				{
					w = whole.cols;
					h = whole.rows;
					Point top_left = max_loc[5] * 2;
					Point bottom_right = Point(top_left.x + (w * 2), top_left.y + (h * 2));
					rectangle(img_out, top_left, bottom_right, Scalar(0, 0, 255), 2);
					strMsg.Format("no cap!");
					AfxMessageBox(strMsg);
				}
				else if (max_val[5] > 0.88 && max_val[1] > 0.8 && max_val[2] > 0.8 && max_val[3] < 0.8 && max_val[4] > 0.8)
				{
					w = whole.cols;
					h = whole.rows;
					Point top_left = max_loc[5] * 2;
					Point bottom_right = Point(top_left.x + (w * 2), top_left.y + (h * 2));
					rectangle(img_out, top_left, bottom_right, Scalar(0, 0, 255), 2);
					strMsg.Format("no switch_tft!");
					AfxMessageBox(strMsg);
				}
				else if (max_val[5] > 0.88 && max_val[1] > 0.8 && max_val[2] > 0.8 && max_val[3] > 0.8 && max_val[4] < 0.8)
				{
					w = whole.cols;
					h = whole.rows;
					Point top_left = max_loc[5] * 2;
					Point bottom_right = Point(top_left.x + (w * 2), top_left.y + (h * 2));
					rectangle(img_out, top_left, bottom_right, Scalar(0, 0, 255), 2);
					strMsg.Format("no drive_tft!");
					AfxMessageBox(strMsg);
				}
				else
				{
				}
				imshow("Vision", img_out);
			}
			cvWaitKey(10);
		}
	}

	destroyAllWindows();
	cap.release();
	return 0;
}

UINT CMy220404_2017132036_testDlg::VisionPThreadStart(LPVOID pParam)
{
	CMy220404_2017132036_testDlg* State;
	State = (CMy220404_2017132036_testDlg*)pParam;
	while (1)
	{
		cvGrabFrame(State->capture);
		State->image = cvQueryFrame(State->capture);
		State->m_CvvImage.CopyOf(State->image);
		CRect viewSize;
		State->m_pcstage.GetClientRect(&viewSize);
		State->m_CvvImage.DrawToHDC(State->m_pcstage.GetDC()->GetSafeHdc(), viewSize);
	}
	return 0;
}

void CMy220404_2017132036_testDlg::aligned()
{
	//if (flag_align == 1)
	//{
	//	int position = 0;
	//	double dPosX = mx, dPosY = my;
	//	flag_align = 0;
	//	Invalidate();
	//	m_sliX.SetPos(ptp_points[1][0]);
	//	m_sliY.SetPos(nSliderEndPosY - ptp_points[1][1]);//��������

	//	cp_dispos[0] = ptp_points[1][0];
	//	cp_dispos[1] = ptp_points[1][1];

	//	Invalidate();
	//	UpdateWindow();

	//	DWORD StatusX = FALSE, StatusY = FALSE;
	//	IAxis[0] = 0;  IAxis[1] = 1;

	//	//Queue�� ����� ������ ��� ������ �ʱ�ȭ
	//	AxmContiWriteClear(ICoordinate);
	//	//������ ��� ��ǥ�� ����
	//	AxmContiSetAxisMap(ICoordinate, IposSize, IAxis);
	//	//�����ġ, ������ġ ������� ����
	//	AxmContiSetAbsRelMode(ICoordinate, 0);
	//	//������ �۾��� ��� ����
	//	AxmContiBeginNode(ICoordinate);

	//	dPos[0] = (m_realPointX - mx) * m_posRevisionX;
	//	dPos[1] = (m_realPointY - my) * m_posRevisionY;

	//	if (dPos[0] < 0 || dPos[0]>199 || dPos[1] < 0 || dPos[1]>194)
	//	{
	//		AfxMessageBox("ǥ���� �� ���� ��ġ�Դϴ�.");
	//		position = 1;
	//	}

	//	if (position == 0)
	//	{
	//		AxmLineMove(ICoordinate, dPos, GetDlgItemDouble(IDC_EDT_X_INPUT_VEL), GetDlgItemDouble(IDC_EDT_X_INPUT_ACC), GetDlgItemDouble(IDC_EDT_X_INPUT_DEC));
	//		AxmContiEndNode(ICoordinate);
	//		//���Ӻ�����������
	//		AxmContiStart(ICoordinate, 0, 0);
	//	}
	//}
	CString strMovePosX, strMovePosY, strMsg;
	int iMovePosX, iMovePosY, iLimitPosX, iLimitPosY;
	double dPosX, dPosY;
	int nSliderEndPosY = m_sliY.GetRangeMax();
	// XY Stage���� �̵� �Ѱ����� ����մϴ�.
	iLimitPosX = (int)((m_rectStage.right - m_rectStage.left - (MARGIN * 2)) *
		m_posRevisionX);
	iLimitPosY = (int)((m_rectStage.bottom - m_rectStage.top - (MARGIN * 2)) *
		m_posRevisionX);
	flag_align = 0;
	iMovePosX = mx * m_posRevisionX;
	//�Է¹��� ��ǥ�� XY Stage�� ��� ��ǥ�̸� ���� �˾��� ����ϰ� �̵����� �ʽ��ϴ�.
	if (iMovePosX < 0 || iMovePosX > iLimitPosX)
	{
		strMsg.Format("�������� ���Դϴ�");
		AfxMessageBox(strMsg);
		return;
	}

	iMovePosY = my * m_posRevisionY;
	//�Է¹��� ��ǥ�� XY Stage�� ��� ��ǥ�̸� ���� �˾��� ����ϰ� �̵����� �ʽ��ϴ�.
	if (iMovePosY < 0 || iMovePosY > iLimitPosY)
	{
		strMsg.Format("�������� ���Դϴ�");
		AfxMessageBox(strMsg);
		return;
	}

	// �ش� ��ǥ�� �̵��մϴ�.
	m_pointX = (int)((double)iMovePosX / (m_posRevisionX));
	m_pointY = (int)((double)iMovePosY / (m_posRevisionY));
	Invalidate();
	m_sliX.SetPos(m_pointX);
	m_sliY.SetPos(nSliderEndPosY - m_pointY);

	dPosX = iMovePosX;
	m_realPointX = iMovePosX;
	AxmMoveStartPos(m_lAxisNoX, dPosX,
		GetDlgItemDouble(IDC_EDT_X_INPUT_VEL),
		GetDlgItemDouble(IDC_EDT_X_INPUT_ACC),
		GetDlgItemDouble(IDC_EDT_X_INPUT_DEC));

	dPosY = iMovePosY;
	m_realPointY = iMovePosY;
	AxmMoveStartPos(m_lAxisNoY, dPosY,
		GetDlgItemDouble(IDC_EDT_Y_INPUT_VEL),
		GetDlgItemDouble(IDC_EDT_Y_INPUT_ACC),
		GetDlgItemDouble(IDC_EDT_Y_INPUT_DEC));

	GetDlgItem(IDC_RADIO_CP)->EnableWindow(TRUE);
	GetDlgItem(IDC_RADIO_PTP)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT1)->EnableWindow(TRUE);
	GetDlgItem(IDC_CHECK2)->EnableWindow(TRUE);
	GetDlgItem(IDC_VISION)->EnableWindow(TRUE);
	GetDlgItem(IDC_RADIO_HEART)->EnableWindow(TRUE);
}
void CMy220404_2017132036_testDlg::delay()
{
	Sleep(300);
}