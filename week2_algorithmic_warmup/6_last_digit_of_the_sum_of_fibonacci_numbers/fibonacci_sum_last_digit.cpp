#include <iostream>

int get_fibonacci_last_digit_fast(long long n)
{
    int f[n + 1];
    f[0] = 0, f[1] = 1;
    for (long long i = 2; i <= n; i++)
    {
        f[i] = (f[i - 1] + f[i - 2]) % 10;
    }
    return f[n];
}

int fibonacci_sum_fast(long long n)
{
    return ((get_fibonacci_last_digit_fast(n % 60) + get_fibonacci_last_digit_fast((n + 1) % 60)) - 1) % 10;
}

int fibonacci_sum_naive(long long n)
{
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current = 1;
    long long sum = 1;

    for (long long i = 0; i < n - 1; ++i)
    {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

int testsolutions()
{
    int n;
    while (true)
    {
        // n = rand() % 1000 + 1;
        n = 100;
        if (fibonacci_sum_naive(n) != fibonacci_sum_fast(n))
        {
            std::cout << n << " ";
            std::cout << fibonacci_sum_naive(n) << " " << fibonacci_sum_fast(n) << std::endl;
            break;
        }
    }
    return 0;
}

int main()
{
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_fast(n);
    //testsolutions();
}
