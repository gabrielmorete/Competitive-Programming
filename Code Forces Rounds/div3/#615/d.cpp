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
const int MAXN = 4e5 + 100;
const ll mod=1e9+7;

int pos[MAXN], mex;

int32_t main(){
	fastio;
	int n, x;
	cin>>n>>x;

	fill(pos, pos + MAXN, -1);

	int a;
	fr(cnt, n){
		cin>>a;
		a %= x;

		if (pos[a] == -1)
			pos[a] = a;
		else
			pos[a] += x;

		while (pos[mex % x] >= mex)
			mex++;

		cout<<mex<<endl;
	}
}