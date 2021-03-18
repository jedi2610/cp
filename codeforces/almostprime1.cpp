#include<cstdio>
#include<algorithm>

using namespace std;
#define MAX 3001

bool isprime[MAX];
int div_arr[MAX]={0};

int main()
{
    //sieve almost prime
    for(int i=2;i<MAX;i++)
    {
        if(!isprime[i])
        {
            //i is prime
            for(int j=2*i;j<MAX;j+=i) {
                isprime[j]=1;
                div_arr[j]++;
            }
        }
    }

    int N, ret = 0;
    scanf("%d",&N);

    for(int i=1;i<=N;i++)
        if(div_arr[i]==2)
            ret++;

    printf("%d\n",ret);
    return 0;
}
