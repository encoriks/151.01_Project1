//Allen Ace Abel
//Javier Bolong
//Enrico Dizon
//Program to find correlation coefficient
#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;
//testing pushing
//COdeblock gaming testing
// function that returns correlation coefficient.
float crossCorrelation(float X_raw[], float Y_raw[], float n_X, float n_Y)
{
    //proc means processed
    //proc = average - X or Y(n)
    float average_X = 0, average_Y = 0, proc_X = 0, proc_Y = 0, counter = 0, hold = 0;

    vector<float> list_proc_X = {};
    vector<float> list_proc_Y = {};

    vector<float> cross_X = {};
    vector<float> cross_Y = {};

    vector<float> r_XY = {};

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

bool readFile(string filename, vector<string>& content)
{
  ifstream file(filename);
  if (!file.is_open())
  {
    cerr << "Error opening " << filename << endl;
    return false;
  }

  string line;
  while (getline(file, line))
  {
    content.push_back(line);
  }

  file.close();
  return true;
}

bool writeFile(const string& filename, const vector<string>& content)
{
  ofstream file(filename);
  if (!file.is_open())
  {
    cerr << "Error opening " << filename << " for writing" << endl;
    return false;
  }

   for (const string& line : content)
   {
      file << line << "\n";
   }

   file.close();
   return true;
}

int main(int argc, char* argv[])
{
  vector<string> file1Content, file2Content;

  if (!readFile("x.txt", file1Content) || !readFile("y.txt", file2Content))
  {
    cerr << "File could not be read." << endl;
    return 1;
  }

  file1Content.push_back("");
  file1Content.insert(file1Content.end(), file2Content.begin(), file2Content.end());

  if (!writeFile("output.txt", file1Content))
  {
    std::cerr << "Combined content could not be written to output.txt." << std::endl;
    return 1;
  }

  cout << "Text from file 1 and file 2 have been combined." << endl;

  float X[] = {1, 5, 10, 3, 5};
  float Y[] = {4, 2, 20, 3, -5};

  //Find the size of array.
  int n_X = sizeof(X)/sizeof(float);
  int n_Y = sizeof(Y)/sizeof(float);

  //Function call to crossCorrelation.
  crossCorrelation(X, Y, n_X, n_Y);

  cout << "successful transfer!" << endl;
  return 0;
}
