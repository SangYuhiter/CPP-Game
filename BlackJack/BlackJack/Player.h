#pragma once
//人类玩家类
#include "GenericPlayer.h"
class Player :public GenericPlayer {
public:
	Player(const string& name = "");
	virtual ~Player();
	virtual bool IsHitting() const;
	void Win() const;
	void Lose() const;
	void Push() const;
};

//构造函数
Player::Player(const string& name) :
	GenericPlayer(name)
{}

//析构函数
Player::~Player()
{}

//询问玩家是否跟牌
bool Player::IsHitting() const {
	cout << m_Name << ",是否跟牌(y/n):";
	char response;
	cin >> response;
	return (response == 'y' || response == 'Y');
}

//输出玩家胜利
void Player::Win() const {
	cout << m_Name << "获胜!\n";
}

//输出玩家失败
void Player::Lose() const {
	cout << m_Name << "失败!\n";
}

//输出玩家平手
void Player::Push() const {
	cout << m_Name << "平手!\n";
}