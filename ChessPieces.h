#include <bits/stdc++.h>
using namespace std;
struct chess{
	string name;
	string location;
	int team;
};
int CheckKnight (string str1, string str2)
{
    int x1,x2,y1,y2;
    x1=str1[0]-64;
    y1=str1[1]-48;
    x2=str2[0]-64;
    y2=str2[1]-48;
   if(x1<=8 && x1>=1 && y1<=8 && y1>=1 && x2<=8 && x2>=1 && y2<=8 && y2>=1)
   {
    
    if ((x2==x1+1 && y2==y1+2) || (x2==x1+2 && y2==y1+1) || (x2==x1+1 && y2==y1-2) || (x2==x1+2 && y2==y1-1)) return 1;
                                        
    else
    {
      if ((x2==x1-1 && y2==y1+2) || (x2==x1-2 && y2==y1+1) || (x2==x1-1 && y2==y1-2) || (x2==x1-2 && y2==y1-1)) return 1;
      else return 2;  
    }
   }
   else return 3;      
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
void Knight(vector<chess> &v, vector<string> &str, int &flag)
{
	int id=-1;//Строка с номером нужной шахматы на доске 
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
				cout<<"//The enemy figure was destroyed\n";//там уже стоит другая фигура
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
