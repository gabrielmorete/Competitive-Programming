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
const ll MAXN = 1e9;

ll mx;
	
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	mx = 1;
	ll pwr = 1;

	while (pwr * 3 <= MAXN){
		mx++;
		pwr *= 3;
	}

	int T;
	cin>>T;
	while (T--){
		ll n;
		cin>>n;

		if (n > mx){
			cout<<"NO"<<endl;
		}
		else{
			cout<<"YES"<<endl;
			pwr = 1;
			fr(i, n){
				cout<<pwr<<' ';
				pwr *= 3;
			}
			gnl;
		}
	}
}