#include<iostream>
#include<fstream>
#include<vector>
#include"sudoku.h"
#include<time.h>
using namespace std;
int main()     //��β���
{
	clock_t t1, t2;
	t1 = clock();
	for (int i = 0; i < 10000; i++)
	{
		sudoku sudo;
		sudo.read("C:\\Users\\86150\\source\\repos\\sudoku\\test.txt");		
		sudo.ini();
		sudo.solve();		
	}
	t2 = clock();
	cout << endl <<"����10000������ʱ��"<< t2 - t1 << endl;
}
/*
int main()     
{
	clock_t t1, t2;
	t1 = clock();
	sudoku sudo;
	sudo.read("C:\\Users\\86150\\source\\repos\\sudoku\\test.txt");
	sudo.print();
	cout << endl << "���" << endl;
	sudo.ini();
	sudo.solve();
	sudo.print();
	t2 = clock();
	cout << endl << "����10000������ʱ��" << t2 - t1 << endl;
}
*/