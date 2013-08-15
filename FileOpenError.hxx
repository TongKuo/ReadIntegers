#ifndef FILEOPENERROR_HXX
#define FILEOPENERROR_HXX

#include "FileError.hxx"

namespace _DIYException
    {
// _FileOpenError class definition

    class _FileOpenError : public _FileError
        {
    public:
        _FileOpenError( const std::string& _FileName );
        };
        
// _FileOpenError class implementation
        
    /* Constructor function */
    _FileOpenError::_FileOpenError( const std::string& _FileName )
        : _FileError( _FileName )
        { m_Msg = "Unable to open " + _FileName; }
    }
    
#endif
