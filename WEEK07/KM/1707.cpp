#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k;
    cin >> k;
    while (k--)
    {
        int v, e;
        cin >> v >> e;
        int visit[20001];

        vector<int> edge[20001];
        //초기화 안해서 틀렸었음..
        for(int i=1;i<=v;i++){
            edge[i].clear();
            visit[i]=false;
        }
        for (int i = 0; i < e; i++)
        {
            int a, b;
            cin >> a >> b;
            edge[a].push_back(b);
            edge[b].push_back(a);
        }
        bool ans = true;
        for (int i = 1; i <= v; i++)
        {
            if(!ans)break;
            if (visit[i])continue;
            queue<pair<int, bool>> q;
            visit[i] = 1;
            q.push({i, false});
            while (!q.empty() && ans)
            {
                int cur = q.front().first;
                bool tmp = q.front().second;
                q.pop();
                for (int next : edge[cur])
                {
                    bool nexttmp = !tmp;
                    if (visit[next])
                    {
                        if (visit[next] != 1 + nexttmp)
                        {
                            // 이미 방문했는데 다른집합에가야돼?
                            ans = false;
                            break;
                        }
                    }
                    else
                    {
                        visit[next] = 1 + nexttmp;
                        q.push({next, nexttmp});
                    }
                }
            }
        }
        if (ans)
        {
            cout<<"YES\n";
        }
        else
        {
            cout<<"NO\n";
        }
    }
    return 0;
}
/*
...
이분그래프 조건?
1-2-3
{1,3},{2}

1-2-3
   \|
    4

이미 방문처리된 노드를 방문하려고하면?? 안되는건가
1-2-3
  |
  4
{1,3,4}{2}

나랑 1단계로 연결된놈은 반대집합에 넣기
또 연결된놈을 반대집합에 넣기
넣을때마다 이미 들어가있으면 false?

1-2-3
| |
5-4


1   2 5
34


1-2
3-4
4-5
3-5



모든정점이 연결되어있지 않음..
결국 모든정점에서 bfs 해봐야댐
반례)
1
5
4
1 2
3 4
4 5
3 5

1-2

3-4
 \|
  5


1-2
|
5-4-3

변수 종류	저장 영역	초기화 여부	설명
전역 변수	데이터 영역	✅ 자동 0 초기화	프로그램 시작 시 초기화
static 변수	데이터 영역	✅ 자동 0 초기화	함수 안에서도 동일
지역 변수	스택	❌ 자동 초기화 안됨	값은 미정 (undefined behavior)


*/
