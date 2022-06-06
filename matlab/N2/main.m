a = -0.8
b = 6.6
delt = 0.1

%result = dichotomy(a, b, eps)

x = a : pi / 500 : b;
y = (x .* x) .* sin(5*x) - 0.7;

plot(x, y);

i = a;
while i + delt < b
  x0 = fzero('fun', i);
  if (x0 > a && x0 < b)
    plot(x,y);  
    hold on; 
    plot(x0,0,'r*');
  endif
  
  i = i + delt;
endwhile