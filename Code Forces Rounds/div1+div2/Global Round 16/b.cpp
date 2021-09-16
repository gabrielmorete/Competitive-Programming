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

	int zero = count(all(s), '0');
	int um = s.size() - zero;

	if (zero == 0){
		cout<<0<<endl;
		return;
	}
	if (um == 0){
		cout<<1<<endl;
		return;
	}

	int cnt = 0, fora = 1;

	for (int i = 0; i < s.size(); i++){
		if (s[i] == '0'){
			if (fora == 1){
				cnt++;
				fora = 0;
			}
		}
		else{
			fora = 1;
		}
	}

	cout<<min(cnt, 2)<<endl;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}