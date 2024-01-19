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
}

LittleComputer::LittleComputer(int instructions[], int numberOfInstructions)
{
  for (int i = 0; i < numberOfInstructions; i++) {
    memory[i] = instructions[i];
  }
  for (int i = numberOfInstructions; i < 20; i++) {
    memory[i] = 0;
  }
  programCounter = 0;
  accumulator = 0;
}


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
}//need examination

int LittleComputer::getCurrentInstruction()
{
  return getMemoryAt(programCounter);
}

// Resets the accumulator and program counter to 0 but leaves memory unchanged.
void LittleComputer::restart()
{
  programCounter = 0;
  accumulator = 0;  
}

// Asks the LittleComputer to run the current instruction
void LittleComputer::step() {
  // Extracting the opcode and address from the current instruction
  int instruction = getCurrentInstruction();
  int opcode = instruction / 100;
  int address = instruction % 100;

  // HALT
  if (opcode == 0) {
    // If it's a halt instruction, you may want to handle it here.
    return;
  }
  //1
  // Add value from location to the accumulator.
  else if (opcode == 1) {
    accumulator += getMemoryAt(address);
    programCounter++;
  }
  //2
  // Sub value from location from the accumulator.
  else if (opcode == 2) {
    accumulator -= getMemoryAt(address);
    programCounter++;
  }
  //3
  // Store accumulator in location.
  else if (opcode == 3) {
    memory[address] = accumulator;
    programCounter++;
  }
  //5
  // Load from location i to the accumulator.
  else if (opcode == 5) {
    accumulator = getMemoryAt(address);
    programCounter++;
  }
  //6
  // Branch always to the address.
  else if (opcode == 6) {
    programCounter = address;
  }
  //7
  // Branch if accumulator is 0.
  else if (opcode == 7) {
    if (accumulator == 0) {
      programCounter = address;
    } else {
      programCounter++;
    }
  }

    int i = getCurrentInstruction() - 700;
      if(getMemoryAt(i)==0){
        programCounter = getMemoryAt(i); // branch
        //won't increase counter
      }else{
      programCounter += 1; // move on if 0 test false.
      }
    }
  
}

bool LittleComputer::isHalted()
{
  if ( getMemoryAt(programCounter+1) == 0)
    {
      return true;
    }
  else
   {
    return false;
    }
}
