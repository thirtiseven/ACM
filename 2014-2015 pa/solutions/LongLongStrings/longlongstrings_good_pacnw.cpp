#include <fstream>
#include <iostream>
#include <string>
#include <vector>

// Requires C++11.  Must be compiled with -std=c++11 or higher.

struct Operation {
  char operation;
  size_t index;
  char c;
  bool operator==(const Operation& other) const {
    return operation == other.operation && index == other.index && c == other.c;
  }
};
using Program = std::vector<Operation>;

Program readProgram(std::istream& in) {
  Program program;
  do {
    Operation op{};
    in >> op.operation;
    if (op.operation == 'E')
      break;
    in >> op.index;
    if (op.operation == 'I')
      in >> op.c;
    program.emplace_back(op);
  } while (true);
  return program;
}

// Normalize a program by transforming it to its cannonical form, which looks like:
//   D i1, D i2, ... D iN, I j1, I j2, ..., I jM
//   where i1 > i2 > ... > iN  and j1 < j2 < ... < jM
// We can convert to the canonical form by applying the following transformation rules:
//
// Rule 1:
// ..., D k, D l, ...  ->  ..., D l+1, D k, ...  if k <= l
// Rule 2:
// ..., I k, I l, ...  ->  ..., I l, I k+1, ...  if k >= l
// Rule 3a:
// ..., I k, D l, ...  ->  ..., D l, I k-1, ...  if k > l
// Rule 3b:
// ..., I k, D l, ...  ->  ..., ...  if k == l
// Rule 3c:
// ..., I k, D l, ...  ->  ..., D l-1, I k, ...  if k < l

void normalizeProgram(Program& p) {
  for (int i = 1; i < int(p.size()); ++i) {
    for (int j = i; j > 0; --j) {
      if (p[j-1].operation == 'D' && p[j].operation == 'D' && p[j-1].index <= p[j].index) {
	std::swap(p[j-1], p[j]);
	p[j-1].index++;
      } else if (p[j-1].operation == 'I' && p[j].operation == 'I' && p[j-1].index >= p[j].index) {
	std::swap(p[j-1], p[j]);
	p[j].index++;
      } else if (p[j-1].operation == 'I' && p[j].operation == 'D') {
	if (p[j-1].index > p[j].index) {
	  std::swap(p[j-1], p[j]);
	  p[j].index--;
	} else if (p[j-1].index == p[j].index) {
	  p.erase(p.begin() + j - 1, p.begin() + j + 1);
	  i -= 2;	  
	  break;
	} else {
	  std::swap(p[j-1], p[j]);
	  p[j-1].index--;
	}
      } else {
	break;
      }
    }
  }
}


bool comparePrograms(size_t, const Program& prog_a, const Program& prog_b) {
  Program norm_a = prog_a, norm_b = prog_b;
  normalizeProgram(norm_a);
  normalizeProgram(norm_b);
  return norm_a == norm_b;
}

int main(int argc, char **argv) {
  std::ifstream fin;
  if (argc >= 2) {
    fin.open(argv[1]);
  }
  std::istream& in = argc >= 2 ? fin : std::cin;
  size_t N = 10000000000 ;
  {
    Program a = readProgram(in);
    Program b = readProgram(in);
    std::cout << (comparePrograms(N, a, b) ? "0" : "1") << std::endl;
  }
  return 0;
}
