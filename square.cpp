#include <iostream>
#include <functional>

using namespace std;


#define Domain(FuncType) decltype(FuncType())
#define requires(...)

template<typename Op>
  requires(BinaryOperation(Op))
Domain(Op) square(const Domain(Op)& x, Op op)
{
  return op(x, x);
}

template <typename T>
class Transformation {
public:
  T operator()(T x) {
    return fn(x);
  }
  Transformation(std::function<T(T)>& f) {
    fn = f;
  }
private:
  std::function<T(T)> fn;
};

template <typename T>
class BinaryOperation {
public:
  T operator()(T x, T y) {
    return fn(x, y);
  }
  BinaryOperation(std::function<T(T,T)>& f) {
    fn = f;
  }
private:
  std::function<T(T, T)> fn;
};


int main()
{
  BinaryOperation<int> mult([](int a, int b) { return a * b; });

  cout << square<BinaryOperation<int>(2, mult) << endl
       << square<BinaryOperation<int>(3, mult) << endl;
  return 0;
}
