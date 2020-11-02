deff('c=fun(x,y)','c=sqrt(abs(cos(y/x)))+log10(exp(y^x))'); // определим функцию fun(x,y)
a = -4.5; b = 8.09; 
c = fun(a,b) 
mprintf('fun( %f %f) = %f',a,b,c)
