#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

//NAME;AFIF SHAQIR IRFAN BIN ARQAM
//MATRIC NUM:A23CS0204
//DATE:6/1/2024

// Global
const int data_F = 8;
float fahren[data_F];
float C[data_F];
float total = 0.0;
float avg;
char desc[data_F];
int High, Med, Low;

//F1
void readFile() {
    ifstream var;
    var.open("file.txt");

    if (!var.is_open()) {
        cout << "While opening a file an error is encountered" << endl;
    }

    for (int i = 0; i < data_F; ++i) {
        var >> fahren[i];
    }
    var.close();
}

//F2
void computeC() {
    for (int i = 0; i < data_F; i++)
        C[i] = (5.0 / 9.0) * (fahren[i] - 32);
}

//F3
float average(float C[], int data_F) {
    float total = 0.0;

    for (int i = 0; i < data_F; i++) {
        total += C[i];
    }
    float avg = (total / data_F);
    return avg;
}

//F4
void grade() {
    for (int i = 0; i < data_F; i++) {
        if (C[i] >= 35.0) {
            desc[i] = 'H';
            High++;
        } else if ((C[i] >= 20) && (C[i] <= 35)) {
            desc[i] = 'M';
            Med++;
        } else {
            desc[i] = 'L';
            Low++;
        }
    }
}

//F5
void writeFile() {
    ofstream output;
    output.open("output.txt");

    output<<"   C(Celcius)      F(Farenheit)            Description   \n";
	output<<"   ==========      ============            ===========   \n";

    for (int i = 0; i < data_F; i++) {
        output << fixed << setprecision(2) << setw(12) << C[i] << setw(17) << fahren[i] << setw(20) << desc[i] << "\n";
    }
    output.close();
}

int main() {
    readFile();
    computeC();
    grade();
    avg = average(C, data_F);
    cout << fixed << setprecision(1) << "Average of the temperature in Celsius: " << avg << endl;
    cout << "Number of high temperature: " << High << endl;
    cout << "Number of medium temperature: " << Med << endl;
    cout << "Number of low temperature: " << Low;
    writeFile();
    return 0;
}

