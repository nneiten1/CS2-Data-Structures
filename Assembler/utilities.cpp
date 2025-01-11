//
//
// nicholas neitenbach
//
//
//

#include "utilities.hpp"
#include "../string/string.hpp"
#include "imp.cpp"

void toPostfix(std::ifstream& in, std::ostream& out) {
    stack<String> s;
    String lhs, rhs, op, currentToken;
    char token[300];

    while (!in.eof()) {
        in >> token;
        currentToken = String(token);

        if (in.eof()) {
            break;
        }

        if (currentToken == ";") {
            out << s.top();
            out << ";";
            out << std::endl;
            s = stack<String>();
        } else if (currentToken == ")") {
            rhs = s.pop();
            op = s.pop();
            lhs = s.pop();
            s.push(lhs + rhs + op);
        } else {
            if (currentToken != "(") {
                s.push(currentToken + ' ');
            }
        }
    }
}
void toAssembly(std::ifstream& in, std::ostream& out) {
    stack<std::string> s;
    std::string lhs, rhs, op, tempvar, currentToken;
    int tempN = 1;

    while (!in.eof()) {
        if (!in.eof()) {
            currentToken = getToken(in);
        } else {
            break;
        }

        if (currentToken == ";") {
            tempvar = "TMP" + intToString(tempN++);
            out << "   ST    " << tempvar << std::endl; 
            out << "=============================================" << std::endl; 
            tempN = 1;
        }

        if (!in.eof() && currentToken != "+" && currentToken != "-" && currentToken != "*" && currentToken != "/") {
            s.push(currentToken);
        } else if (!in.eof()) {
            rhs = s.pop();
            lhs = s.pop();

            out << "   LD    " << lhs << std::endl;

            op = getOperator(currentToken);
            out << op << rhs << std::endl;
            
            tempvar = "TMP" + intToString(tempN++);
            s.push(tempvar);

            out << "   ST    " << tempvar << std::endl;
        }
    }

   
}



std::string getOperator(const std::string& op)
{
    switch (op[0]) {
        case '+':
            return "   AD\t ";
            break;
        case '-':
            return "   SB\t ";
            break;
        case '*':
            return "   MU\t ";
            break;
        case '/':
            return "   DV\t ";
            break;
        default:
            return "    UNDEF\t";
    }
}

std::string intToString(int x) {
    if (!x) {
        return "0";
    }

    std::string result;

    do {
        result += (x % 10 + 48);
        x /= 10;
    } while (x > 0);

    return result;
}

std::string getToken(std::ifstream& in) {
    std::string result;
    char token = '\0';

    
    while(token != ' ' && !in.eof()) {
        in.get(token);

        if (token == ';') {
            return ";";
        } else if (token != ' ') {
            result += token;
        }
        
    }
    return result;
}

    /*for (int i = 0; token != ' ' && !in.eof(); ++i) {
        in.get(token);

        if (token == ';') {
            return ";";
        } else if (token != ' ') {
            result += token;
        }
    }

    return result;
}
*/