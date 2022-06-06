function g = newton (a, eps)
  
x0 = a;  
dx = 100;
 
  while(dx > eps)
    x1 = x0 - fp1(x0) ./ fp2(x0);
    dx = abs(x1 - x0);
    x0 = x1;  
  endwhile
if (fp2(x1) < 0)
  g = x1;
else
  g = 0;
endif

endfunction
