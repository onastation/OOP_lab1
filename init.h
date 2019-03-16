using namespace std;
string add_team(string line);
int* team_stats(string line);
void sort_teams(int* MP, int* W, int* D, int* L, int* GF, int* GA, int* GD, int* Pts, string * teams, int n);
void check_GD(int* MP, int* W, int* D, int* L, int* GF, int* GA, int* GD, int* Pts, string * teams, int n);