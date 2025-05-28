#include "../include/Fixed.hpp"

int main( void ) {
   Fixed a;
   Fixed const b( Fixed( 6.05f ) * Fixed( 2 ) );
   std::cout << "A number is: " << a << std::endl;
   std::cout << "A pre-incremented: " << ++a << std::endl;
   std::cout << "A has stance: " << a << std::endl;
   std::cout << "A post-incremented: " << a++ << std::endl;
   std::cout << "A has stance: " << a << std::endl;

   std::cout << "B number is: " << b << std::endl;
   std::cout << "The bigger number is: " << Fixed::max( a, b ) << std::endl;
   std::cout << "The less number is: " << Fixed::min( a, b ) << std::endl;
   Fixed const c( a * b );
   Fixed const d(a / b);
   std::cout << "A multiplied by B is: " << c << std::endl;
   std::cout << "A divideded by B is: " << d << std::endl;
   return 0;
}
