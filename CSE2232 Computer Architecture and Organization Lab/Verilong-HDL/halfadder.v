module halfadder(s,c,a,b);

input a,b;
output s,c;

xor xr(s,a,b);
and an(c,a,b);

endmodule