#pragma once
#include<vector>
#include<time.h>
#include<random>
using namespace std;


#define white 1
#define black -1


class chessboard
{
public:
	int board[8][8] = { 0 };
	void ini()
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				board[i][j] = 0;
			}
		}
		board[3][3] = white;
		board[4][4] = white;
		board[3][4] = black;
		board[4][3] = black;
	}
	void clear()
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				board[i][j] = 0;
			}
		}
		board[3][3] = white;
		board[4][4] = white;
		board[3][4] = black;
		board[4][3] = black;
	}
	bool getenablepos(int player,vector<int>& pos)
	{
		pos.clear();
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (board[i][j] == 0)
				{					
					if (i+1<8&&board[i + 1][j] == 0 - player) 
					{
						bool wflag = 0;
						bool bflag = 0;
						int curi = i + 1;
						int curj = j;					
						while (curi >= 0 && curi < 8 && curj >= 0 && curj < 8 && (wflag == 0 || bflag == 0))
						{
							if (board[curi][curj] == 0)
								break;
							if (board[curi][curj] == white)
								wflag = 1;
							if (board[curi][curj] == black)
								bflag = 1;
							curi++;
						}
						if (wflag == 1 && bflag == 1)
							pos.push_back(i * 8 + j);
					}
					if (i-1>=0&&board[i -1][j] == 0 - player)
					{
						bool wflag = 0;
						bool bflag = 0;
						int curi = i -1;
						int curj = j;
						while (curi >= 0 && curi < 8 && curj >= 0 && curj < 8 && (wflag == 0 || bflag == 0))
						{
							if (board[curi][curj] == 0)
								break;
							if (board[curi][curj] == white)
								wflag = 1;
							if (board[curi][curj] == black)
								bflag = 1;
							curi--;
						}
						if (wflag == 1 && bflag == 1)
							pos.push_back(i * 8 + j);
					}
					if (j+1<8&&board[i][j+1] == 0 - player)
					{
						bool wflag = 0;
						bool bflag = 0;
						int curi = i;
						int curj = j+1;
						while (curi >= 0 && curi < 8 && curj >= 0 && curj < 8 && (wflag == 0 || bflag == 0))
						{
							if (board[curi][curj] == 0)
								break;
							if (board[curi][curj] == white)
								wflag = 1;
							if (board[curi][curj] == black)
								bflag = 1;
							curj++;
						}
						if (wflag == 1 && bflag == 1)
							pos.push_back(i * 8 + j);
					}
					if (j-1>=0&&board[i][j -1] == 0 - player)
					{
						bool wflag = 0;
						bool bflag = 0;
						int curi = i;
						int curj = j -1;
						while (curi >= 0 && curi < 8 && curj >= 0 && curj < 8 && (wflag == 0 || bflag == 0))
						{
							if (board[curi][curj] == 0)
								break;
							if (board[curi][curj] == white)
								wflag = 1;
							if (board[curi][curj] == black)
								bflag = 1;
							curj--;
						}
						if (wflag == 1 && bflag == 1)
							pos.push_back(i * 8 + j);
					}
					if (i+1<8&&j+1<8&&board[i+1][j +1] == 0 - player)
					{
						bool wflag = 0;
						bool bflag = 0;
						int curi = i+1;
						int curj = j+1;
						while (curi >= 0 && curi < 8 && curj >= 0 && curj < 8 && (wflag == 0 || bflag == 0))
						{
							if (board[curi][curj] == 0)
								break;
							if (board[curi][curj] == white)
								wflag = 1;
							if (board[curi][curj] == black)
								bflag = 1;
							curj++;
							curi++;
						}
						if (wflag == 1 && bflag == 1)
							pos.push_back(i * 8 + j);
					}
					if (i-1>=0&&j-1>=0&&board[i - 1][j - 1] == 0 - player)
					{
						bool wflag = 0;
						bool bflag = 0;
						int curi = i - 1;
						int curj = j - 1;
						while (curi >= 0 && curi < 8 && curj >= 0 && curj < 8 && (wflag == 0 || bflag == 0))
						{
							if (board[curi][curj] == 0)
								break;
							if (board[curi][curj] == white)
								wflag = 1;
							if (board[curi][curj] == black)
								bflag = 1;
							curj--;
							curi--;
						}
						if (wflag == 1 && bflag == 1)
							pos.push_back(i * 8 + j);
					}
					if (i+1<8&&j-1>=0&&board[i + 1][j - 1] == 0 - player)
					{
						bool wflag = 0;
						bool bflag = 0;
						int curi = i + 1;
						int curj = j - 1;
						while (curi >= 0 && curi < 8 && curj >= 0 && curj < 8 && (wflag == 0 || bflag == 0))
						{
							if (board[curi][curj] == 0)
								break;
							if (board[curi][curj] == white)
								wflag = 1;
							if (board[curi][curj] == black)
								bflag = 1;
							curj--;
							curi++;
						}
						if (wflag == 1 && bflag == 1)
							pos.push_back(i * 8 + j);
					}
					if (i-1>=0&&j+1<8&&board[i -1][j + 1] == 0 - player)
					{
						bool wflag = 0;
						bool bflag = 0;
						int curi = i - 1;
						int curj = j + 1;
						while (curi >= 0 && curi < 8 && curj >= 0 && curj < 8 && (wflag == 0 || bflag == 0))
						{
							if (board[curi][curj] == 0)
								break;
							if (board[curi][curj] == white)
								wflag = 1;
							if (board[curi][curj] == black)
								bflag = 1;
							curj++;
							curi--;
						}
						if (wflag == 1 && bflag == 1)
							pos.push_back(i * 8 + j);
					}
				}
			}
		}
		for (int i = 0; i < pos.size(); i++)
		{
			for (int j = i + 1; j < pos.size(); j++)
			{
				if (pos[i] == pos[j])
				{
					pos.erase(pos.begin() + j);
					j--;
				}
			}
		}
		if (pos.size() == 0)
			return false;
		return true;
	}
	void reserve(int pos,int player)
	{
		vector<int> x;
		vector<int> y;
		int line = pos / 8;
		int col = pos % 8;
		int curi = line+1;
		int curj = col;
		while (curi >= 0 && curi < 8 && curj >= 0 && curj < 8 && board[curi][curj] == 0 - player)
		{
			x.push_back(curi);
			y.push_back(curj);
			curi++;
		}
		if (curi >= 0 && curi < 8 && curj >= 0 && curj < 8 && board[curi][curj] == player)
		{
			for (int i = 0; i < x.size(); i++)
			{
				board[x[i]][y[i]] = player;
			}
		}
		x.clear();
		y.clear();
		curi = line - 1;
		curj = col;
		while (curi >= 0 && curi < 8 && curj >= 0 && curj < 8 && board[curi][curj] == 0 - player)
		{
			x.push_back(curi);
			y.push_back(curj);
			curi--;
		}
		if (curi >= 0 && curi < 8 && curj >= 0 && curj < 8 && board[curi][curj] == player)
		{
			for (int i = 0; i < x.size(); i++)
			{
				board[x[i]][y[i]] = player;
			}
		}
		x.clear();
		y.clear();
		curi = line;
		curj = col+1;
		while (curi >= 0 && curi < 8 && curj >= 0 && curj < 8 && board[curi][curj] == 0 - player)
		{
			x.push_back(curi);
			y.push_back(curj);
			curj++;
		}
		if (curi >= 0 && curi < 8 && curj >= 0 && curj < 8 && board[curi][curj] == player)
		{
			for (int i = 0; i < x.size(); i++)
			{
				board[x[i]][y[i]] = player;
			}
		}
		x.clear();
		y.clear();
		curi = line;
		curj = col -1;
		while (curi >= 0 && curi < 8 && curj >= 0 && curj < 8 && board[curi][curj] == 0 - player)
		{
			x.push_back(curi);
			y.push_back(curj);
			curj--;
		}
		if (curi >= 0 && curi < 8 && curj >= 0 && curj < 8 && board[curi][curj] == player)
		{
			for (int i = 0; i < x.size(); i++)
			{
				board[x[i]][y[i]] = player;
			}
		}
		x.clear();
		y.clear();
		curi = line+1;
		curj = col +1;
		while (curi >= 0 && curi < 8 && curj >= 0 && curj < 8 && board[curi][curj] == 0 - player)
		{
			x.push_back(curi);
			y.push_back(curj);
			curi++;
			curj++;
		}
		if (curi >= 0 && curi < 8 && curj >= 0 && curj < 8 && board[curi][curj] == player)
		{
			for (int i = 0; i < x.size(); i++)
			{
				board[x[i]][y[i]] = player;
			}
		}
		x.clear();
		y.clear();
		curi = line - 1;
		curj = col - 1;
		while (curi >= 0 && curi < 8 && curj >= 0 && curj < 8 && board[curi][curj] == 0 - player)
		{
			x.push_back(curi);
			y.push_back(curj);
			curi--;
			curj--;
		}
		if (curi >= 0 && curi < 8 && curj >= 0 && curj < 8 && board[curi][curj] == player)
		{
			for (int i = 0; i < x.size(); i++)
			{
				board[x[i]][y[i]] = player;
			}
		}
		x.clear();
		y.clear();
		curi = line + 1;
		curj = col - 1;
		while (curi >= 0 && curi < 8 && curj >= 0 && curj < 8 && board[curi][curj] == 0 - player)
		{
			x.push_back(curi);
			y.push_back(curj);
			curi++;
			curj--;
		}
		if (curi >= 0 && curi < 8 && curj >= 0 && curj < 8 && board[curi][curj] == player)
		{
			for (int i = 0; i < x.size(); i++)
			{
				board[x[i]][y[i]] = player;
			}
		}
		x.clear();
		y.clear();
		curi = line - 1;
		curj = col + 1;
		while (curi >= 0 && curi < 8 && curj >= 0 && curj < 8 && board[curi][curj] == 0 - player)
		{
			x.push_back(curi);
			y.push_back(curj);
			curi--;
			curj++;
		}
		if (curi >= 0 && curi < 8 && curj >= 0 && curj < 8 && board[curi][curj] == player)
		{
			for (int i = 0; i < x.size(); i++)
			{
				board[x[i]][y[i]] = player;
			}
		}
		x.clear();
		y.clear();
	}
	chessboard()
	{

	}
	chessboard(chessboard& b)
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				board[i][j] = b.board[i][j];
			}
		}
	}
	int checkwin()
	{
		int countw = 0;
		int countb = 0;
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (board[i][j] == white)
					countw++;
				if (board[i][j] == black)
					countb++;
			}
		}
		if (countw + countb == 64)
		{
			if (countw > countb)
				return white;
			if (countw < countb)
				return black;
		}
		return 0;
	}
	int checkwin2()
	{
		int countw = 0;
		int countb = 0;
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (board[i][j] == white)
					countw++;
				if (board[i][j] == black)
					countb++;
			}
		}
		if (countw > countb)
			return white;
		if (countw < countb)
			return black;		
		return 0;
	}
	int checkwin2(int colour)
	{
		int countw = 0;
		int countb = 0;
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (board[i][j] == white)
					countw++;
				if (board[i][j] == black)
					countb++;
			}
		}
		if (colour == white)
			return countw - countb;
		else
			return countb - countw;
	}
};


