#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct imageData
{
    int dataSize;
    uint8_t *data;

    void getImageData(string path)
    {
        ifstream imageFile(path, ios::in | ios::binary | ios::ate); // Opens setting position to the end of file. This is to find the file size in a bit.
        dataSize = imageFile.tellg();
        imageFile.seekg(0, ios::beg);   // Sets the position back to the beggining.
        data = new uint8_t[dataSize];
        imageFile.read(reinterpret_cast<char*>(data), dataSize);
    }

    imageData() {}

    imageData(string path)
    {
        getImageData(path);
    }

};

struct gifDecode
{
    imageData gifData;

    static constexpr int header_size = 6;
    uint8_t *header;   // Byte header.

    static constexpr int *logicalScreenDescriptor_size = 7;
    uint8_t *logicalScreenDescriptor

    uint16_t canvasWidth;
    uint16_t canvasHeight;

    bool globalColorTableFlag;
    bool sortFlag;

    uint8_t bitColorDepth;

    bool GCTF;  // Global color table flag
    bool sortF; // Sort flag.

    uint8_t bitColorDepth;
    uint16_t globalColorTableSize;       // Global color table size.
    uint8_t backgroundColorIndex;
    uint8_t pixelAspectRatio;

    bool fail;


    gifDecode(string path)
    {
        gifData.getImageData(path);
        fail = false;

        if(gifData.dataSize < 6)    // Sanity check, prevents out of bounds. Needs to be larger than this, around 14 so far?????????????????????????????
        {
            fail = true;
            return;
        }

        header = gifData.data;
        logicalScreenDescriptor = gifData.data + header_size;   // Stores address after header into LSD.

        canvasWidth = (logicalScreenDescriptor[1] << 8) | logicalScreenDescriptor[0];
        canvasHeight = (logicalScreenDescriptor[3] << 8) | logicalScreenDescriptor[2];

        globalColorTableFlag = (logicalScreenDescriptor[4] & 0b10000000 == 0b10000000) ? true : false;
        sortFlag = logicalScreenDescriptor[4] & 0b00001000 == 0b00001000 ? true : false;    // Normally I let binary digits hang, 0b1 is 1, 0b10 is 2, etc, but sometimes I get it backwards, thinking thats the high end, 0b1 is 128, which is wrong.

        if(globalColorTableFlag)
        {
            bitColorDepth = (logicalScreenDescriptor[4] >> 4) & 0b0111) + 1;
            globalColorTableSize = 1 << ( logicalScreenDescriptor[4] & 0b00000111 );    // Should be the same as 2 pwr (N + 1), where N came from last 3 bits of LSD[4];
            backgroundColorIndex = logicalScreenDescriptor[5];
        }
        else
        {
            backgroundColorIndex = 0;
            // Uncertain.
        }

        pixelAspectRatio = (logicalScreenDescriptor[6] + 15) / 64;          // May have to change to just store the value. Seems float would be more appropriate but being an old format idk.??????????????????



    }



};




int main()
{
    gifDecode test("C:\\x.gif");

    // for(int i = 0; i < test.dataSize; i++) { cout<< char(test.data[i]) << " " << uint64_t(test.data[i]) << endl; }
    cout << "Height is " << test.canvasHeight << endl;
    cout << "Width is " << test.canvasWidth << endl;

    return 0;
}

