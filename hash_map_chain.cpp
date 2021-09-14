
// 체이닝을 사용하여 발생한 충돌 문제를 해결함

#include <iostream>
#include <vector> 

//추가
#include <list>
#include <algorithm>

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
class hash_map_chain {
	std::vector<std::list<int>> data;

public:

	// 생성자
	hash_map_chain(size_t n)
	{
		data.resize(n);
	}

	// 삽입 함수
	void insert(uint value)
	{
		int n = data.size();
		data[value % n].push_back(value);
		std::cout << "[SYSTEM] : Insert data : " << value << std::endl;

	}

	// 특정 원소가 해시맵에 있는지를 확인하는 룩업 함수
	bool find(uint value)
	{
		int n = data.size();
		auto& entries = data[value % n];

		// 존재한다면 true, 아니라면 false. entries.end() 와 같아진다면 반복자가 값을 찾지 못해 끝에 도달했다는 말이기 때문. 
		return std::find(entries.begin(), entries.end(), value) != entries.end();
	}

	void erase(uint value)
	{
		int n = data.size();
		auto& entries = data[value % n];
		
		// 반복자를 활용하여 find 메서드를 이용하여 value 값을 찾아낸다
		auto iter = std::find(entries.begin(), entries.end(), value);

		// 값이 존재한다면 삭제시킨다.
		if (iter != entries.end())
		{
			entries.erase(iter);
			std::cout << "[SYSTEM] : Delete data : " << value << endl;
		}
		else {
			std::cout << "[SYSTEM] : Can't find data. " << endl;
		}

	}
};


int main()
{

	hash_map_chain map_chain(7);

	auto print = [&](int value) {
		if (map_chain.find(value))
		{
			std::cout << "[SYSTEM] : Find data in hash map : " << value << endl;
		}
		else

		{
			std::cout << "[SYSTEM] : Can't find data. " << endl;
		}

	};

	map_chain.insert(1);
	map_chain.insert(2);
	map_chain.insert(25);
	map_chain.insert(10);

	print(1);
	print(2);
	print(25);
	print(10);

	map_chain.insert(100);
	map_chain.insert(200);
	map_chain.insert(300);
	map_chain.insert(400);

	print(1);
	print(2);
	print(25);
	print(10);

	print(100);
	print(200);
	print(300);
	print(400);


	// 시간 복잡도 O(n) 

	// 부하율 = 전체 키 개수 / 해시 테이블 크기 

	





	return 0 ;

}