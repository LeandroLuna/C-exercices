#include <bits/stdc++.h>
using namespace std;

int sum(int arr[],int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++){
        sum += arr[i];
    }
    return sum;
}
 
// Driver code
int main()
{
    int ar[] = {12, 3, 4, 15};
    int n = *(&ar + 1) - ar;
    cout << "Array size: " << n << endl;
    cout << "Sum of given array is " << sum(ar, n);
    return 0;
}