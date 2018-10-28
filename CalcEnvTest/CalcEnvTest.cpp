#include "../CalcEnv/CalcEnv.h"
#include <chrono>


int main()
{
  int ec = ecGood;
  double result = 0;
  
  result = DoIt( twAdd, 12.5, 11.5, ec );
  result = DoIt( twSubtract, 12.5, 11.5, ec );
  result = DoIt( twDivide, 12.5, 2.0, ec );
  result = DoIt( twMultiply, 12.5, 0.5, ec );
  result = DoIt( twDivide, 12.5, 0, ec );

  using namespace std::chrono_literals;

  const auto time = 1s;

  return 0;
}

