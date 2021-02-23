#include<bits/stdc++.h>
#include <fstream>
#include"ChessPieces.h"
using namespace std;
struct chess{
	string name;
	string location;
};
void Reading_Chess_board(vector<chess> &v)
{
	chess b;
	fstream file;
	file.open("ChessBoard.txt", ios::in);
	string a;
	for(int i=0;i<32;++i)
	{
		file>>a;
		if(a!="DESTROED")//Если фигура не уничтожена
		{
			b.location+=a[a.size()-2];
			b.location+=a[a.size()-1];
			int i=0;
			while(a[i]!='-')
			{
				b.name+=a[i];
				i++;
			}	
			v.push_back(b);
			b.location="";
			b.name="";
		}
	}
	file.close();
}
void RewriteBoard(vector<chess> &v)//Обновляет доску в файле 
{
	fstream file;
	file.open("ChessBoard.txt", ios::out);
	for(int i=0;i<32;++i)
		file<<v[i].name<<"-"<<v[i].location<<"\n";
	file.close();
}
void StandartBoard()//Обнуляет шахматную доску
{
	fstream file;
	file.open("ChessBoard.txt", ios::out);
	file<<"Knight-B1\n";//Рыцари
	file<<"Knight-B8\n";
	file<<"Knight-G1\n";
	file<<"Knight-G8\n";
	file<<"King-E1\n";//Короли
	file<<"King-E8\n";
	file<<"Qween-D1\n";//Ферзи
	file<<"Qween-D8\n";
	file<<"Bishop-C1\n";//Слоны
	file<<"Bishop-F1\n";
	file<<"Bishop-C8\n";
	file<<"Bishop-F8\n";
	file<<"Rook-A1\n";//Ладьи
	file<<"Rook-A8\n";
	file<<"Rook-H1\n";
	file<<"Rook-H8\n";
	file<<"Pawn-A2\n";//Пешки
	file<<"Pawn-B2\n";
	file<<"Pawn-C2\n";
	file<<"Pawn-D2\n";
	file<<"Pawn-E2\n";
	file<<"Pawn-F2\n";
	file<<"Pawn-G2\n";
	file<<"Pawn-H2\n";
	file<<"Pawn-A7\n";
	file<<"Pawn-B7\n";
	file<<"Pawn-C7\n";
	file<<"Pawn-D7\n";
	file<<"Pawn-E7\n";
	file<<"Pawn-F7\n";
	file<<"Pawn-G7\n";
	file<<"Pawn-H7\n";
	file.close();
}
int main()
{	
	
	vector<chess> v;//Вектор с месторасположением фигур
	Reading_Chess_board(v);//Считывает шахматную доску в вектор "v"
	cout<<"Input date format:\n  Knight(A5,B3);  or  Chess(A1(B2(;  or  Chess)C5)N5);  or  Chess,E8,A2,;\n  Pay attention to the register!\n>>";
	int flag=0;
	string s;
	cin>>s;
	vector<string> str(3);
	for(int i=0;i<s.size()-1;++i)//Принимет команду: str[0] - фигура str[1] - откуда перемещать str[2] - куда перемещать
	{
		if(s[i]=='(' || s[i]==',' || s[i]==')')
		{
			flag++;
			continue;
		}
		str[flag].push_back(s[i]);
	}
	if(s[s.size()-1]!=';')//Ошибка: Ожидалась ';'
		cout<<"-Error: Expected ';'\n";
	if(flag!=3)//Ошибка: Введена какая-та хрень
		cout<<"-Error: Input data limit exceeded\n";
	flag=0;
	int id=-1;//Строка с номером нужной шахматы на доске 
	if(str[0]=="Knight")
	{
		for(int i=0;i<32;++i)
		{
			if(v[i].name == "Knight" && v[i].location==str[1]) id=i;
		}
		if(id==-1)
			cout<<"-Error: There is no such figure in this area\n";//В этой координате нет такой фигуры
		if(CheckKnight(str[1],str[2])==3 && id!=-1)
			cout<<"-Error: Initial data entered incorrectly\n";//Данные введены не правильно, ход за пределы доски
		if(CheckKnight(str[1],str[2])==2 && id!=-1) 
			cout<<"-Error: This piece cannot make this move\n";//Эта фигурв не умеет так ходить 
		if(CheckKnight(str[1],str[2])==1 && id!=-1) //если зашло в этот if то такой ход совершить можно, но там может быть фигура
		{
			for(int i=0;i<32;++i)
			{
				if(v[i].location==str[2])
				{
					cout<<"-Error: It is locally already taken\n";//там уже стоит другая фигура
					flag=1;
				}	
			}
			if(flag==0)
			{
				v[id].location=str[2];//переставляет фигуру
				flag=5;
			} 
		}
	}	
	if(flag==5) 
	{
		RewriteBoard(v);//обновляет доску
		cout<<"//The move was successful\n";//Сообщение о успехе
	}
	cout<<"Do we continual? (yes/no)\n>>";//хотим ли мы продолжать
	cin>>s;
	cout<<"\n";
	if(s=="yes" || s=="YES" || s=="Yes" || s=="YeS" || s=="yES" || s=="YEs" )
		main();//Давай по новой, все фигня
	else 
	{
		StandartBoard();//Обнуляет шахматную доску
		cout<<"//THE END\n//The chess board was destroed";
	}
	cin>>s;
}
