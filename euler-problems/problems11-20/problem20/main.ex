defmodule Problem20 do
  # n! means n × (n − 1) × ... × 3 × 2 × 1
  # For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
  # and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.
  # Find the sum of the digits in the number 100!
  # Result: 648

  def solve do
    1..100 |> Enum.reduce(&(&1 * &2)) |> Integer.digits() |> Enum.sum()
  end

  def main do
    IO.puts(solve())
  end
end
