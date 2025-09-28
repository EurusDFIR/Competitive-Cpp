#include <algorithm>
#include <bits/stdc++.h>
#include <cstddef>
#include <ios>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;

    vector<int>v;
    v.reserve(n);
   
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        v.push_back(temp);
    }
    int id1, id2;
     int min =v[0];
     int max=v[0];
    for (int i=0;i<n;i++){
        if (v[i]< min){
            min = v[i];
            id1=i;
        }
        if (v[i] > max){
            max = v[i];
            id2=i;
        }
    }

    cout<<"Min: "<<min<<" at index "<<id1<<"\n";
    cout<<"Max: "<<max<<" at index "<<id2<<"\n";

    return 0;
}