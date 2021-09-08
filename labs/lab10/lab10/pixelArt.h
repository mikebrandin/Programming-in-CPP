#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class pixelArt
{
public:
    pixelArt(int w, int h);
    int getW() const;
    int getH() const;
    int getPixel(int i, int j);
    void readArts(const char* fileName);
    pixelArt operator + (int num);
    pixelArt operator - (int num);
    pixelArt operator + (const pixelArt& pa);
    friend ostream& operator<<(ostream& os, const pixelArt& pa);
private:
    vector<vector<int> > pixels;
    int w;
    int h;
};

void output(pixelArt& pa);
