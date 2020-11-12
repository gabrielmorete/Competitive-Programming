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
#define all(x)  x.begin(),x.end()

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 1e5 + 10;

typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> ordered_set;
// Comandos
// find_by_order(i) -> iterador para o i-ésimo elemento (contando do zero)
// order_of_key(k) -> número de elementos estritamente menores que k
// pode-se subtrair iteradores como em um vector

typedef tuple<int, int, int> tup;


int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m;
	cin>>n>>m;

	ordered_set q;
	multiset<int> qq;
	qq.insert(0);

	int x;
	fr(i, n){
		cin>>x;
		q.insert(x);
	}

	ll ans, low, high;
	low = *q.find_by_order(0);
	high = *q.find_by_order(q.size() - 1);
	ans = high - low;

	int cnt = 0, p1, p2;
	for (int i = 0; i < n - 1; i++){
		p1 = *q.find_by_order(i);
		p2 = *q.find_by_order(i + 1);
		qq.insert(p1 - p2);
		ans = min(ans, p1 - low + high - p2);
	}

	cout<<ans<<endl;

	int typ, aux, val;
	while (m--){
		cin>>typ>>x;

		if (typ == 0){
			aux = q.order_of_key(x);
			p1 = p2 = -1;
			if (aux > 0){
				p1 = *q.find_by_order(aux - 1);
				qq.erase(qq.find(p1 - x));
			}
			if (aux + 1 < q.size()){
				p2 = *q.find_by_order(aux + 1);
				qq.erase(qq.find(x - p2));
			}
			if (p1 != -1 and p2 != -1)
				qq.insert(p1 - p2);

			q.erase(q.find(x));
		}
		else{
			q.insert(x);
			aux = q.order_of_key(x);
			if (q.size() > 1){
				if (aux + 1 == q.size()){
					p1 = *q.find_by_order(aux - 1);
					qq.insert(p1 - x);
				}
				else if (aux == 0){
					p1 = *q.find_by_order(aux + 1);
					qq.insert(x - p1);
				}
				else{
					p1 = *q.find_by_order(aux - 1);
					p2 = *q.find_by_order(aux + 1);
					qq.erase(qq.find(p1 - p2));
					qq.insert(p1 - x);
					qq.insert(x - p2);
				}
			}
		}

		ll aux = 0;
		if (!q.empty()){
			aux = *q.find_by_order(q.size() - 1) - *q.begin();
		}

		cout<<aux + *qq.begin()<<endl;
	}


}