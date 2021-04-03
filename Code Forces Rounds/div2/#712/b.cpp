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
const int MAXN = 3e5 + 100;

void solve(){
	bool cng[MAXN];
	int n;
	string a, b;

	cin>>n;
	cin>>a>>b;

	fr(i, n +10)
		cng[i] = 0;

	int zr, um;
	zr = um = 0;

	fr(i, n){
		if (a[i] == '0')
			zr++;
		else
			um++;
		if (zr == um)
			cng[i] = 1;
	}	

	bool ok = 1, flip = 0;


	for (int i = n - 1; i >= 0; i--){
		// cout<<i<<' '<<flip<<' '<<ok<<endl;
		if (flip){
			if (a[i] == b[i] and cng[i] == 0)
				ok = 0;
			else if (a[i] == b[i] and cng[i] == 1)
				flip = 1 - flip;
		}
		else{
			if (a[i] != b[i] and cng[i] == 0)
				ok = 0;
			else if (a[i] != b[i] and cng[i] == 1)
				flip = 1 - flip;
		}
	}

	if (ok)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;

}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}