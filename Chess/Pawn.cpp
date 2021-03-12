#include<iostream>
#include<vector>
#include<string>
#include"ChessPieces.h"
using namespace std;
void CheckPawn(vector<chess>& v, vector<string>& str, int& flag, int& id)
{
	int x1, x2, y1, y2;
	int c=0;
	// ������������ ������� ������ � ���������� ��� �������� (����� � ��� �����, �� ��� ��� ��������)
	x1 = str[1][0] - 64;
	y1 = str[1][1] - 48;
	x2 = str[2][0] - 64;
	y2 = str[2][1] - 48;
	if (x1 <= 8 && x1 >= 1 && y1 <= 8 && y1 >= 1 && x2 <= 8 && x2 >= 1 && y2 <= 8 && y2 >= 1)
	{
		if ( ((y2 == y1 + 1 && v[id].team == 1 && x2 == x1)  ||  (y2 == y1 - 1 && v[id].team == 2 && x2 == x1)) || (y2 == y1 + 2 && v[id].team == 1 && x2 == x1)  || (y2 == y1 - 2 && v[id].team == 2 && x2 == x1))
		{
			for (int i = 0; i < 32; ++i)
			{
				if (v[i].location == str[2] && v[i].team != v[id].team)//��������� ������ ������
				{
					cout << "//A enemy figure gets in the way\n";
					flag = 1;
				}
				else if (v[i].location == str[2] && v[i].team == v[id].team)//������� ������ ������
				{
					cout << "//A friendly figure gets in the way\n";
					flag = 1;
				}
			}
			if (flag == 0)//���� ������ �� ������ ����������� ������
			{
				v[id].location = str[2];//������������ ������
				flag = 5;
				++v[id].countmove;
				Transform(v, id);//���������� ����� � �����, ���� ��� ����� �� ����� �����
			}
		}
		else if (abs(x1 - x2) == 1 && y2 == y1 + 1)//��� ��� �����������
		{
			for (int i = 0; i < 32; ++i)
			{
				if (v[i].location == str[2] && v[i].team != v[id].team)//��������� ������ ����� �� ���� ����������
				{
					cout << "//The enemy figure '" << v[i].name << "' was destroyed\n";//�������� � ���, ��� ��������� ������ ����������
					flag = 4;//����, ��� ������ ���������� � �������������� ��� ��� ��������
					v[i].name = "DESTROED";
					v[i].location = "";
					v[i].team = 0;
				}
				else if (v[i].location == str[2] && v[i].team == v[id].team)//������� ������ ����� �� ���� �����������
				{
					cout << "//A friendly figure gets in the way\n";//������� ������ ������
					flag = 1;
				}
			}
			if (flag == 0)//��� �� ����� ���� �������
				cout << "The This piece cannot make this move\n";
			if (flag == 4)
			{
				v[id].location = str[2];//������������ ������
				flag = 5;
				++v[id].countmove;
				Transform(v, id);//���������� ����� � �����, ���� ��� ����� �� ����� �����
			}
		}
		else
			cout << "-Error: This piece cannot make this move\n";//��� ������ �� ����� ��� ������ 
	}
	else
		cout << "-Error: Initial data entered incorrectly\n";//������ ������� �� ���������, ��� �� ������� �����
}
void Transform(vector<chess>& v, int& id)//���������� ����� � �����, ���� ��� ����� �� ����� �����
{
	if ((v[id].location[1] == '8' && v[id].team == 1) || (v[id].location[1] == '1' && v[id].team == 2))
	{
		cout << "The Pawn transform to Queen\n";
		v[id].name = "Queen";
	}
}
void Pawn(vector<chess>& v, vector<string>& str, int& flag, int& switcher)
{
	int id = -1;//������ � ������� ������ ������� �� ����� 
	for (int i = 0; i < 32; ++i)
		if (v[i].name == "Pawn" && v[i].location == str[1])
			id = i;
	if (id == -1)
		cout << "-Error: There is no such figure in this area\n";//� ���� ���������� ��� ����� ������
	else if (v[id].team != switcher)
		cout << "It's time to another team\n";
	else
		CheckPawn(v, str, flag, id);
}
