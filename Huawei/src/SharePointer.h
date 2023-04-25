
#ifndef SHAREPOINTER_H 
#define SHAREPOINTER_H  

#include <cassert>
#include <memory>
template <typename T>
class SharedPointer {
public:
	/// @brief default constructor(default (1))
	/// Usage: SharedPointer<T> sptr;
	///        cout << sptr.use_count() << endl;    // 0
	SharedPointer() : ref_count_(nullptr), pointer_(nullptr) {}

	/// @brief default constructor(default (2))
	/// Usage: SharedPointer<T> sptr;
	///        cout << sptr.use_count() << endl;    // 0
	explicit SharedPointer(nullptr_t) : ref_count_(nullptr), pointer_(nullptr) {}

	/// @brief construct from pointer (3)
	/// Usage: SharedPointer<int> sptr(new int(1));
	///        cout << sptr.use_count() << endl;    // 1
	explicit SharedPointer(T* target) : ref_count_(nullptr), pointer_(target) {
		AddReference_();
	}

	/// @brief copy constructors (6)
	/// Usage: SharedPointer<int> sptr(new int(1));
	///        SharedPointer<int> sptr2(sptr);
	SharedPointer(const SharedPointer<T>& that) : ref_count_(nullptr), pointer_(nullptr) {
		if (that) {
			ref_count_ = that.ref_count_;
			pointer_ = that.pointer_;
			AddReference_();
		}
	}

	/// @brief move constructors (8)
	SharedPointer(SharedPointer<T>&& that) noexcept : ref_count_(nullptr), pointer_(nullptr) {
		if (that) {
			ref_count_ = that.ref_count_;
			pointer_ = that.pointer_;
			that.ref_count_ = nullptr;
			that.pointer_ = nullptr;
		}
	}

	~SharedPointer() {
		RemoveReference_();
	}

	/// @brief ������ֵ����(copy assignment function) copy(1)
	/// Usage: SharedPointer<int> sptr(new int(1));
	///        auto sptr2 = sptr;
	SharedPointer<T>& operator=(const SharedPointer<T>& that) noexcept {
		if (this != &that) {
			RemoveReference_();
			this->ref_count_ = that.ref_count_;
			this->pointer_ = that.pointer_;
			AddReference_();
		}
		return *this;
	}

	/// @brief �ƶ���ֵ����(move assignment function) copy(2)
	/// Usage: SharedPointer<T> sptr(new int(1));
	///        auto sptr2 = std::move(sptr);
	SharedPointer<T>& operator=(SharedPointer<T>&& that) noexcept {
		if (this != &that) {
			RemoveReference_();
			this->ref_count_ = that.ref_count_;
			this->pointer_ = that.pointer_;
			that.ref_count_ = nullptr;
			that.pointer_ = nullptr;
		}
		return *this;
	}

	/// @brief �ƶ���ֵ����(move assignment function) copy(3)
	/// Usage: std::unique_ptr<int> uptr(new int(1));
	///        SharedPointer<int> sptr = std::move(uptr);
	SharedPointer<T>& operator=(std::unique_ptr<T>&& that) {
		if (this != &that) {
			RemoveReference_();
			this->pointer_ = that.get();
			*this->ref_count_ = 1;
		}
		return *this;
	}

	/// @brief ָ�������
	/// Usage: SharedPointer<int> sptr(new int(1));
	///        cout << *sptr << endl;
	T& operator*() const {
		return *pointer_;
	}

	/// @brief ������ָ����Ĺ�����Ա
	/// Usage: struct C{int a, int b};
	///        SharedPointer<C> sptr(new C);
	///        sptr->a = 10;
	T* operator->() const {
		return pointer_;
	}

	/// @brief Check if not null
	/// @return whether the stored pointer is a null pointer.
	/// Usage: SharedPointer<T> sptr(new int(1));
	///        cout << sptr ? "not null" : "null" << endl;
	explicit operator bool() const noexcept {
		return pointer_ != nullptr;
	}

	/// @brief Get pointer,
	/// Usage: SharedPointer<T> sptr(new int(1));
	///        cout << *sptr.get() << endl;
	T* get() const noexcept {
		return pointer_;
	}

	/// @brief ��ȡ���ü���
	/// Usage: SharedPointer<int> sptr(new int(1));
	///        cout << sptr.use_count();
	int use_count() const { // NOLINT
		if (ref_count_) {
			return *ref_count_;
		}
		// If this is an empty shared_ptr, the function returns zero.
		return 0;
	}
protected:
	/// @brief �����ü���Ϊnullptrʱ���������ü�����Դ������ʼ��Ϊ1���������ü�����1
	void AddReference_() {
		if (ref_count_) {
			(*ref_count_)++;
		}
		else {
			ref_count_ = new int(1);
		}
	}

	/// @brief ���ü�����1����Ϊ0ʱ���ͷ���Դ
	void RemoveReference_() {
		if (ref_count_) {
			(*ref_count_)--;
			if (*ref_count_ == 0) {
				delete ref_count_;
				delete pointer_;
				ref_count_ = nullptr;
				pointer_ = nullptr;
			}
		}
	}

private:
	int* ref_count_;  // ���ü���
	T* pointer_;  // ָ����Դ��ָ��
};


#endif //SHAREPOINTER_H

