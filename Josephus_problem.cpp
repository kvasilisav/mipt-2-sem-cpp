#include<iostream> 

using namespace std;

struct node
{
    int item;
    node* next;

    node(int x, node* t)
    {
        item = x;
        next = t;
    }
};

typedef node* link;

int main()
{
    int i;
    int N;
    int M;
    cout << "enter the number of elements" << endl;
    cin >> N;
    cout << "enter the step" << endl;
    cin >> M;

    link t = new node(1, 0);
    t->next = t;

    link x = t;

    for (i = 2; i <= N; i++)
    {
        x = (x->next = new node(i, t));
    }

    while (x != x->next)
    {
        for (i = 1; i < M; i++)
        {
            x = x->next;
        }

        x->next = x->next->next;
    }
    cout << "Last alive: " << x->item << '\n';
    return 0;
}