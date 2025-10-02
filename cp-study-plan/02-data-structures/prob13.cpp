#include<bits/stdc++.h>
#include <cstddef>
#include<ios>
#include<algorithm>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<int>v(n);
    v.reserve(n);
    for(int i=0;i<n;++i){
        cin>>v[i];
    }

    bool check=next_permutation(v.begin(), v.end());
    if(check == true){
        for(int x:v)cout<<x<<" ";
    }
    else{
        cout<<"1 2 3";
    }



    return 0;
}