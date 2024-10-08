#include "Task_1.h"

/*
Массив, который вы будете выводить на экран, не просто динамический, 
а массив, у которого может быть запас. Помимо указателя на динамический 
массив и его фактический размер, то есть максимальное количество элементов, 
которое массив может хранить, вы должны знать его логический размер, то есть 
количество добавленных в этот массив элементов. Поэтому сигнатура вашей функции 
вывода будет выглядеть так: void print_dynamic_array(int* arr, int logical_size, int actual_size). 
Эта функция вам потребуется в следующих заданиях.

Помните: логический размер массива не может превышать его фактический размер.

Массив должен выводиться на экран следующим образом: элементы массива, 
входящие в его логический размер, должны выводиться как есть, а те элементы, 
которые выходят за границы логического размера, должны выводиться, 
как символ _ (нижнее подчёркивание). Элементы массива разделяются символом пробела.

Реализуйте ввод такого динамического массива с пользовательской консоли. 
Пользователь должен предоставить:

Фактический размер массива.
Логический размер массива.
Элементы для заполнения массива. Их количество будет равно логическому размеру массива.
Вы должны создать массив, который может хранить количество элементов, равное фактическому размеру массива.

После ввода пользователем массива с консоли выведите на консоль полученный массив 
с помощью созданной вами функции print_dynamic_array.

Примеры работы программы
Введите фактичеcкий размер массива: 10
Введите логический размер массива: 7
Введите arr[0]: 1
Введите arr[1]: 2
Введите arr[2]: 3
Введите arr[3]: 4
Введите arr[4]: 5
Введите arr[5]: 6
Введите arr[6]: 7
Динамический массив: 1 2 3 4 5 6 7 _ _ _

Введите фактичеcкий размер массива: 8
Введите логический размер массива: 9
Ошибка! Логический размер массива не может превышать фактический!
*/

std::pair<int, int> input_sizes() {
	int size_a{ 0 };
	int size_l{ 0 };

	std::cout << "Введите фактичеcкий размер массива: ";
	std::cin >> size_a;

	do {
		std::cout << "Введите логический размер массива : ";
		std::cin >> size_l;

		if (size_l > size_a) {
			std::cout << "Ошибка! Логический размер массива не может превышать фактический! Уточните размер!" << std::endl;
		}
		else break;
	} while (true);
	std::cout << std::endl;
	return { size_l ,size_a };
}

int* create_dynamic_array( int actual_size) {

	int *arr = new int[actual_size];

	for (int i = 0; i < actual_size; ++i) {
		arr[i] = 0;
	}

	return arr;
}

void print_dynamic_array(int* arr, int logical_size, int actual_size) {

	for (int i = 0; i < (actual_size); ++i) {

		if (i <= (logical_size - 1)) {
			std::cout << arr[i] << " ";
		}
		else {
			std::cout << "_ ";
		}
	}
}

void delete_dynamic_array(int* arr) { delete [] arr; }

void Task_1() {
	
	std::pair<int, int> sizes = input_sizes();
	int size_arr = sizes.second;
	int size_logic_arr = sizes.first;
	int* arr_x = create_dynamic_array(size_arr);

	for (int i = 0; i <= (size_logic_arr - 1); ++i) {
		
		std::cout << "Введите arr[" << i << "]: ";
		std::cin >> arr_x[i];				
	}
	std::cout << std::endl;

	std::cout << "Динамический массив: ";
	print_dynamic_array(arr_x, size_logic_arr, size_arr);

	std::cout << "\n" << std::endl;
	delete_dynamic_array(arr_x);
};