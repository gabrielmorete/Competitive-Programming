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

map<string,int> dic;
map<int,string> rdic;

vi adj[112];
int pre[112], lo[112], pa[112], cut[112];
int clk, n;

void dfsRc(int v){
	pre[v] = lo[v] = clk++;
	int chd = 0;
	bool any = 0;
	for (int x : adj[v]) {
		if (pre[x] == -1){
			pa[x] = v;
			dfsRc(x);
			chd++;
			lo[v] = min(lo[v], lo[x]);
			if (lo[x] >= pre[v])
				any = true;
		}
		else if (x != pa[v])
			lo[v] = min( lo[v], pre[x]);
	}
	if (v == pa[v] and chd >= 2)
		cut[v] = true;
	if (v != pa[v] and any)
		cut[v] = true;
}

void findc(){
	frr(v,n)
		pre[v] = -1, cut[v] = 0;
	clk = 0;
	frr(v,n)
		if (pre[v] == -1){
			pa[v] = v;
			dfsRc( v);
		}	
}

int main(){
	fastio;
	cin>>n;
	int tst = 1;
	while (n){
		dic.clear();
		rdic.clear();
		frr(i,n)
			adj[i].clear();

		vector<string> s;
		s.clear();
		string t;
		frr(i,n){
			cin>>t;
			s.pb(t);
		}

		sort(all(s));
		fr(i,n){
			dic[s[i]] = i + 1;
			rdic[i + 1] = s[i];
		}

		int m;
		cin>>m;

		string y;

		fr(i,m){
			cin>>t>>y;
			adj[dic[t]].pb(dic[y]);
			adj[dic[y]].pb(dic[t]);
		}

		findc();
		int ans = 0;
		frr(i,n)
			ans += cut[i];

		cout<<"City map #"<<tst++<<": "<<ans<<" camera(s) found"<<endl;	
		frr(i,n)
			if (cut[i])
				cout<<rdic[i]<<endl;
		cin>>n;
		if (n)
			gnl;
	}
}