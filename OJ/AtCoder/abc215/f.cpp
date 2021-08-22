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
const int MAXN = 2e5 + 10;
const int LMAXN = 25;

int n;
vii v;

int minimo[MAXN][LMAXN], maximo[MAXN][LMAXN], lg[MAXN];

void build_rmq(){
	for (int i = 0; i < n; i++)
		maximo[i][0] = minimo[i][0] = v[i].snd;

	for (int j = 1; j < LMAXN; j++)
    	for (int i = 0; i + (1 << j) <= n; i++){
        	minimo[i][j] = min(minimo[i][j - 1], minimo[i + (1 << (j - 1))][j - 1]);
        	maximo[i][j] = max(maximo[i][j - 1], maximo[i + (1 << (j - 1))][j - 1]);
    	}

	lg[1] = 0;
	for (int i = 2; i < MAXN; i++)
	    lg[i] = lg[i/2] + 1;    
}

int query_min(int l, int r){
	int aux = lg[r - l + 1];
	return min(minimo[l][aux], minimo[r - (1 << aux) + 1][aux]);
}

int query_max(int l, int r){
	int aux = lg[r - l + 1];
	return min(maximo[l][aux], maximo[r - (1 << aux) + 1][aux]);
}

vi px;

bool atras(int id, int val){
	auto back = upper_bound(all(px), px[id] - val);
	if (back != px.begin()){ // caso contrario, não teria ninguem menor
		back--;
		int p = (int)(back - px.begin());

		if (query_max(0, p) - v[id].snd >= val)
			return true;
		if (v[id].snd - query_min(0, p) >= val)
			return true;
	}

	return false;
}

bool frente(int id, int val){
	auto fron = lower_bound(all(px), px[id] + val);
	
	if (fron != px.end()){
		int p = (int)(fron - px.begin());
		if (query_max(p, n - 1) - v[id].snd >= val)
			return true;
		if (v[id].snd - query_min(p, n - 1) >= val)
			return true;
	}

	return false;
}


int solve(int id){
	int ini = 0, fim = 1e9, bst = 0;

	while (ini <= fim){
		int meio = (ini + fim)/2; 

		bool ok = atras(id, meio) or frente(id, meio);

		if (ok){
			bst = meio;
			ini = meio + 1;
		}
		else
			fim = meio - 1;
	}

	return bst;
}


int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n;

	int x, y;
	fr(i, n){
		cin>>x>>y;
		v.pb({x, y});
	}

	sort(all(v));

	for (auto e : v)
		px.pb(e.fst);

	build_rmq();

	int ans = 0;

	for (int i = 0; i < n; i++)
		ans = max(ans, solve(i));

	cout<<ans<<endl;
}