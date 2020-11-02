a1=[1 2 3 4;4 3 2 1;1 2 3 4;4 3 2 1]; 
disp(a1,"Произвольная A=")
c  = mean(a1)
a1 = a1./c; 
disp(a1,"Матрица A после преобразований");

a = [1 -2 1 ;-0.5 1 5;-1 2 3];
b = [2 0.5 2;1 0 -1;1 -2 1];
var1 = inv(b);
var2 = det(b);
c = 3*a*(a-b)+var2*(a+3*var1);
disp(c,"Результатная матрица C=");

/*
deff('y=f(x)','y=2*x^3 - 7*x');
x0=1;
z=numderivative(f, x0);
mprintf("Значение производной в точке x0: %f ",z);
b=f(x0)-z*x0;
deff('g=kas(x)', 'g=z*x+b');
xgraph=-7:0.1:1;
fgraph=f(xgraph);
kasgraph=kas(xgraph);
plot(xgraph,fgraph,xgraph,kasgraph);
xgrid(100);
legend ("y=f(x)", "y=z(x, x0)");
*/