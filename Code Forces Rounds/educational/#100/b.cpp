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

int pw2(int x){
	int pwr = 0;

	while (x){
		pwr++;
	
		x >>= 1;
	}
	pwr--;
	return (1 << pwr);
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int T, n, b[55], x;

	cin>>T;

	while (T--){
		cin>>n;

		fr(i, n){
			cin>>x;
			b[i] = pw2(x);
		}

		fr(i, n)
			cout<<b[i]<<' ';
		gnl;
	}
}