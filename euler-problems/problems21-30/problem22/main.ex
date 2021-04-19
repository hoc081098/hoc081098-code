defmodule Problem22 do
  # Using names.txt (right click and 'Save Link/Target As...'), 
  # a 46K text file containing over five-thousand first names,
  # begin by sorting it into alphabetical order. 
  # Then working out the alphabetical value for each name, multiply this value by its alphabetical position in the list to obtain a name score.
  # For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain a score of 938 × 53 = 49714.
  # What is the total of all the name scores in the file?
  # Result: 871198282

  def read_file do
    Path.expand("./lib/p022_names.txt") |> File.read!()
  end

  def val(s) do
    String.to_charlist(s) |> Enum.map(&(&1 - 64)) |> Enum.sum()
  end

  def solve do
    read_file()
    |> String.split(~r/\W+/, trim: true)
    |> Enum.sort()
    |> Enum.with_index()
    |> Enum.map(fn {e, index} -> val(e) * (index + 1) end)
    |> Enum.sum()
  end

  def main do
    IO.puts(solve())
  end
end
