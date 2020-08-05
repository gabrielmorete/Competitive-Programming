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
const int MAXN = 1e2 + 10;

int n, k, v[MAXN];

int get_max(){
	int p, q;
	p = -1;
	q = 0;
	frr(i, n)
		if (v[i] > q){
			q = v[i];
			p = i;
		}			
	return p;
}

int get_min(){
	int p, q;
	p = -1;
	q = INF;
	frr(i, n)
		if (v[i] < q){
			q = v[i];
			p = i;
		}			
	return p;
}

int32_t main(){
	fastio;
	cin>>n>>k;

	frr(i, n)
		cin>>v[i];

	int p, q;
	vii ans;
	while (k--){
		p = get_max();
		q = get_min();

		if (v[p] > v[q]){
			ans.pb({p, q});
			v[p]--;
			v[q]++;
		}
	}

	p = get_max();
	q = get_min();

	cout<<v[p] - v[q]<<' '<<ans.size()<<endl;
	for (auto x : ans)
		cout<<x.fst<<' '<<x.snd<<endl;
}