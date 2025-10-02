#include "bits/stdc++.h"
#include<ios>
#include <vector>

using namespace std;


int main(){

    ios_base::sync_with_stdio(false);

    int n;
    cin>>n;
    vector<int>v(n);

    for (int i=0;i<n;++i){
        cin>>v[i];
    }

    int pos, value;
    cin>>pos>>value;
    int posEra;
    cin>>posEra;

    v.insert(v.begin() + pos, value);
    v.erase(v.begin() + posEra);

    for (int x: v){
        cout<<x<<" ";
    }

    return 0;
}