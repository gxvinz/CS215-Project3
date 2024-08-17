#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "player.h"
#include "team.h"
using namespace std;

//---------------------------------------------------------
//                    Constructor
//---------------------------------------------------------
team::team() {
	numPlayer = 0;
	numGames = 0;
}

//---------------------------------------------------------
//                    Get Methods
//---------------------------------------------------------
int team::getNumPlayers() {
	return numPlayer;
}
int team::getNumGames() {
	return numGames;
}

//---------------------------------------------------------
//                    Set Methods
//---------------------------------------------------------
void team::setNumPlayers(int num) {
	numPlayer = num;
}
void team::setNumGames(int num) {
	numGames = num;
}

//---------------------------------------------------------
//                      Print
//---------------------------------------------------------
void team::print() {
	// printing team
	cout << "Number of Games: " << numGames << " Number of Players: " << numPlayer << endl;
	for (int i = 0; i < numPlayer; i++) {

		cout << p[i].getName() << "  [" << p[i].getJerseyNum() << "]" << endl;
		cout << "Game  " << "3-Point FGs   " << "2-Point FGs   " << "Free Throws " << "  Total" << endl;
		cout << "----  " << "------------  " << "------------  " << "------------" << "  -----" << endl;
		for (int j = 0; j < numGames; j++) {
			cout << right << setw(4) << j;
			cout << right << setw(4) << p[i].getThreeMade(j) << "/";
			cout << right << setw(2) << p[i].getThreeAtt(j) << " (";
			if (p[i].getThreeAtt(j) == 0) { cout << "  0%)"; }
			else {
				cout << right << setw(3) << fixed << setprecision(0) << ((p[i].getThreeMade(j) / double(p[i].getThreeAtt(j))) * 100) << "%)";
			}
			cout << right << setw(4) << p[i].getTwoMade(j) << "/";
			cout << right << setw(2) << p[i].getTwoAtt(j) << " (";
			if (p[i].getTwoAtt(j) == 0) { cout << "  0%)"; }
			else {
				cout << right << setw(3) << fixed << setprecision(0) << ((p[i].getTwoMade(j) / double(p[i].getTwoAtt(j))) * 100) << "%)";
			}
			cout << right << setw(4) << p[i].getFtMade(j) << "/";
			cout << right << setw(2) << p[i].getFtAtt(j) << " (";
			if (p[i].getFtAtt(j) == 0) { cout << "  0%)"; }
			else {
				cout << right << setw(3) << fixed << setprecision(0) << ((p[i].getFtMade(j) / double(p[i].getFtAtt(j))) * 100) << "%)";
			}
			cout << right << setw(7) << p[i].getTotPointsGame(j);
			cout << endl;
		}
		cout << " ALL";
		cout << right << setw(4) << p[i].getTotThreeMade() << "/";
		cout << right << setw(2) << p[i].getTotThreeAtt() << " (";
		if (p[i].getTotThreeAtt() == 0) { cout << "  0%)"; }
		else {
			cout << right << setw(3) << fixed << setprecision(0) << ((p[i].getTotThreeMade() / double(p[i].getTotThreeAtt())) * 100) << "%)";
		}
		cout << right << setw(4) << p[i].getTotTwoMade() << "/";
		cout << right << setw(2) << p[i].getTotTwoAtt() << " (";
		if (p[i].getTotTwoAtt() == 0) { cout << "  0%)"; }
		else {
			cout << right << setw(3) << fixed << setprecision(0) << ((p[i].getTotTwoMade() / double(p[i].getTotTwoAtt())) * 100) << "%)";
		}
		cout << right << setw(4) << p[i].getTotFtMade() << "/";
		cout << right << setw(2) << p[i].getTotFtAtt() << " (";
		if (p[i].getTotFtAtt() == 0) { cout << "  0%)"; }
		else {
			cout << right << setw(3) << fixed << setprecision(0) << ((p[i].getTotFtMade() / double(p[i].getTotFtAtt())) * 100) << "%)";
		}
		cout << right << setw(7) << p[i].getTotPoints();
		cout << endl;
	}
	system("pause");
}

