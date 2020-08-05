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
const int MAXN = 2e5 + 10;
const ll mod=1e9+7;

typedef tuple<int, int, int> tup;
int v[MAXN];

void solve(){
	int n;
	cin>>n;

	set<tup> q;
	q.insert({-n, 1, n});

	int t, l, r, p, cnt;
	cnt = 1;
	tup aux;
	while (!q.empty()){
		aux = *q.begin();
		q.erase(q.begin());
		t = -get<0>(aux); l = get<1>(aux); r = get<2>(aux);

		if (t % 2)
			p = (l + r)/2; 
		else
			p = (l + r - 1)/2;

		v[p] = cnt++;

		if (p > l){
			q.insert({-(p - l), l, p - 1});
		}
		if (p < r){
			q.insert({-(r - p), p + 1, r});
		}
	}

	frr(i, n)
		cout<<v[i]<<' ';
	gnl;	
}

int32_t main(){
	fastio;
	int T;
	cin>>T;
	while (T--)
		solve();
}