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
#define all(x)  x.begin(),x.end()

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 1e5 + 10;

ll a[MAXN], b[MAXN];

void solve(){
	ll ah, bh, n;

	cin>>ah>>bh>>n;

	fr(i, n)
		cin>>a[i];
	fr(i, n)
		cin>>b[i];

	ll sum = 0;
	
	for (int i = 0; i < n; i++){
		ll niter = (b[i] + ah - 1)/ah; // # de atks para matar

		sum += a[i] * niter; // total dmg
	}	

	for (int i = 0; i < n; i++){
		if (sum >= bh and bh <= sum - a[i]) // morreu antes do ultimo hit
			continue;

		cout<<"YES"<<endl;			
		return;
	}

	cout<<"NO"<<endl;	
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int T;

	cin>>T;

	while (T--)
		solve();
}