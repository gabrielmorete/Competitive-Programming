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
const int MAXN = 1e6 + 10;

int n, m, k, lid[MAXN], cid[MAXN];
vi lin, col;


map<int, ll> lf, cf;
map<pair<int, int>, ll> leq, ceq;


int rec_lin(ll x){
	int p = (int)(lower_bound(all(lin), x) - lin.begin());
	return p - 1;
}


int rec_col(ll x){
	int p = (int)(lower_bound(all(col), x) - col.begin());
	return p - 1;
}

void clean(){
	for (auto x : lin)
		lid[x] = 0;
	for (auto x : col)
		cid[x] = 0;
	lin.clear();
	col.clear();
	lf.clear();
	cf.clear();
	leq.clear();
	ceq.clear();
}

ll comb(ll a){
	return (a * (a - 1))/2;
}

void solve(){
	clean();

	cin>>n>>m>>k;

	int x, y;
	frr(i, n){
		cin>>x;
		lid[x] = i;
		lin.pb(x);
	}

	frr(i, m){
		cin>>x;
		cid[x] = i;
		col.pb(x);
	}

	fr(i, k){
		cin>>x>>y;

		if (lid[x] != 0 and cid[y] != 0)
			continue;

		if (lid[x] == 0){ // na coluna
			int aux = rec_lin(x);
			cf[aux]++; //indexado pela esquerda, nessa coluna
			ceq[{aux, y}]++;
		}
		else{ // na linha
			int aux = rec_col(y);
			lf[aux]++; //indexado por baixo, nessa linha
			leq[{aux, x}]++;
		}
	}

	ll ans = 0;

	for (auto e : lf)
		ans += comb(e.snd);
	for (auto e : cf)
		ans += comb(e.snd);
	for (auto e : leq)
		ans -= comb(e.snd);
	for (auto e : ceq)
		ans -= comb(e.snd);

	cout<<ans<<endl;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;

	while (T--)
		solve();
}