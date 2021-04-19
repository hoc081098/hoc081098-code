defmodule Problem6 do
  # The sum of the squares of the first ten natural numbers is,
  # 1^2 + 2^2 + ... + 10^2 = 385
  # The square of the sum of the first ten natural numbers is,
  # (1 + 2 + ... + 10)^2 = 552 = 3025
  # Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640.
  # Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
  # Result: 25164150

  require Integer
  use Bitwise

  def solve1 do
    f1 = fn n ->
      1..n |> Enum.map(&(&1 * &1)) |> Enum.sum()
    end

    f2 = fn n ->
      s = 1..n |> Enum.sum()
      s * s
    end

    abs(f1.(100) - f2.(100))
  end

  def solve2 do
    f1 = fn n ->
      s = (n * (n + 1)) >>> 1
      s * s
    end

    f2 = fn n -> div(n * (n + 1) * (2 * n + 1), 6) end

    abs(f1.(100) - f2.(100))
  end

  def main do
    IO.puts(solve1())
    IO.puts(solve2())
  end
end
