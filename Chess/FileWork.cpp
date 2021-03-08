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
		file << v[i].name << "-" << v[i].team << "-" << v[i].location << "\n";
	file << switcher;
	file.close();
}
void StandartBoard()//Обнуляет шахматную доску
{
	fstream file;
	file.open("ChessBoard.txt", ios::out);
	file << "Knight-1-B1\n";//Рыцари
	file << "Knight-2-B8\n";
	file << "Knight-1-G1\n";
	file << "Knight-2-G8\n";
	file << "King-1-E1\n";//Короли
	file << "King-2-E8\n";
	file << "Queen-1-D1\n";//Ферзи
	file << "Queen-2-D8\n";
	file << "Bishop-1-C1\n";//Слоны
	file << "Bishop-1-F1\n";
	file << "Bishop-2-C8\n";
	file << "Bishop-2-F8\n";
	file << "Rook-1-A1\n";//Ладьи
	file << "Rook-2-A8\n";
	file << "Rook-1-H1\n";
	file << "Rook-2-H8\n";
	file << "Pawn-1-A2\n";//Пешки
	file << "Pawn-1-B2\n";
	file << "Pawn-1-C2\n";
	file << "Pawn-1-D2\n";
	file << "Pawn-1-E2\n";
	file << "Pawn-1-F2\n";
	file << "Pawn-1-G2\n";
	file << "Pawn-1-H2\n";
	file << "Pawn-2-A7\n";
	file << "Pawn-2-B7\n";
	file << "Pawn-2-C7\n";
	file << "Pawn-2-D7\n";
	file << "Pawn-2-E7\n";
	file << "Pawn-2-F7\n";
	file << "Pawn-2-G7\n";
	file << "Pawn-2-H7\n";
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
		if (a != "DESTROED-0-")//Если фигура не уничтожена
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
			v.push_back(b);
			b.location = "";
			b.name = "";
		}
		else if (a == "DESTROED-0-")
		{
			b.location = "";
			b.team = 0;
			b.name = "DESTROED";
			v.push_back(b);
			b.location = "";
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