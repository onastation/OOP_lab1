#include "pch.h"
#include <iostream>
#include <fstream>
#include <sstream>
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
		int* all_points = new int[num];
		while (getline(game_results, line))
		{
			teams[k] = add_team(line);
			all_points[k] = team_points(line);
			k++;
		}
		sort_teams(all_points, teams, num);
		for (int i = 0; i < num; i++) {
			final_table << teams[i] << "," << all_points[i] << endl;
			cout << teams[i] << ' ' << all_points[i] << endl;
		}
		game_results.close();
		final_table.close();
	}
	else cout << "Unable to open file";
	cout << "kek";
	system("pause");
}
