#include "range_detection.h"

void sortme(int arr[], int size)
{
    sort(arr, arr+size);
}

map<string, int> detectAndFetchSampleRanges(int chargingSessionSamples[], int numberOfSamples)
{
    int rangeReading = 1;
    map<string, int> sampleRangeReading;
 
    //sort the samples
    sort(chargingSessionSamples, chargingSessionSamples+numberOfSamples);
	
    for(int start = 1; start <= numberOfSamples; start++)
    {
        if (start == numberOfSamples or chargingSessionSamples[start] - chargingSessionSamples[start - 1] != 1 
            and chargingSessionSamples[start] - chargingSessionSamples[start - 1] > 0)
        {
            if (rangeReading == 1)
            {
                string sampleStr = to_string(chargingSessionSamples[start - rangeReading]); 
                sampleRangeReading.insert({sampleStr, rangeReading});
            }
            else
            {
                string tempStr = to_string(chargingSessionSamples[start - rangeReading]) + "-" + to_string(chargingSessionSamples[start - 1]);
                sampleRangeReading.insert({tempStr, rangeReading});
            }
            rangeReading = 1;
        }
        else
        {
            rangeReading++;
        }
    }
    return sampleRangeReading;
}

void display_readings(map<string, int> sampleRangeReadings)
{
    for (auto &a : sampleRangeReadings)
    {
        cout << a.first << ", " << a.second << endl;
    }
}
