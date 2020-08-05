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
const int MAXN = 2e5 + 10;
const ll mod=1e9+7;

ll n, v[MAXN], soma[MAXN], rep[MAXN];

map<ll, ll> freq;

int32_t main(){
	fastio;

	cin>>n;
	frr(i, n){
		cin>>v[i];
		v[i] += v[i - 1];
	}

	fill(rep, rep + n + 1, n + 1);

	fr(i, n + 1){
		if (!freq.count(v[i]))
			freq[v[i]] = i;
		else{
			rep[freq[v[i]]] = i;
			freq[v[i]] = i;
		}
	}

	ll ans = 0;
	ll aux = n + 1;
	for(int i = n; i >= 0; i--){
		aux = min(aux, rep[i]);
		rep[i] = aux;
	
		ans += (ll) (rep[i] - i - 1);
	}

	cout<<ans<<endl;
}