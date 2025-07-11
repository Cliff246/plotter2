#pragma once
#include <string>
#include <memory>
namespace messenger
{
	class childholder
	{
	private:
		std::string m_socket;
		int m_socket_code = -1;
	public:



		childholder(const std::string &socket_path);


		//delete it
		~childholder();


		//get the socket path
		std::string get_socket_path() const;


		//get the socket code
		int get_socket_code() const;


		//set socket path for a child
		void set_socket_path(const std::string& socket_path);	
		//the socket code.... don't use?
		void set_socket_code(int socket_code);
		//starts a socket and gives you back the code
		int start_socket();
		//close the socket
		void close_socket();
	};

	using childholder_ptr = std::shared_ptr<childholder>;	
}
