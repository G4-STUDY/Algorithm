#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector<int> ledge[101];
vector<int> hedge[101];
queue<int> q;
bool visit[101];
int cnt;

void ldfs(int cur)
{
    for(int next:ledge[cur]){
        if(visit[next])continue;
        visit[next]=true;
        cnt++;
        ldfs(next);
    }   
}

void hdfs(int cur)
{
    for(int next:hedge[cur]){
        if(visit[next])continue;
        visit[next]=true;
        cnt++;
        hdfs(next);
    }   
}

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    for(vector<int> v:results){
        int high=v[0];
        int low=v[1];
        ledge[low].push_back(high);
        hedge[high].push_back(low);
    }
    for(int i=1;i<=n;i++){
        cout<<'\n';
        for(int j=1;j<=n;j++)visit[j]=0;
        visit[i]=true;
        cnt=1;//나
        ldfs(i);//나보다 약한사람들
        hdfs(i);//나보다 쎈사람들
        cout<<cnt<<' ';
        if(cnt!=n)continue;
        answer++;
    }
    return answer;
}
    