//---------------------------------------------------------
//                    Add Game
//---------------------------------------------------------
void team::addGame() {
	int threes, threesMade, twos{}, twosMade{}, ft, ftMade;
	if (numGames >= maxGames) {
		cout << "No more games can be added." << endl;
	}
	else {
		int num = numGames + 1;
		for (int i = 0; i < numPlayer; i++) {
			//getting input
			cout << "Enter stats for " << p[i].getName();
			cout << " [" << p[i].getJerseyNum() << "]" << endl;
			cout << "3 Pointers (made attempted): ";
			cin >> threesMade;
			cin >> threes;
			cout << "2 Pointers (made attempted): ";
			cin >> twosMade;
			cin >> twos;
			cout << "Freethrows (made attempted): ";
			cin >> ftMade;
			cin >> ft;
			// checking if valid
			if (threesMade > threes) {
				cout << "aStat::set(" << threesMade << "," << threes << ") invalid!" << endl;
				threesMade = 0;
				threes = 0;
			}
			p[i].setThree(threesMade, threes, numGames);
			if (twosMade > twos) {
				cout << "aStat::set(" << twosMade << "," << twos << ") invalid!" << endl;
				twosMade = 0;
				twos = 0;
			}
			p[i].setTwo(twosMade, twos, numGames);
			if (ftMade > ft) {
				cout << "aStat::set(" << ftMade << "," << ft << ") invalid!" << endl;
				ftMade = 0;
				ft = 0;
			}
			p[i].setFt(ftMade, ft, numGames);



			p[i].setNumGames(num);
		}
		numGames = numGames + 1;
	}
}

//---------------------------------------------------------
//                  Display Player
//---------------------------------------------------------
void team::displayPlayer() {
	// displaying specific player
	int num;
	int a = 0;
	cout << "Enter player jersey number: ";
	cin >> num;
	for (int i = 0; i < numPlayer; i++) {
		if (p[i].getJerseyNum() == num) {
			a = 5;
			cout << p[i].getName() << "  [" << num << "]" << endl;
			cout << "Game  " << "3-Point FGs   " << "2-Point FGs   " << "Free Throws " << "  Total" << endl;
			cout << "----  " << "------------  " << "------------  " << "------------" << "  -----" << endl;
			for (int j = 0; j < numGames; j++) {
				cout << right << setw(4) << j;
				cout << right << setw(4) << p[i].getThreeMade(j) << "/";
				cout << right << setw(2) << p[i].getThreeAtt(j) << " (";
				if (p[i].getThreeAtt(j) == 0) { cout << "  0%)"; }
				else {
					cout << right << setw(3) << fixed << setprecision(0) << ((p[i].getThreeMade(j) / double(p[i].getThreeAtt(j))) * 100) << "%)";
				}
				cout << right << setw(4) << p[i].getTwoMade(j) << "/";
				cout << right << setw(2) << p[i].getTwoAtt(j) << " (";
				if (p[i].getTwoAtt(j) == 0) { cout << "  0%)"; }
				else {
					cout << right << setw(3) << fixed << setprecision(0) << ((p[i].getTwoMade(j) / double(p[i].getTwoAtt(j))) * 100) << "%)";
				}
				cout << right << setw(4) << p[i].getFtMade(j) << "/";
				cout << right << setw(2) << p[i].getFtAtt(j) << " (";
				if (p[i].getFtAtt(j) == 0) { cout << "  0%)"; }
				else {
					cout << right << setw(3) << fixed << setprecision(0) << ((p[i].getFtMade(j) / double(p[i].getFtAtt(j))) * 100) << "%)";
				}
				cout << right << setw(7) << p[i].getTotPointsGame(j);
				cout << endl;
			}
			cout << " ALL";
			cout << right << setw(4) << p[i].getTotThreeMade() << "/";
			cout << right << setw(2) << p[i].getTotThreeAtt() << " (";
			if (p[i].getTotThreeAtt() == 0) { cout << "  0%)"; }
			else {
				cout << right << setw(3) << fixed << setprecision(0) << ((p[i].getTotThreeMade() / double(p[i].getTotThreeAtt())) * 100) << "%)";
			}
			cout << right << setw(4) << p[i].getTotTwoMade() << "/";
			cout << right << setw(2) << p[i].getTotTwoAtt() << " (";
			if (p[i].getTotTwoAtt() == 0) { cout << "  0%)"; }
			else {
				cout << right << setw(3) << fixed << setprecision(0) << ((p[i].getTotTwoMade() / double(p[i].getTotTwoAtt())) * 100) << "%)";
			}
			cout << right << setw(4) << p[i].getTotFtMade() << "/";
			cout << right << setw(2) << p[i].getTotFtAtt() << " (";
			if (p[i].getTotFtAtt() == 0) { cout << "  0%)"; }
			else {
				cout << right << setw(3) << fixed << setprecision(0) << ((p[i].getTotFtMade() / double(p[i].getTotFtAtt())) * 100) << "%)";
			}
			cout << right << setw(7) << p[i].getTotPoints();
			cout << endl;
		}
		
	}
	if (a == 0) {
		cout << "Player not found!" << endl;
	}
}

