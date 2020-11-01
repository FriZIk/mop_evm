/*x =-2:0.1:2 
disp(x,'x=');

deff('y = myfunc(a)','y = x^4+2*x');
op = myfunc(x);
disp(op);
plot(x,op);
*/

clear
clf

x=-2*%pi:0.01:2*%pi;
f1=sin(x);
f2=cos(x);
f3= x^2/20-1;
xgrid(1), 
plot(x,f1,x,f2,x,f3)
xtitle("съела","моча","говно")

legend('y1(x)=вот','y2(x)=это', 'y3(x)=прикол',1)
