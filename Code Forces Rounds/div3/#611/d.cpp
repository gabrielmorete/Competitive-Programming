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

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 2e5 + 10;
const ll mod=1e9+7;

ll n, m, v[MAXN], pos[MAXN], dist;
map<int, int> vis;

void bfs(){
	queue<pii> fila;
	fr(i, n){
		fila.push({v[i], 0});
		vis[v[i]] = 1;
	}

	ll x, y;
	pii aux;
	int cnt = 0;
	while (cnt < m){
		aux = fila.front();
		fila.pop();
		x = aux.fst; y = aux.snd;

		if (vis[x - 1] == 0 and cnt < m){
			vis[x - 1] = 1;
			pos[cnt++] = x - 1;
			dist += y + 1ll;
			fila.push({x - 1, y + 1});
		}
		if (vis[x + 1] == 0 and cnt < m){
			vis[x + 1] = 1;
			pos[cnt++] = x + 1;
			dist += y + 1ll;
			fila.push({x + 1, y + 1});
		}
	}
}

int32_t main(){
	fastio;
	cin>>n>>m;
	fr(i, n)
		cin>>v[i];

	bfs();

	cout<<dist<<endl;
	fr(i, m)
		cout<<pos[i]<<' ';
	gnl;	
}