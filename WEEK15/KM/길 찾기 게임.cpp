#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
pair<int,int> tree[40001];//x값,idx값
vector<pair<pair<int,int>,int>> nodes;
vector<int> prearr;
vector<int> postarr;
bool comp(pair<pair<int,int>,int> a,pair<pair<int,int>,int> b){
    if(a.first.second==b.first.second){
        return a.first.first<b.first.first;
    }
    return a.first.second>b.first.second;
}

void treepush(int node,pair<int,int> x){
    if(tree[node].second==0){
        tree[node]=x;
        return;
    }
    if(x.first<tree[node].first){
        treepush(node*2,x);
    }
    else{
        treepush(node*2+1,x);
    }
    //나보다 x값 작은것중에 y값 가장큰게 왼쪽노드
    //나보다 x값 큰것중에 y값 가장 큰게 오른쪽 노드
}

void pre(int node){
    if(tree[node].second==0) return;
    //cout<<tree[node].second<<' ';
    prearr.push_back(tree[node].second);
    pre(node*2);
    pre(node*2+1);
}

void post(int node){
    if(tree[node].second==0) return;
    post(node*2);
    post(node*2+1);
    postarr.push_back(tree[node].second);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    int idx=1;
    for(vector<int> node:nodeinfo){
        pair<pair<int,int>,int> p;
        p.first.first=node[0];
        p.first.second=node[1];
        p.second=idx;
        nodes.push_back(p);
        idx++;
    }    
    sort(nodes.begin(),nodes.end(),comp);
    for(pair<pair<int,int>,int> n:nodes){
        pair<int,int> p;
        p.first=n.first.first;
        p.second=n.second;
        treepush(1,p);
    }
    pre(1);
    post(1);
    answer.push_back(prearr);
    answer.push_back(postarr);
    return answer;
}


/*
노드는 전부다른값을 가진다
root 는 y값 제일큰거
y값순으로 정렬하고 ㄱㄱ

나보다 x값 작은것중에 y값 가장큰게 왼쪽노드
나보다 x값 큰것중에 y값 가장 큰게 오른쪽 노드
--틀림
why? 원소가 10000개인데 완전이진트리가 아니라 idx가 2^10000승까지 갈수있음..
트리구조체로 바꾸면 정답..
*/