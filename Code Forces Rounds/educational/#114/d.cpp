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
const int MAXN = 1e5 + 10;

ll n, m, c[11];
vector<ll> a[11];


const ll mod1 = 1000015553; // primo grande 1
const ll mod2 = 1000028537; // primo grande 2

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count()); // Gerador aleatório
static ll p = uniform_int_distribution<int>(200001, mod1 - 1)(rng);	// Caso TL usa const p
ll pwr1[11], pwr2[11];


pair<ll, ll> gen_hash(vector<ll> &v){
	ll hsh1 = v[0];
	ll hsh2 = v[0];
	for (int i = 1; i < n; i++){
		hsh1 = (hsh1 * p + (ll)(v[i]))%mod1;
		hsh2 = (hsh2 * p + (ll)(v[i]))%mod2;
	}
	return {hsh1, hsh2};
}

typedef tuple<ll, pair<ll, ll>, vector<ll>> tup;

set<pair<ll, ll>> nope, vis;

ll incval = 0;
vector<ll> inc;

void dij(){
	vector<ll> s(n);
	fr(i, n)
		s[i] = c[i];

	ll val = 0;
	fr(i, n)
		val += a[i].back();

	pair<ll, ll> hsh = gen_hash(s); 

	priority_queue< tup > pq;
	pq.push({val, hsh, s});

	while (!pq.empty()){
		tie(val, hsh, s) = pq.top();
		pq.pop();

		if (!vis.count(hsh)){
			vis.insert(hsh);

			if (!nope.count(hsh)){
				fr(i, n)
					cout<<s[i]<<' ';
				gnl;
				exit(0);
			}
			else{
				fr(i, n){
					if (s[i] > 1){
						s[i]--;
						hsh = gen_hash(s);
						ll aux = 0;
						fr(i, n)
							aux += a[i][s[i] - 1];

						if (!vis.count(hsh) and val > incval){
							pq.push({aux, hsh, s});
						}	

						s[i]++;
					}
				}
			}
		}	
	}
}


signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n;
	
	fr(i, n){
		cin>>c[i];
		a[i].resize(c[i]);
		fr(j, c[i])
			cin>>a[i][j];
	}


	pwr1[0] = pwr2[0] = 1;
	for (int i = 1; i < n; i++){
		pwr1[i] = (p * pwr1[i - 1]) % mod1;
		pwr2[i] = (p * pwr2[i - 1]) % mod2;
	}


	cin>>m;

	fr(i, m){
		vector<ll> b(n);
		fr(i, n)
			cin>>b[i];
		pair<ll, ll> pl = gen_hash(b);
		nope.insert(pl);	
	}

	inc.resize(n);

	dij();

	fr(i, n)
		cout<<inc[i]<<' ';
	gnl;
}