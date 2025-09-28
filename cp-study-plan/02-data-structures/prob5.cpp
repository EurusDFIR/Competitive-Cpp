#include <algorithm>
#include<bits/stdc++.h>
#include<ios>
#include <vector>

using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int n;
    cin>>n;
    vector<int>v;
    for (int i=0;i<n;++i){
        int temp;
        cin>>temp;
        v.push_back(temp);
    }

    reverse(v.begin(), v.end());

    for(int x:v){
        cout<<x<<" ";
    }

    




    return 0;
}