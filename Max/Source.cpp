#include <iostream>
#include <cstring>

template <class T>
T maxn(T ar[], int n)
{
    T max = ar[0];
    for (int i(0); i < n; i++)
        if (max < ar[i])
            max = ar[i];
    return max;
}
template<> const char* maxn <const char*>(const char* ar[], int n);

int main()
{
    int a[6]{ 1,4,7,4,8,5 };
    double d[4]{ 234.4,6.3,7.4,67.4 };
    const char* arr[4]{ "Maxim", "Maximilian", "Maximus", "Maxi Lopez" };
    std::cout << maxn(a, 6) << std::endl;
    std::cout << maxn(d, 4) << std::endl;
    std::cout << maxn(arr, 4);


    return 0;
}
template<> const char* maxn(const char* ar[], int n)
{
    unsigned maxstr = 0;
    int k = 0;
    for (int i(0); i < n; i++)
    {
        if (maxstr < strlen(ar[i]))
        {
            maxstr = strlen(ar[i]);
            k = i;
        }
    }
    return ar[k];
}