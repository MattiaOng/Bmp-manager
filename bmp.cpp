/**
 * \file bmp.cpp
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
 
#include "bmp.h"
#include "bmpException.cpp"

#include <fstream>
#include <cstring>

template < class Rgb >
bmp < Rgb > :: bmp ( )
{
    image = 0;
    std :: memset ( &type, 0, sizeof ( bmpType ) );
    std :: memset ( &FileHeader, 0, sizeof ( fileHeader ) );
    std :: memset ( &InfoHeader, 0, sizeof ( infoHeader ) );
    size = 0;
}

template < class Rgb >
bmp < Rgb > :: ~bmp ( )
{
    delete image ;
}

template < class Rgb >
void bmp < Rgb > :: allocImage ( void )
{
    size = InfoHeader.width * InfoHeader.height;

    image = new Rgb[ size + 1 ];

    std :: memset ( image, 0, size * sizeof( Rgb ) );
}

template < class Rgb >
void bmp < Rgb > :: loadImage ( char * fileName ) throw ( bmpException )
{
    std :: ifstream file( fileName, std :: ios :: in | std :: ios :: binary );

    if ( ! file )
        throw bmpException ( bmpException :: fileOut );

    file.read ( ( char * ) &type, sizeof ( bmpType ) );

    file.read ( ( char * ) &FileHeader, sizeof ( fileHeader ) );
    file.read ( ( char * ) &InfoHeader, sizeof ( infoHeader ) );

    if ( InfoHeader.compressType )
        throw bmpException ( bmpException :: compress );

    file.seekg ( FileHeader.offset, std :: ios :: beg );

    this -> allocImage ( );

    file.read ( ( char * ) image, size * sizeof ( Rgb ) );

    if ( !file.good ( ) )
        throw bmpException ( bmpException :: fileIn );

    file.close();
}

template < class Rgb >
void bmp < Rgb > :: saveImage ( char * fileName ) throw ( bmpException )
{
    if ( InfoHeader.headerSz == 0 )
        throw bmpException ( bmpException :: headInit );

    std :: ofstream file ( fileName, std :: ios :: out | std :: ios :: binary );

    if ( !file )
        throw bmpException ( bmpException :: fileOut );

    file.write ( ( char * ) &type , sizeof ( bmpType ) );

    FileHeader.offset = 54;

    file.write ( ( char * ) &FileHeader , sizeof ( fileHeader ) );

    file.write ( ( char * ) &InfoHeader, sizeof ( infoHeader ) );

    file.write ( ( char * ) image , size * sizeof ( Rgb ) );

    if ( ! file.good ( ) )
        throw bmpException ( bmpException :: fileOut );

    file.close ( );
}

template < class Rgb >
void bmp < Rgb > :: setPixel ( uint32_t x, uint32_t y,  Rgb color) throw ( bmpException )
{
    if ( x > InfoHeader.width || y >= InfoHeader.height )
        throw bmpException ( bmpException :: cartCoord );

    image[(InfoHeader.height - 1 - y ) * InfoHeader.width + x] = color;
}

template < class Rgb >
void bmp < Rgb > :: getPixel ( uint32_t x, uint32_t y, Rgb & pixel) throw ( bmpException )
{
    pixel = image[(InfoHeader.height - 1 - y ) * InfoHeader.width + x];
}

template < class Rgb >
const uint32_t bmp < Rgb > :: height ( void )
{
    return InfoHeader.height;
}

template < class Rgb >
const uint32_t bmp < Rgb > :: width ( void )
{
    return InfoHeader.width;
}

template < class Rgb >
void bmp < Rgb > :: setWidthHeight ( uint32_t width, uint32_t height )
{
    FileHeader.size = height * width;
    InfoHeader.height = height;
    InfoHeader.width = width;

    this -> allocImage ( );
}

template < class Rgb >
void bmp < Rgb > :: initHeader ( uint16_t bitForPixel )
{
    type.magic [ 0 ] = 0x42;
    type.magic [ 1 ] = 0x4D;
    type.magic [ 2 ] = 0x00;

    if ( image != 0 )
    {
        delete image;
        image = 0;
        size = 0;

        std :: memset ( & FileHeader, 0, sizeof ( fileHeader ) );
        std :: memset ( & InfoHeader, 0, sizeof ( infoHeader ) );
    }

    InfoHeader.headerSz = 40;
    InfoHeader.nplanes = 1;
    InfoHeader.bitspp = bitForPixel;
}

/* End of bmp.cpp */