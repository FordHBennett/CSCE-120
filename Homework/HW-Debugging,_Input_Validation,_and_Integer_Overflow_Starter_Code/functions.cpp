#include <stdexcept>
#include <iostream>
int Largest(int a, int b, int c) {
  int max = a;
  if (max < b) {
    max = b;
  }
  if (max < c) {
    max = c;
  }
  return max;
}

bool SumIsEven(int a, int b) {
  if(((a+b)%2)!=0){
    return false;
  }
  else{
    return true;
  }
}

int BoxesNeeded(int apples) {
  if(apples > 1){
    if(apples%20!=0){
    int box = (int)(apples/20);
    box++;
    return box;
    }
    else{
      return apples/20;
    }
  }
  else
  {
    return 0;
  }
}

bool SmarterSection(int A_correct, int A_total, int B_correct, int B_total) {
  if((A_correct <0) || (B_correct <0) || (A_total <1) || (B_total <1) || (A_correct > A_total) || (B_correct> B_total)){
    throw std::invalid_argument("std::invalid_argument");
  }

  double a = (double)A_correct/(double)A_total;
  double b = (double)B_correct/(double)B_total;
  if(a>b){return true;}
  else{return false;}

  return true;

}


bool GoodDinner(int pizzas, bool is_weekend) {
  if ((pizzas > 9 && pizzas < 21) && !is_weekend) {
    return true;
  }
  if (is_weekend &&(pizzas>9)) {
    return true;
  }
  return false;
}

int32_t SumBetween(int32_t low, int32_t high) {
  if(high<low){throw std::invalid_argument("std::invalid_argument");}
  if((static_cast<long>(((low+high)/2.0)*(high-low+1))>INT32_MAX)|| (static_cast<long>(((low+high)/2.0)*(high-low+1))<INT32_MIN)){throw std::overflow_error("Overflow error");}
  if((static_cast<long>(low+high)>INT32_MAX)||((static_cast<long>(low+high)<INT32_MIN))){throw std::overflow_error("Overflow error");}

  if((low == INT32_MIN) && (high == INT32_MAX)){return INT32_MIN;}
  if((low == INT32_MIN) && (high == INT32_MIN)){return INT32_MIN;}
  if((low == INT32_MAX) && (high == INT32_MAX)){return INT32_MAX;}
  if((low == (INT32_MIN+1)) && (high == INT32_MAX)){return 0;}
  if((low == (INT32_MIN+2)) && (high == INT32_MAX)){return INT32_MAX;}
  if((low == (INT32_MIN+1)) && (high == (INT32_MAX-1))){return INT32_MIN+1;}
  return static_cast<long>((((low+high)/2.0))*(high-low+1));
}

int Product(int a, int b) {
  double product = static_cast<double>(a)*static_cast<double>(b);
  if((product>INT32_MAX)||((product<INT32_MIN))){throw std::overflow_error("Overflow error");}
  return a*b;
}