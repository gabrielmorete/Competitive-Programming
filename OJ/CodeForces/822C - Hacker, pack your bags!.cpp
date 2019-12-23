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

int n, peri;
typedef tuple<int, int, int> tup;
vector<tup> v;
vi bs[212345];
vii u[212345];

int main(){
	fastio;
	cin>>n>>peri;

	int l, r, cst;
	fr(i,n){
		cin>>l>>r>>cst;
		v.pb({l,r,cst});	
		u[r - l + 1].pb({l, cst});
	}

	fr(i,212345)
		sort(all(u[i]));
	fr(i,212345){
		for (auto x : u[i])
			bs[i].pb(x.fst);
	}	

	fr(i,212345){
		if (u[i].empty())
			continue;
		int t = u[i].size() - 1;
		int aux = INF;

		for (int j = t; j >= 0; j--){
			aux = min( aux, u[i][j].snd);
			u[i][j].snd = aux;
		}
	}	

	ll best = llINF;


	for (auto x : v){
		l = get<0>(x);
		r = get<1>(x);
		cst = get<2>(x);
		int p = r - l + 1;
		p = peri - p;

		if (p <= 0)
			continue;

		if (u[p].empty())
			continue;
		auto it = lower_bound(all(bs[p]), r + 1);

		if (it == bs[p].end())
			continue;
		else{
			int pos = (int)(it - bs[p].begin());
			best = min<ll>( best, cst + u[p][pos].snd);
		}
	}
	if (best == llINF)
		cout<<-1<<endl;
	else
		cout<<best<<endl;	

}