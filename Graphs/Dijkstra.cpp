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

class Node {

public:

	int  v, wt;
	Node (int v, int wt) {
		this->v = v;
		this->wt = wt;
	}
};

const int N = 1e5 + 5;
vector<vector<Node>> graph(N);
vi answer(N, 1e18L);

void dijkstra(int n) {

	priority_queue<pii, vii, greater<pii>> q;
	q.push({0, 1});
	answer[1] = 0;

	while(!q.empty()) {	

		auto t = q.top().S;
		int x = q.top().F;
		q.pop();

		if(x != answer[t]) continue;

		for (auto ngb : graph[t]) {


			if(answer[t] + ngb.wt < answer[ngb.v]) {
				answer[ngb.v] = answer[t] + ngb.wt;
				q.push({answer[ngb.v] , ngb.v});
			}
		}
	}


}

int32_t main() {
	
	// file_io();
	
	ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	// int T; cin>>T; while(T-	-) 
	{
		
		int n, m;
		cin>>n>>m;
		for (int i = 0; i < m; i++) {
			int u, v, wt;
			cin>>u>>v>>wt;
			graph[u].P_B(Node(v, wt));
		
		}		


		dijkstra( n);
		// for (int i = 1; i <= N; i++) {
		// 	if(graph[i].size() == 0) continue;
		// 	for (auto ele : graph[i]) {
		// 		cout<<i<<" "<< ele.v<<" "<<ele.wt<<endl;
		// 	}
		// }

		for (int i = 1; i <= n; i++) cout<<answer[i]<<" ";

	}	
	
	return 0;
}   
