#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fst first
#define snd second

#define fr(i,n)     for (int i = 0; i < n; i++)
#define frr(i,n)    for (int i = 1; i <= n; i++)

#define endl '\n'
#define gnl cout << endl
#define chapa cout << "oi meu chapa" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
//cout << setprecision(9)<<fixed;

#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 1e3 + 10;
const ll mod=1e9+7;


int id[MAXN], sz[MAXN], stk[MAXN], st;

int find(int a){
	return a == id[a]? a : find(id[a]);
}

void merge(int a, int b){
	a = find(a);
	b = find(b);
	if (a == b)
		return;
	if (sz[a] < sz[b])
		swap(a, b);
	id[b] = a;
	sz[a] += sz[b];
	stk[st++] = b;
}

void rollback(){
	if (st > 0){
		int aux = stk[--st];
		sz[id[aux]] -= sz[aux];
		id[aux] = aux;
	}
}

int grid[10][10], v[10][10], n;

void print(){
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++)
			if (grid[i][j])
				cout<<'/';
			else
				cout<<'\\';
		gnl;			
	}
	exit(0); // Termina o programa
}

bool fcheck(){
	// Checa a borda direita e inferior que não 
	// são cobertas pela coloca()
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
			if (v[i][j] > 0)
				return false;	
	return true;		
}

int coord(int x, int y){
	return x * (n + 1) + y;
}

bool coloca(int x, int y, int s){
	if (s == 0){
		if (v[x - 1][y - 1] != 1 and v[x - 1][y - 1] > -1) return false;
		if (v[x][y] == 0) return false;
		if (find(coord(x - 1, y - 1)) == find(coord(x, y))) return false;
	}
	else{
		if (v[x - 1][y - 1] > 0) return false;
		if (v[x - 1][y] == 0 or v[x][y - 1] == 0) return false;
		if (find(coord(x - 1, y)) == find(coord(x, y - 1))) return false;
	}
	return true;
}

void solve(int x, int y){ // Posição do grid
	if (x == n + 1 and fcheck())
		print();

	// Próxima prosião
	int nx = x, ny = y + 1;
	if (y == n){ //
		nx++;
		ny = 1;
	}
	// Tentar coloar um \

	if (coloca(x, y, 0)){
		grid[x][y] = 0;
		v[x - 1][y - 1]--;
		v[x][y]--;
		merge(coord(x - 1, y - 1), coord(x, y));

		solve(nx, ny);
		v[x - 1][y - 1]++;
		v[x][y]++;
		rollback();
	}


	// Tenta colocar um /

	if (coloca(x, y, 1)){
		grid[x][y] = 1;
		v[x - 1][y]--;
		v[x][y - 1]--;
		merge(coord(x - 1, y), coord(x, y - 1));

		solve(nx, ny);
		v[x - 1][y]++;
		v[x][y - 1]++;
		rollback();
	}
}


int32_t main(){
	fastio;
	fr(i, MAXN){
		id[i] = i;
		sz[i] = 1;
	}
	st = 0;

	cin>>n;
	string s;

	fr(i, n + 1){
		cin>>s;
		fr(j, n + 1)
			if (s[j] == '.')
				v[i][j] = -1;
			else
				v[i][j] = s[j] - '0';
	}

	solve(1, 1);
}