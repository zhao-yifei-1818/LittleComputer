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
  for (int i = 0; i <= numberOfInstructions; i++) {
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
void LittleComputer::step()
{
  //000
  //HALT
  if (getCurrentInstruction() ！= 0)
    
    //1
    if ((getCurrentInstruction()/100)%10 == 1){
    // add value from location i to the accumulator.
    int i = getCurrentInstruction()-100;    //get current instruction
    accumulator += getMemoryAt(i);      //and add its value to accumulator.
    programCounter += 1;
    }

    //2
    if ((getCurrentInstruction()/100)%10 == 2){
    // Sub value from location i to the accumulator.
    int i = getCurrentInstruction()-200;     //get current instruction.
    accumulator -= getMemoryAt(i);      //and add its value to accumulator.
    programCounter += 1;}

    //3
    if ((getCurrentInstruction()/100)%10 == 3){
    // Store at location i
    int i = getCurrentInstruction()-300;     //get current instruction.
    memory[i] = accumulator;  //store current accumulator value to instructed memory
      programCounter += 1;}

    //5
    if ((getCurrentInstruction()/100)%10 == 5){
    // Load from location i
    int i = getCurrentInstruction()-500;     //get current instruction.
    accumulator = getMemoryAt(i); // bring out the stored value to accumulator.
    programCounter += 1;
    }
    //6
    if ((getCurrentInstruction()/100)%10 == 6){
    // Branch always
    int i = getCurrentInstruction()-600;     //get current instruction.
    programCounter = getMemoryAt(i);  // changes the program counter to hold the value in XX. 
    // The program counter does not increase by 1 after that.
    }
    //7 
    if ((getCurrentInstruction()/100)%10 == 7){
    // Branch if 0
      //test 0
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
