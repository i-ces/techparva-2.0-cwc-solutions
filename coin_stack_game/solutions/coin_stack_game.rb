# frozen_string_literal: true

def calculate_coins_by_sudru(stack_1, stack_2)
  sudru = 0
  seamoon = 0
  turn = 0
  pointer_1 = 0
  pointer_2 = 0

  while pointer_1 < stack_1.length || pointer_2 < stack_2.length
    if pointer_1 == stack_1.length
      if turn.even?
        sudru += stack_2[pointer_2]
      else
        seamoon += stack_2[pointer_2]
      end
      pointer_2 += 1

    elsif pointer_2 == stack_2.length
      if turn.even?
        sudru += stack_1[pointer_1]
      else
        seamoon += stack_1[pointer_1]
      end
      pointer_1 += 1

    elsif turn.even?
      if stack_1[pointer_1] > stack_2[pointer_2]
        sudru +=  stack_1[pointer_1]
        pointer_1 += 1
      else
        sudru += stack_2[pointer_2]
        pointer_2 += 1
      end
    elsif stack_1[pointer_1] > stack_2[pointer_2]
      seamoon += stack_1[pointer_1]
      pointer_1 += 1
    else
      seamoon += stack_2[pointer_2]
      pointer_2 += 1
    end

    turn += 1
  end
  sudru
end

n = gets.to_i

if n.zero?
  puts ''
  exit
end

coin_stack_1 = gets.split.map(&:to_i)

coin_stack_2 = gets.split.map(&:to_i)

result = calculate_coins_by_sudru(coin_stack_1, coin_stack_2)

puts "The total number of coins collected by Sudru: #{result}"
