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
	int n, m;

	cin>>n>>m;

	if (n <= m){
		cout<<"Pay the bill"<<endl;
		return 0;
	}

	ll win = 0; // todas as primeiras m posições são vencedoras
	ll move = 0;

	frr(i, m){
		move <<= 1;
		int x = __builtin_popcount(i);
		move |= !(x&1); // se eu sou impar, não vem
	}

	int lst = 1;
	for (int i = m + 1; i <= n; i++){
		lst = (win&move)>0;
		win<<=1;
	
		if (win &(1ll<<m)) // desliga o bit m
			win -= 1ll<<m;

		win |= !lst;

		move <<= 1;
		if (move &(1ll<<m)) // desliga o bit m
			move -= 1ll<<m;

		int x = __builtin_popcount(i);
		move |= !(x&1); 
	}

	if (lst == 0)
		cout<<"Free snacks!"<<endl;
	else
		cout<<"Pay the bill"<<endl;
}