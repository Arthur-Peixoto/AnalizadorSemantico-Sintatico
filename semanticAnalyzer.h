#include <iostream>
#include <sstream>
#include <string> 
#include <vector>
#include <map>
#include <cmath>
#include <cstdlib>
#include <unordered_set> 

using std::vector;
using std::string;
using std::cout;
using std::endl;

class semanticAnalyzer {
  private:

  public:
  int qntdErrors = 0;
    vector<string> precAux;
    vector<string> onlys;
    vector<string> semanticErrors;
    vector<string> coercionAppeareds;

    semanticAnalyzer();
    ~semanticAnalyzer();

    void onlyCheck(const string& currentOper, int currentLine);
    void coercionChecker(const string& currentDtype, const string& num, int currentLine);
};