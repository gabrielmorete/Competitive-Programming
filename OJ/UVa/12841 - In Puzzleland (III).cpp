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
vi adj[20];
char label[20];
int rlabel[300];
string memo[35000][16];

string pd(int mask, int node){
	if(node == 0){
		if (mask != 0)
			return "z";
		else{
			string s;
			s.pb(label[0]);
			return s;
		}
	}

	string &pdm = memo[mask][node];
	if (pdm != " ")
		return pdm;
	for (int i : adj[node])
		if (mask & (1 << i)){
			string aux = pd(mask ^ (1<<i), i);
			if (aux != "z"){
				if (pdm == " ")
					pdm = aux;
				else
					pdm = min(pdm, aux);
			}
		}
	
	if (pdm == " ")
		pdm = "z";	
	else
		pdm += label[node];

	return pdm;
}


void solve( int cse){
	fr(i,20)
		adj[i].clear();
	for (int i = 0; i < 35000; i++)
		for (int j = 0; j < 16; j++)
			memo[i][j] = " ";

	cin>>n>>m;



	fr(i,n){
		cin>>label[i];
		rlabel[label[i]] = i;
	}

	char x, y;
	fr(i,m){
		cin>>x>>y;
		adj[rlabel[x]].pb(rlabel[y]);
		adj[rlabel[y]].pb(rlabel[x]);
	}

	int mask = (1<<(n - 1)) - 1; 
	cout<<"Case "<<cse<<": ";
	cout<<(pd( mask, n - 1) == "z"? "impossible" : pd( mask, n - 1))<<endl;

}

int main(){
	fastio;
	int t;
	cin>>t;
	frr(i, t)
		solve(i);
}