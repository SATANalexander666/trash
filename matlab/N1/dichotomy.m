function solution = dichotomy (a, b, eps)

while b - a > eps
  c = (a + b) / 2;
  if fun(c) * fun(a) > 0
    a = c;
  else
    b = c;
  end;
endwhile

solution = c;

endfunction