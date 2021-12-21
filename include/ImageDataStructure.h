#include <iostream>
#include <stdlib.h>
#include "Pixel.h"

class ImageDataStructure{
public:
    ImageDataStructure();
    ImageDataStructure(int,int);
    ImageDataStructure(int,int,Pixel);
    ImageDataStructure(const ImageDataStructure& other);
    ~ImageDataStructure();
    Pixel* operator[](size_t index) const;
    ImageDataStructure& operator = (const ImageDataStructure& other);
    int getHeight()const {return m_height;}
    int getwidth()const { return m_width;}
private:
    void swap(ImageDataStructure& other);
    Pixel ** M_matrix;
    int m_height = 0;
    int m_width = 0;
};
