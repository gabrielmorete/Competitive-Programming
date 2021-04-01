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
const int MAXN = 1e3 + 10;

set<pii> ans;

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin>>n;

	int t = (n + 1)/2;
	int p = n/2;

	for (int i = 0; i < t; i++){
		for (int j = 0; j <= p; j++){
			ans.insert({t - 2*i, p - 2*j});
			ans.insert({t - 2*i, 2*j - p});

			ans.insert({2*i - t, p - 2*j});
			ans.insert({2*i - t, 2*j - p});
		
			ans.insert({p - 2*j, t - 2*i});
			ans.insert({2*j - p, t - 2*i});

			ans.insert({p - 2*j, 2*i - t});
			ans.insert({2*j - p, 2*i - t});
		}
	}


	cout<<ans.size()<<endl;
}