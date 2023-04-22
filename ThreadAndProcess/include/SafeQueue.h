#ifndef COMMON_SOURCE_CPP_THREADSAFE_QUEUE_H_
#define COMMON_SOURCE_CPP_THREADSAFE_QUEUE_H_
#include <queue>
#include "../HardwareInterface/hycriticalsection.h"
namespace SafeSpace {
	/*
	* 线程安全队列
	* T为队列元素类型
	* 因为有std::mutex和std::condition_variable类成员,所以此类不支持复制构造函数也不支持赋值操作符(=)
	* */
	template<typename T>
	class threadsafe_queue{
	private:
		//data_queue访问信号量
		CHYCriticalSection m_cs;									// 互锁

		typedef std::queue<T> queue_type;
		queue_type data_queue;

		int isFree;//是否空闲
	public:
		typedef typename queue_type::value_type value_type;
		typedef typename queue_type::container_type container_type;
		threadsafe_queue(){}
		/*
		* 使用迭代器为参数的构造函数,适用所有容器对象
		* */
		template<typename _InputIterator>
		threadsafe_queue(_InputIterator first, _InputIterator last){
			for (auto itor = first; itor != last; ++itor){
				data_queue.push(*itor);
			}
		}
		explicit threadsafe_queue(const container_type &c) :data_queue(c){}

		/*
		* 将元素加入队列
		* */
		void push(const value_type &new_value){
			CHYLock<CHYCriticalSection> lock(m_cs);
			data_queue.push(new_value);
		}

		/*
		* 从队列中弹出一个元素,如果队列为空就阻塞
		* */
		value_type wait_and_pop(){
			CHYLock<CHYCriticalSection> lock(m_cs);

			value_type value = data_queue.front();
			data_queue.pop();
			return value;
		}
		/*
		* 从队列中弹出一个元素,如果队列为空返回false
		* */
		bool try_pop(value_type& value){
			CHYLock<CHYCriticalSection> lock(m_cs);
			if (data_queue.empty())
				return false;
			value = data_queue.front();
			data_queue.pop();
			return true;
		}
		/*
		* 返回队列是否为空
		* */
		bool empty(){
			CHYLock<CHYCriticalSection> lock(m_cs);
			return data_queue.empty();
		}
		/*
		* 返回队列中元素数个
		* */
		int size(){
			CHYLock<CHYCriticalSection> lock(m_cs);
			return data_queue.size();
		}

		/*
		* 使用的优先级,越小越优先
		* */
		int priorityLevel(){
			//CHYLock<CHYCriticalSection> lock(m_cs);
			return data_queue.size() * 10 + (1 - isFree);
		}

		int getIsFree(){
			return isFree;
		}

		void setIsFree(int value){
			isFree = value;
		}

		void clear(){
			CHYLock<CHYCriticalSection> lock(m_cs);
			queue_type empty;
			swap(empty, data_queue);

		}
	}; /* threadsafe_queue */
}/* namespace SafeSpace */

using namespace SafeSpace;
#endif /* COMMON_SOURCE_CPP_THREADSAFE_QUEUE_H_ */