#include <algorithm>
#include<bits/stdc++.h>
#include <climits>
#include<ios>
#include <vector>



using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<int>v(n);
    v.reserve(n);
    for (int i=0;i<n;++i){
        cin>>v[i];

    }

    int currSum=0;
    int maxSum = INT_MIN;

    //BRUTE FORCE WAY: vetcan
    // for (int i=0;i<n;++i){
    //     currSum =0;
    //     for (int j=i;j<n;++j){
    //         currSum+=v[j];
    //         maxSum = max(currSum, maxSum);
    //     }

    // }

    // cout<<maxSum<<"\n";


}
