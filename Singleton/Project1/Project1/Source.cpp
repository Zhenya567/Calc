#include <iostream>
using namespace std;
class Singleton
{
private:
	Singleton()=default;
	~Singleton()=default;

	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;

	void* operator new(size_t) = delete;
	void* operator new[](size_t) = delete;

	void operator delete(void*) = delete;
	void operator delete[](void*) = delete;
public:
	static 	Singleton& getInst() {
		static Singleton object;
		return object;
	}
};
void foo() {
	auto& a = Singleton::getInst();
	cout << &a << endl;
}
void bar() {
	auto& b = Singleton::getInst();
	cout << &b << endl;
}
int main() {
	auto& s = Singleton::getInst();
	foo();
	bar();
	system("pause");
	return 0;
}

