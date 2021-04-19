defmodule Problem3 do
  # The prime factors of 13195 are 5, 7, 13 and 29.
  # What is the largest prime factor of the number 600851475143 ?
  # Result: 6857

  def helper(n, i) when n <= 1, do: i

  def helper(n, i) when rem(n, i) != 0, do: helper(n, i + 1)

  def helper(n, i), do: helper(div(n, i), i)

  def solve do
    n = 600_851_475_143
    helper(n, 2)
  end

  def main do
    IO.puts(solve())
  end
end
