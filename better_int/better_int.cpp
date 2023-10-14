#include <iostream>

class BetterInt {
  public:
    BetterInt(int new_num = 0){this->num = new_num;}
    BetterInt operator=(int& new_num) {
      this->num = new_num;
      return BetterInt(new_num);
    }
    BetterInt& operator++() {
      ++this->num;
      return *this;
    }
    BetterInt& operator--() {
      --this->num;
      return *this;
    }
    BetterInt operator++(int) {
      BetterInt temp = *this;
      ++num;
      return temp;
    }
    BetterInt operator--(int) {
      BetterInt temp = *this;
      --num;
      return temp;
    }
    friend std::ostream& operator<<(std::ostream& out, const BetterInt& number) {
      out << number.num;
      return out;
    }
  private:
    int num;
};

int main() { 
  BetterInt a = 2;
  std::cout << a++--++--++--++-- << std::endl;

  return 0;
}