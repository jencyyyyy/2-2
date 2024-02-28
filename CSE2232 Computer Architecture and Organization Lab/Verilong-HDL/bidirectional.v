module bidirectional(q,clr,clk,mode);

input clr,clk;
input mode;
output [2:0]q;

wire [2:0]qbar;

assign j=1;
assign k=1;

not nt(modebar,mode);

jkff jk1(q[0],qbar[0],j,k,clr,clk);

and an1(x1,modebar,q[0]);
and an2(x2,mode,qbar[0]);
or or1(s1,x1,x2);

jkff jk2(q[1],qbar[1],s1,s1,clr,clk);

and an3(y1,x1,q[1]);
and an4(y2,x2,qbar[1]);
or or2(s2,y1,y2);

jkff jk3(q[2],qbar[2],s2,s2,clr,clk);

endmodule