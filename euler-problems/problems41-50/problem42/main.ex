defmodule Problem do
  # The nth term of the sequence of triangle numbers is given by, tn = ½n(n+1); so the first ten triangle numbers are:
  # 1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...
  # By converting each letter in a word to a number corresponding to its alphabetical position and adding these values we form a word value. For example, the word value for SKY is 19 + 11 + 25 = 55 = t10. If the word value is a triangle number then we shall call the word a triangle word.
  # Using words.txt (right click and 'Save Link/Target As...'), a 16K text file containing nearly two-thousand common English words, how many are triangle words?
  # Result: 162

  def read_file do
    Path.expand("./lib/p042_words.txt")
    |> File.read!()
    |> String.split(~r/\W+/)
  end

  def word_value(s) do
    String.to_charlist(s)
    |> Enum.map(&(&1 - 64))
    |> Enum.sum()
  end

  def is_triangle_word(s) do
    value = word_value(s)
    Stream.iterate(1, &(&1 + 1))
    |> Stream.take_while(fn i -> i * (i + 1) <= 2 * value end)
    |> Enum.any?(fn i -> i * (i + 1) == 2 * value end)
  end

  def solve do
    read_file() |> Enum.count(&is_triangle_word/1)
  end

  def main do
    IO.puts(solve())
  end
end
