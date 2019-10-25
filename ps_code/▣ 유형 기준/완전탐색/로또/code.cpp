#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool next_k_permutation(vector<int>&v, int k){
	sort(v.begin()+k, v.end(), greater<int>());
	return next_permutation(v.begin(), v.end());
}

bool next_k_combination(vector<int>&v, int k){
	while(next_k_permutation(v,k)){
		if(is_sorted(v.begin(), v.begin()+k))
			return true;
	}
	return false;
}

int main(){
	int n;
	while(cin>>n && n!=0){
		vector<int>v(n);
		for(int i=0; i<n; ++i) cin>>v[i];
		

		do{
			for(int i=0; i<6; ++i)
				cout<<v[i]<<" ";
			cout<<endl;
		}while(next_k_combination(v,6));
		cout<<endl;
	}

	return 0;
}