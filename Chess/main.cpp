#include<iostream>
#include<vector>
#include<string>
#include <fstream>
//#include "chess.h"
#include"ChessPieces.h"
using namespace std;
int main()
{	
	vector<chess> v;//Вектор с месторасположением фигур
	Reading_Chess_board(v);//Считывает шахматную доску в вектор "v"
	cout<<"Input date format:\n  NameStartLocation-FinishLocation;\n  KnightB1-C3;  or  QweenD1-G4;  or  RookA1-A5;  or  BishopC1-E3 or PawnA2-A3;\n  Pay attention to the register!\n>>";
	int flag=0;
	string s;
	cin>>s;
	vector<string> str(3);
	for(int i=0;i<s.size()-1;++i)//Принимет команду: str[0] - фигура str[1] - откуда перемещать str[2] - куда перемещать
	{
		if((65<=s[i] && s[i]<=90) && i!=0 && s[i]!='-' && s[i]!=';')
		{
			flag++;
			str[flag].push_back(s[i]);
			continue;
		}
		if(s[i]!='-' && s[i]!=';') str[flag].push_back(s[i]);
		if(s[i]==';') break;
	}
	if(s[s.size()-1]!=';')//Ошибка: Ожидалась ';'
		cout<<"-Error: Expected ';'\n";
	if(flag!=2)//Ошибка: Введена какая-та хрень
		cout<<"-Error: Input data limit exceeded\n";
	flag=0;
	//cout <<"\n"<< str[0] << " " << str[1] << " " << str[2];
	if(str[0]=="Knight")
		Knight(v,str,flag);
	else if(str[0]=="Qween")
		Qween(v,str,flag);	
	else if(str[0]=="Rook")
		Rook(v,str,flag);
	else if(str[0]=="Bishop")
		Bishop(v,str,flag);	
	else if(str[0]=="King")
		King(v,str,flag);
	else if(str[0]=="Pawn")
		Pawn(v,str,flag);
	else 
		cout<<"Error: The bad name\n";
	
		
	if(flag==5) 
	{
		RewriteBoard(v);//обновляет доску
		cout<<"//The move was successful\n";//Сообщение о успехе
	} 
	
	cout<<"Do we continual? (yes - continue; no - destroy the board?;\n>>";//хотим ли мы продолжать?
	cin>>s;
	cout<<"\n";
	if(s=="no" || s=="No" || s=="nO")
	{
		cout<<"Destroy the board? (yes/no/ Rubbish) ( Rubbish=no)\n>>";//Хотим ли мы обнулить доску?
		cin>>s;
		if(s=="yes" || s=="YES" || s=="Yes" || s=="YeS" || s=="yES" || s=="YEs" )
		{
			StandartBoard();//Обнуляет шахматную доску
			cout<<"//THE END\n//The chess board was destroed";
		}
		else return 0;	
	}
	else 
		main();//Давай по новой, все фигня*/
}
