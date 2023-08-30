//Allen Ace Abel
//Enrico Dizon
//Javier Bolong
#include <iostream>
#include <fstream>
#include <vector>

class XYDataProcessor {
public:
    bool importFromFile(const std::string& filename, std::vector<float>& xValues, std::vector<float>& yValues) {
        std::ifstream inputFile(filename);

        if (!inputFile.is_open()) {
            std::cerr << "Failed to open file: " << filename << std::endl;
            return false;
        }

        float x, y;
        while (inputFile >> x >> y) {
            xValues.push_back(x);
            yValues.push_back(y);
        }

        inputFile.close();
        return true;
    }
};

float crossCorrelation(const std::vector<float>& X_raw, const std::vector<float>& Y_raw, int n_X, int n_Y) {
    float average_X = 0, average_Y = 0, proc_X = 0, proc_Y = 0, counter = 0, hold = 0;

    std::vector<float> list_proc_X = {};
    std::vector<float> list_proc_Y = {};

    std::vector<float> cross_X = {};
    std::vector<float> cross_Y = {};

    std::vector<float> r_XY = {};

    for (int i = 0; i < n_X; i++) {
        average_X += X_raw[i];
    }
    average_X = average_X / n_X;

    for (int i = 0; i < n_Y; i++) {
        average_Y += Y_raw[i];
    }
    average_Y = average_Y / n_Y;

    std::cout << "Average of list X: " << average_X << std::endl;
    std::cout << "Average of list Y: " << average_Y << std::endl;

    for (int j = 0; j < n_X; j++) {
        proc_X = X_raw[j] - average_X;
        list_proc_X.push_back(proc_X);
        std::cout << proc_X << ", ";
    }
    std::cout << std::endl;

    for (int j = 0; j < n_Y; j++) {
        proc_Y = Y_raw[j] - average_Y;
        list_proc_Y.push_back(proc_Y);
        std::cout << proc_Y << ", ";
    }
    std::cout << std::endl;

    if (list_proc_X.size() > list_proc_Y.size()) {
        counter = list_proc_X.size();
    } else {
        counter = list_proc_Y.size();
    }

    for (int k = 0; k < counter; k++) {
        hold = 0;

        for (int l = 0; l < k; l++) {
            hold += list_proc_X[0 + k] * list_proc_Y[counter - l];
        }

        r_XY.push_back(hold);
    }
    std::cout << "r_xy sequence: ";
    for (int a = 0; a < r_XY.size(); a++) {
        std::cout << r_XY[a] << ", ";
    }
    std::cout << std::endl;
     std::ofstream outputFile("cross_correlation.txt");
    if (outputFile.is_open()) {
        for (int i = 0; i < r_XY.size(); i++) {
            outputFile << r_XY[i] << std::endl;
        }
        outputFile.close();
        std::cout << "Sucess" << std::endl;
    } else {
        std::cerr << "Failed to open " << std::endl;
    }
    return 0;
}

int main() {
    XYDataProcessor processor;
    std::vector<float> X_values;
    std::vector<float> Y_values;

    if (processor.importFromFile("xyvalues.txt", X_values, Y_values)) {
        std::cout << "Import successful";

        int n_X = X_values.size();
        int n_Y = Y_values.size();
        float X[n_X];
        float Y[n_Y];
        for (int i = 0; i < n_X; i++) {
            X[i] = X_values[i];
        }
        for (int i = 0; i < n_Y; i++) {
            Y[i] = Y_values[i];
        }

        crossCorrelation(X, Y, n_X, n_Y);
    } else {
        std::cerr << "Import failed." << std::endl;
    }

    return 0;
}
