#include <algorithm>
#include <bits/stdc++.h>
#include<ios>
#include<climits>
#include <vector>


using namespace  std;


int main(){

    int n, k;
    cin>>n>>k;


    vector<int>v(n);
    for (int i=0;i<n;++i){
        cin>>v[i];
    }

    k = k%n;
    reverse(v.begin(), v.end());
    reverse(v.begin(), v.begin()+k);
    reverse(v.begin()+k, v.end());

    for (int x: v){
        cout<<x<<" ";
    }

    return 0; 

}