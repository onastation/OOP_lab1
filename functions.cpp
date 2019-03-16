#include "pch.h"
#include <iostream>
#include <string>
#include "init.h"
using namespace std;

string add_team(string line) {
	string team;
	int j = 0;
	if (line.find('"') < line.find(',')) {
		while (line[j+1] != '"') {
			team += line[j+1];
			j++;
		}
		line.erase(0, j + 1);
	}
	else {
		for (int i = 0; i < line.find(','); i++) {
			team += line[i];
		}
		line.erase(0, line.find(','));
	}
	return team;
}
int* team_stats(string line) {
	int Played = 0, Won = 0, Drawn = 0, Lost = 0, GF = 0, GA = 0, GD = 0, Pts = 0;
	line += ',';
	string col = ":";
	string them = "", opp = "";
	for (int i = 0; i < line.length(); i++) {
		if (line[i] == ':') {
			Played++;
		}
	}
	for (int i = 0; i < Played; i++) {
		int j = line.find(col);
		while (line[j-1] != ',') {
			them += line[j-1];
			j--;
		}
		j = line.find(col);
		while ((line[j+1] != ',')) {
			opp += line[j+1];
			j++;
		}
		line.erase(0, j+1);
		int scored = 0, missed = 0;
		scored = stoi(them);
		GF += scored;
		missed = stoi(opp);
		GA += missed;
		if (scored < missed) {
			Lost++;
		}
		if (scored == missed) {
			Pts++;
			Drawn++;
		}
		if (scored > missed) {
			Pts += 3;
			Won++;
		}
		them = "", opp = "";
	}
	GD = GF - GA;
	int *stats = new int[8];
	stats[0] = Played;
	stats[1] = Won;
	stats[2] = Drawn;
	stats[3] = Lost;
	stats[4] = GF;
	stats[5] = GA;
	stats[6] = GD;
	stats[7] = Pts;
	return stats;
}
void sort_teams(int* Played, int* Won, int* Drawn, int* Lost, int* GF, int* GA, int* GD, int* Pts, string * teams, int n)
{
	for (int gap = n / 2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < n; i += 1)
		{
			int tempPts = Pts[i], tempPlayed = Played[i], tempWon = Won[i], tempDrawn = Drawn[i], tempLost = Lost[i], tempGF = GF[i], tempGA = GA[i], tempGD = GD[i];
			string temp_str = teams[i];
			int j;
			for (j = i; j >= gap && Pts[j - gap] < tempPts; j -= gap) {
				Pts[j] = Pts[j - gap];
				teams[j] = teams[j - gap];
				Played[j] = Played[j - gap];
				Won[j] = Won[j - gap];
				Drawn[j] = Drawn[j - gap];
				Lost[j] = Lost[j - gap];
				GF[j] = GF[j - gap];
				GA[j] = GA[j - gap];
				GD[j] = GD[j - gap];
			}
			Pts[j] = tempPts;
			teams[j] = temp_str;
			Played[j] = tempPlayed;
			Won[j] = tempWon;
			Drawn[j] = tempDrawn;
			Lost[j] = tempLost;
			GF[j] = tempGF;
			GA[j] = tempGA;
			GD[j] = tempGD;
		}
	}
}
void check_GD(int* Played, int* Won, int* Drawn, int* Lost, int* GF, int* GA, int* GD, int* Pts, string * teams, int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (Pts[j] == Pts[j + 1]) {
				if (GD[j + 1] > GD[j]) {
					swap(teams[j], teams[j + 1]);
					swap(Pts[j], Pts[j + 1]);
					swap(Played[j], Played[j + 1]);
					swap(Won[j], Won[j + 1]);
					swap(Drawn[j], Drawn[j + 1]);
					swap(Lost[j], Lost[j + 1]);
					swap(GF[j], GF[j + 1]);
					swap(GA[j], GA[j + 1]);
					swap(GD[j], GD[j + 1]);
				}
			}
		}
	}
}
