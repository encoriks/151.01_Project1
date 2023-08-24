//Allen Ace Abel
//Javier Bolong
//Enrico Dizon
// Program to find correlation coefficient
#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;
//testing pushing
//COdeblock gaming testing
// function that returns correlation coefficient.
double crossCorrelation(double X_raw[], double Y_raw[], double n_X, double n_Y)
{
    //proc means processed
    //proc = average - X or Y(n)
    double average_X = 0, average_Y = 0, proc_X = 0, proc_Y = 0, counter = 0, hold = 0;

    vector<double> list_proc_X = {};
    vector<double> list_proc_Y = {};

    vector<double> cross_X = {};
    vector<double> cross_Y = {};

    vector<double> r_XY = {};

    //loops for averages
    for (int i = 0; i < n_X; i++)
    {
        average_X += X_raw[i];
    }
    average_X = average_X / n_X;

    for (int i = 0; i < n_Y; i++)
    {
        average_Y += Y_raw[i];
    }
    average_Y = average_Y / n_Y;

    cout << "Average of list X: " << average_X << endl;
    cout << "Average of list Y: " << average_Y << endl;

    // obtaining X(n), and Y(n)
    for (int j = 0; j < n_X; j++)
    {
        proc_X = X_raw[j] - average_X;
        list_proc_X.push_back(proc_X);
        cout << proc_X << ", ";
    }
    cout << endl;

    for (int j = 0; j < n_Y; j++)
    {
        proc_Y = Y_raw[j] - average_Y;
        list_proc_Y.push_back(proc_Y);
        cout << proc_Y << ", ";
    }
    cout << endl;

    //checking which line
    if (list_proc_X.size() > list_proc_Y.size())
    {
        counter = list_proc_X.size();
    }
    else
    {
        counter = list_proc_Y.size();
    }

    for(int k = 0; k < counter; k++)
    {
        hold = 0;

        for(int l = 0; l < k; l++)
        {
            hold += list_proc_X[0 + k] * list_proc_Y[counter - l];
        }

        r_XY.push_back(hold);
    }
    cout << "r_xy sequence: ";
    for (int a = 0; a < r_XY.size(); a++)
    {

        cout << r_XY[a] << ", ";
    }
    cout << endl;
    return 0;
}

int main()
{

    double X[] = {1, 5, 10, 3, 5};
    double Y[] = {4, 2, 20, 3, -5};

    //Find the size of array.
    int n_X = sizeof(X)/sizeof(double);
    int n_Y = sizeof(Y)/sizeof(double);

    //Function call to crossCorrelation.
    crossCorrelation(X, Y, n_X, n_Y);

    cout << "successful transfer!" << endl;
    return 0;
}
