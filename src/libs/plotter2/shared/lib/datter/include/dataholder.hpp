#pragma once 

#include <array>
#include <vector>
namespace plt_shared
{
	class dataholder
	{
	private:
				
	public:	
	};

	template <class T, uint64_t N>
	class dataary : public dataholder
	{
	private:
		std::array<T, N> m_ary;
	public:
		dataary(std::array<T, N> array);	
		~dataary();
	};

	template <class T>
	class datavec : public dataholder
	{
	private:
		std::vector<T> m_vec;
	public:
		datavec(std::vector<T> &m_vec);
		~datavec();
	};
	
	template <class T>
	class datamatrix : public dataholder
	{
	private:
		std::vector<T> m_matrix;
		size_t m_rows, m_cols;
	public:
		datamatrix();
		~datamatrix();
	};
}
