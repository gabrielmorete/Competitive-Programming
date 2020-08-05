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

#define sz 7

int mx[sz] = {0, 1, 2, 0, 2, 0, 1};
int my[sz] = {0, 0, 0, 1, 1, 2, 2};

int32_t main(){
	fastio;
	int n;
	cin>>n;

	vii ans;

	int x, y;
	x = 0;
	y = 0;

	n++;
	while (n > 0){
		fr(i, sz)
			ans.pb({x + mx[i], y + my[i]});

		x += 2;
		y += 2;
		n--;
	}
	ans.pb({x, y});
	cout<<ans.size()<<endl;
	for (auto x : ans)
		cout<<x.fst<<' '<<x.snd<<endl;	

}