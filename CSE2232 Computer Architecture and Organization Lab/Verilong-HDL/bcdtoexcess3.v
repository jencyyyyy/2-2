module bcdtoexcess3(a,d);

input [3:0]d;
output [3:0]a;

not nt1(a[0],d[0]);

xnor nr(a[1], d[0],d[1]);

or or1(x1, d[0],d[1]);
xor ar(a[2], x1,d[2]);

and an1(x2,d[0],d[2]);
and an2(x3, d[1],d[2]);
or or2(a[3], d[3],x2,x3);

endmodule

