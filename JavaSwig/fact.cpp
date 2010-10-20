unsigned int fact(unsigned int i) {
  unsigned result = 1;
  unsigned int c=1;
  while ( c <= i ) {
    result *= c;
    c++;
  }
  return result;
}
