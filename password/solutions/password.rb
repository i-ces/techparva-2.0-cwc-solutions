# frozen_string_literal: true

def decipher(strings)
  result = ''

  strings.each do |str|
    mid = str.length / 2

    first_half = str[0...mid].chars.to_set
    second_half = str[mid..].chars.to_set

    intersection = first_half & second_half

    next if intersection.empty?

    result += intersection.to_a[0]
  end

  result
end

def main
  n = gets.to_i

  strings = []
  n.times { strings << gets.chomp }

  puts decipher(strings)
end

main
