#pragma once
//���������
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

//���캯��
Player::Player(const string& name) :
	GenericPlayer(name)
{}

//��������
Player::~Player()
{}

//ѯ������Ƿ����
bool Player::IsHitting() const {
	cout << m_Name << ",�Ƿ����(y/n):";
	char response;
	cin >> response;
	return (response == 'y' || response == 'Y');
}

//������ʤ��
void Player::Win() const {
	cout << m_Name << "��ʤ!\n";
}

//������ʧ��
void Player::Lose() const {
	cout << m_Name << "ʧ��!\n";
}

//������ƽ��
void Player::Push() const {
	cout << m_Name << "ƽ��!\n";
}