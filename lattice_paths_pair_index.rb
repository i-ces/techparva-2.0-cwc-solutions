# frozen_string_literal: true

# This is the question with a special solution, multi approaches

## Approach 1: Using the recursion

# def calculate_paths(row, col)
#   return 0 if row.zero? || col.zero?
#   return 1 if row == 1 || col == 1

#   calculate_paths(row - 1, col) + calculate_paths(row, col - 1)
# end

## Approach 2: Using the dynamic programming

def calculate_paths(row, col)
  dp = Array.new(row + 1) { Array.new(col + 1, 0) }

  (1..row).each do |i|
    (1..col).each do |j|
      dp[i][j] = calculate_path(dp, i, j)
    end
  end

  dp[row][col]
end

def calculate_path(dpp, row, col)
  return 1 if row == 1 || col == 1

  dpp[row - 1][col] + dpp[row][col - 1]
end

def find_pair_index(input_array)
  value_to_index = {}

  input_array.each_with_index do |row, i|
    row.each_with_index do |number, j|
      return [value_to_index[number], [i, j]] if value_to_index.key?(number)

      value_to_index[number] = [i, j]
    end
  end

  nil
end

# Taking input for the array
puts 'Enter the values for m and n (separated by a space): '
m, n = gets.chomp.split.map(&:to_i)

input_array = []
puts "Enter the array values (#{m} rows x #{n} columns):"
m.times do
  input_array << gets.chomp.split.map(&:to_i)
end

# Finding the single pair index
pair_index = find_pair_index(input_array)

# Calculating the number of paths
row = pair_index[1][0] - pair_index[0][0]
col = pair_index[1][1] - pair_index[0][1]

puts "The number of paths is: #{calculate_paths(row + 1, col + 1)}"
