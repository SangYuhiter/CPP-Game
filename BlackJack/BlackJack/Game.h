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

//构造函数
Game::Game(const vector<string>& names) {
	//添加玩家
	vector<string>::const_iterator pName;
	for (pName = names.begin(); pName != names.end(); ++pName) {
		m_Players.push_back(Player(*pName));
	}
	//添加牌，并洗牌
	srand(static_cast<unsigned int>(time(0)));
	m_Deck.Populate();
	m_Deck.Shuffle();
}

//析构函数
Game::~Game()
{}

//游戏流程
void Game::Play() {
	//为每人发两张牌
	vector<Player>::iterator pPlayer;
	for (int i = 0; i < 2; ++i) {
		for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer) {
			m_Deck.Deal(*pPlayer);
		}
		m_Deck.Deal(m_House);
	}
	//隐藏庄家的第一张牌
	m_House.FlipFirstCard();
	//显示每个玩家的牌
	for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer) {
		cout << *pPlayer << endl;
	}
	cout << m_House << endl;
	//开始为玩家跟牌
	for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer) {
		m_Deck.AdditionalCards(*pPlayer);
	}
	//显示庄家隐藏的牌
	m_House.FlipFirstCard();
	cout << endl << m_House;
	//为庄家跟牌
	m_Deck.AdditionalCards(m_House);
	//庄家超过21点
	if (m_House.IsBusted()) {
		//在当前玩家中寻找胜者
		for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer) {
			if (!(pPlayer->IsBusted())) {
				pPlayer->Win();
			}
		}
	}
	//庄家未超过21点
	else {
		//在当前玩家中超过庄家且未超过21点的胜利
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
	//清除所有人手中的牌
	for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer) {
		pPlayer->Clear();
	}
	m_House.Clear();
}