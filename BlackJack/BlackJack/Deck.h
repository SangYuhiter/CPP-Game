#pragma once
//牌堆类
#include "Hand.h"
#include "GenericPlayer.h"
#include <algorithm>
using namespace std;
class Deck :public Hand {
public:
	Deck();
	virtual ~Deck();
	void Populate();
	void Shuffle();
	void Deal(Hand& aHand);
	void AdditionalCards(GenericPlayer& aGenericPlayer);
};

//构造函数
Deck::Deck() {
	m_Cards.reserve(52);
	Populate();
}

//析构函数
Deck::~Deck()
{}

//生成一副牌
void Deck::Populate() {
	Clear();
	for (int s = Card::CLUBS; s < Card::SPADES; ++s) {
		for (int r = Card::ACE; r < Card::KING; ++r) {
			Add(new Card(static_cast<Card::rank>(r), static_cast<Card::suit>(s)));
		}
	}
}

//洗牌
void Deck::Shuffle() {
	random_shuffle(m_Cards.begin(), m_Cards.end());
}

//向玩家发一张牌
void Deck::Deal(Hand& aHand) {
	if (!m_Cards.empty()) {
		aHand.Add(m_Cards.back());
		m_Cards.pop_back();
	}
	else {
		cout << "牌堆已空！\n";
	}
}

//向玩家发额外的牌
void Deck::AdditionalCards(GenericPlayer& aGenericPlayer) {
	cout << endl;
	//玩家未超出21点且选择跟牌
	while (!(aGenericPlayer.IsBusted()) && aGenericPlayer.IsHitting()) {
		Deal(aGenericPlayer);
		cout << aGenericPlayer << endl;
		if (aGenericPlayer.IsBusted()) {
			aGenericPlayer.Bust();
		}
	}
}