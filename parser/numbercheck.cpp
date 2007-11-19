/* KDevelop Python Support
 *
 * Copyright 2007 Andreas Pakulat <apaku@gmx.de>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 */

#include "numbercheck.h"
#include "python_parser.h"

#include <QtCore/QRegExp>
#include <QtCore/QString>
#include <QtCore/QDebug>

namespace Python
{
QRegExp intnum("((0|[1-9][0-9]*)|0[0-7]+|0(x|X)[0-9a-fA-F]+)(l|L)?");
QRegExp floatnum("(([0-9]+)?\\.[0-9]+|[0-9]+\\.)|(([0-9]+|(([0-9]+)?\\.[0-9]+|[0-9]+\\.))(e|E)[-+]?[0-9]+)");
QRegExp imagnum("("+floatnum.pattern()+"|[0-9]+)(j|J)");

int getTokenForNumberString( const QString& s )
{
    if( intnum.exactMatch( s ) )
    {
        return parser::Token_INTEGER;
    }else if( floatnum.exactMatch( s ) )
    {
        return parser::Token_FLOAT;
    }else  if( imagnum.exactMatch( s ) )
    {
        return parser::Token_IMAGNUM;
    }
    return parser::Token_INVALID;
}
}

// kate: space-indent on; indent-width 4; tab-width 4; replace-tabs on; auto-insert-doxygen on