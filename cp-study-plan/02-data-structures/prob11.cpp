#include<bits/stdc++.h>
#include <cstddef>
#include<ios>
#include<climits>
#include <ratio>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;

    vector<int>v(n);
    vector<int>v2(m);
    for (int i=0;i<n;++i){
        cin>>v[i];
    }
    for (int i=0;i<m;++i){
        cin>>v2[i];
    }
    int i=0;
    int j=0;

    vector<int>result;
    result.reserve(n+m);
    while(i< v.size() && j < v2.size()){
        if (v[i] < v2[j]){
            result.push_back(v[i]);
            ++i;
        }
        else{
            result.push_back(v2[j]);
            ++j;
        }
    }
    while(i<v.size()){
        result.push_back(v[i]);
        ++i;
    }
    while(j<v2.size()){
        result.push_back(v2[j]);
        ++j;
    }
    
    for(int x :result){
        cout<<x<<" ";
    }

    return 0;
}