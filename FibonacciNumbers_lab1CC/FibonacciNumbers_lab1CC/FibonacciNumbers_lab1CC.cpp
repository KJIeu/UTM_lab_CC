#include <iostream>
#include <chrono> 

using namespace std;
using namespace std::chrono;


long long DynamicAlgorithm(int n);

long long RecursiveAlgorithm(int n);

long long BinetFormula(int n);

long long MatrixDerivationAlgorithm(int n);

unsigned long long f[1000000];


int main()
{
    int n = 10;     //introduce n number here

    
        cout << "n = " << n << "\n";
        
        cout << "====================";
        cout << "\n\tDynamic Programic Algorithm\n";
        auto StartTime = high_resolution_clock::now();
        unsigned long long answer = DynamicAlgorithm(n);
        auto EndTime = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(EndTime - StartTime);
        cout << "Time of execution : " << duration.count() << " microseconds\n";
        cout << "Answer : " << answer;


        cout << "\n====================\n";
        cout << "\tRecursive Algoritm\n";
        StartTime = high_resolution_clock::now();
        answer = RecursiveAlgorithm(n);
        EndTime = high_resolution_clock::now();
        duration = duration_cast<microseconds>(EndTime - StartTime);
        cout << "Time of execution : " << duration.count() << " microseconds\n";
        cout << "Answer : " << answer;

        cout << "\n====================\n";
        cout << "\tBinet Formula\n";
        StartTime = high_resolution_clock::now();
        answer = BinetFormula(n);
        EndTime = high_resolution_clock::now();

        duration = duration_cast<microseconds>(EndTime - StartTime);
        cout << "Time of execution : " << duration.count() << " microseconds\n";
        cout << "Answer : " << answer;

        cout << "\n====================\n";
        cout << "\tMatrix Derivation Algorithm\n";
        StartTime = high_resolution_clock::now();
        answer = MatrixDerivationAlgorithm(n);
        EndTime = high_resolution_clock::now();
        cout << "Time of execution : " << duration.count() << " microseconds\n";
        cout << "Answer : " << answer;
        cout << "\n====================\n";
}

long long DynamicAlgorithm(int n) {
    long long f[2] = { 0, 1 };
    long long reminder;
    for (int i = 2; i <= n; i++)
    {
        reminder = f[1];
        f[1] = f[0] + f[1];
        f[0] = reminder;
    }
    return f[1];
}


long long RecursiveAlgorithm(int n) {
    if (n <= 1)
        return n;
    return RecursiveAlgorithm(n - 1) + RecursiveAlgorithm(n - 2);
}


long long BinetFormula(int n) {

    double index = pow(5, 0.5);
    double phi = (1 + index) / 2;

    return round(pow(phi, n) / index);
}


long long MatrixDerivationAlgorithm(int n)
{
    if (n == 0)
        return 0;
    if (n == 1 || n == 2)
        return 1;
    if (f[n])
        return f[n];

    int k = (n & 1) ? (n + 1) / 2 : n / 2;

    return (f[n] = (n & 1) ? (MatrixDerivationAlgorithm(k) * MatrixDerivationAlgorithm(k) 
        + MatrixDerivationAlgorithm(k - 1) * MatrixDerivationAlgorithm(k - 1))
        : (2 * MatrixDerivationAlgorithm(k - 1) + MatrixDerivationAlgorithm(k)) * MatrixDerivationAlgorithm(k));
}

/*

*+*+*+*+*+*+*+*+*+*+*+*+*+*
*  _____________________  *
* |  Made by Boico Alex | *
* |   github.com/KJIeu  | *
* |_____________________| *
*                         *
*+*+*+*+*+*+*+*+*+*+*+*+*+*

*/

