defmodule Problem21 do
  # Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
  # If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b are called amicable numbers.
  # For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.
  # Evaluate the sum of all the amicable numbers under 10000.
  # Result: 31626

  def d(n) do
    cond do
      n <= 1 -> 0
      true -> 1..(n - 1) |> Enum.filter(&(rem(n, &1) == 0)) |> Enum.sum()
    end
  end

  def solve do
    1..(10_000 - 1)
    |> Enum.filter(fn b ->
      a = d(b)
      d(a) == b && a != b
    end)
    |> Enum.sum()
  end

  def main do
    IO.puts(solve())
  end
end
