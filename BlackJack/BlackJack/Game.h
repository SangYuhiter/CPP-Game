#pragma once
#include "Deck.h"
#include "House.h"
#include "Player.h"
#include <time.h>
class Game {
public:
	Game(const vector<string>& names);
	~Game();
	void Play();
private:
	Deck m_Deck;
	House m_House;
	vector<Player> m_Players;
};

//���캯��
Game::Game(const vector<string>& names) {
	//������
	vector<string>::const_iterator pName;
	for (pName = names.begin(); pName != names.end(); ++pName) {
		m_Players.push_back(Player(*pName));
	}
	//����ƣ���ϴ��
	srand(static_cast<unsigned int>(time(0)));
	m_Deck.Populate();
	m_Deck.Shuffle();
}

//��������
Game::~Game()
{}

//��Ϸ����
void Game::Play() {
	//Ϊÿ�˷�������
	vector<Player>::iterator pPlayer;
	for (int i = 0; i < 2; ++i) {
		for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer) {
			m_Deck.Deal(*pPlayer);
		}
		m_Deck.Deal(m_House);
	}
	//����ׯ�ҵĵ�һ����
	m_House.FlipFirstCard();
	//��ʾÿ����ҵ���
	for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer) {
		cout << *pPlayer << endl;
	}
	cout << m_House << endl;
	//��ʼΪ��Ҹ���
	for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer) {
		m_Deck.AdditionalCards(*pPlayer);
	}
	//��ʾׯ�����ص���
	m_House.FlipFirstCard();
	cout << endl << m_House;
	//Ϊׯ�Ҹ���
	m_Deck.AdditionalCards(m_House);
	//ׯ�ҳ���21��
	if (m_House.IsBusted()) {
		//�ڵ�ǰ�����Ѱ��ʤ��
		for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer) {
			if (!(pPlayer->IsBusted())) {
				pPlayer->Win();
			}
		}
	}
	//ׯ��δ����21��
	else {
		//�ڵ�ǰ����г���ׯ����δ����21���ʤ��
		for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer) {
			if (!(pPlayer->IsBusted())) {
				if (pPlayer->GetTotal() > m_House.GetTotal()) {
					pPlayer->Win();
				}
				else if (pPlayer->GetTotal() < m_House.GetTotal()) {
					pPlayer->Lose();
				}
				else {
					pPlayer->Push();
				}
			}
		}
	}
	//������������е���
	for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer) {
		pPlayer->Clear();
	}
	m_House.Clear();
}