class Solution {
public:
    bool isValid(string s) {
        
    stack<char> x;
    char a;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            x.push(s[i]);
            continue;
        }
 
        if (x.empty())
            return false;
 
        switch (s[i]) {
        case ')':
            a = x.top();
            x.pop();
            if (a == '{' || a == '[')
                return false;
            break;
 
            case '}':
            a = x.top();
            x.pop();
            if (a == '(' || a == '[')
                return false;
            break;
 
        case ']':
            a = x.top();
            x.pop();
            if (a == '(' || a == '{')
                return false;
            break;
        }
    }
    return (x.empty());
    }
};