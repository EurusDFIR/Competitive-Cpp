#include<bits/stdc++.h>
#include <cstddef>
#include<ios>
#include <vector>



using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int n;
    cin>>n;
    int occ;
    cin>>occ;
    vector<int>v;
    v.reserve(n);
    for(int i=0;i<n;++i){
        int temp;
        cin>>temp;

        v.push_back(temp);
    }
    int cnt=0;
    for (int i=0;i<n;i++){
        if (v[i] == occ){
            cnt+=1;
        }
    }
    cout<<cnt<<"\n";



    return 0;
}