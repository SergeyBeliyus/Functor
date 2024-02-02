#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
class Functor {
private:
	T sum;
	int count;
public:
	Functor() {
		sum = 0;
		count = 0;
	}

	T get_sum() {
		return sum;
	}

	int get_count() {
		return count;
	}

	void operator()(T value){
		if (value % 3 == 0) {
			sum += value;
			count++;
		}
	}

};

void printing(std::string what, std::vector<int> vec) {
	std::cout << what << " ";
	for (size_t i = 0; i < vec.size(); i++) {
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
}

int main() {
	Functor<int> f;
	std::vector<int> vec;
	int input;
	std::cout << "[IN]: ";
	std::cin >> input;
	while (input != 0) {
		vec.push_back(input);
		std::cout << "[IN]: ";
		std::cin >> input;
	}

	printing("[IN]:", vec);

	for (size_t i = 0; i < vec.size(); i++) {
		f(vec[i]);
	}

	std::cout << "[OUT]: " << "get_sum() " << f.get_sum() << std::endl;
	std::cout << "[OUT]: " << "get_count() " << f.get_count() << std::endl;
}