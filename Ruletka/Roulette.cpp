#include "Roulette.h"


Roulette::Roulette()
{
	srand(time(NULL));
	playersMoney = new int[playerAmount] {startMoney};
	playerBet = new sBet[playerAmount];
}

Roulette::~Roulette()
{
	delete[] playersMoney;
	delete[] playerBet;
}

bool Roulette::SetPlayerAmount(int amount)
{
	if (amount < 1 || amount > 5)
	{
		return false;
	}
	playerAmount = amount;

	delete[] playersMoney;
	playersMoney = new int[playerAmount];
	for (int i = 0; i < playerAmount; i++)
	{
		playersMoney[i] = startMoney;
	}
	delete[] playerBet;
	playerBet = new sBet[playerAmount];
	
	return true;
}

bool Roulette::SetStartMoney(int amount)
{
	if (amount < 1)
	{
		return false;
	}

	startMoney = amount;
	return true;
}

bool Roulette::SetPlayerBet(sBet bet)
{
	if (bet.money <= 0 && playersMoney[playerTurn - 1] < bet.money)
	{
		return false;
	}
	playerBet[playerTurn - 1] = bet;

	return true;
}

int Roulette::Random()
{
	randNumber = rand() % 37;

	for (int i = 0; i < playerAmount; i++)
	{
		if (playersMoney[i] <= 0)
		{
			continue;
		}

		switch (playerBet[i].bet)
		{
		case Number:
			if (playerBet[i].number[0] == randNumber)
			{
				playersMoney[i] = playersMoney[i] + playerBet[i].money * 35;
			}
			else
			{
				playersMoney[i] -= playerBet[i].money;
			}
			break;
		case Split:
			if (playerBet[i].number[0] == randNumber || playerBet[i].number[1] == randNumber)
			{
				playersMoney[i] = playersMoney[i] + playerBet[i].money * 17;
			}
			else
			{
				playersMoney[i] -= playerBet[i].money;
			}
			break;
		case Street:
			if (playerBet[i].number[0] == randNumber || playerBet[i].number[1] == randNumber || playerBet[i].number[2] == randNumber)
			{
				playersMoney[i] = playersMoney[i] + playerBet[i].money * 11;
			}
			else
			{
				playersMoney[i] -= playerBet[i].money;
			}
			break;
		case Corner:
			if (playerBet[i].number[0] == randNumber || playerBet[i].number[1] == randNumber || playerBet[i].number[2] == randNumber || playerBet[i].number[3] == randNumber)
			{
				playersMoney[i] = playersMoney[i] + playerBet[i].money * 8;
			}
			else
			{
				playersMoney[i] -= playerBet[i].money;
			}
			break;
		case Line:
			if (playerBet[i].number[0] == randNumber || playerBet[i].number[1] == randNumber || playerBet[i].number[2] == randNumber || playerBet[i].number[3] == randNumber || playerBet[i].number[4] == randNumber || playerBet[i].number[5] == randNumber)
			{
				playersMoney[i] = playersMoney[i] + playerBet[i].money * 5;
			}
			else
			{
				playersMoney[i] -= playerBet[i].money;
			}
			break;
		case Colour:
			if (randNumber != 0)
			{
				bool isRed = false;
				for (int j = 0; j < 18; j++)
				{
					if (red[j] == randNumber)
					{
						isRed = true;
						break;
					}
				}
				if (playerBet[i].number[0] == 1 && isRed)
				{
					playersMoney[i] = playersMoney[i] + playerBet[i].money * 2;
				}
				else if (playerBet[i].number[0] == 2 && !isRed)
				{
					playersMoney[i] = playersMoney[i] + playerBet[i].money * 2;
				}
			}
			playersMoney[i] -= playerBet[i].money;
			break;
		case Parity:
			if (randNumber != 0)
			{
				if (randNumber % 2 == playerBet[i].number[0] - 1)
				{
					playersMoney[i] = playersMoney[i] + playerBet[i].money * 2;
				}
			}
			playersMoney[i] -= playerBet[i].money;
			break;
		case Height:
			if (randNumber != 0)
			{
				if (playerBet[i].number[0] == 1)
				{
					if (randNumber <= 18)
					{
						playersMoney[i] = playersMoney[i] + playerBet[i].money * 2;
					}
				}
				else
				{
					if (randNumber <= 36 && randNumber > 18)
					{
						playersMoney[i] = playersMoney[i] + playerBet[i].money * 2;
					}
				}
			}
			playersMoney[i] -= playerBet[i].money;
			break;
		case Dozen:
			if (randNumber != 0)
			{
				if (playerBet[i].number[0] == 1)
				{
					if (randNumber <= 12)
					{
						playersMoney[i] = playersMoney[i] + playerBet[i].money * 2;
					}
				}
				else if (playerBet[i].number[0] == 2)
				{
					if (randNumber <= 24 && randNumber > 12)
					{
						playersMoney[i] = playersMoney[i] + playerBet[i].money * 2;
					}
				}
				else
				{
					if (randNumber <= 36 && randNumber > 24)
					{
						playersMoney[i] = playersMoney[i] + playerBet[i].money * 2;
					}
				}
			}
			playersMoney[i] -= playerBet[i].money;
			break;
		case Column:
			int j;
			if (randNumber != 0)
			{
				for (j = playerBet[i].number[0]; j <= 36; j += 3)
				{
					if (randNumber == j)
					{
						playersMoney[i] = playersMoney[i] + playerBet[i].money * 3;
						break;
					}
				}
			}
			playersMoney[i] -= playerBet[i].money;
			break;
		default:
			break;
		}
	}
	return randNumber;
}

