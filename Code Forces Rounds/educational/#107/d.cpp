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

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, k;

	cin>>n>>k;

	string s;

	for (int i = 0; i < k - 1; i++){ // base
		s.pb('a' +i);
		for (int j = i + 1; j < k; j++){
			s.pb('a' + i);
			s.pb('a' + j);
		}
	}

	s.pb('a' + k - 1);
	
	if (k == 1)
		s.pb('a' + k - 1);

	string ans = s;

	while (ans.size() < n){
		for (auto x : s)
			ans.pb(x);
	}

	while (ans.size() > n)
		ans.pop_back();

	cout<<ans<<endl;
}