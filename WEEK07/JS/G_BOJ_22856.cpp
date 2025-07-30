//오답

#include<iostream>
#include<vector>
#include<set>
using namespace std;
void inorder(int cur_node);
int left_child[100001];
int right_child[100001];
int n;
int move_dist = 0;
set<int> visited_node; 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    //이진 트리 생성 
    for(int i = 1; i <= n; i++)
    {
        int node, lc, rc;
        cin >> node >> lc >> rc;
        left_child[node] = lc;
        right_child[node] = rc;
    }
    inorder(1);
    
    cout << move_dist;
    return 0;

}

void inorder(int cur_node)
{
    visited_node.insert(cur_node);
    
    if(left_child[cur_node] != -1)
    {
        move_dist++;
        inorder(left_child[cur_node]);
        if(visited_node.size() != n) move_dist++;
    }
    if(right_child[cur_node] != -1)
    {
        move_dist++;
        inorder(right_child[cur_node]);
        if(visited_node.size() != n) move_dist++;
    }


}