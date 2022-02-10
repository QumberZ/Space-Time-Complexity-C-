#include<iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <ratio>
#include <chrono>
using namespace std;
using namespace std::chrono;

int steps = 0;
void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void BubbleSort(int a[], int n) {

    for (int i = 0; i < n - 1; i++)
    {
        steps += 2;
        for (int j = 0; j < n - i - 1; j++) {
            steps += 2;

            if (a[j] > a[j + 1])

                steps += 2;
                swap(a[j], a[j + 1]);
        }
    }
}

int main()

{

    srand(0);

    int n[8] = {100, 300, 500, 1000, 3000, 5000, 10000, 50000 };



    int* a1;

    int* a2;

    int* a3;



    for (int i = 0; i < 2; i++)

    {
        //for loop for Task two 50 times (incomplete)

        int size = n[i];

        a1 = new int[size];

        a2 = new int[size];

        a3 = new int[size];

        //assign 1,2,...n-1, n to a1

        for (int j = 1; j <= size; j++)

        {

            a1[j - 1] = j;

            a3[j - 1] = j;

        }

        //assign n, n-1, ... , 2, 1 to a2

        for (int j = size; j > 0; j--)

        {

            a2[size - j] = j;

        }

        //random permutations

        for (int k = 0; k < size; k++) // 1  2 3 ....100  its not repeated  after numbers I randomized 

        {

            int index = rand() % size;

            int temp = a3[k];

            a3[k] = a3[index];

            a3[index] = temp;

        }

        cout << endl;

        for (int a = 0; a < size; a++)

        {

            cout << a1[a] << " ";

        }

        cout << endl;

        high_resolution_clock::time_point t1 = high_resolution_clock::now();
        BubbleSort(a1, size);
        high_resolution_clock::time_point t2 = high_resolution_clock::now();

        duration<double> time_span1 = duration_cast<duration<double>>(t2 - t1);



        std::cout << "It took me " << time_span1.count() << " seconds.";
        cout << endl;
        cout << steps << endl;
        steps = 0;
        for (int a = 0; a < size; a++)

        {

            cout << a1[a] << " ";

        }

        cout << endl;
        cout << endl;

        for (int a = 0; a < size; a++)

        {

            cout << a2[a] << " ";

        }

        cout << endl;

        high_resolution_clock::time_point t4 = high_resolution_clock::now();
        BubbleSort(a2, size);
        high_resolution_clock::time_point t5 = high_resolution_clock::now();
        duration<double> time_span2 = duration_cast<duration<double>>(t5 - t4);



        std::cout << "It took me " << time_span2.count() << " seconds.";
        cout << endl;
        cout << steps << endl;
        steps = 0;

   

        for (int a = 0; a < size; a++)

        {

            cout << a2[a] << " ";

        }

        cout << endl;
        cout << endl;

        for (int a = 0; a < size; a++)

        {

            cout << a3[a] << " ";

        }

        cout << endl;

        high_resolution_clock::time_point t6 = high_resolution_clock::now();
        BubbleSort(a3, size);
        high_resolution_clock::time_point t7 = high_resolution_clock::now();
        duration<double> time_span3 = duration_cast<duration<double>>(t7 - t6);



        std::cout << "It took me " << time_span3.count() << " seconds.";
        cout << endl;
        cout << steps << endl;
        steps = 0;
        for (int a = 0; a < size; a++)

        {

            cout << a3[a] << " ";

        }

        cout << endl;




    }
    return 0;
}

