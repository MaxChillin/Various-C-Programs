#include <fstream>
#include <iostream>
#include <string>
#include <random>
#include <math.h>
#include <vector>
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds

using namespace std;


unsigned int  a, b, c, d, PCguess, lastChange, e, f, g, h;
int aa, bb, cc, dd, playerNumber, playerGuess, ee, ff, gg, hh;
int playerBulls, playerCows, PCCurrentBulls, PCCurrentCows, PCPreviousBulls, PCPreviousCows, digitChange, trueBulls;
bool goodGuess = false, newGuess = false, firstGuess = true, winner = false, loser = false, newGame = true, validNumber = false;
bool eChanged = false, fChanged = false, gChanged = false, hChanged = false, eCorrect = false, fCorrect = false, gCorrect = false, hCorrect = false;
bool bullCountChanged = false, cowCountChanged = false, firstBull = true;
string choice;
vector<int> computerGuesses;
vector<int> possible_E_Bulls;
vector<int> possible_F_Bulls;
vector<int> possible_G_Bulls;
vector<int> possible_H_Bulls;
int notE[8] = { 0,0,0,0,0,0,0,0 };
int notF[8] = { 0,0,0,0,0,0,0,0 };
int notG[8] = { 0,0,0,0,0,0,0,0 };
int notH[8] = { 0,0,0,0,0,0,0,0 };
int eIndex = 0, fIndex = 0, gIndex = 0, hIndex = 0;

std::default_random_engine generator;
std::uniform_int_distribution<int> randOne(1, 9);
std::uniform_int_distribution<int> randTwo(0, 3);



void generateNumber();
void setPlayerNumber();
void computerGuess();
void removePossible(int vector, int number);
void resetAll();

