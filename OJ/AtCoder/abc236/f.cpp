#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fst first
#define snd second

#define fr(i,n)     for (int i = 0; i < n; i++)
#define frr(i,n)    for (int i = 1; i <= n; i++)

#define endl '\n'
#define gnl cout << endl
#define chapa cout << "oi meu chapa" << endl

#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(), x.end()

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 4e5 + 10;

int n;
vector<pair<ll, ll>> v;

ll lsb[MAXN], ans;
vector<ll> base;


signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin>>n;

	n = (1<<n) - 1;

	frr(i, n){
		ll x;
		cin>>x;
		v.pb({x, i});
	}

	sort(all(v));

	for (auto x : v){
		ll a = x.snd;

		fr(i, base.size()){
			if (a&(1<<lsb[i]))
				a ^= base[i];
		}

		if (a != 0){
			int l = 0;

			while ( (a&(1<<l)) == 0)
				l++;

			lsb[base.size()] = l;
			base.pb(a);
				ans += x.fst;
		}
	}

	cout<<ans<<endl;
}