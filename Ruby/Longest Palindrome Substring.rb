# @param {String} s
# @return {String}
def longest_palindrome(s)
  @lo = 0
  @max_len = 0

  return s if s.size < 2

  (0..s.size - 1).each do |i|
    extend_pal(s, i, i)
    extend_pal(s, i, i + 1)
  end

  s[@lo..@lo + @max_len - 1]
end

def extend_pal(s, left, right)
  while left >= 0 && right < s.size && s[left] == s[right]
    left -= 1
    right += 1
  end

  if @max_len < right - left - 1
    @lo = left + 1
    @max_len = right - left - 1
  end
end

# https://leetcode.com/problems/longest-palindromic-substring/
# shellpy03
