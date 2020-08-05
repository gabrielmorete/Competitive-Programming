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
const ll mod = 1e9+7;

void solve(){
	int n, x;
	int ev, od;
	ev = od = 0;

	cin>>n>>x;
	
	int aux;
	fr(i, n){
		cin>>aux;
		if (aux % 2)
			od++;
		else
			ev++;
	}

	if (od == 0){
		cout<<"no"<<endl;
		return;
	}

	x--;
	od--;

	if (x % 2 and ev == 0){
		cout<<"no"<<endl;
		return;
	}

	if (x % 2){
		x--;
		ev--;
	}

	if (x <= ev){
		cout<<"yes"<<endl;
		return;
	}

	if (od % 2)
		od--;

	x -= od;

	if (x <= ev){
		cout<<"yes"<<endl;
		return;
	}
	cout<<"no"<<endl;


}

int32_t main(){
	fastio;
	int T;
	cin>>T;
	while (T--)
		solve();
}
