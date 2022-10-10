# @Sk70249 solution in Python
'''
Example 1:
Input: s = "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.
Example 2:
Input: s = "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
'''
class Solution:
    def romanToInt(self, s: str) -> int:
        roman = {

            "I": 1,
            "V": 5,
            "X": 10,
            "L": 50,
            "C": 100,
            "D": 500,
            "M": 1000,
        }
        num = 0

        val = [roman[i] for i in s if i in roman.keys()]

        for i in range(len(val) - 1):
            if val[i] < val[i + 1]:
                num -= val[i]
            else:
                num += val[i]

        return num + val[-1]
Footer
