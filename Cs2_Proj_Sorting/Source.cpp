#include"Merge_Sort.h"
#include"Select_Sort.h"
#include"Fill.h"
#include<iostream>
using namespace std;
int main()
{
	int num = 10001;
	int* arr = new int[num];
	Fill(arr, num);
	for (int i = 0; i < num; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl << endl;
	//Select_Sort sortedtest(arr, num);
	//cout << sortedtest.get_count() << endl << endl;
	//sortedtest.print_arr();
	Merge_Sort testing(arr, 0, num-1);
	testing.print_arr();
	cout << endl << testing.get_Size()<<endl << testing.get_count();
	return 0;
}