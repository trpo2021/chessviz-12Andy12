#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "ChessPieces.h"
using namespace std;
int main()
{	
	int switcher;
	vector<chess> v;//������ � ������������������ �����
	Reading_Chess_board(v,switcher);//��������� ��������� ����� � ������ "v"  +  switcher - ����� �������, ������� ������ ������ ���
	cout << "Now the "<<switcher<<" teem is moving";
	cout << "\nInput date format:\n  NameStartLocation-FinishLocation;\n  KnightB1-C3;  or  QueenD1-G4;  or  RookA1-A5;  or  BishopC1-E3 or PawnA2-A3;\n  Pay attention to the register!\n>>";
	int flag=0;
	string s;
	getline(cin, s);//��������� ������
	vector<string> str(3);
	for(int i=0;i<s.size()-1;++i)//�������� �������: str[0] - ������ str[1] - ������ ���������� str[2] - ���� ����������
	{
		if((65<=s[i] && s[i]<=90) && i!=0)//���� ������ �� ������ � ������ � �������� A-Z 
		{
			flag++;
			str[flag].push_back(s[i]);
			continue;
		}
		if(s[i]!='-' && s[i]!=';' && s[i]!=' ') //������ ��� ��� �� ' '  '-'  ';'
			str[flag].push_back(s[i]);
		if(s[i]==';') //���������� ���� ����� ����� � �������
			break; 
	}
	if(s[s.size()-1]!=';')//������: ��������� ';'
		cout<<"-Error: Expected ';'\n";
	if(flag!=2)//������: ������� �����-�� �����
		cout<<"-Error: Input data limit exceeded\n";
	flag=0;//���� ������������� ��� ����� ������, � ���������� �� ��� ����������� => �������� ���

	/* 
	   �������� ��������������� �������
	   � ������� ������� ��������������: ���������� ��������� �����, 
										 	 ������� ������, 
												 ����(������ ��� �������� - ��������� ���������� ���������), 
													 ����� �������, ������� ������ �����
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
		cout<<"Error: The bad name\n";//�� ����� ������� �������� ������

	/*
		flag==5 - ������ ��� ������ � ������ ��� ����������
		flag==4 - �� ���� ���� ���������� ���������� ������ => ��� ��� ��������
		flag==1 - �������� ���������� ������ ������ ��� ��������� (������ ��� �����) �������
		flag==0 - ������ �� ����� ��� ������, ����� ������ �� �������� ����������
		��� ���������� ������ flag==5;
	*/

	if (flag == 5)//����, ��� ��� ��� ��������
	{
		MoveSwitcher(switcher);//����������� �� ��������� �������
		RewriteBoard(v, switcher);//��������� �����
		cout << "//The move was successful\n";//��������� � ������
	}
	else
		cout << "//The move was not successful\n";//��������� � �������


	cout<<"Do we continual? (yes - continue; no - destroy the board?;\n>>";//����� �� �� ����������?
	getline(cin, s);
	cout<<"\n";
	if(s=="no" || s=="No" || s=="nO")
	{
		cout<<"Destroy the board? (yes/no/ Rubbish) ( Rubbish=no)\n>>";//����� �� �� �������� �����?
		cin>>s;
		if(s=="yes" || s=="YES" || s=="Yes" || s=="YeS" || s=="yES" || s=="YEs" )
		{
			StandartBoard();//�������� ��������� �����
			cout<<"//THE END\n//The chess board was destroed";
		}
		else return 0;	
	}
	else
		main();//����� �� �����, ��� �����*/	
}
