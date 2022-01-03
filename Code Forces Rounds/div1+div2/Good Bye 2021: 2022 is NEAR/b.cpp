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

void solve(){
	int n;
	string s;

	cin>>n>>s;

	if (n == 1){
		cout<<s[0]<<s[0]<<endl;
		return;
	}

	if (s[0] == s[1]){
		cout<<s[0]<<s[0]<<endl;
		return;
	}

	int p = -1;

	fr(i, n - 1)
		if (s[i] < s[i + 1]){
			p = i + 1;
			break;
		}

	if (p == -1)
		p = n;

	fr(i, p)
		cout<<s[i];
	for (int i = p - 1; i >= 0; i--)
		cout<<s[i];
	gnl;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}