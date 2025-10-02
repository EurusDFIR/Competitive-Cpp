#include <algorithm>
#include<bits/stdc++.h>
#include<ios>
#include <vector>


using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;

    vector<int>v(n);
    v.reserve(n);

    for(int i=0;i<n;i++){
       cin>>v[i];
       
    }
//  two pointer Technique
    sort(v.begin(), v.end());
    
    int i=0;
    for (int j=1;j<n;j++){
        if (v[i] !=v[j]){
            ++i;
            v[i]=v[j];
        }
    }
    v.resize(i+1);

    for (int x: v){
        cout<<x<<"\n";
    }
 

    
    return 0;
}