void main() {
	
	// Game Loop
	while (true) {
		if (newGame) {
			cout << "New Game! Good Luck!" << endl;
			resetAll();
			generateNumber();
			setPlayerNumber();
		}

		if (winner || loser) {
			newGame = true;
			cout << "Would You Like To Play Again: Y/N? " << endl;
			cin >> choice;
			if (choice == "N" || choice == "n") {
				cout << "Thank You For Playing! Good-Bye!" << endl;
				std::this_thread::sleep_for(std::chrono::seconds(3));
				exit(0);
			}
			continue;
		}

		//**************************
		// This is the Players Guess
		while (!goodGuess) {
			cout << "You have " << playerBulls << " Bulls, and " << playerCows << " Cows." << endl;
			cout << "Make a Guess. All digits must be different:" << endl;
			cin >> playerGuess;
			int temp = playerGuess;

			dd = temp % 10;
			temp /= 10;
			cc = temp % 10;
			temp /= 10;
			bb = temp % 10;
			temp /= 10;
			aa = temp % 10;
			if (aa == bb || aa == cc || aa == dd || bb == cc || bb == dd || cc == dd || playerGuess > 9999) {
				cout << "Invalid Guess! All digits must be different!" << endl;
			}
			else
				goodGuess = true;

		}//******************* 
		//End of Players Guess
		//********************

		//**********************************
		// Victory Check and Bull/Cow update
		if (a == aa && b == bb && c == cc && d == dd) {
			winner = true;
			cout << "Congradulations! You Have Guess The Number!" << endl;
		}
		else {
			playerBulls = playerCows = 0;

			if (a == aa)
				playerBulls++;
			if (b == bb)
				playerBulls++;
			if (c == cc)
				playerBulls++;
			if (d == dd)
				playerBulls++;
			if (a == bb || a == cc || a == dd)
				playerCows++;
			if (b == aa || b == cc || b == dd)
				playerCows++;
			if (c == aa || c == bb || c == dd)
				playerCows++;
			if (d == aa || d == bb || d == cc)
				playerCows++;

		}//****************************************
		// End of Victory Check and Bull/Cow update
		//*****************************************

		computerGuess();
		cout << "The computer guesses " << PCguess << endl;
		cout << "                     " << ee << ff << gg << hh << endl;

		//***********************
		// Computer Victory Check 
		if (e == ee && f == ff && g == gg && h == hh) {
			loser = true;
			cout << "Loser! The Computer Guessed Your Number!" << endl;
			continue;
		}
		else {
			trueBulls = 0;
			if (e == ee)
				trueBulls++;
			if (f == ff)
				trueBulls++;
			if (g == gg)
				trueBulls++;
			if (h == hh)
				trueBulls++;
		}//*****************************
		// End of Computer Victory Check 
		//******************************

		PCPreviousBulls = PCCurrentBulls;
		PCPreviousCows = PCCurrentCows;
		cout << "How many Bulls did the computer get: " << endl;
		cin >> PCCurrentBulls;
		cout << "How many Cows did the computer get: " << endl;
		cin >> PCCurrentCows;

		if (trueBulls != PCCurrentBulls)
			eCorrect = fCorrect = gCorrect = hCorrect = false;

		if (!firstBull) {
			if (PCCurrentBulls > PCPreviousBulls) {
				cout << "PCCurrentBulls > PCPreviousBulls" << endl;
				cout << "The digit that changed was " << digitChange << endl;
				switch (digitChange) {
				case 0:
					eCorrect = true;
					cout << "e = " << e << endl;
					cout << "e is locked" << endl;
					removePossible(1, e);
					removePossible(2, e);
					removePossible(3, e);
					/*for (int i = 0; i < possible_F_Bulls.size(); i++) {
						if (possible_F_Bulls.at(i) == e) {
							cout << possible_F_Bulls.at(i) << " has been removed from F list" << endl;
							possible_F_Bulls.erase(possible_F_Bulls.begin() + i);
						}
					}
					for (int i = 0; i < possible_G_Bulls.size(); i++) {
						if (possible_G_Bulls.at(i) == e) {
							cout << possible_G_Bulls.at(i) << " has been removed from G list" << endl;
							possible_G_Bulls.erase(possible_G_Bulls.begin() + i);
						}
					}
					for (int i = 0; i < possible_H_Bulls.size(); i++) {
						if (possible_H_Bulls.at(i) == e) {
							cout << possible_H_Bulls.at(i) << " has been removed from H list" << endl;
							possible_H_Bulls.erase(possible_H_Bulls.begin() + i);
						}
					}*/
					break;
				case 1:
					fCorrect = true;
					cout << "f = " << f << endl;
					cout << "f is locked" << endl;
					removePossible(0, f);
					removePossible(2, f);
					removePossible(3, f);
					/*for (int i = 0; i < possible_E_Bulls.size(); i++) {
						if (possible_E_Bulls.at(i) == f) {
							cout << possible_E_Bulls.at(i) << " has been removed from E list" << endl;
							possible_E_Bulls.erase(possible_E_Bulls.begin() + i);
						}
					}
					for (int i = 0; i < possible_G_Bulls.size(); i++) {
						if (possible_G_Bulls.at(i) == f) {
							cout << possible_G_Bulls.at(i) << " has been removed from G list" << endl;
							possible_G_Bulls.erase(possible_G_Bulls.begin() + i);
						}
					}
					for (int i = 0; i < possible_H_Bulls.size(); i++) {
						if (possible_H_Bulls.at(i) == f) {
							cout << possible_H_Bulls.at(i) << " has been removed from H list" << endl;
							possible_H_Bulls.erase(possible_H_Bulls.begin() + i);
						}
					}*/
					break;
				case 2:
					gCorrect = true;
					cout << "g = " << g << endl;
					cout << "g is locked" << endl;
					removePossible(0, g);
					removePossible(1, g);
					removePossible(3, g);
					/*for (int i = 0; i < possible_E_Bulls.size(); i++) {
						if (possible_E_Bulls.at(i) == g) {
							cout << possible_E_Bulls.at(i) << " has been removed from E list" << endl;
							possible_E_Bulls.erase(possible_E_Bulls.begin() + i);
						}
					}
					for (int i = 0; i < possible_F_Bulls.size(); i++) {
						if (possible_F_Bulls.at(i) == g) {
							cout << possible_F_Bulls.at(i) << " has been removed from F list" << endl;
							possible_F_Bulls.erase(possible_F_Bulls.begin() + i);
						}
					}
					for (int i = 0; i < possible_H_Bulls.size(); i++) {
						if (possible_H_Bulls.at(i) == g) {
							cout << possible_H_Bulls.at(i) << " has been removed from H list" << endl;
							possible_H_Bulls.erase(possible_H_Bulls.begin() + i);
						}
					}*/
					break;
				case 3:
					hCorrect = true;
					cout << "h = " << h << endl;
					cout << "h is locked" << endl;
					removePossible(0, h);
					removePossible(1, h);
					removePossible(2, h);
					/*for (int i = 0; i < possible_E_Bulls.size(); i++) {
						if (possible_E_Bulls.at(i) == h) {
							cout << possible_E_Bulls.at(i) << " has been removed from E list" << endl;
							possible_E_Bulls.erase(possible_E_Bulls.begin() + i);
						}
					}
					for (int i = 0; i < possible_F_Bulls.size(); i++) {
						if (possible_F_Bulls.at(i) == h) {
							cout << possible_F_Bulls.at(i) << " has been removed from F list" << endl;
							possible_F_Bulls.erase(possible_F_Bulls.begin() + i);
						}
					}
					for (int i = 0; i < possible_G_Bulls.size(); i++) {
						if (possible_G_Bulls.at(i) == h) {
							cout << possible_G_Bulls.at(i) << " has been removed from G list" << endl;
							possible_G_Bulls.erase(possible_G_Bulls.begin() + i);
						}
					}*/
					break;
				}// end of switch
			}
			if (PCCurrentBulls < PCPreviousBulls) {
				cout << "PCCurrentBulls < PCPreviousBulls" << endl;
				cout << "The digit that changed was " << digitChange << endl;
				PCCurrentBulls++;
				switch (digitChange) {
				case 0:
					eCorrect = true;
					e = lastChange;
					cout << "e = " << e << endl;
					cout << "e is locked" << endl;
					removePossible(1, e);
					removePossible(2, e);
					removePossible(3, e);
					/*for (int i = 0; i < possible_F_Bulls.size(); i++) {
						if (possible_F_Bulls.at(i) == e) {
							cout << possible_F_Bulls.at(i) << " has been removed from F list" << endl;
							possible_F_Bulls.erase(possible_F_Bulls.begin() + i);
						}
					}
					for (int i = 0; i < possible_G_Bulls.size(); i++) {
						if (possible_G_Bulls.at(i) == e) {
							cout << possible_G_Bulls.at(i) << " has been removed from G list" << endl;
							possible_G_Bulls.erase(possible_G_Bulls.begin() + i);
						}
					}
					for (int i = 0; i < possible_H_Bulls.size(); i++) {
						if (possible_H_Bulls.at(i) == e) {
							cout << possible_H_Bulls.at(i) << " has been removed from H list" << endl;
							possible_H_Bulls.erase(possible_H_Bulls.begin() + i);
						}
					}*/
					break;
				case 1:
					fCorrect = true;
					f = lastChange;
					cout << "f = " << f << endl;
					cout << "f is locked" << endl;
					removePossible(0, f);
					removePossible(2, f);
					removePossible(3, f);
					/*for (int i = 0; i < possible_E_Bulls.size(); i++) {
						if (possible_E_Bulls.at(i) == f) {
							cout << possible_E_Bulls.at(i) << " has been removed from E list" << endl;
							possible_E_Bulls.erase(possible_E_Bulls.begin() + i);
						}
					}
					for (int i = 0; i < possible_G_Bulls.size(); i++) {
						if (possible_G_Bulls.at(i) == f) {
							cout << possible_G_Bulls.at(i) << " has been removed from G list" << endl;
							possible_G_Bulls.erase(possible_G_Bulls.begin() + i);
						}
					}
					for (int i = 0; i < possible_H_Bulls.size(); i++) {
						if (possible_H_Bulls.at(i) == f) {
							cout << possible_H_Bulls.at(i) << " has been removed from H list" << endl;
							possible_H_Bulls.erase(possible_H_Bulls.begin() + i);
						}
					}*/
					break;
				case 2:
					gCorrect = true;
					g = lastChange;
					cout << "g = " << g << endl;
					cout << "g is locked" << endl;
					removePossible(0, g);
					removePossible(1, g);
					removePossible(3, g);
					/*for (int i = 0; i < possible_E_Bulls.size(); i++) {
						if (possible_E_Bulls.at(i) == g) {
							cout << possible_E_Bulls.at(i) << " has been removed from E list" << endl;
							possible_E_Bulls.erase(possible_E_Bulls.begin() + i);
						}
					}
					for (int i = 0; i < possible_F_Bulls.size(); i++) {
						if (possible_F_Bulls.at(i) == g) {
							cout << possible_F_Bulls.at(i) << " has been removed from F list" << endl;
							possible_F_Bulls.erase(possible_F_Bulls.begin() + i);
						}
					}
					for (int i = 0; i < possible_H_Bulls.size(); i++) {
						if (possible_H_Bulls.at(i) == g) {
							cout << possible_H_Bulls.at(i) << " has been removed from H list" << endl;
							possible_H_Bulls.erase(possible_H_Bulls.begin() + i);
						}
					}*/
					break;
				case 3:
					hCorrect = true;
					h = lastChange;
					cout << "h = " << h << endl;
					cout << "h is locked" << endl;
					removePossible(0, h);
					removePossible(1, h);
					removePossible(2, h);
					break;
				}// end of switch
			}


			if (PCCurrentCows < PCPreviousCows) {
				cout << "PCCurrentCows < PCPreviousCows" << endl;
				cout << "The digit that changed was " << digitChange << endl;
				removePossible(digitChange, lastChange);
				switch (digitChange) {
				case 0:
					cout << lastChange << " was push onto F, G, and H vectors" << endl;
					possible_F_Bulls.push_back(lastChange);
					possible_G_Bulls.push_back(lastChange);
					possible_H_Bulls.push_back(lastChange);
					break;
				case 1:
					cout << lastChange << " was push onto E, G, and H vectors" << endl;
					possible_E_Bulls.push_back(lastChange);
					possible_G_Bulls.push_back(lastChange);
					possible_H_Bulls.push_back(lastChange);
					break;
				case 2:
					cout << lastChange << " was push onto E, F, and H vectors" << endl;
					possible_E_Bulls.push_back(lastChange);
					possible_F_Bulls.push_back(lastChange);
					possible_H_Bulls.push_back(lastChange);
					break;
				case 3:
					cout << lastChange << " was push onto E, F, and G vectors" << endl;
					possible_E_Bulls.push_back(lastChange);
					possible_F_Bulls.push_back(lastChange);
					possible_G_Bulls.push_back(lastChange);
					break;
				}// end of switch
			}

			if (PCCurrentCows > PCPreviousCows) {
				cout << "PCCurrentCows > PCPreviousCows" << endl;
				cout << "The digit that changed was " << digitChange << endl;
				switch (digitChange) {
				case 0:
					cout << e << " was push onto F, G, and H vectors" << endl;
					possible_F_Bulls.push_back(e);
					possible_G_Bulls.push_back(e);
					possible_H_Bulls.push_back(e);
					removePossible(digitChange, e);
					break;
				case 1:
					cout << f << " was push onto E, G, and H vectors" << endl;
					possible_E_Bulls.push_back(f);
					possible_G_Bulls.push_back(f);
					possible_H_Bulls.push_back(f);
					removePossible(digitChange, f);
					break;
				case 2:
					cout << g << " was push onto E, F, and H vectors" << endl;
					possible_E_Bulls.push_back(g);
					possible_F_Bulls.push_back(g);
					possible_H_Bulls.push_back(g);
					removePossible(digitChange, g);
					break;
				case 3:
					cout << h << " was push onto E, F, and G vectors" << endl;
					possible_E_Bulls.push_back(h);
					possible_F_Bulls.push_back(h);
					possible_G_Bulls.push_back(h);
					removePossible(digitChange, h);
					break;
				}// end of switch
			}

		}// end if(!firstBull)




		//system("PAUSE");
		goodGuess = false, validNumber = false;
	}// end of Game loop

}// end of main


