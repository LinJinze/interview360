#include "qh_string.h"

#include <string.h>

namespace qh
{

    string::string()
        : data_(NULL), len_(0)
    {
    }

    string::string( const char* s )
    {
		if(s == NULL)
		{
			data_ = NULL;
			len_ = 0;
		}
		else
		{
			len_ = strlen(s);
			data_ = new char[ len_ + 1 ];
			memcpy( data_, s, len_ );
			data_[len_] = '\0';
		}
    }

    string::string( const char* s, size_t len )
    {
		if(s == NULL || len < 0)
		{
			data_ = NULL;
			len_ = 0;
			return;
		}
		if( len <= strlen(s) )
		{
			data_ = new char[ len + 1 ];
			memcpy( data_, s, len );
			len_ = len;
			data_[len_] = '\0';
		}
		else
		{
			len_ = strlen(s);
			data_ = new char[ len_ + 1 ];
			memcpy( data_, s, len_);
			data_[len_] = '\0';
		}
    }

    string::string( const string& rhs )
    {
		if(rhs.data_ == NULL)
		{
			data_ = NULL;
			len_ = 0;
		}
		else
		{
			len_ = rhs.len_;
			data_ = new char[ len_ + 1 ];
			memcpy( data_, rhs.data_, len_ );
			data_[len_] = '\0';
		}
    }

    string& string::operator=( const string& rhs )
    {
		if(this == &rhs)
		{
			return *this;
		}
		else
		{
			delete []data_;
			len_ = strlen(rhs.data_);
			data_ = new char[len_ +1];
			memcpy(data_, rhs.data_, len_);
			data_[len_] = '\0';
			return *this;
		}
    }

    string::~string()
    {
		if( data_ != NULL)
		{
			delete[] data_;
			data_ = NULL;
			len_ = 0;
		}
		
    }

    size_t string::size() const
    {
        return len_;
    }

    const char* string::data() const
    {
        return data_;
    }

    const char* string::c_str() const
    {
		if( data_ != NULL )
			data_[len_] = '\0';
        return data_;
    }

    char* string::operator[]( size_t index )
    {
		if( index >= len_ || index < 0 )
		{
			return NULL;
		}
		else
		{
			return data_ + index;
		}
    }
}