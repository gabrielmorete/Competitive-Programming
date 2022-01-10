#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fst first
#define snd second

#define fr(i,n)     for (int i = 0; i < n; i++)
#define frr(i,n)    for (int i = 1; i <= n; i++)

// #define endl '\n'
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
const int MAXN = 4e5 + 10;

vector<vector<string>> num = {
{{"***"},
{"* *"},
{"* *"},
{"* *"},
{"***"}},

{{"  *"}, 
{"  *"}, 
{"  *"}, 
{"  *"}, 
{"  *"}}, 

{{"***"}, 
{"  *"}, 
{"***"}, 
{"*  "}, 
{"***"}}, 

{{"***"}, 
{"  *"}, 
{"***"}, 
{"  *"}, 
{"***"}}, 

{{"* *"}, 
{"* *"}, 
{"***"}, 
{"  *"}, 
{"  *"}}, 

{{"***"}, 
{"*  "}, 
{"***"}, 
{"  *"}, 
{"***"}},

{{"***"}, 
{"*  "}, 
{"***"}, 
{"* *"}, 
{"***"}},  

{{"***"}, 
{"  *"}, 
{"  *"}, 
{"  *"}, 
{"  *"}}, 

{{"***"}, 
{"* *"}, 
{"***"}, 
{"* *"}, 
{"***"}},

{{"***"},
 {"* *"},
 {"***"},
 {"  *"},
 {"***"}}

};

string in[5], testa[5];

bool test(int val){
	fr(i, 5){
		fr(j, 3)
			if (num[val][i][j] != testa[i][j])
				return false;
	}

	return true;
}


signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	fr(i, 5){
		getline(cin, in[i]);
	}

	ll ans = 0, pwr = 1;	

	while (!in[0].empty()){
		int n = in[0].size();
		fr(i, 5){
			testa[i].clear();
			for (int j = 3; j > 0; j--)
				testa[i].pb(in[i][n - j]);
		}

		int val = -1;

		fr(i, 10)
			if (test(i))
				val = i;

		if (val == -1){
			cout<<"BOOM!!"<<endl;
			return 0;
		}	

		ans += val * pwr;
		pwr *= 10;

		fr(i, 5)
			fr(j, 4)
				if (!in[i].empty())
					in[i].pop_back();
	}	

	if (ans % 6 == 0)
		cout<<"BEER!!"<<endl;
	else
		cout<<"BOOM!!"<<endl;
}