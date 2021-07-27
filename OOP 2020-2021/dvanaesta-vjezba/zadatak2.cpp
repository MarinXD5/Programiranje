#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>

template <typename T ,int n> 
class array {
private:
	T* p;
public:
	array(int x) {
		p = new T[n];
		std::fill(p, p + n, x);
	}
	T&operator[](int a){
		if (a < n) {
			return p[a];
		}
	}
	T* begin() {
		return p;
	}
	T* end() {
		return p+n;
	}
};

int main() {
	std::ostream_iterator<int> os(std::cout, " ");
	array<int, 10> a(4);
	a[0] = a[2] += 5;
	copy(a.begin(), a.end(), os);
}