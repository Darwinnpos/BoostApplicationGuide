
#include <iostream>
#include <thread>
#include <chrono>
#include "lockfree_queue.h"

void queue::test()
{
	// 基础功能
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


	// 无锁主要测试性能 非竞争状态
	fn_for_n(10000, [&] { a.push(1); });

	timer( [&] { fn_for_n(10000, [&] { a.pop(b); }); });

	// 测试在 0.3us, 每次可以接受


}
