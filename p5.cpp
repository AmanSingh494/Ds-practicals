#include <bits/stdc++.h>
using namespace std;
double evaluatePolynomial(const vector<double> &coefficients, double n)
{
    double result = 0.0;
    int size = coefficients.size() - 1;

    for (int i = 0; i <= size; ++i)
    {
        result += coefficients[i] * pow(n, size - i);
    }

    return result;
}

int main()
{
    vector<double> coefficients; 
    int size = 0;
    int x = 0;
    cout << "Enter the number of terms in the polynomial" << endl;
    cin >> size;
    cout << "Enter the coefficients of the polynomial. For ex: if f(x) = 2x^2 + 3x + 1, enter : 2 3 1" << endl;
    for(int i = 0;i<size;i++){
        int element = 0;
        cin >> element;
        coefficients.push_back(element);
    }
    cout << "Enter the value of x" << endl;
    cin >> x;
    double result = evaluatePolynomial(coefficients, x);

    cout << "The value of the polynomial for x = " << x << " is " << result << endl;

    return 0;
}