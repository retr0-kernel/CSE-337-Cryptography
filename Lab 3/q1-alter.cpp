#include <bits/stdc++.h>
using namespace std;

int no_of_spaces(string C)
{
    int cnt = 0;
    for (int i = 0; i < C.size(); i++)
        if (C[i] == ' ')
            cnt++;
    return cnt;
}

int Procedure_for_key_length(string C)
{
    int t = 0;
    float min_len = INT_MAX;
    for (int i = 1; i <= C.size(); i++)
    {
        vector<float> freq(26, 0);
        float sum = 0.0;
        for (int j = 0; j < C.size() && j + i < C.size(); j++)
            if (C[j] != ' ')
                freq[C[j + i] - 'A']++;

        for (int l = 0; l < freq.size(); l++)
            freq[l] = freq[l] / i;

        for (int k = 0; k < freq.size(); k++)
            sum += (freq[k] * freq[k]);

        if (abs(sum - 0.065) < min_len)
        {
            t = i;
            min_len = abs(sum - 0.065);
            // cout<<sum<<" ";
        }
    }
    return t - no_of_spaces(C);
}

int main()
{
    string str = "ULE PSO ENG LII WREBR RHLSMEWE XHH DFXTHJ GVOP LII PRKU SFIADI";
    cout << "The length of key is : " << Procedure_for_key_length(str);

    return 0;
}