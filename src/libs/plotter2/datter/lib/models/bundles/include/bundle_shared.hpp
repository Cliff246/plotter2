#pragma once


#include "bundle.hpp"

namespace datter
{
	class bundle_shared
	{
	private:
		//unsafe yes... but we need this for interproccess sharing
		//this will almost certanly be rewritten later
		char *m_read_bytes;
		char *m_write_bytes;

		bool m_set;

	public:
		
		void point_read_head(char *head);	
		void point_write_head(char *head);	
		
		
		
		
	};	
}
