#pragma once
//�ƶ���
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

//���캯��
Deck::Deck() {
	m_Cards.reserve(52);
	Populate();
}

//��������
Deck::~Deck()
{}

//����һ����
void Deck::Populate() {
	Clear();
	for (int s = Card::CLUBS; s < Card::SPADES; ++s) {
		for (int r = Card::ACE; r < Card::KING; ++r) {
			Add(new Card(static_cast<Card::rank>(r), static_cast<Card::suit>(s)));
		}
	}
}

//ϴ��
void Deck::Shuffle() {
	random_shuffle(m_Cards.begin(), m_Cards.end());
}

//����ҷ�һ����
void Deck::Deal(Hand& aHand) {
	if (!m_Cards.empty()) {
		aHand.Add(m_Cards.back());
		m_Cards.pop_back();
	}
	else {
		cout << "�ƶ��ѿգ�\n";
	}
}

//����ҷ��������
void Deck::AdditionalCards(GenericPlayer& aGenericPlayer) {
	cout << endl;
	//���δ����21����ѡ�����
	while (!(aGenericPlayer.IsBusted()) && aGenericPlayer.IsHitting()) {
		Deal(aGenericPlayer);
		cout << aGenericPlayer << endl;
		if (aGenericPlayer.IsBusted()) {
			aGenericPlayer.Bust();
		}
	}
}