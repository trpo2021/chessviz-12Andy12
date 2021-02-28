#include<iostream>
#include<vector>
#include<string>
#include"ChessPieces.h"
using namespace std;
void CheckRook(vector<chess>& v, vector<string>& str, int& flag, int& id)
{
	int x1, x2, y1, y2;
	x1 = str[1][0] - 64;
	y1 = str[1][1] - 48;
	x2 = str[2][0] - 64;
	y2 = str[2][1] - 48;
	if (x1 <= 8 && x1 >= 1 && y1 <= 8 && y1 >= 1 && x2 <= 8 && x2 >= 1 && y2 <= 8 && y2 >= 1)
	{
		if (x1 == x2 || y1 == y2)
			Move(v, str, id, flag);
		else
			cout << "-Error: This piece cannot make this move\n";//��� ������ �� ����� ��� ������ 
	}
	else
		cout << "-Error: Initial data entered incorrectly\n";//������ ������� �� ���������, ��� �� ������� �����
}
void Rook(vector<chess>& v, vector<string>& str, int& flag)
{
	int id = -1;//������ � ������� ������ ������� �� ����� 
	for (int i = 0; i < 32; ++i)
		if (v[i].name == "Rook" && v[i].location == str[1])
			id = i;
	if (id == -1)
		cout << "-Error: There is no such figure in this area\n";//� ���� ���������� ��� ����� ������
	else
		CheckRook(v, str, flag, id);
}