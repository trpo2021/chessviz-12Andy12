#include<iostream>
#include<vector>
#include<math.h>
#include<string>
#include <fstream>
#include "chess.h"
using namespace std;
void CheckQueen(vector<chess>& v, vector<string>& str, int& flag, int& id);
void Queen(vector<chess>& v, vector<string>& str, int& flag, int & switcher);//Ферзь
void CheckPawn(vector<chess>& v, vector<string>& str, int& flag, int& id);
void Pawn(vector<chess>& v, vector<string>& str, int& flag, int& switcher);//Пешка
void CheckKing(vector<chess>& v, vector<string>& str, int& flag, int& id);
void King(vector<chess>& v, vector<string>& str, int& flag, int& switcher);//Король
void CheckKnight(vector<chess>& v, vector<string>& str, int& flag, int& id);
void Knight(vector<chess>& v, vector<string>& str, int &flag, int& switcher);//Конь
void RewriteBoard(vector<chess>& v, int& switcher);//Обновляет доску в файле 
void StandartBoard();// Обнуляет шахматную доску
void Reading_Chess_board(vector<chess>& v,int &switcher);//Считывает из шахматной доски
void Move(vector<chess>& v, vector<string>& str, int& id, int& flag);
void CheckBishop(vector<chess>& v, vector<string>& str, int& flag, int& id);
void Bishop(vector<chess>& v, vector<string>& str, int& flag, int& switcher);//Слон
void CheckRook(vector<chess>& v, vector<string>& str, int& flag, int& id);
void Rook(vector<chess>& v, vector<string>& str, int& flag, int& switcher);//Ладья
void MoveSwitcher(int& switcher);//Переключает на следующую команду
void Transform(vector<chess>& v, int& id);//Превращает пешку в ферзя, если она дошла до конца доски




