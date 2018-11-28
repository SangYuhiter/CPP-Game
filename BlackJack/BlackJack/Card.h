#pragma once
#include <iostream>
#include <string>
using namespace std;
//Card类:一张纸牌
class Card {
public:
	//牌面大小
	enum rank {
		ACE = 1, TWO, THREE, FOUR, FIVE, SIX,
		SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING
	};
	//牌面花色
	enum suit { CLUBS, DIAMONDS, HEARTS, SPADES };
	//重载输出函数
	friend ostream& operator<<(ostream& os, const Card& aCard);
	Card(rank r = ACE, suit s = SPADES, bool ifu = true);
	int GetValue() const;
	void Flip();
private:
	rank m_Rank;	//纸牌大小
	suit m_Suit;	//纸牌花色
	bool m_IsFaceUp;	//纸牌朝向
};

//构造函数
Card::Card(rank r, suit s, bool ifu) :
	m_Rank(r), m_Suit(s), m_IsFaceUp(ifu)
{}

//获取纸牌大小
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

//翻牌，正反变换
void Card::Flip() {
	m_IsFaceUp = !(m_IsFaceUp);
}

//重载输出函数，输出纸牌的花色大小
ostream& operator<<(ostream& os, const Card& aCard) {
	const string RANKS[] = { "0","A","2","3","4","5","6",
		"7","8","9","10","J","Q","K" };
	const string SUITS[] = { "梅花","方块","红桃","黑桃" };
	if (aCard.m_IsFaceUp) {
		os << SUITS[aCard.m_Suit] << RANKS[aCard.m_Rank];
	}
	else {
		os << "XX";
	}
	return os;
}