/**
 * \file bmpException.h
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
 
#ifndef BMPEXCEPTION_H
#define BMPEXCEPTION_H

#include <exception>

class bmpException : public std :: exception
{
    public:
        typedef enum
        {
            gen = 0,
            fileIn,
            fileOut,
            headInit,
            compress,
            cartCoord
        } error;

        bmpException ( void );

        bmpException ( error er );

        const char * what ( void );

    private:
        error err;
};

#endif

/* End of bmpException.h */