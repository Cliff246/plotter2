#pragma once
#include <memory>
#include <string>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>

namespace messenger
{

	//set the socket path. no numbers
	//no file name
	constexpr char socket_path[] = "/tmp/plotter_";	

	class message
	{
		//a dummy message class for the lol's
		//we will rebuild this later when it reaches that point
		//TODO
	private:
	
		int m_typeid;
		std::string m_message;
	public:
		//message
		message();
		//
		message(int type, const std::string& bytes);
		
		~message();


		//serialize the thing
		std::string serialize() const;

		//getters 
		int get_type() const;
		std::string get_message() const;
		size_t get_message_length() const;

		//setters 
		
		void set_type(int type);
		void set_message(const std::string& message);

	};
		
	messenger::message deserialize(const std::string& bytes);
	using message_ptr = std::unique_ptr<message>;
}



