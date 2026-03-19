#include <iostream>
#include <fstream>
using namespace std;

// TODO: Step 1 - Define the struct TemperatureRecord
// It should contain two integer fields: day and temperature.

struct TemperatureRecord {
    int day; 
    int temperature;
};

// Constants
const int MAX_DAYS = 31;

// Function Prototypes
void readTemperatures(TemperatureRecord arr[], int& size); // TODO: Fix the parameters
void printTemperatures(const TemperatureRecord arr[], int size);
int findMin(const TemperatureRecord array[], int size);
int findMax(const TemperatureRecord array[], int size);
double findAverage(const TemperatureRecord array[], int size);

int main() {
    // TODO: Step 2 - Declare an array of TemperatureRecord structs (MAX_DAYS size)

    TemperatureRecord temperatures[MAX_DAYS];
    
    int size = 0;  // Actual number of records read

    // TODO: Step 3 - Call readTemperatures() to load data from file

    readTemperatures(temperatures, size);

    // TODO: Step 4 - Print the temperatures

    printTemperatures(temperatures, size);

    // TODO: Step 5 - Compute and display min, max, and average temperature

    int min = findMin(temperatures, size);
    cout << "Lowest temperature: " << min << endl;

    int max = findMax(temperatures, size);
    cout << "Highest temperature: " << max << endl;

    int avg = findAverage(temperatures, size);
    cout << "Average temperature: " << avg;

    return 0;
}

// TODO: Step 6 - Implement readTemperatures()
// Read from "temps.txt" and store data in the array

void readTemperatures(TemperatureRecord arr[], int& size) {
    ifstream infile;
    infile.open("temps.txt");
    if (!infile.is_open()) {
        cout << "Error, could not open file." << endl;
    }
    cout << "Reading file..." << endl;
    
    while ((size < MAX_DAYS) && (infile >> arr[size].day >> arr[size].temperature)) {
        size++;
    }
}

// TODO: Step 7 - Implement printTemperatures()
// Print all stored temperatures in a formatted table

void printTemperatures(const TemperatureRecord arr[], int size) {
    cout << "Day     Temp" << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i].day << "       " << arr[i].temperature << endl;
    }
}

// TODO: Step 8 - Implement findMin()
// Return the TemperatureRecord with the lowest temperature

int findMin(const TemperatureRecord array[], int size) {
    int min = array[0].temperature;
    for (int i = 0; i < size; i++) {
        if (array[i].temperature < min) {
            min = array[i].temperature;
        }
    }

    return min;
}

// TODO: Step 9 - Implement findMax()
// Return the TemperatureRecord with the highest temperature

int findMax(const TemperatureRecord array[], int size) {
    int max = array[0].temperature;
    for (int i = 0; i < size; i++) {
        if (array[i].temperature > max) {
            max = array[i].temperature;
        }
    }

    return max;
}

// TODO: Step 10 - Implement findAverage()
// Compute and return the average temperature

double findAverage(const TemperatureRecord array[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i].temperature;
    }

    int avg = sum / size;

    return avg;
}