sVector Roulette::SetPlayerBet(int money, sVector mousePosition, sVector boardPosition, sVector boardSize)
{
	mousePosition = sVector(mousePosition.x - boardPosition.x, mousePosition.y - boardPosition.y);
	if (!(mousePosition.x < 61 || mousePosition.x > 915 || mousePosition.y < 67 || mousePosition.y > 390))
	{
		if (mousePosition.y > 298)
		{
			if (mousePosition.x < 109 || mousePosition.x > 853)
			{
				return sVector(0, 0);
			}
			else if (mousePosition.y > 344)
			{
				int t = (mousePosition.x - 109) / 124;
				int tab[6]{ 0 };
				switch (t)
				{
				case 0:
					tab[0] = 1;
					if (SetPlayerBet(sBet(eBet::Height, tab, money)))
					{
						return sVector(109 + t * 124 + 62, 367);
					}
					else
					{
						return sVector(-1, 0);
					}
					break;
				case 1:
					tab[0] = 1;
					if (SetPlayerBet(sBet(eBet::Parity, tab, money)))
					{
						return sVector(109 + t * 124 + 62, 367);
					}
					else
					{
						return sVector(-1, 0);
					}
					break;
				case 2:
					tab[0] = 1;
					if (SetPlayerBet(sBet(eBet::Colour, tab, money)))
					{
						return sVector(109 + t * 124 + 62, 367);
					}
					else
					{
						return sVector(-1, 0);
					}
					break;
				case 3:
					tab[0] = 2;
					if (SetPlayerBet(sBet(eBet::Colour, tab, money)))
					{
						return sVector(109 + t * 124 + 62, 367);
					}
					else
					{
						return sVector(-1, 0);
					}
					break;
				case 4:
					tab[0] = 2;
					if (SetPlayerBet(sBet(eBet::Parity, tab, money)))
					{
						return sVector(109 + t * 124 + 62, 367);
					}
					else
					{
						return sVector(-1, 0);
					}
					break;
				case 5:
					tab[0] = 2;
					if (SetPlayerBet(sBet(eBet::Height, tab, money)))
					{
						return sVector(109 + t * 124 + 62, 367);
					}
					else
					{
						return sVector(-1, 0);
					}
					break;
				default:
					break;
				}
			}
			else
			{
				int tab[6] = { (mousePosition.x - 109) / 248 + 1,0,0,0,0,0 };
				if(SetPlayerBet(sBet(eBet::Dozen,tab,money)))
				{
					return sVector((109 + ((mousePosition.x - 109) / 248) * 248 + 124), 321);
				}
				else
				{
					return sVector(-1, 0);
				}
			}
		}
		else
		{
			if (mousePosition.x > 853)
			{
				int tab[6] = { -((mousePosition.y - 67) / 77) + 3,0,0,0,0,0 };
				if (SetPlayerBet(sBet(eBet::Column, tab, money)))
				{
					return sVector(884, (67 + ((mousePosition.y - 67) / 77) * 77 + 38));
				}
				else
				{
					return sVector(-1, 0);
				}
			}
			else
			{
				int tab[6] = { 0,0,0,0,0,0 };
				if (mousePosition.x < 109)
				{
					if (SetPlayerBet(sBet(eBet::Number, tab, money)))
					{
						return sVector(89, 182);
					}
					else
					{
						return sVector(-1, 0);
					}
				}
				else
				{
					if (mousePosition.x <= 124)
					{
						if (mousePosition.y - 67 <= 19)
						{
							tab[0] = 1; tab[1] = 2; tab[2] = 3;
							if (SetPlayerBet(sBet(eBet::Corner, tab, money)))
							{
								return sVector(109, 67);
							}
							else
							{
								return sVector(-1, 0);
							}
						}
						int t = (mousePosition.y - 92) / 38.5;
						if (t >= 5)
						{
							tab[0] = 1;
							if (SetPlayerBet(sBet(eBet::Number, tab, money)))
							{
								return sVector(89, 182);
							}
							else
							{
								return sVector(-1, 0);
							}
						}
						if (t % 2 == 0)
						{
							tab[0] = numbers[t/2][0];
							if (SetPlayerBet(sBet(eBet::Split, tab, money)))
							{
								return sVector(109, 67 + t * 38.5 + 38.5);
							}
							else
							{
								return sVector(-1, 0);
							}
						}
						else
						{
							tab[0] = numbers[t / 2][0]; tab[1] = numbers[t / 2 + 1][0];
							if (SetPlayerBet(sBet(eBet::Street, tab, money)))
							{
								return sVector(109, 67 + t * 38.5 + 38.5);
							}
							else
							{
								return sVector(-1, 0);
							}
						}
					}
					else
					{
						int c, w;
						w = (mousePosition.y - 47.75) / 38.5;
						c = (mousePosition.x - 124.5) / 31;
						if (w >= 6)
						{
							return sVector(0, 0);
						}
						if (c >= 23)
						{
							return sVector(0, 0);
						}
						if (w == 0)
						{
							if (c % 2 == 0)
							{
								tab[0] = numbers[0][c/2]; tab[1] = numbers[1][c/2]; tab[2] = numbers[2][c/2];
								if (SetPlayerBet(sBet(eBet::Street, tab, money)))
								{
									return sVector(140 + c * 31, 67);
								}
								else
								{
									return sVector(-1, 0);
								}
							}
							else
							{
								tab[0] = numbers[0][c / 2];     tab[1] = numbers[1][c / 2];     tab[2] = numbers[2][c / 2];
								tab[3] = numbers[0][c / 2 + 1]; tab[4] = numbers[1][c / 2 + 1]; tab[5] = numbers[2][c / 2 + 1];
								if (SetPlayerBet(sBet(eBet::Line, tab, money)))
								{
									return sVector(140 + c * 31, 67);
								}
								else
								{
									return sVector(-1, 0);
								}
							}
						}
						else
						{
							if (w % 2 == 0)
							{
								if (c % 2 == 0)
								{
									tab[0] = numbers[w / 2 - 1][c / 2]; tab[1] = numbers[w / 2][c / 2];
									if (SetPlayerBet(sBet(eBet::Split, tab, money)))
									{
										return sVector(140 + c * 31, 67 + w * 38.5);
									}
									else
									{
										return sVector(-1, 0);
									}
								}
								else
								{
									tab[0] = numbers[w / 2 - 1][c / 2]; tab[1] = numbers[w / 2 - 1][c / 2 + 1];
									tab[2] = numbers[w / 2][c / 2];     tab[3] = numbers[w / 2][c / 2 + 1];
									if (SetPlayerBet(sBet(eBet::Corner, tab, money)))
									{
										return sVector(140 + c * 31, 67 + w * 38.5);
									}
									else
									{
										return sVector(-1, 0);
									}
								}
							}
							else
							{
								if (c % 2 == 0)
								{
									tab[0] = numbers[w / 2][c / 2];
									if (SetPlayerBet(sBet(eBet::Number, tab, money)))
									{
										return sVector(140 + c * 31, 67 + w * 38.5);
									}
									else
									{
										return sVector(-1, 0);
									}
								}
								else
								{
									tab[0] = numbers[w / 2][c / 2]; tab[1] = numbers[w / 2][c / 2 + 1];
									if (SetPlayerBet(sBet(eBet::Split, tab, money)))
									{
										return sVector(140 + c * 31, 67 + w * 38.5);
									}
									else
									{
										return sVector(-1, 0);
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return sVector(0,0);
	
}

bool Roulette::NextTurn()
{
	int i = IsNextTurn();
	if (i > 0)
	{
		playerTurn = i;
	}
	else
	{
		return false;
	}
}

bool Roulette::StartTurn()
{
	playerTurn = playerAmount;
	int i = IsNextTurn();
	if (i > 0)
	{
		playerTurn = i;
	}
	else
	{
		return false;
	}
}

int Roulette::IsNextTurn()
{
	for (int i = playerTurn + 1; i <= playerAmount + 1; i++)
	{
		if (i > playerAmount)
		{
			i = 1;
		}
		if (playersMoney[i - 1] > 0)
		{
			//playerTurn = i;
			return i;
		}

		if (i == playerTurn)
		{
			return 0;
		}
	}
}
