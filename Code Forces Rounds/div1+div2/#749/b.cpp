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

int n, m, frq[MAXN];

void solve(){
	cin>>n>>m;

	frr(i, n)
		frq[i] = 0;

	int a, b, c;
	fr(i, m){
		cin>>a>>b>>c;
		frq[b] = 1;
	}

	a = 1;
	frr(i, n)
		if (frq[i] == 0)
			a = i;

	frr(i, n)
		if (i != a)
			cout<<a<<' '<<i<<endl;	
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}