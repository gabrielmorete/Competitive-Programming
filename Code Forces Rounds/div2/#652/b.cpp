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
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
//cout << setprecision(9)<<fixed;

#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 1e5 + 10;

void solve(){
	int n;
	string s;
	
	cin>>n>>s;

	int ini = -1, fim = -1;
	bool um = 0;
	fr(i, n){
		if (s[i] == '1')
			um = 1;
		if (s[i] == '0' and !um)
			ini = i;
		if (s[i] == '0' and um)
			fim = i;
	}

	if (fim == -1)
		cout<<s<<endl;
	else{
		if (ini != -1)
			for (int i = 0; i <= ini; i++)
				cout<<s[i];
		for (int i = fim; i < n; i++)
			cout<<s[i];
		gnl;			
	}

}

int32_t main(){
	fastio;
	int T;
	cin>>T;
	while (T--)
		solve();
}