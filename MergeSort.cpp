#include<iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <ratio>
#include <chrono>
using namespace std;
using namespace std :: chrono;
int steps = 0;
void Merge(int a[], int begin, int mid, int end) {
    int i = begin;
    int j = mid + 1;
    int* b = new int[end - begin + 1];
    int k = 0;

    while (i <= mid && j <= end)
    {
        steps += 2;
        if (a[i] <= a[j])
        {
            steps += 4;
            b[k] = a[i];
            i++;
            k++;

        }
        else
        {
            steps += 3;
            b[k] = a[j];
            j++;
            k++;
        }
    }
    while (i <= mid) {
        steps += 4;
        b[k] = a[i];
        k++;
        i++;
    }
    while (j <= end) {
        steps += 4;
        b[k] = a[j];
        k++;
        j++;
    }

    for (i = begin, k = 0; i <= end; i++, k++) {
        steps += 4;
        a[i] = b[k];
    }

}

void Mergesort(int a[], int begin, int end) {
    if (begin < end) {
        int mid = (begin + end) / 2;
        Mergesort(a, begin, mid);
        Mergesort(a, mid + 1, end);
        Merge(a, begin, mid, end);
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

                                                  // we choose the number from the array and save it, 
            {                                     // then we pick the number from whats left and save it, except number we picked before
                                                  // then choose the number again, but without the numbers -
                int index = rand() % size;        // - we chose before ( last two numbers)
                                                  // repeat
                                                  // the array is getting shorter and shorter until there only-
                int temp = a3[k];                 //  - one number left to pick
                                                  // why ? becuase it need to be same for the all program
                a3[k] = a3[index];                //  - it cant be different numbers for all programs
                                                  // not sure what she meant by all this :c
                a3[index] = temp;              

            }

            cout << endl;

            for (int a = 0; a < size; a++)

            {

                cout << a1[a] << " ";

            }

            cout << endl;

            high_resolution_clock::time_point t1 = high_resolution_clock::now();   // high resolution clock
            Mergesort(a1, 0, size - 1);
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
            Mergesort(a2, 0, size - 1);
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
            Mergesort(a3, 0, size - 1);
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


