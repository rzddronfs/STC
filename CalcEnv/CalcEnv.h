#pragma once

#ifdef CONTEXT_4E49CB3A52154134B189035180892B5F
#define DLLSPEC __declspec(dllexport)
#else
#define DLLSPEC __declspec(dllimport)
#endif

#ifdef __cplusplus
extern "C" {
#endif

enum TypeWork
{
  twAdd,
  twSubtract,
  twDivide,
  twMultiply,
};

enum ErrorCode
{
  ecGood,
  ecUnknownTypeWork,
  ecDenormalized,
};

DLLSPEC
double DoIt (int TypeWork, double OperandA, double OperandB, int& ErrorCode);


#ifdef __cplusplus
} //extern "C"
#endif
