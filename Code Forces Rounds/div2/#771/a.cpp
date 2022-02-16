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

int n;
vi a;
void solve(){
	cin>>n;
	a.resize(n);

	fr(i, n)
		cin>>a[i];

	fr(i, n){
		if (a[i] == i + 1)
			continue;

		int p = i;
		while (a[p] != i + 1)
			p++;

		reverse(a.begin() + i, a.begin() + p + 1);
		fr(j, n)
			cout<<a[j]<<' ';
		gnl;
		return;
	}	
	fr(j, n)
			cout<<a[j]<<' ';
		gnl;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}