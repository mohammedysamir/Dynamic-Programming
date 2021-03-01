#include <iostream>
#include <vector>
using namespace std;
/*
Coin-row problem: is a maximze problem, we have N coins and we need to pick up most valuable coins
                 within a constrain ==> don't pick up 2 adjecent coins
*/
//return maximum of 2 numbers
int get_Max(int num1, int num2)
{
    return num1 > num2 ? num1 : num2;
}

int main()
{
    int Num_Coins;
    cout<<"Enter number of Coins: ";
    cin >> Num_Coins;
    cout<<endl;

    int MaxValue = INT16_MIN;
    cout<<"Start to insert set of Coins: ";
    int *Set_of_Coins = new int[Num_Coins];
    for (int i = 0; i < Num_Coins; i++)
        cin >> Set_of_Coins[i];
    cout<<endl;
    //we need to create a matrix of size 2*(N+1)
    //first row for coins values, second one for the function that determine the max set of coins
    int **Coins = new int *[2];
    for (int j = 0; j < 2; j++)
        Coins[j] = new int[Num_Coins + 1];

    for (int i = 0; i <= Num_Coins; i++) //filling the matrix
    {
        if (i == 0)
        {
            //fill first column with 0
            Coins[0][i] = 0;
            Coins[1][i] = 0;
        }
        else
        {
            Coins[0][i] = Set_of_Coins[i - 1];
            if (i > 1)
                Coins[1][i] = get_Max(Coins[0][i] + Coins[1][i - 2], Coins[1][i - 1]); //max(Ci + F(n-2) , F(n-1))
            else
                Coins[1][i] = Coins[0][i];
        }
    }
    MaxValue = Coins[1][Num_Coins];
    cout<<"Maximum value:"<<MaxValue<<endl;

    vector<int> Selected_Coins;
    //Now we need to find the set of coins that achieve most value
    int Searched_value = MaxValue;


    for (int i = Num_Coins; i > 0; i--)
    {
        if (Coins[1][i] == Searched_value && Coins[1][i] != Coins[1][i - 1])
        {
            //include this coin and subtract searched value by the coin value
            Selected_Coins.push_back(Coins[0][i]);
            Searched_value -= Coins[0][i];
        }
        //else skip , this is not a part of solution
    }

    //print Coins
    cout << "Selected coins are: ";
    for (int i = 0; i < Selected_Coins.size(); i++)
        cout << Selected_Coins.at(i) << " ";
    cout << endl;
}

/*
Test case 1:-

Num_Coin=6
Coins: 5 1 2 10 6 2
Max value = 17
Selected Coins: 5 10 2
*/