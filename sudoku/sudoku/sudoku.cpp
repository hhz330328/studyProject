#include"sudoku.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
ostream& operator <<(ostream& out, number& a)
{
	out << a.value;
	return out;
}
istream& operator>>(istream& in, number& a)
{
	in >> a.value;
	return in;
}
void clear(number* pos)
{
	if (pos->value == 0)
		return;
	if (pos->alloced==0)
	{
		pos->alloced = 1;
		pos->column->allocation[pos->value]++;
		pos->line->allocation[pos->value]++;
		pos->square->allocation[pos->value]++;
	}
	pos->column->possible[pos->value] = 0;
	pos->line->possible[pos->value] = 0;
	pos->square->possible[pos->value] = 0;
	for (int j = 0; j < 9; j++)
	{
		
		if (pos->column->member[j]->possible[pos->value] == 0)
		{
			pos->column->member[j]->possible[pos->value] = 1;
			pos->column->member[j]->possible[0]--;
		}
		if (pos->line->member[j]->possible[pos->value] == 0)
		{
			pos->line->member[j]->possible[pos->value] = 1;
			pos->line->member[j]->possible[0]--;
		}
		if (pos->square->member[j]->possible[pos->value] == 0)
		{
			pos->square->member[j]->possible[pos->value] = 1;
			pos->square->member[j]->possible[0]--;
		}
		pos->column->member[j]->column->possible[pos->value]--;
		pos->column->member[j]->square->possible[pos->value]--;
		pos->column->member[j]->line->possible[pos->value]--;
		pos->line->member[j]->column->possible[pos->value]--;
		pos->line->member[j]->square->possible[pos->value]--;
		pos->line->member[j]->line->possible[pos->value]--;
		pos->square->member[j]->column->possible[pos->value]--;
		pos->square->member[j]->square->possible[pos->value]--;
		pos->square->member[j]->line->possible[pos->value]--;
	}
}
void sudoku::read(string path)
{
	ifstream in(path);
	for (int i = 0; i < 81; i++)
	{
		in >> sudonumber[i];
	}
	in.close();
}
void sudoku::ini()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			sudoline[i].member[j] = &(sudonumber[i * 9 + j]);
			sudonumber[i * 9 + j].line = &(sudoline[i]);
			sudocolumn[i].member[j] = &(sudonumber[i + j * 9]);
			sudonumber[i + j * 9].column = &(sudocolumn[i]);
		}
	}
	for (int i = 0, count = 0; i < 81; i = i + 3)
	{
		for (int j = i, count2 = 0; j < i + 27; j = j + 9)
		{
			for (int k = j; k < j + 3; k++)
			{
				sudosquare[count].member[count2++] = &(sudonumber[k]);
				sudonumber[k].square = &(sudosquare[count]);
			}
		}
		count++;
		if (count % 3 == 0)
		{
			i += 18;
		}
	}
	for (int i = 0; i < 81; i++)
	{
		if (sudonumber[i].value != 0)
		{
			clear(&(sudonumber[i]));
		}
	}
}

void sudoku::ini2()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			sudoline[i].member[j] = &(sudonumber[i * 9 + j]);
			sudonumber[i * 9 + j].line = &(sudoline[i]);
			sudocolumn[i].member[j] = &(sudonumber[i + j * 9]);
			sudonumber[i + j * 9].column = &(sudocolumn[i]);
		}
	}
	for (int i = 0, count = 0; i < 81; i = i + 3)
	{
		for (int j = i, count2 = 0; j < i + 27; j = j + 9)
		{
			for (int k = j; k < j + 3; k++)
			{
				sudosquare[count].member[count2++] = &(sudonumber[k]);
				sudonumber[k].square = &(sudosquare[count]);
			}
		}
		count++;
		if (count % 3 == 0)
		{
			i += 18;
		}
	}
}


int sudoku::search()
{
	int min = 9;
	int minpos = -1;
	for (int i = 0; i < 81; i++)
	{
		if (sudonumber[i].value==0 && sudonumber[i].possible[0] <= min)
		{
			min = sudonumber[i].possible[0];
			minpos = i;
		}
	}
	sudoku temp(*this);
	for (int i = 1; i < 10; i++)
	{
		if (sudonumber[minpos].possible[i] == 0)
		{
			sudonumber[minpos].value = i;
			clear(&(sudonumber[minpos]));
			int end = solve();
			if (end == 1)
				return 1;
			if (end == -1)
			{
				*this = temp;
				ini2();
				sudonumber[minpos].value = 0;
				sudonumber[minpos].possible[i] = 1;
				sudonumber[minpos].possible[0]--;
				sudonumber[minpos].column->possible[i]--;
				sudonumber[minpos].line->possible[i]--;
				sudonumber[minpos].square->possible[i]--;
				temp = *this;
				
			}
		}
	}
	return -1;
}

int sudoku::checkall()
{
	int flag = 1;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			if (sudocolumn[i].allocation[j] == 0)
				flag = 0;
			if (sudocolumn[i].allocation[j] > 1)
				return -1;
		}
	}
	return flag;
}

int sudoku::solve()
{
	bool flag = true;
	while (flag)
	{
		flag = false;
		for (int i = 0; i < 9; i++)
		{
			flag = flag || sudocolumn[i].search();
			flag = flag || sudoline[i].search();
			flag = flag || sudosquare[i].search();
		}
	}
	int end=checkall();
	if (end == 1)
		return 1;
	if (end == -1)
		return -1;
	if (end == 0)
		return search();
}

void sudoku::print()
{
	for (int i = 0; i < 81; i++)
	{
		if (i % 9 == 0)
			cout << endl;
		cout << sudonumber[i];
	}
}

sudoku& sudoku::operator=(const sudoku& a)
{
	for (int i = 0; i < 81; i++)
	{
		sudonumber[i] = a.sudonumber[i];
	}
	for (int i = 0; i < 9; i++)
	{
		sudocolumn[i] = a.sudocolumn[i];
		sudoline[i] = a.sudoline[i];
		sudosquare[i] = a.sudosquare[i];
	}
	return *this;
}

bool aggregate::check()
{
	for (int i = 0; i < 10; i++)
	{
		if (allocation[i] > 1)
			return false;
	}
	return true;
}

bool aggregate::search()
{
	for (int i = 0; i < 9; i++)
	{
		if (member[i]->value == 0 && member[i]->possible[0] == 1)
		{
			for (int j = 1; j < 10; j++)
			{
				if (member[i]->possible[j] == 0)
				{
					member[i]->value = j;
					clear(member[i]);
					return true;
				}
			}
		}
	}
	for (int i = 1; i < 10; i++)
	{
		if (possible[i] == 1)
		{
			int count = 0;
			int pos = -1;
			for (int j = 0; j < 9&&count<2; j++)
			{
				if (member[j]->possible[i] == 0)
				{
					count++;
					pos = j;
				}				
			}
			if (count == 1)
			{
				member[pos]->value = i;
				clear(member[pos]);
				return true;
			}
		}
	}
	return false;
}
