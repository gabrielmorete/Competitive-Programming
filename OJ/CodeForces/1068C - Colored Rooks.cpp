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

int n, m;
vii edge;
vii pos[110];

int main(){
	fastio;
	cin>>n>>m;

	int a, b;
	fr(i, m){
		cin>>a>>b;
		edge.pb({a, b});
	}
	frr(i, n)
		pos[i].pb({i, i});
	int col = n + 1;
	
	for (pii x : edge){
		pos[x.fst].pb({x.fst, col});
		pos[x.snd].pb({x.snd, col});
		col++;
	}

	frr(i, n){
		cout<<pos[i].size()<<endl;
		for (pii x : pos[i])
			cout<<x.fst<<' '<<x.snd<<endl;
	}	
}