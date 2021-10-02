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

string s;
ll n, memo[11][2][2];

ll pd(int p, int now, int nxt){
	if (p >= n) 
		return (now + nxt) == 0;

	ll &pdm = memo[p][now][nxt];
	if (pdm != -1)
		return pdm;

	pdm = 0;

	int v = s[p] - '0';

	for (int i = 0; i <= 9; i++)
		for (int j = 0; j <= 9; j++){
			int x = (i + j + now) % 10;

			if (x == v)
				pdm += pd(p + 1, nxt, (i + j + now) >= 10);
		}


	return pdm;
}


void solve(){
	cin>>s;
	reverse(all(s));

	n = s.size();

	memset(memo, -1, sizeof memo);

	cout<<pd(0, 0, 0) - 2<<endl;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}