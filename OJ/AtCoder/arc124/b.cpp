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

int n, a[MAXN], b[MAXN];

vi fb[MAXN];

map<int, int> frqa, frqb;

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n;

	fr(i, n)
		cin>>a[i];
	fr(i, n)
		cin>>b[i];

	fr(i, n){
		frqa[a[i]]++;
		frqb[b[i]]++;
	}	

	for (auto e : frqb)
		fb[e.snd].pb(e.fst); // todos os caras com frequencia b

	int v = frqa[a[0]]; // frequencia do a[0]

	vi ans;

	for (auto y : fb[v]){ // todos que combinam com o a[0] em freq
		int x = y^a[0];
		bool ok = 1;

		for (auto e : frqa)
			if (frqb[e.fst^x] != e.snd)
				ok = 0;
		if (ok)
			ans.pb(x);	
	}

	sort(all(ans));

	cout<<ans.size()<<endl;
	for (auto x : ans)
		cout<<x<<endl;
}