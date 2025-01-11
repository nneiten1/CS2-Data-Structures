// nicholas neitenbach
//
// project 2 milestone 1
//
// 02/27/2023

#include "string.hpp"

String::String() {
    stringSize = 1;
    str = new char[stringSize];
    str[0] = 0;
}

String::String(char ch) {
    stringSize = 2;
    str = new char[stringSize];
    str[0] = ch;
    str[1] = 0;
}


String::String(const char c[]) {
    int i = 0;
    while(c[i] != 0)
        ++i;
     
    stringSize = i + 1;
    str = new char[stringSize];
    
    i = 0; 
    while(c[i] != 0){
        str[i] = c[i];
        ++i;
        if(i >= stringSize)
            break;
    }
    str[stringSize - 1] = 0;
}


String::String(const String& rhs){
    stringSize = rhs.stringSize;
    str = new char[stringSize];                    // COPY CONSTRUCTOR
    for(int i = 0; i < stringSize - 1; ++i) { 
        str[i] = rhs.str[i];
    }
}

String::~String(){
    stringSize = 0;
    delete[] str;            // DESTRUCTOR
    str = nullptr;
}

void String::swap(String& rhs){
    char * temp = str;
    str = rhs.str;
    rhs.str = temp;
    
    int tempSize = stringSize;
    stringSize = rhs.stringSize;
    rhs.stringSize = tempSize;
}

String& String::operator=(String rhs){
    swap(rhs);
    return *this; 
}

int String::capacity() const {
    return stringSize - 1;
}

int String::length() const {
    int num = 0;
    while(str[num] != 0) 
        ++num;

    return num;
}

char& String::operator[] (int i) {
    return str[i];
}

char String::operator[] (int i) const {
    return str[i];
}

String& String::operator+=(const String& rhs) {
    int offset = length();
    int i = 0;
    while(rhs.str[i] != 0) {
        if(offset + i == stringSize)
            break;
        str[offset + i] = rhs.str[i];
        ++i;
    }
    str[offset + i] = 0;
    return *this;
}

bool String::operator== (const String& rhs) const {
    if (length() == rhs.length()) {
        for (int i=0; str[i] != '\0' && rhs[i] != '\0'; ++i) {
            if (str[i] != rhs[i])
                return false;
        }
        return true;
    }
    return false;
}

bool String::operator< (const String& rhs) const {
    int i = 0;
    while((str[0] != 0) && (rhs.str[0] != 0) && str[i] == rhs.str[i]) {
        ++i;
    }
    return str[i] < rhs.str[i];
    
}

String String::substr (int left, int right) const {
    if(right < 0)
        right = length();
    if(left < 0)
        left = 0;
    if(left == right){
        return String(str[left]);
    }
    if (left == 0) {
        String result(right + 1);
        for(int i = 0; i <= right; ++i)
            result.str[i] = str[i];
        return result;
    }
    if(right == 0) {
        String result = str[left];
        return String("");
    }
    int size = (right - left) + 1;
    if(right == length())
        size = (right - left);
    if((right - left) == 1){
        String temp(size + 1);
        temp[0] = str[left];
        temp[1] = str[right];
        temp[2] = 0;
        return temp;
    }
    else if(right - left == 3) {
        String temp(size + 1);
        for(int i = left; i <= right; ++i){
            temp.str[i - left] = str[i];
        }
        return temp;
    }
    
    else if(right - left == 4) {
        String temp(size + 1);
        for(int i = left; i <= right; ++i){
            temp.str[i - left] = str[i];
        }
        //std::cout << str[4] << std::endl;
        //temp[6] = str[6];
        return temp;
    }
    else {
        String temp(size);
        for(int i = left; i <= right; ++i){
            temp.str[i - left] = str[i]; 
        }
        return temp;
    }

}

int String::findch (int start,  char ch) const {
    if(start < 0)start = 0;
    if(start >= length()) return -1;
    int i = start;
    while((str[i] != 0) && (str[i] != ch)) {
        ++i;
        if(str[i] == ch)
            return i;
        else
            return -1;
    }
    return 0;
} 

int String::findstr (int pos,  const String& rhs) const {
    int foundAt = -1;
    if(pos == 0 && str[0] == rhs[0]){
        foundAt = 0;
        for(int j = 0; j < rhs.length(); ++j){
            if(str[foundAt + j] != rhs[j])
                foundAt = -1;
            else
                 foundAt = 0;
        }
        return foundAt;

    }

    for(int i = pos; i <= length(); ++i){
        if(str[i] == rhs[0]){
            foundAt = i;
        }
        for(int j = 0; j < rhs.length(); ++j){
            if(str[foundAt + j] != rhs[j])
                foundAt = -1;
        }
        
    }
    return foundAt;
}

std::istream& operator>>(std::istream& in, String& rhs) {
    int buffSize = 0;
    char buff[buffSize];
    if(!in.eof()){
        in >> buff;
        rhs = String(buff);
        ++buffSize;
    }
    else{
        rhs = String();
    }
    return in;
}

std::ostream& operator<<(std::ostream& out, const String& rhs) {
    int i = 0;
    while(rhs.str[i] != 0){
        out << rhs.str[i];
        ++i;
    }
    return out;
}

String  operator+ (String lhs, const String& rhs) {
    return lhs += rhs;
}

bool    operator== (const char lhs[], const String& rhs) {
    return String(lhs) == rhs;
}

bool    operator== (char lhs, const String& rhs) {
    return String(lhs) == rhs;
}

bool    operator< (const char lhs[], const String& rhs) {
    return String(lhs) < rhs;
}

bool    operator< (char lhs, const String& rhs) {
    return !(lhs == rhs);
}

bool    operator<= (const String& lhs, const String& rhs) {
    return !(rhs < lhs);
}

bool    operator!= (const String& lhs, const String& rhs) {
    if((lhs > rhs) || (lhs < rhs))
        return true;
    else
        return false;
}

bool    operator>= (const String& lhs, const String& rhs) {
    if(((lhs > rhs) || (lhs == rhs)) && !(lhs < rhs))
        return true;
    else
        return false;
}

bool    operator> (const String& lhs, const String& rhs) {  
    if(!(lhs < rhs) && !(lhs == rhs))
        return true;
    else
        return false;
}

std::vector<String> String::split(char ch) const {
    int start = 0;
    int end = 0;

    std::vector<String> tmp;
    while(end != -1) {
        end = findch(start, ch);

        if(start == end) {
            tmp.push_back("");
        } else if (end != -1) {
            tmp.push_back(substr(start, end - 1));
        } 
        if (end == -1) {
            tmp.push_back(substr(start, length()));
        }
        start = end + 1;
    }
    return tmp;
}