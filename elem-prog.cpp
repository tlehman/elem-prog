int main() {
template<typename F>
    requires(Transformation(F))
DistanceType(F) distance(Domain(F) x, Domain(F) y, F f)
{
  // Precondition: y is reachable from x under f
  typedef DistanceType(F) N;
  N n(0);
  while(x != y) {
    x = f(x);
    n = n + N(1);
  }
  return n;
}
return 0;
}

int main() {
#define DistanceType(ftype) std::size_t
return 0;
}
