#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fst first
#define snd second

#define fr(i,n)     for (int i = 0; i < n; i++)
#define frr(i,n)    for (int i = 1; i <= n; i++)

//#define endl '\n'
#define gnl cout << endl
#define chapa cout << "oi meu chapa" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
//cout << setprecision(9)<<fixed;

#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 1e5 + 10;

typedef pair<ll, ll> pll;

ll in[MAXN], out[MAXN];

vector<ll> e, s;

int32_t main(){
	fastio;
	int n, m;
	ll x;

	cin>>n>>m;

	ll a, b;
	fr(i, m){
		cin>>a>>b>>x;
		out[a] += x;
		in[b] += x;
	}	

	frr(i, n){
		if (in[i] > out[i])
			e.pb(i);
		else
			s.pb(i);

		out[i] -= in[i];
		out[i] = max(out[i], -out[i]);
	}	

	vector< tuple<ll,ll,ll> > ans;

	for (auto a : s){
		while (out[a]){
			b = e.back();
			e.pop_back();

			ll mn = min(out[a], out[b]);
			out[a] -= mn; 
			out[b] -= mn;

			ans.pb({a, b, mn});

			if (out[b])
				e.pb(b);
		}
	}

	cout<<ans.size()<<endl;
	for (auto t : ans){
		tie(a, b, x) = t;
		cout<<a<<' '<<b<<' '<<x<<endl;
	}
}