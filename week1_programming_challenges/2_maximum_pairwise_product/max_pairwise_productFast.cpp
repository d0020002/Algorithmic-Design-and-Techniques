#include <iostream>
#include <vector>

using namespace std;

long long max_pairwise_productFast(vector<int> numbers);
int main()
{
    int n;
    cin >> n;

    vector<int> numbers(n);
    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }
    cout << max_pairwise_productFast(numbers);
}

long long max_pairwise_productFast(vector<int> numbers)
{
    int n = numbers.size();
    int max_index1 = -1, max_index2 = -1;

    for (int i = 0; i < n; i++)
    {
        if (max_index1 == -1 || numbers[i] > numbers[max_index1])
        {
            max_index1 = i;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (i != max_index1 && (max_index2 == -1 || numbers[i] > numbers[max_index2]))
        {
            max_index2 = i;
        }
    }
    return (long long)numbers[max_index1] * numbers[max_index2];
}