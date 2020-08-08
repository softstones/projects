#define dataSize 4

int main()
{
    int data[dataSize] = { 15, 10, 7, 3 };
    int k = 17;

    int counter = 0;
    
    for (int i = 0; i < dataSize; i++) {
        int result = 0;
        result = data[counter] + data[i];

        if (result == k) {
            return 1;
        } 
        if (i == 3) {
            counter++;
            i = 0;
        }
    }
}
