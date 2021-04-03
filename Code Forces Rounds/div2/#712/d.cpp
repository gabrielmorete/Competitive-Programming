#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fst first
#define snd second

#define fr(i,n)     for (int i = 0; i < n; i++)
#define frr(i,n)    for (int i = 1; i <= n; i++)

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

vii white, black;

void pw(int c){
	cout<<c<<' '<<white.back().fst<<' '<<white.back().snd<<endl;
	white.pop_back();
}

void pb(int c){
	cout<<c<<' '<<black.back().fst<<' '<<black.back().snd<<endl;
	black.pop_back();
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;

	cin>>n;

	frr(i, n)
		frr(j, n){
			if ((i + j) % 2)
				white.pb({i, j});
			else
				black.pb({i, j});
		}

	int a;	
	fr(t, n * n){
		cin>>a;

		if (a == 1){
			if (!black.empty())
				pb(2); // preto com cor 2
			else // preto vazio
				pw(3);
		}
		else if (a == 2){
			if (!white.empty())
				pw(1);
			else // branco vazio
				pb(3);
		}
		else{
			if (!white.empty())
				pw(1);
			else
				pb(2);
		}
	}	
}