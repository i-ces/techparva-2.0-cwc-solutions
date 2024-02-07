# frozen_string_literal: true

# Function to calculate the total number of times the stamp was dipped in the ink
def calculate_dip_count(stamp_times, ink_duration)
  dip_count = 0
  current_dip_time = 0

  stamp_times.each do |stamp_time|
    if stamp_time.zero? || stamp_time > current_dip_time
      dip_count += 1
      current_dip_time = stamp_time + ink_duration
    end
  end

  dip_count
end

# Input: Number of stamps, Stamp times, and Ink duration
puts 'Enter the number of stamps:'
n = gets.to_i

if n.zero?
  puts 0
  exit
end

puts 'Enter the stamp times (sorted, space-separated):'
stamp_times = gets.split.map(&:to_i)

puts 'Enter the ink duration:'
ink_duration = gets.to_i

if ink_duration.zero?
  puts n
  exit
end

# Calculate and output the dip count
result = calculate_dip_count(stamp_times, ink_duration)
puts "The total number of times the stamp was dipped in the ink: #{result}"
