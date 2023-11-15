#include <iostream>
#include <cstring>
#define filein() freopen("test.inp", "r", stdin);
#define fileout() freopen("test.out", "w", stdout);
#define N 1001
using namespace std;

char adj[N][N];
bool visited_x[N][N];
bool visited_o[N][N];
char res[N][N];
int n, m;
int dx[8] = {-1, -1, -1, 1, 1, 1, 0, 0};
int dy[8] = {0, -1, 1, -1, 0, 1, 1, -1};

void dfs(int a, int b, char s){
	if(s == 'x')
		visited_x[a][b] = true;
	else if(s == 'o')
		visited_o[a][b] = true;
	for(int i = 0; i < 8; i++){
		int x = a + dx[i];
		int y = b + dy[i];
		if(s == 'x'){
			if(x > 0 && x < n && y > 0 && y < m && adj[x][y] == s && !visited_x[x][y])
				dfs(x, y, s);
		}
		else if(s == 'o'){
			if(x > 0 && x < n && y > 0 && y < m && adj[x][y] == s && !visited_o[x][y])
				dfs(x, y, s);
		}
	}
}

void input(){
	cin >> n >> m;
	memset(visited_x, false, sizeof(visited_x));
	memset(visited_o, false, sizeof(visited_o));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			char s; cin >> s;
			adj[i][j] = s;
			//cout << adj[i][j] << " ";
		}
		//cout << endl << endl;
	}
	//cout << endl << endl;
}

void check_x(){
	char s = 'x';
	for(int i = 0; i < m; i++){
		if(adj[0][i] == 'x' && !visited_x[0][i])
			dfs(0, i, s);
		if(adj[n - 1][i] == 'x' && !visited_x[n - 1][i])
			dfs(n - 1, i, s);
	}
	for(int i = 0; i < n; i++){
		if(adj[i][0] == 'x' && !visited_x[i][0])
			dfs(i, 0, s);
		if(adj[i][m - 1] == 'x' && !visited_x[i][m - 1])
			dfs(i, m - 1, s);
	}
}

void check_o(){
	char s = 'o';
	for(int i = 0; i < m; i++){
		if(adj[0][i] == 'o' && !visited_o[0][i])
			dfs(0, i, s);
		if(adj[n - 1][i] == 'o' && !visited_o[n - 1][i])
			dfs(n - 1, i, s);
	}
	for(int i = 0; i < n; i++){
		if(adj[i][0] == 'o' && !visited_o[i][0])
			dfs(i, 0, s);
		if(adj[i][m - 1] == 'o' && !visited_o[i][m - 1])
			dfs(i, m - 1, s);
	}
}

void count_x(){
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++){		
			if(!visited_x[i][j] && adj[i][j] == 'x')
				res[i][j] = 'o';
			else if(visited_x)
				res[i][j] = 'x';
		}
}

void count_o(){
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++){
			if(!visited_o[i][j] && adj[i][j] == 'o')
				res[i][j] = 'x';
			else if(visited_o[i][j])
				res[i][j] = 'o';
		}
}

void inres(){
	cout << "result: " << endl;
	for(int i = 0; i < n; i++){
		cout << "       ";
		for(int j = 0; j < m; j++)
			cout << res[i][j] << "   ";
		cout << endl << endl;
	}
}

void winner(){
	int cnt_o = 0;
	int cnt_x = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(res[i][j] == 'x')
				cnt_x++;
			else
				cnt_o++;
	cout << "x  score: " << cnt_x << endl;
	cout << "o  score: " << cnt_o << endl;
	if(cnt_x > cnt_o)
		cout << "		player x WIN";
	else if(cnt_x < cnt_o)
		cout << "		player o WIN";
	else
		cout << "		DRAW";
}

int main(){
	filein(); fileout();
	// input();
	// check_x();
	// for(int i = 0; i < n; i++){
	// 	for(int j = 0; j < m; j++)
	// 		cout << visited_x[i][j];
	// 	cout << endl;
	// }
	input();
	check_x(); check_o();
	count_x(); count_o();
	inres();
	winner();
	return 0;
}