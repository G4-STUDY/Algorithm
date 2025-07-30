#include <iostream>

using namespace std;

//int arr[10001]; 
int edge[10001][2];
bool rootcheck[10001];//root 찾기
int root=-1;
int idx;
int level[10001][2];//level[x][0]=x레벨의 가장왼쪽 ,level[x][1]=가장 오른쪽 
int maxdepth;
int len[10001];

void dfs(int cur,int depth){
    if(edge[cur][0]!=0){//왼쪽탐색
        dfs(edge[cur][0],depth+1);
    }
    //arr[idx]=cur;
    if(level[depth][0]>idx)level[depth][0]=idx; //같은 레벨의 왼쪽보다 작으면
    if(level[depth][1]<idx)level[depth][1]=idx; //같은 레벨의 오른쪽보다 크면
    idx++;
    if(edge[cur][1]!=0){//오른쪽 탐색
        dfs(edge[cur][1],depth+1);
    }
    maxdepth=max(maxdepth,depth);//깊이 갱신
}

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        if(b==-1)b=0;
        edge[a][0]=b;
        if(c==-1)c=0;
        edge[a][1]=c;
        //root 찾기
        rootcheck[b]=true;
        rootcheck[c]=true;
    }
    //root find
    for(int i=1;i<=n;i++){
        if(!rootcheck[i]){
            root=i;
            break;
        }
    }
    //초기화
    for(int i=0;i<10001;i++){
        level[i][0]=1e9;
        level[i][1]=-1;
    }
    maxdepth=0;
    idx=0;
    //루트 넣고 탐색
    dfs(root,0);
    int maxlen=0;
    for(int i=0;i<=maxdepth;i++){//레벨별로
        len[i]=level[i][1]-level[i][0]+1;//길이[i] = 오른쪽idx - 왼쪽idx +1
        maxlen=max(maxlen,len[i]);//가장 긴 레벨 갱신
    }
    
    for(int i=0;i<=maxdepth;i++){
        if(maxlen==len[i]){//가장 긴레벨이면 
            cout<<i+1<<' '<<maxlen;//레벨 ' ' 깊이
            break;
        }
    }
    return 0;
}

/*
칸결정? 중위순회
root는 안정해져있는거같은데 
root 찾고 중위순회 idx 구하고
depth 별로 넓이구하기
*/