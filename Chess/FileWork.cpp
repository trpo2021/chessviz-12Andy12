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
		file << v[i].name << "-" << v[i].team << "-" << v[i].location << "-" << v[i].countmove << "\n";
	file << switcher;
	file.close();
}
void StandartBoard()//Обнуляет шахматную доску
{
	fstream file;
	file.open("ChessBoard.txt", ios::out);
	file << "Knight-1-B1-0\n";//Рыцари
	file << "Knight-2-B8-0\n";
	file << "Knight-1-G1-0\n";
	file << "Knight-2-G8-0\n";
	file << "King-1-E1-0\n";//Короли
	file << "King-2-E8-0\n";
	file << "Queen-1-D1-0\n";//Ферзи
	file << "Queen-2-D8-0\n";
	file << "Bishop-1-C1-0\n";//Слоны
	file << "Bishop-1-F1-0\n";
	file << "Bishop-2-C8-0\n";
	file << "Bishop-2-F8-0\n";
	file << "Rook-1-A1-0\n";//Ладьи
	file << "Rook-2-A8-0\n";
	file << "Rook-1-H1-0\n";
	file << "Rook-2-H8-0\n";
	file << "Pawn-1-A2-0\n";//Пешки
	file << "Pawn-1-B2-0\n";
	file << "Pawn-1-C2-0\n";
	file << "Pawn-1-D2-0\n";
	file << "Pawn-1-E2-0\n";
	file << "Pawn-1-F2-0\n";
	file << "Pawn-1-G2-0\n";
	file << "Pawn-1-H2-0\n";
	file << "Pawn-2-A7-0\n";
	file << "Pawn-2-B7-0\n";
	file << "Pawn-2-C7-0\n";
	file << "Pawn-2-D7-0\n";
	file << "Pawn-2-E7-0\n";
	file << "Pawn-2-F7-0\n";
	file << "Pawn-2-G7-0\n";
	file << "Pawn-2-H7-0\n";
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
			b.location += a[a.size() - 4];
			b.location += a[a.size() - 3];
			int i = 0;
			while (a[i] != '-')
			{
				b.name += a[i];
				i++;
			}
			if (a[i] == '-') b.team = a[i + 1] - 48;
			b.countmove = a[a.size()];
			v.push_back(b);
			b.location = "";
			b.name = "";
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
		v[id].countmove++;
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