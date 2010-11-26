/*****************************************************************************
 * Copyright (c) 2006 Andreas Pakulat <apaku@gmx.de>                         *
 * Copyright (c) 2007 Piyush Verma <piyush.verma@gmail.com>                  *
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
 *****************************************************************************/

#include "pythondriver.h"

#include <QtGlobal>
#include <QtCore/QString>

#include <kdebug.h>
#include <kcmdlineargs.h>
#include <kurl.h>

int main( int argc, char* argv[] )
{
    KCmdLineArgs::init( argc, argv, "Python Parser", 0, ki18n("python-parser"), "4.0.0", ki18n("Parse Python project files"));

    KCmdLineOptions options;
    options.add("!debug", ki18n("Enable output of the debug AST"));
    options.add("!+files", ki18n("Python project files"));
    KCmdLineArgs::addCmdLineOptions(options);

    KCmdLineArgs *args = KCmdLineArgs::parsedArgs();

    if( args->count() < 1 )
    {
        KCmdLineArgs::usage(0);
    }

    int debug = 0;
    if( args->isSet("debug") )
        debug = 1;
    for( int i = 0 ; i < args->count() ; i++ )
    {
        Python::Driver d;
        if( !d.readFile( args->url(i).toLocalFile() ) )
            exit( EXIT_FAILURE );
        d.setDebug( debug );

        Python::CodeAst* ast = 0;
        if ( !d.parse( &ast ) ) {
            exit( EXIT_FAILURE );
        }else
        {
        }
    }
    return EXIT_SUCCESS;
}

// kate: space-indent on; indent-width 4; tab-width 4; replace-tabs on; auto-insert-doxygen on
