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
//cout << setprecision(9)<<fixed;

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 100100;
const int MAXM = 1001000;
const ll mod=1e9+7;
const int LMAXN = 25;
int n, m, k, c[555], type[112345];

int id[112345], sz[112345];

int find(int a){
	return a == id[a]? a : id[a] = find(id[a]);
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
}

vii adj[112345];
vii adj2[555];
int memo[555][555];

int main(){
	fastio;
	cin>>n>>m>>k;

	frr(i,k)
		cin>>c[i];
	
	int cnt = 1;

	frr(i,k)
		frr(j,c[i])
			type[cnt++] = i;
	frr(i,n)
		id[i] = i, sz[i] = 1;		

	int a, b, d;

	fr(i,m) {
		cin>>a>>b>>d;
		if(d == 0){
			merge( a, b);
		}
		adj[a].pb({b, d});
		adj[b].pb({a, d});
	}


	frr(i,n - 1){
		if(type[i] == type[i + 1] and find(i) != find(i + 1)){
			cout<<"No"<<endl;
			return 0;
		}
	}	

	frr(i,n)
		for(auto x : adj[i])
			if(type[i] != type[x.fst]){
				adj2[type[i]].pb({type[x.fst], x.snd});
			}
	ms(memo, INF);

	frr(i,k)
		memo[i][i] = 0;
	frr(i,k)
		for(auto x: adj2[i])
			memo[i][x.fst] = min(memo[i][x.fst], x.snd);

	frr(l,k)
		frr(i,k)
			frr(j,k)
				memo[i][j] = min(memo[i][j], memo[i][l] + memo[l][j]);
	cout<<"Yes"<<endl;
	frr(i,k){
		frr(j,k)
			cout<<(memo[i][j] == INF? -1 : memo[i][j])<<' ';
		gnl;	
	}						
}