#include <iostream>

int fibonacci_fast(int n, int m)
{
    int f[n + 1];
    f[0] = 0, f[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        // I have still to wrap head around this
        f[i] = (f[i - 1] + f[i - 2]) % m;
    }
    return f[n];
}

int get_pisano(int m)
{

    int cur, prv = -1;
    for (int i = 2; i <= m * m; i++)
    {
        cur = fibonacci_fast(i, m) % m;
        // std::cout << "{" << cur << ", " << prv << "}"
        //           << "\n";
        if (prv == 0 && cur == 1)
        {
            return i - 1;
        }
        prv = cur;
    }
    return -1;
}

long long get_fibonacci_huge_fast(long long n, long long m)
{
    int Pisano = get_pisano(m);
    int equivalentFib = n % Pisano;
    return fibonacci_fast(equivalentFib, m) % m;
}

long long get_fibonacci_huge_naive(long long n, long long m)
{
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current = 1;

    for (long long i = 0; i < n - 1; ++i)
    {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

int main()
{
    long long n, m;
    std::cin >> n >> m;
    // std::cout << get_fibonacci_huge_naive(n, m) << '\n';

    std::cout << get_fibonacci_huge_fast(n, m) << '\n';

    // int n;
    // std::cin >> n;
    // std::cout << get_pisano(n);
}
