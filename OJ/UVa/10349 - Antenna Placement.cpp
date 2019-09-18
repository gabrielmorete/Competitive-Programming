#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
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

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;  
const int MAXN = 100100;
const int MAXM = 1001000;
const ll mod=1e9+7;
const int LMAXN = 25;

int ned;
int first[MAXN], work[MAXN], dist[MAXN], q[MAXN];
int to[MAXM], nxt[MAXM], cap[MAXM];

void init() {
	memset( first, -1, sizeof first);
	ned = 0;
}

void add( int u, int v, int f) {
	to[ned] = v; cap[ned] = f;
	nxt[ned] = first[u];
	first[u] = ned++;

	to[ned] = u; cap[ned] = 0;
	nxt[ned] = first[v];
	first[v] = ned++;
}

int dfs( int u, int t, int f) {
	if (u == t) return f;

	for (int &e = work[u]; e != -1; e = nxt[e]) {
		int v = to[e];
		if (dist[v] == dist[u] + 1 and cap[e] > 0) {
			int df = dfs( v, t, min(f, cap[e]));
			if (df > 0) {
				cap[e] -= df;
				cap[e^1] += df;
				return df;
			}

		}
	}
	return 0;
}

bool bfs( int s, int t) {
	memset(dist, -1, sizeof dist);
	int st = 0, en = 0;
	dist[s] = 0;
	q[en++] = s;

	while( en > st) {
		int u = q[st++];

		for (int e = first[u]; e != -1; e = nxt[e]) {
			int v = to[e];
			if(dist[v] < 0 and cap[e] > 0) {
				dist[v] = dist[u] + 1;
				q[en++] = v;
			}
		}
	}
	return dist[t] >= 0;
}

int dinic( int s, int t) {
	int res = 0, f;
	while (bfs( s, t)){
		memcpy( work, first, sizeof work);
		while (f = dfs( s, t, INF))
			res += f;
	}
	return res;
}

int mx[4] = {-1,0,1,0};
int my[4] = {0,1,0,-1};

int mapa[44][44];
int h, w;

int to_g(int x, int y) {
	return x*w + y;
}

bool valid (int x, int y) {
	if (x < 0 or y < 0)
		return 0;
	if (x >= h or y >= w)
		return 0;
	return 1;
}

bool alone(int x, int y) {

	fr(k,4)
		if ( valid( x + mx[k], y + my[k]) and mapa[x + mx[k]][y + my[k]] )
			return 0;

	return 1;
}

void solve() {
	init();
	int snk, src;
	cin>>h>>w;

	src = h*w + 10;
	snk = h*w + 20;

	string s;
	fr(i,h){
		cin>>s;
		fr(j,s.size())
			mapa[i][j] = (s[j] == '*')? 1 : 0;
	}

	int ans = 0;

	fr(i,h)
		fr(j,w){
			//não é importante
			if (!mapa[i][j])
				continue;

			//está isolado, precisa de uma antena
			if (alone(i,j)){
				ans++;
				continue;
			}
			//tabuleiro de xadrez, pretas recebem, brancas enviam
			if ((i + j) % 2 == 0){
				add( to_g(i,j), snk, 1);
				continue;
			}

			add( src, to_g(i,j), 1);

			fr(k,4){
				if (valid( i + mx[k], j + my[k]) and mapa[i + mx[k]][j + my[k]]){
					add( to_g(i,j), to_g(i + mx[k], j + my[k]), 1);
				}
			}
				

		}
		
	ans += dinic( src, snk);

	//soma os que não foram cobertos
	for (int e = first[snk]; e != -1; e = nxt[e]) 
		if(cap[e] == 0)
			ans++;
	//soma os que não conseguiram cobrir	
	for (int e = first[src]; e != -1; e = nxt[e]) 
		if(cap[e] != 0)
			ans++;	
	

	cout<<ans<<endl;
}

int main(){
	fastio;
	int t;
	cin>>t;
	while (t--) solve();

}