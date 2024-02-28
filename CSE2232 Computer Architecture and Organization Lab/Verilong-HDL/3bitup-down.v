module threebitupdown(q,mode,clr,clk);

input clr,clk;
input mode;

output [2:0]q;

wire [2:0]qbar;

assign j=1;
assign k=1;

not nt(modebar, mode);

jkff jk1(q[0],qbar[0],j,k,clr,clk);

and an1(a,modebar,q[0]);
and an2(b,mode,qbar[0]);
or or1(x1,a,b);

jkff jk2(q[1],qbar[1],x1,x1,clr,clk);

and an3(c,a,q[1]);
and an4(d,b,qbar[1]);
or or2(x2,c,d);

jkff jk3(q[2],qbar[2],x2,x2,clr,clk);

endmodule
