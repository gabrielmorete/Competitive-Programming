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

ll n, a[MAXN], b[MAXN];

void solve(){
	cin>>n;

	fr(i, n)
		cin>>a[i];

	int st = 0;
	
	if (n % 2){
		if (abs(a[0]) == abs(a[1]) and abs(a[0]) == abs(a[2])){
			b[0] = 1;
			if (a[0] < 0) b[0] = -1;
			b[1] = 1;
			if (a[1] < 0) b[1] = -1;
			b[2] = -2;
			if (a[2] < 0) b[2] = 2;
		}
		else if (abs(a[0]) == abs(a[1])){
			int s0 = a[0] > 0;
			int s2 = a[2] > 0;

			int x = 1;
			if (s0 + s2 != 1)
				x = -1;

			b[0] = a[1];
			b[2] = x*a[1];
			b[1] = -(a[0] + x*a[2]);
		}
		else{
			int s0 = a[0] > 0;
			int s1 = a[1] > 0;

			int x = 1;
			if (s0 + s1 != 1)
				x = -1;

			b[0] = a[2];
			b[1] = x*a[2];
			b[2] = -(a[0] + x*a[1]);
		}
		st = 3;
	}


	for (int i = st; i < n; i+=2){
		b[i] = -a[i + 1];
		b[i + 1] = a[i];
	}

	fr(i, n)
		cout<<b[i]<<' ';
	gnl;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;

	while (T--)
		solve();
}