#include <iostream>
using namespace std;
//산타의 생일선물 2
int q;
int n, m;
class Box
{
public:
    Box *prev;
    Box *next;
    int num = -1;
    Box(int x)
    {
        prev = NULL;
        next = NULL;
        num = x;
    }
};

class Belt
{
public:
    int num;
    Box *Head;
    Box *Tail;
    Belt()
    {
        Head = new Box(-1);
        Tail = new Box(-1);
        Head->prev = NULL;
        Head->next = Tail;
        Tail->prev = Head;
        Tail->next = NULL;
        num = 0;
    }
};
Belt *factory[100001];

void printbelt()
{
    for (int i = 1; i <= n; i++)
    {
        cout << i << "st belt: ";
        Box *tmp = factory[i]->Head;
        for (int j = 0; j < factory[i]->num; j++)
        {
            tmp = tmp->next;
            cout << tmp->num << ',';
        }
        cout << '\n';
    }
}

void insert_back(int idx, Box *b)
{
    factory[idx]->num++; // 개수증가
    factory[idx]->Tail->prev->next = b;
    b->prev = factory[idx]->Tail->prev;
    b->next = factory[idx]->Tail;
    factory[idx]->Tail->prev = b;
}

void init()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        factory[i] = new Belt();
    }
    int idx;
    for (int i = 1; i <= m; i++)
    {
        cin >> idx;
        // cout<<"insert "<<i<<" to "<<idx<<"\n";
        insert_back(idx, new Box(i));
    }
    printbelt();
}

void cleanbelt(int idx)
{
    factory[idx]->Head->next = factory[idx]->Tail;
    factory[idx]->Tail->prev = factory[idx]->Head;
    factory[idx]->num = 0;
}
/*
head  1 2 3 tail
head  1  tail
head->next->prev=
*/
void moving()
{
    int src, dst;
    cin >> src >> dst;
    factory[dst]->Head->next->prev = factory[src]->Tail->prev;
    factory[src]->Tail->prev->next = factory[dst]->Head->next;
    /*
    src의 뒤 연결
    */
    factory[dst]->Head->next = factory[src]->Head->next;
    factory[dst]->Head->next->prev = factory[dst]->Head;
    // 앞부분연결
    // 개수더하기
    factory[dst]->num += factory[src]->num;
    cleanbelt(src);
    cout << factory[dst]->num << '\n';
    printbelt();
}

void change()
{
}

void divide()
{
}

void giftinfo()
{
}

void beltinfo()
{
}

int main()
{
    cin >> q;
    int op;
    for (int i = 0; i < q; i++)
    {
        cin >> op;
        switch (op)
        {
        case 100:
            init();
            break;
        case 200:
            moving();
            break;
        case 300:
            change();
            break;
        case 400:
            divide();
            break;
        case 500:
            giftinfo();
            break;
        case 600:
            beltinfo();
            break;
        default:
            break;
        }
    }
    return 0;
}