# frozen_string_literal: true

def calculate_max_coins(board)
  row = board.length
  col = board[0].length

  dp = Array.new(row + 1) { Array.new(col + 1, 0) }

  (1..row).each do |i|
    (1..col).each do |j|
      dp[i][j] = calculate_coins(dp, i, j, board)
    end
  end

  dp[row][col]
end

def calculate_coins(dpp, row, col, board)
  return 0 if row <= 0 || col <= 0

  coins_on_cell = board[row - 1][col - 1]
  [dpp[row - 1][col], dpp[row][col - 1]].max + coins_on_cell
end

# Taking input for the board
puts 'Enter the number of rows and columns (separated by a space): '
rows, cols = gets.chomp.split.map(&:to_i)

board = []
puts "Enter the board values (#{rows} rows x #{cols} columns):"
rows.times do
  board << gets.chomp.split.map(&:to_i)
end

# Finding the maximum number of coins in any one path
max_coins = calculate_max_coins(board)

puts "The maximum number of coins in any one path is: #{max_coins}"
