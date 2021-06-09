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
const int MAXN = 1e4 + 10;

int n, m, a[MAXN], b[MAXN];

void solve(){
	cin>>n>>m;

	string s;

	cin>>s;

	frr(i, n)
		a[i] = s[i - 1] - '0';
	a[0] = a[n + 1] = 0;	

	bool ok = 1;
	int cnt = 0;

	while (ok){
		ok = 0;

		frr(i, n){
			if (a[i] == 0){
				if (a[i - 1] + a[i + 1] == 1){
					b[i] = 1;
					ok = 1;
				}
				else
					b[i] = 0;
			}
			else
				b[i] = 1;
		}

		frr(i, n)
			a[i] = b[i];

		cnt++;

		if (cnt == m)
			ok = 0;
	}

	frr(i, n)
		cout<<a[i];
	gnl;		

}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}