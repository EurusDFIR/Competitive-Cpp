#include "bits/stdc++.h"
#include <unistd.h>
#include <vector>
#include <ios>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);

    int n ;
    cin>>n;
    double  sum=0;
    double avg=0;
    vector<int>v;
    v.reserve(n);


    for (int i=0;i<n;++i){
        int temp;
        cin>>temp;
        v.push_back(temp);
    }
    for (int x:v){
        sum+=x;
       
    }
    avg=1.0*sum/v.size();
    cout<<"Sum: "<<sum<<"\n";
    cout<<"Average: "<<avg<<"\n";
    




    return 0;
}