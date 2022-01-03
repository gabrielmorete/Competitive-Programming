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
const int MAXN = 4e5 + 10;

typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> ordered_set;
// Comandos
// find_by_order(i) -> iterador para o i-ésimo elemento (contando do zero)
// order_of_key(k) -> número de elementos estritamente menores que k
// pode-se subtrair iteradores como em um vector


int n;
string s, t;

void solve(){
	cin>>n>>s>>t;

	ll ans = llINF;
	stack<int> stk[150];
	ordered_set q;

	for (int i = n - 1; i >= 0; i--){
		q.insert(i);
		stk[s[i]].push(i);
	}

	ll now = 0;

	for (int i = 0; i < n; i++){
		for (char a = 'a'; a < t[i]; a++)
			if (!stk[a].empty())
				ans = min<ll>(ans, now + q.order_of_key(stk[a].top()));
		
		if (stk[t[i]].empty())
			break;

		now += q.order_of_key(stk[t[i]].top());
		q.erase(stk[t[i]].top());
		stk[t[i]].pop();
	}

	if (ans >= llINF)
		cout<<"-1"<<endl;
	else
		cout<<ans<<endl;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}