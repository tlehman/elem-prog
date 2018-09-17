#include <iostream>
#include <type_traits>

using namespace std;


#define Domain(ftype) typename ftype::DomainType
#define requires(...)

template<typename Op>
  requires(BinaryOperation(Op))
Domain(Op) square(const Domain(Op)& x, Op op)
{
  return op(x, x);
}

template <typename T>
struct BinaryOperation {
  typedef T DomainType;
  typedef T ReturnType;
  typedef std::function<T(T,T)> FuncType;
  FuncType fn;
  ReturnType operator()(DomainType x, DomainType y) {
    return fn(x,y);
  };
};


int main()
{
  BinaryOperation<int> mult;
  mult.fn = [](int a, int b) { return a * b; };

  cout << square<BinaryOperation<int>>(2, mult) << endl
       << square<BinaryOperation<int>>(3, mult) << endl;
  return 0;
}
