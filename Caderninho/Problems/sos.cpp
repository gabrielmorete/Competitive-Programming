// Sum over subsets DP (SOS DP)
// Percorre** todos os subconjuntos de uma mask
// Seja n o numero de conjuntos e m tal que 2^m> = n
// Complexidade: O(m 2**m)

// Resolve https://codeforces.com/contest/165/problem/E
// Dados uma lista de 10^6 numeros queremos descobrir para cada numero
// se há outro número na lista cujo o and da representação binária é zero.
// Se sim, temos que imprimir o número


#include "bits/stdc++.h"
using namespace std;

const int MAXN = 1<<22;

int n, v[MAXN], a[MAXN], memo[MAXN];

void sos(){
	for (int msk = 0; msk <(1<<22); msk++)
		memo[msk] = a[msk]; // eu produzo essa representaçao

	for (int i = 0; i < 22; i++)
		for (int msk = 0; msk < (1<<22); msk++)
			if ((msk & (1<<i)))
				memo[msk] = max(memo[msk], memo[msk^(1<<i)]); // se tam alguem e maior que zero
				// memo[msk] += memo[msk^(1<<i)]; para soma
}


int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin>>n;
	for (int i = 1; i <= n; i++){
		cin>>v[i];
		a[v[i]] = i; // indice que gera
	}

	sos();

	int ones = (1<<22) - 1; // 22 uns

	for (int i = 1; i <= n; i++){
		if (memo[v[i]^ones] > 0)
			cout<<v[memo[v[i]^ones]]<<' ';
		else
			cout<<-1<<' ';
	}
	cout<<endl;	
}