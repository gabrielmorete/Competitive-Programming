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

int n;
string s, t;

void solve(){
	cin>>n>>s>>t;

	set<int> to[MAXN];

	bool ok = 1;

	fr(i, n){
		if (s[i] > t[i]) ok = 0;
		else{
			if (s[i] != t[i])
				to[s[i] - 'a'].insert(t[i] - 'a');
		}
	}

	if (!ok){
		cout<<-1<<endl;
		return;
	}


	int ans = 0;
	fr(i, 20)
		if (!to[i].empty()){
			ans++;
			ok = 1;
			int x = *to[i].begin();
			to[i].erase(to[i].begin());

			for (auto y : to[i])
				to[x].insert(y);
			to[i].clear();

		}
	cout<<ans<<endl;	

}


int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}