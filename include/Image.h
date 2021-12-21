
#include "Pixel.h"
#include "ImageDataStructure.h"
#include <vector>
class Image{
public:
    Image();
    Image(int height, int width);
    Image(int height, int width, unsigned char pixel);
    Image(const Image& other);
    int getHeight()const{return m_imageMat.getHeight();};
    int getWidth()const{return m_imageMat.getwidth();};
    Image& operator = (const Image&);
    Image& operator += (const Image&);
    Image& operator |= (const Image&);
    Image& operator &= (const Image&);
    Image& operator *= (int);
    Pixel& operator () (unsigned int,unsigned int);
    const Pixel& operator () (unsigned int,unsigned int)const;
private:
    void swap(Image& other);
    ImageDataStructure m_imageMat;
};
//===================================================
bool operator == (const Image& lhs, const Image& rhs);
bool operator != (const Image& lhs, const Image& rhs);
Image operator + (const Image& lhs, const Image& rhs);
Image operator | (const Image& lhs, const Image& rhs);
Image operator & (const Image& lhs, const Image& rhs);
std::ostream& operator<< (std::ostream&, const Image&);
Image operator * (const Image&, int);
Image operator * (int ,const Image&);
Image operator ~ (const Image&);


