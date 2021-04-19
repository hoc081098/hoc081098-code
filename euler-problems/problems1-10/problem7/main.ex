defmodule Problem7 do
  # By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
  # What is the 10 001st prime number?
  # Result: 104743

  require Float

  def divisible_by_any(n, list) do
    list |> Enum.any?(&(rem(n, &1) == 0))
  end

  def solve2 do
    n = 10001

    Stream.iterate(1, &(&1 + 2))
    |> Stream.scan([2], fn
      e, acc when e <= 2 -> acc
      e, acc -> if divisible_by_any(e, acc), do: acc, else: [e | acc]
    end)
    |> Stream.map(&List.first/1)
    |> Stream.dedup()
    |> Stream.take(n)
    |> Enum.at(-1)
  end

  def is_prime(n), do: !divisible_by_any(n, 2..(:math.sqrt(n) |> Float.floor() |> round()))

  def solve1 do
    n = 10001

    Stream.concat(
      [2, 3],
      Stream.iterate(5, &(&1 + 1))
      |> Stream.filter(&is_prime/1)
    )
    |> Stream.take(n)
    |> Enum.at(-1)
  end

  def main do
    IO.puts(solve1())
    IO.puts(solve2())
  end
end
