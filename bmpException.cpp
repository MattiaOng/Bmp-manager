/**
 * \file bmpException.cpp
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
 
#include "bmpException.h"

bmpException :: bmpException ( void )
{
	err = gen;
}

bmpException :: bmpException ( error er )
{
	err = er;
}

const char * bmpException :: what ( void )
{
	switch ( err ) {
		case gen:
			return "General error\n";

		case fileIn:
			return "Fail file input\n";

		case fileOut:
			return "Fail file output\n";

		case headInit:
			return "Header is not initialized\n";

		case compress:
			return "Compression does not supported\n";

		case cartCoord:
			return "Cartesian coordinates are too high\n";
	}

	return "Undefined\n";
}

/* End of bmpException.cpp */