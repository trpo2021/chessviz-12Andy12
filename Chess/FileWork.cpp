#include<iostream>
#include<vector>
#include<string>
#include <fstream>
#include"ChessPieces.h"
using namespace std;
void RewriteBoard(vector<chess>& v,int &switcher)//Обновляет доску в файле 
{
	fstream file;
	file.open("ChessBoard.txt", ios::out);
	for (int i = 0; i < 32; ++i)
		file << v[i].name << "-" << v[i].team << "-" << v[i].countmove << "-" << v[i].location << "\n";
	file << switcher;
	file.close();
}
void StandartBoard()//Обнуляет шахматную доску
{
	fstream file;
	file.open("ChessBoard.txt", ios::out);
	file << "Knight-1-0-B1\n";//Рыцари
	file << "Knight-2-0-B8\n";
	file << "Knight-1-0-G1\n";
	file << "Knight-2-0-G8\n";
	file << "King-1-0-E1\n";//Короли
	file << "King-2-0-E8\n";
	file << "Queen-1-0-D1\n";//Ферзи
	file << "Queen-2-0-D8\n";
	file << "Bishop-1-0-C1\n";//Слоны
	file << "Bishop-1-0-F1\n";
	file << "Bishop-2-0-C8\n";
	file << "Bishop-2-0-F8\n";
	file << "Rook-1-0-A1\n";//Ладьи
	file << "Rook-2-0-A8\n";
	file << "Rook-1-0-H1\n";
	file << "Rook-2-0-H8\n";
	file << "Pawn-1-0-A2\n";//Пешки
	file << "Pawn-1-0-B2\n";
	file << "Pawn-1-0-C2\n";
	file << "Pawn-1-0-D2\n";
	file << "Pawn-1-0-E2\n";
	file << "Pawn-1-0-F2\n";
	file << "Pawn-1-0-G2\n";
	file << "Pawn-1-0-H2\n";
	file << "Pawn-2-0-A7\n";
	file << "Pawn-2-0-B7\n";
	file << "Pawn-2-0-C7\n";
	file << "Pawn-2-0-D7\n";
	file << "Pawn-2-0-E7\n";
	file << "Pawn-2-0-F7\n";
	file << "Pawn-2-0-G7\n";
	file << "Pawn-2-0-H7\n";
	file << "1\n";
	file.close();
}
void Reading_Chess_board(vector<chess>& v,int &switcher)
{
	chess b;
	fstream file;
	file.open("ChessBoard.txt", ios::in);
	string a;
	for (int i = 0; i < 32; ++i)
	{
		file >> a;
		if (a != "DESTROED-0--0")//Если фигура не уничтожена
		{
			b.location += a[a.size() - 2];
			b.location += a[a.size() - 1];
			int i = 0;
			while (a[i] != '-')
			{
				b.name += a[i];
				i++;
			}
			if (a[i] == '-') b.team = a[i + 1] - 48;
			int j = i + 3;
			int n = a.size() - 3;
			while (j<n)
			{
				b.countmove += (a[j]-48)+(n-j-1)*10;
				++j;
			}
			v.push_back(b);
			b.location = "";
			b.name = "";
			b.countmove = 0;
		}
		else if (a == "DESTROED-0--0")
		{
			b.location = "";
			b.team = 0;
			b.countmove = 0;
			b.name = "DESTROED";
			v.push_back(b);
			b.name = "";
		}
	}
	file >> a;
	switcher = a[0] - 48;
	file.close();
}
void Move(vector<chess>& v, vector<string>& str, int& id, int& flag)
{
	for (int i = 0; i < 32; ++i)
	{
		if (v[i].location == str[2] && v[i].team != v[id].team)
		{
			cout << "//The enemy figure '" << v[i].name << "' was destroyed\n";//Вражеская фигура уничтожена
			flag = 0;
			v[i].name = "DESTROED";
			v[i].location = "";
			v[i].team = 0;
			v[i].countmove = 0;
		}
		else if (v[i].location == str[2] && v[i].team == v[id].team)
		{
			cout << "//A friendly figure gets in the way\n";//Союзная фигура мешает
			flag = 1;
		}
	}
	if (flag == 0)
	{
		v[id].location = str[2];//переставляет фигуру
		++v[id].countmove;
		flag = 5;
	}
}
void MoveSwitcher(int &switcher)//Переключает на следующую команду
{
	if (switcher == 1)
		switcher = 2;
	else
		switcher = 1;
}