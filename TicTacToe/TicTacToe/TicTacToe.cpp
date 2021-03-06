// TicTacToe.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//全局变量
const char X = 'X';
const char O = 'O';
const char EMPTY = ' ';
const char TIE = 'T';
const char NO_ONE = 'N';

//函数原型
void instruction();
char askYesNo(string question);
int askNumber(string question, int high, int low = 0);
char humanPiece();
char opponent(char piece);
void displayBoard(const vector<char>& board);
char winner(const vector<char>& board);
bool isLegal(const vector<char>& board, int move);
int humanMove(const vector<char>& board, char human);
int computerMove(vector<char> board, char computer);
void announceWinner(char winner, char computer, char human);

//主函数
int main() {
	int move;
	const int NUM_SQUARES = 9;
	vector<char> board(NUM_SQUARES, EMPTY);
	instruction();
	char human = humanPiece();
	char computer = opponent(human);
	char turn = X;
	displayBoard(board);
	while (winner(board) == NO_ONE) {
		if (turn == human) {
			move = humanMove(board, human);
			board[move] = human;
		}
		else {
			move = computerMove(board, computer);
			board[move] = computer;
		}
		displayBoard(board);
		turn = opponent(turn);
	}
	announceWinner(winner(board), computer, human);
	return 0;
}

//游戏操作介绍
void instruction() {
	cout << "\t欢迎来到Tic-Tac-Toe!\n";
	cout << "通过输入位置0-8来移动棋子，与计算机对战！\n";
	cout << "棋盘如下所示\n";
	cout << " 0 | 1 | 2 \n";
	cout << "-----------\n";
	cout << " 3 | 4 | 5 \n";
	cout << "-----------\n";
	cout << " 6 | 7 | 8 \n";
	cout << "游戏开始！\n";
}

//接受问题输入，返回y/n
char askYesNo(string question) {
	char response;
	do {
		cout << question << "(y/n):";
		cin >> response;
	} while (response != 'y'&&response != 'n');
	return response;
}

//接受问题和范围输入，返回输入数字
int askNumber(string question, int high, int low) {
	int number;
	do {
		cout << question << "(" << low << "-" << high << "):";
		cin >> number;
	} while (number > high || number < low);
	return number;
}

//询问玩家是否先手，若是返回先手棋X
char humanPiece() {
	char go_first = askYesNo("是否要先手？");
	if (go_first == 'y') {
		cout << "\n你选择了先手，走第一步。\n";
		return X;
	}
	else {
		cout << "\n你选择了后手，等计算机先走。\n";
		return O;
	}
}

//接受棋子，返回对手的棋子
char opponent(char piece) {
	if (piece == X) {
		return O;
	}
	else {
		return X;
	}
}

//显示棋盘
void displayBoard(const vector<char>& board) {
	cout << "\n\t" << board[0] << " | " << board[1] << " | " << board[2];
	cout << "\n\t" << "---------";
	cout << "\n\t" << board[3] << " | " << board[4] << " | " << board[5];
	cout << "\n\t" << "---------";
	cout << "\n\t" << board[6] << " | " << board[7] << " | " << board[8];
	cout << "\n\t" << "---------";
	cout << "\n\n";
}

//接受棋盘输入，返回胜利者（X\O），平局TIE，空余方格NO_ONE
char winner(const vector<char>& board) {
	//获胜方式
	const int WINNING_ROWS[8][3] = {
		{0,1,2},
		{3,4,5},
		{6,7,8},
		{0,3,6},
		{1,4,7},
		{2,5,8},
		{0,4,8},
		{2,4,6}
	};
	//玩家获胜
	const int TOTAL_ROWS = 8;
	for (int row = 0; row < TOTAL_ROWS; ++row) {
		if ((board[WINNING_ROWS[row][0]] != EMPTY) &&
			(board[WINNING_ROWS[row][0]] == board[WINNING_ROWS[row][1]]) &&
			(board[WINNING_ROWS[row][1]] == board[WINNING_ROWS[row][2]])) {
			return board[WINNING_ROWS[row][0]];
		}
	}
	//和棋
	if (count(board.begin(), board.end(), EMPTY) == 0) {
		return TIE;
	}
	//无胜者
	return NO_ONE;
}

//判断棋子是否合法
inline bool isLegal(const vector<char>& board, int move) {
	return (board[move] == EMPTY);
}

//接受当前棋子，返回人的下子
int humanMove(const vector<char>& board, char human) {
	int move = askNumber("下一步移到哪里？", (board.size() - 1));
	while (!isLegal(board, move)) {
		cout << "\n此处已有棋子！\n";
		move = askNumber("下一步移到哪里？", (board.size() - 1));
	}
	cout << "好的！\n";
	return move;
}

//计算机经过计算得到最好的一步（使用棋盘副本进行尝试）
int computerMove(vector<char> board, char computer) {
	//一招获胜
	unsigned int move = 0;
	bool found = false;
	while (!found&&move < board.size()) {
		if (isLegal(board, move)) {
			board[move] = computer;
			found = winner(board) == computer;
			board[move] = EMPTY;
		}
		if (!found) {
			++move;
		}
	}
	//让人不能获胜
	if (!found) {
		move = 0;
		char human = opponent(computer);
		while (!found&&move < board.size()) {
			if (isLegal(board, move)) {
				board[move] = human;
				found = winner(board) == human;
				board[move] = EMPTY;
			}
			if (!found) {
				++move;
			}
		}
	}
	//选择最优方格（中心->角落->其余）
	if (!found) {
		move = 0;
		unsigned int i = 0;
		const int BEST_MOVES[] = { 4,0,2,6,8,1,3,5,7 };
		while (!found&&i < board.size()) {
			move = BEST_MOVES[i];
			if (isLegal(board, move)) {
				found = true;
			}
			++i;
		}
	}
	cout << "计算机选择了位置" << move << endl;
	return move;
}

//接受游戏胜者，并宣布
void announceWinner(char winner, char computer, char human) {
	if (winner == computer) {
		cout << "\n计算机获胜，再接再厉！";
	}
	else if (winner == human) {
		cout << "\n恭喜你战胜了计算机！";
	}
	else {
		cout << "\n平局！";
	}
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
