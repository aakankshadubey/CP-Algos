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
vvi graph(N);

map<int, int> mp;
bool printed = false;
vb visited(N, false);


void printCycle(int node) {

	int tmp = node;
	vi answer;
	answer.P_B(tmp);
	node = mp[node];

	while(node != tmp) {
		// cout<<node<<" ";
		answer.P_B(node);
		node = mp[node];
	}

	answer.P_B(tmp);

	if(answer.size() <= 3) return;
	cout<<answer.size()<<endl;
	for (auto ele : answer) cout<<ele<<" ";

	printed = true;

	// cout<<node<<" ";


}


void dfs(int node, int prev) {

	// cout<<node<<" ";

	if(mp.find(node) != mp.end()) {
		if(!printed) printCycle(node); 
		return;
	}
	visited[node] = true;

	if(printed) return;

	for (auto ngb : graph[node]) {

		if(ngb == prev) continue;

		mp[node] = ngb;
		// cout<<node<<" "<<ngb<<endl;
		dfs(ngb, node);
	}
}


int32_t main() {
	
	// file_io();
	
	ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	// int T; cin>>T; while(T--) 
	{
		
		int n, m;
		cin>>n>>m;	

		for (int i = 0; i < m; i++) {
			int u, v;
			cin>>u>>v;
			graph[u].P_B(v);
			graph[v].P_B(u);
		}

		// for (int i = 1; i <= n; i++) {
		// 	cout<<i<<" : ";			
		// 	for (auto ngb : graph[i]) cout<<ngb<<" ";
		// 	cout<<endl;
		// }

		for (int i = 1; i <= n; i++) {

			if(mp.find(i) != mp.end()) continue;
			dfs(i, -1);
			if(printed) break;
		}

		// for (auto itr : mp) cout<<itr.F<<" "<<itr.S<<endl;

		if(!printed) cout<<"IMPOSSIBLE";


	}	
	
	return 0;
}   
