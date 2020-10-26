#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define ll long long 
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
stack<int> st;
bool toggle;

void dfs(vvi &graph, vb &visited, int node) {

	if(visited[node]) return;
	visited[node] = true;

	for (auto ngb : graph[node]) {

		if(visited[ngb]) continue;
		dfs(graph, visited, ngb);
	}

	if(toggle) st.push(node);

}


int32_t main() {
	
	// file_io();
	
	ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	int T; cin>>T; while(T--) 
	{
		
		int n, m;
		cin>>n>>m;

		vb visited(n, false);
		toggle = true;

		vvi graph(n), transpose_graph(n);
		while(m--) {

			int u, v;
			cin>>u>>v;
			graph[u].P_B(v);
			transpose_graph[v].P_B(u);
		}

		for (int i = 0; i < n; i++) {
			if(!visited[i]) dfs(graph, visited, i);
		}

		visited.clear();
		visited.resize(n, false);

		int answer = 0;
		toggle = false;

		while(!st.empty()) {

			int node = st.top();
			st.pop();

			if(visited[node]) continue;
			dfs(transpose_graph, visited, node);
			answer++;
		}

		cout<<answer<<endl;

	}	
	
	return 0;
}   
