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
const int MAXN = 4e5 + 10;

void solve(){
	ll n, pr, pd;
	string s;
	
	cin>>n>>s;

	if ((int)count(all(s), 'R') == s.size()){
		cout<<n<<endl;
		return;
	}

	if ((int)count(all(s), 'D') == s.size()){
		cout<<n<<endl;
		return;
	}

	pr = n - 1 - (int)count(all(s), 'R'); // posso r
	pd = n - 1 - (int)count(all(s), 'D'); // posso d

	ll cant = 0, x = 1, y = 1, fr = 0, fd = 0;

	for (auto e : s){
		if (e == 'D'){ // going down
			ll mxr = y;
			if (fr)
				mxr += pr; // max colum I can reach

			cant += n - mxr; // all is lost after

			x++;
			fd = 1;
		}
		else{
			ll mxd = x;
			if (fd)
				mxd += pd;

			cant += n - mxd;

			y++;
			fr = 1;
		}
	}

	cout<<n * n - cant<<endl;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}