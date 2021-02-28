#include<iostream>
#include<vector>
#include<math.h>
#include<string>
#include <fstream>
#include "chess.h"
using namespace std;
void CheckQween(vector<chess>& v, vector<string>& str, int& flag, int& id);
void Qween(vector<chess>& v, vector<string>& str, int& flag);
void CheckPawn(vector<chess>& v, vector<string>& str, int& flag, int& id);
void Pawn(vector<chess>& v, vector<string>& str, int& flag);
void CheckKing(vector<chess>& v, vector<string>& str, int& flag, int& id);
void King(vector<chess>& v, vector<string>& str, int& flag);
void CheckKnight(vector<chess>& v, vector<string>& str, int& flag, int& id);
void Knight(vector<chess>& v, vector<string>& str, int &flag);
void RewriteBoard(vector<chess>& v);//Обновляет доску в файле 
void StandartBoard();// Обнуляет шахматную доску
void Reading_Chess_board(vector<chess>& v);
void Move(vector<chess>& v, vector<string>& str, int& id, int& flag);
void CheckBishop(vector<chess>& v, vector<string>& str, int& flag, int& id);
void Bishop(vector<chess>& v, vector<string>& str, int& flag);
void CheckRook(vector<chess>& v, vector<string>& str, int& flag, int& id);
void Rook(vector<chess>& v, vector<string>& str, int& flag);




