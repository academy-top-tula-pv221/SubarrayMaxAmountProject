#include <iostream>

void ArrayInit(int* array, int size)
{
    for (int i = 0; i < size; i++)
        array[i] = rand() % 100;
}

void ArrayPrint(int* array, int size)
{
    for (int i = 0; i < size; i++)
        std::cout << array[i] << " ";
    std::cout << "\n";
}

int main()
{
    srand(time(nullptr));
    
    int half{ 7 };
    int size{ half * 2 };
    int* array = new int[size];

    ArrayInit(array, size);
    ArrayPrint(array, size);

    {
        int amountMax = array[0];
        int indexMax{};

        for (int i = 0; i < size / 2 + 1; i++)
        {
            int amountCurr{};
            for (int j = i; j < i + size / 2; j++)
                amountCurr += array[j];
            if (amountCurr > amountMax)
            {
                amountMax = amountCurr;
                indexMax = i;
            }
            std::cout << "index: " << i << " amount = " << amountCurr << "\n";
        }

        std::cout << "max amount = " << amountMax << " in " << indexMax << " subarray\n";
    }
    std::cout << "\n\n";

    int indexMax{ 0 };
    int amountMax{ 0 };
    for (int i = 0; i < size / 2; i++)
        amountMax += array[i];
    
    int amountCurr = amountMax;
    for (int i = 1; i < size / 2 + 1; i++)
    {
        amountCurr = amountCurr - array[i - 1] + array[i + size / 2 - 1];
        if (amountCurr > amountMax)
        {
            amountMax = amountCurr;
            indexMax = i;
        }
        std::cout << "index: " << i << " amount = " << amountCurr << "\n";
    }


    std::cout << "max amount = " << amountMax << " in " << indexMax << " subarray\n";
}
