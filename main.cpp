#include<bits/stdc++.h>
#include <fstream>
#include"ChessPieces.h"
using namespace std;
int main()
{	
	vector<chess> v;//������ � ������������������ �����
	Reading_Chess_board(v);//��������� ��������� ����� � ������ "v"
	cout<<"Input date format:\n  Knight(A5,B3);  or  Chess(A1(B2(;  or  Chess)C5)N5);  or  Chess,E8,A2,;\n  Pay attention to the register!\n>>";
	int flag=0;
	string s;
	cin>>s;
	vector<string> str(3);
	for(int i=0;i<s.size()-1;++i)//�������� �������: str[0] - ������ str[1] - ������ ���������� str[2] - ���� ����������
	{
		if(s[i]=='(' || s[i]==',' || s[i]==')')
		{
			flag++;
			continue;
		}
		str[flag].push_back(s[i]);
	}
	if(s[s.size()-1]!=';')//������: ��������� ';'
		cout<<"-Error: Expected ';'\n";
	if(flag!=3)//������: ������� �����-�� �����
		cout<<"-Error: Input data limit exceeded\n";
	flag=0;
	if(str[0]=="Knight")
		Knight(v,str,flag);
	if(flag==5) 
	{
		RewriteBoard(v);//��������� �����
		cout<<"//The move was successful\n";//��������� � ������
	}
	cout<<"Do we continual? (yes - continue; no - destroy the board; Rubbish - exit)\n>>";//����� �� �� ����������
	cin>>s;
	cout<<"\n";
	if(s=="yes" || s=="YES" || s=="Yes" || s=="YeS" || s=="yES" || s=="YEs" )
		main();//����� �� �����, ��� �����
	else if(s=="no" || s=="No" || s=="nO")
	{
		StandartBoard();//�������� ��������� �����
		cout<<"//THE END\n//The chess board was destroed";
	}
	else 
	cin>>s;
}
