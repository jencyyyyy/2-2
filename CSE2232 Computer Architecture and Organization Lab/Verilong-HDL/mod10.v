module mod10(q,clr,clk);

input clr,clk;
output [3:0]q;

wire j,k;
wire [3:0]qbar;

assign j=1;
assign k=1;

jkff jk1(q[0],qbar[0],j,k,clr,clk);
jkff jk2(q[1],qbar[1],j,k,clr,q[0]);
jkff jk3(q[2],qbar[2],j,k,clr,q[1]);
jkff jk4(q[3],qbar[3],j,k,clr,q[2]);

nand nd(clr,q[1],q[3]);

endmodule