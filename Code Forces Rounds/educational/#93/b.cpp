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
	string s;
	cin>>s;

	priority_queue<int> pq;

	int now = 0;

	while (!s.empty()){
		if (s.back() == '0'){
			pq.push(now);
			now = 0;
		}
		else
			now++;
		s.pop_back();
	}
	pq.push(now);

	int ans = 0;
	fr(i, 110){
		if (pq.empty()) break;
		if (i%2 == 0)
			ans += pq.top();
		pq.pop();
	}
	cout<<ans<<endl;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}