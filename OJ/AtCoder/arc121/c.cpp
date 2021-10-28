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
const int MAXN = 1e5 + 10;

int vn, v[10];
vi ans;
bool backtrack(int op, int prt){
	if (op > vn * vn) return 0;
	
	bool ok = 1;
	frr(i, vn - 1)
		if (v[i] > v[i + 1])
			ok = 0;

	if (ok) return true;

	frr(i, vn - 1)
		if (i%2 == prt){
			swap(v[i], v[i + 1]);
			ans.pb(i);
			if (backtrack(op + 1, 1 - prt))
				return true;
			ans.pop_back();
			swap(v[i], v[i + 1]);
		}	

	return 0;
}

int n, a[510];

void solve(){
	ans.clear();

	cin>>n;
	frr(i, n)
		cin>>a[i];

	int prt = 1;

	if (n > 5){
		for (int i = n; i > 5; i--){
			int p = 1;
			while (a[p] != i)
				p++;

			if (p == i)
				continue;
		
			if (p%2 != prt){
				for (int j = 1; j < i; j++)
					if (j != (p - 1) and j % 2 == prt){
						swap(a[j], a[j + 1]);
						ans.pb(j);
						prt = 1 - prt;
						break;
					}
			}

			while (p < i){
				ans.pb(p);
				swap(a[p], a[p + 1]);
				prt = 1 - prt;
				p++;
			}
		}
	}	


	vn = min(n, 5);
	frr(i, vn)
		v[i] = a[i];
	
	backtrack(0, prt);

	cout<<ans.size()<<endl;
	for (auto x : ans)
		cout<<x<<' ';
	gnl;	
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}