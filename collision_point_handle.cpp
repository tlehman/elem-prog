#include <iostream>

using namespace std;




#define Domain(ftype) typename ftype::DomainType
#define requires(...)
template <typename T>
struct Transformation {
  typedef T DomainType;
  typedef T ReturnType;
  typedef std::function<T(T)> FuncType;
  Transformation(FuncType fn) {
    this->fn = fn;
  }
  FuncType fn;
  ReturnType operator()(DomainType x) {
    return fn(x);
  };
};
template<typename F>
  requires(Transformation(F))
Domain(F) collision_point_nonterminating_orbit(const Domain(F)& x, F f) {
  Domain(F) slow = x;
  Domain(F) fast = f(x);

  while(fast != slow) {
    slow = f(slow);
    fast = f(fast);
    fast = f(fast);
  }
  return fast;
  // Postconditon: return value is a collision point
}

int main() {
  typedef Transformation<int> F;
    
  F handle_tx([](int a) {
      int fa = (a < 4) ? a+1 : (a%5 + 4);
      cout << a << "->" << fa << "; ";
      return fa;
  });
  cout << collision_point_nonterminating_orbit(0, handle_tx) << endl;
  return 0;
}
