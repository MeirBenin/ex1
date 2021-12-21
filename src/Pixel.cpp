
#include "Pixel.h"


#include <iostream>


Pixel::Pixel(unsigned char pixel){
    m_color = pixel;
}
//-------------------------------------------
unsigned char Pixel::getColor()const{
    return m_color;
}
//===================================================
void Pixel::operator |= (const Pixel& rhs){
    this -> m_color = (*this | rhs).getColor();
}
//-------------------------------------------
void Pixel::operator &= (const Pixel& rhs){
    this -> m_color = (*this & rhs).getColor();
}
//===================================================
bool operator == (const Pixel& lhs, const Pixel& rhs){
    return (lhs.getColor() == rhs.getColor())? true:false;
}
//-------------------------------------------
bool operator != (const Pixel& lhs, const Pixel& rhs){
    return (lhs == rhs)? false:true;
}
//-------------------------------------------
Pixel operator | (const Pixel& lhs, const Pixel& rhs){
    Pixel newPixel((lhs.getColor() >= rhs.getColor())?lhs.getColor():rhs.getColor());
    return newPixel;
}
//-------------------------------------------
std::ostream& operator<< (std::ostream& ostr, const Pixel& pixel){
    ostr << pixel.getColor();
    return ostr;
}
//-------------------------------------------
Pixel operator & ( const Pixel& lhs,const Pixel& rhs){
    Pixel newPixel((lhs.getColor() <= rhs.getColor())?lhs.getColor():rhs.getColor());
    return newPixel;
}
