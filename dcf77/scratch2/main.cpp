#include <iostream>
using namespace std;

uint16_t decodeDCF(const bool input[], uint8_t beginAdr, uint8_t endAdr){

    uint16_t result = 0;

    uint8_t k[8] = {1, 2, 4, 8, 10, 20, 40, 80};

    for(int i = 0; i<=(endAdr-beginAdr); i++){

        result += input[beginAdr+i]*k[i];

        }

    return result;
}



int main()
{
    const uint16_t B = 59; //array size

    const bool sampleData[B] = {
        0,1,1,0,1,1,1,0,0,0,0,1,0,0,1,0,0,1,0,0,1,1,1,0,0,1,0,1,0,
        0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,1,1,1,1,0,0,0,0,0,0,0,1,0,0,1
    };


        if((sampleData[0] == 0) && (sampleData[15] == 0) && (sampleData[20] == 1)){
            // check if the buffer is filled with a full 59 bits (B-size) of time data
            // Maybe there's a better way to check for this? (assuming you're going to store the data in a circular buffer or something)
            // The chance of this event occuring randomly is 12.5%, parity check to confirm?
            // Bit positions taken from: https://en.wikipedia.org/wiki/DCF77#Time_code_details

            cout << "Time is "  << decodeDCF(sampleData, 29, 34) //hours
                                << ":"
                                << decodeDCF(sampleData, 21, 27) //minutes
                                << " "
                                << decodeDCF(sampleData, 36, 41) //day of month
                                << "/"
                                << decodeDCF(sampleData, 45, 49) //month number
                                << "/20"
                                << decodeDCF(sampleData, 50, 57) //year number
                                << endl;

            cout << "Day of week is " <<decodeDCF(sampleData, 42, 44)<< endl;

    }

    return 0;
}
