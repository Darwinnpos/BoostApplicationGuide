

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

	boost::range::generate(a, [n=0]() mutable { return n++; }); // 生成函数
	boost::range::fill(b, 2); // 填充函数

	// 拷贝函数
	boost::range::copy(a, b.begin());
	
	// boost::range::copy(a, c.begin()); // 不提供边界检查，异常越界
	auto traversal_print = [](const auto& container) {
		boost::range::for_each(container, [](const int& it) { std::cout << it << "\t"; });
	};

	traversal_print(a);
	traversal_print(b);

	// 搜寻连续相等
	boost::range::adjacent_find(a);

	// 二进制查找
	boost::range::binary_search(a, 0);

	// 后向拷贝
	boost::range::copy_backward(a ,b.end());

	boost::range::make_heap(a);

	traversal_print(a);
}