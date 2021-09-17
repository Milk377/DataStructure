#include <iostream>
#include <vector>

class hash_map
{
	std::vector<int> data1;
	std::vector<int> data2;
	int size;

	//키를 입력하면 해쉬값을 줌
	int hash1(int key) const
	{
		std::cout << "[SYSTEM] : active hash1. -> ";
		return key % size;
	}

	//키를 입력하면 2번째 규칙에 따라 해쉬값을 줌
	int hash2(int key) const
	{

		std::cout << "[SYSTEM] : active hash2. -> " ;
		return (key / size) % size;
	}


public:
	// 생성자에서 data1,data2 값 초기화
	hash_map(int n) : size(n)
	{
		// 초기값 -1 
		data1 = std::vector<int>(size, -1);
		data2 = std::vector<int>(size, -1);
	}

	std::vector<int>::iterator lookup(int key)
	{
		auto hash_value1 = hash1(key);
		if (data1[hash_value1] == key) {
			std::cout << "[SYSTEM] : Find key :" << key << "In table1." << std::endl;
			return data1.begin() + hash_value1;
		}

		auto hash_value2 = hash2(key);
		if (data2[hash_value2] == key)
		{
			std::cout << "[SYSTEM] : Find key :" << key << "In table2." << std::endl;
			return data2.begin() + hash_value2;
		}

		// 원소를 찾지 못할 경우 data2 테이블의 마지막을 가리키는 반복자가 반환됨. 
		return data2.end();

	}

	void erase(int key)
	{
		auto position = lookup(key);

		//데이터를 찾은 경우 
		if (position != data2.end())
		{
			*position = -1;
			std::cout << key << " 에 해당하는 원소 삭제 " << std::endl;
		}
		else
		{
			std::cout << "[SYSTEM] : Can't find key" << std::endl;
		}
	}

	void insert(int key)
	{
		insert_impl(key, 0, 1);
	}

	void insert_impl(int key, int cnt, int table)
	{
		if (cnt >= size)
		{
			std::cout << key << " 삽입 시 순환 발생!! 재 해싱이 필요합니다!" << std::endl;
			return;
		}

		if (table == 1)
		{
			int hash = hash1(key);
			if (data1[hash] == -1)
			{
				std::cout << table << "번 테이블에" << key << " 삽입" << std::endl;
				data1[hash] = key;

			}
			else
			{
				int old = data1[hash];
				data1[hash] = key;
				std::cout << table << " 번 테이블에 " << key << "삽입 : 기존의 " << old << " 이동 ->"; 
				insert_impl(old, cnt + 1, 2);
				
			}
		}
		else if(table == 2){
			int hash = hash2(key);
			if (data2[hash] == -1)
			{
				std::cout << table << "번 테이블에" << key << " 삽입" << std::endl;
				data2[hash] = key;

			}
			else
			{
				int old = data2[hash];
				data2[hash] = key;
				std::cout << table << " 번 테이블에 " << key << "삽입 : 기존의 " << old << " 이동 ->";
				insert_impl(old, cnt + 1, 2);

			}

		}
		else
		{
			std::cout << "[SYSTEM] : table number error!." << std::endl;
		}
	}

	void print()
	{
		std::cout << "Index: ";
		for (int i = 0; i < size; i++)
		{
			std::cout << i << '\t';

		}
		std::cout << std::endl;

		std::cout << "Data1: ";
		for (auto i : data1)
		{
			std::cout << i << '\t';

		}
		std::cout << std::endl;


		std::cout << "Data2: ";
		for (auto i : data2)
		{
			std::cout << i << '\t';

		}
		std::cout << std::endl;

	}



};

int main()
{
	hash_map map(7);
	map.print();
	std::cout << std::endl;

	map.insert(10);
	map.insert(20);
	map.insert(30);

	std::cout << std::endl;

	map.print();
	map.insert(104);
	map.insert(2);
	map.insert(70);
	map.insert(9);
	map.insert(90);
	map.insert(2);
	map.insert(7);

	map.print();
	std::cout << std::endl;

	map.insert(14);

} 