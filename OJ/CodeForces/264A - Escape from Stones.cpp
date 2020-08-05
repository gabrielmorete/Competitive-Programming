#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n)     for(int i=0;i<n;i++)
#define frr(i,n)    for(int i=1;i<=n;i++)

#define ms(x,i) memset(x,i,sizeof(x))
#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()

#define gnl cout << endl
#define chapa cout << "oi meu chapa" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
//cout << setprecision(9)<<fixed;

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 100100;
const int MAXM = 1001000;
const ll mod=1e9+7;
const int LMAXN = 25;

char s[1123456];

int main(){
	vi esq, dir;
	
	scanf("%s", s);
	int cnt = 1;

	for (int i = 0; s[i] != 0; i++){
		if (s[i] == 'r')
			esq.pb(cnt++);
		else
			dir.pb(cnt++);
	}
	
	for (int i = 0; i < esq.size(); i++)
		printf("%d\n", esq[i]);
	for (int i = ((int)dir.size()) - 1; i >= 0;i--)
		printf("%d\n", dir[i]);
}