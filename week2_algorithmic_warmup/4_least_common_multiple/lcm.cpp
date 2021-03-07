#include <iostream>

int gcd_fast(int a, int b)
{
  int rem;
  while (b != 0)
  {
    rem = a % b, a = b, b = rem;
  }
  return a;
}

long long lcm_fast(int a, int b)
{
  return (long long)a * b / gcd_fast(a, b);
}

long long lcm_naive(int a, int b)
{
  for (long l = 1; l <= (long long)a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long)a * b;
}

int main()
{
  int a, b;
  std::cin >> a >> b;
  //std::cout << lcm_naive(a, b) << std::endl;
  std::cout << lcm_fast(a, b) << std::endl;
  return 0;
}
