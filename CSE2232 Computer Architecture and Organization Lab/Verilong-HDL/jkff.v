module jkff(q,qbar,j,k,clr,clk);

input j,k,clr,clk;
output q,qbar;

nand nd1(a,qbar,j,clk,clr);
nand nd2(b,q,k,clk);
nand nd3(y,a,ybar);
nand nd4(ybar,b,y,clr);

not nt(cbar,clk);

nand nd5(c,y,cbar);
nand nd6(d,cbar,ybar);
nand nd7(q,c,qbar);
nand nd8(qbar,d,q,clr);

endmodule