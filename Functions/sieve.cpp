#include <bits/stdc++.h>
using namespace std;
/*
for finding prime numbers we use a optimized way
we mark all the multiples of each prime number and then mark multiples of next unmarked element
and at last print only unmarked element
while iterating we start from i*i because before i^2 all elements are already marked so no need to mark again
*/
void primesieve(int n)
{
    int prime[1000] = {0};
    for (int i = 2; i <= n; i++)
    {
        if (prime[i] == 0)
        {
            for (int j = i * i; j <= n; j = j + i)
            {
                prime[j] = 1;
            }
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if (prime[i] == 0)
        {
            cout << i << " ";
        }
    }
    cout << endl;
}

void primefactor(int n)
{
    int spf[n + 1] = {0};
    spf[1] = 1;

    // making spf of all numbers as number itself
    for (int i = 2; i <= n; i++)
    {
        spf[i] = i;
    }

    // marking spf for all even numbers as 2
    for (int i = 4; i <= n; i += 2)
    {
        spf[i] = 2;
    }

    for (int i = 3; i * i <= n; i++)
    {
        // checking for prime number
        if (spf[i] == i)
        {
            // marking SPF for all numbers divisible by i
            for (int j = i * i; j <= n; j += i)
            {
                // marking SPF[j] if its not previously marked
                if (spf[j] == j)
                {
                    spf[j] = i;
                }
            }
        }
    }
    // printing prime factors
    while (n != 1)
    {
        cout << spf[n] << " ";
        n = n / spf[n];
    }
}

int main()
{
    // sieve of eratosthenes
    // to find prime number from 2 to n
    int n;
    cout << "Enter a Number : ";
    cin >> n;
    cout << "All prime numbers from " << 2 << " to " << n << " is : ";
    primesieve(n);

    // to find prime factorization of a number
    // cout << "Prime factors of " << n << " is : ";
    // primefactor(n);
    return 0;
}
