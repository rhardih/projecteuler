max_sum = 0

1.upto(99) do |i|
  1.upto(99) do |j|
    product = i**j

    sum = product.to_s.chars.map(&:to_i).inject { |a,b| a + b }

    if sum > max_sum
      max_sum = sum
    end
  end
end

puts max_sum
