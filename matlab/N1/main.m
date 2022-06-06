a = -0.1
b = 10.8
eps = 0.0000001

%result = dichotomy(a, b, eps)

x = a : pi / 500 : b;
y = 3.6 .* (sin(x) ./ (x + 4.1)) - 0.15;

plot(x, y)

%Построили график функции, увидели периодичность
%Пускаем дихотомию по отрезкам длиной pi / 2.

j = a;
i = 0;
while i + pi/2 <= b
  i = i + pi/2;
  res = dichotomy(j, i, eps);
  plot(x, y);  
  hold on; 
  plot(res, 0 ,'r*');
  
  disp(res);
  disp(fun(res));
  j = i;
endwhile

