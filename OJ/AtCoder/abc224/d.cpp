#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fst first
#define snd second

#define fr(i,n)     for (int i = 0; i < n; i++)
#define frr(i,n)    for (int i = 1; i <= n; i++)

// #define endl '\n'
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
const int MAXN = 1e5 + 10;

ll pwr[14];
int m;
vi adj[10];

map<ll, int> dist;

vector<ll> get_adj(ll v){
	int p = 0;
	ll aux = v;
	while (aux % 10 != 0){
		p++;
		aux /= 10;
	}

	// p é a posiçao do zero

	vector<ll> ans;

	for (auto x : adj[p]){
		ll k = v%pwr[x + 1];
		k /= pwr[x];
		aux = v - k*pwr[x];// zera essa entrada
		aux += k * pwr[p];
		ans.pb(aux);
	}

	return ans;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>m;

	int x, y;
	fr(i, m){
		cin>>x>>y;
		x--;
		y--;
		adj[x].pb(y);
		adj[y].pb(x);
	}

	pwr[0] = 1;
	frr(i, 13)
		pwr[i] = pwr[i - 1] * 10;	

	ll en = 0;
	frr(i, 8){
		cin>>x;
		en += pwr[x - 1]*(ll)(i); // mask final	
	}

	ll st = 0;
	frr(i, 8){
		st += (ll)(i) * pwr[i - 1];
	}	

	queue<ll> fila;
	fila.push(st);
	dist[st] = 0;

	ll v;
	while (!fila.empty()){
		v = fila.front();
		fila.pop();

		if (v == en){
			cout<<dist[en]<<endl;
			return 0;
		}

		vector<ll> a = get_adj(v);

		for (auto x : a)
			if (!dist.count(x)){
				dist[x] = dist[v] + 1;
				fila.push(x);
			}
	}

	cout<<-1<<endl;
}