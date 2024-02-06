# frozen_string_literal: true

def max_consec(array)
  current_team = nil
  max_team = nil
  max_count = 0
  current_count = 0

  array.each do |team|
    if team == current_team
      current_count += 1
    else
      if current_count > max_count
        max_count = current_count
        max_team = current_team
      end
      current_team = team
      current_count = 1
    end
  end

  if current_count > max_count
    max_count = current_count
    max_team = current_team
  end

  return ['', 0] if max_count == 1

  [max_team, max_count]
end

size = gets.to_i

if size.zero?
  puts ''
  puts 0
elsif size == 1
  array = gets.chomp.split
  puts array[0]
else
  array = gets.chomp.split
  puts max_consec(array)
end
