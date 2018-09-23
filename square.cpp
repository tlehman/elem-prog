#include <iostream>
#include <functional>

using namespace std;


#define Domain(ftype) typename ftype::DomainType
#define requires(...)

template<typename Op>
  requires(BinaryOperation(Op))
Domain(Op) square(const Domain(Op)& x, Op op)
{
  return op(x, x);
}

int main()
{
  BinaryOperation<int> mult;
  mult.fn = [](int a, int b) { return a * b; };

  cout << square<BinaryOperation<int>>(2, mult) << endl
       << square<BinaryOperation<int>>(3, mult) << endl;
  return 0;
}
