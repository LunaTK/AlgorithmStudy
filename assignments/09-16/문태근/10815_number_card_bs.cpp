#include <cstdio>
#include <algorithm>
#define for_range(i, n) for (int i = 0; i < n; i++)

using namespace std;

int N, M;
int deck[500000];

bool exist_in_deck_binary_search(int num, int from, int until)
{
    bool exist = false;
    int pivot = (from + until) / 2;
    if (from < until)
    {
        if (deck[pivot] == num)
        {
            exist = true;
        }
        else if (deck[pivot] > num)
        {
            exist = exist_in_deck_binary_search(num, from, pivot);
        }
        else if (deck[pivot] < num)
        {
            exist = exist_in_deck_binary_search(num, pivot + 1, until);
        }
    }
    return exist;
}

int main(void)
{
    int num;
    scanf("%d", &N);
    for_range(i, N)
    {
        scanf("%d", &deck[i]);
    }
    sort(deck, deck + N);
    scanf("%d", &M);
    for_range(i, M)
    {
        scanf("%d", &num);
        printf("%d ", exist_in_deck_binary_search(num, 0, N));
    }
    printf("\n");
}