
// MCTSDlg.h: 头文件
//

#pragma once
#include"chess.h"

// CMCTSDlg 对话框
class CMCTSDlg : public CDialogEx
{
// 构造
public:
	CMCTSDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MCTS_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;
	chessboard board;
	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	void clearboard();
	void drawwhite(int line,int colum);
	void drawblack(int line, int colum);
	void printboard();
	void lock();
	void lock2();
	void unlock();
	void drawnow();
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnClickedChessboard0();
	afx_msg void OnClickedChessboard1();
	afx_msg void OnClickedChessboard2();
	afx_msg void OnClickedChessboard3();
	afx_msg void OnClickedChessboard4();
	afx_msg void OnClickedChessboard5();
	afx_msg void OnClickedChessboard6();
	afx_msg void OnClickedChessboard7();
	afx_msg void OnClickedChessboard8();
	afx_msg void OnClickedChessboard9();
	afx_msg void OnClickedChessboard10();
	afx_msg void OnClickedChessboard11();
	afx_msg void OnClickedChessboard12();
	afx_msg void OnClickedChessboard13();
	afx_msg void OnClickedChessboard14();
	afx_msg void OnClickedChessboard15();
	afx_msg void OnClickedChessboard16();
	afx_msg void OnClickedChessboard17();
	afx_msg void OnClickedChessboard18();
	afx_msg void OnClickedChessboard19();
	afx_msg void OnClickedChessboard20();
	afx_msg void OnClickedChessboard21();
	afx_msg void OnClickedChessboard22();
	afx_msg void OnClickedChessboard23();
	afx_msg void OnClickedChessboard24();
	afx_msg void OnClickedChessboard25();
	afx_msg void OnClickedChessboard26();
	afx_msg void OnClickedChessboard27();
	afx_msg void OnClickedChessboard28();
	afx_msg void OnClickedChessboard29();
	afx_msg void OnClickedChessboard30();
	afx_msg void OnClickedChessboard31();
	afx_msg void OnClickedChessboard32();
	afx_msg void OnClickedChessboard33();
	afx_msg void OnClickedChessboard34();
	afx_msg void OnClickedChessboard35();
	afx_msg void OnClickedChessboard36();
	afx_msg void OnClickedChessboard37();
	afx_msg void OnClickedChessboard38();
	afx_msg void OnClickedChessboard39();
	afx_msg void OnClickedChessboard40();
	afx_msg void OnClickedChessboard41();
	afx_msg void OnClickedChessboard42();
	afx_msg void OnClickedChessboard43();
	afx_msg void OnClickedChessboard44();
	afx_msg void OnClickedChessboard45();
	afx_msg void OnClickedChessboard46();
	afx_msg void OnClickedChessboard47();
	afx_msg void OnClickedChessboard48();
	afx_msg void OnClickedChessboard49();
	afx_msg void OnClickedChessboard50();
	afx_msg void OnClickedChessboard51();
	afx_msg void OnClickedChessboard52();
	afx_msg void OnClickedChessboard53();
	afx_msg void OnClickedChessboard54();
	afx_msg void OnClickedChessboard55();
	afx_msg void OnClickedChessboard56();
	afx_msg void OnClickedChessboard57();
	afx_msg void OnClickedChessboard58();
	afx_msg void OnClickedChessboard59();
	afx_msg void OnClickedChessboard60();
	afx_msg void OnClickedChessboard61();
	afx_msg void OnClickedChessboard62();
	afx_msg void OnClickedChessboard63();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton6();
	CStatic blacktext;
	CStatic whitetext;
};
