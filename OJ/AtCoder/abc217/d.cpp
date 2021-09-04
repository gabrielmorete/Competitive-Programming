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


typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> ordered_set;
// Comandos
// find_by_order(i) -> iterador para o i-ésimo elemento (contando do zero)
// order_of_key(k) -> número de elementos estritamente menores que k
// pode-se subtrair iteradores como em um vector

ordered_set q;

int n, m;

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin>>n>>m;

	int typ, x;
	while (m--){
		cin>>typ>>x;

		if (typ == 1){
			q.insert(x);
		}
		else{
			int p = q.order_of_key(x);

			if (q.empty())
				cout<<n<<endl;
			else if (p == 0){
				cout<<*q.begin()<<endl;
			}
			else if (p == q.size()){
				int y = *q.find_by_order(p - 1);
				cout<<n - y<<endl;
			}
			else{
				int a = *q.find_by_order(p);
				int b = *q.find_by_order(p - 1);
				cout<<a - b<<endl;
			}
		}
	}

}