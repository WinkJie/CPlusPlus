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
	//���캯��
	delipse() {};
	//��������
	~delipse()
	{
		// �������й����߳�
		for (auto& thread : worker_threads_) {
			if (thread.joinable()) {
				thread.join();
			}
		}
	};

	// �����񣺶�һ���������
	double sum_with_start(const double* data_ptr, int size, int start)
	{
		double sum = 0.0;
		for (int i = start; i < size; i += knumthreads)
		{
			sum += data_ptr[i];
		}
		return sum;
	}

	// �������ڶ���߳��е�����������ɼ���
	double parallel_sum(const double* data_ptr, int size)
	{
		std::vector<std::thread> threads(knumthreads);
		// ��������̣߳�ÿ���̴߳������ݵ�һ����
		std::vector<double> partial_sums(knumthreads);
		for (int i = 0; i < knumthreads; ++i)
		{
			/* capture list�� �����б�
			 * ����ʽ����ֵ����[=]�Ͱ����ò���[&]
			 */

			 /* 1.��ֵ���� (=) �Ὣ��������ʱ�ɼ������зǾ�̬�����Լ� this ָ�밴��ֵ���ݵ��հ������У���Щ�����ڱհ����󴴽�ʱ�ͱ�������һ�Σ�
			  *  Ȼ���������ֵ�ڱհ������������ڶ����á����ԣ�����ǰ�������е�ֵ�����仯ʱ���հ��ڲ���ı�����ֵ��������֮�ı䡣
			  */

			  /* 2.�����ò��� (&)�Ὣ��������ʱ�ɼ������зǾ�̬�����Լ� this ָ��ȫ�������ô��ݵ��հ������У���Щ�����ڱհ���������ʱ��
			   *  һ�������˱仯����ô�հ��ڲ���ı���Ҳ����֮�ı䡣
			  */

			  /*
			   * ָ������ö���c++�����ڼ�ӷ��ʶ���ķ���������������������
			   * 1.ָ��������¸�ֵָ��ͬ�Ķ����Ϊ�գ�������һ����ʼ���Ͳ��ܰ󶨵���һ������
			   * 2.ָ�����������ʱ��̬�ط�����ͷ��ڴ棬�����ñ����ڱ���ʱ��ʼ����
			   * 3.�Կ�ָ�������ûᵼ�³�����������Կ����ý�����ûᵼ��δ������Ϊ��
			   * 4.ȡ��ַ��&�������ڻ�ȡ�κζ���ĵ�ַ���������ã���ָ����Ҫͨ�������ͳ�ʼ��������ռ䲢ָ����������
			   * ��֮��ָ���ṩ�˸����������Լ���̬�ڴ�������������ʹ��ʱ��Ҫ�����ע�⡣�����ø��Ӽ���Ұ�ȫ�������ں��������ͷ���ֵ�С�
			   */
			   //lambda���ʽ
			threads[i] = std::thread(
				[&](int thread_num)
				{
					partial_sums[thread_num] = sum_with_start(data_ptr, size, thread_num);
				}, i);
			//
		}

		// �ȴ������߳�ִ�����
		for (auto& t : threads)
			t.join();

		// ��ÿ��������ļ��������
		double total = 0.0;
		for (double partial_sum : partial_sums)
			total += partial_sum;

		return total;
	}
	//���߳�һ  
	/* ��� cpu �µĲ��м��㣺����Ҫ���и��ӵġ���ʱ�ļ������ʱ�����Խ���������ֽ�ɶ��������
	�ڶ���߳��Ͻ��в��м��㣬�Ӷ����̼���ʱ�䣬���Ч�ʡ�*/
	void cpucomputerthread()
	{
		/* ����kdatasizeΪһ���򣬿��ܻ���ʾ˵���뿼�ǽ�ĳЩ����ת�Ƶ����С�
		 * �������ͨ�������ڳ����������˹���ı��������ݣ�ʹ��ջ�ռ䲻�����������ǡ�
		 * �Ѻ�ջ���ڴ��е���������ջ�����洢����ִ��ʱ�ĺ������á��ֲ������ȣ��������ڶ�̬�����ڴ档
		 * ��������Ҫ��ջ�Ϸ��������̫��ʱ���ͻ�������������ʾ��
		 * ��ʱ����Կ��ǽ�һЩ����ת�Ƶ����У�ͨ����̬�����ڴ�ķ�ʽ���ջ�ռ䲻������⡣
		 * ��أ�����ʹ�� new ������ڶ��з����ڴ棬��ʹ��ָ������������
		 */
		const int kdatasize = 100;
		double data[kdatasize];
		for (int i = 0; i < kdatasize; ++i) {
			data[i] = static_cast<double>(i); // ��ʼ��Ϊ 0, 1, 2, ..., kdatasize-1
		}

		double sum = parallel_sum(data, kdatasize);
		std::cout << "sum: " << sum << std::endl;
	}

	/*���̶߳��Լ�ʹ�õ��м亯��*/

	// �����񣺽�Դ�ļ����Ƶ�Ŀ���ļ�
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

	// �������ڶ���߳��е�������������ļ�����
	void parallel_copy_files(const std::vector<std::pair<std::string, std::string>>& file_pairs)
	{
		std::vector<std::thread> threads(knumthreads);

		// ��������̣߳�ÿ���߳̿���һ���ļ�,lambda���ʽ����ֵ����
		for (int i = 0; i < knumthreads && i < file_pairs.size(); ++i)
		{
			threads[i] = std::thread([=]() {
				copy_file(file_pairs[i].first, file_pairs[i].second);
				});
		}

		// �ȴ������߳�ִ�����
		for (auto& t : threads)
		{
			if (t.joinable())
				t.join();
		}
	}
	//�̶߳�
	/*i/o �ܼ��Ͳ��������ڽ����ļ���д������ͨ�ŵ������������ʱ������ڴ����������ȴ�����ʱ��
	���Բ��ö��̻߳���ʹ�ó�����������񲻱� i/o ��������������߳��������������Ӧ�ٶȡ�*/
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

	/*������й�����������й����У����Խ���������һ�����Ŀ��Բ���ִ�е��������У��ڶ��߳�
	�Ͻ��д������磬get����ʱ��ÿ��http�����������У�Ȼ����϶��߳�һ��������*/

	void sendhttpgetrequest(const std::string& url) 
	{
		// ��http�����װ��һ��task�������������
		std::lock_guard<std::mutex> lock(mutex_);
		task_queue_.emplace([url]() 
			{
			// ����http����
			// ...
			});
		cv_.notify_all();   // ����һ���ȴ��е��߳�
	}

	void startworkerthreads(size_t num_threads) 
	{
		for (size_t i = 0; i < num_threads; ++i) 
		{
			worker_threads_.emplace_back([this] 
				{
				while (true) 
				{
					// �ȴ��µ�������
					std::unique_lock<std::mutex> lock(mutex_);
					cv_.wait(lock, [this]() { return !task_queue_.empty(); });
					// ȡ����������ִ��
					auto task = std::move(task_queue_.front());
					task_queue_.pop();
					lock.unlock();   // �ͷ��������������߳̽����ٽ���
					task();   // ִ������
				}
				});
		}
	}


private:
	const int knumthreads = 4;
private:
	std::queue<std::function<void()>> task_queue_;   // �������
	std::vector<std::thread> worker_threads_;   // �����߳�
	std::mutex mutex_;   // �����������ڱ����������
	std::condition_variable cv_;   // �������������ڻ��ѵȴ��е��߳�



};

