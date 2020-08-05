#include "bits/stdc++.h"
using namespace std;

// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

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
const int MAXN = 2e5 + 100;
const ll mod=1e9+7;

typedef tuple<int, int, int> tup;

int esq[MAXN], dir[MAXN], ini[MAXN], sz[MAXN], v[MAXN], n;

set<tup> seq;

void update(int chave){
	int e, d;
	e = esq[chave];
	d = dir[chave];

	if (e != 0)
		dir[e] = d;
	if (d != n + 1)
		esq[d] = e;
}

void merge(int e, int d){
	if (dir[d] != n + 1)
		esq[dir[d]] = e;
	
	dir[e] = dir[d];
	seq.erase({-sz[e], ini[e], e});
	seq.erase({-sz[d], ini[d], d});


	seq.insert({-(sz[e] + sz[d]), ini[e], e});
	sz[e] += sz[d];
}

int32_t main(){
	scanf("%d", &n);
	frr(i, n)
		scanf("%d", v + i);
	
	int tp, chave;

	esq[1] = 0;
	ini[1] = 1;
	tp = v[1];
	chave = 1;

	for (int i = 2; i <= n; i++){
		if (v[i] != tp){
			sz[chave] = i - ini[chave];
			dir[chave] = chave + 1;
			esq[chave + 1] = chave;
			seq.insert({-sz[chave], ini[chave], chave});

			chave++;
			ini[chave] = i;
			tp = v[i];
		}
	}

	sz[chave] = n + 1 - ini[chave];
	dir[chave] = n + 1;
	seq.insert({-sz[chave], ini[chave], chave});

	int ans = 0;

	int e, d;
	tup aux;
	while (!seq.empty()){
		aux = *seq.begin();
		seq.erase(seq.begin());

		chave = get<2>(aux);

		//dbg(chave);

		update(chave);

		e = esq[chave]; d = dir[chave];

		if (e != 0 and d != n + 1 and v[ini[e]] == v[ini[d]]){
			merge(e, d);
		}

		ans++;
	}
	printf("%d\n", ans);

}