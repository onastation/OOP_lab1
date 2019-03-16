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
		int* MP = new int[num];
		int* W = new int[num];
		int* D = new int[num];
		int* L = new int[num];
		int* GF = new int[num];
		int* GA = new int[num];
		int* GD = new int[num];
		int* Pts = new int[num];
		while (getline(game_results, line))
		{
			int *stats = team_stats(line);
			teams[k] = add_team(line);
			MP[k] = stats[0];
			W[k] = stats[1];
			D[k] = stats[2];
			L[k] = stats[3];
			GF[k] = stats[4];
			GA[k] = stats[5];
			GD[k] = stats[6];
			Pts[k] = stats[7];
			k++;
		}
		sort_teams(MP, W, D, L, GF, GA, GD, Pts, teams, num);
		final_table << "Club" << ',' << "MP" << ',' << "W" << ',' << "D" << ',' << "L" << ',' << "GF" << ',' << "GA" << ',' << "GD" << ',' << "Pts" << endl;
		cout << left << setw(25) << "Club" << setw(5) << "MP" << setw(5) << "W" << setw(5) << "D" << setw(5) << "L" << setw(5) << "GF" << setw(5) << "GA" << setw(5) << "GD" << setw(5) << "Pts" << endl;
		for (int i = 0; i < num; i++) {
			final_table << teams[i] << "," << MP[i] << "," << W[i] << "," << D[i] << "," << L[i] << "," << GF[i] << "," << GA[i] << "," << GD[i] << "," << Pts[i] << endl;
			cout << left << setw(25) << teams[i] << setw(5) << MP[i] << setw(5) << W[i] << setw(5) << D[i] << setw(5) << L[i] << setw(5) << GF[i] << setw(5) << GA[i] << setw(5) << GD[i] << setw(5) << Pts[i] << endl;
		}
		game_results.close();
		final_table.close();
	}
	else cout << "Unable to open file";
	cout << "kek";
	system("pause");
}
