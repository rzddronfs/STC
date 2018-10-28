#include "stdafx.h"
#include "CalcEnv.h"
#include <cmath>


static double Calculate( int opcode, double valueA, double valueB, ErrorCode & ec )
{
  ec = ecGood;

  switch( opcode )
  {
    case twAdd: return valueA + valueB;
    case twSubtract: return valueA - valueB;
    case twDivide: return valueA / valueB;
    case twMultiply: return valueA * valueB;
  }

  ec = ecUnknownTypeWork;
  return NAN;
}


double DoIt(int TypeWork, double OperandA, double OperandB, int& ErrorCode)
{
  ::ErrorCode ec = ecGood;
  const double result = Calculate( TypeWork, OperandA, OperandB, ec );
  
  ErrorCode = ec;

  if( ec != ecGood )
    return result;

  if( std::isnormal( result ) )
    return result;

  ErrorCode = ecDenormalized;
  return result;
}


