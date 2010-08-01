/**
 * \file fractal_example.cpp
 *
 *  Copyright (C) 2009-2010, Ongaro Mattia <moongaro at gmail.com>
 *  All rights reserved.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 */
 
#include "bmp/bmp.cpp"
 
#include <complex>
#include <iostream>
 
#define WIDTH  1000
#define HEIGHT 1000
 
#define X0  -2
#define Y0  -2
#define X1 2
#define Y1 2
 
 
#define LIMIT 2
#define DEPTH 256
#define FILE "mandelbrot.bmp"
 
int main ( void )
{
    rgb24 black, inUse;
    memset ( &black, 0, sizeof ( rgb24 ) );
 
    std :: complex < double > z ( 0.0 );
    std :: complex < double > c ( 0.0 );
 
    bool flag;
    double real_x, real_y;
 
    try
    {
        bmp < rgb24 > image;
        image.initHeader ( 24 );
        image.setWidthHeight ( WIDTH, HEIGHT );
 
        for ( uint32_t x = 0; x < WIDTH ; x++ )
        {
            real_x =  X0+((double(x)*(X1-X0))/double(WIDTH));
            for ( uint32_t y = 0, count; y < HEIGHT ; y++ )
            {
                real_y = Y0+((double(y)*(Y1-Y0))/double(HEIGHT));
 
                c = std :: complex < double > ( real_x, real_y );
                z = c;
                for ( count=0 ; count < DEPTH ; count++ )
                {
                    z=z*z+c;
 
                    if( abs ( z ) > LIMIT )
                        break;
                }
 
                if ( count < DEPTH )
                {
                        inUse.red = 100+count/4;
                        inUse.blue = count/2;
                        inUse.green = 4*count;
 
						if(inUse.red>128)   inUse.red=128;
						if(inUse.green>128) inUse.green=128;
						if(inUse.blue>255)  inUse.blue=255;
 
                        image.setPixel ( x, y, inUse );
                }
                else
                        image.setPixel ( x, y, black );
            }
        }
 
        image.saveImage ( FILE );
    }
 
	catch ( bmpException e )
	{
		std :: cerr << "Exception in the bmp managment:\n" << e.what ( );
	}
 
    std :: cout << "\aFractal generate!" << std :: endl;
 
    return 0;
}

/* End of fractal_example.cpp */