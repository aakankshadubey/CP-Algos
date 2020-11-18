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


// MAX HEAP

const int N = 1e5 + 5;

void heapify( vi &v, int n) {

	int end = n;

	while(end >= 1) {

		int cur = end;
		while(cur <= n) {

			int left_child = 2*cur, right_child = 2*cur+1;
			int left = INT_MIN, right = INT_MIN;

			if(left_child <= n) left = v[left_child];
			if(right_child <= n) right = v[right_child];


			int max_idx = -1;
			if(left > right) max_idx = left_child;
			else max_idx = right_child;

			if(max_idx > n) break;

			if(v[max_idx] > v[cur]) {
				swap(v[cur], v[max_idx]);
				cur = max_idx;
			}

			else break;


		}

		end--;
	
	}
}


void rev_heapify(vi &v, int n) {


		int cur = 1;

		while(cur <= n) {

			int left_child = 2*cur, right_child = 2*cur+1;
			int left = INT_MIN, right = INT_MIN;

			if(left_child <= n) left = v[left_child];
			if(right_child <= n) right = v[right_child];


			int max_idx = -1;
			if(left > right) max_idx = left_child;
			else max_idx = right_child;

			if(max_idx > n) break;

			if(v[max_idx] > v[cur]) {
				swap(v[cur], v[max_idx]);
				cur = max_idx;
			}

			else break;

	}

}

void heapSort(vi &v, int n) {


	int sz = n;

	while(sz >= 2) {

		swap(v[1], v[sz]);
		sz--;

		if(sz == 1) return;
		rev_heapify(v, sz);
	} 
}


int32_t main() {
	
	// file_io();
	
	ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	// int T; cin>>T; while(T--) 
	{
		
		int n;
		cin>>n;
		vi v(n+1);
		for (int i = 1; i <= n; i++) cin>>v[i];

		heapify(v, n);
		heapSort(v, n);

		for (int i = 1; i <= n; i++) cout<<v[i]<<" ";
			cout<<endl;

	}	
	
	return 0;
}   
