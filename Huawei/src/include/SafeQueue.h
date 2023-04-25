#ifndef COMMON_SOURCE_CPP_THREADSAFE_QUEUE_H_
#define COMMON_SOURCE_CPP_THREADSAFE_QUEUE_H_
#include <queue>
#include "../HardwareInterface/hycriticalsection.h"
namespace SafeSpace {
	/*
	* �̰߳�ȫ����
	* TΪ����Ԫ������
	* ��Ϊ��std::mutex��std::condition_variable���Ա,���Դ��಻֧�ָ��ƹ��캯��Ҳ��֧�ָ�ֵ������(=)
	* */
	template<typename T>
	class threadsafe_queue{
	private:
		//data_queue�����ź���
		CHYCriticalSection m_cs;									// ����

		typedef std::queue<T> queue_type;
		queue_type data_queue;

		int isFree;//�Ƿ����
	public:
		typedef typename queue_type::value_type value_type;
		typedef typename queue_type::container_type container_type;
		threadsafe_queue(){}
		/*
		* ʹ�õ�����Ϊ�����Ĺ��캯��,����������������
		* */
		template<typename _InputIterator>
		threadsafe_queue(_InputIterator first, _InputIterator last){
			for (auto itor = first; itor != last; ++itor){
				data_queue.push(*itor);
			}
		}
		explicit threadsafe_queue(const container_type &c) :data_queue(c){}

		/*
		* ��Ԫ�ؼ������
		* */
		void push(const value_type &new_value){
			CHYLock<CHYCriticalSection> lock(m_cs);
			data_queue.push(new_value);
		}

		/*
		* �Ӷ����е���һ��Ԫ��,�������Ϊ�վ�����
		* */
		value_type wait_and_pop(){
			CHYLock<CHYCriticalSection> lock(m_cs);

			value_type value = data_queue.front();
			data_queue.pop();
			return value;
		}
		/*
		* �Ӷ����е���һ��Ԫ��,�������Ϊ�շ���false
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
		* ���ض����Ƿ�Ϊ��
		* */
		bool empty(){
			CHYLock<CHYCriticalSection> lock(m_cs);
			return data_queue.empty();
		}
		/*
		* ���ض�����Ԫ������
		* */
		int size(){
			CHYLock<CHYCriticalSection> lock(m_cs);
			return data_queue.size();
		}

		/*
		* ʹ�õ����ȼ�,ԽСԽ����
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