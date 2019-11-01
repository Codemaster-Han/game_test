#ifndef _GAME_H
#define _GAME_H
#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 3
#define COL 3
#define CHESS_NUMBER 3

void Menu_Game();
void Init_Checkerboard(char Checkerboard[ROW][COL], int row, int col);
void Show_Checkerboard(char Checkerboard[ROW][COL], int row, int col);
void Player_Move(char Checkerboard[ROW][COL], int row, int col);
void Computer_Move(char Checkerboard[ROW][COL], int row, int col);
char Full_Checkerboard(char Checkerboard[ROW][COL], int row, int col);
char Win_Game(char Checkerboard[ROW][COL], int row, int col);
void Game(char Checkerboard[ROW][COL], int row, int col);

#endif