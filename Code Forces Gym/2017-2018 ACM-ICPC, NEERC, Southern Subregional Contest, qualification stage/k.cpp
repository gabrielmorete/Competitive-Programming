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

ll n, a, b, k, f;

map<string, int> crd;
int cnt = 1;
int get_id(string &s){
	if (!crd.count(s))
		crd[s] = cnt++;
	
	return crd[s];
}

map<pii, ll> cst;

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin>>n>>a>>b>>k>>f;

	ll lst = -1;

	fr(i, n){
		string s, t;
		cin>>s>>t;

		int x = get_id(s);
		int y = get_id(t);

		if (x != y){ // não fala sobre no enunciado
			if (lst == x)
				cst[{min(x, y), max(x, y)}] += b;
			else
				cst[{min(x, y), max(x, y)}] += a;
		}

		lst = y;
	}

	vector<ll> v;
	for (auto e : cst)
		v.pb(e.snd);

	sort(all(v));
	reverse(all(v));

	ll ans = 0;

	for (auto e : v){
		if (k > 0)
			ans += min(e, f);
		else
			ans += e;
		k--;
	}

	cout<<ans<<endl;
}