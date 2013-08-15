#ifndef FILEREADERROR_HXX
#define FILEREADERROR_HXX

#include <sstream>
#include "FileError.hxx"

namespace _DIYException
    {
// _FileReadError class definition

    class _FileReadError : public _FileError
        {
    public:
        _FileReadError( const std::string& _FileName, int _ErrorLineNum );
        
        int _GetErrorLineNum();
        
    protected:
        int m_ErrorLineNum;
        };
        
// _FileReadError class implementation
        
    /* Constructor function */
    _FileReadError::_FileReadError( const std::string& _FileName,
                                    int _ErrorLineNum )
        : _FileError( _FileName ),
          m_ErrorLineNum( _ErrorLineNum )
        {
        std::ostringstream _OutStrStream;
        _OutStrStream << "Error reading " << _FileName << " at line "
                      << _ErrorLineNum;
                      
        m_Msg = _OutStrStream.str();
        }
        
     /* _GetErrorLineNum() function */
     int _FileReadError::_GetErrorLineNum()
        { return m_ErrorLineNum; }
    }
    
#endif
