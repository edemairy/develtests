#include <memory>
#include <iostream>
#include <cassert>
using namespace std;

#define VARS(A) cout << "\"" << #A << "\" = " << A << endl;

class SharedFromThis: public enable_shared_from_this<SharedFromThis> {
};

int main(int,char**) {
  std::shared_ptr<int> spi(new int);
  // Normal shared_ptr
  VARS( spi.use_count() );
  assert( spi.use_count() == 1 );
  std::shared_ptr<int> spi1( spi );
  VARS( spi.use_count() );
  VARS( spi1.use_count() );
  assert( ( spi.use_count() == spi1.use_count() ) && (spi.use_count() == 2) );

  // shared_ptr with shared_from_this.
  std::shared_ptr<SharedFromThis> p1( new SharedFromThis );
  VARS( p1.use_count() );
  assert( p1.use_count() == 1 );
  std::shared_ptr<SharedFromThis> p2( p1.get()->shared_from_this() );
  VARS( p1.use_count() );
  VARS( p2.use_count() );
  assert( ( p1.use_count() == p2.use_count() ) && (p2.use_count() == 2) );
}

