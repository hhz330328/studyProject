
// MCTSDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "MCTS.h"
#include "MCTSDlg.h"
#include "afxdialogex.h"
#include<vector>
using namespace std;
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

mctree tree;
int againstflag=0;
bool is_begin = 0;
// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMCTSDlg 对话框



CMCTSDlg::CMCTSDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MCTS_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMCTSDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, blackbox, blacktext);
	DDX_Control(pDX, whitebox, whitetext);
}

BEGIN_MESSAGE_MAP(CMCTSDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMCTSDlg::OnBnClickedButton1)
	ON_STN_CLICKED(chessboard0, &CMCTSDlg::OnClickedChessboard0)
	ON_STN_CLICKED(chessboard1, &CMCTSDlg::OnClickedChessboard1)
	ON_STN_CLICKED(chessboard2, &CMCTSDlg::OnClickedChessboard2)
	ON_STN_CLICKED(chessboard3, &CMCTSDlg::OnClickedChessboard3)
	ON_STN_CLICKED(chessboard4, &CMCTSDlg::OnClickedChessboard4)
	ON_STN_CLICKED(chessboard5, &CMCTSDlg::OnClickedChessboard5)
	ON_STN_CLICKED(chessboard6, &CMCTSDlg::OnClickedChessboard6)
	ON_STN_CLICKED(chessboard7, &CMCTSDlg::OnClickedChessboard7)
	ON_STN_CLICKED(chessboard8, &CMCTSDlg::OnClickedChessboard8)
	ON_STN_CLICKED(chessboard9, &CMCTSDlg::OnClickedChessboard9)
	ON_STN_CLICKED(chessboard10, &CMCTSDlg::OnClickedChessboard10)
	ON_STN_CLICKED(chessboard11, &CMCTSDlg::OnClickedChessboard11)
	ON_STN_CLICKED(chessboard12, &CMCTSDlg::OnClickedChessboard12)
	ON_STN_CLICKED(chessboard13, &CMCTSDlg::OnClickedChessboard13)
	ON_STN_CLICKED(chessboard14, &CMCTSDlg::OnClickedChessboard14)
	ON_STN_CLICKED(chessboard15, &CMCTSDlg::OnClickedChessboard15)
	ON_STN_CLICKED(chessboard16, &CMCTSDlg::OnClickedChessboard16)
	ON_STN_CLICKED(chessboard17, &CMCTSDlg::OnClickedChessboard17)
	ON_STN_CLICKED(chessboard18, &CMCTSDlg::OnClickedChessboard18)
	ON_STN_CLICKED(chessboard19, &CMCTSDlg::OnClickedChessboard19)
	ON_STN_CLICKED(chessboard20, &CMCTSDlg::OnClickedChessboard20)
	ON_STN_CLICKED(chessboard21, &CMCTSDlg::OnClickedChessboard21)
	ON_STN_CLICKED(chessboard22, &CMCTSDlg::OnClickedChessboard22)
	ON_STN_CLICKED(chessboard23, &CMCTSDlg::OnClickedChessboard23)
	ON_STN_CLICKED(chessboard24, &CMCTSDlg::OnClickedChessboard24)
	ON_STN_CLICKED(chessboard25, &CMCTSDlg::OnClickedChessboard25)
	ON_STN_CLICKED(chessboard26, &CMCTSDlg::OnClickedChessboard26)
	ON_STN_CLICKED(chessboard27, &CMCTSDlg::OnClickedChessboard27)
	ON_STN_CLICKED(chessboard28, &CMCTSDlg::OnClickedChessboard28)
	ON_STN_CLICKED(chessboard29, &CMCTSDlg::OnClickedChessboard29)
	ON_STN_CLICKED(chessboard30, &CMCTSDlg::OnClickedChessboard30)
	ON_STN_CLICKED(chessboard31, &CMCTSDlg::OnClickedChessboard31)
	ON_STN_CLICKED(chessboard32, &CMCTSDlg::OnClickedChessboard32)
	ON_STN_CLICKED(chessboard33, &CMCTSDlg::OnClickedChessboard33)
	ON_STN_CLICKED(chessboard34, &CMCTSDlg::OnClickedChessboard34)
	ON_STN_CLICKED(chessboard35, &CMCTSDlg::OnClickedChessboard35)
	ON_STN_CLICKED(chessboard36, &CMCTSDlg::OnClickedChessboard36)
	ON_STN_CLICKED(chessboard37, &CMCTSDlg::OnClickedChessboard37)
	ON_STN_CLICKED(chessboard38, &CMCTSDlg::OnClickedChessboard38)
	ON_STN_CLICKED(chessboard39, &CMCTSDlg::OnClickedChessboard39)
	ON_STN_CLICKED(chessboard40, &CMCTSDlg::OnClickedChessboard40)
	ON_STN_CLICKED(chessboard41, &CMCTSDlg::OnClickedChessboard41)
	ON_STN_CLICKED(chessboard42, &CMCTSDlg::OnClickedChessboard42)
	ON_STN_CLICKED(chessboard43, &CMCTSDlg::OnClickedChessboard43)
	ON_STN_CLICKED(chessboard44, &CMCTSDlg::OnClickedChessboard44)
	ON_STN_CLICKED(chessboard45, &CMCTSDlg::OnClickedChessboard45)
	ON_STN_CLICKED(chessboard46, &CMCTSDlg::OnClickedChessboard46)
	ON_STN_CLICKED(chessboard47, &CMCTSDlg::OnClickedChessboard47)
	ON_STN_CLICKED(chessboard48, &CMCTSDlg::OnClickedChessboard48)
	ON_STN_CLICKED(chessboard49, &CMCTSDlg::OnClickedChessboard49)
	ON_STN_CLICKED(chessboard50, &CMCTSDlg::OnClickedChessboard50)
	ON_STN_CLICKED(chessboard51, &CMCTSDlg::OnClickedChessboard51)
	ON_STN_CLICKED(chessboard52, &CMCTSDlg::OnClickedChessboard52)
	ON_STN_CLICKED(chessboard53, &CMCTSDlg::OnClickedChessboard53)
	ON_STN_CLICKED(chessboard54, &CMCTSDlg::OnClickedChessboard54)
	ON_STN_CLICKED(chessboard55, &CMCTSDlg::OnClickedChessboard55)
	ON_STN_CLICKED(chessboard56, &CMCTSDlg::OnClickedChessboard56)
	ON_STN_CLICKED(chessboard57, &CMCTSDlg::OnClickedChessboard57)
	ON_STN_CLICKED(chessboard58, &CMCTSDlg::OnClickedChessboard58)
	ON_STN_CLICKED(chessboard59, &CMCTSDlg::OnClickedChessboard59)
	ON_STN_CLICKED(chessboard60, &CMCTSDlg::OnClickedChessboard60)
	ON_STN_CLICKED(chessboard61, &CMCTSDlg::OnClickedChessboard61)
	ON_STN_CLICKED(chessboard62, &CMCTSDlg::OnClickedChessboard62)
	ON_STN_CLICKED(chessboard63, &CMCTSDlg::OnClickedChessboard63)
	ON_BN_CLICKED(IDC_BUTTON5, &CMCTSDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON4, &CMCTSDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON2, &CMCTSDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMCTSDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON7, &CMCTSDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON6, &CMCTSDlg::OnBnClickedButton6)
END_MESSAGE_MAP()


// CMCTSDlg 消息处理程序

BOOL CMCTSDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	board.ini();
	CWnd* pwnd = GetDlgItem(IDC_BUTTON5);
	pwnd->EnableWindow(false);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMCTSDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMCTSDlg::OnPaint()
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
HCURSOR CMCTSDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}






int curplayer=black;



void CMCTSDlg::clearboard()
{
	for (int i = 0; i < 64; i++)
	{
		CWnd* pwnd = GetDlgItem(chessboard0 + i);
		CDC* pdc = pwnd->GetDC();
		CRect rec;
		pwnd->GetWindowRect(rec);
		CPen pen(0, 1, RGB(165, 135, 46));
		CBrush brush(RGB(165, 135, 46));
		pdc->SelectObject(pen);
		pdc->SelectObject(brush);
		pdc->Rectangle(0, 0, rec.Width(), rec.Height());
		ReleaseDC(pdc);
	}
}

void CMCTSDlg::drawwhite(int line, int colum)
{
	int temp = line * 8 + colum;
	CWnd* pwnd = GetDlgItem(chessboard0 + temp);
	CDC* pdc = pwnd->GetDC();
	CRect rec;
	pwnd->GetWindowRect(rec);
	CPen pen(0, 1, RGB(255, 255, 255));
	CBrush brush(RGB(255, 255, 255));
	pdc->SelectObject(pen);
	pdc->SelectObject(brush);
	pdc->Ellipse(0, 0, rec.Width(), rec.Height());
	ReleaseDC(pdc);
}

void CMCTSDlg::drawblack(int line, int colum)
{
	int temp = line * 8 + colum;
	CWnd* pwnd = GetDlgItem(chessboard0 + temp);
	CDC* pdc = pwnd->GetDC();
	CRect rec;
	pwnd->GetWindowRect(rec);
	CPen pen(0, 1, RGB(0, 0, 0));
	CBrush brush(RGB(0, 0, 0));
	pdc->SelectObject(pen);
	pdc->SelectObject(brush);
	pdc->Ellipse(0, 0, rec.Width(), rec.Height());
	ReleaseDC(pdc);
}

void CMCTSDlg::printboard()
{
	clearboard();
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
			{
				drawwhite(i, j);
			}
			else if (board.board[i][j] == black)
			{
				drawblack(i, j);
			}
		}
	}
}

void CMCTSDlg::lock()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			int temp = i * 8 + j;			
			CWnd* pwnd = GetDlgItem(chessboard0 + temp);
			pwnd->EnableWindow(false);						
		}
	}
}
void CMCTSDlg::lock2()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			int temp = i * 8 + j;
			CWnd* pwnd = GetDlgItem(chessboard0 + temp);
			pwnd->EnableWindow(false);
		}
	}
	bool flag;
	vector<int> pos;
	flag = board.getenablepos(curplayer, pos);
	if (flag == true)
	{
		for (int i = 0; i < pos.size(); i++)
		{
			CWnd* pwnd = GetDlgItem(chessboard0 + pos[i]);
			CRect rec;
			pwnd->GetWindowRect(rec);
			CDC* pdc = pwnd->GetDC();
			CPen pen(0, 1, RGB(0, 255, 0));
			CBrush brush(RGB(0, 255, 0));
			pdc->SelectObject(pen);
			pdc->SelectObject(brush);
			pdc->Ellipse(15, 15, rec.Width() - 15, rec.Height() - 15);
			ReleaseDC(pdc);
		}
	}
}

void CMCTSDlg::unlock()
{
	bool flag;
	vector<int> pos;
	flag = board.getenablepos(curplayer, pos);
	if (flag == true)
	{
		for (int i = 0; i < pos.size(); i++)
		{
			CWnd* pwnd = GetDlgItem(chessboard0 + pos[i]);
			CRect rec;
			pwnd->GetWindowRect(rec);
			CDC* pdc = pwnd->GetDC();
			CPen pen(0, 1, RGB(0, 255, 0));
			CBrush brush(RGB(0, 255, 0));
			pdc->SelectObject(pen);
			pdc->SelectObject(brush);
			pdc->Ellipse(15, 15, rec.Width()-15, rec.Height()-15);
			ReleaseDC(pdc);
			pwnd->EnableWindow(true);
		}
	}
	else
	{
		CWnd* pwnd = GetDlgItem(IDC_BUTTON5);
		pwnd->EnableWindow(true);
	}
}

void CMCTSDlg::drawnow()
{
	CWnd* pwnd = GetDlgItem(chessboard64);
	CRect rec;
	pwnd->GetWindowRect(rec);
	CDC* pdc = pwnd->GetDC();
	if (curplayer == white)
	{
		CPen pen(0, 1, RGB(255, 255, 255));
		CBrush brush(RGB(255, 255, 255));
		pdc->SelectObject(pen);
		pdc->SelectObject(brush);
		pdc->Ellipse(0, 0, rec.Width(), rec.Height());
		ReleaseDC(pdc);
	}
	else if (curplayer == black)
	{
		CPen pen(0, 1, RGB(0, 0, 0));
		CBrush brush(RGB(0, 0,0));
		pdc->SelectObject(pen);
		pdc->SelectObject(brush);
		pdc->Ellipse(0, 0, rec.Width(), rec.Height());
		ReleaseDC(pdc);
	}
}



void CMCTSDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	blacktext.SetWindowTextW(_T("0"));
	whitetext.SetWindowTextW(_T("0"));
	tree.clear();
	board.clear();
	clearboard();
	printboard();
	curplayer = black;
	is_begin = 0;
	lock();
}








