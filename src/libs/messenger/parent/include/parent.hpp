#pragma once
#include <memory>
#include <vector>
#include <string>
#include "childholder.hpp"

namespace messenger
{
	const std::string generate_socket_path(int code);	
	
	using childholder_ptr = std::shared_ptr<childholder>;	
	class parent_messenger
	{
	private:
		std::vector<childholder_ptr> m_children;
	public:
		
		parent_messenger();
		~parent_messenger();


		std::vector<childholder_ptr> get_children() const;
		size_t get_number_children() const;


	};



}
