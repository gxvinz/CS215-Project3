#include <iostream>
#include <iomanip>
#include <string>
#include "player.h"
using namespace std;

//---------------------------------------------------------
//                    Constructor
//---------------------------------------------------------
player::player() {
	name = "";
	jerseyNum = 0;
	numGames = 0;
}

//---------------------------------------------------------
//                    Get Methods
//---------------------------------------------------------
string player::getName() {
	return name;
}
int player::getJerseyNum() {
	return jerseyNum;
}
int player::getNumGames() {
	return numGames;
}
int player::getThreeMade(int game) {
	return g[game].threeMade;
}
int player::getThreeAtt(int game) {
	return g[game].threeAtt;
}
int player::getTwoMade(int game) {
	return g[game].twoMade;
}
int player::getTwoAtt(int game) {
	return g[game].twoAtt;
}
int player::getFtMade(int game) {
	return g[game].ftMade;
}
int player::getFtAtt(int game) {
	return g[game].ftAtt;
}

// Totals

// added to a total count game by game 
int player::getTotThreeMade() {
	int total = 0;
	for (int i = 0; i < numGames; i++) {
		total = total + g[i].threeMade;
	}
	return total;
}
int player::getTotThreeAtt() {
	int total = 0;
	for (int i = 0; i < numGames; i++) {
		total = total + g[i].threeAtt;
	}
	return total;
}
int player::getTotTwoMade() {
	int total = 0;
	for (int i = 0; i < numGames; i++) {
		total = total + g[i].twoMade;
	}
	return total;
}
int player::getTotTwoAtt() {
	int total = 0;
	for (int i = 0; i < numGames; i++) {
		total = total + g[i].twoAtt;
	}
	return total;
}
int player::getTotFtMade() {
	int total = 0;
	for (int i = 0; i < numGames; i++) {
		total = total + g[i].ftMade;
	}
	return total;
}
int player::getTotFtAtt() {
	int total = 0;
	for (int i = 0; i < numGames; i++) {
		total = total + g[i].ftAtt;
	}
	return total;
}

// getting total points by finding totals and then mulitplying goals by their point values
int player::getTotPoints() {
	int total3 = getTotThreeMade();
	int total2 = getTotTwoMade();
	int total1 = getTotFtMade();
	int total = (total3 * 3) + (total2 * 2) + total1;
	return total;
}

// using number of shots made in a game and their point value to find total points scored in a game
int player::getTotPointsGame(int game) {
	int total = 0;
	total = total + (getThreeMade(game) * 3);
	total = total + (getTwoMade(game) * 2);
	total = total + getFtMade(game);
	return total;
}

void player::setName(string name1) {
	name = name1;
}
void player::setJerseyNum(int num){
	jerseyNum = num;
}
void player::setThree(int made, int att, int game) {
	g[game].threeMade = made;
	g[game].threeAtt = att;
}
void player::setTwo(int made, int att, int game) {
	g[game].twoMade = made;
	g[game].twoAtt = att;
}
void player::setFt(int made, int att, int game) {
	g[game].ftMade = made;
	g[game].ftAtt = att;
}
void player::setNumGames(int num) {
	numGames = num;
}