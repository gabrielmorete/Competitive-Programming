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

/*
    Gauss Elimination algorithm to solve linear system of equations in Z_2.
    Parameters:
        A * ans = b
        "b" comes in the last column of "a" and "A" is the rest 
    
    Return value:
        - It returns 
            - INF if there are infintely many solutions to the system,
            - 0 if there isn't any
            - 1 if there is a unique solution.
        - If there is only one solution, it returns in the vector "ans" this solution
        - If there are infinitely many, in the positions that I have a choice, it returns INF.
    Usage:
        You may call it with any size of bitset
    Complexity: 
        O(n * m * min(n, m)/ 64)
*/


const int INF = 2;
const int N = 300;

template<size_t N>
int gauss (vector < bitset<N> > a, int m, bitset<N> & ans) {
    int n = (int) a.size();

    for (int it = 0; it < min(n, m); it++) {
        // Firtly, take the row with largest entry to be the pivot
        int sel = it;
        for (int i = it; i < n; i++) 
            if (a[i][it]) {
                swap(a[i], a[it]);
                break;
            }
        if (!a[it][it]) continue;

        // Make the eliminations
        for (int i = 0; i < n; i++)
            if (i != it && a[i][it])
                a[i] ^= a[it];
    }       

    ans.reset();
    for (int i = 0; i < m; ++i) 
        if (a[i][i]) ans[i] = a[i][m] & a[i][i];
  
    // Check if actually it solves the system
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < m; j++) 
            sum ^= ans[j] & a[i][j];
        if (sum != a[i][m]) return 0;
    }

    for (int i = 0; i < m; i++) 
        if (!a[i][i]) return INF;

    return 1;
}

int mx[4] = {-1, 1, 0, 0};
int my[4] = {0, 0, 1, -1};

int n, m;
int crd(int x, int y){
	return x * m + y;
}

pii rcrd(int val){
	int x = val/m;
	int y = val % m;
	return {x, y};
}	

bool valid(int x, int y){
	return (0 <= x and x < n) and (0 <= y and y < m);
}


signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	while (cin>>n>>m and n > 0){
		swap(n, m); // agora tem n linhas e m colunas

		int sz = n * m;

		vector < bitset<N> > a(sz);

		fr(i, sz)
			fr(j, N)
				a[i][j] = 0;


		fr(i, n){
			string s;
			cin>>s;

			fr(j, m){
				int x = s[j] - '0';
				a[crd(i, j)][sz] = 1 - x;
			}
		}

		fr(i, n)
			fr(j, m){
				a[crd(i, j)][crd(i, j)] = 1;

				fr(k, 4){
					int x = i + mx[k];
					int y = j + my[k];
					if (valid(x, y))
						a[crd(x, y)][crd(i, j)] = 1;
				}
			}	

		bitset<N> ans;			

		fr(i, N)
			ans[i] = 0;

		int ret = gauss(a, sz, ans);

		if (ret == 0)
			cout<<-1<<endl;			
		else{
			vii resp;
			fr(i, sz)
				if (ans[i] == 1)
					resp.pb(rcrd(i));

			cout<<resp.size()<<endl;
			for (auto x : resp)	
				cout<<x.snd+1<<' '<<x.fst+1<<endl;
		}
	}
}