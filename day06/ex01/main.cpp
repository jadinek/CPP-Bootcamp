#include <iostream>
#include <string>
#include <cstdlib>

struct Data
{
    std::string s1;
    std::string s2;

    int n;
};

void *serialize(void)
{
    Data *data = new Data;
    data->n = 0;

    static const char alphanumericArray[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";

    for (int i = 0; i < 8; i++)
    {
        data->s1 += alphanumericArray[rand() % 63];
        data->s2 += alphanumericArray[rand() % 63];
    }
    data->n += rand();

    return (reinterpret_cast<void *>(data));
}

Data *deserialize(void *raw)
{
    return (reinterpret_cast<Data *>(raw));
}

int main(void)
{
    srand(time(0));

    void *ptr = serialize();
    Data *desData = deserialize(ptr);

    std::cout << "Serialised: " << std::endl;
    std::cout << ptr << std::endl << std:: endl;

    std::cout << "Deserialised: " << std::endl;
    std::cout << "String 1: " << desData->s1 << std::endl;
    std::cout << "String 2: " << desData->s2 << std::endl;
    std::cout << "Random Integer: " << desData->n << std::endl;
}