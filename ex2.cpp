#include <iostream>
using namespace std;

int main()
{
    float wage, new_wage;
    int company_time;
    cout << "Current wage: ";
    cin >> wage;
    cout << "Company time: ";
    cin >> company_time;

    if (company_time < 0)
        cout << "Company time can't be lower than 0, mf.";
    else
    {
        if (company_time <= 2)
            new_wage = wage * 1.03;
        else if (company_time <= 5)
            new_wage = wage * 1.05;
        else if (company_time <= 10)
            new_wage = wage * 1.07;
        else
            new_wage = wage * 1.09;
        cout << "Your new wage is: R$" << new_wage;
    }
    cin.get();
    return 0;
}
