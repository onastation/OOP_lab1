#include "pch.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "init.h"
using namespace std;
int main() {
	string line;
	ifstream game_results("premier_league.csv");
	ofstream final_table("results.csv");
	if (game_results.is_open())
	{
		getline(game_results, line);
		int num = stoi(line), k = 0;
		string* teams = new string[num];
		int *stats;
		int* Played = new int[num];
		int* Won = new int[num];
		int* Drawn = new int[num];
		int* Lost = new int[num];
		int* GF = new int[num]; //goals for
		int* GA = new int[num]; //goals against
		int* GD = new int[num]; //goal difference
		int* Pts = new int[num]; //points
		while (getline(game_results, line))
		{
			int *stats = team_stats(line);
			teams[k] = add_team(line);
			Played[k] = stats[0];
			Won[k] = stats[1];
			Drawn[k] = stats[2];
			Lost[k] = stats[3];
			GF[k] = stats[4];
			GA[k] = stats[5];
			GD[k] = stats[6];
			Pts[k] = stats[7];
			k++;
		}
		sort_teams(Played, Won, Drawn, Lost, GF, GA, GD, Pts, teams, num);
		check_GD(Played, Won, Drawn, Lost, GF, GA, GD, Pts, teams, num);
		final_table << "Club" << ',' << "Played" << ',' << "Won" << ',' << "Drawn" << ',' << "Lost" << ',' << "GF" << ',' << "GA" << ',' << "GD" << ',' << "Pts" << endl;
		cout << left << setw(25) << "Club" << setw(9) << "Played" << setw(9) << "Won" << setw(9) << "Drawn" << setw(9) << "Lost" << setw(9) << "GF" << setw(9) << "GA" << setw(9) << "GD" << setw(9) << "Pts" << endl;
		for (int i = 0; i < num; i++) {
			final_table << teams[i] << "," << Played[i] << "," << Won[i] << "," << Drawn[i] << "," << Lost[i] << "," << GF[i] << "," << GA[i] << "," << GD[i] << "," << Pts[i] << endl;
			cout << left << setw(25) << teams[i] << setw(9) << Played[i] << setw(9) << Won[i] << setw(9) << Drawn[i] << setw(9) << Lost[i] << setw(9) << GF[i] << setw(9) << GA[i] << setw(9) << GD[i] << setw(9) << Pts[i] << endl;
		}
		game_results.close();
		final_table.close();
	}
	else cout << "Unable to open file";
	system("pause");
}
