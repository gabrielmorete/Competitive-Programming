#include "bits/stdc++.h"
using namespace std;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

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
const int MAXN = 1e5 + 10;

int n, m, a[MAXN], lugar[MAXN];
vii v;

typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> ordered_set;

ordered_set fileira[302];


// Comandos
// find_by_order(i) -> iterador para o i-ésimo elemento (contando do zero)
// order_of_key(k) -> número de elementos estritamente menores que k
// pode-se subtrair iteradores como em um vector

void solve(){
	v.clear();
	cin>>n>>m;

	fr(i, n + 2)
		fileira[i].clear();


	int x;
	frr(i, n * m){
		cin>>x;
		v.pb({x, n * m - i});
	}

	sort(all(v));

	int cnt = 0;
	for (auto x : v){
		int id = n*m - x.snd;
		lugar[id] = ++cnt;
	}

	int ans = 0;

	frr(i, n * m){
		ans += fileira[1].order_of_key(lugar[i]);
		fileira[1].insert(lugar[i]);
	}

	cout<<ans<<endl;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}