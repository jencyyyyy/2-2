module excess3tobcd(b,e);

input [3:0]e;
output [3:0]b;

not nt1(b[0],e[0]);

xor xr1(b[1],e[0],e[1]);

not nt2(x1, e[1]);
not nt3(x2,e[0]);
or or1(s1,x1,x2);
xor xr2(b[2],e[2],s1);

and an1(x3,e[0],e[1]);
or or2(s2,e[2],x3);
and an2(b[3], s2,e[3]);

endmodule