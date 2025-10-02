#include<bits/stdc++.h>
#include <cstddef>
#include<ios>
#include<vector>
#include<climits>



using namespace std;

int main(){

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    int n, target;
    cin>>n>>target;

    vector<int>v(n);
    v.reserve(n);
    for (int i=0;i<n;i++){
        cin>>v[i];
    }

    int left, right;
    left =0;
    right = n-1;

    while(left <=right){
       int mid = (left + right)/2;
        if (v[mid] == target){
            cout<<v[mid];
            break;
        }
        else if (v[mid] > target){
            right = mid -1;
        }
        else if(v[mid] < target){
            left = mid +1;
        }
        else{
            cout<<-1;
            break;
        }
    }




    return 0;
}