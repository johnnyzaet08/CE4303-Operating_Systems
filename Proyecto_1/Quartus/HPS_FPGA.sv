`timescale 1 ps / 1 ps
module HPS_FPGA (
		input  wire        clk_clk,            //    clk.clk
		input  wire [3:0]  keys_export,        //   keys.export
		output wire [9:0]  leds_export,        //   leds.export
		output wire [12:0] memory_mem_a,       // memory.mem_a
		output wire [2:0]  memory_mem_ba,      //       .mem_ba
		output wire        memory_mem_ck,      //       .mem_ck
		output wire        memory_mem_ck_n,    //       .mem_ck_n
		output wire        memory_mem_cke,     //       .mem_cke
		output wire        memory_mem_cs_n,    //       .mem_cs_n
		output wire        memory_mem_ras_n,   //       .mem_ras_n
		output wire        memory_mem_cas_n,   //       .mem_cas_n
		output wire        memory_mem_we_n,    //       .mem_we_n
		output wire        memory_mem_reset_n, //       .mem_reset_n
		inout  wire [7:0]  memory_mem_dq,      //       .mem_dq
		inout  wire        memory_mem_dqs,     //       .mem_dqs
		inout  wire        memory_mem_dqs_n,   //       .mem_dqs_n
		output wire        memory_mem_odt,     //       .mem_odt
		output wire        memory_mem_dm,      //       .mem_dm
		input  wire        memory_oct_rzqin,   //       .oct_rzqin
		input  wire        reset_reset_n,      //  reset.reset_n
		output wire [12:0] sdram_wire_addr,    // sdram_wire.addr
		output wire [1:0]  sdram_wire_ba,      //           .ba
		output wire        sdram_wire_cas_n,   //           .cas_n
		output wire        sdram_wire_cke,     //           .cke
		output wire        sdram_wire_cs_n,    //           .cs_n
		inout  wire [15:0] sdram_wire_dq,      //           .dq
		output wire [1:0]  sdram_wire_dqm,     //           .dqm
		output wire        sdram_wire_ras_n,   //           .ras_n
		output wire        sdram_wire_we_n,    //           .we_n
		output wire [6:0]  seg1_export,        //   seg1.export
		output wire [6:0]  seg2_export,        //   seg2.export
		output wire [6:0]  seg3_export,        //   seg3.export
		output wire [6:0]  seg4_export,        //   seg4.export
		output wire [6:0]  seg5_export,        //   seg5.export
		output wire [6:0]  seg6_export,        //   seg6.export
		input  wire [9:0]  sw_export           //     sw.export
);


	NUEVO_DESIGN u0 (
		.clk_clk            (clk_clk),            //        clk.clk
		.keys_export        (keys_export),        //       keys.export
		.leds_export        (leds_export),        //       leds.export
		.memory_mem_a       (memory_mem_a),       //     memory.mem_a
		.memory_mem_ba      (memory_mem_ba),      //           .mem_ba
		.memory_mem_ck      (memory_mem_ck),      //           .mem_ck
		.memory_mem_ck_n    (memory_mem_ck_n),    //           .mem_ck_n
		.memory_mem_cke     (memory_mem_cke),     //           .mem_cke
		.memory_mem_cs_n    (memory_mem_cs_n),    //           .mem_cs_n
		.memory_mem_ras_n   (memory_mem_ras_n),   //           .mem_ras_n
		.memory_mem_cas_n   (memory_mem_cas_n),   //           .mem_cas_n
		.memory_mem_we_n    (memory_mem_we_n),    //           .mem_we_n
		.memory_mem_reset_n (memory_mem_reset_n), //           .mem_reset_n
		.memory_mem_dq      (memory_mem_dq),      //           .mem_dq
		.memory_mem_dqs     (memory_mem_dqs),     //           .mem_dqs
		.memory_mem_dqs_n   (memory_mem_dqs_n),   //           .mem_dqs_n
		.memory_mem_odt     (memory_mem_odt),     //           .mem_odt
		.memory_mem_dm      (memory_mem_dm),      //           .mem_dm
		.memory_oct_rzqin   (memory_oct_rzqin),   //           .oct_rzqin
		.reset_reset_n      (reset_reset_n),      //      reset.reset_n
		.seg1_export        (seg1_export),        //       seg1.export
		.seg2_export        (seg2_export),        //       seg2.export
		.seg3_export        (seg3_export),        //       seg3.export
		.seg4_export        (seg4_export),        //       seg4.export
		.seg5_export        (seg5_export),        //       seg5.export
		.seg6_export        (seg6_export),        //       seg6.export
		.sw_export          (sw_export),          //         sw.export
		.sdram_wire_addr    (sdram_wire_addr),    // sdram_wire.addr
		.sdram_wire_ba      (sdram_wire_ba),      //           .ba
		.sdram_wire_cas_n   (sdram_wire_cas_n),   //           .cas_n
		.sdram_wire_cke     (sdram_wire_cke),     //           .cke
		.sdram_wire_cs_n    (sdram_wire_cs_n),    //           .cs_n
		.sdram_wire_dq      (sdram_wire_dq),      //           .dq
		.sdram_wire_dqm     (sdram_wire_dqm),     //           .dqm
		.sdram_wire_ras_n   (sdram_wire_ras_n),   //           .ras_n
		.sdram_wire_we_n    (sdram_wire_we_n)     //           .we_n
	);

endmodule