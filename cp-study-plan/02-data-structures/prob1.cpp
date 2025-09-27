#include <bits/stdc++.h>
#include <ios>
#include <vector>

using namespace std;



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);



    vector<int>v;
    v.reserve(1000000);
    int q;
    cin>>q;
    while(q--){
        int op;
        cin>>op;
        switch (op) {
            case 1: 
                int value; cin>>value;
                v.push_back(value); break;
            case 2: if(!v.empty()) v.pop_back(); break;
            case 3: cout<<v.size()<<"\n"; break;
            case 4: 
                for (int x: v){
                    cout<< x<<" ";
                }
        }
    }


    return 0;
}