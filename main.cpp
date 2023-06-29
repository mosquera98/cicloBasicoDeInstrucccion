#include <iostream>
#include <unordered_map>
#include <sstream>
#include <fstream>
using namespace std;

unordered_map<string, int> memory;
int accumulator = 0;
int instructionCounter = 0;
int memoryAddressRegister = 0;
int memoryDataRegister = 0;

void executeInstruction(const string& instruction) {
  stringstream chain (instruction);
  string opCode, operand1, operand2, operand3;
  chain >> opCode >> operand1 >> operand2 >>
   operand3;

  if (opCode == "SET") {
    memory[operand1] = stoi(operand2);
  } else if (opCode == "ADD") {
    int value1 = (operand1 == "NULL") ? 0 : memory[operand1];
    int value2 = (operand2 == "NULL") ? 0 : memory[operand2];
    accumulator += value1 + value2;
  } else if (opCode == "LDR") {
    accumulator = memory[operand1];
  } else if (opCode == "STR") {
    memory[operand1] = accumulator;
  } else if (opCode == "SHW") {
    if (operand1 == "ACC") {
      cout << "Accumulator: " << accumulator << endl;
    } else if (operand1 == "ICR") {
      cout << instructionCounter << endl;
    } else if (operand1 == "MAR") {
      cout << memoryAddressRegister << endl;
    } else if (operand1 == "MDR") {
      cout << memoryDataRegister << endl;
    } else if (operand1 == "UC") {
      cout << instructionCounter << endl;
    } else {
      cout << memory[operand1];
    }
    exit(0);
  }
}

int main() {
  ifstream archivo("ENTRADA1.txt");  // Nombre del archivo de entrada

  if (!archivo) {
    cerr << "No se pudo abrir el archivo de entrada." << endl;
    return 1;
  }

  string instruction;
  while (getline(archivo, instruction)) {
    executeInstruction(instruction);
  }

  archivo.close();

  return 0;
}