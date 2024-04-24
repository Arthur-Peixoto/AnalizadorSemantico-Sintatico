#include "semanticAnalyzer.h"

semanticAnalyzer::semanticAnalyzer()
{
}

semanticAnalyzer::~semanticAnalyzer()
{
}

void semanticAnalyzer::onlyCheck(const string& currentOper, int currentLine)
{
     // Usar um set para evitar duplicatas
    std::unordered_set<std::string> unique_onlys(onlys.begin(), onlys.end());

    // Remover itens em precAux do set unique_onlys
    for (const auto& item : precAux) {
        unique_onlys.erase(item);
    }

    // Adicionar erros para elementos restantes em unique_onlys
    for (const auto& item : unique_onlys) {
        string error = "(Linha " + std::to_string(currentLine) + ") \"" + item + "\" não foi declarada antes de ser fechada.\n";
        semanticErrors.push_back(error);
    }
}

void semanticAnalyzer::coercionChecker(const string& currentDtype, const string& num, int currentLine){

    // Split the dtype into its components
    std::vector<std::string> dtype;
    std::istringstream stream(currentDtype);
    std::string token;

    while (std::getline(stream, token, ':')) {
        dtype.push_back(token);
    }

    const std::string& last_type = dtype.back(); // Tipo atual

    int num_as_int = std::atoi(num.c_str());
    bool has_decimal_point = (num.find('.') != std::string::npos);

    // Checar se o número é menor ou igual a zero
    if (num_as_int <= 0) {
        string error = "(Linha " + std::to_string(currentLine) + ") Não pode ser atribuído \"" + num + "\" ao quantificador de \"" + last_type + "\".\n";
        semanticErrors.push_back(error);
        return; // Não precisa continuar se houver erro
    }

    // Checar coerção com base no tipo
    if (last_type == "string") {
        // Sem verificações específicas para string
    } else if (last_type == "integer") {
        if (has_decimal_point) {
            string error = "(Linha " + std::to_string(currentLine) + ") \"" + num + "\" não pode ser atribuído ao tipo \"integer\".\n"; 
            semanticErrors.push_back(error);
        }
    } else if (last_type == "float" || last_type == "double") {
        if (!has_decimal_point) {
            string error = "(Linha " + std::to_string(currentLine) + ") \"" + num + "\" não pode ser atribuído ao tipo \"" + last_type + "\".\n";
            semanticErrors.push_back(error);
        }
    }

}