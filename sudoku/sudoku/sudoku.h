#pragma once
#include<iostream>
using namespace std;
class aggregate;
struct number
{
	bool alloced = false;
	int value=0;
	int possible[10] = { 0 };
	aggregate* square = nullptr;
	aggregate* line = nullptr;
	aggregate* column = nullptr;
	number()
	{
		possible[0] = 9;
	}
	number(number& a)
	{
		alloced = a.alloced;
		value = a.value;
		for (int i = 0; i < 10; i++)
		{
			possible[i] = a.possible[i];
		}
	}
	number& operator =(const number& a)
	{
		alloced = a.alloced;
		value = a.value;
		for (int i = 0; i < 10; i++)
		{
			possible[i] = a.possible[i];
		}
		return *this;
	}
};

class aggregate
{
	friend class sudoku;
	friend void clear(number* pos);
private:
	int allocation[10] = { 0 };
	int possible[10] = { 9,9,9,9,9,9,9,9,9,9 };
	number* member[9] = { nullptr };
	bool check();
	bool search();
public:	
	aggregate()
	{

	}
	aggregate(aggregate& a)
	{
		for (int i = 0; i < 10; i++)
		{
			allocation[i] = a.allocation[i];
			possible[i] = a.possible[i];
		}
	}
	aggregate& operator = (const aggregate& a)
	{
		for (int i = 0; i < 10; i++)
		{
			allocation[i] = a.allocation[i];
			possible[i] = a.possible[i];
		}
		return *this;
	}
};

class sudoku
{
private:
	aggregate sudoline[9];
	aggregate sudocolumn[9];
	aggregate sudosquare[9];
	number sudonumber[81];
public:
	void ini();
	void ini2();
	void read(std::string path);
	int search();
	int checkall();
	int solve();
	void print();
	sudoku& operator=(const sudoku& a);
	sudoku(sudoku& a)
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
	}
	sudoku()
	{

	}
};


