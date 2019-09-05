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
const int LMAXN = 20;

int ned, first[MAXN], work[MAXN], dist[MAXN], q[MAXN];
int cap[MAXM], to[MAXM], nxt[MAXM];

void init() {
   memset(first, -1, sizeof first);
   ned = 0;
}

void add(int u, int v, int f) {
	to[ned] = v, cap[ned] = f;
	nxt[ned] = first[u];
	first[u] = ned++;
	
	to[ned] = u, cap[ned] = 0;
	nxt[ned] = first[v];
	first[v] = ned++;
}

int dfs(int u, int f, int t) {
	if (u == t) return f;
	for(int &e = work[u]; e != -1; e = nxt[e]) {
		int v = to[e];
		if (dist[v] == dist[u] + 1 && cap[e] > 0) {
			int df = dfs(v, min(f, cap[e]), t);
			if (df > 0) {
				cap[e] -= df;
				cap[e^1] += df;
				return df;
			}
		}
	}
	return 0;
}

bool bfs(int s, int t) {
	memset(&dist, -1, sizeof dist);
	dist[s] = 0;
	int st = 0, en = 0;
	q[en++] = s;
	while (en > st) {
		int u = q[st++];
		for(int e = first[u]; e!=-1; e = nxt[e]) {
			int v = to[e];
			if (dist[v] < 0 && cap[e] > 0) {
				dist[v] = dist[u] + 1;
				q[en++] = v;
			}
		}
	}
	return dist[t] >= 0;
}

int dinic(int s, int t) {
	int result = 0, f;
	while (bfs(s, t)) {
		memcpy(work, first, sizeof work);
		while (f = dfs(s, INF, t)) result += f;
	}
	return result;
}


void solve( int n, int m, int g) {

	int gms[111][111], pnts[111];
	fr(i,111) 
		fr(j,111) 
			gms[i][j] = m;
	
	fr(i,111) pnts[i] = 0;

	init();

	fr(i,n) gms[i][i] = 0;

	int src, snk;
	src = 100;
	snk = 101;

	int a, b;
	string s;
	fr(i,g){
		cin>>a>>s>>b;
		if(s == "="){
			pnts[a]++;
			pnts[b]++;
			gms[a][b]--;
			gms[b][a]--;
		}
		else{

			pnts[b] += 2;
			gms[a][b]--;
			gms[b][a]--;			

		}
	}


	frr(i,n-1)
		if(gms[0][i]){
			pnts[0] += 2*gms[0][i];
			gms[0][i] = 0;
			gms[i][0] = 0;
		}

	frr(i, n-1){
		if(pnts[0] > pnts[i]){
			add( 50 + i, snk, pnts[0] - pnts[i] - 1);
		}
		else{
			cout<<'N'<<endl;
			return;
		}
	}	

	int tot = 0;
	int falta;
	for (int i = 1; i < n; i++){
		falta = 0;
		for (int j = i + 1; j < n; j++) {
			for (int k = 0; k < gms[i][j]; k++) {
				falta += 2;
				add( i, 50 + i, 2);
				add( i, 50 + j, 2);
			}
		}
		if(falta)
			add( src, i, falta);
		tot += falta;
	}

	int mf = dinic( src, snk);	
	if (mf >= tot)
		cout<<'Y'<<endl;
	else
		cout<<'N'<<endl;
}

int main(){
	fastio;
	int n, m, g;
	cin>>n>>m>>g;
	while (n != 0){ 
		solve( n, m, g);
		cin>>n>>m>>g;
	}	

}