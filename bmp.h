/**
 * \file bmp.h
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

#ifndef BMP_H
#define BMP_H

#include "dataType.hpp"
#include "bmpException.h"

template < class Rgb >
class bmp
{
    public:
    bmp ( void );
    ~bmp ( void );

    // Load an image from a bmp file
    void loadImage ( char * ) throw ( bmpException );
    // Save the current bitmap image in a file
    void saveImage ( char * ) throw ( bmpException );

    // Set a pixel with cartesian coordinates ( x, y ) and a rgb color
    void setPixel ( uint32_t , uint32_t ,  Rgb ) throw ( bmpException );
    // Get a pixel with cartesian coordinates ( x, y )
    void getPixel ( uint32_t , uint32_t, Rgb & ) throw ( bmpException );

    // Return the current height of the bitmap image
    const uint32_t height ( void );
    // Return the current width of the bitmap image
    const uint32_t width ( void );

    // Init or restart the header
    void initHeader ( uint16_t );

    // Set the width and the height of the bitmap image
    void setWidthHeight ( uint32_t, uint32_t );

    private:
    void allocImage ( void );

    Rgb * image;
    uint32_t size;

    bmpType type;
    fileHeader FileHeader;
    infoHeader InfoHeader;
};

#endif

/* End of bmp.h */