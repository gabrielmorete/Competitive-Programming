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
const int MAXN = 1e5 + 10;

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string s[2];
	cin>>s[0]>>s[1];

	vii v;
	fr(i, 2)
		fr(j, 2)
			if (s[i][j] == '#')
				v.pb({i, j});

	if (v.size() <= 1 or v.size() >= 3){
		cout<<"Yes"<<endl;
	}
	else{
		if (v[0].fst != v[1].fst and v[0].snd != v[1].snd)
			cout<<"No"<<endl;
		else
			cout<<"Yes"<<endl;
	}		
}		