//---------------------------------------------------------
//                   Sort By Name
//---------------------------------------------------------
void team::sortByName() {
	// comparing each name and swapping when out of order
	cout << "Players sorted by name." << endl;
	for (int i = 0; i < numPlayer; i++) {
		for (int j = i + 1; j < numPlayer; j++) {
			if (p[i].getName() > p[j].getName()) {
				player temp = p[i];
				p[i] = p[j];
				p[j] = temp;
			}
		}
	}
}

//---------------------------------------------------------
//                   Sort By Jersey
//---------------------------------------------------------
void team::sortByJersey() {
	// checking each jersey number and swapping when out of order
	cout << "Players sorted by jersey." << endl;
	for (int i = 0; i < numPlayer; i++) {
		for (int j = i + 1; j < numPlayer; j++) {
			if (p[i].getJerseyNum() > p[j].getJerseyNum()) {
				player temp = p[i];
				p[i] = p[j];
				p[j] = temp;
			}
		}
	}
}

//---------------------------------------------------------
//                   Remove Player
//---------------------------------------------------------
void team::removePlayer() {
	// removing player based on user input
	int num;
	int a = 0;
	cout << "Enter player jersey number: ";
	cin >> num;
	for (int i = 0; i < numPlayer; i++) {
		if (p[i].getJerseyNum() == num) {
			cout << "Player" << p[i].getName() << " [" << p[i].getJerseyNum() << "] removed" << endl;
			for(i; i < numPlayer-1; i++){
				// filling up empty spot with remaining players
			int temp = i + 1;
			p[i].setJerseyNum(p[temp].getJerseyNum());
			p[i].setName(p[temp].getName());
				for (int j = 0; j < numGames; j++) {
					p[i].setThree(p[temp].getThreeMade(j), p[temp].getThreeAtt(j), j);
					p[i].setTwo(p[temp].getTwoMade(j), p[temp].getTwoAtt(j), j);
					p[i].setFt(p[temp].getFtMade(j), p[temp].getFtAtt(j), j);
				}
			}
		}
	}
	string temp = "";
	numPlayer = numPlayer - 1;
	p[numPlayer].setJerseyNum(0);
	p[numPlayer].setName(temp);
	for (int j = 0; j < numGames; j++) {
		p[numPlayer].setThree(0,0,j);
		p[numPlayer].setTwo(0,0,j);
		p[numPlayer].setFt(0,0,j);
	}

}

//---------------------------------------------------------
//                      Write
//---------------------------------------------------------
void team::write() {
	// writing data to ending txt file
	ofstream fout;
	fout.open("bballout.txt");
	fout << numPlayer << " " << numGames << endl;
	for (int i = 0; i < numPlayer; i++) {
		fout << p[i].getJerseyNum() << p[i].getName() << endl;
		for (int j = 0; j < numGames; j++) {
			fout << p[i].getThreeMade(j) << " " << p[i].getThreeAtt(j) << " ";
			fout << p[i].getTwoMade(j) << " " << p[i].getTwoAtt(j) << " ";
			fout << p[i].getFtMade(j) << " " << p[i].getFtAtt(j) << " ";
			fout << endl;
		}
	}
}

//---------------------------------------------------------
//                      Read
//---------------------------------------------------------
void team::read() {
	// reading data from starting text file
	ifstream fin;
	fin.open("bballin.txt");
	fin >> numPlayer;
	fin >> numGames;
	for (int i = 0; i < numPlayer; i++) {
		int temp1;
		 fin >> temp1;
		 p[i].setJerseyNum(temp1);
		 p[i].setNumGames(numGames);
		 string temp;
		getline(fin, temp);
		p[i].setName(temp);
		for (int j = 0; j < numGames; j++) {
			int made = 0;
			int att = 0;
			fin >> made;
			fin >> att;
			p[i].setThree(made, att, j);
			made = 0;
			att = 0;
			fin >> made;
			fin >> att;
			p[i].setTwo(made, att, j);
			made = 0;
			att = 0;
			fin >> made;
			fin >> att;
			p[i].setFt(made, att, j);
		}
	}
}