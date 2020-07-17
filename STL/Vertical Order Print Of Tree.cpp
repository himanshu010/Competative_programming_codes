//Vertical Order Print Of Tree
/*output
-2->4 
-1->2 
0->1 5 6 
1->8 3 
2->7 
3->9 
*/
#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node*left;
    node*right;

    node(int d){
        data = d;
        left = right = NULL;
    }
};
void verticalOrderPrint(node *root , int d , map<int , vector<int>> &mp){
    //base case
    if(root == NULL){
        return ;
    }
    //otherwise
    mp[d].push_back(root->data);
    verticalOrderPrint(root->left , d-1 , mp);
    verticalOrderPrint(root->right , d+1 , mp);
    return ;
}
int main() {
    node*root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);

    root->right->left = new node(6);
    root->right->right = new node(7);

    root->right->right->right = new node(9);
    root->left->right->right = new node(8);

    map<int , vector<int>> mp;
    int d = 0;
    verticalOrderPrint(root , d , mp);

    for(auto p : mp){
        cout<<p.first<<"->";
        for(auto x: p.second){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    return 0;
}