void generateNumber() {
	a = randOne(generator);
	b = randOne(generator);
	while (b == a)
		b = randOne(generator);
	c = randOne(generator);
	while (c == b || c == a)
		c = randOne(generator);
	d = randOne(generator);
	while (d == c || d == b || d == a)
		d = randOne(generator);

}// end of generateNumber function


void setPlayerNumber() {
	while (!validNumber) {
		cout << "Please Enter A 4 Digit Number For The Computer To Guess: " << endl;
		cin >> playerNumber;
		int temp = playerNumber;

		hh = temp % 10;
		temp /= 10;
		gg = temp % 10;
		temp /= 10;
		ff = temp % 10;
		temp /= 10;
		ee = temp % 10;
		//cout << aa << " " << bb << " " << cc << " " << dd << endl;
		if (ee == ff || ee == gg || ee == hh || ff == gg || ff == hh || gg == hh || playerNumber > 9999) {
			cout << "Invalid Guess! All digits must be different!" << endl;
		}
		else
			validNumber = true;

	}// End of input while loop

}// end of setPlayerNumber function


void resetAll() {
	a = b = c = d = aa = bb = cc = dd = playerBulls = playerCows = PCCurrentBulls = PCPreviousBulls = PCPreviousCows = PCCurrentCows = playerGuess = 0;
	for (int i = 0; i <= 8; i++) {
		notE[i] = 0;
		notF[i] = 0;
		notG[i] = 0;
		notH[i] = 0;
	}
	newGame = false, firstGuess = true,	winner = false,	loser = false, firstBull = true;
	eChanged = false, fChanged = false, gChanged = false, hChanged = false, eCorrect = false, fCorrect = false, gCorrect = false, hCorrect = false;
	possible_E_Bulls.clear();
	possible_F_Bulls.clear();
	possible_G_Bulls.clear();
	possible_H_Bulls.clear();
	computerGuesses.clear();
	if (computerGuesses.empty())
		cout << "Stack is cleared!" << endl;
	eIndex = 0, fIndex = 0, gIndex = 0, hIndex = 0;

}//***************************************
// End of resetAll function
//****************************************


