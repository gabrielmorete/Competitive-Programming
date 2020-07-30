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

ll ox[10], oy[10];

ll sq(ll val){
	return val * val;
}

ll dist(int x, int y){
	return sq(ox[x] - ox[y]) + sq(oy[x] - oy[y]);
}

int32_t main(){
	fastio;
	
	int x, y;
	fr(i, 8)
		cin>>ox[i]>>oy[i];
		
	vi p;
	fr(i, 8)
		p.pb(i);

	do {	
		if (dist(p[0], p[1]) == dist(p[0], p[2]) and 
			dist(p[3], p[2]) == dist(p[3], p[1]) and  
			dist(p[0], p[1]) == dist(p[2], p[3]) and
			dist(p[0], p[3]) == dist(p[2], p[1]) and 
			dist(p[0], p[3]) == dist(p[0], p[1]) + dist(p[1], p[3])){ // quadrado

			if (dist(p[4], p[5]) == dist(p[6], p[7]) and 
				dist(p[4], p[6]) == dist(p[5], p[7]) and 
				dist(p[4], p[7]) == dist(p[6], p[5]) and 
				dist(p[4], p[7]) == dist(p[4], p[5]) + dist(p[5], p[7])){ // retangulo
				cout<<"YES"<<endl;
				cout<<p[0] + 1<<' '<<p[1] + 1<<' '<<p[2] + 1<<' '<<p[3] + 1<<endl;
				cout<<p[4] + 1<<' '<<p[5] + 1<<' '<<p[6] + 1<<' '<<p[7] + 1<<endl;
				return 0;
			}
		}

	} while (next_permutation(all(p)));

	cout<<"NO"<<endl;
}