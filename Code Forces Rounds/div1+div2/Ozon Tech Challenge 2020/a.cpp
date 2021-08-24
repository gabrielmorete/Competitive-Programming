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

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;

	while (T--){
		int n;
		vi a, b;

		cin>>n;

		int x;
		fr(i, n){
			cin>>x;
			a.pb(x);
		}

		fr(i, n){
			cin>>x;
			b.pb(x);
		}

		sort(all(a));
		sort(all(b));

		for (auto x : a)
			cout<<x<<' ';
		gnl;
		for (auto x : b)
			cout<<x<<' ';
		gnl;

	}
}