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

int n, m, k, inb[MAXN];
vi v;
vi vbig, vsmal;

void print_big(){
	int sz = (n + m - 1)/m;

	while (!vbig.empty()){
		cout<<sz<<' ';
		fr(j, sz){
			cout<<vbig.back() + 1<<' ';
			vbig.pop_back();
		}
		gnl;
	}
}

void print_small(){
	int sz = n/m;

	while (!vsmal.empty()){
		cout<<sz<<' ';
		fr(j, sz){
			cout<<vsmal.back() + 1<<' ';
			vsmal.pop_back();
		}
		gnl;
	}
}

void solve(){
	cin>>n>>m>>k;

	v.resize(n);
	fr(i, n)
		v[i] = i;

	int nb = n/m;
	nb = (nb + 1) * (n % m);

	int p = 0;
	fr(trn, k){
		fr(j, n)
			inb[j] = 0;

		vbig.clear();
		for (int i = 0; i < nb; i++){
			vbig.pb( (p + i) % n);
			inb[(p + i) % n] = 1;
		}
		p = (p + nb) % n;

		vsmal.clear();
		fr(j, n)
			if (!inb[j])
				vsmal.pb(j);

		print_big();	
		print_small();
	}
	gnl;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}