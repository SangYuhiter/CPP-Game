#pragma once
#include <iostream>
#include <string>
using namespace std;
//Card��:һ��ֽ��
class Card {
public:
	//�����С
	enum rank {
		ACE = 1, TWO, THREE, FOUR, FIVE, SIX,
		SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING
	};
	//���滨ɫ
	enum suit { CLUBS, DIAMONDS, HEARTS, SPADES };
	//�����������
	friend ostream& operator<<(ostream& os, const Card& aCard);
	Card(rank r = ACE, suit s = SPADES, bool ifu = true);
	int GetValue() const;
	void Flip();
private:
	rank m_Rank;	//ֽ�ƴ�С
	suit m_Suit;	//ֽ�ƻ�ɫ
	bool m_IsFaceUp;	//ֽ�Ƴ���
};

//���캯��
Card::Card(rank r, suit s, bool ifu) :
	m_Rank(r), m_Suit(s), m_IsFaceUp(ifu)
{}

//��ȡֽ�ƴ�С
int Card::GetValue() const {
	int value = 0;
	if (m_IsFaceUp) {
		value = m_Rank;
		if (value > 10) {
			value = 10;
		}
	}
	return value;
}

//���ƣ������任
void Card::Flip() {
	m_IsFaceUp = !(m_IsFaceUp);
}

//����������������ֽ�ƵĻ�ɫ��С
ostream& operator<<(ostream& os, const Card& aCard) {
	const string RANKS[] = { "0","A","2","3","4","5","6",
		"7","8","9","10","J","Q","K" };
	const string SUITS[] = { "÷��","����","����","����" };
	if (aCard.m_IsFaceUp) {
		os << SUITS[aCard.m_Suit] << RANKS[aCard.m_Rank];
	}
	else {
		os << "XX";
	}
	return os;
}