#ifndef BIGNUMBER_H
#define BIGNUMBER_H

#include <QString>

typedef unsigned int quint;

#define MAX_CHAR 512 //максимум знаков в числе
#define BIG_BASE 10000 //база счисления(на ячейку)
#define SIZE_OF_ARRAY MAX_CHAR / 4 //10000 - short
#define DIMENSION 65526

template <typename T>
void invert_string( T & tmp ) {
    int size = tmp.length();
    QChar tmpChar;
    for ( int i = 0; i < size / 2; ++i ) {
        tmpChar = tmp[i];
        tmp[i] = tmp[size - i - 1];
        tmp[size - i - 1] = tmpChar;
    }
}

class bigNumber
{
    short arr[SIZE_OF_ARRAY];
    short currentSize = 0;
    bool Negative = false;
    quint sizeOfInt = sizeof(int);
public:
    bigNumber(){
        memset(arr, 0, SIZE_OF_ARRAY * sizeof(short));
    }
    bigNumber(const QString & income);

    bigNumber & operator+(const bigNumber & other);
    bigNumber & operator=(const bigNumber & other);
    bool operator->*(const bigNumber & other);//thats MOD operator >
    bool operator>(const bigNumber & other);

    friend bool operator==(const bigNumber & left, const bigNumber & right);
    friend std::ostream & operator<< (std::ostream &out, const bigNumber & number);
    short getSize() const;
    bool isNegative() const;
    bool isPositive() const;

    void setNegative();
    void setPositive();
};

#endif // BIGNUMBER_H
