#include <cstdint>
#include "message.hpp"
#include <iterator>
#include <stdexcept>
#include <unistd.h>
#include <algorithm>
#include <iostream>
using namespace messenger;


message::message()
{

}

message::message(int type, const std::string& bytes)
{
	m_typeid = type;
	m_message = bytes;
}

message::~message()
{

}


std::string message::serialize() const
{

	std::string bytes;
	bytes.resize(m_message.size());
	bytes[0] = (m_typeid >> 24)	& 0xff;
	bytes[1] = (m_typeid >> 16)	& 0xff;
	bytes[2] = (m_typeid >> 8)	& 0xff;
	bytes[3] = (m_typeid)		& 0xff;
	int size = (int)m_message.size();
	bytes[4] = (size >> 24) 	& 0xff;
	bytes[5] = (size >> 16) 	& 0xff;
	bytes[6] = (size >> 8) 		& 0xff;
	bytes[7] = (size)			& 0xff;

	return bytes + m_message;
}



// inline readline for the next 4 bytes
inline uint32_t read_uint32_be(const char* data) {
    return (static_cast<uint8_t>(data[0]) << 24) |
           (static_cast<uint8_t>(data[1]) << 16) |
           (static_cast<uint8_t>(data[2]) << 8)  |
           (static_cast<uint8_t>(data[3]));
}



//deseralize the
messenger::message messenger::deserialize(const std::string& bytes)
{
	//check the bytes are long enough
	if(bytes.size() < 8)
		throw std::runtime_error("to small message size");
	//set the type correctly
	int type = read_uint32_be(bytes.data());
	//get the type
	size_t length = read_uint32_be(bytes.data() + 4);



	//check valid again
	if(bytes.size() < 8 + length)
		throw std::runtime_error("bad data message size");

	std::string actual_data;
	//resize
	actual_data.resize(length);
	//copy using this stupid thing
	std::copy(bytes.begin() + 8, bytes.end() + 8 + length, actual_data.begin());
	//create messge
	messenger::message message(type, actual_data);

	return message;
}

//getters
int message::get_type() const
{
	return m_typeid;
}



//get message
std::string message::get_message() const
{
	return m_message;
}

size_t message::get_message_length() const
{
	return m_message.size();
}

//setters
//set
void message::set_type(int type)
{
	m_typeid = type;
}
//set a mesage
void message::set_message(const std::string& message)
{
	m_message = message;
}

