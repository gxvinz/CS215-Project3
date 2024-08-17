#pragma once
//---------------------------------------------------------
//                     class team
//---------------------------------------------------------
// Describes a partial array of player objects.
//---------------------------------------------------------
#include <iostream>
#include "player.h"
using namespace std;

const int maxPlayer = 10;

class team {
public:
	team();
	void setNumPlayers(int num);
	void setNumGames(int num);
	int getNumPlayers();
	int getNumGames();
	void print();
	void addGame();
	void displayPlayer();
	void sortByName();
	void sortByJersey();
	void removePlayer();
	void write();
	void read();
private:
	player p[maxPlayer];
	int numPlayer;
	int numGames;
};
