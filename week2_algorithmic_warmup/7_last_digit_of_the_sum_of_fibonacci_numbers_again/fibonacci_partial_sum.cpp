#include <iostream>
#include <vector>
using std::vector;

int get_fibonacci_last_digit_fast(int n)
{
    int f[n + 1];
    f[0] = 0, f[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        f[i] = (f[i - 1] + f[i - 2]) % 10;
    }
    return f[n];
}

int fibonacci_sum_fast(long long n)
{
    return ((get_fibonacci_last_digit_fast(n % 60) + get_fibonacci_last_digit_fast((n + 1) % 60)) - 1) % 10;
}

long long get_fibonacci_partial_sum_fast(long long from, long long to)
{
    int last_of_to = fibonacci_sum_fast(to);
    if (from != 0)
        from -= 1;
    int last_of_from = fibonacci_sum_fast(from);
    if (last_of_from > last_of_to)
    {
        last_of_to += 10;
    }
    return (last_of_to - last_of_from) % 10;
}

long long get_fibonacci_partial_sum_naive(long long from, long long to)
{
    long long sum = 0;

    long long current = 0;
    long long next = 1;

    for (long long i = 0; i <= to; ++i)
    {
        if (i >= from)
        {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}

void test_solutions()
{
    int from, to;
    while (true)
    {
        from = rand() % 100;
        to = rand() % 10 + from;
        if (get_fibonacci_partial_sum_fast(from, to) != get_fibonacci_partial_sum_naive(from, to))
        {
            std::cout << "MIS  " << from << ", " << to << "  ";
            std::cout << get_fibonacci_partial_sum_fast(from, to) << " " << get_fibonacci_partial_sum_naive(from, to);
            std::cout << std::endl;
            break;
        }
        else
        {
            std::cout << "OK";
        }
    }
}

int main()
{
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
    // test_solutions();
}
