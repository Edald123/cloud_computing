#include "pch.h"
#include <iostream>

#ifdef _OPENMP
    #include <omp.h>
#else
    #define omp_get_thread_num() 0
#endif

using namespace std;
int tid;

int main()
{   
    while (true)
    {
        const int n = 1000;
        int randArray[n];
        int randArray2[n];
        int random;

        cout << "Press 1 to use random numbers or 0 to specify the numers: ";
        cin >> random;
        if (random == 1)
        {
            for (int i = 0; i < n; ++i)
            {
                randArray[i] = rand() % n; //number between 0-n
                randArray2[i] = rand() % n;
            }
        }
        else
        {
            int userNumber;
            cout << "Numbers for Array 1--------" << endl;
            for (int i = 0; i < n; ++i)
            {
                cout << "enter a number for array 1: ";
                cin >> randArray[i];
            }
            cout << "Numbers for Array 2--------" << endl;
            for (int i = 0; i < n; ++i)
            {
                cout << "enter a number for array 2: ";
                cin >> randArray2[i];
            }
        }

        cout << "------Array 1, first 10 values--------" << endl;
        for (int i = 0; i < 10; ++i)
        {
            cout << randArray[i] << " ";
        }
        cout << endl << "------Array 2, first 10 values--------" << endl;
        for (int i = 0; i < 10; ++i)
        {
            cout << randArray2[i] << " ";
        }

        // creating the sum of arrays in parallel
        cout << endl << "<<<<<<<Making the sum of the 2 arrays>>>>>>>" << endl;
        int newArray[n];

        int nThreads;
        cout << "# of threads to use: ";
        cin >> nThreads;

        #pragma omp parallel for num_threads(nThreads)
        for (int i = 0; i < n; ++i)
        {
            newArray[i] = randArray[i] + randArray2[i];
        }
        

        cout << "-------New Array, first 10 values--------" << endl;
        for (int i = 0; i < 10; i++)
        {
            cout << newArray[i] << " ";
        }

        cout << endl << "NEW EXECUTION" << endl;
    }
}
