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
		~childholder();

		std::string get_socket_path() const;
		int get_socket_code() const;

		void set_socket_path(const std::string& socket_path);	
		void set_socket_code(int socket_code);
		int start_socket();
	};

	using childholder_ptr = std::shared_ptr<childholder>;	
}
