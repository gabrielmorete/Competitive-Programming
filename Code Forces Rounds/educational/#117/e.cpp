#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fst first
#define snd second

#define fr(i,n)     for (int i = 0; i < n; i++)
#define frr(i,n)    for (int i = 1; i <= n; i++)

// #define endl '\n'
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
const int MAXN = 2e5 + 10;

ll n;
vi v[MAXN];
vector<pair<ll, ll>> aux;

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n;

	int x, y;
		
	fr(i, n){
		cin>>x>>y;
		v[x].pb(y);
	}

	vi ans;
	ll p = 0, q = 1;

	frr(t, 20){
		aux.clear();

		fr(i, MAXN){
			ll sum = 0;
			for (auto x : v[i])
				sum += min(t, x);
			if (sum > 0)
				aux.pb({sum, i});
		}

		sort(all(aux));
		reverse(all(aux));//

		ll sum = 0;
		fr(i, min<int>(t, aux.size()))
			sum += aux[i].fst;

		if (sum * q > p * t){
			ans.clear();
			fr(i, min<int>(t, aux.size()))
				ans.pb(aux[i].snd);
			p = sum;
			q = t;	
		}	
	}

	cout<<ans.size()<<endl;
	for (auto x : ans)
		cout<<x<<' ';
	gnl;
}