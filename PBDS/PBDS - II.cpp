/*Output
0 1
1 3
2 4
3 10
4 15
3
*/
#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int , null_type , less<int> , rb_tree_tag , 
             tree_order_statistics_node_update>
             new_data_set;

int main(){
    
    new_data_set St;
    St.insert(1);
    St.insert(3);
    St.insert(4);
    St.insert(10);
    St.insert(15);

    //Kth largest element at till in O(logn)
    for(int i=0 ; i<St.size() ; i++){
        cout<<i<<" "<<*St.find_by_order(i) << endl;
    }
    
    //elements strictly smaller than 5
    cout<<St.order_of_key(5)<<endl;
   
}

