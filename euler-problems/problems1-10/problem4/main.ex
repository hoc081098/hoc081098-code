defmodule Problem4 do
  # A palindromic number reads the same both ways.
  # The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
  # Find the largest palindrome made from the product of two 3-digit numbers.
  # Result: 906609

  def is_palindromic(n) do
    s = Integer.to_string(n)
    s == String.reverse(s)
  end

  def solve do
    100..999
    |> Enum.flat_map(fn i ->
      100..999 |> Enum.map(&(i * &1))
    end)
    |> Enum.filter(&is_palindromic/1)
    |> Enum.max()
  end

  def main do
    IO.puts(solve())
  end
end
