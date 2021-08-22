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

vi divi;
void fat(int val){
	divi.clear();

	for (int i = 2; i * i <= val; i++){
		if (val % i == 0){
			divi.pb(i);
			divi.pb(val/i); // tudo bem raiz
		}
	}
	divi.pb(val);
}


vi ans;

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin>>n>>m;

	int x;
	fr(i, n){
		cin>>x;
		fat(x);

		for (auto y : divi)
			frq[y]++;
	}

	ans.pb(1);

	for (int i = 2; i <= m; i++){
		fat(i);

		bool ok = 1;
		for (auto y : divi)
			if (frq[y] > 0)
				ok = 0;

		if (ok)
			ans.pb(i);
	}

	cout<<ans.size()<<endl;
	for (auto y : ans)
		cout<<y<<endl;
}