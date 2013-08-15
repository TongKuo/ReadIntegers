///:
/*****************************************************************************
 **                                                                         **
 **                               .======.                                  **
 **                               | INRI |                                  **
 **                               |      |                                  **
 **                               |      |                                  **
 **                      .========'      '========.                         **
 **                      |   _      xxxx      _   |                         **
 **                      |  /_;-.__ / _\  _.-;_\  |                         **
 **                      |     `-._`'`_/'`.-'     |                         **
 **                      '========.`\   /`========'                         **
 **                               | |  / |                                  **
 **                               |/-.(  |                                  **
 **                               |\_._\ |                                  **
 **                               | \ \`;|                                  **
 **                               |  > |/|                                  **
 **                               | / // |                                  **
 **                               | |//  |                                  **
 **                               | \(\  |                                  **
 **                               |  ``  |                                  **
 **                               |      |                                  **
 **                               |      |                                  **
 **                               |      |                                  **
 **                               |      |                                  **
 **                   \\    _  _\\| \//  |//_   _ \// _                     **
 **                  ^ `^`^ ^`` `^ ^` ``^^`  `^^` `^ `^                     **
 **                                                                         **
 **                    Copyright © 1997-2013 by Tong G.                     **
 **                          ALL RIGHTS RESERVED.                           **
 **                                                                         **
 ****************************************************************************/

#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <numeric>
#include <typeinfo>
#include <fstream>

#include "FileOpenError.hxx"
#include "FileReadError.hxx"

typedef _DIYException::_FileError _FileError;
typedef _DIYException::_FileOpenError _OpenError;
typedef _DIYException::_FileReadError _ReadError;

/* _TerminateFunc() function */
void _TerminateFunc()
    { std::cerr << "Uncaught some fuck exception!" << std::endl; }
    
/* _UnexpectedFunc() function */
void _UnexpectedFunc()
    { throw std::runtime_error( "Unexpected exception!" ); }

/* _ReadIntegerFile() function */
void _ReadIntegerFile( const std::string& _FileName,
                       std::vector< int >& _Dest )
    throw( _OpenError, _ReadError )
    {
    std::ifstream _InStream;
    int _Temp;
    std::string _ErrorLineStr;
    int _ErrorLineNum = 0;
    
    _InStream.open( _FileName );
    if ( _InStream.fail() )
        throw _OpenError( _FileName );
    
    while ( !_InStream.eof() )
        {
        std::getline( _InStream, _ErrorLineStr );
        _ErrorLineNum++;
    
        // Create a string stream out of the line
        std::istringstream _LineStream( _ErrorLineStr );
    
        // Read the integers one by one and add them to the std::vector.
        while ( _LineStream >> _Temp )
            _Dest.push_back( _Temp );
        
        if ( !_LineStream.eof() )
            {
            // Some other error. Close the file and throw an exception.
            _InStream.close();
        
            throw _ReadError( _FileName, _ErrorLineNum );
            }
        }
    
    _InStream.close();
    }
    
int main( int /* _Argc */, char* */* _Argv */ )
    {
    std::terminate_handler _OldTerminateHandler = 
                    std::set_terminate( _TerminateFunc );

    std::unexpected_handler _OldExpectedHandler = 
                    std::set_unexpected( _UnexpectedFunc );
        
    std::vector< int > _MyInts;
    const std::string _FileName( "/home/Tong_G/Test.txt" );

    try {
        _ReadIntegerFile( _FileName, _MyInts );
        } catch ( const _FileError& _Ex )
            { std::cerr << _Ex.what() << std::endl; }

    for ( const int& _Elem : _MyInts )
        std::cout << _Elem << " | ";
    std::cout << std::endl;
    
    std::set_terminate( _OldTerminateHandler );
    std::set_unexpected( _OldExpectedHandler );

    return 0;      
    }

 ////////////////////////////////////////////////////////////////////////////

 /***************************************************************************
 **                                                                        **
 **      _________                                      _______            **
 **     |___   ___|                                   / ______ \           **
 **         | |     _______   _______   _______      | /      |_|          **
 **         | |    ||     || ||     || ||     ||     | |    _ __           **
 **         | |    ||     || ||     || ||     ||     | |   |__  \          **
 **         | |    ||     || ||     || ||     ||     | \_ _ __| |  _       **
 **         |_|    ||_____|| ||     || ||_____||      \________/  |_|      **
 **                                           ||                           **
 **                                    ||_____||                           **
 **                                                                        **
 ***************************************************************************/
///:~
