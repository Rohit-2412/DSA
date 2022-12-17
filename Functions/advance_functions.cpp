#include <bits/stdc++.h>
using namespace std;
// 1. sum of first n natural numbers
// 2. checking for pythagorian triplets
// 3. decimal to binary
// 4. decimal to octal
// 5. decimal to hexadecimal
// 6. binary to decimal
// 7. octal to decimal
// 8. hexadecimal to decimal
// 9. binary number addition
int sumOfNaturalNumbers(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += i;
    }
    return sum;
}

bool check(int x, int y, int z)
{
    int a, b, c;
    a = max(x, max(y, z));
    if (a == x)
    {
        b = y;
        c = z;
    }
    else if (a == y)
    {
        b = x;
        c = z;
    }
    else if (a == z)
    {
        b = y;
        c = x;
    }

    if (a * a == b * b + c * c)
    {
        return true;
    }
    else
        return false;
}

int binaryToDecimal(int n)
{
    int ans = 0;
    int x = 1;
    while (n > 0)
    {
        int y = n % 10; // getting last digit
        ans += x * y;   // adding ans
        x *= 2;
        n /= 10;
    }
    return ans;
}

int octalToDecimal(int n)
{
    int ans = 0;
    int x = 1;
    while (n > 0)
    {
        int y = n % 10;
        ans += x * y;
        x *= 8;
        n /= 10;
    }
    return ans;
}

int hexadecimalToDecimal(string n)
{
    int ans = 0;
    int x = 1;
    int length = n.size();
    for (int i = length - 1; i >= 0; i--)
    {
        if (n[i] >= '0' && n[i] <= '9')
        {
            ans += x * (n[i] - '0');
        }
        else if (n[i] >= 'A' && n[i] <= 'F')
        {
            ans += x * (n[i] - 'A' + 10);
        }
        x *= 16;
    }

    return ans;
}

int decimalToBinary(int n)
{
    int ans = 0;
    int x = 1;
    while (x <= n)
        x *= 2; // gives a number(i.e. power of 2 greater than number)
    x /= 2;     // dividing by 2 to get the smallest like for n=11 we need x=8
    while (x > 0)
    {
        int lastDigit = n / x; //
        n -= lastDigit * x;
        x /= 2;
        ans = ans * 10 + lastDigit;
    }
    return ans;
}

int decimalToOctal(int n)
{
    int ans = 0;
    int x = 1;
    while (x <= n)
        x *= 8; // gives a number(i.e. power of 2 greater than number)
    x /= 8;     // dividing by 2 to get the smallest like for n=11 we need x=8
    while (x > 0)
    {
        int lastDigit = n / x; //
        n -= lastDigit * x;
        x /= 8;
        ans = ans * 10 + lastDigit;
    }
    return ans;
}

string decimalToHexadecimal(int n)
{
    string ans = "";
    int x = 1;
    while (x <= n)
    {
        x *= 16;
    }
    x /= 16;
    while (x > 0)
    {
        int lastDigit = n / x;
        n -= lastDigit * x;
        x /= 16;
        if (lastDigit <= 9)
        {
            ans += to_string(lastDigit);
        }
        else
        {
            char c = 'A' + lastDigit - 10;
            ans.push_back(c);
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    // cout << sumOfNaturalNumbers(n)<< endl;
    // pyth triplet
    // int x, y, z;
    // cin >> x >> y >> z;
    // if (check(x, y, z))
    // {
    //     cout << "Pythagorian Triplet" << endl;
    // }
    // else
    //     cout << "Not Pythagorian triplet" << endl;
    // dec to binary
    // cout << decimalToHexadecimal(n) << endl;
    cout << binaryToDecimal(n) << endl;
    return 0;
}