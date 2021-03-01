#include <iostream>
using namespace std;
/*
Computing a binomail coeff can take exponential time to be done.
by DP it can be done in n*k time or n^2

*/
int get_Min(int num1, int num2)
{
    return num1 < num2 ? num1 : num2;
}
int Compute(int n, int k)
{
    if (n < k)
        return -1;
    if (n == k)
        return n;
    else
    {
        //create matrix of size n*k
        int **Matrix = new int *[n + 1];
        for (int i = 0; i <= n; i++)
            Matrix[i] = new int[k + 1];
        //fill the matrix
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= k; j++)
            {
                if (j == 0 || i == 0 || j == i) //fill first row and first column with 1s , nCn = 1 too
                {
                    Matrix[i][j] = 1;
                }
                else
                    Matrix[i][j] = Matrix[i - 1][j] + Matrix[i - 1][j - 1];
            }
        }
        return Matrix[n][k];
    }
}
int main()
{
    int n, k;
    cout << "insert n and k (nCk)" << endl;
    cin >> n >> k;
    cout << "result of " << n << "C" << k << " : " << Compute(n, k) << endl;
}

/*
Test case : 6C3 = 20
*/