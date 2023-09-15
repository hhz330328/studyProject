#include<iostream>
#include<fstream>
#include<vector>
#include"sudoku.h"
#include<time.h>
using namespace std;
int main()     //万次测试
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
	cout << endl <<"运行10000次所需时间"<< t2 - t1 << endl;
}
/*
int main()     
{
	clock_t t1, t2;
	t1 = clock();
	sudoku sudo;
	sudo.read("C:\\Users\\86150\\source\\repos\\sudoku\\test.txt");
	sudo.print();
	cout << endl << "解答" << endl;
	sudo.ini();
	sudo.solve();
	sudo.print();
	t2 = clock();
	cout << endl << "运行10000次所需时间" << t2 - t1 << endl;
}
*/