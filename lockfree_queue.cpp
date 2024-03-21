
#include <iostream>
#include <thread>
#include <chrono>
#include "lockfree_queue.h"

void queue::test()
{
	// ��������
	boost::lockfree::queue<int> a(10000);
	a.push(1);
	int b;
	a.pop(b);
	// a for n fn
	auto fn_for_n = [](const int n,const auto& fn)
	{
		for (int i = n - 1; i >= 0; --i)
		{
			fn();
		}		
	};
	// timer
	auto timer = [](const auto& fn)
	{
		const auto s =	std::chrono::high_resolution_clock::now();
		fn();
		std::cout << std::chrono::high_resolution_clock::now() - s << "\n";
	};


	// ������Ҫ�������� �Ǿ���״̬
	fn_for_n(10000, [&] { a.push(1); });

	timer( [&] { fn_for_n(10000, [&] { a.pop(b); }); });

	// ������ 0.3us, ÿ�ο��Խ���


}
