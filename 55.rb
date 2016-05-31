def palindrome?(i)
  i.to_s.reverse == i.to_s
end

def lychrel?(i)
  tmp = i

  1.upto(50) do
    revi = tmp.to_s.reverse.to_i
    sum = tmp + revi

    #puts "#{tmp} + #{revi} = #{sum}"

    if palindrome?(sum)
      return false
    else
      tmp = sum
    end
  end

  true
end

result = 0

1.upto(9999) do |i|
  if lychrel?(i)
    result += 1
  end
end

puts result
