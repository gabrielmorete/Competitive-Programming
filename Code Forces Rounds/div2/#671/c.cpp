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

int n, x, a[MAXN];

void solve(){
	cin>>n>>x;
	
	int dif = 0, eq = 0;	

	fr(i, n){
		cin>>a[i];
		if (a[i] == x)
			eq++;
		dif += a[i] - x;
	}

	if (eq == n){ // geral igual
		cout<<0<<endl;
		return;
	}

	if (dif == 0 or eq > 0){
		cout<<1<<endl;
		return;
	}
	else
		cout<<2<<endl;
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}