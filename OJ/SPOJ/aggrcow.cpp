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

int n, m;
vi v;

bool test(int val){
	int tot = 0;
	int lst = -val;

	fr(i, n){
		if (v[i] - lst >= val){
			tot++;
			lst = v[i];
		}
	}

	return tot >= m;
}


void solve(){
	cin>>n>>m;
	v.resize(n);

	fr(i, n)
		cin>>v[i];

	sort(all(v));
	
	int ini = 1, fim = 1e9, ans = 0;

	while (ini <= fim){
		int meio = (ini + fim)/2;

		if (test(meio)){
			ans = meio ;
			ini = meio + 1;
		}
		else
			fim = meio - 1;
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