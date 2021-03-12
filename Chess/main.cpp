#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "ChessPieces.h"
using namespace std;
int main()
{	
	int switcher;
	vector<chess> v;//Вектор с месторасположением фигур
	Reading_Chess_board(v,switcher);//Считывает шахматную доску в вектор "v"  +  switcher - номер команды, которая сейчас делает ход
	cout << "Now the "<<switcher<<" teem is moving";
	cout << "\nInput date format:\n  NameStartLocation-FinishLocation;\n  KnightB1-C3;  or  QueenD1-G4;  or  RookA1-A5;  or  BishopC1-E3 or PawnA2-A3;\n  Pay attention to the register!\n>>";
	int flag=0;
	string s;
	getline(cin, s);//Считываем строку
	vector<string> str(3);
	for(int i=0;i<s.size()-1;++i)//Принимет команду: str[0] - фигура str[1] - откуда перемещать str[2] - куда перемещать
	{
		if((65<=s[i] && s[i]<=90) && i!=0)//Если символ не первый и входит в диапазон A-Z 
		{
			flag++;
			str[flag].push_back(s[i]);
			continue;
		}
		if(s[i]!='-' && s[i]!=';' && s[i]!=' ') //Вводим все что не ' '  '-'  ';'
			str[flag].push_back(s[i]);
		if(s[i]==';') //Прекращаем ввод после точки с запятой
			break; 
	}
	if(s[s.size()-1]!=';')//Ошибка: Ожидалась ';'
		cout<<"-Error: Expected ';'\n";
	if(flag!=2)//Ошибка: Введена какая-та хрень
		cout<<"-Error: Input data limit exceeded\n";
	flag=0;//Флаг использовался для ввода данных, в дальнейшем он еще понадобится => обнуляем его

	/* 
	   Вызываем соответствующую функцию
	   В функцию пердаем соответственно: Актуальную шахматную доску, 
										 	 Входные данные, 
												 Флаг(теперь его значение - результат выполнения программы), 
													 Номер команды, которая сейчас ходит
	*/

	if(str[0]=="Knight")
		Knight(v,str,flag, switcher);
	else if(str[0]=="Queen")
		Queen(v,str,flag, switcher);
	else if(str[0]=="Rook")
		Rook(v,str,flag, switcher);
	else if(str[0]=="Bishop")
		Bishop(v,str,flag, switcher);
	else if(str[0]=="King")
		King(v,str,flag, switcher);
	else if(str[0]=="Pawn")
		Pawn(v,str,flag, switcher);
	else 
		cout<<"Error: The bad name\n";//Не верно введено название фигуры

	/*
		flag==5 - Просто ход сделан и фигура уже перемещена
		flag==4 - На этом ходу уничтожена вражесская фигура => ход был совершен
		flag==1 - Конечные координаты заняты созной или вражеской (только для пешки) фигурой
		flag==0 - Фигура не умеет так ходить, чтобы встать на заданные координаты
		нас интересует только flag==5;
	*/

	if (flag == 5)//Флаг, что ход был совершен
	{
		MoveSwitcher(switcher);//Переключает на следующую команду
		RewriteBoard(v, switcher);//обновляет доску
		cout << "//The move was successful\n";//Сообщение о успехе
	}
	else
		cout << "//The move was not successful\n";//Сообщение о провале


	cout<<"Do we continual? (yes - continue; no - destroy the board?;\n>>";//хотим ли мы продолжать?
	getline(cin, s);
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
