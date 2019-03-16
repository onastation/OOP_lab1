#include "pch.h"
#include <iostream>
#include <string>
#include "init.h"
using namespace std;
void sort_teams(int* MP, int* W, int* D, int* L, int* GF, int* GA, int* GD, int* Pts, string * teams, int n)
{
	for (int gap = n / 2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < n; i += 1)
		{
			int tempPts = Pts[i], tempMP = MP[i], tempW = W[i], tempD = D[i], tempL = L[i], tempGF = GF[i], tempGA = GA[i], tempGD = GD[i];
			string temp_str = teams[i];
			int j;
			for (j = i; j >= gap && Pts[j - gap] < tempPts; j -= gap) {
				Pts[j] = Pts[j - gap];
				teams[j] = teams[j - gap];
				MP[j] = MP[j - gap];
				W[j] = W[j - gap];
				D[j] = D[j - gap];
				L[j] = L[j - gap];
				GF[j] = GF[j - gap];
				GA[j] = GA[j - gap];
				GD[j] = GD[j - gap];
			}
			Pts[j] = tempPts;
			teams[j] = temp_str;
			MP[j] = tempMP;
			W[j] = tempW;
			D[j] = tempD;
			L[j] = tempL;
			GF[j] = tempGF;
			GA[j] = tempGA;
			GD[j] = tempGD;
		}
	}
}
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
	int MP = 0, W = 0, D = 0, L = 0, GF = 0, GA = 0, GD = 0, Pts = 0;
	line += ',';
	string col = ":";
	string them = "", opp = "";
	for (int i = 0; i < line.length(); i++) {
		if (line[i] == ':') {
			MP++;
		}
	}
	for (int i = 0; i < MP; i++) {
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
			L++;
		}
		if (scored == missed) {
			Pts++;
			D++;
		}
		if (scored > missed) {
			Pts += 3;
			W+=1;
		}
		them = "", opp = "";
	}
	GD = GF - GA;
	int *stats = new int[8];
	stats[0] = MP;
	stats[1] = W;
	stats[2] = D;
	stats[3] = L;
	stats[4] = GF;
	stats[5] = GA;
	stats[6] = GD;
	stats[7] = Pts;
	return stats;
}
void check_GD(int* MP, int* W, int* D, int* L, int* GF, int* GA, int* GD, int* Pts, string * teams, int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (Pts[j] == Pts[j + 1]) {
				if (GD[j + 1] > GD[j]) {
					swap(teams[j], teams[j + 1]);
					swap(Pts[j], Pts[j + 1]);
					swap(MP[j], MP[j + 1]);
					swap(W[j], W[j + 1]);
					swap(D[j], D[j + 1]);
					swap(L[j], L[j + 1]);
					swap(GF[j], GF[j + 1]);
					swap(GA[j], GA[j + 1]);
					swap(GD[j], GD[j + 1]);
				}
			}
		}
	}
}
