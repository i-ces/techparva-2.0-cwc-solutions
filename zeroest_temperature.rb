# frozen_string_literal: true

n = gets.to_i

if n.zero?
  puts 0
  exit
end

# Convert inputs to integers and store in array
inputs = gets.split.map(&:to_i)

# Sort the array of temperatures by absolute value, prioritizing positive values
sorted_temperatures = inputs.sort_by { |t| [t.abs, -t] }

result = sorted_temperatures.first

puts result.nil? ? 0 : result
