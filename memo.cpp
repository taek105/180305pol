#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

// int solution(string s) {
//     int answer = s.length();
//     int cnt = 2;
//     string a, b;
//     vector<char> c;
//     if ( answer == 1 ) return 1;

//     for ( int i = 1; i <= s.length()/2; i ++ )
//     {
//         for ( int j = 0; j < s.length() && j+i < s.length(); j+=i )
//         {
//             a = s.substr(j, i), b = s.substr(j+i, i);
            
//             if ( a == b && j+i < s.length() ) 
//             {
//                 answer -= i-1, j += i;
//                 b = s.substr(j+i, i);
//             }
//             while ( a == b && j+i < s.length() )
//             {
//                 cnt ++;
//                 cout << cnt << endl;
//                 answer -= i, j += i;
//                 b = s.substr(j+i, i);
//             }
//             answer += to_string(cnt).length()-1;
//             cout << i << " / " << answer << endl;
//             cnt = 2;
//         }
//         c.push_back(answer);
//         answer = s.length();
//     }
//     return *min_element(c.begin(), c.end());
// }
vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size(), -1);
    stack<pair<int, int>> st;
    
    for (int i = 0; i < numbers.size()-1; i++)
    {
        while (!st.empty())
        {
            pair<int, int> top = st.top();
            
            if (top.first >= numbers[i])
            {
                break;
            }
            
            answer[top.second] = numbers[i];
            st.pop();
        }
        
        st.push({ numbers[i], i });
    }
    
    return answer;
}

int main()
{
    vector<int> v(8, 0);
    v[0] = 1; v[1] = 3; v[2] = 2; v[3] = 5; v[4] = 4; v[5] = 5; v[6] = 2; v[7] = 3;

    // cout << solution("ababcdcdabababcd") << endl;
    // cout << solution("abcabcabcabcdededededede");
    for ( auto a : solution(v))
        cout << a << " ";
    
}