#include "ini_parser.h"

namespace qh
{
	INIParser::INIParser()
	{
	};

	INIParser::~INIParser()
	{
		map.clear();
	};

	bool INIParser::Parse(const std::string& ini_file_path)
	{
		return false;
	};

	bool INIParser::Parse(const char* ini_data, size_t ini_data_len, const std::string& line_seperator, const std::string& key_value_seperator )
	{
		std::string data = ini_data;
        std::string key;
		std::string value;
		std::string onedata;
		int line_position = 0;
		int key_position = 0;
		while (data.length() > 0) {
			line_position = data.find( line_seperator, 0 );
			//get one argument
			onedata = data.substr( 0, line_position );
			//cut arguments
			if(line_position == -1)
			{
				data = "";
			}
			else
			{
				data = data.substr( line_position + line_seperator.length(), data.length() );
			}
			key_position = onedata.find( key_value_seperator, 0 );
			//get key
			if(key_position == -1)
			{
				key = "";
			}
			else
			{
				key = onedata.substr( 0, key_position );
				value = onedata.substr( key_position + key_value_seperator.length(), onedata.length() );
			}
			//set value
			if( key.compare("") != 0)
			{
				if (map.find( key ) != map.end())
				{
					map.erase( key );
					map.insert( std::pair< std::string, std::string >( key, value ) );
				}
				else
				{
					map.insert( std::pair< std::string, std::string >( key, value ) );
				}
			}
        }
		return true;
	};

	const std::string& INIParser::Get(const std::string& key, bool* found)
	{
		//find key
		std::map< std::string, std::string >::iterator iter = map.find( key );
		if( iter != map.end())
		{
			if(found != NULL)
				*found = true;
			return iter->second;
		}
		else
		{
			if(found != NULL)
				*found = false;
			nodata = "";
			return nodata;
		}
	};

	const std::string& INIParser::Get(const std::string& section, const std::string& key, bool* found)
	{
		return NULL;
	};
}