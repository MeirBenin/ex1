//
//  ן.cpp
//  ex1
//
//  Created by meir benin on 21/03/2021.
//

#include "ImageDataStructure.h"
//------------------------------------------------------------------
ImageDataStructure::ImageDataStructure():ImageDataStructure(0,0,' '){}
//------------------------------------------------------------------
ImageDataStructure::ImageDataStructure(int height,int width):ImageDataStructure(height,width,' '){}
//------------------------------------------------------------------
ImageDataStructure::ImageDataStructure(int height, int width, Pixel color){
    M_matrix = new Pixel*[height];
    if (M_matrix == nullptr) {
        std::cout << "alloc error\n";
        exit(1);
    }
    for (int i = 0; i < height; i++) {
        M_matrix[i] = new Pixel[width];
        if (M_matrix[i] == nullptr) {
            std::cout << "alloc error\n";
            exit(1);
        }
        for (int j = 0; j < height ; j++)
            M_matrix[i][j] = color;
        
    }
    m_width = width;
    m_height = height;
}
//------------------------------------------------------------------
    ImageDataStructure::ImageDataStructure(const ImageDataStructure& other){
        m_width = other.getwidth();
        m_height = other.getHeight();
        M_matrix = new Pixel*[m_height];
        if (M_matrix == nullptr) {
            std::cout << "alloc error\n";
            exit(1);
        }
        for (int i = 0; i < m_height; i++) {
            M_matrix[i] = new Pixel[m_width];
            if (M_matrix[i] == nullptr) {
                std::cout << "alloc error\n";
                exit(1);
            }
            for (int j = 0; j < m_height ; j++)
                M_matrix[i][j] = other[i][j];
            
        }
       
    }
//------------------------------------------------------------------
ImageDataStructure:: ~ImageDataStructure(){
    for (int i = 0; i < m_height; i++) {
        delete M_matrix[i];
    }
    delete M_matrix;
}
//------------------------------------------------------------------
Pixel* ImageDataStructure::operator[](size_t index) const{
    return M_matrix[index];
}
//------------------------------------------------------------------
ImageDataStructure& ImageDataStructure::operator = (const ImageDataStructure& other){
    auto newMat = other;
    swap(newMat);
    return *this;
}
//------------------------------------------------------------------
void ImageDataStructure::swap(ImageDataStructure& other){
    auto temp = M_matrix;
    M_matrix = other.M_matrix;
    other.M_matrix = temp;
}
