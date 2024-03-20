

#include "range.h"

#include <iostream>
#include <vector>
#include <boost/range.hpp>
#include <boost/range/algorithm.hpp>


void range::generate()
{
	std::vector<int> a(100);
	std::vector<int> b(100);
	std::vector<int> c(4);

	boost::range::generate(a, [n=0]() mutable { return n++; }); // ���ɺ���
	boost::range::fill(b, 2); // ��亯��

	// ��������
	boost::range::copy(a, b.begin());
	
	// boost::range::copy(a, c.begin()); // ���ṩ�߽��飬�쳣Խ��
	auto traversal_print = [](const auto& container) {
		boost::range::for_each(container, [](const int& it) { std::cout << it << "\t"; });
	};

	traversal_print(a);
	traversal_print(b);

	// ��Ѱ�������
	boost::range::adjacent_find(a);

	// �����Ʋ���
	boost::range::binary_search(a, 0);

	// ���򿽱�
	boost::range::copy_backward(a ,b.end());

	boost::range::make_heap(a);

	traversal_print(a);
}