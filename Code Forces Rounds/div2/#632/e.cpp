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
const ll mod=1e9+7;

int32_t main(){
	fastio;
	int n, ans[555][555];
	cin>>n;

	if (n <= 2){
		cout<<-1<<endl;
		return 0;
	}


	int aux = n * n - 9;
	ans[0][0] = 9 + aux; ans[0][1] = 5 + aux; ans[0][2] = 6 + aux;
	ans[1][0] = 7 + aux; ans[1][1] = 2 + aux; ans[1][2] = 8 + aux;
	ans[2][0] = 1 + aux; ans[2][1] = 3 + aux; ans[2][2] = 4 + aux;

	int cnt = 1;
	bool ok = n % 2;
	aux = n;
	while (aux > 3){
		if (ok){
			fr(i, aux)
				ans[aux - 1][i] = cnt++;
			for (int i = aux - 2; i >= 0; i--)
				ans[i][aux - 1] = cnt++;
		}
		else{
			fr(i, aux)
				ans[i][aux - 1] = cnt++;
			for (int i = aux - 2; i >= 0; i--)
				ans[aux - 1][i] = cnt++;	
		}
		aux--;
		ok = !ok;
	}
	fr(i,n){
		fr(j, n)
			cout<<ans[i][j]<<' ';
		gnl;	
	}

}