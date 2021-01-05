#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define F first
#define S second
#define pii pair<int, int>
#define vi vector<int>
#define vb vector<bool>
#define vii vector<pii>
#define vvi vector<vector<int>>
#define P_B push_back
#define M_P make_pair
#define endl "\n"

#define MOD 1000000007
#define pi 3.141592653589793238


// void file_io()
// {
//     freopen("input.txt","r",stdin);
//     freopen("output.txt","w",stdout);
// }


const int N = 1e5 + 5;
vvi graph;
vi c;
vb visited;

bool canColor(int node, int color) {


	for (auto ngb : graph[node]) {
		if(c[ngb] == color) return false;
	}

	return true;
}


bool backtrack(int v, int m, int n) {


	if(v > n) return true;

	for (int i = 1; i <= m; i++) {

		if(canColor(v, i)) {

			c[v] = i;
			if(backtrack(v+1 ,m, n)) return true;
			c[v] = 0;
		}
	}

	return false;
}

int32_t main() {
	
	// file_io();
	
	ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	int T; cin>>T; while(T--) 
	{
		
		graph.clear();
		c.clear();
		visited.clear();

		int n, color, e;
		cin>>n>>color>>e;
		graph.resize(n+1);
		c.resize(n+1);
		visited.resize(n+1, false);


		for (int i = 0; i < e; i++) {
			int u, v;
			cin>>u>>v;

			graph[u].P_B(v);
			graph[v].P_B(u);

		}


		cout<<backtrack(1, color, n)<<endl;


	}	
	
	return 0;
}   