void removePossible(int theVector, int number) {
	cout << "remove Possible " << number << " from " << theVector << " vector" << endl;
	switch (theVector) {
	case 0:
		if(eIndex <= 8)
			notE[eIndex++] = number;
		for (int i = 0; i < possible_E_Bulls.size(); i++) {
			if (possible_E_Bulls.at(i) == number) {
				cout << possible_E_Bulls.at(i) << " has been removed from E list" << endl;
				possible_E_Bulls.erase(possible_E_Bulls.begin() + i);
			}
		}
		break;
	case 1:
		if (fIndex <= 8)
			notF[fIndex++] = number;
		for (int i = 0; i < possible_F_Bulls.size(); i++) {
			if (possible_F_Bulls.at(i) == number) {
				cout << possible_F_Bulls.at(i) << " has been removed from F list" << endl;
				possible_F_Bulls.erase(possible_F_Bulls.begin() + i);
			}
		}
		break;
	case 2:
		if (gIndex <= 8)
			notG[gIndex++] = number;
		for (int i = 0; i < possible_G_Bulls.size(); i++) {
			if (possible_G_Bulls.at(i) == number) {
				cout << possible_G_Bulls.at(i) << " has been removed from G list" << endl;
				possible_G_Bulls.erase(possible_G_Bulls.begin() + i);
			}
		}
		break;
	case 3:
		if (hIndex <= 8)
			notH[hIndex++] = number;
		for (int i = 0; i < possible_H_Bulls.size(); i++) {
			if (possible_H_Bulls.at(i) == number) {
				cout << possible_H_Bulls.at(i) << " has been removed from H list" << endl;
				possible_H_Bulls.erase(possible_H_Bulls.begin() + i);
			}
		}
		break;
	}// end of switch

}//*************************************************
// End of removePossible function
//**************************************************


