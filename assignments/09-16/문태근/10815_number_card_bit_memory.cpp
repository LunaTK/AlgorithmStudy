#include <cstdio>
#include <algorithm>
#define for_range(i, n) for (int i = 0; i < n; i++)

using namespace std;

int N, M;

unsigned int bit_memory[625000] = {0};

bool exist_in_bit_memory(int num)
{
    num += 10000000;
    return (bit_memory[num / 32] >> (num % 32)) % 2 == 1;
}

void set_bit_to_1(int num)
{
    num += 10000000;
    bit_memory[num / 32] += (1 << (num % 32));
}

int main(void)
{
    int num;
    scanf("%d", &N);
    for_range(i, N)
    {
        scanf("%d", &num);
        set_bit_to_1(num);
    }
    scanf("%d", &M);
    for_range(i, M)
    {
        scanf("%d", &num);
        printf("%d ", exist_in_bit_memory(num));
    }
    printf("\n");
}