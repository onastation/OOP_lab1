using namespace std;
string add_team(string line); //adds a team to the array of teams
int* team_stats(string line); //returns an array with all of the team stats
void sort_teams(int* Played, int* Won, int* Drawn, int* Lost, int* GF, int* GA, int* GD, int* Pts, string * teams, int n); //sorts teams by points
void check_GD(int* Played, int* Won, int* Drawn, int* Lost, int* GF, int* GA, int* GD, int* Pts, string * teams, int n); //sorts teams with identical points according to goal difference