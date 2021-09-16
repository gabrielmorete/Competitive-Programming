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

int n;
vi v;


int freq[MAXN];

int get_mex(){
	for (auto x : v)
		freq[x]++;

	int mex = n;

	fr(i, n)
		if (freq[i] == 0)
			mex = min(mex, i);

	for (auto x : v)
		freq[x] = 0;

	return mex;
}

vi ans;

int terminou(){
	bool ok = 1;
	fr(i, n - 1)
		if (v[i + 1] < v[i]) ok = 0;

	if (ok){
		cout<<ans.size()<<endl;
		for (auto x : ans)
			cout<<x<<' ';
		gnl;
		return 1;
	}	

	return 0;
}


void solve(){
	v.clear();
	ans.clear();

	cin>>n;

	v.resize(n);

	fr(i, n)
		cin>>v[i];

	int temn = 0, temz = 0;	

	fr(r, 2*n){
		if (terminou()) return;

		int x = get_mex();

		if (x == n){
			fr(i, n)
				if (i != v[i]){
					ans.pb(i + 1);
					v[i] = n;
					break;
				}

			continue;
		}

		v[x] = x;
		ans.pb(x + 1);
	}
	if (terminou()) return;
	assert(0);
}


signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}