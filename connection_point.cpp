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
template <typename F>
  requires(Transformation(F))
Domain(F) convergent_point(Domain(F) x0, Domain(F) x1, F f) {
  while(x0 != x1) {
    x0 = f(x0);
    x1 = f(x1);
  }
  return x0;
} 
template <typename F>
  requires(Transformation(F))
Domain(F) connection_point_nonterminating_orbit(const Domain(F)& x, F f) {
  Domain(F) y = collision_point_nonterminating_orbit(x, f);
  return convergent_point(x, f(y), f);
} 

int main() {
  typedef Transformation<int> F;
    
  F handle_tx([](int a) {
      int fa = (a < 4) ? a+1 : (a%5 + 4);
      return fa;
  });
  cout << connection_point_nonterminating_orbit(0, handle_tx) << endl;
  return 0;
}
