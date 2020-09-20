deff('f = func1(x,y)','f = 2 + sqrt(-(x-2)^2+1)');
deff('g = func2(x,y)','g = 2 - sqrt(-(x-2)^2+1)');
deff('h = func3(x,y)','h = 3 * x - 3');
deff('a = func4(x,y)','a = -3 * x + 9');
deff('j = func5(x,y)','j = 0.2*x+1.7');

a = 1,0,1,4;
clf;
xgrid(1);
plot(x,func1,x,func2,x,func3,x,func4,x,func5);
xtitle("Мама анархия,папа стакан потрвейна",'x','y');
legend('f(x) = 2 + sqrt(-(x-2)^2+1)','g(x) = 2 - sqrt(-(x-2)^2+1)','h(x) = 3 * x - 3','a(x) = -3 * x + 9','j(x) = 0.2*x+1.7')
2