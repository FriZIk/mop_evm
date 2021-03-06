/* Полином 
// y(x) = x^2 - 2x + 1 = (x - 1)^2s
// 1 2 1 
a = poly([1,-2,1],'x','c');
disp(a,'Полином:');
b = roots(a);
disp(b,'Корни уравнения:');
*/


/*
// Трансцендентное уравнение
// y(x) = sin(x)  y(x) = -2x + 4
x = 1:0.01:10;
plot(x,sin(x),x,-2*x+4);
xgrid(100)
// sin(x) = -2x+4 => sin(x) + 2x - 4 = 0
a = 1.5; // Приближенное значение
deff("y = f(x)","y = sin(x) + 2*x -4"); 
b = fsolve(a,f);
disp(b,'Корни уравнения:');
*/

// Дифференцирование

deff('y = f(x)','y = 2*cos(x)');
x = 2:0.01:20;

x0 = 5;
k = numderivative(f, x0);
printf('Производная в точке x0 = %f равна:%f',x0,k);
b = f(x0) - k*x0;
deff('y = f1(x)','y = k*x + b');
plot(x,f(x),x,f1(x));
xgrid(100);
xtitle("Постороение косательной к графику функции, дифференцирование");
legend('f(x) = 2 * cos(x)','f1(x) = k*x + b');
