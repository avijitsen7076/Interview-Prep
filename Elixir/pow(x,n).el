defmodule Solution do
  import Integer, only: [is_odd: 1]
  import Bitwise, only: [">>>": 2]

  @spec my_pow(x :: float, n :: integer) :: float
  def my_pow(x, n), do: my_pow(x, n, 1)

  # x ^ 0
  defp my_pow(_, 0, acc), do: acc
  
  # 0 ^ n
  defp my_pow(0, _, _), do: 0
  
  # negative n
  defp my_pow(x, n, acc) when n < 0 do
    my_pow(1 / x, -n, acc)
  end
  
  # positive odd n
  defp my_pow(x, n, acc) when is_odd(n) do
    my_pow(x, n - 1, x * acc)                        
  end
   
  # positive even n
  defp my_pow(x, n, acc) do
    my_pow(x * x, n >>> 1, acc)
  end
end
