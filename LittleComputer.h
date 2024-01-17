#ifndef LITTLECOMPUTER_H
#define LITTLECOMPUTER_H


class LittleComputer {
private:
    int memory[20];
    int accumulator;
    int programCounter;
    /*Memory should be an array of 20 integers - we will never try to load a program with more instructions than that. We will also never load a program that tries to access memory locations lower than 0 or greater than 19.

The programCounter or PC represents the instruction that will be executed next. i.e. if the programCounter is 1 and the computer does a step, the instruction at 1 will be executed.

The accumulator will store the value of the most recent computation done by the Little Computer.*/
public:
    LittleComputer();
    //This takes an array that contains a list of instructions and a size of the array. The instructions from the array provided should be copied into the computer's memory starting at address 0.
    LittleComputer(int instructions[], int numberOfInstructions);
    
    int getProgramCounter();

    int getAccumulator();
    int getMemoryAt(int location);
    int getCurrentInstruction();

    void step();
    bool isHalted();
    void restart();

};

#endif // LITTLECOMPUTER_H