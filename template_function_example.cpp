#include <iostream>

class Size {
public:
    Size() { symbol = 'M'; }
    Size(char symbol) { this->symbol = symbol; }

    bool operator>(const Size &second) { return index(symbol) > index(second.symbol); }
    bool operator<(const Size &second) { return index(symbol) < index(second.symbol); }
    bool operator==(const Size &second) { return symbol == second.symbol; }
    bool operator>=(const Size &second) { return index(symbol) >= index(second.symbol); }
    bool operator<=(const Size &second) { return index(symbol) <= index(second.symbol); }

    char get_symbol() { return symbol; }
private:
    char symbols[3] = {'S', 'M', 'L'};
    int symbols_size = 3;
    char symbol;

    int index(char symbol) {
        for (int i = 0; i < symbols_size; i++)
            if (symbols[i] == symbol)
                return i;
        return 0;
    }
};

template < typename type >
void swap(type &first, type &second) {
    type temp = first;
    first = second;
    second = temp;
}

template < typename type >
void bubble_sort(type array[], int size)
{
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1; j++)
            if (array[j] > array[j + 1])
                swap<type>(array[j], array[j + 1]);
}

template < typename type >
void selection_sort(type array[], int size)
{
    int min_index;
    for (int i = 0; i < size - 1; i++) {
        min_index = i;
        for (int j = i + 1; j < size; j++)
            if (array[j] < array[min_index])
                min_index = j;
        swap<type>(array[min_index], array[i]);
    }
}

int main() {
    const int size = 9;
    int  int_array[size] {1, 3, 2, 7, 5, 9, 4, 6, 8};
    double double_array[size] {1.3, 1.0, 1.2999, 2.1, 2.001, 3.17, 3.5, 12.3, 7.2};
    Size size_array[size] {
        Size('M'),
        Size('S'),
        Size('S'),
        Size('L'),
        Size('S'),
        Size('S'),
        Size('M'),
        Size('L'),
        Size('M')
    };

    bubble_sort<int>(int_array, size);
    bubble_sort<double>(double_array, size);
    bubble_sort<Size>(size_array, size);

    for (int i = 0; i < size; i++)
        std::cout << int_array[i] << ' ';
    std::cout << std::endl;
    for (int i = 0; i < size; i++)
        std::cout << double_array[i] << ' ';
    std::cout << std::endl;
    for (int i = 0; i < size; i++)
        std::cout << size_array[i].get_symbol() << ' ';
    std::cout << std::endl;

    return 0;
}
