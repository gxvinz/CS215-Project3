#pragma once
//---------------------------------------------------------
//                   class player
//---------------------------------------------------------
// Describes the items within a player object.
//---------------------------------------------------------
#include <iostream>
using namespace std;
const int maxGames = 15;
class player {
public:
	//constructor
	player();

	//get Methods
	string getName();
	int getJerseyNum();
	int getNumGames();
	int getThreeMade(int game);
	int getThreeAtt(int game);
	int getTwoMade(int game);
	int getTwoAtt(int game);
	int getFtMade(int game);
	int getFtAtt(int game);
	int getTotThreeMade();
	int getTotThreeAtt();
	int getTotTwoMade();
	int getTotTwoAtt();
	int getTotFtMade();
	int getTotFtAtt();
	int getTotPoints();
	int getTotPointsGame(int game);

	//set Methods
	void setName(string name1);
	void setJerseyNum(int num);
	void setThree(int made, int att, int game);
	void setTwo(int made, int att, int game);
	void setFt(int made, int att, int game);
	void setNumGames(int num);
private:
	string name;
	int jerseyNum;
	int numGames;
	// make a these into arrays to hold all game stats
	struct gameStats {
		int threeMade;
		int threeAtt;
		int twoMade;
		int twoAtt;
		int ftMade;
		int ftAtt;
	};
	gameStats g[maxGames];
};
