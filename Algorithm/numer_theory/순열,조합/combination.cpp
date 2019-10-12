0. 재귀를 통한 방법
 
void pick(int n, vector<int>& picked, int toPick){
    if(toPick==0) {
        printPicked(picked);
        return;
    }
 
    int smallest=picked.empty() ? 0 : picked.back()+1;
    for(int next=smallest; next<n; ++next){
        picked.push_back(next);
        pick(n,picked, toPick-1);
        picked.pop_back();
    }
}
 
1.STL 활용한 방법(하나하나 출력할때 편하다)
 
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
 
//is_sorted 함수는 c++11에서부터 존재
bool is_sorted(vector<int>::iterator first, vector<int>::iterator last){
    if(first==last) return true;
    vector<int>::iterator next=first;
 
    while(++next != last){
        if(*next<*first)
            return false;
        ++first;
    }
    return true;
}