void CMCTSDlg::OnBnClickedButton5()   //弃权
{
	// TODO: 在此添加控件通知处理程序代码
	tree.against(-1, -1);
	lock();
	curplayer = 0 - curplayer;
	drawnow();
	if (againstflag == 1)
	{
		int line;
		int colun;
		clearboard();
		printboard();
		lock2();
		tree.sim();
		tree.select(line, colun);
		if (line == -1)
		{
			curplayer = 0 - curplayer;
		}
		else
		{
			board.board[line][colun] = curplayer;
			board.reserve(line * 8 + colun, curplayer);
			curplayer = 0 - curplayer;
		}
	}
	clearboard();
	printboard();
	unlock();
	int countw = 0;
	int countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	CString sss;
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
}


void CMCTSDlg::OnBnClickedButton4()	//先手
{
	// TODO: 在此添加控件通知处理程序代码
	tree.setcolour(white);
	drawnow();
	board.clear();
	clearboard();
	printboard();
	curplayer = black;
	unlock();
}


void CMCTSDlg::OnBnClickedButton2()	//后手
{
	// TODO: 在此添加控件通知处理程序代码
	lock();
	lock2();
	drawnow();
	if (againstflag == 1)
	{
		is_begin = 1;
		node* temp = new node(-1, -1);
		board.getenablepos(black, temp->enablepos);
		for (int i = 0; i < temp->enablepos.size(); i++)
		{
			temp->visit.push_back(0);
		}
		tree.setroot(temp);
		int line;
		int col;
		tree.setboard(board);
		tree.setcolour(black);
		tree.sim();
		tree.select(line, col);
		board.board[line][col] = black;
		board.reserve(line * 8 + col, black);
		clearboard();
		printboard();
		curplayer = 0 - curplayer;
		unlock();
	}
	
}


void CMCTSDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	lock();
	int countw = 0;
	int countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	CString tt;
	CString s("");
	s = s + _T("黑棋数量：");
	tt.Format(_T("%d"), countb);
	s = s + tt;
	s = s + _T("   白棋数量：");
	tt.Format(_T("%d"), countw);
	s = s + tt;
	if (countw > countb)
		tt = _T("\n白棋胜利！");
	else if (countw < countb)
		tt = _T("\n黑棋胜利！");
	else if (countw == countb)
		tt = _T("\n平局！");
	s = s + tt;
	MessageBox(s);

}


void CMCTSDlg::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
	againstflag = 1;
	CWnd* pwnd = GetDlgItem(IDC_BUTTON2);
	pwnd->EnableWindow(true);
}


void CMCTSDlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	againstflag = 0;
	CWnd* pwnd = GetDlgItem(IDC_BUTTON2);
	pwnd->EnableWindow(false);
}


