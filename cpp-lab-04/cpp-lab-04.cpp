#include <iostream>
#include <fstream>
#include <chrono>
using namespace std;
using namespace std::chrono;

void Soup(long long n, char *outp)
{
    ofstream file(outp);

    unsigned long long total = ((1 + n)*n)/2;
    long long i = n;
    int count = 0, count1 = 0, count2 = 0;

    if (total % 2 != 0)
    {
        file << "NO" << endl;

        file.close();
    }

    else
    {
        long long target = total/2;

        file << "YES" << endl;

        while (target - i > 0)
        {
            count++;
            target -= i;
            i--;
        }

        target = total/2;

        for (long long i = n; i >= 0; i--)
        {
            if (target - i > 0)
            {
                target -= i;
                file << i << " ";
            }
        }

        file << endl;

        count2 = n - count1;
        target = total/2;

        file << count2 << endl;

        for (long long i = n; i >= 0; i--)
        {
            target -= i;
            file << i << " ";
        }

        file.close();
    }
}

void Test(long long n, char *output, char *input)
{
    auto start = high_resolution_clock::now();
    Soup(n, output);
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(stop-start);

    string str, str1, str2;

    ifstream file(input);

    while (getline(file, str))
    {
        cout << str << " ";
    }

    cout << endl;
    file.close();

    ifstream file1(output);

    while (getline(file1, str))
    {
        cout << str << " ";
    }

    cout << endl;
    file1.close();

    if (duration.count()/1000 < 1)
    {
        cout << "Passed | Execution time " << duration.count() << " milliseconds" << endl;
    }

    else
    {
        cout << "Error" << endl;
    }
}

int main()
{
    Test(17237842, "C:/cpp-lab-04/Tests/out1.txt", "C:/cpp-lab-04/Tests/in1.txt");
    Test(10000, "C:/cpp-lab-04/Tests/out2.txt", "C:/cpp-lab-04/Tests/in2.txt");
    Test(99999, "C:/cpp-lab-04/Tests/out3.txt", "C:/cpp-lab-04/Tests/in3.txt");
    Test(10000000, "C:/cpp-lab-04/Tests/out4.txt", "C:/cpp-lab-04/Tests/in4.txt");
    Test(37263, "C:/cpp-lab-04/Tests/out5.txt", "C:/cpp-lab-04/Tests/in5.txt");
}