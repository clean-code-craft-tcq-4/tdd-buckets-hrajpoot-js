#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "test/catch.hpp"
#include "range_detection.h"


TEST_CASE("Case 1: test detect sample ranges") 
{
        int chargingSessionSamples[] = { 4,5 };
        int NumbersOfSamples = sizeof(chargingSessionSamples) / sizeof(chargingSessionSamples[0]);

        auto sampleRangeReading = detectAndFetchSampleRanges(chargingSessionSamples, NumbersOfSamples);

        REQUIRE(sampleRangeReading.size() == 1);
        REQUIRE(sampleRangeReading["4-5"] == 2);
}

TEST_CASE("Case 2: test detect sample ranges") 
{
        int chargingSessionSamples[] = { 3, 3, 5, 4, 10, 11, 12 };
        int NumbersOfSamples = sizeof(chargingSessionSamples) / sizeof(chargingSessionSamples[0]);

        auto sampleRangeReading = detectAndFetchSampleRanges(chargingSessionSamples, NumbersOfSamples);

        REQUIRE(sampleRangeReading.size() == 2);
        REQUIRE(sampleRangeReading["3-5"] == 4);
        REQUIRE(sampleRangeReading["10-12"] == 3);
}

TEST_CASE("Case 3: test detect sample ranges")
{
        int chargingSessionSamples[] = {};
        int NumbersOfSamples = sizeof(chargingSessionSamples) / sizeof(chargingSessionSamples[0]);

        auto sampleRangeReading = detectAndFetchSampleRanges(chargingSessionSamples, NumbersOfSamples);

        REQUIRE(sampleRangeReading.size() == 0);
}

TEST_CASE("Case 4: test detect sample ranges")
{
        int chargingSessionSamples[] = { -1, 3, 4, 5, 20, 21, 25, 12, 14, 15 };
        int NumbersOfSamples = sizeof(chargingSessionSamples) / sizeof(chargingSessionSamples[0]);

        auto sampleRangeReading = detectAndFetchSampleRanges(chargingSessionSamples, NumbersOfSamples);

        REQUIRE(sampleRangeReading.size() == 6);
        REQUIRE(sampleRangeReading["-1"] == 1);
        REQUIRE(sampleRangeReading["12"] == 1);
        REQUIRE(sampleRangeReading["14-15"] == 2);
        REQUIRE(sampleRangeReading["20-21"] == 2);
        REQUIRE(sampleRangeReading["25"] == 1);
        REQUIRE(sampleRangeReading["3-5"] == 3);
}

TEST_CASE("test sortme function")
{
    int chargingSessionSamples[] = {8,4,6,5,3,1,17};
    int NumbersOfSamples = sizeof(chargingSessionSamples) / sizeof(chargingSessionSamples[0]);
    
    bool isArraySorted = (end(chargingSessionSamples) == adjacent_find( begin(chargingSessionSamples), 
                                                                        end(chargingSessionSamples), greater<int>()));
    REQUIRE(isArraySorted == false);
    
    sortme(chargingSessionSamples, NumbersOfSamples);
    
    isArraySorted = (end(chargingSessionSamples) == adjacent_find( begin(chargingSessionSamples), 
                                                                        end(chargingSessionSamples), greater<int>()));
    REQUIRE(isArraySorted == true);
}

TEST_CASE("test bits to amps conversion")
{
    REQUIRE(bit_to_amps_conversion(1146) == 3);
}