void CMCTSDlg::OnClickedChessboard0()
{
	// TODO: 在此添加控件通知处理程序代码
	CString sss;
	int temp = 0;
	int line = temp / 8;
	int colun = temp % 8;
	board.board[line][colun] = curplayer;
	board.reserve(temp, curplayer);
	if (curplayer == white)
	{
		drawwhite(line, colun);
	}
	else
	{
		drawblack(line, colun);
	}
	lock();
	curplayer = 0 - curplayer;
	int countw = 0;
	int countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
	if (againstflag == 1)
	{
		if (is_begin == 0)
		{
			is_begin = 1;
			tree.clear();
			tree.setboard(board);
			node* p = new node(line, colun);
			tree.setroot(p);
			tree.setcolour(white);
			board.getenablepos(white, p->enablepos);
			for (int i = 0; i < p->enablepos.size(); i++)
			{
				p->visit.push_back(0);
			}
		}
		else
		{
			tree.against(line, colun);
		}
		clearboard();
		printboard();
		lock2();
		tree.sim();
		tree.select(line, colun);
		if (line == -1)
		{
			curplayer = 0 - curplayer;
		}
		else
		{
			board.board[line][colun] = curplayer;
			board.reserve(line * 8 + colun, curplayer);
			curplayer = 0 - curplayer;
		}
	}
	clearboard();
	printboard();
	unlock();
	countw = 0;
	countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
}
void CMCTSDlg::OnClickedChessboard1()
{
	// TODO: 在此添加控件通知处理程序代码
	CString sss;
	int temp = 1;
	int line = temp / 8;
	int colun = temp % 8;
	board.board[line][colun] = curplayer;
	board.reserve(temp, curplayer);
	if (curplayer == white)
	{
		drawwhite(line, colun);
	}
	else
	{
		drawblack(line, colun);
	}
	lock();
	curplayer = 0 - curplayer;
	int countw = 0;
	int countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
	if (againstflag == 1)
	{
		if (is_begin == 0)
		{
			is_begin = 1;
			tree.clear();
			tree.setboard(board);
			node* p = new node(line, colun);
			tree.setroot(p);
			tree.setcolour(white);
			board.getenablepos(white, p->enablepos);
			for (int i = 0; i < p->enablepos.size(); i++)
			{
				p->visit.push_back(0);
			}
		}
		else
		{
			tree.against(line, colun);
		}
		clearboard();
		printboard();
		lock2();
		tree.sim();
		tree.select(line, colun);
		if (line == -1)
		{
			curplayer = 0 - curplayer;
		}
		else
		{
			board.board[line][colun] = curplayer;
			board.reserve(line * 8 + colun, curplayer);
			curplayer = 0 - curplayer;
		}
	}
	clearboard();
	printboard();
	unlock();
	countw = 0;
	countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
}
void CMCTSDlg::OnClickedChessboard2()
{
	// TODO: 在此添加控件通知处理程序代码
	CString sss;
	int temp = 2;
	int line = temp / 8;
	int colun = temp % 8;
	board.board[line][colun] = curplayer;
	board.reserve(temp, curplayer);
	if (curplayer == white)
	{
		drawwhite(line, colun);
	}
	else
	{
		drawblack(line, colun);
	}
	lock();
	curplayer = 0 - curplayer;
	int countw = 0;
	int countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
	if (againstflag == 1)
	{
		if (is_begin == 0)
		{
			is_begin = 1;
			tree.clear();
			tree.setboard(board);
			node* p = new node(line, colun);
			tree.setroot(p);
			tree.setcolour(white);
			board.getenablepos(white, p->enablepos);
			for (int i = 0; i < p->enablepos.size(); i++)
			{
				p->visit.push_back(0);
			}
		}
		else
		{
			tree.against(line, colun);
		}
		clearboard();
		printboard();
		lock2();
		tree.sim();
		tree.select(line, colun);
		if (line == -1)
		{
			curplayer = 0 - curplayer;
		}
		else
		{
			board.board[line][colun] = curplayer;
			board.reserve(line * 8 + colun, curplayer);
			curplayer = 0 - curplayer;
		}
	}
	clearboard();
	printboard();
	unlock();
	countw = 0;
	countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
}
void CMCTSDlg::OnClickedChessboard3()
{
	// TODO: 在此添加控件通知处理程序代码
	CString sss;
	int temp = 3;
	int line = temp / 8;
	int colun = temp % 8;
	board.board[line][colun] = curplayer;
	board.reserve(temp, curplayer);
	if (curplayer == white)
	{
		drawwhite(line, colun);
	}
	else
	{
		drawblack(line, colun);
	}
	lock();
	curplayer = 0 - curplayer;
	int countw = 0;
	int countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
	if (againstflag == 1)
	{
		if (is_begin == 0)
		{
			is_begin = 1;
			tree.clear();
			tree.setboard(board);
			node* p = new node(line, colun);
			tree.setroot(p);
			tree.setcolour(white);
			board.getenablepos(white, p->enablepos);
			for (int i = 0; i < p->enablepos.size(); i++)
			{
				p->visit.push_back(0);
			}
		}
		else
		{
			tree.against(line, colun);
		}
		clearboard();
		printboard();
		lock2();
		tree.sim();
		tree.select(line, colun);
		if (line == -1)
		{
			curplayer = 0 - curplayer;
		}
		else
		{
			board.board[line][colun] = curplayer;
			board.reserve(line * 8 + colun, curplayer);
			curplayer = 0 - curplayer;
		}
	}
	clearboard();
	printboard();
	unlock();
	countw = 0;
	countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
}
void CMCTSDlg::OnClickedChessboard4()
{
	// TODO: 在此添加控件通知处理程序代码
	CString sss;
	int temp = 4;
	int line = temp / 8;
	int colun = temp % 8;
	board.board[line][colun] = curplayer;
	board.reserve(temp, curplayer);
	if (curplayer == white)
	{
		drawwhite(line, colun);
	}
	else
	{
		drawblack(line, colun);
	}
	lock();
	curplayer = 0 - curplayer;
	int countw = 0;
	int countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
	if (againstflag == 1)
	{
		if (is_begin == 0)
		{
			is_begin = 1;
			tree.clear();
			tree.setboard(board);
			node* p = new node(line, colun);
			tree.setroot(p);
			tree.setcolour(white);
			board.getenablepos(white, p->enablepos);
			for (int i = 0; i < p->enablepos.size(); i++)
			{
				p->visit.push_back(0);
			}
		}
		else
		{
			tree.against(line, colun);
		}
		clearboard();
		printboard();
		lock2();
		tree.sim();
		tree.select(line, colun);
		if (line == -1)
		{
			curplayer = 0 - curplayer;
		}
		else
		{
			board.board[line][colun] = curplayer;
			board.reserve(line * 8 + colun, curplayer);
			curplayer = 0 - curplayer;
		}
	}
	clearboard();
	printboard();
	unlock();
	countw = 0;
	countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
}
void CMCTSDlg::OnClickedChessboard5()
{
	// TODO: 在此添加控件通知处理程序代码
	CString sss;
	int temp = 5;
	int line = temp / 8;
	int colun = temp % 8;
	board.board[line][colun] = curplayer;
	board.reserve(temp, curplayer);
	if (curplayer == white)
	{
		drawwhite(line, colun);
	}
	else
	{
		drawblack(line, colun);
	}
	lock();
	curplayer = 0 - curplayer;
	int countw = 0;
	int countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
	if (againstflag == 1)
	{
		if (is_begin == 0)
		{
			is_begin = 1;
			tree.clear();
			tree.setboard(board);
			node* p = new node(line, colun);
			tree.setroot(p);
			tree.setcolour(white);
			board.getenablepos(white, p->enablepos);
			for (int i = 0; i < p->enablepos.size(); i++)
			{
				p->visit.push_back(0);
			}
		}
		else
		{
			tree.against(line, colun);
		}
		clearboard();
		printboard();
		lock2();
		tree.sim();
		tree.select(line, colun);
		if (line == -1)
		{
			curplayer = 0 - curplayer;
		}
		else
		{
			board.board[line][colun] = curplayer;
			board.reserve(line * 8 + colun, curplayer);
			curplayer = 0 - curplayer;
		}
	}
	clearboard();
	printboard();
	unlock();
	countw = 0;
	countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
}
void CMCTSDlg::OnClickedChessboard6()
{
	// TODO: 在此添加控件通知处理程序代码
	CString sss;
	int temp = 6;
	int line = temp / 8;
	int colun = temp % 8;
	board.board[line][colun] = curplayer;
	board.reserve(temp, curplayer);
	if (curplayer == white)
	{
		drawwhite(line, colun);
	}
	else
	{
		drawblack(line, colun);
	}
	lock();
	curplayer = 0 - curplayer;
	int countw = 0;
	int countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
	if (againstflag == 1)
	{
		if (is_begin == 0)
		{
			is_begin = 1;
			tree.clear();
			tree.setboard(board);
			node* p = new node(line, colun);
			tree.setroot(p);
			tree.setcolour(white);
			board.getenablepos(white, p->enablepos);
			for (int i = 0; i < p->enablepos.size(); i++)
			{
				p->visit.push_back(0);
			}
		}
		else
		{
			tree.against(line, colun);
		}
		clearboard();
		printboard();
		lock2();
		tree.sim();
		tree.select(line, colun);
		if (line == -1)
		{
			curplayer = 0 - curplayer;
		}
		else
		{
			board.board[line][colun] = curplayer;
			board.reserve(line * 8 + colun, curplayer);
			curplayer = 0 - curplayer;
		}
	}
	clearboard();
	printboard();
	unlock();
	countw = 0;
	countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
}
void CMCTSDlg::OnClickedChessboard7()
{
	// TODO: 在此添加控件通知处理程序代码
	CString sss;
	int temp = 7;
	int line = temp / 8;
	int colun = temp % 8;
	board.board[line][colun] = curplayer;
	board.reserve(temp, curplayer);
	if (curplayer == white)
	{
		drawwhite(line, colun);
	}
	else
	{
		drawblack(line, colun);
	}
	lock();
	curplayer = 0 - curplayer;
	int countw = 0;
	int countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
	if (againstflag == 1)
	{
		if (is_begin == 0)
		{
			is_begin = 1;
			tree.clear();
			tree.setboard(board);
			node* p = new node(line, colun);
			tree.setroot(p);
			tree.setcolour(white);
			board.getenablepos(white, p->enablepos);
			for (int i = 0; i < p->enablepos.size(); i++)
			{
				p->visit.push_back(0);
			}
		}
		else
		{
			tree.against(line, colun);
		}
		clearboard();
		printboard();
		lock2();
		tree.sim();
		tree.select(line, colun);
		if (line == -1)
		{
			curplayer = 0 - curplayer;
		}
		else
		{
			board.board[line][colun] = curplayer;
			board.reserve(line * 8 + colun, curplayer);
			curplayer = 0 - curplayer;
		}
	}
	clearboard();
	printboard();
	unlock();
	countw = 0;
	countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
}
void CMCTSDlg::OnClickedChessboard8()
{
	// TODO: 在此添加控件通知处理程序代码
	CString sss;
	int temp = 8;
	int line = temp / 8;
	int colun = temp % 8;
	board.board[line][colun] = curplayer;
	board.reserve(temp, curplayer);
	if (curplayer == white)
	{
		drawwhite(line, colun);
	}
	else
	{
		drawblack(line, colun);
	}
	lock();
	curplayer = 0 - curplayer;
	int countw = 0;
	int countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
	if (againstflag == 1)
	{
		if (is_begin == 0)
		{
			is_begin = 1;
			tree.clear();
			tree.setboard(board);
			node* p = new node(line, colun);
			tree.setroot(p);
			tree.setcolour(white);
			board.getenablepos(white, p->enablepos);
			for (int i = 0; i < p->enablepos.size(); i++)
			{
				p->visit.push_back(0);
			}
		}
		else
		{
			tree.against(line, colun);
		}
		clearboard();
		printboard();
		lock2();
		tree.sim();
		tree.select(line, colun);
		if (line == -1)
		{
			curplayer = 0 - curplayer;
		}
		else
		{
			board.board[line][colun] = curplayer;
			board.reserve(line * 8 + colun, curplayer);
			curplayer = 0 - curplayer;
		}
	}
	clearboard();
	printboard();
	unlock();
	countw = 0;
	countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
}
void CMCTSDlg::OnClickedChessboard9()
{
	// TODO: 在此添加控件通知处理程序代码
	CString sss;
	int temp = 9;
	int line = temp / 8;
	int colun = temp % 8;
	board.board[line][colun] = curplayer;
	board.reserve(temp, curplayer);
	if (curplayer == white)
	{
		drawwhite(line, colun);
	}
	else
	{
		drawblack(line, colun);
	}
	lock();
	curplayer = 0 - curplayer;
	int countw = 0;
	int countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
	if (againstflag == 1)
	{
		if (is_begin == 0)
		{
			is_begin = 1;
			tree.clear();
			tree.setboard(board);
			node* p = new node(line, colun);
			tree.setroot(p);
			tree.setcolour(white);
			board.getenablepos(white, p->enablepos);
			for (int i = 0; i < p->enablepos.size(); i++)
			{
				p->visit.push_back(0);
			}
		}
		else
		{
			tree.against(line, colun);
		}
		clearboard();
		printboard();
		lock2();
		tree.sim();
		tree.select(line, colun);
		if (line == -1)
		{
			curplayer = 0 - curplayer;
		}
		else
		{
			board.board[line][colun] = curplayer;
			board.reserve(line * 8 + colun, curplayer);
			curplayer = 0 - curplayer;
		}
	}
	clearboard();
	printboard();
	unlock();
	countw = 0;
	countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
}
void CMCTSDlg::OnClickedChessboard10()
{
	// TODO: 在此添加控件通知处理程序代码
	CString sss;
	int temp = 10;
	int line = temp / 8;
	int colun = temp % 8;
	board.board[line][colun] = curplayer;
	board.reserve(temp, curplayer);
	if (curplayer == white)
	{
		drawwhite(line, colun);
	}
	else
	{
		drawblack(line, colun);
	}
	lock();
	curplayer = 0 - curplayer;
	int countw = 0;
	int countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
	if (againstflag == 1)
	{
		if (is_begin == 0)
		{
			is_begin = 1;
			tree.clear();
			tree.setboard(board);
			node* p = new node(line, colun);
			tree.setroot(p);
			tree.setcolour(white);
			board.getenablepos(white, p->enablepos);
			for (int i = 0; i < p->enablepos.size(); i++)
			{
				p->visit.push_back(0);
			}
		}
		else
		{
			tree.against(line, colun);
		}
		clearboard();
		printboard();
		lock2();
		tree.sim();
		tree.select(line, colun);
		if (line == -1)
		{
			curplayer = 0 - curplayer;
		}
		else
		{
			board.board[line][colun] = curplayer;
			board.reserve(line * 8 + colun, curplayer);
			curplayer = 0 - curplayer;
		}
	}
	clearboard();
	printboard();
	unlock();
	countw = 0;
	countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
}
void CMCTSDlg::OnClickedChessboard11()
{
	// TODO: 在此添加控件通知处理程序代码
	CString sss;
	int temp = 11;
	int line = temp / 8;
	int colun = temp % 8;
	board.board[line][colun] = curplayer;
	board.reserve(temp, curplayer);
	if (curplayer == white)
	{
		drawwhite(line, colun);
	}
	else
	{
		drawblack(line, colun);
	}
	lock();
	curplayer = 0 - curplayer;
	int countw = 0;
	int countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
	if (againstflag == 1)
	{
		if (is_begin == 0)
		{
			is_begin = 1;
			tree.clear();
			tree.setboard(board);
			node* p = new node(line, colun);
			tree.setroot(p);
			tree.setcolour(white);
			board.getenablepos(white, p->enablepos);
			for (int i = 0; i < p->enablepos.size(); i++)
			{
				p->visit.push_back(0);
			}
		}
		else
		{
			tree.against(line, colun);
		}
		clearboard();
		printboard();
		lock2();
		tree.sim();
		tree.select(line, colun);
		if (line == -1)
		{
			curplayer = 0 - curplayer;
		}
		else
		{
			board.board[line][colun] = curplayer;
			board.reserve(line * 8 + colun, curplayer);
			curplayer = 0 - curplayer;
		}
	}
	clearboard();
	printboard();
	unlock();
	countw = 0;
	countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
}
void CMCTSDlg::OnClickedChessboard12()
{
	// TODO: 在此添加控件通知处理程序代码
	CString sss;
	int temp = 12;
	int line = temp / 8;
	int colun = temp % 8;
	board.board[line][colun] = curplayer;
	board.reserve(temp, curplayer);
	if (curplayer == white)
	{
		drawwhite(line, colun);
	}
	else
	{
		drawblack(line, colun);
	}
	lock();
	curplayer = 0 - curplayer;
	int countw = 0;
	int countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
	if (againstflag == 1)
	{
		if (is_begin == 0)
		{
			is_begin = 1;
			tree.clear();
			tree.setboard(board);
			node* p = new node(line, colun);
			tree.setroot(p);
			tree.setcolour(white);
			board.getenablepos(white, p->enablepos);
			for (int i = 0; i < p->enablepos.size(); i++)
			{
				p->visit.push_back(0);
			}
		}
		else
		{
			tree.against(line, colun);
		}
		clearboard();
		printboard();
		lock2();
		tree.sim();
		tree.select(line, colun);
		if (line == -1)
		{
			curplayer = 0 - curplayer;
		}
		else
		{
			board.board[line][colun] = curplayer;
			board.reserve(line * 8 + colun, curplayer);
			curplayer = 0 - curplayer;
		}
	}
	clearboard();
	printboard();
	unlock();
	countw = 0;
	countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
}
void CMCTSDlg::OnClickedChessboard13()
{
	// TODO: 在此添加控件通知处理程序代码
	CString sss;
	int temp = 13;
	int line = temp / 8;
	int colun = temp % 8;
	board.board[line][colun] = curplayer;
	board.reserve(temp, curplayer);
	if (curplayer == white)
	{
		drawwhite(line, colun);
	}
	else
	{
		drawblack(line, colun);
	}
	lock();
	curplayer = 0 - curplayer;
	int countw = 0;
	int countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
	if (againstflag == 1)
	{
		if (is_begin == 0)
		{
			is_begin = 1;
			tree.clear();
			tree.setboard(board);
			node* p = new node(line, colun);
			tree.setroot(p);
			tree.setcolour(white);
			board.getenablepos(white, p->enablepos);
			for (int i = 0; i < p->enablepos.size(); i++)
			{
				p->visit.push_back(0);
			}
		}
		else
		{
			tree.against(line, colun);
		}
		clearboard();
		printboard();
		lock2();
		tree.sim();
		tree.select(line, colun);
		if (line == -1)
		{
			curplayer = 0 - curplayer;
		}
		else
		{
			board.board[line][colun] = curplayer;
			board.reserve(line * 8 + colun, curplayer);
			curplayer = 0 - curplayer;
		}
	}
	clearboard();
	printboard();
	unlock();
	countw = 0;
	countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
}
void CMCTSDlg::OnClickedChessboard14()
{
	// TODO: 在此添加控件通知处理程序代码
	CString sss;
	int temp = 14;
	int line = temp / 8;
	int colun = temp % 8;
	board.board[line][colun] = curplayer;
	board.reserve(temp, curplayer);
	if (curplayer == white)
	{
		drawwhite(line, colun);
	}
	else
	{
		drawblack(line, colun);
	}
	lock();
	curplayer = 0 - curplayer;
	int countw = 0;
	int countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
	if (againstflag == 1)
	{
		if (is_begin == 0)
		{
			is_begin = 1;
			tree.clear();
			tree.setboard(board);
			node* p = new node(line, colun);
			tree.setroot(p);
			tree.setcolour(white);
			board.getenablepos(white, p->enablepos);
			for (int i = 0; i < p->enablepos.size(); i++)
			{
				p->visit.push_back(0);
			}
		}
		else
		{
			tree.against(line, colun);
		}
		clearboard();
		printboard();
		lock2();
		tree.sim();
		tree.select(line, colun);
		if (line == -1)
		{
			curplayer = 0 - curplayer;
		}
		else
		{
			board.board[line][colun] = curplayer;
			board.reserve(line * 8 + colun, curplayer);
			curplayer = 0 - curplayer;
		}
	}
	clearboard();
	printboard();
	unlock();
	countw = 0;
	countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
}
void CMCTSDlg::OnClickedChessboard15()
{
	// TODO: 在此添加控件通知处理程序代码
	CString sss;
	int temp = 15;
	int line = temp / 8;
	int colun = temp % 8;
	board.board[line][colun] = curplayer;
	board.reserve(temp, curplayer);
	if (curplayer == white)
	{
		drawwhite(line, colun);
	}
	else
	{
		drawblack(line, colun);
	}
	lock();
	curplayer = 0 - curplayer;
	int countw = 0;
	int countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
	if (againstflag == 1)
	{
		if (is_begin == 0)
		{
			is_begin = 1;
			tree.clear();
			tree.setboard(board);
			node* p = new node(line, colun);
			tree.setroot(p);
			tree.setcolour(white);
			board.getenablepos(white, p->enablepos);
			for (int i = 0; i < p->enablepos.size(); i++)
			{
				p->visit.push_back(0);
			}
		}
		else
		{
			tree.against(line, colun);
		}
		clearboard();
		printboard();
		lock2();
		tree.sim();
		tree.select(line, colun);
		if (line == -1)
		{
			curplayer = 0 - curplayer;
		}
		else
		{
			board.board[line][colun] = curplayer;
			board.reserve(line * 8 + colun, curplayer);
			curplayer = 0 - curplayer;
		}
	}
	clearboard();
	printboard();
	unlock();
	countw = 0;
	countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
}
void CMCTSDlg::OnClickedChessboard16()
{
	// TODO: 在此添加控件通知处理程序代码
	CString sss;
	int temp = 16;
	int line = temp / 8;
	int colun = temp % 8;
	board.board[line][colun] = curplayer;
	board.reserve(temp, curplayer);
	if (curplayer == white)
	{
		drawwhite(line, colun);
	}
	else
	{
		drawblack(line, colun);
	}
	lock();
	curplayer = 0 - curplayer;
	int countw = 0;
	int countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
	if (againstflag == 1)
	{
		if (is_begin == 0)
		{
			is_begin = 1;
			tree.clear();
			tree.setboard(board);
			node* p = new node(line, colun);
			tree.setroot(p);
			tree.setcolour(white);
			board.getenablepos(white, p->enablepos);
			for (int i = 0; i < p->enablepos.size(); i++)
			{
				p->visit.push_back(0);
			}
		}
		else
		{
			tree.against(line, colun);
		}
		clearboard();
		printboard();
		lock2();
		tree.sim();
		tree.select(line, colun);
		if (line == -1)
		{
			curplayer = 0 - curplayer;
		}
		else
		{
			board.board[line][colun] = curplayer;
			board.reserve(line * 8 + colun, curplayer);
			curplayer = 0 - curplayer;
		}
	}
	clearboard();
	printboard();
	unlock();
	countw = 0;
	countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
}
void CMCTSDlg::OnClickedChessboard17()
{
	// TODO: 在此添加控件通知处理程序代码
	CString sss;
	int temp = 17;
	int line = temp / 8;
	int colun = temp % 8;
	board.board[line][colun] = curplayer;
	board.reserve(temp, curplayer);
	if (curplayer == white)
	{
		drawwhite(line, colun);
	}
	else
	{
		drawblack(line, colun);
	}
	lock();
	curplayer = 0 - curplayer;
	int countw = 0;
	int countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
	if (againstflag == 1)
	{
		if (is_begin == 0)
		{
			is_begin = 1;
			tree.clear();
			tree.setboard(board);
			node* p = new node(line, colun);
			tree.setroot(p);
			tree.setcolour(white);
			board.getenablepos(white, p->enablepos);
			for (int i = 0; i < p->enablepos.size(); i++)
			{
				p->visit.push_back(0);
			}
		}
		else
		{
			tree.against(line, colun);
		}
		clearboard();
		printboard();
		lock2();
		tree.sim();
		tree.select(line, colun);
		if (line == -1)
		{
			curplayer = 0 - curplayer;
		}
		else
		{
			board.board[line][colun] = curplayer;
			board.reserve(line * 8 + colun, curplayer);
			curplayer = 0 - curplayer;
		}
	}
	clearboard();
	printboard();
	unlock();
	countw = 0;
	countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
}
void CMCTSDlg::OnClickedChessboard18()
{
	// TODO: 在此添加控件通知处理程序代码
	CString sss;
	int temp = 18;
	int line = temp / 8;
	int colun = temp % 8;
	board.board[line][colun] = curplayer;
	board.reserve(temp, curplayer);
	if (curplayer == white)
	{
		drawwhite(line, colun);
	}
	else
	{
		drawblack(line, colun);
	}
	lock();
	curplayer = 0 - curplayer;
	int countw = 0;
	int countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
	if (againstflag == 1)
	{
		if (is_begin == 0)
		{
			is_begin = 1;
			tree.clear();
			tree.setboard(board);
			node* p = new node(line, colun);
			tree.setroot(p);
			tree.setcolour(white);
			board.getenablepos(white, p->enablepos);
			for (int i = 0; i < p->enablepos.size(); i++)
			{
				p->visit.push_back(0);
			}
		}
		else
		{
			tree.against(line, colun);
		}
		clearboard();
		printboard();
		lock2();
		tree.sim();
		tree.select(line, colun);
		if (line == -1)
		{
			curplayer = 0 - curplayer;
		}
		else
		{
			board.board[line][colun] = curplayer;
			board.reserve(line * 8 + colun, curplayer);
			curplayer = 0 - curplayer;
		}
	}
	clearboard();
	printboard();
	unlock();
	countw = 0;
	countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
}
void CMCTSDlg::OnClickedChessboard19()
{
	// TODO: 在此添加控件通知处理程序代码
	CString sss;
	int temp = 19;
	int line = temp / 8;
	int colun = temp % 8;
	board.board[line][colun] = curplayer;
	board.reserve(temp, curplayer);
	if (curplayer == white)
	{
		drawwhite(line, colun);
	}
	else
	{
		drawblack(line, colun);
	}
	lock();
	curplayer = 0 - curplayer;
	int countw = 0;
	int countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
	if (againstflag == 1)
	{
		if (is_begin == 0)
		{
			is_begin = 1;
			tree.clear();
			tree.setboard(board);
			node* p = new node(line, colun);
			tree.setroot(p);
			tree.setcolour(white);
			board.getenablepos(white, p->enablepos);
			for (int i = 0; i < p->enablepos.size(); i++)
			{
				p->visit.push_back(0);
			}
		}
		else
		{
			tree.against(line, colun);
		}
		clearboard();
		printboard();
		lock2();
		tree.sim();
		tree.select(line, colun);
		if (line == -1)
		{
			curplayer = 0 - curplayer;
		}
		else
		{
			board.board[line][colun] = curplayer;
			board.reserve(line * 8 + colun, curplayer);
			curplayer = 0 - curplayer;
		}
	}
	clearboard();
	printboard();
	unlock();
	countw = 0;
	countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
}
void CMCTSDlg::OnClickedChessboard20()
{
	// TODO: 在此添加控件通知处理程序代码
	CString sss;
	int temp = 20;
	int line = temp / 8;
	int colun = temp % 8;
	board.board[line][colun] = curplayer;
	board.reserve(temp, curplayer);
	if (curplayer == white)
	{
		drawwhite(line, colun);
	}
	else
	{
		drawblack(line, colun);
	}
	lock();
	curplayer = 0 - curplayer;
	int countw = 0;
	int countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
	if (againstflag == 1)
	{
		if (is_begin == 0)
		{
			is_begin = 1;
			tree.clear();
			tree.setboard(board);
			node* p = new node(line, colun);
			tree.setroot(p);
			tree.setcolour(white);
			board.getenablepos(white, p->enablepos);
			for (int i = 0; i < p->enablepos.size(); i++)
			{
				p->visit.push_back(0);
			}
		}
		else
		{
			tree.against(line, colun);
		}
		clearboard();
		printboard();
		lock2();
		tree.sim();
		tree.select(line, colun);
		if (line == -1)
		{
			curplayer = 0 - curplayer;
		}
		else
		{
			board.board[line][colun] = curplayer;
			board.reserve(line * 8 + colun, curplayer);
			curplayer = 0 - curplayer;
		}
	}
	clearboard();
	printboard();
	unlock();
	countw = 0;
	countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
}
void CMCTSDlg::OnClickedChessboard21()
{
	// TODO: 在此添加控件通知处理程序代码
	CString sss;
	int temp = 21;
	int line = temp / 8;
	int colun = temp % 8;
	board.board[line][colun] = curplayer;
	board.reserve(temp, curplayer);
	if (curplayer == white)
	{
		drawwhite(line, colun);
	}
	else
	{
		drawblack(line, colun);
	}
	lock();
	curplayer = 0 - curplayer;
	int countw = 0;
	int countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
	if (againstflag == 1)
	{
		if (is_begin == 0)
		{
			is_begin = 1;
			tree.clear();
			tree.setboard(board);
			node* p = new node(line, colun);
			tree.setroot(p);
			tree.setcolour(white);
			board.getenablepos(white, p->enablepos);
			for (int i = 0; i < p->enablepos.size(); i++)
			{
				p->visit.push_back(0);
			}
		}
		else
		{
			tree.against(line, colun);
		}
		clearboard();
		printboard();
		lock2();
		tree.sim();
		tree.select(line, colun);
		if (line == -1)
		{
			curplayer = 0 - curplayer;
		}
		else
		{
			board.board[line][colun] = curplayer;
			board.reserve(line * 8 + colun, curplayer);
			curplayer = 0 - curplayer;
		}
	}
	clearboard();
	printboard();
	unlock();
	countw = 0;
	countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
}
void CMCTSDlg::OnClickedChessboard22()
{
	// TODO: 在此添加控件通知处理程序代码
	CString sss;
	int temp = 22;
	int line = temp / 8;
	int colun = temp % 8;
	board.board[line][colun] = curplayer;
	board.reserve(temp, curplayer);
	if (curplayer == white)
	{
		drawwhite(line, colun);
	}
	else
	{
		drawblack(line, colun);
	}
	lock();
	curplayer = 0 - curplayer;
	int countw = 0;
	int countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
	if (againstflag == 1)
	{
		if (is_begin == 0)
		{
			is_begin = 1;
			tree.clear();
			tree.setboard(board);
			node* p = new node(line, colun);
			tree.setroot(p);
			tree.setcolour(white);
			board.getenablepos(white, p->enablepos);
			for (int i = 0; i < p->enablepos.size(); i++)
			{
				p->visit.push_back(0);
			}
		}
		else
		{
			tree.against(line, colun);
		}
		clearboard();
		printboard();
		lock2();
		tree.sim();
		tree.select(line, colun);
		if (line == -1)
		{
			curplayer = 0 - curplayer;
		}
		else
		{
			board.board[line][colun] = curplayer;
			board.reserve(line * 8 + colun, curplayer);
			curplayer = 0 - curplayer;
		}
	}
	clearboard();
	printboard();
	unlock();
	countw = 0;
	countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
}
void CMCTSDlg::OnClickedChessboard23()
{
	// TODO: 在此添加控件通知处理程序代码
	CString sss;
	int temp = 23;
	int line = temp / 8;
	int colun = temp % 8;
	board.board[line][colun] = curplayer;
	board.reserve(temp, curplayer);
	if (curplayer == white)
	{
		drawwhite(line, colun);
	}
	else
	{
		drawblack(line, colun);
	}
	lock();
	curplayer = 0 - curplayer;
	int countw = 0;
	int countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
	if (againstflag == 1)
	{
		if (is_begin == 0)
		{
			is_begin = 1;
			tree.clear();
			tree.setboard(board);
			node* p = new node(line, colun);
			tree.setroot(p);
			tree.setcolour(white);
			board.getenablepos(white, p->enablepos);
			for (int i = 0; i < p->enablepos.size(); i++)
			{
				p->visit.push_back(0);
			}
		}
		else
		{
			tree.against(line, colun);
		}
		clearboard();
		printboard();
		lock2();
		tree.sim();
		tree.select(line, colun);
		if (line == -1)
		{
			curplayer = 0 - curplayer;
		}
		else
		{
			board.board[line][colun] = curplayer;
			board.reserve(line * 8 + colun, curplayer);
			curplayer = 0 - curplayer;
		}
	}
	clearboard();
	printboard();
	unlock();
	countw = 0;
	countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
}
void CMCTSDlg::OnClickedChessboard24()
{
	// TODO: 在此添加控件通知处理程序代码
	CString sss;
	int temp = 24;
	int line = temp / 8;
	int colun = temp % 8;
	board.board[line][colun] = curplayer;
	board.reserve(temp, curplayer);
	if (curplayer == white)
	{
		drawwhite(line, colun);
	}
	else
	{
		drawblack(line, colun);
	}
	lock();
	curplayer = 0 - curplayer;
	int countw = 0;
	int countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
	if (againstflag == 1)
	{
		if (is_begin == 0)
		{
			is_begin = 1;
			tree.clear();
			tree.setboard(board);
			node* p = new node(line, colun);
			tree.setroot(p);
			tree.setcolour(white);
			board.getenablepos(white, p->enablepos);
			for (int i = 0; i < p->enablepos.size(); i++)
			{
				p->visit.push_back(0);
			}
		}
		else
		{
			tree.against(line, colun);
		}
		clearboard();
		printboard();
		lock2();
		tree.sim();
		tree.select(line, colun);
		if (line == -1)
		{
			curplayer = 0 - curplayer;
		}
		else
		{
			board.board[line][colun] = curplayer;
			board.reserve(line * 8 + colun, curplayer);
			curplayer = 0 - curplayer;
		}
	}
	clearboard();
	printboard();
	unlock();
	countw = 0;
	countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
}
void CMCTSDlg::OnClickedChessboard25()
{
	// TODO: 在此添加控件通知处理程序代码
	CString sss;
	int temp = 25;
	int line = temp / 8;
	int colun = temp % 8;
	board.board[line][colun] = curplayer;
	board.reserve(temp, curplayer);
	if (curplayer == white)
	{
		drawwhite(line, colun);
	}
	else
	{
		drawblack(line, colun);
	}
	lock();
	curplayer = 0 - curplayer;
	int countw = 0;
	int countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
	if (againstflag == 1)
	{
		if (is_begin == 0)
		{
			is_begin = 1;
			tree.clear();
			tree.setboard(board);
			node* p = new node(line, colun);
			tree.setroot(p);
			tree.setcolour(white);
			board.getenablepos(white, p->enablepos);
			for (int i = 0; i < p->enablepos.size(); i++)
			{
				p->visit.push_back(0);
			}
		}
		else
		{
			tree.against(line, colun);
		}
		clearboard();
		printboard();
		lock2();
		tree.sim();
		tree.select(line, colun);
		if (line == -1)
		{
			curplayer = 0 - curplayer;
		}
		else
		{
			board.board[line][colun] = curplayer;
			board.reserve(line * 8 + colun, curplayer);
			curplayer = 0 - curplayer;
		}
	}
	clearboard();
	printboard();
	unlock();
	countw = 0;
	countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
}
void CMCTSDlg::OnClickedChessboard26()
{
	// TODO: 在此添加控件通知处理程序代码
	CString sss;
	int temp = 26;
	int line = temp / 8;
	int colun = temp % 8;
	board.board[line][colun] = curplayer;
	board.reserve(temp, curplayer);
	if (curplayer == white)
	{
		drawwhite(line, colun);
	}
	else
	{
		drawblack(line, colun);
	}
	lock();
	curplayer = 0 - curplayer;
	int countw = 0;
	int countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
	if (againstflag == 1)
	{
		if (is_begin == 0)
		{
			is_begin = 1;
			tree.clear();
			tree.setboard(board);
			node* p = new node(line, colun);
			tree.setroot(p);
			tree.setcolour(white);
			board.getenablepos(white, p->enablepos);
			for (int i = 0; i < p->enablepos.size(); i++)
			{
				p->visit.push_back(0);
			}
		}
		else
		{
			tree.against(line, colun);
		}
		clearboard();
		printboard();
		lock2();
		tree.sim();
		tree.select(line, colun);
		if (line == -1)
		{
			curplayer = 0 - curplayer;
		}
		else
		{
			board.board[line][colun] = curplayer;
			board.reserve(line * 8 + colun, curplayer);
			curplayer = 0 - curplayer;
		}
	}
	clearboard();
	printboard();
	unlock();
	countw = 0;
	countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
}
void CMCTSDlg::OnClickedChessboard27()
{
	// TODO: 在此添加控件通知处理程序代码
	CString sss;
	int temp = 27;
	int line = temp / 8;
	int colun = temp % 8;
	board.board[line][colun] = curplayer;
	board.reserve(temp, curplayer);
	if (curplayer == white)
	{
		drawwhite(line, colun);
	}
	else
	{
		drawblack(line, colun);
	}
	lock();
	curplayer = 0 - curplayer;
	int countw = 0;
	int countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
	if (againstflag == 1)
	{
		if (is_begin == 0)
		{
			is_begin = 1;
			tree.clear();
			tree.setboard(board);
			node* p = new node(line, colun);
			tree.setroot(p);
			tree.setcolour(white);
			board.getenablepos(white, p->enablepos);
			for (int i = 0; i < p->enablepos.size(); i++)
			{
				p->visit.push_back(0);
			}
		}
		else
		{
			tree.against(line, colun);
		}
		clearboard();
		printboard();
		lock2();
		tree.sim();
		tree.select(line, colun);
		if (line == -1)
		{
			curplayer = 0 - curplayer;
		}
		else
		{
			board.board[line][colun] = curplayer;
			board.reserve(line * 8 + colun, curplayer);
			curplayer = 0 - curplayer;
		}
	}
	clearboard();
	printboard();
	unlock();
	countw = 0;
	countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
}
void CMCTSDlg::OnClickedChessboard28()
{
	// TODO: 在此添加控件通知处理程序代码
	CString sss;
	int temp = 28;
	int line = temp / 8;
	int colun = temp % 8;
	board.board[line][colun] = curplayer;
	board.reserve(temp, curplayer);
	if (curplayer == white)
	{
		drawwhite(line, colun);
	}
	else
	{
		drawblack(line, colun);
	}
	lock();
	curplayer = 0 - curplayer;
	int countw = 0;
	int countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
	if (againstflag == 1)
	{
		if (is_begin == 0)
		{
			is_begin = 1;
			tree.clear();
			tree.setboard(board);
			node* p = new node(line, colun);
			tree.setroot(p);
			tree.setcolour(white);
			board.getenablepos(white, p->enablepos);
			for (int i = 0; i < p->enablepos.size(); i++)
			{
				p->visit.push_back(0);
			}
		}
		else
		{
			tree.against(line, colun);
		}
		clearboard();
		printboard();
		lock2();
		tree.sim();
		tree.select(line, colun);
		if (line == -1)
		{
			curplayer = 0 - curplayer;
		}
		else
		{
			board.board[line][colun] = curplayer;
			board.reserve(line * 8 + colun, curplayer);
			curplayer = 0 - curplayer;
		}
	}
	clearboard();
	printboard();
	unlock();
	countw = 0;
	countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
}
void CMCTSDlg::OnClickedChessboard29()
{
	// TODO: 在此添加控件通知处理程序代码
	CString sss;
	int temp = 29;
	int line = temp / 8;
	int colun = temp % 8;
	board.board[line][colun] = curplayer;
	board.reserve(temp, curplayer);
	if (curplayer == white)
	{
		drawwhite(line, colun);
	}
	else
	{
		drawblack(line, colun);
	}
	lock();
	curplayer = 0 - curplayer;
	int countw = 0;
	int countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
	if (againstflag == 1)
	{
		if (is_begin == 0)
		{
			is_begin = 1;
			tree.clear();
			tree.setboard(board);
			node* p = new node(line, colun);
			tree.setroot(p);
			tree.setcolour(white);
			board.getenablepos(white, p->enablepos);
			for (int i = 0; i < p->enablepos.size(); i++)
			{
				p->visit.push_back(0);
			}
		}
		else
		{
			tree.against(line, colun);
		}
		clearboard();
		printboard();
		lock2();
		tree.sim();
		tree.select(line, colun);
		if (line == -1)
		{
			curplayer = 0 - curplayer;
		}
		else
		{
			board.board[line][colun] = curplayer;
			board.reserve(line * 8 + colun, curplayer);
			curplayer = 0 - curplayer;
		}
	}
	clearboard();
	printboard();
	unlock();
	countw = 0;
	countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
}
void CMCTSDlg::OnClickedChessboard30()
{
	// TODO: 在此添加控件通知处理程序代码
	CString sss;
	int temp = 30;
	int line = temp / 8;
	int colun = temp % 8;
	board.board[line][colun] = curplayer;
	board.reserve(temp, curplayer);
	if (curplayer == white)
	{
		drawwhite(line, colun);
	}
	else
	{
		drawblack(line, colun);
	}
	lock();
	curplayer = 0 - curplayer;
	int countw = 0;
	int countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
	if (againstflag == 1)
	{
		if (is_begin == 0)
		{
			is_begin = 1;
			tree.clear();
			tree.setboard(board);
			node* p = new node(line, colun);
			tree.setroot(p);
			tree.setcolour(white);
			board.getenablepos(white, p->enablepos);
			for (int i = 0; i < p->enablepos.size(); i++)
			{
				p->visit.push_back(0);
			}
		}
		else
		{
			tree.against(line, colun);
		}
		clearboard();
		printboard();
		lock2();
		tree.sim();
		tree.select(line, colun);
		if (line == -1)
		{
			curplayer = 0 - curplayer;
		}
		else
		{
			board.board[line][colun] = curplayer;
			board.reserve(line * 8 + colun, curplayer);
			curplayer = 0 - curplayer;
		}
	}
	clearboard();
	printboard();
	unlock();
	countw = 0;
	countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
}
void CMCTSDlg::OnClickedChessboard31()
{
	// TODO: 在此添加控件通知处理程序代码
	CString sss;
	int temp = 31;
	int line = temp / 8;
	int colun = temp % 8;
	board.board[line][colun] = curplayer;
	board.reserve(temp, curplayer);
	if (curplayer == white)
	{
		drawwhite(line, colun);
	}
	else
	{
		drawblack(line, colun);
	}
	lock();
	curplayer = 0 - curplayer;
	int countw = 0;
	int countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
	if (againstflag == 1)
	{
		if (is_begin == 0)
		{
			is_begin = 1;
			tree.clear();
			tree.setboard(board);
			node* p = new node(line, colun);
			tree.setroot(p);
			tree.setcolour(white);
			board.getenablepos(white, p->enablepos);
			for (int i = 0; i < p->enablepos.size(); i++)
			{
				p->visit.push_back(0);
			}
		}
		else
		{
			tree.against(line, colun);
		}
		clearboard();
		printboard();
		lock2();
		tree.sim();
		tree.select(line, colun);
		if (line == -1)
		{
			curplayer = 0 - curplayer;
		}
		else
		{
			board.board[line][colun] = curplayer;
			board.reserve(line * 8 + colun, curplayer);
			curplayer = 0 - curplayer;
		}
	}
	clearboard();
	printboard();
	unlock();
	countw = 0;
	countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
}
void CMCTSDlg::OnClickedChessboard32()
{
	// TODO: 在此添加控件通知处理程序代码
	CString sss;
	int temp = 32;
	int line = temp / 8;
	int colun = temp % 8;
	board.board[line][colun] = curplayer;
	board.reserve(temp, curplayer);
	if (curplayer == white)
	{
		drawwhite(line, colun);
	}
	else
	{
		drawblack(line, colun);
	}
	lock();
	curplayer = 0 - curplayer;
	int countw = 0;
	int countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
	if (againstflag == 1)
	{
		if (is_begin == 0)
		{
			is_begin = 1;
			tree.clear();
			tree.setboard(board);
			node* p = new node(line, colun);
			tree.setroot(p);
			tree.setcolour(white);
			board.getenablepos(white, p->enablepos);
			for (int i = 0; i < p->enablepos.size(); i++)
			{
				p->visit.push_back(0);
			}
		}
		else
		{
			tree.against(line, colun);
		}
		clearboard();
		printboard();
		lock2();
		tree.sim();
		tree.select(line, colun);
		if (line == -1)
		{
			curplayer = 0 - curplayer;
		}
		else
		{
			board.board[line][colun] = curplayer;
			board.reserve(line * 8 + colun, curplayer);
			curplayer = 0 - curplayer;
		}
	}
	clearboard();
	printboard();
	unlock();
	countw = 0;
	countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
}
void CMCTSDlg::OnClickedChessboard33()
{
	// TODO: 在此添加控件通知处理程序代码
	CString sss;
	int temp = 33;
	int line = temp / 8;
	int colun = temp % 8;
	board.board[line][colun] = curplayer;
	board.reserve(temp, curplayer);
	if (curplayer == white)
	{
		drawwhite(line, colun);
	}
	else
	{
		drawblack(line, colun);
	}
	lock();
	curplayer = 0 - curplayer;
	int countw = 0;
	int countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
	if (againstflag == 1)
	{
		if (is_begin == 0)
		{
			is_begin = 1;
			tree.clear();
			tree.setboard(board);
			node* p = new node(line, colun);
			tree.setroot(p);
			tree.setcolour(white);
			board.getenablepos(white, p->enablepos);
			for (int i = 0; i < p->enablepos.size(); i++)
			{
				p->visit.push_back(0);
			}
		}
		else
		{
			tree.against(line, colun);
		}
		clearboard();
		printboard();
		lock2();
		tree.sim();
		tree.select(line, colun);
		if (line == -1)
		{
			curplayer = 0 - curplayer;
		}
		else
		{
			board.board[line][colun] = curplayer;
			board.reserve(line * 8 + colun, curplayer);
			curplayer = 0 - curplayer;
		}
	}
	clearboard();
	printboard();
	unlock();
	countw = 0;
	countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
}
void CMCTSDlg::OnClickedChessboard34()
{
	// TODO: 在此添加控件通知处理程序代码
	CString sss;
	int temp = 34;
	int line = temp / 8;
	int colun = temp % 8;
	board.board[line][colun] = curplayer;
	board.reserve(temp, curplayer);
	if (curplayer == white)
	{
		drawwhite(line, colun);
	}
	else
	{
		drawblack(line, colun);
	}
	lock();
	curplayer = 0 - curplayer;
	int countw = 0;
	int countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
	if (againstflag == 1)
	{
		if (is_begin == 0)
		{
			is_begin = 1;
			tree.clear();
			tree.setboard(board);
			node* p = new node(line, colun);
			tree.setroot(p);
			tree.setcolour(white);
			board.getenablepos(white, p->enablepos);
			for (int i = 0; i < p->enablepos.size(); i++)
			{
				p->visit.push_back(0);
			}
		}
		else
		{
			tree.against(line, colun);
		}
		clearboard();
		printboard();
		lock2();
		tree.sim();
		tree.select(line, colun);
		if (line == -1)
		{
			curplayer = 0 - curplayer;
		}
		else
		{
			board.board[line][colun] = curplayer;
			board.reserve(line * 8 + colun, curplayer);
			curplayer = 0 - curplayer;
		}
	}
	clearboard();
	printboard();
	unlock();
	countw = 0;
	countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
}
void CMCTSDlg::OnClickedChessboard35()
{
	// TODO: 在此添加控件通知处理程序代码
	CString sss;
	int temp = 35;
	int line = temp / 8;
	int colun = temp % 8;
	board.board[line][colun] = curplayer;
	board.reserve(temp, curplayer);
	if (curplayer == white)
	{
		drawwhite(line, colun);
	}
	else
	{
		drawblack(line, colun);
	}
	lock();
	curplayer = 0 - curplayer;
	int countw = 0;
	int countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
	if (againstflag == 1)
	{
		if (is_begin == 0)
		{
			is_begin = 1;
			tree.clear();
			tree.setboard(board);
			node* p = new node(line, colun);
			tree.setroot(p);
			tree.setcolour(white);
			board.getenablepos(white, p->enablepos);
			for (int i = 0; i < p->enablepos.size(); i++)
			{
				p->visit.push_back(0);
			}
		}
		else
		{
			tree.against(line, colun);
		}
		clearboard();
		printboard();
		lock2();
		tree.sim();
		tree.select(line, colun);
		if (line == -1)
		{
			curplayer = 0 - curplayer;
		}
		else
		{
			board.board[line][colun] = curplayer;
			board.reserve(line * 8 + colun, curplayer);
			curplayer = 0 - curplayer;
		}
	}
	clearboard();
	printboard();
	unlock();
	countw = 0;
	countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
}
void CMCTSDlg::OnClickedChessboard36()
{
	// TODO: 在此添加控件通知处理程序代码
	CString sss;
	int temp = 36;
	int line = temp / 8;
	int colun = temp % 8;
	board.board[line][colun] = curplayer;
	board.reserve(temp, curplayer);
	if (curplayer == white)
	{
		drawwhite(line, colun);
	}
	else
	{
		drawblack(line, colun);
	}
	lock();
	curplayer = 0 - curplayer;
	int countw = 0;
	int countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
	if (againstflag == 1)
	{
		if (is_begin == 0)
		{
			is_begin = 1;
			tree.clear();
			tree.setboard(board);
			node* p = new node(line, colun);
			tree.setroot(p);
			tree.setcolour(white);
			board.getenablepos(white, p->enablepos);
			for (int i = 0; i < p->enablepos.size(); i++)
			{
				p->visit.push_back(0);
			}
		}
		else
		{
			tree.against(line, colun);
		}
		clearboard();
		printboard();
		lock2();
		tree.sim();
		tree.select(line, colun);
		if (line == -1)
		{
			curplayer = 0 - curplayer;
		}
		else
		{
			board.board[line][colun] = curplayer;
			board.reserve(line * 8 + colun, curplayer);
			curplayer = 0 - curplayer;
		}
	}
	clearboard();
	printboard();
	unlock();
	countw = 0;
	countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
}
void CMCTSDlg::OnClickedChessboard37()
{
	// TODO: 在此添加控件通知处理程序代码
	CString sss;
	int temp = 37;
	int line = temp / 8;
	int colun = temp % 8;
	board.board[line][colun] = curplayer;
	board.reserve(temp, curplayer);
	if (curplayer == white)
	{
		drawwhite(line, colun);
	}
	else
	{
		drawblack(line, colun);
	}
	lock();
	curplayer = 0 - curplayer;
	int countw = 0;
	int countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
	if (againstflag == 1)
	{
		if (is_begin == 0)
		{
			is_begin = 1;
			tree.clear();
			tree.setboard(board);
			node* p = new node(line, colun);
			tree.setroot(p);
			tree.setcolour(white);
			board.getenablepos(white, p->enablepos);
			for (int i = 0; i < p->enablepos.size(); i++)
			{
				p->visit.push_back(0);
			}
		}
		else
		{
			tree.against(line, colun);
		}
		clearboard();
		printboard();
		lock2();
		tree.sim();
		tree.select(line, colun);
		if (line == -1)
		{
			curplayer = 0 - curplayer;
		}
		else
		{
			board.board[line][colun] = curplayer;
			board.reserve(line * 8 + colun, curplayer);
			curplayer = 0 - curplayer;
		}
	}
	clearboard();
	printboard();
	unlock();
	countw = 0;
	countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
}
void CMCTSDlg::OnClickedChessboard38()
{
	// TODO: 在此添加控件通知处理程序代码
	CString sss;
	int temp = 38;
	int line = temp / 8;
	int colun = temp % 8;
	board.board[line][colun] = curplayer;
	board.reserve(temp, curplayer);
	if (curplayer == white)
	{
		drawwhite(line, colun);
	}
	else
	{
		drawblack(line, colun);
	}
	lock();
	curplayer = 0 - curplayer;
	int countw = 0;
	int countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
	if (againstflag == 1)
	{
		if (is_begin == 0)
		{
			is_begin = 1;
			tree.clear();
			tree.setboard(board);
			node* p = new node(line, colun);
			tree.setroot(p);
			tree.setcolour(white);
			board.getenablepos(white, p->enablepos);
			for (int i = 0; i < p->enablepos.size(); i++)
			{
				p->visit.push_back(0);
			}
		}
		else
		{
			tree.against(line, colun);
		}
		clearboard();
		printboard();
		lock2();
		tree.sim();
		tree.select(line, colun);
		if (line == -1)
		{
			curplayer = 0 - curplayer;
		}
		else
		{
			board.board[line][colun] = curplayer;
			board.reserve(line * 8 + colun, curplayer);
			curplayer = 0 - curplayer;
		}
	}
	clearboard();
	printboard();
	unlock();
	countw = 0;
	countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
}
void CMCTSDlg::OnClickedChessboard39()
{
	// TODO: 在此添加控件通知处理程序代码
	CString sss;
	int temp = 39;
	int line = temp / 8;
	int colun = temp % 8;
	board.board[line][colun] = curplayer;
	board.reserve(temp, curplayer);
	if (curplayer == white)
	{
		drawwhite(line, colun);
	}
	else
	{
		drawblack(line, colun);
	}
	lock();
	curplayer = 0 - curplayer;
	int countw = 0;
	int countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
	if (againstflag == 1)
	{
		if (is_begin == 0)
		{
			is_begin = 1;
			tree.clear();
			tree.setboard(board);
			node* p = new node(line, colun);
			tree.setroot(p);
			tree.setcolour(white);
			board.getenablepos(white, p->enablepos);
			for (int i = 0; i < p->enablepos.size(); i++)
			{
				p->visit.push_back(0);
			}
		}
		else
		{
			tree.against(line, colun);
		}
		clearboard();
		printboard();
		lock2();
		tree.sim();
		tree.select(line, colun);
		if (line == -1)
		{
			curplayer = 0 - curplayer;
		}
		else
		{
			board.board[line][colun] = curplayer;
			board.reserve(line * 8 + colun, curplayer);
			curplayer = 0 - curplayer;
		}
	}
	clearboard();
	printboard();
	unlock();
	countw = 0;
	countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
}
void CMCTSDlg::OnClickedChessboard40()
{
	// TODO: 在此添加控件通知处理程序代码
	CString sss;
	int temp = 40;
	int line = temp / 8;
	int colun = temp % 8;
	board.board[line][colun] = curplayer;
	board.reserve(temp, curplayer);
	if (curplayer == white)
	{
		drawwhite(line, colun);
	}
	else
	{
		drawblack(line, colun);
	}
	lock();
	curplayer = 0 - curplayer;
	int countw = 0;
	int countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
	if (againstflag == 1)
	{
		if (is_begin == 0)
		{
			is_begin = 1;
			tree.clear();
			tree.setboard(board);
			node* p = new node(line, colun);
			tree.setroot(p);
			tree.setcolour(white);
			board.getenablepos(white, p->enablepos);
			for (int i = 0; i < p->enablepos.size(); i++)
			{
				p->visit.push_back(0);
			}
		}
		else
		{
			tree.against(line, colun);
		}
		clearboard();
		printboard();
		lock2();
		tree.sim();
		tree.select(line, colun);
		if (line == -1)
		{
			curplayer = 0 - curplayer;
		}
		else
		{
			board.board[line][colun] = curplayer;
			board.reserve(line * 8 + colun, curplayer);
			curplayer = 0 - curplayer;
		}
	}
	clearboard();
	printboard();
	unlock();
	countw = 0;
	countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
}
void CMCTSDlg::OnClickedChessboard41()
{
	// TODO: 在此添加控件通知处理程序代码
	CString sss;
	int temp = 41;
	int line = temp / 8;
	int colun = temp % 8;
	board.board[line][colun] = curplayer;
	board.reserve(temp, curplayer);
	if (curplayer == white)
	{
		drawwhite(line, colun);
	}
	else
	{
		drawblack(line, colun);
	}
	lock();
	curplayer = 0 - curplayer;
	int countw = 0;
	int countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
	if (againstflag == 1)
	{
		if (is_begin == 0)
		{
			is_begin = 1;
			tree.clear();
			tree.setboard(board);
			node* p = new node(line, colun);
			tree.setroot(p);
			tree.setcolour(white);
			board.getenablepos(white, p->enablepos);
			for (int i = 0; i < p->enablepos.size(); i++)
			{
				p->visit.push_back(0);
			}
		}
		else
		{
			tree.against(line, colun);
		}
		clearboard();
		printboard();
		lock2();
		tree.sim();
		tree.select(line, colun);
		if (line == -1)
		{
			curplayer = 0 - curplayer;
		}
		else
		{
			board.board[line][colun] = curplayer;
			board.reserve(line * 8 + colun, curplayer);
			curplayer = 0 - curplayer;
		}
	}
	clearboard();
	printboard();
	unlock();
	countw = 0;
	countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
}
void CMCTSDlg::OnClickedChessboard42()
{
	// TODO: 在此添加控件通知处理程序代码
	CString sss;
	int temp = 42;
	int line = temp / 8;
	int colun = temp % 8;
	board.board[line][colun] = curplayer;
	board.reserve(temp, curplayer);
	if (curplayer == white)
	{
		drawwhite(line, colun);
	}
	else
	{
		drawblack(line, colun);
	}
	lock();
	curplayer = 0 - curplayer;
	int countw = 0;
	int countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
	if (againstflag == 1)
	{
		if (is_begin == 0)
		{
			is_begin = 1;
			tree.clear();
			tree.setboard(board);
			node* p = new node(line, colun);
			tree.setroot(p);
			tree.setcolour(white);
			board.getenablepos(white, p->enablepos);
			for (int i = 0; i < p->enablepos.size(); i++)
			{
				p->visit.push_back(0);
			}
		}
		else
		{
			tree.against(line, colun);
		}
		clearboard();
		printboard();
		lock2();
		tree.sim();
		tree.select(line, colun);
		if (line == -1)
		{
			curplayer = 0 - curplayer;
		}
		else
		{
			board.board[line][colun] = curplayer;
			board.reserve(line * 8 + colun, curplayer);
			curplayer = 0 - curplayer;
		}
	}
	clearboard();
	printboard();
	unlock();
	countw = 0;
	countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
}
void CMCTSDlg::OnClickedChessboard43()
{
	// TODO: 在此添加控件通知处理程序代码
	CString sss;
	int temp = 43;
	int line = temp / 8;
	int colun = temp % 8;
	board.board[line][colun] = curplayer;
	board.reserve(temp, curplayer);
	if (curplayer == white)
	{
		drawwhite(line, colun);
	}
	else
	{
		drawblack(line, colun);
	}
	lock();
	curplayer = 0 - curplayer;
	int countw = 0;
	int countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
	if (againstflag == 1)
	{
		if (is_begin == 0)
		{
			is_begin = 1;
			tree.clear();
			tree.setboard(board);
			node* p = new node(line, colun);
			tree.setroot(p);
			tree.setcolour(white);
			board.getenablepos(white, p->enablepos);
			for (int i = 0; i < p->enablepos.size(); i++)
			{
				p->visit.push_back(0);
			}
		}
		else
		{
			tree.against(line, colun);
		}
		clearboard();
		printboard();
		lock2();
		tree.sim();
		tree.select(line, colun);
		if (line == -1)
		{
			curplayer = 0 - curplayer;
		}
		else
		{
			board.board[line][colun] = curplayer;
			board.reserve(line * 8 + colun, curplayer);
			curplayer = 0 - curplayer;
		}
	}
	clearboard();
	printboard();
	unlock();
	countw = 0;
	countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
}
void CMCTSDlg::OnClickedChessboard44()
{
	// TODO: 在此添加控件通知处理程序代码
	CString sss;
	int temp = 44;
	int line = temp / 8;
	int colun = temp % 8;
	board.board[line][colun] = curplayer;
	board.reserve(temp, curplayer);
	if (curplayer == white)
	{
		drawwhite(line, colun);
	}
	else
	{
		drawblack(line, colun);
	}
	lock();
	curplayer = 0 - curplayer;
	int countw = 0;
	int countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
	if (againstflag == 1)
	{
		if (is_begin == 0)
		{
			is_begin = 1;
			tree.clear();
			tree.setboard(board);
			node* p = new node(line, colun);
			tree.setroot(p);
			tree.setcolour(white);
			board.getenablepos(white, p->enablepos);
			for (int i = 0; i < p->enablepos.size(); i++)
			{
				p->visit.push_back(0);
			}
		}
		else
		{
			tree.against(line, colun);
		}
		clearboard();
		printboard();
		lock2();
		tree.sim();
		tree.select(line, colun);
		if (line == -1)
		{
			curplayer = 0 - curplayer;
		}
		else
		{
			board.board[line][colun] = curplayer;
			board.reserve(line * 8 + colun, curplayer);
			curplayer = 0 - curplayer;
		}
	}
	clearboard();
	printboard();
	unlock();
	countw = 0;
	countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
}
void CMCTSDlg::OnClickedChessboard45()
{
	// TODO: 在此添加控件通知处理程序代码
	CString sss;
	int temp = 45;
	int line = temp / 8;
	int colun = temp % 8;
	board.board[line][colun] = curplayer;
	board.reserve(temp, curplayer);
	if (curplayer == white)
	{
		drawwhite(line, colun);
	}
	else
	{
		drawblack(line, colun);
	}
	lock();
	curplayer = 0 - curplayer;
	int countw = 0;
	int countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
	if (againstflag == 1)
	{
		if (is_begin == 0)
		{
			is_begin = 1;
			tree.clear();
			tree.setboard(board);
			node* p = new node(line, colun);
			tree.setroot(p);
			tree.setcolour(white);
			board.getenablepos(white, p->enablepos);
			for (int i = 0; i < p->enablepos.size(); i++)
			{
				p->visit.push_back(0);
			}
		}
		else
		{
			tree.against(line, colun);
		}
		clearboard();
		printboard();
		lock2();
		tree.sim();
		tree.select(line, colun);
		if (line == -1)
		{
			curplayer = 0 - curplayer;
		}
		else
		{
			board.board[line][colun] = curplayer;
			board.reserve(line * 8 + colun, curplayer);
			curplayer = 0 - curplayer;
		}
	}
	clearboard();
	printboard();
	unlock();
	countw = 0;
	countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
}
void CMCTSDlg::OnClickedChessboard46()
{
	// TODO: 在此添加控件通知处理程序代码
	CString sss;
	int temp = 46;
	int line = temp / 8;
	int colun = temp % 8;
	board.board[line][colun] = curplayer;
	board.reserve(temp, curplayer);
	if (curplayer == white)
	{
		drawwhite(line, colun);
	}
	else
	{
		drawblack(line, colun);
	}
	lock();
	curplayer = 0 - curplayer;
	int countw = 0;
	int countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
	if (againstflag == 1)
	{
		if (is_begin == 0)
		{
			is_begin = 1;
			tree.clear();
			tree.setboard(board);
			node* p = new node(line, colun);
			tree.setroot(p);
			tree.setcolour(white);
			board.getenablepos(white, p->enablepos);
			for (int i = 0; i < p->enablepos.size(); i++)
			{
				p->visit.push_back(0);
			}
		}
		else
		{
			tree.against(line, colun);
		}
		clearboard();
		printboard();
		lock2();
		tree.sim();
		tree.select(line, colun);
		if (line == -1)
		{
			curplayer = 0 - curplayer;
		}
		else
		{
			board.board[line][colun] = curplayer;
			board.reserve(line * 8 + colun, curplayer);
			curplayer = 0 - curplayer;
		}
	}
	clearboard();
	printboard();
	unlock();
	countw = 0;
	countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
}
void CMCTSDlg::OnClickedChessboard47()
{
	// TODO: 在此添加控件通知处理程序代码
	CString sss;
	int temp = 47;
	int line = temp / 8;
	int colun = temp % 8;
	board.board[line][colun] = curplayer;
	board.reserve(temp, curplayer);
	if (curplayer == white)
	{
		drawwhite(line, colun);
	}
	else
	{
		drawblack(line, colun);
	}
	lock();
	curplayer = 0 - curplayer;
	int countw = 0;
	int countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
	if (againstflag == 1)
	{
		if (is_begin == 0)
		{
			is_begin = 1;
			tree.clear();
			tree.setboard(board);
			node* p = new node(line, colun);
			tree.setroot(p);
			tree.setcolour(white);
			board.getenablepos(white, p->enablepos);
			for (int i = 0; i < p->enablepos.size(); i++)
			{
				p->visit.push_back(0);
			}
		}
		else
		{
			tree.against(line, colun);
		}
		clearboard();
		printboard();
		lock2();
		tree.sim();
		tree.select(line, colun);
		if (line == -1)
		{
			curplayer = 0 - curplayer;
		}
		else
		{
			board.board[line][colun] = curplayer;
			board.reserve(line * 8 + colun, curplayer);
			curplayer = 0 - curplayer;
		}
	}
	clearboard();
	printboard();
	unlock();
	countw = 0;
	countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
}
void CMCTSDlg::OnClickedChessboard48()
{
	// TODO: 在此添加控件通知处理程序代码
	CString sss;
	int temp = 48;
	int line = temp / 8;
	int colun = temp % 8;
	board.board[line][colun] = curplayer;
	board.reserve(temp, curplayer);
	if (curplayer == white)
	{
		drawwhite(line, colun);
	}
	else
	{
		drawblack(line, colun);
	}
	lock();
	curplayer = 0 - curplayer;
	int countw = 0;
	int countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
	if (againstflag == 1)
	{
		if (is_begin == 0)
		{
			is_begin = 1;
			tree.clear();
			tree.setboard(board);
			node* p = new node(line, colun);
			tree.setroot(p);
			tree.setcolour(white);
			board.getenablepos(white, p->enablepos);
			for (int i = 0; i < p->enablepos.size(); i++)
			{
				p->visit.push_back(0);
			}
		}
		else
		{
			tree.against(line, colun);
		}
		clearboard();
		printboard();
		lock2();
		tree.sim();
		tree.select(line, colun);
		if (line == -1)
		{
			curplayer = 0 - curplayer;
		}
		else
		{
			board.board[line][colun] = curplayer;
			board.reserve(line * 8 + colun, curplayer);
			curplayer = 0 - curplayer;
		}
	}
	clearboard();
	printboard();
	unlock();
	countw = 0;
	countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
}
void CMCTSDlg::OnClickedChessboard49()
{
	// TODO: 在此添加控件通知处理程序代码
	CString sss;
	int temp = 49;
	int line = temp / 8;
	int colun = temp % 8;
	board.board[line][colun] = curplayer;
	board.reserve(temp, curplayer);
	if (curplayer == white)
	{
		drawwhite(line, colun);
	}
	else
	{
		drawblack(line, colun);
	}
	lock();
	curplayer = 0 - curplayer;
	int countw = 0;
	int countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
	if (againstflag == 1)
	{
		if (is_begin == 0)
		{
			is_begin = 1;
			tree.clear();
			tree.setboard(board);
			node* p = new node(line, colun);
			tree.setroot(p);
			tree.setcolour(white);
			board.getenablepos(white, p->enablepos);
			for (int i = 0; i < p->enablepos.size(); i++)
			{
				p->visit.push_back(0);
			}
		}
		else
		{
			tree.against(line, colun);
		}
		clearboard();
		printboard();
		lock2();
		tree.sim();
		tree.select(line, colun);
		if (line == -1)
		{
			curplayer = 0 - curplayer;
		}
		else
		{
			board.board[line][colun] = curplayer;
			board.reserve(line * 8 + colun, curplayer);
			curplayer = 0 - curplayer;
		}
	}
	clearboard();
	printboard();
	unlock();
	countw = 0;
	countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
}
void CMCTSDlg::OnClickedChessboard50()
{
	// TODO: 在此添加控件通知处理程序代码
	CString sss;
	int temp = 50;
	int line = temp / 8;
	int colun = temp % 8;
	board.board[line][colun] = curplayer;
	board.reserve(temp, curplayer);
	if (curplayer == white)
	{
		drawwhite(line, colun);
	}
	else
	{
		drawblack(line, colun);
	}
	lock();
	curplayer = 0 - curplayer;
	int countw = 0;
	int countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
	if (againstflag == 1)
	{
		if (is_begin == 0)
		{
			is_begin = 1;
			tree.clear();
			tree.setboard(board);
			node* p = new node(line, colun);
			tree.setroot(p);
			tree.setcolour(white);
			board.getenablepos(white, p->enablepos);
			for (int i = 0; i < p->enablepos.size(); i++)
			{
				p->visit.push_back(0);
			}
		}
		else
		{
			tree.against(line, colun);
		}
		clearboard();
		printboard();
		lock2();
		tree.sim();
		tree.select(line, colun);
		if (line == -1)
		{
			curplayer = 0 - curplayer;
		}
		else
		{
			board.board[line][colun] = curplayer;
			board.reserve(line * 8 + colun, curplayer);
			curplayer = 0 - curplayer;
		}
	}
	clearboard();
	printboard();
	unlock();
	countw = 0;
	countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
}
void CMCTSDlg::OnClickedChessboard51()
{
	// TODO: 在此添加控件通知处理程序代码
	CString sss;
	int temp = 51;
	int line = temp / 8;
	int colun = temp % 8;
	board.board[line][colun] = curplayer;
	board.reserve(temp, curplayer);
	if (curplayer == white)
	{
		drawwhite(line, colun);
	}
	else
	{
		drawblack(line, colun);
	}
	lock();
	curplayer = 0 - curplayer;
	int countw = 0;
	int countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
	if (againstflag == 1)
	{
		if (is_begin == 0)
		{
			is_begin = 1;
			tree.clear();
			tree.setboard(board);
			node* p = new node(line, colun);
			tree.setroot(p);
			tree.setcolour(white);
			board.getenablepos(white, p->enablepos);
			for (int i = 0; i < p->enablepos.size(); i++)
			{
				p->visit.push_back(0);
			}
		}
		else
		{
			tree.against(line, colun);
		}
		clearboard();
		printboard();
		lock2();
		tree.sim();
		tree.select(line, colun);
		if (line == -1)
		{
			curplayer = 0 - curplayer;
		}
		else
		{
			board.board[line][colun] = curplayer;
			board.reserve(line * 8 + colun, curplayer);
			curplayer = 0 - curplayer;
		}
	}
	clearboard();
	printboard();
	unlock();
	countw = 0;
	countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
}
void CMCTSDlg::OnClickedChessboard52()
{
	// TODO: 在此添加控件通知处理程序代码
	CString sss;
	int temp = 52;
	int line = temp / 8;
	int colun = temp % 8;
	board.board[line][colun] = curplayer;
	board.reserve(temp, curplayer);
	if (curplayer == white)
	{
		drawwhite(line, colun);
	}
	else
	{
		drawblack(line, colun);
	}
	lock();
	curplayer = 0 - curplayer;
	int countw = 0;
	int countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
	if (againstflag == 1)
	{
		if (is_begin == 0)
		{
			is_begin = 1;
			tree.clear();
			tree.setboard(board);
			node* p = new node(line, colun);
			tree.setroot(p);
			tree.setcolour(white);
			board.getenablepos(white, p->enablepos);
			for (int i = 0; i < p->enablepos.size(); i++)
			{
				p->visit.push_back(0);
			}
		}
		else
		{
			tree.against(line, colun);
		}
		clearboard();
		printboard();
		lock2();
		tree.sim();
		tree.select(line, colun);
		if (line == -1)
		{
			curplayer = 0 - curplayer;
		}
		else
		{
			board.board[line][colun] = curplayer;
			board.reserve(line * 8 + colun, curplayer);
			curplayer = 0 - curplayer;
		}
	}
	clearboard();
	printboard();
	unlock();
	countw = 0;
	countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
}
void CMCTSDlg::OnClickedChessboard53()
{
	// TODO: 在此添加控件通知处理程序代码
	CString sss;
	int temp = 53;
	int line = temp / 8;
	int colun = temp % 8;
	board.board[line][colun] = curplayer;
	board.reserve(temp, curplayer);
	if (curplayer == white)
	{
		drawwhite(line, colun);
	}
	else
	{
		drawblack(line, colun);
	}
	lock();
	curplayer = 0 - curplayer;
	int countw = 0;
	int countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
	if (againstflag == 1)
	{
		if (is_begin == 0)
		{
			is_begin = 1;
			tree.clear();
			tree.setboard(board);
			node* p = new node(line, colun);
			tree.setroot(p);
			tree.setcolour(white);
			board.getenablepos(white, p->enablepos);
			for (int i = 0; i < p->enablepos.size(); i++)
			{
				p->visit.push_back(0);
			}
		}
		else
		{
			tree.against(line, colun);
		}
		clearboard();
		printboard();
		lock2();
		tree.sim();
		tree.select(line, colun);
		if (line == -1)
		{
			curplayer = 0 - curplayer;
		}
		else
		{
			board.board[line][colun] = curplayer;
			board.reserve(line * 8 + colun, curplayer);
			curplayer = 0 - curplayer;
		}
	}
	clearboard();
	printboard();
	unlock();
	countw = 0;
	countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
}
void CMCTSDlg::OnClickedChessboard54()
{
	// TODO: 在此添加控件通知处理程序代码
	CString sss;
	int temp = 54;
	int line = temp / 8;
	int colun = temp % 8;
	board.board[line][colun] = curplayer;
	board.reserve(temp, curplayer);
	if (curplayer == white)
	{
		drawwhite(line, colun);
	}
	else
	{
		drawblack(line, colun);
	}
	lock();
	curplayer = 0 - curplayer;
	int countw = 0;
	int countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
	if (againstflag == 1)
	{
		if (is_begin == 0)
		{
			is_begin = 1;
			tree.clear();
			tree.setboard(board);
			node* p = new node(line, colun);
			tree.setroot(p);
			tree.setcolour(white);
			board.getenablepos(white, p->enablepos);
			for (int i = 0; i < p->enablepos.size(); i++)
			{
				p->visit.push_back(0);
			}
		}
		else
		{
			tree.against(line, colun);
		}
		clearboard();
		printboard();
		lock2();
		tree.sim();
		tree.select(line, colun);
		if (line == -1)
		{
			curplayer = 0 - curplayer;
		}
		else
		{
			board.board[line][colun] = curplayer;
			board.reserve(line * 8 + colun, curplayer);
			curplayer = 0 - curplayer;
		}
	}
	clearboard();
	printboard();
	unlock();
	countw = 0;
	countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
}
void CMCTSDlg::OnClickedChessboard55()
{
	// TODO: 在此添加控件通知处理程序代码
	CString sss;
	int temp = 55;
	int line = temp / 8;
	int colun = temp % 8;
	board.board[line][colun] = curplayer;
	board.reserve(temp, curplayer);
	if (curplayer == white)
	{
		drawwhite(line, colun);
	}
	else
	{
		drawblack(line, colun);
	}
	lock();
	curplayer = 0 - curplayer;
	int countw = 0;
	int countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
	if (againstflag == 1)
	{
		if (is_begin == 0)
		{
			is_begin = 1;
			tree.clear();
			tree.setboard(board);
			node* p = new node(line, colun);
			tree.setroot(p);
			tree.setcolour(white);
			board.getenablepos(white, p->enablepos);
			for (int i = 0; i < p->enablepos.size(); i++)
			{
				p->visit.push_back(0);
			}
		}
		else
		{
			tree.against(line, colun);
		}
		clearboard();
		printboard();
		lock2();
		tree.sim();
		tree.select(line, colun);
		if (line == -1)
		{
			curplayer = 0 - curplayer;
		}
		else
		{
			board.board[line][colun] = curplayer;
			board.reserve(line * 8 + colun, curplayer);
			curplayer = 0 - curplayer;
		}
	}
	clearboard();
	printboard();
	unlock();
	countw = 0;
	countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
}
void CMCTSDlg::OnClickedChessboard56()
{
	// TODO: 在此添加控件通知处理程序代码
	CString sss;
	int temp = 56;
	int line = temp / 8;
	int colun = temp % 8;
	board.board[line][colun] = curplayer;
	board.reserve(temp, curplayer);
	if (curplayer == white)
	{
		drawwhite(line, colun);
	}
	else
	{
		drawblack(line, colun);
	}
	lock();
	curplayer = 0 - curplayer;
	int countw = 0;
	int countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
	if (againstflag == 1)
	{
		if (is_begin == 0)
		{
			is_begin = 1;
			tree.clear();
			tree.setboard(board);
			node* p = new node(line, colun);
			tree.setroot(p);
			tree.setcolour(white);
			board.getenablepos(white, p->enablepos);
			for (int i = 0; i < p->enablepos.size(); i++)
			{
				p->visit.push_back(0);
			}
		}
		else
		{
			tree.against(line, colun);
		}
		clearboard();
		printboard();
		lock2();
		tree.sim();
		tree.select(line, colun);
		if (line == -1)
		{
			curplayer = 0 - curplayer;
		}
		else
		{
			board.board[line][colun] = curplayer;
			board.reserve(line * 8 + colun, curplayer);
			curplayer = 0 - curplayer;
		}
	}
	clearboard();
	printboard();
	unlock();
	countw = 0;
	countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
}
void CMCTSDlg::OnClickedChessboard57()
{
	// TODO: 在此添加控件通知处理程序代码
	CString sss;
	int temp = 57;
	int line = temp / 8;
	int colun = temp % 8;
	board.board[line][colun] = curplayer;
	board.reserve(temp, curplayer);
	if (curplayer == white)
	{
		drawwhite(line, colun);
	}
	else
	{
		drawblack(line, colun);
	}
	lock();
	curplayer = 0 - curplayer;
	int countw = 0;
	int countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
	if (againstflag == 1)
	{
		if (is_begin == 0)
		{
			is_begin = 1;
			tree.clear();
			tree.setboard(board);
			node* p = new node(line, colun);
			tree.setroot(p);
			tree.setcolour(white);
			board.getenablepos(white, p->enablepos);
			for (int i = 0; i < p->enablepos.size(); i++)
			{
				p->visit.push_back(0);
			}
		}
		else
		{
			tree.against(line, colun);
		}
		clearboard();
		printboard();
		lock2();
		tree.sim();
		tree.select(line, colun);
		if (line == -1)
		{
			curplayer = 0 - curplayer;
		}
		else
		{
			board.board[line][colun] = curplayer;
			board.reserve(line * 8 + colun, curplayer);
			curplayer = 0 - curplayer;
		}
	}
	clearboard();
	printboard();
	unlock();
	countw = 0;
	countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
}
void CMCTSDlg::OnClickedChessboard58()
{
	// TODO: 在此添加控件通知处理程序代码
	CString sss;
	int temp = 58;
	int line = temp / 8;
	int colun = temp % 8;
	board.board[line][colun] = curplayer;
	board.reserve(temp, curplayer);
	if (curplayer == white)
	{
		drawwhite(line, colun);
	}
	else
	{
		drawblack(line, colun);
	}
	lock();
	curplayer = 0 - curplayer;
	int countw = 0;
	int countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
	if (againstflag == 1)
	{
		if (is_begin == 0)
		{
			is_begin = 1;
			tree.clear();
			tree.setboard(board);
			node* p = new node(line, colun);
			tree.setroot(p);
			tree.setcolour(white);
			board.getenablepos(white, p->enablepos);
			for (int i = 0; i < p->enablepos.size(); i++)
			{
				p->visit.push_back(0);
			}
		}
		else
		{
			tree.against(line, colun);
		}
		clearboard();
		printboard();
		lock2();
		tree.sim();
		tree.select(line, colun);
		if (line == -1)
		{
			curplayer = 0 - curplayer;
		}
		else
		{
			board.board[line][colun] = curplayer;
			board.reserve(line * 8 + colun, curplayer);
			curplayer = 0 - curplayer;
		}
	}
	clearboard();
	printboard();
	unlock();
	countw = 0;
	countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
}
void CMCTSDlg::OnClickedChessboard59()
{
	// TODO: 在此添加控件通知处理程序代码
	CString sss;
	int temp = 59;
	int line = temp / 8;
	int colun = temp % 8;
	board.board[line][colun] = curplayer;
	board.reserve(temp, curplayer);
	if (curplayer == white)
	{
		drawwhite(line, colun);
	}
	else
	{
		drawblack(line, colun);
	}
	lock();
	curplayer = 0 - curplayer;
	int countw = 0;
	int countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
	if (againstflag == 1)
	{
		if (is_begin == 0)
		{
			is_begin = 1;
			tree.clear();
			tree.setboard(board);
			node* p = new node(line, colun);
			tree.setroot(p);
			tree.setcolour(white);
			board.getenablepos(white, p->enablepos);
			for (int i = 0; i < p->enablepos.size(); i++)
			{
				p->visit.push_back(0);
			}
		}
		else
		{
			tree.against(line, colun);
		}
		clearboard();
		printboard();
		lock2();
		tree.sim();
		tree.select(line, colun);
		if (line == -1)
		{
			curplayer = 0 - curplayer;
		}
		else
		{
			board.board[line][colun] = curplayer;
			board.reserve(line * 8 + colun, curplayer);
			curplayer = 0 - curplayer;
		}
	}
	clearboard();
	printboard();
	unlock();
	countw = 0;
	countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
}
void CMCTSDlg::OnClickedChessboard60()
{
	// TODO: 在此添加控件通知处理程序代码
	CString sss;
	int temp = 60;
	int line = temp / 8;
	int colun = temp % 8;
	board.board[line][colun] = curplayer;
	board.reserve(temp, curplayer);
	if (curplayer == white)
	{
		drawwhite(line, colun);
	}
	else
	{
		drawblack(line, colun);
	}
	lock();
	curplayer = 0 - curplayer;
	int countw = 0;
	int countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
	if (againstflag == 1)
	{
		if (is_begin == 0)
		{
			is_begin = 1;
			tree.clear();
			tree.setboard(board);
			node* p = new node(line, colun);
			tree.setroot(p);
			tree.setcolour(white);
			board.getenablepos(white, p->enablepos);
			for (int i = 0; i < p->enablepos.size(); i++)
			{
				p->visit.push_back(0);
			}
		}
		else
		{
			tree.against(line, colun);
		}
		clearboard();
		printboard();
		lock2();
		tree.sim();
		tree.select(line, colun);
		if (line == -1)
		{
			curplayer = 0 - curplayer;
		}
		else
		{
			board.board[line][colun] = curplayer;
			board.reserve(line * 8 + colun, curplayer);
			curplayer = 0 - curplayer;
		}
	}
	clearboard();
	printboard();
	unlock();
	countw = 0;
	countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
}
void CMCTSDlg::OnClickedChessboard61()
{
	// TODO: 在此添加控件通知处理程序代码
	CString sss;
	int temp = 61;
	int line = temp / 8;
	int colun = temp % 8;
	board.board[line][colun] = curplayer;
	board.reserve(temp, curplayer);
	if (curplayer == white)
	{
		drawwhite(line, colun);
	}
	else
	{
		drawblack(line, colun);
	}
	lock();
	curplayer = 0 - curplayer;
	int countw = 0;
	int countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
	if (againstflag == 1)
	{
		if (is_begin == 0)
		{
			is_begin = 1;
			tree.clear();
			tree.setboard(board);
			node* p = new node(line, colun);
			tree.setroot(p);
			tree.setcolour(white);
			board.getenablepos(white, p->enablepos);
			for (int i = 0; i < p->enablepos.size(); i++)
			{
				p->visit.push_back(0);
			}
		}
		else
		{
			tree.against(line, colun);
		}
		clearboard();
		printboard();
		lock2();
		tree.sim();
		tree.select(line, colun);
		if (line == -1)
		{
			curplayer = 0 - curplayer;
		}
		else
		{
			board.board[line][colun] = curplayer;
			board.reserve(line * 8 + colun, curplayer);
			curplayer = 0 - curplayer;
		}
	}
	clearboard();
	printboard();
	unlock();
	countw = 0;
	countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
}
void CMCTSDlg::OnClickedChessboard62()
{
	// TODO: 在此添加控件通知处理程序代码
	CString sss;
	int temp = 62;
	int line = temp / 8;
	int colun = temp % 8;
	board.board[line][colun] = curplayer;
	board.reserve(temp, curplayer);
	if (curplayer == white)
	{
		drawwhite(line, colun);
	}
	else
	{
		drawblack(line, colun);
	}
	lock();
	curplayer = 0 - curplayer;
	int countw = 0;
	int countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
	if (againstflag == 1)
	{
		if (is_begin == 0)
		{
			is_begin = 1;
			tree.clear();
			tree.setboard(board);
			node* p = new node(line, colun);
			tree.setroot(p);
			tree.setcolour(white);
			board.getenablepos(white, p->enablepos);
			for (int i = 0; i < p->enablepos.size(); i++)
			{
				p->visit.push_back(0);
			}
		}
		else
		{
			tree.against(line, colun);
		}
		clearboard();
		printboard();
		lock2();
		tree.sim();
		tree.select(line, colun);
		if (line == -1)
		{
			curplayer = 0 - curplayer;
		}
		else
		{
			board.board[line][colun] = curplayer;
			board.reserve(line * 8 + colun, curplayer);
			curplayer = 0 - curplayer;
		}
	}
	clearboard();
	printboard();
	unlock();
	countw = 0;
	countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
}
void CMCTSDlg::OnClickedChessboard63()
{
	// TODO: 在此添加控件通知处理程序代码
	CString sss;
	int temp = 63;
	int line = temp / 8;
	int colun = temp % 8;
	board.board[line][colun] = curplayer;
	board.reserve(temp, curplayer);
	if (curplayer == white)
	{
		drawwhite(line, colun);
	}
	else
	{
		drawblack(line, colun);
	}
	lock();
	curplayer = 0 - curplayer;
	int countw = 0;
	int countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
	if (againstflag == 1)
	{
		if (is_begin == 0)
		{
			is_begin = 1;
			tree.clear();
			tree.setboard(board);
			node* p = new node(line, colun);
			tree.setroot(p);
			tree.setcolour(white);
			board.getenablepos(white, p->enablepos);
			for (int i = 0; i < p->enablepos.size(); i++)
			{
				p->visit.push_back(0);
			}
		}
		else
		{
			tree.against(line, colun);
		}
		clearboard();
		printboard();
		lock2();
		tree.sim();
		tree.select(line, colun);
		if (line == -1)
		{
			curplayer = 0 - curplayer;
		}
		else
		{
			board.board[line][colun] = curplayer;
			board.reserve(line * 8 + colun, curplayer);
			curplayer = 0 - curplayer;
		}
	}
	clearboard();
	printboard();
	unlock();
	countw = 0;
	countb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j] == white)
				countw++;
			if (board.board[i][j] == black)
				countb++;
		}
	}
	sss.Format(_T("%d"), countw);
	whitetext.SetWindowTextW(sss);
	sss.Format(_T("%d"), countb);
	blacktext.SetWindowTextW(sss);
	drawnow();
}




