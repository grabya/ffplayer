#pragma once
extern "C"
{
#include "./ffplay/ffplay.h"
}
#include "afxcmn.h"
#include "afxwin.h"
#include "xskin/xskinbutton.h"
class CffplayerDlg : public CDialogEx
{
public:
	CffplayerDlg(CWnd* pParent = NULL);
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FFPLAYER_DIALOG };
#endif
private:
	DECLARE_MESSAGE_MAP()
	virtual void DoDataExchange(CDataExchange* pDX);
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBnClickedButtonOpenfile();
	afx_msg void OnBnClickedButtonPlay();
	afx_msg void OnClose();
	afx_msg void OnBnClickedButtonStop();
	afx_msg void OnBnClickedButtonPause();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnNMReleasedcaptureSliderplayprogress(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	static DWORD WINAPI playProcess(LPVOID pParam);
	static DWORD WINAPI consoleInputMonitor(LPVOID pParam);
    DWORD ProcessConsoleInput(INPUT_RECORD* pInputRec,DWORD dwInputs);
    void initConsole();
	void OnWndFullScreen();
	void CreateBtnSkin();
	void cleanupResource(bool isTerminaterPlayProcess);
	WINDOWPLACEMENT m_OldWndplacement;
    HANDLE m_playProcessHandler;
    HANDLE m_consoleMonitorProcessHandler;
	BOOL m_bIsFullScreen;
    BOOL m_bIsPlaying;
	CString m_strFileName;
	CBrush m_brushBackground;
	CBrush m_brushPlayarea;
	void * m_playHandler;
	int m_screenWidth;
	int m_screenHeight;
	CSliderCtrl m_sliderPlay;
	CSkinButton m_btnOpenFile;
	CSkinButton m_btnPlay;
	CSkinButton m_btnPause;
	CSkinButton m_btnStop;
	HANDLE m_hInputConsole;
    HANDLE m_hOutputConsole;
	HICON m_hIcon;
	RECT m_rc;
    int m_consoleWindowWidth;
};
