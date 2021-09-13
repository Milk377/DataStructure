
#include <iostream>
#include <vector>

using namespace std;

using uint = unsigned int;

class hash_map {
	std::vector<int> data;

public:
	// 생성자
	hash_map(size_t n)
	{
		data = std::vector<int>(n, -1);
	}

	// 데이터 삽입 함수
	void insert(uint value)
	{
		int n = data.size();
		data[value % n] = value;
		std::cout << "[SYSTEM] : Insert data : " << value << std::endl;
	}

	// 중복이 있는지 찾는 룩업 함수 
	bool find(uint value) {
		int n = data.size();
		return (data[value % n] == value);
	}

	void erase(uint value) {
		int n = data.size();
		if (data[value % n] == value)
		{
			data[value % n] = -1;
			std::cout << "[SYSTEM] : Delete data : " << value << std::endl;
		}
	}
};


int main()
{
	hash_map map(7);

	auto print = [&](int value) {
		if (map.find(value)) std::cout << "[SYSTEM] : In hash find data : " << value << std::endl;
		else std::cout << "[SYSTEM] : Can find data in hash. " << std::endl;

		std::cout << std::endl;

	};


	// 1,2,3,4,5 삽입
	map.insert(1);
	map.insert(2);
	map.insert(3);
	map.insert(4);
	map.insert(5);

	// 1 존재 확인
	print(1);
	// 2 존재 확인
	print(2);

	// 1 제거
	map.erase(1);

	// 1제거 확인
	print(1);

	// 추가로 이전 기능에 이상이 있는지 랜덤하게 확인
	print(4);
	print(2);

	// 100 삽입
	map.insert(100);

	// 100 을 삽입하여 중복되는 값인 2와 충돌하는지 확인. 충돌했다면 2를 찾지못함
	print(2);

	// 찾지 못하는게 확인. 







	return 0 ;

}