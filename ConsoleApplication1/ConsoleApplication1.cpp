#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

void checkValidInput()
{
    if (cin.fail())
    {
        cerr << "Incorrect data has been entered." << endl;
        exit(-1);
    }
}

double calculateY(double x, int n)
{
    double y;
    if (x < 0)
    {
        y = 1;
        for (int j = 2; j <= n - 2; j++)
        {
            y *= (j * j + x);
        }
    }
    else
    {
        y = 1;
        int p = 1;
        for (int i = 0; i <= n - 1; i++)
        {
            for (int j = 0; j <= n - 1; j++)
            {
                p *= (x + i * i + j);
                y += p;
                p = 1;
            }
        }
    }
    return y;
}

void nValidation(double x, int n)
{
    if ((x < 0 && n < 2) || (x >= 0 && n < 3))
    {
        cerr << "Error" << endl;
        exit(-1);
    }
}

void dataValidation(double a, double b, double h, int n)
{
    if (b < a || h <= 0 || n < 2)
    {
        cerr << "Error: invalid input data." << endl;
        exit(-1);
    }
}

void saveResultsToFile(ofstream& outputFile, double a, double b, double h, int n, int iteration)
{
    string fileName = "result" + to_string(iteration) + ".txt";
    int saveToFile;
    cout << "Do you want to save the results to a file? (1 - Yes/0 - No): ";
    cin >> saveToFile;
    if (saveToFile == 1)
    {
        outputFile.open(fileName, ios::app);
    }
    double x = a;
    while (x <= b)
    {
        nValidation(x, n);
        double result = calculateY(x, n);

        cout << "x:" << x << endl;
        cout << "y:" << result << endl;

        if (outputFile.is_open())
        {
            outputFile << "x:" << x << endl;
            outputFile << "y:" << result << endl;
        }

        x += h;
    }

    if (outputFile.is_open())
    {
        outputFile.close();
        if (saveToFile == 1)
        {
            cout << "Results have been successfully saved to the file " << fileName << "." << endl;
        }
    }
}

int main()
{
    int iteration = 1;

    while (true)
    {
        double a, b, h;
        int n;
        cout << "Enter the values of a, b, h, and n" << endl;
        cin >> a >> b >> h >> n;
        checkValidInput();
        dataValidation(a, b, h, n);
        ofstream outputFile;
        saveResultsToFile(outputFile, a, b, h, n, iteration);
        cout << "Do you want to perform another calculation? (1 - Yes/0 - No): ";
        int repeat;
        cin >> repeat;
        if (repeat == 0)
        {
            return 0;
        }
        system("cls");
        iteration++;
    }
    return 0;
}

