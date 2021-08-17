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
	int n;
	string s, t;

	cin>>n>>s>>t;


	vi ans;

	int beg = 0;
	int end = n - 1;
	int flip = 0;

	for (int p = n - 1; p >= 0; p--){
		int x = ((int)(s[end] - '0') + flip) % 2;
		int y = t[p] - '0';

		// cout<<p<<' '<<beg<<' '<<end<<' '<<flip<<endl;

		if (x == y){ // tudo certo
			if (end <= beg) end++; // movimenta sem flipar
			else end--;
		}
		else{
			if (s[beg] != s[end])
				ans.pb(1); // flip first
			
			ans.pb(abs(end - beg) + 1); // flip all
			swap(beg, end);

			if (end <= beg) end++; // movimenta sem flipar
			else end--;

			flip = (flip + 1)%2;
		}
	}

	cout<<ans.size()<<' ';

	for (auto x : ans)
		cout<<x<<' ';
	gnl;
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}