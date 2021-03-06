// MadLib.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//用户输入一些信息，输出一个个性化故事
#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

string askText(string prompt);
int askNumber(string prompt);
void tellStory(string name, string noun, int number, string bodypart, string verb);
int main()
{
	cout << "\tWelcome to Mad Lib!\n";
	cout << "回答下列问题\n";
	string name = askText("输入一个名字:");
	string noun = askText("输入一个复数名词:");
	int number = askNumber("输入一个数字:");
	string bodypart = askText("输入一个身体部分:");
	string verb = askText("输入一个动词:");
	tellStory(name, noun, number, bodypart, verb);
	return 0;
}

string askText(string prompt) {
	string text;
	cout << prompt;
	cin >> text;
	return text;
}

int askNumber(string prompt) {
	int num;
	cout << prompt;
	cin >> num;
	return num;
}

void tellStory(string name, string noun, int number, string bodypart, string verb) {
	cout << "\n这是你的故事：\n";
	cout << "著名探险家" << name << "一生都在寻找" << noun << "迷失之城。\n"
		<< "有一天，" << noun << "发现了探险家，" << number << "个" << noun << "包围了"
		<< name << "\n探险家的" << bodypart << "受到伤害，之后" << name << "逃走了"
		<< "此后，每次" << name+" " << verb << "时都会感到害怕！";
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
