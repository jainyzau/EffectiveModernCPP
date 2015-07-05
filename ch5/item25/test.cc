#include <iostream>
#include <string>

class Matrix
{
    public:
        Matrix()
        {
        }

        Matrix(const Matrix&)
        {
            std::cout << "copy constructor of Matrix is called" << std::endl;
        }

        /*
        Matrix(Matrix&& rhs)
        {
            std::cout << "move constructor of Matrix is called" << std::endl;
        }
        */

        Matrix& operator=(const Matrix& rhs)
        {
            std::cout << "assignment operator of Matrix is called" << std::endl;
            return *this;
        }

        void operator+=(const Matrix& rhs)
        {
        }
};

Matrix operator+(Matrix&& lhs, const Matrix& rhs)
{
    std::cout << "move +" << std::endl;
    lhs += rhs;
    return std::move(lhs);
}

Matrix operator+(Matrix& lhs, const Matrix& rhs)
{
    std::cout << "copy +" << std::endl;
    lhs += rhs;
    return lhs;
}

void func(std::string&& aVal)
{
    aVal[0] = 'a';
    std::cout << aVal << std::endl;
}

void func2(const std::string& aVal)
{
    std::cout << __func__ << " const std::string&" << std::endl;
}

void func2(std::string& aVal)
{
    std::cout << __func__ << " std::string&" << std::endl;
}

void func2(std::string&& aVal)
{
    std::cout << __func__ << " std::string&&" << std::endl;
}

void func2(const std::string&& aVal)
{
    std::cout << __func__ << " const std::string&&" << std::endl;
}

void func3(std::string&& aVal)
{
    std::cout << __func__ << "std::string&&" << std::endl;
}

int main()
{
    func("Able");
    func2("Capable");

    std::string lStr("Wise");
    func3(std::move(lStr));

    Matrix m0;
    Matrix m1;
    Matrix m2;
    Matrix m3;

    //m0 = std::move(m0) + m1 + m2 + m3;
    m0 + m1 + m2 + m3;
}
