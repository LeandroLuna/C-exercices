#include <iostream>
#include <locale>

using namespace std;

void delta (int a, int b, int c, int *d)
{
    *d = b*b-4*a*c;
}

int main()  {
    setlocale(LC_ALL,"");
    int a,b,c,d;
    cout << "digite os valores dos 3 coeficientes \n";
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    cout << "c = ";
    cin >> c;
    delta(a,b,c,&d);
    cout <<" O discriminante é "<< d <<endl;
    return 0;
}

