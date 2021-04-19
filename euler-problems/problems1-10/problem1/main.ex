defmodule Problem1 do
  # If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9.
  # The sum of these multiples is 23.
  # Find the sum of all the multiples of 3 or 5 below 1000.
  # Result: 233168

  def solve1 do
    0..999
    |> Enum.filter(fn i -> rem(i, 3) == 0 || rem(i, 5) == 0 end)
    |> Enum.sum()
  end

  def solve2 do
    # sum_3or5(n) = sum_3(n) + sum_5(n) - sum_15(n)
    # sum_k(n) = sum (ik), i in 0 to (n - 1) / k

    sum = fn k, n ->
      0..div(n - 1, k)
      |> Enum.map(fn i -> i * k end)
      |> Enum.sum()
    end

    sum.(5, 1000) + sum.(3, 1000) - sum.(15, 1000)
  end

  def main do
    IO.puts(solve1())
    IO.puts(solve2())
  end
end
