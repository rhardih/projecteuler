
result = 0
numerator = 3
denominator = 2
num_tmp1 = 1
den_tmp1 = 1

1.upto(1000) do
  num_tmp0 = numerator;
  numerator = 2 * numerator + num_tmp1;
  num_tmp1 = num_tmp0;

  num_magnitude = Math.log10(numerator).floor;

  den_tmp0 = denominator;
  denominator = 2 * denominator + den_tmp1;
  den_tmp1 = den_tmp0;

  den_magnitude = Math.log10(denominator).floor;

  if num_magnitude > den_magnitude
    puts "#{numerator}/#{denominator}"
    result += 1
  end
end


puts "Answer: #{result}"
