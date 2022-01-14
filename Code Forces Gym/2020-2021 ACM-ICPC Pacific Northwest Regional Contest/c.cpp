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

#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(), x.end()

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 1e2 + 10;

int n, m, r, b, y;
vector<pair<int, char>> adj[MAXN];
bool vis[MAXN][MAXN][MAXN], used[MAXN][MAXN];


typedef tuple<int, int, int> tup;

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n>>m;
	cin>>r>>b>>y;

	int a, f;
	char c;

	fr(i, m){
		cin>>a>>f>>c;
		adj[a].pb({f, c});
		adj[f].pb({a, c});
	}

	queue<tup> fila;

	fila.push({r, b, y});
	vis[r][b][y] = 1;

	string s = "RBYPGOX";

	tup aux;
	int v[3];
	while (!fila.empty()){
		aux = fila.front();
		fila.pop();

		tie(v[0], v[1], v[2]) = aux; // red, blue, yellow

		fr(i, 3){
			for (auto x : adj[v[i]])
				if ((x.snd == s[i] or x.snd == s.back())){
					used[v[i]][x.fst] = 1;
					v[i] = x.fst;
					if (!vis[v[0]][v[1]][v[2]]){
						vis[v[0]][v[1]][v[2]] = 1;
						fila.push({v[0], v[1], v[2]});
					}

					tie(v[0], v[1], v[2]) = aux;
				}
		}

		fr(i, 3)
			if (v[i] == v[(i + 1)%3])
				for (auto x : adj[v[i]])
					if (x.snd == s[i + 3] or x.snd == s.back()){
						used[v[i]][x.fst] = 1;
						v[i] = v[(i + 1)%3] = x.fst;
						if (!vis[v[0]][v[1]][v[2]]){
							vis[v[0]][v[1]][v[2]] = 1;
							fila.push({v[0], v[1], v[2]});
						}

						tie(v[0], v[1], v[2]) = aux;
					}
	}

	bool ok = 1;
	frr(i, n)
		for (auto x : adj[i])
			if (!used[i][x.fst] and x.snd != s.back())
				ok = 0;

	cout<<ok<<endl;
}