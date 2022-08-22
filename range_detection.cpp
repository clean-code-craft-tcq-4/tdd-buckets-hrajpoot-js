#include "range_detection.h"

void sortme(int arr[], int size)
{
    sort(arr, arr+size);
}

int bit_to_amps_conversion(double bitInput)
{
    return round( (10 * bitInput) / 4094 );
}

string high_fidelity_current_sensing(int inputBits)
{
    int apmsInput = bit_to_amps_conversion(inputBits);
    string returnValue = "";
    if (apmsInput >= 0 and apmsInput <= 10)
    {
        returnValue = to_string(apmsInput) + "A";
    }
    else
    {
        returnValue = "An error case";
    }

    return returnValue;
}

map<string, int> detectAndFetchSampleRanges(int chargingSessionSamples[], int numberOfSamples)
{
    int rangeReading = 1;
    map<string, int> sampleRangeReading;
 
    //sort the samples
    sortme(chargingSessionSamples, numberOfSamples);
	
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