struct node
{
	int line=-1;
	int col=-1;
	int win = 0;
	int all = 0;
	vector<int> enablepos;
	vector<node*> child;
	vector<int> visit;
	node* father=nullptr;
	~node()
	{
		for (int i = 0; i < child.size(); i++)
		{
			if (child[i] != nullptr)
				delete child[i];
		}
	}
	node()
	{
	}
	node(int temp)
	{
		line = temp / 8;
		col = temp % 8;
	}
	node(int a,int b)
	{
		line = a;
		col = b;
	}
};


class mctree
{
private:
	chessboard board;
	int mycolour;
	node* root = nullptr;
	node* curroot = nullptr;
public:
	void bp(node* p, int a, int b)
	{	
		while (p != nullptr)
		{
			p->win += a;
			p->all += b;
			p = p->father;
		}
	}
	void setcolour(int a)
	{
		mycolour = a;
	}
	void clear()
	{
		if (root != nullptr)
			delete root;
		root = nullptr;
		curroot = nullptr;
		board.ini();
	}
	void movecurroot(int line,int col)
	{
		for (int i = 0; i < curroot->child.size(); i++)
		{
			if (curroot->child[i]->line == line && curroot->child[i]->col == col)
			{
				curroot = curroot->child[i];
				return;
			}
		}
	}
	void setroot(node* p)
	{
		root = p;
		curroot = p;
	}
	void setboard(chessboard b)
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				board.board[i][j] = b.board[i][j];
			}
		}
	}
	void against(int line, int col)
	{
		if (line == -1)
		{
			node* temp = new node(-1, -1);
			temp->father = curroot;
			temp->all = curroot->all;
			temp->win = curroot->win;
			board.getenablepos(mycolour, temp->enablepos);
			curroot = temp;
			return;
		}
		board.board[line][col] = 0 - mycolour;
		board.reserve(line * 8 + col, 0 - mycolour);
		movecurroot(line, col);
	}
	void select(int& line, int& col)
	{
		double best = -9999999;
		node* next = nullptr;
		for (int i = 0; i < curroot->child.size(); i++)
		{
			if (calucb(curroot->child[i]) > best)
			{
				best = calucb(curroot->child[i]);
				next = curroot->child[i];
			}
		}
		if (next!=nullptr&&next->line!= -1)
		{
			line = next->line;
			col = next->col;
			board.board[line][col] = mycolour;
			board.reserve(line * 8 + col, mycolour);
			curroot = next;
		}
		else
		{
			line =-1;
			col = -1;
			movecurroot(-1, -1);
		}
	}
	void sim()
	{
		default_random_engine e(time(NULL));
		clock_t t1, t2;
		t1 = clock();
		t2 = clock();
		int count1 = 0;
		while (t2 - t1 < 2000)
		{	
			chessboard boardtemp(board);
			int curcolour = mycolour;
			node* cur = curroot;
			int flag = 0;
			while (1)
			{
				if (cur->enablepos.size() == 0)
				{
					flag = flag + 1;
					node* temp = new node(-1, -1);
					temp->win = cur->win;
					temp->all = cur->all;
					temp->father = cur;
					boardtemp.getenablepos(0-curcolour, temp->enablepos);
					curcolour = 0 - curcolour;
					cur = temp;
					if (flag == 2)
					{
						if (boardtemp.checkwin2() == mycolour)
						{
							bp(cur, boardtemp.checkwin2(mycolour), 1);
							break;
						}
						else
						{
							count1++;
							bp(cur, 0, 1);
							break;
						}
					}
					continue;
				}				
				flag = 0;
				if (cur->child.size() < cur->enablepos.size())
				{
					if (cur->visit.size() != cur->enablepos.size()) 
					{
						for (int i = 0; i < cur->enablepos.size(); i++)
						{
							cur->visit.push_back(0);
						}
					}
					uniform_int_distribution<int> u(0, cur->enablepos.size() - 1);
					int nextpos;
					do
					{
						nextpos = u(e);
					} while (cur->visit[nextpos] == 1);					
					node* temp = new node(cur->enablepos[nextpos]);
					cur->child.push_back(temp);					
					cur->visit[nextpos] = 1;
					temp->father = cur;					
					boardtemp.board[temp->line][temp->col] = curcolour;
					boardtemp.reserve(cur->enablepos[nextpos], curcolour);
					boardtemp.getenablepos(0-curcolour, temp->enablepos);
					curcolour = 0 - curcolour;
					cur = temp;
					if (board.checkwin() == mycolour)
					{
						bp(temp, boardtemp.checkwin2(mycolour) , 1);
						break;
					}
					else if (board.checkwin() == 0 - mycolour)
					{
						bp(temp, 0, 1);
						break;
					}
					else
					{
						continue;
					}
				}
				else
				{
					double best;
					node* next=nullptr;
					if (curcolour == mycolour)
					{
						best = -99999;
						for (int i = 0; i < cur->child.size(); i++)
						{
							if (calucb(cur->child[i]) > best)
							{
								best = calucb(cur->child[i]);
								next = cur->child[i];
							}
						}
					}
					else
					{						
						best = -99999;
						for (int i = 0; i < cur->child.size(); i++)
						{
							if (calucb2(cur->child[i]) > best)
							{
								best = calucb2(cur->child[i]);
								next = cur->child[i];
							}
						}
					}
					if (next->line > -1 && next->col > -1)
					{
						//boardtemp.getenablepos(curcolour, next->enablepos);
						boardtemp.board[next->line][next->col] = curcolour;
						boardtemp.reserve(next->line * 8 + next->col, curcolour);
					}
					cur = next;
					curcolour = 0 - curcolour;
					if (board.checkwin() == mycolour)
					{
						bp(cur, boardtemp.checkwin2(mycolour), 1);
						break;
					}
					else if (board.checkwin() == 0 - mycolour)
					{
						bp(cur, 0, 1);
						break;
					}
					else
					{
						continue;
					}
				}
			}
			t2 = clock();
		}
		return;
	}
	double calucb(node* p, double cof=15)
	{
		double ucb;
		ucb = (double)p->win / p->all + cof * sqrt(2 * log(curroot->all) / p->all);
		return ucb;
	}
	double calucb2(node* p, double cof =15)
	{
		double ucb;
		ucb = (double)((p->all) - (p->win)) / p->all + cof * sqrt(2 * log(curroot->all) / p->all);
		return ucb;
	}
};