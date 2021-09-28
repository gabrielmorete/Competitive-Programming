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

void solve(){
	string s, t;
	cin>>s>>t;

	int n = s.size();
	int m = t.size();

	if (m > n){
		cout<<"no"<<endl;
		return;
	}

	reverse(all(s));
	reverse(all(t));


	int p = 0;
	for (int i = 0; i < m; i++){
		while (p < n and s[p] != t[i]) p += 2;

		if (p >= n){
			cout<<"no"<<endl;
			return;
		}

		if (t[i] == s[p])
			p++;
	}

	cout<<"yes"<<endl;
}


signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}