#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
double calculateSumOfSquares(const std::vector<int> &freq)
{
    double sum = 0.0;
    for (int f : freq)
    {
        sum += f * f;
    }
    return sum;
}
int main()
{
    std::string ciphertext = "ULEPSOENGLIIWREBRRHLSMEWEXHHDFXTHJGVOPLIIPRKUSFIADI";
    int bestKeyLength = 0;
    double closestSumOfSquares = 1000.0;
    for (int keyLength = 1; keyLength <= 10; ++keyLength)
    {
        std::vector<int> freq(26, 0);
        for (int i = 0; i < ciphertext.length(); ++i)
        {
            if (i % keyLength == 0)
            {
                char c = ciphertext[i];
                if (isalpha(c))
                {
                    int index = tolower(c) - 'a';
                    freq[index]++;
                }
            }
        }
        double sumOfSquares = calculateSumOfSquares(freq);
        if (std::fabs(sumOfSquares - 0.065) < std::fabs(closestSumOfSquares - 0.065))
        {
            closestSumOfSquares = sumOfSquares;
            bestKeyLength = keyLength;
        }
    }
    std::cout << "Potential key length found: " << bestKeyLength << std::endl;
    return 0;
}