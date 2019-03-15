#include "pch.h"
#include <iostream>
#include <string>
#include "init.h"
using namespace std;
void sort_teams(int* all_points, string * teams, int n)
{
	for (int gap = n / 2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < n; i += 1)
		{
			int temp = all_points[i];
			string temp_str = teams[i];
			int j;
			for (j = i; j >= gap && all_points[j - gap] < temp; j -= gap) {
				all_points[j] = all_points[j - gap];
				teams[j] = teams[j - gap];
			}
			all_points[j] = temp;
			teams[j] = temp_str;
		}
	}
}
string add_team(string line) {
	string team;
	for (int i = 0; i < line.find(','); i++) {
		team += line[i];
	}
	line.erase(0, line.find(','));
	return team;
}
int team_points(string line) {
	line += ',';
	string col = ":";
	int points = 0;
	string they = "", opp = "";
	int game_counter = 0;
	for (int i = 0; i < line.length(); i++) {
		if (line[i] == ':') {
			game_counter++;
		}
	}
	for (int i = 0; i < game_counter; i++) {
		int j = line.find(col);
		while (line[j-1] != ',') {
			they += line[j-1];
			j--;
		}
		j = line.find(col);
		while ((line[j+1] != ',')) {
			opp += line[j+1];
			j++;
		}
		line.erase(0, j+1);
		int tp, op;
		tp = stoi(they);
		op = stoi(opp);
		if (tp > op) {
			points += 3;
		}
		if (tp == op) {
			points++;
		}
		they = "", opp = "";
	}
	return points;
}
