#include "LittleComputer.h"

/**
 * @brief Assignment 1 LittleComputer
 * @name Yifei Zhao
 */
LittleComputer::LittleComputer()
{
  for (int i = 0; i < 20; i++) {
    memory[i] = 0;
  }

  programCounter = 0;
  accumulator = 0;
};

//  LittleComputer::LittleComputer(int instructions[], int
//  numberOfInstructions){
//     for (int i = 0; i < 20; i++){
//              memory[i] = instructions[i];
//         }

//  }
int LittleComputer::getProgramCounter()
{
  return programCounter;
}
int LittleComputer::getAccumulator()
{
  return accumulator;
}
int LittleComputer::getMemoryAt(int location)
{
  if (location >= 0 && location < 20)
    return memory[location];
  return 0;
}
int LittleComputer::getCurrentInstruction()
{
  return getMemoryAt(programCounter);
}

// Resets the accumulator and program counter to 0 but leaves memory unchanged.
void LittleComputer::restart()
{
}

// Asks the LittleComputer to run the current instruction
void LittleComputer::step()
{
  //  if (programCounter < 19){
  //         //do things

  //  }
  //  programCounter++;
}

bool isHalted()
{
  return false;
}
void restart()
{
}
