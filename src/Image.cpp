

#include "Image.h"
#include <algorithm>

Image::Image():Image(0,0,' '){}
//----------------------------------------------------
Image::Image(int height, int width):Image(height,width,' '){}
//----------------------------------------------------
Image::Image(int height, int width, unsigned char pixel):m_imageMat(height,width,pixel){}
//----------------------------------------------------
Image::Image(const Image& other): m_imageMat(other.m_imageMat){}
//----------------------------------------------------
Image& Image::operator = (const Image& other)
{
    auto newImage = other;
    swap(newImage);
    return *this;
}
//----------------------------------------------------
Image& Image::operator += (const Image& other)
{
    *this = (*this + other);
    return *this;
}
//----------------------------------------------------
Image& Image::operator |= (const Image& other)
{
    *this = (*this | other);
    return *this;
}
//----------------------------------------------------
Image& Image::operator &= (const Image& other)
{
    *this = (*this & other);
    return *this;
}
//----------------------------------------------------
Image& Image::operator *= (int n)
{
    *this = (*this * n);
    return *this;
}
//----------------------------------------------------
Pixel& Image::operator () (unsigned int row,unsigned int col)
{
    return m_imageMat[row][col];
}
//----------------------------------------------------
const Pixel& Image::operator () (unsigned int row,unsigned int col)const
{
    return m_imageMat[row][col];
}
//----------------------------------------------------
void Image::swap(Image& other){
    auto temp = ImageDataStructure(m_imageMat);
    m_imageMat = other.m_imageMat;
    other.m_imageMat = temp;
}

//====================================================
//====================================================
//                      global
//                     operators
//====================================================
//====================================================
bool operator == (const Image& lhs, const Image& rhs)
{
    if(lhs.getHeight() != rhs.getHeight()
       || lhs.getWidth() != rhs.getWidth())
        return false;
    
    for (int i = 0; i < lhs.getHeight(); i++) {
        for (int j = 0; j < lhs.getWidth(); j++) {
            if(lhs(i,j) != rhs(i,j))
                return false;
        }
    }
    return true;
}
//----------------------------------------------------
bool operator != (const Image& lhs, const Image& rhs)
{
    return (lhs == rhs)? false:true;
}
//----------------------------------------------------
Image operator + (const Image& lhs, const Image& rhs)
{
    
    auto newImage = Image(std::max(lhs.getHeight(),rhs.getHeight()),lhs.getWidth()+rhs.getWidth());
    
    for(int row = 0 ; row < lhs.getHeight()  ;row++){
        for(int col = 0 ; col < lhs.getWidth()  ;col++){
            newImage(row,col) =  lhs(row,col);
        }
    }
    for(int row = 0 ,newRow = lhs.getHeight(); row < rhs.getHeight()  ;row++, newRow++){
        for(int col = 0 ,newCol = lhs.getWidth() ; col < rhs.getWidth()  ;col++, newCol++){
            newImage(newRow,newCol) =  lhs(row,col);
        }
    }
    return newImage;
}
//----------------------------------------------------
Image operator | (const Image& lhs, const Image& rhs)
{
    auto newImage = Image(std::max(lhs.getHeight(), rhs.getHeight()),
                      std::max(lhs.getWidth(), rhs.getWidth()));
    
    for(int row = 0 ; row < lhs.getHeight()  ;row++){
        for(int col = 0 ; col < lhs.getWidth()  ;col++){
            newImage(row,col) =  lhs(row,col);
        }
    }
    
    for(int row = 0 ; row < rhs.getHeight()  ;row++){
        for(int col = 0 ; col < rhs.getWidth()  ;col++){
            newImage(row,col) |=  rhs(row,col);
        }
    }

    return newImage;
}
//----------------------------------------------------
Image operator & (const Image& lhs, const Image& rhs)
{
    auto newImage = Image(std::min(lhs.getHeight(), rhs.getHeight()),
                      std::min(lhs.getWidth(), rhs.getWidth()));
    
    for(int row = 0 ; row < newImage.getHeight()  ;row++){
        for(int col = 0 ; col < newImage.getWidth()  ;col++){
            newImage(row,col) =  lhs(row,col) & rhs(row,col);
        }
    }

    return newImage;
}
//----------------------------------------------------
std::ostream& operator<< (std::ostream& ostr, const Image& image)
{
    for(int row = 0 ; row < image.getHeight()  ;row++){
        for(int col = 0 ; col < image.getWidth()  ;col++){
            ostr << image(row,col);
        }
        ostr << std::endl;
    }
    return ostr;
}
//----------------------------------------------------
Image operator * (const Image& image, int n )
{
    Image newImage;
    for(int i = 0; i < n; i++){
        newImage+= image;
    }
    return newImage;
}
//----------------------------------------------------
Image operator * (int n ,const Image& image)
{
    return image * n;
}
//----------------------------------------------------
Image operator ~ (const Image& image)
{
    auto newImage = Image(image.getHeight(),image.getWidth());
    for(int row = 0 ; row < image.getHeight()  ;row++){
        for(int col = 0 ; col < image.getWidth()  ;col++){
            if(image(row,col) == 219)
                newImage(row,col) = 32;
            else if(image(row,col) == 32 )
                newImage(row,col) = 219;
            else
                newImage(row,col) = image(row,col);
        }
    }
    return newImage;
}
