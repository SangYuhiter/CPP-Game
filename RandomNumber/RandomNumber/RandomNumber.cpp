// RandomNumber.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using std::cin;
using std::cout;
using std::endl;

//掷骰子游戏
void rollGame();

//猜数游戏
void guessNumberGame();
int main()
{
	//掷骰子游戏
	//rollGame();

	//猜数游戏
	guessNumberGame();
	return 0;
}

//掷骰子游戏
void rollGame() {
	cout << "\t掷骰子游戏" << endl;
	char choice;
	do {
		srand(static_cast<unsigned int>(time(0)));
		int number = (rand() % 6) + 1;
		cout << "骰子点数: " << number << endl;
		cout << "再来一次(y/n):";
		cin >> choice;
	} while (choice == 'y');
}

//猜数游戏
void guessNumberGame() {
	cout << "\t猜数游戏" << endl;
	char choice;
	do {
		srand(static_cast<unsigned int>(time(0)));
		cout << "输入猜数范围(1-n):";
		int selectNumberSize=0;
		cin >> selectNumberSize;
		int selectNumber = rand() % selectNumberSize + 1;

		int tries = 0;	//猜测次数
		int guessNumber = 0;	//猜测数字

		cout << "开始游戏" << endl;

		do {
			cout << "输入猜测：";
			cin >> guessNumber;
			++tries;
			if (guessNumber > selectNumber) {
				cout << "太大！" << endl;
			}
			else if (guessNumber < selectNumber) {
				cout << "太小！" << endl;
			}
			else {
				cout << "恭喜你，猜对了！" << endl;
				cout << "在猜测了" << tries << "次后猜对了！" << endl;
			}
		} while (guessNumber!=selectNumber);
		cout << "再来一次(y/n):";
		cin >> choice;
	} while (choice=='y');
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
