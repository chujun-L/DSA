#include <iostream>
#include "include/array.h"

int main()
{
	array_t *array = NULL;
	int data, i = 0;

	array = createArray(5, sizeof(int));

	while (1) {
		std::cout << "�������������: ";
		std::cin >> data;

		pushArray(array, data);

		std::cout << array->elts[i++] << std::endl;
	}


	system("pause");
	return 0;
}