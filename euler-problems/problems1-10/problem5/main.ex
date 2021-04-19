defmodule Problem5 do
  # 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
  # What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
  # Result: 232792560

  require Integer

  def lcm(a, b), do: a * div(b, Integer.gcd(a, b))

  def solve do
    1..20 |> Enum.reduce(&lcm/2)
  end

  def main do
    IO.puts(solve())
  end
end
