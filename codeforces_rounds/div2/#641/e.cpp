#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fst first
#define snd second

#define fr(i,n)     for(int i=0;i<n;i++)
#define frr(i,n)    for(int i=1;i<=n;i++)

#define ms(x,i) memset(x,i,sizeof(x))
#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()

#define gnl cout << endl
#define chapa cout << "oi meu chapa" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
//cout << setprecision(9)<<fixed;

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 1e5 + 10;
const ll mod=1e9+7;

int mx[4] = {1, -1, 0, 0};
int my[4] = {0, 0, -1, 1};
int n, m, q;

bool valid(int x, int y){
	if (x < 0 or y < 0)
		return false;
	if (x >= n or y >= m)
		return false;
	return true;
}

bool mapa[1010][1010];
int dist[1010][1010];

int32_t main(){
	fastio;
	
	cin>>n>>m>>q;

	string s;
	fr(i, n){
		cin>>s;
		fr(j, m)
			mapa[i][j] = s[j] - '0'; 
	}

	ms(dist, -1);

	queue<pii> fila;

	fr(i, n)
		fr(j, m)
			fr (k, 4)
				if (valid(i + mx[k], j + my[k]) and mapa[i][j] == mapa[i + mx[k]][j + my[k]])
					fila.push({i, j}), dist[i][j] = 0;

	pii aux;			
	while (!fila.empty()) {
		aux = fila.front();
		fila.pop();

		fr(k, 4)
			if (valid(aux.fst + mx[k], aux.snd + my[k]) and dist[aux.fst + mx[k]][aux.snd + my[k]] == -1)
				fila.push({aux.fst + mx[k], aux.snd + my[k]}), dist[aux.fst + mx[k]][aux.snd + my[k]] = dist[aux.fst][aux.snd] + 1;
	}
	
	ll a, b, p;			
	while (q--){
		cin>>a>>b>>p;
		a--;b--;

		if (dist[a][b] == -1){
			cout<<mapa[a][b]<<endl;
			continue;
		}

		p -= (ll)dist[a][b];
		
		if (p < 0 or p % 2 == 0)
			cout<<mapa[a][b]<<endl;
		else
			cout<<!mapa[a][b]<<endl;
	}
}