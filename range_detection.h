#include <bits/stdc++.h>
using namespace std;

map<string, int> detectAndFetchSampleRanges(int chargingSessionSamples[], int numberOfSamples);
void display_readings(map<string, int> sampleRangeReadings);
void sortme(int arr[], int size);
int bit_to_amps_conversion(double bitInput);
string high_fidelity_current_sensing(int inputBits);
