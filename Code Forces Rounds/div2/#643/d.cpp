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


int32_t main(){
	fastio;
	int n, s;
	cin>>n>>s;

	for (int k = 1; k < s - n + 1; k++){
		if (k > n - 1 and k - s < s - n + 1){
			cout<<"YES"<<endl;
			fr(i, n - 1)
				cout<<1<<' ';
			cout<<s - n + 1<<endl;
			cout<<k<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;
}