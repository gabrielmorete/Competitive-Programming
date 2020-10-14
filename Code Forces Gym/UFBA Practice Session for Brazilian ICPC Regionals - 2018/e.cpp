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
#define all(x)  x.begin(),x.end()

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 1e5 + 10;

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	string s;
	cin>>s;

	int n = s.size();

	if (n <= 1){
		cout<<"YES"<<endl;
		return 0;
	}

	int xr = 0;

	for (int i = 0; i < n - 1; i++)
		xr ^= (s[i] -  '0');

	if (xr == (s.back() - '0')) // if last count correctly
		cout<<"YES"<<endl;		// every other can be correct also
	else
		cout<<"NO"<<endl;		// if not, no one can
}