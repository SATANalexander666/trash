a = 0.8
b = 5.1
eps = pi/500

x = a : eps : b;
y = (cos(2.3 * x) ./ (x .* x) + 0.2) + 3.6;
%plot(x, y);

[x1, y1] = fminbnd(@fun, a, 2)%minimum 1
[x2, y2] = fminbnd(@neg_fun, 2, 3);%min of negative = max
x2
y2 = -y2
[x3, y3] = fminbnd(@fun, 3, b)%minimum 2
maximum = newton(2, eps)
y_maximum = fun(maximum)

yp = fp1(x);
yp2 = fp2(x);
plot(x,y);  
hold on; 
%plot(x, yp2);
%plot(x, yp);
plot(x1,y1,'b*');
plot(x2,y2,'r*');
plot(x3,y3,'b*');
plot(maximum, y_maximum, 'g+');
hold off;
