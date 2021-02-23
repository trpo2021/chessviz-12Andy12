#include<bits/stdc++.h>
#include <fstream>
#include"ChessPieces.h"
using namespace std;
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
	if(str[0]=="Knight")
		Knight(v,str,flag);
	if(flag==5) 
	{
		RewriteBoard(v);//обновляет доску
		cout<<"//The move was successful\n";//Сообщение о успехе
	}
	cout<<"Do we continual? (yes - continue; no - destroy the board; Rubbish - exit)\n>>";//хотим ли мы продолжать
	cin>>s;
	cout<<"\n";
	if(s=="yes" || s=="YES" || s=="Yes" || s=="YeS" || s=="yES" || s=="YEs" )
		main();//Давай по новой, все фигня
	else if(s=="no" || s=="No" || s=="nO")
	{
		StandartBoard();//Обнуляет шахматную доску
		cout<<"//THE END\n//The chess board was destroed";
	}
	else 
	cin>>s;
}
