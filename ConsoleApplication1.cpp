// таблица наименьших общих кратных до 24
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <Windows.h>

using namespace std;
int nok(int a, int b, int c)
{
	int max = c;
	for (int i = max; i > 0; i++) {
		if ((i % a == 0) && (i % b == 0) && (i % c == 0)) {
			return i;
		}
	}
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	vector<int> NumRow, newString;
	vector<vector<int>> NOKTable;
	NumRow.push_back(' ');
	for (int i = 0; i < 24; i++)
	{
		NumRow.push_back(i+1);
	}
	NOKTable.push_back(NumRow);//ряд исх чисел
	for (int i = 0; i < 24; i++)
	{
		newString.push_back(i+1);
		for (int j = 0; j < 24; j++)
		{
			newString.push_back(nok(i + 1, j + 1, 1));
		}
		NOKTable.push_back(newString);
		newString.clear();
	}
	cout << "Таблица наименьших общих кратных:\n";
	//cout << " ";
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			if (NOKTable[i][j] < 10) cout << "  " << NOKTable[i][j] << "  ";
			else if (NOKTable[i][j] < 100) cout << " " << NOKTable[i][j] << "  ";
			else cout << " " << NOKTable[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
	for (int i = 0; i < NOKTable.size(); i++)
	{
		if(NOKTable[i][0]<10) cout << NOKTable[i][0]<<"  ";
		else cout << NOKTable[i][0] << " ";
		for (int j = 16; j < NOKTable.size(); j++)
		{
			if (NOKTable[i][j] < 10) cout << "  " << NOKTable[i][j] << "  ";
			else if (NOKTable[i][j] < 100) cout << " " << NOKTable[i][j] << "  ";
			else cout << " " << NOKTable[i][j] << " ";
		}
		cout << "\n";
	}
	system("pause");
    return 0;
}

