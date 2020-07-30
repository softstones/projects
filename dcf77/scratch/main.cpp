#include <iostream>
using namespace std;

int decodeHours(const uint16_t input[]){
    int result = 0;

    if(input[29]){
        result = result + 1;
    }
    if(input[30]){
        result = result + 2;
    }
    if(input[31]){
        result = result + 4;
    }
    if(input[32]){
        result = result + 8;
    }
    if(input[33]){
        result = result + 10;
    }
    if(input[34]){
        result = result + 20;
    }

    return result;
}

int decodeMinutes(const uint16_t input[]){
    int result = 0;

    if(input[21]){
        result = result + 1;
    }
    if(input[22]){
        result = result + 2;
    }
    if(input[23]){
        result = result + 4;
    }
    if(input[24]){
        result = result + 8;
    }
    if(input[25]){
        result = result + 10;
    }
    if(input[26]){
        result = result + 20;
    }
    if(input[27]){
        result = result + 40;
    }

    return result;
}

int decodeDayOfMonth(const uint16_t input[]){
    int result = 0;

    if(input[36]){
        result = result + 1;
    }
    if(input[37]){
        result = result + 2;
    }
    if(input[38]){
        result = result + 4;
    }
    if(input[39]){
        result = result + 8;
    }
    if(input[40]){
        result = result + 10;
    }
    if(input[41]){
        result = result + 20;
    }
    return result;
}

int decodeMonth(const uint16_t input[]){
    int result = 0;

    if(input[45]){
        result = result + 1;
    }
    if(input[46]){
        result = result + 2;
    }
    if(input[47]){
        result = result + 4;
    }
    if(input[48]){
        result = result + 8;
    }
    if(input[49]){
        result = result + 10;
    }
    return result;
}

int decodeYear(const uint16_t input[]){
    int result = 0;

    if(input[50]){
        result = result + 1;
    }
    if(input[51]){
        result = result + 2;
    }
    if(input[52]){
        result = result + 4;
    }
    if(input[53]){
        result = result + 8;
    }
    if(input[54]){
        result = result + 10;
    }
    if(input[55]){
        result = result + 20;
    }
    if(input[56]){
        result = result + 40;
    }
    if(input[57]){
        result = result + 80;
    }

    return result;
}

int decodeDayofWeek(const uint16_t input[]){
    int result = 0;

    if(input[42]){
        result = result + 1;
    }
    if(input[43]){
        result = result + 2;
    }
    if(input[44]){
        result = result + 4;
    }

    return result;
}


int main()
{
    cout.precision(10);

    const uint16_t B = 59;

    const uint16_t sampleData[B] = {
        0,                              //Start of minute, always zero                  [0]     (X)
        1,1,0,1,1,1,0,0,0,0,1,0,0,1,    //Civil warning bits                            [1:14]
        0,                              //Call bit, abnormal operation                  [15]    (X)
        0,                              //Summer time announcement.                     [16]
        1,                              //Set to 1 when CEST is in effect               [17]
        0,                              //Set to 1 when CET is in effect                [18]
        0,                              //Leap second announcement                      [19]
        1,                              //Start of encoded time. Always 1.              [20]    (X)
        1,1,0,0,1,0,1,0,                //Encoded minutes (00-59)                       [21-27]
        0,                              //Even parity bit over encoded minutes          [28]
        0,0,0,0,1,1,                    //Encoded hours (0-23)                          [29-34]
        0,                              //Even parity bit over encoded hours            [35]
        0,0,0,1,1,0,                    //Encoded day of month (01-31)                  [36-41]
        0,1,1,                          //Encoded day of week (monday = 1, sunday = 7)  [42-44]
        1,1,0,0,0,                      //Encoded month number (01-12)                  [45-49]
        0,0,0,0,1,0,0,                  //Encoded year (00-99)                          [50-57]
        1                               //Even parity over date bits                    [58]
    };


        if((sampleData[0] == 0) && (sampleData[15] == 0) && (sampleData[20] == 1)){
            // check if the buffer is filled with a full 58 bits (B-size) of time data
            // Maybe theres a better way to check for this? (assuming you're going to store the data in a circular buffer or something)
            // The chance of this event occuring randomly is 12.5%, parity check to confirm?

            cout << "Time is "  << decodeHours(sampleData)
                                << ":"
                                << decodeMinutes(sampleData)
                                << " "
                                << decodeDayOfMonth(sampleData)
                                << "/"
                                << decodeMonth(sampleData)
                                << "/20"
                                << decodeYear(sampleData)
                                << endl;

            cout << "Day of week is " << decodeDayofWeek(sampleData)<< endl;

    }

    return 0;
}
