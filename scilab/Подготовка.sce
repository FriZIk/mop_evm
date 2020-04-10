// y(x) = sin(x),y(x) = 2x + 3;
// sin(x) = 2x + 3; => sin(x) - 2x - 6 = 0
x = 1:0.1:10;
plot(x,sin(x),x,-2*x+6);
x0 = 2.865
deff('y = f(x)','y = sin(x) + 2*x - 6');
res = fsolve(x0,f);
disp(res,"Корни трансцендетного уравнения:");


// Решение полиномиального уравнения
/*p = poly([1,-2 ,1],'x','c');
disp(p);
res = root s(p)
disp(res,"Корни полинома:");*/


// Численное дифференцирование
 
/*deff('y = f1(x)','y = sin(x)');
x1 = 1:0.01:10;
y1 = f1(x1);

x0 = 2;
k = numderivative(f1,x0);
printf("Производная в точке x0 = %f равна:%f",x0,k);

b = f1(x0) - x0*k;
deff('y = f2(x)','y = k*x + b');

y2 = f2(x1);
plot(x1,y1,x1,y2);
xgrid(100);
legend("y1(x) = sin(x)","y2(x) = kx + b");
*/
