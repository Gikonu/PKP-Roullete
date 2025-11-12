#pragma once
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <fstream>

enum eBet
{
	None,  //0
	Number,//35:1
	Split, //17:1
	Street,//11:1
	Corner,//8:1
	Line,  //5:1
	Colour,//2:1
	Parity,//1:1
	Height,//1:1
	Dozen, //1:1
	Column //1:1
};

struct sBet
{
	eBet bet = None;
	int number[6]{0};
	int money = 0;
	sBet()
	{
		
	}
	sBet(eBet bet, int numbers[], int money)
	{
		this->bet = bet;
		this->money = money;
		for (int i = 0; i < 6; i++)
		{
			number[i] = numbers[i];
		}
	}
};

struct sVector
{
	int x;
	int y;
	sVector()
	{
		x = 0;
		y = 0;
	}
	sVector(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	sVector(const sVector& v)
	{
		x = v.x;
		y = v.y;
	}
	sVector& operator=(const sVector& v)
	{
		x = v.x;
		y = v.y;
		return *this;
	}
};

class Roulette
{
	int playerAmount = 1;
	int* playersMoney;
	int playerTurn = 1;
	int startMoney = 1000;
	sBet* playerBet;
	int randNumber = 0;
	std::string playersName[5];
	int bestMoney[5] = { 0,0,0,0,0 };
	const std::string fillName = "BP.txt";

	const int red[18] = {1,3,5,7,9,12,14,16,18,21,23,25,27,28,30,32,34,36};
	const int numbers[3][12] =
	{
		{3,6,9,12,15,18,21,24,27,30,33,36},
		{2,5,8,11,14,17,20,23,26,29,32,35},
		{1,4,7,10,13,16,19,22,25,28,31,34}
	};
	
public:
	Roulette();
	~Roulette();

	bool SetPlayerAmount(int amount);
	bool SetStartMoney(int amount);
	bool SetPlayerBet(sBet bet);

	void SetPlayerName(int playerID, std::string name)
	{
		playersName[playerID - 1] = name;
	}

	int Random();
	sVector SetPlayerBet(int money, sVector mousePosition, sVector boardPosition = sVector(0,0), sVector boardSize = sVector(960,480));
	void NullBit()
	{
		for (int i = 0; i < playerAmount; i++)
		{
			playerBet[i].bet = eBet::None;
		}
	}

	int GetPlayerAmount()
	{
		return playerAmount;
	}

	int GetPlayerMoney(int player)
	{
		return playersMoney[player-1];
	}

	int GetPlayerTurn()
	{
		return playerTurn;
	}

	std::string GetPlayerName(int playerID)
	{
		return playersName[playerID - 1];
	}

	bool NextTurn();
	bool StartTurn();
	int IsNextTurn();
	
	void UpdateBest();
	void SaveBest();
	void GetBest(int money[], std::string name[]);
};

