#include <iostream>
#include "Image.h"
#include "Pixel.h"

int main()
{

	auto image = Image(5, 5);
	image(0, 0) = Pixel(176);
	image(1, 1) = Pixel(219);
	std::cout << image;
	return 0;
}
