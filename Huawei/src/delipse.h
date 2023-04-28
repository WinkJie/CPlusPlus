#pragma once
#include <iostream>
#include <queue>

#include <vector>
#include <thread>
#include <fstream>

#include <mutex>
#include <condition_variable>
#include <functional>

class delipse
{
public:
	//构造函数
	delipse() {};
	//析构函数
	~delipse()
	{
		// 结束所有工作线程
		for (auto& thread : worker_threads_) {
			if (thread.joinable()) {
				thread.join();
			}
		}
	};

	// 子任务：对一段数据求和
	double sum_with_start(const double* data_ptr, int size, int start)
	{
		double sum = 0.0;
		for (int i = start; i < size; i += knumthreads)
		{
			sum += data_ptr[i];
		}
		return sum;
	}

	// 主任务：在多个线程中调用子任务完成计算
	double parallel_sum(const double* data_ptr, int size)
	{
		std::vector<std::thread> threads(knumthreads);
		// 创建多个线程，每个线程处理数据的一部分
		std::vector<double> partial_sums(knumthreads);
		for (int i = 0; i < knumthreads; ++i)
		{
			/* capture list： 捕获列表
			 * 捕获方式有桉值捕获[=]和按引用捕获[&]
			 */

			 /* 1.按值捕获 (=) 会将函数定义时可见的所有非静态变量以及 this 指针按照值传递到闭包对象中，这些变量在闭包对象创建时就被复制了一次，
			  *  然后这个复制值在闭包的生命周期内都可用。所以，当当前作用域中的值发生变化时，闭包内捕获的变量的值并不会随之改变。
			  */

			  /* 2.按引用捕获 (&)会将函数定义时可见的所有非静态变量以及 this 指针全部以引用传递到闭包对象中，这些变量在闭包作用域内时，
			   *  一旦产生了变化，那么闭包内捕获的变量也会随之改变。
			  */

			  /*
			   * 指针和引用都是c++中用于间接访问对象的方法，但它们有以下区别：
			   * 1.指针可以重新赋值指向不同的对象或为空，而引用一旦初始化就不能绑定到另一个对象。
			   * 2.指针可以在运行时动态地分配和释放内存，而引用必须在编译时初始化。
			   * 3.对空指针解除引用会导致程序崩溃，而对空引用解除引用会导致未定义行为。
			   * 4.取地址符&可以用于获取任何对象的地址来创建引用，而指针需要通过声明和初始化来分配空间并指向其他对象。
			   * 总之，指针提供了更多的灵活性以及动态内存分配的能力，但使用时需要额外的注意。而引用更加简洁且安全，常用于函数参数和返回值中。
			   */
			   //lambda表达式
			threads[i] = std::thread(
				[&](int thread_num)
				{
					partial_sums[thread_num] = sum_with_start(data_ptr, size, thread_num);
				}, i);
			//
		}

		// 等待所有线程执行完毕
		for (auto& t : threads)
			t.join();

		// 对每个子任务的计算结果求和
		double total = 0.0;
		for (double partial_sum : partial_sums)
			total += partial_sum;

		return total;
	}
	//多线程一  
	/* 多核 cpu 下的并行计算：当需要进行复杂的、耗时的计算操作时，可以将计算任务分解成多个子任务，
	在多个线程上进行并行计算，从而缩短计算时间，提高效率。*/
	void cpucomputerthread()
	{
		/* 假如kdatasize为一百万，可能会提示说“请考虑将某些数据转移到堆中”
		 * 这个错误通常发生在程序中声明了过多的变量或数据，使得栈空间不足以容纳它们。
		 * 堆和栈是内存中的两大区域，栈用来存储程序执行时的函数调用、局部变量等，堆则用于动态分配内存。
		 * 当程序需要在栈上分配的数据太多时，就会出现这个错误提示。
		 * 这时候可以考虑将一些数据转移到堆中，通过动态分配内存的方式解决栈空间不足的问题。
		 * 体地，可以使用 new 运算符在堆中分配内存，并使用指针来引用它。
		 */
		const int kdatasize = 100;
		double data[kdatasize];
		for (int i = 0; i < kdatasize; ++i) {
			data[i] = static_cast<double>(i); // 初始化为 0, 1, 2, ..., kdatasize-1
		}

		double sum = parallel_sum(data, kdatasize);
		std::cout << "sum: " << sum << std::endl;
	}

	/*多线程二以及使用的中间函数*/

	// 子任务：将源文件复制到目标文件
	void copy_file(const std::string& src_path, const std::string& dest_path)
	{
		std::ifstream src_file(src_path, std::ios::binary);
		std::ofstream dst_file(dest_path, std::ios::binary);

		if (!src_file || !dst_file)
		{
			std::cerr << "failed to open file!" << std::endl;
			return;
		}
		dst_file << src_file.rdbuf();
	}

	// 主任务：在多个线程中调用子任务完成文件拷贝
	void parallel_copy_files(const std::vector<std::pair<std::string, std::string>>& file_pairs)
	{
		std::vector<std::thread> threads(knumthreads);

		// 创建多个线程，每个线程拷贝一个文件,lambda表达式，按值捕获
		for (int i = 0; i < knumthreads && i < file_pairs.size(); ++i)
		{
			threads[i] = std::thread([=]() {
				copy_file(file_pairs[i].first, file_pairs[i].second);
				});
		}

		// 等待所有线程执行完毕
		for (auto& t : threads)
		{
			if (t.joinable())
				t.join();
		}
	}
	//线程二
	/*i/o 密集型操作处理：在进行文件读写、网络通信等输入输出操作时，会存在大量的阻塞等待，这时候
	可以采用多线程机制使得程序的其他任务不被 i/o 操作所阻塞，提高程序的吞吐量和响应速度。*/
	void iodeal()
	{
		std::vector<std::pair<std::string, std::string>> file_pairs{
			{"input1.txt", "output1.txt"},
			{"input2.txt", "output2.txt"},
			{"input3.txt", "output3.txt"},
			{"input4.txt", "output4.txt"}
		};

		parallel_copy_files(file_pairs);
	}

	/*任务队列管理：在任务队列管理中，可以将任务抽象成一个个的可以并行执行的子任务当中，在多线程
	上进行处理。例如，get请求时将每个http请求放入队列中，然后配合多线程一起处理请求。*/

	void sendhttpgetrequest(const std::string& url) 
	{
		// 将http请求包装成一个task，加入任务队列
		std::lock_guard<std::mutex> lock(mutex_);
		task_queue_.emplace([url]() 
			{
			// 处理http请求
			// ...
			});
		cv_.notify_all();   // 唤醒一个等待中的线程
	}

	void startworkerthreads(size_t num_threads) 
	{
		for (size_t i = 0; i < num_threads; ++i) 
		{
			worker_threads_.emplace_back([this] 
				{
				while (true) 
				{
					// 等待新的任务到来
					std::unique_lock<std::mutex> lock(mutex_);
					cv_.wait(lock, [this]() { return !task_queue_.empty(); });
					// 取出队首任务并执行
					auto task = std::move(task_queue_.front());
					task_queue_.pop();
					lock.unlock();   // 释放锁，允许其他线程进入临界区
					task();   // 执行任务
				}
				});
		}
	}


private:
	const int knumthreads = 4;
private:
	std::queue<std::function<void()>> task_queue_;   // 任务队列
	std::vector<std::thread> worker_threads_;   // 工作线程
	std::mutex mutex_;   // 互斥锁，用于保护任务队列
	std::condition_variable cv_;   // 条件变量，用于唤醒等待中的线程



};

