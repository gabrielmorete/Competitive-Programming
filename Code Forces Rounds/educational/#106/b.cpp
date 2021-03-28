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

	int n = s.size();

	if (count(all(s), '0') == n or count(all(s), '1') == n){
		cout<<"yes"<<endl;
		return;
	}

	for (int i = 0; i < n; i++){
		bool ok = 1;
		int lst = -3;
		for (int j = 0; j < i; j++){
			if (s[j] == '1'){
				if (lst >= j - 1)
					ok = 0;
				lst = j;
			}
		}

		if (s[i] == 0 and lst >= i - 1)
			ok = 0;

		for (int j = i; j < n; j++){
			if (s[j] == '0'){
				if (lst >= j - 1)
					ok = 0;
				lst = j;
			}
		}

		if (ok){
			cout<<"yes"<<endl;
			return;
		}
	}
	cout<<"no"<<endl;
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}