void computerGuess() {
	cout << "Enter computerGuess function" << endl;



	if (firstGuess) {
		cout << "PC First Guess" << endl;
		firstGuess = false;		
		e = randOne(generator);
		f = randOne(generator);
		while (f == e)
			f = randOne(generator);
		g = randOne(generator);
		while (g == e || g == f)
			g = randOne(generator);
		h = randOne(generator);
		while (h == e || h == f || h == g)
			h = randOne(generator);
		PCguess = e*10e+2 + f*10e+1 + g * 10 + h;
	}
	else {
		cout << "Not PC First Guess" << endl;
		firstBull = false;
		while (!newGuess) {
			cout << "New Guess" << endl;
			newGuess = true;
			int temp = randTwo(generator);
			switch (temp) {
			case 0:
				if (!eCorrect) {
					lastChange = e;
					if (!possible_E_Bulls.empty()) {
						cout << "E vector not empty" << endl;
						cout << "possible_E_Bulls.at(0) = " << possible_E_Bulls.at(0) << endl;
						e = possible_E_Bulls.at(0);
						cout << "e = " << e << endl;
						//removePossible(0, e);
						while (e == lastChange || e == f || e == g || e == h || e == notE[0] || e == notE[1] || e == notE[2] || e == notE[3] || e == notE[4] || e == notE[5] || e == notE[6] || e == notE[7])
							e = randOne(generator);
					}
					else {
						cout << "e = randOne(generator)" << endl;
						while (e == lastChange || e == f || e == g || e == h || e == notE[0] || e == notE[1] || e == notE[2] || e == notE[3] || e == notE[4] || e == notE[5] || e == notE[6] || e == notE[7])
							e = randOne(generator);
						cout << "e = " << e << endl;
					}
					digitChange = 0;
				}
				break;
			case 1:
				if (!fCorrect) {
					lastChange = f;
					if (!possible_F_Bulls.empty()) {
						cout << "F vector not empty" << endl;
						cout << "possible_F_Bulls.at(0) = " << possible_F_Bulls.at(0) << endl;
						f = possible_F_Bulls.at(0);
						cout << "f = " << f << endl;
						//removePossible(1, f);
						while (f == lastChange || f == e || f == g || f == h || f == notF[0] || f == notF[1] || f == notF[2] || f == notF[3] || f == notF[4] || f == notF[5] || f == notF[6] || f == notF[7])
							f = randOne(generator);
					}
					else {
						cout << "f = randOne(generator)" << endl;
						while (f == lastChange || f == e || f == g || f == h || f == notF[0] || f == notF[1] || f == notF[2] || f == notF[3] || f == notF[4] || f == notF[5] || f == notF[6] || f == notF[7])
							f = randOne(generator);
						cout << "f = " << f << endl;
					}
					digitChange = 1;
				}
				break;
			case 2:
				if (!gCorrect) {
					lastChange = g;
					if (!possible_G_Bulls.empty()) {
						cout << "G vector not empty" << endl;
						cout << "possible_G_Bulls.at(0) = " << possible_G_Bulls.at(0) << endl;
						g = possible_G_Bulls.at(0);
						cout << "g = " << g << endl;
						//removePossible(2, g);
						while (g == lastChange || g == e || g == f || g == h || g == notG[0] || g == notG[1] || g == notG[2] || g == notG[3] || g == notG[4] || g == notG[5] || g == notG[6] || g == notG[7])
							g = randOne(generator);
					}
					else {
						cout << "g = randOne(generator)" << endl;
						while (g == lastChange || g == e || g == f || g == h || g == notG[0] || g == notG[1] || g == notG[2] || g == notG[3] || g == notG[4] || g == notG[5] || g == notG[6] || g == notG[7])
							g = randOne(generator);
						cout << "g = " << g << endl;
					}
					digitChange = 2;
				}
				break;
			case 3:
				if (!hCorrect) {
					lastChange = h;
					if (!possible_H_Bulls.empty()) {
						cout << "H vector not empty" << endl;
						cout << "possible_H_Bulls.at(0) = " << possible_H_Bulls.at(0) << endl;
						h = possible_H_Bulls.at(0);
						cout << "h = " << h << endl;
						//removePossible(3, h);
						while (h == lastChange || h == e || h == f || h == g || h == notH[0] || h == notH[1] || h == notH[2] || h == notH[3] || h == notH[4] || h == notH[5] || h == notH[6] || h == notH[7])
							h = randOne(generator);
					}
					else {
						cout << "h = randOne(generator)" << endl;
						while (h == lastChange || h == e || h == f || h == g || h == notH[0] || h == notH[1] || h == notH[2] || h == notH[3] || h == notH[4] || h == notH[5] || h == notH[6] || h == notH[7])
							h = randOne(generator);
						cout << "h = " << h << endl;
					}
					digitChange = 3;
				}
				break;
			}// end of switch(temp)
			PCguess = e*10e+2 + f*10e+1 + g * 10 + h;

			for (int x : computerGuesses) {
				cout << "Is " << PCguess << " = " << x << endl;
				if (x == PCguess)
					newGuess = false;
			}
		}// end of newGuess while loop
	}// end of else
	computerGuesses.push_back(PCguess);
	cout << PCguess << " was pushed onto the computerGuesses vector" << endl;
	//PCCurrentBulls = PCCurrentCows = 0;
	newGuess = false;
}// end of computerGuess function
