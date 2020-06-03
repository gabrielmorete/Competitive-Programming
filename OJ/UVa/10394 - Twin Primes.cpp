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
const int MAXN = 2e7 + 10;
const ll mod = 1e9+7;

bool check[MAXN];

vector<ll> ans;

void crivo(){
	for (ll i = 2; i < MAXN; i++){
		if (check[i])
			continue;
		for (ll j = i * i; j < MAXN; j += i)
			check[j] = 1;

		if (check[i + 2] == 0)
			ans.pb(i);
	}
}

int32_t main(){
	crivo();
	fastio;

	int n;

	while (cin>>n){
		cout<<'('<<ans[n - 1]<<", "<<ans[n - 1] + 2<<')'<<endl;
	}
}