defmodule Problem9 do
  # A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
  # a^2 + b^2 = c^2
  #
  # For example, 32 + 42 = 9 + 16 = 25 = 52.
  # There exists exactly one Pythagorean triplet for which a + b + c = 1000.
  # Find the product abc.
  # Result: 31875000

  def solve do
    for(
      i <- 1..999,
      do:
        for(
          j <- 1..999,
          i * i + j * j == (1000 - i - j) * (1000 - i - j),
          do: i * j * (1000 - i - j)
        )
    )
    |> Enum.reject(&Enum.empty?/1)
    |> Enum.at(0)
    |> Enum.at(0)
  end

  def main do
    IO.puts(solve())
  end
end
