#include <iostream>
#include <list>
#include <list>

class Size {
public:
    Size() { symbol = 'M'; }
    Size(char symbol) { this->symbol = symbol; }

    bool operator>(const Size &second) { return index(symbol) > index(second.symbol); }
    bool operator<(const Size &second) { return index(symbol) < index(second.symbol); }
    bool operator==(const Size &second) { return symbol == second.symbol; }

    char get_symbol() { return symbol; }

private:

    char symbols[5] = {'A', 'B', 'C', 'D', 'E'};
    int symbols_size = 5;
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
void shaker_sort(type array[], int size)
{
    for (int left_idx = 0, right_idx = size - 1;
         left_idx < right_idx;)
    {
        for (int idx = left_idx; idx < right_idx; idx++)
        {
            if (array[idx + 1] < array[idx])
            {
                swap<type>(array[idx], array[idx + 1]);
            }
        }
        right_idx--;

        for (int idx = right_idx; idx > left_idx; idx--)
        {
            if (array[idx - 1] >  array[idx])
            {
                swap<type>(array[idx - 1], array[idx]);
            }
        }
        left_idx++;
    }
}

template < typename type >
void gnome_sort(type array[], int size) {
    for (int i = 0; i + 1 < size; ++i) {
        if (array[i] > array[i + 1]) {
            swap(array[i], array[i + 1]);
            if (i != 0)
                i -= 2;
        }
    }
}

int main() {
    const int size = 9;
    int  int_array[size] {1, 3, 2, 7, 5, 9, 4, 6, 8};
    double double_array[size] {1.3, 1.0, 1.2999, 2.1, 2.001, 3.17, 3.5, 12.3, 7.2};
    Size size_array[size] {
        Size('B'),
        Size('A'),
        Size('C'),
        Size('D'),
        Size('A'),
        Size('D'),
        Size('E'),
        Size('A'),
        Size('C')
    };

    shaker_sort<int>(int_array, size);
    shaker_sort<double>(double_array, size);
    shaker_sort<Size>(size_array, size);

    for (int i = 0; i < size; i++)
        std::cout << int_array[i] << ' ';
    std::cout << std::endl;
    for (int i = 0; i < size; i++)
        std::cout << double_array[i] << ' ';
    std::cout << std::endl;
    for (int i = 0; i < size; i++)
        std::cout << size_array[i].get_symbol() << ' ';
    std::cout << std::endl;

    int gnome_int_array[size] {4, 6, 5, 12, 8, 12, 7, 9, 11};
    double gnome_double_array[size] {1.31, 11.0, 12.2999, 32.1, 2.0501, 33.17, 33.5, 12.63, 7.42};
    Size gnome_size_array[size] {
        Size('A'),
        Size('B'),
        Size('C'),
        Size('E'),
        Size('A'),
        Size('C'),
        Size('E'),
        Size('D'),
        Size('C')
    };

    gnome_sort<int>(gnome_int_array, size);
    gnome_sort<double>(gnome_double_array, size);
    gnome_sort<Size>(gnome_size_array, size);

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
