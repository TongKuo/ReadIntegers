#ifndef FILEERROR_HXX
#define FILEERROR_HXX

#include <stdexcept>
#include <string>

namespace _DIYException
    {
// _FileError class definition

    class _FileError : public std::runtime_error
        {
    public:
        _FileError( const std::string& _FileName );
    
        virtual const char* what() const noexcept;
        std::string _GetFileName();
    
    protected:
        std::string m_FileName;
        std::string m_Msg;
        };
    
// _FileError class implementation
    
    /* Constructor function */
    _FileError::_FileError( const std::string& _FileName )
        : std::runtime_error( "" ),
          m_FileName( _FileName ) {;}
          
    /* what() function */
    const char* _FileError::what() const noexcept
        {
        return m_Msg.c_str();
        }
        
    /* _GetFileName() function */
    std::string _FileError::_GetFileName()
        {
        return m_FileName;
        }
    }
    
#endif
