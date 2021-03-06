// WordJumble.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

//猜字谜游戏：给定打乱后的词，猜测原词，有提示和退出
#include "pch.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	//设定游戏资料
	enum fields{WORD,HINT,NUM_FIELDS};
	const int NUM_WORLDS = 5;
	const string WORDS[NUM_WORLDS][NUM_FIELDS]=
	{
		{"wall","头会撞到什么上面？"},
		{"glasses","帮助你看清远处的东西"},
		{"apple","红彤彤的很好吃"},
		{"banana","小黄人最喜欢的东西"},
		{"water","每个人必不可少的东西"}
	};

	//开始游戏
	cout << "\t\t猜词游戏" << endl;
	cout << "给出乱序字母，还原原词" << endl;
	cout << "输入hint获得提示" << endl;
	cout << "输入quit退出游戏" << endl;
	char rsp;	//用户是否继续游戏
	do {
		//随机选取词
		srand(static_cast<unsigned int>(time(0)));
		int choice = rand() % NUM_WORLDS;
		string theWord = WORDS[choice][WORD];
		string theHint = WORDS[choice][HINT];

		//单词乱序
		string jumble = theWord;
		int length = jumble.size();
		for (int i = 0; i < length; ++i) {
			int index1 = rand() % length;
			int index2 = rand() % length;
			char temp = jumble[index1];
			jumble[index1] = jumble[index2];
			jumble[index2] = temp;
		}

		//接受用户输入并进行判断
		cout << "乱序字母为：" << jumble << endl;
		string guess;
		do {
			cout << "你的猜测：";
			cin >> guess;
			if (guess == "hint")
				cout << theHint << endl;
			else if (guess != theWord&&guess!="quit")
				cout << "猜错了！" << endl;
		} while (guess!=theWord&&guess!="quit");
		if (guess == theWord)
			cout << "恭喜你，猜对了！" << endl;
		if (guess == "quit")
			break;
		cout << "再来一次(y/n):";
		cin >> rsp;
	} while (rsp=='y');
	cout << "谢谢你的参与！" << endl;
	return 0;
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
