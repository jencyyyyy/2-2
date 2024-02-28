module addersubtractor(s,c,a,b,mode);

input [3:0]a,b;
input mode;

output [3:0]s;
output c;

wire [3:0]b2;

xor xr1(b2[0], mode,b[0]);
xor xr2(b2[1], mode,b[1]);
xor xr3(b2[2], mode,b[2]);
xor xr4(b2[3], mode,b[3]);

rippleadder ra(s,c,a,b2,mode);

endmodule