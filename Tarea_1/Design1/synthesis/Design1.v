// Design1.v

// Generated using ACDS version 22.1 917

`timescale 1 ps / 1 ps
module Design1 (
		input  wire       clk_clk,                                      //                                   clk.clk
		output wire [6:0] pio_miliseconds_0_external_connection_export, // pio_miliseconds_0_external_connection.export
		output wire [6:0] pio_miliseconds_1_external_connection_export, // pio_miliseconds_1_external_connection.export
		output wire [6:0] pio_minutes_0_external_connection_export,     //     pio_minutes_0_external_connection.export
		output wire [6:0] pio_minutes_1_external_connection_export,     //     pio_minutes_1_external_connection.export
		output wire [6:0] pio_seconds_0_external_connection_export,     //     pio_seconds_0_external_connection.export
		output wire [6:0] pio_seconds_1_external_connection_export,     //     pio_seconds_1_external_connection.export
		input  wire [1:0] pio_selectmode_0_external_connection_export,  //  pio_selectmode_0_external_connection.export
		input  wire       pio_start_0_external_connection_export,       //       pio_start_0_external_connection.export
		input  wire       pio_stop_0_external_connection_export,        //        pio_stop_0_external_connection.export
		input  wire       reset_reset_n                                 //                                 reset.reset_n
	);

	wire  [31:0] nios2_gen2_0_data_master_readdata;                 // mm_interconnect_0:nios2_gen2_0_data_master_readdata -> nios2_gen2_0:d_readdata
	wire         nios2_gen2_0_data_master_waitrequest;              // mm_interconnect_0:nios2_gen2_0_data_master_waitrequest -> nios2_gen2_0:d_waitrequest
	wire  [20:0] nios2_gen2_0_data_master_address;                  // nios2_gen2_0:d_address -> mm_interconnect_0:nios2_gen2_0_data_master_address
	wire   [3:0] nios2_gen2_0_data_master_byteenable;               // nios2_gen2_0:d_byteenable -> mm_interconnect_0:nios2_gen2_0_data_master_byteenable
	wire         nios2_gen2_0_data_master_read;                     // nios2_gen2_0:d_read -> mm_interconnect_0:nios2_gen2_0_data_master_read
	wire         nios2_gen2_0_data_master_write;                    // nios2_gen2_0:d_write -> mm_interconnect_0:nios2_gen2_0_data_master_write
	wire  [31:0] nios2_gen2_0_data_master_writedata;                // nios2_gen2_0:d_writedata -> mm_interconnect_0:nios2_gen2_0_data_master_writedata
	wire         mm_interconnect_0_ram_0_s1_chipselect;             // mm_interconnect_0:ram_0_s1_chipselect -> ram_0:chipselect
	wire  [31:0] mm_interconnect_0_ram_0_s1_readdata;               // ram_0:readdata -> mm_interconnect_0:ram_0_s1_readdata
	wire  [11:0] mm_interconnect_0_ram_0_s1_address;                // mm_interconnect_0:ram_0_s1_address -> ram_0:address
	wire   [3:0] mm_interconnect_0_ram_0_s1_byteenable;             // mm_interconnect_0:ram_0_s1_byteenable -> ram_0:byteenable
	wire         mm_interconnect_0_ram_0_s1_write;                  // mm_interconnect_0:ram_0_s1_write -> ram_0:write
	wire  [31:0] mm_interconnect_0_ram_0_s1_writedata;              // mm_interconnect_0:ram_0_s1_writedata -> ram_0:writedata
	wire         mm_interconnect_0_ram_0_s1_clken;                  // mm_interconnect_0:ram_0_s1_clken -> ram_0:clken
	wire         mm_interconnect_0_timer_0_s1_chipselect;           // mm_interconnect_0:timer_0_s1_chipselect -> timer_0:chipselect
	wire  [15:0] mm_interconnect_0_timer_0_s1_readdata;             // timer_0:readdata -> mm_interconnect_0:timer_0_s1_readdata
	wire   [2:0] mm_interconnect_0_timer_0_s1_address;              // mm_interconnect_0:timer_0_s1_address -> timer_0:address
	wire         mm_interconnect_0_timer_0_s1_write;                // mm_interconnect_0:timer_0_s1_write -> timer_0:write_n
	wire  [15:0] mm_interconnect_0_timer_0_s1_writedata;            // mm_interconnect_0:timer_0_s1_writedata -> timer_0:writedata
	wire         mm_interconnect_0_pio_miliseconds_0_s1_chipselect; // mm_interconnect_0:pio_miliseconds_0_s1_chipselect -> pio_miliseconds_0:chipselect
	wire  [31:0] mm_interconnect_0_pio_miliseconds_0_s1_readdata;   // pio_miliseconds_0:readdata -> mm_interconnect_0:pio_miliseconds_0_s1_readdata
	wire   [1:0] mm_interconnect_0_pio_miliseconds_0_s1_address;    // mm_interconnect_0:pio_miliseconds_0_s1_address -> pio_miliseconds_0:address
	wire         mm_interconnect_0_pio_miliseconds_0_s1_write;      // mm_interconnect_0:pio_miliseconds_0_s1_write -> pio_miliseconds_0:write_n
	wire  [31:0] mm_interconnect_0_pio_miliseconds_0_s1_writedata;  // mm_interconnect_0:pio_miliseconds_0_s1_writedata -> pio_miliseconds_0:writedata
	wire         mm_interconnect_0_pio_seconds_0_s1_chipselect;     // mm_interconnect_0:pio_seconds_0_s1_chipselect -> pio_seconds_0:chipselect
	wire  [31:0] mm_interconnect_0_pio_seconds_0_s1_readdata;       // pio_seconds_0:readdata -> mm_interconnect_0:pio_seconds_0_s1_readdata
	wire   [1:0] mm_interconnect_0_pio_seconds_0_s1_address;        // mm_interconnect_0:pio_seconds_0_s1_address -> pio_seconds_0:address
	wire         mm_interconnect_0_pio_seconds_0_s1_write;          // mm_interconnect_0:pio_seconds_0_s1_write -> pio_seconds_0:write_n
	wire  [31:0] mm_interconnect_0_pio_seconds_0_s1_writedata;      // mm_interconnect_0:pio_seconds_0_s1_writedata -> pio_seconds_0:writedata
	wire         mm_interconnect_0_pio_minutes_0_s1_chipselect;     // mm_interconnect_0:pio_minutes_0_s1_chipselect -> pio_minutes_0:chipselect
	wire  [31:0] mm_interconnect_0_pio_minutes_0_s1_readdata;       // pio_minutes_0:readdata -> mm_interconnect_0:pio_minutes_0_s1_readdata
	wire   [1:0] mm_interconnect_0_pio_minutes_0_s1_address;        // mm_interconnect_0:pio_minutes_0_s1_address -> pio_minutes_0:address
	wire         mm_interconnect_0_pio_minutes_0_s1_write;          // mm_interconnect_0:pio_minutes_0_s1_write -> pio_minutes_0:write_n
	wire  [31:0] mm_interconnect_0_pio_minutes_0_s1_writedata;      // mm_interconnect_0:pio_minutes_0_s1_writedata -> pio_minutes_0:writedata
	wire  [31:0] mm_interconnect_0_pio_selectmode_0_s1_readdata;    // pio_selectmode_0:readdata -> mm_interconnect_0:pio_selectmode_0_s1_readdata
	wire   [1:0] mm_interconnect_0_pio_selectmode_0_s1_address;     // mm_interconnect_0:pio_selectmode_0_s1_address -> pio_selectmode_0:address
	wire         mm_interconnect_0_pio_miliseconds_1_s1_chipselect; // mm_interconnect_0:pio_miliseconds_1_s1_chipselect -> pio_miliseconds_1:chipselect
	wire  [31:0] mm_interconnect_0_pio_miliseconds_1_s1_readdata;   // pio_miliseconds_1:readdata -> mm_interconnect_0:pio_miliseconds_1_s1_readdata
	wire   [1:0] mm_interconnect_0_pio_miliseconds_1_s1_address;    // mm_interconnect_0:pio_miliseconds_1_s1_address -> pio_miliseconds_1:address
	wire         mm_interconnect_0_pio_miliseconds_1_s1_write;      // mm_interconnect_0:pio_miliseconds_1_s1_write -> pio_miliseconds_1:write_n
	wire  [31:0] mm_interconnect_0_pio_miliseconds_1_s1_writedata;  // mm_interconnect_0:pio_miliseconds_1_s1_writedata -> pio_miliseconds_1:writedata
	wire         mm_interconnect_0_pio_seconds_1_s1_chipselect;     // mm_interconnect_0:pio_seconds_1_s1_chipselect -> pio_seconds_1:chipselect
	wire  [31:0] mm_interconnect_0_pio_seconds_1_s1_readdata;       // pio_seconds_1:readdata -> mm_interconnect_0:pio_seconds_1_s1_readdata
	wire   [1:0] mm_interconnect_0_pio_seconds_1_s1_address;        // mm_interconnect_0:pio_seconds_1_s1_address -> pio_seconds_1:address
	wire         mm_interconnect_0_pio_seconds_1_s1_write;          // mm_interconnect_0:pio_seconds_1_s1_write -> pio_seconds_1:write_n
	wire  [31:0] mm_interconnect_0_pio_seconds_1_s1_writedata;      // mm_interconnect_0:pio_seconds_1_s1_writedata -> pio_seconds_1:writedata
	wire         mm_interconnect_0_pio_minutes_1_s1_chipselect;     // mm_interconnect_0:pio_minutes_1_s1_chipselect -> pio_minutes_1:chipselect
	wire  [31:0] mm_interconnect_0_pio_minutes_1_s1_readdata;       // pio_minutes_1:readdata -> mm_interconnect_0:pio_minutes_1_s1_readdata
	wire   [1:0] mm_interconnect_0_pio_minutes_1_s1_address;        // mm_interconnect_0:pio_minutes_1_s1_address -> pio_minutes_1:address
	wire         mm_interconnect_0_pio_minutes_1_s1_write;          // mm_interconnect_0:pio_minutes_1_s1_write -> pio_minutes_1:write_n
	wire  [31:0] mm_interconnect_0_pio_minutes_1_s1_writedata;      // mm_interconnect_0:pio_minutes_1_s1_writedata -> pio_minutes_1:writedata
	wire  [31:0] mm_interconnect_0_pio_stop_0_s1_readdata;          // pio_stop_0:readdata -> mm_interconnect_0:pio_stop_0_s1_readdata
	wire   [1:0] mm_interconnect_0_pio_stop_0_s1_address;           // mm_interconnect_0:pio_stop_0_s1_address -> pio_stop_0:address
	wire  [31:0] mm_interconnect_0_pio_start_0_s1_readdata;         // pio_start_0:readdata -> mm_interconnect_0:pio_start_0_s1_readdata
	wire   [1:0] mm_interconnect_0_pio_start_0_s1_address;          // mm_interconnect_0:pio_start_0_s1_address -> pio_start_0:address
	wire  [31:0] nios2_gen2_0_instruction_master_readdata;          // mm_interconnect_1:nios2_gen2_0_instruction_master_readdata -> nios2_gen2_0:i_readdata
	wire         nios2_gen2_0_instruction_master_waitrequest;       // mm_interconnect_1:nios2_gen2_0_instruction_master_waitrequest -> nios2_gen2_0:i_waitrequest
	wire  [12:0] nios2_gen2_0_instruction_master_address;           // nios2_gen2_0:i_address -> mm_interconnect_1:nios2_gen2_0_instruction_master_address
	wire         nios2_gen2_0_instruction_master_read;              // nios2_gen2_0:i_read -> mm_interconnect_1:nios2_gen2_0_instruction_master_read
	wire         mm_interconnect_1_rom_0_s1_chipselect;             // mm_interconnect_1:rom_0_s1_chipselect -> rom_0:chipselect
	wire  [31:0] mm_interconnect_1_rom_0_s1_readdata;               // rom_0:readdata -> mm_interconnect_1:rom_0_s1_readdata
	wire         mm_interconnect_1_rom_0_s1_debugaccess;            // mm_interconnect_1:rom_0_s1_debugaccess -> rom_0:debugaccess
	wire  [10:0] mm_interconnect_1_rom_0_s1_address;                // mm_interconnect_1:rom_0_s1_address -> rom_0:address
	wire   [3:0] mm_interconnect_1_rom_0_s1_byteenable;             // mm_interconnect_1:rom_0_s1_byteenable -> rom_0:byteenable
	wire         mm_interconnect_1_rom_0_s1_write;                  // mm_interconnect_1:rom_0_s1_write -> rom_0:write
	wire  [31:0] mm_interconnect_1_rom_0_s1_writedata;              // mm_interconnect_1:rom_0_s1_writedata -> rom_0:writedata
	wire         mm_interconnect_1_rom_0_s1_clken;                  // mm_interconnect_1:rom_0_s1_clken -> rom_0:clken
	wire         irq_mapper_receiver0_irq;                          // timer_0:irq -> irq_mapper:receiver0_irq
	wire  [31:0] nios2_gen2_0_irq_irq;                              // irq_mapper:sender_irq -> nios2_gen2_0:irq
	wire         rst_controller_reset_out_reset;                    // rst_controller:reset_out -> [irq_mapper:reset, mm_interconnect_0:nios2_gen2_0_reset_reset_bridge_in_reset_reset, mm_interconnect_1:nios2_gen2_0_reset_reset_bridge_in_reset_reset, nios2_gen2_0:reset_n, pio_miliseconds_0:reset_n, pio_miliseconds_1:reset_n, pio_minutes_0:reset_n, pio_minutes_1:reset_n, pio_seconds_0:reset_n, pio_seconds_1:reset_n, pio_selectmode_0:reset_n, pio_start_0:reset_n, pio_stop_0:reset_n, ram_0:reset, rom_0:reset, rst_translator:in_reset, timer_0:reset_n]
	wire         rst_controller_reset_out_reset_req;                // rst_controller:reset_req -> [ram_0:reset_req, rom_0:reset_req, rst_translator:reset_req_in]

	Design1_nios2_gen2_0 nios2_gen2_0 (
		.clk           (clk_clk),                                     //                       clk.clk
		.reset_n       (~rst_controller_reset_out_reset),             //                     reset.reset_n
		.d_address     (nios2_gen2_0_data_master_address),            //               data_master.address
		.d_byteenable  (nios2_gen2_0_data_master_byteenable),         //                          .byteenable
		.d_read        (nios2_gen2_0_data_master_read),               //                          .read
		.d_readdata    (nios2_gen2_0_data_master_readdata),           //                          .readdata
		.d_waitrequest (nios2_gen2_0_data_master_waitrequest),        //                          .waitrequest
		.d_write       (nios2_gen2_0_data_master_write),              //                          .write
		.d_writedata   (nios2_gen2_0_data_master_writedata),          //                          .writedata
		.i_address     (nios2_gen2_0_instruction_master_address),     //        instruction_master.address
		.i_read        (nios2_gen2_0_instruction_master_read),        //                          .read
		.i_readdata    (nios2_gen2_0_instruction_master_readdata),    //                          .readdata
		.i_waitrequest (nios2_gen2_0_instruction_master_waitrequest), //                          .waitrequest
		.irq           (nios2_gen2_0_irq_irq),                        //                       irq.irq
		.dummy_ci_port ()                                             // custom_instruction_master.readra
	);

	Design1_pio_miliseconds_0 pio_miliseconds_0 (
		.clk        (clk_clk),                                           //                 clk.clk
		.reset_n    (~rst_controller_reset_out_reset),                   //               reset.reset_n
		.address    (mm_interconnect_0_pio_miliseconds_0_s1_address),    //                  s1.address
		.write_n    (~mm_interconnect_0_pio_miliseconds_0_s1_write),     //                    .write_n
		.writedata  (mm_interconnect_0_pio_miliseconds_0_s1_writedata),  //                    .writedata
		.chipselect (mm_interconnect_0_pio_miliseconds_0_s1_chipselect), //                    .chipselect
		.readdata   (mm_interconnect_0_pio_miliseconds_0_s1_readdata),   //                    .readdata
		.out_port   (pio_miliseconds_0_external_connection_export)       // external_connection.export
	);

	Design1_pio_miliseconds_0 pio_miliseconds_1 (
		.clk        (clk_clk),                                           //                 clk.clk
		.reset_n    (~rst_controller_reset_out_reset),                   //               reset.reset_n
		.address    (mm_interconnect_0_pio_miliseconds_1_s1_address),    //                  s1.address
		.write_n    (~mm_interconnect_0_pio_miliseconds_1_s1_write),     //                    .write_n
		.writedata  (mm_interconnect_0_pio_miliseconds_1_s1_writedata),  //                    .writedata
		.chipselect (mm_interconnect_0_pio_miliseconds_1_s1_chipselect), //                    .chipselect
		.readdata   (mm_interconnect_0_pio_miliseconds_1_s1_readdata),   //                    .readdata
		.out_port   (pio_miliseconds_1_external_connection_export)       // external_connection.export
	);

	Design1_pio_miliseconds_0 pio_minutes_0 (
		.clk        (clk_clk),                                       //                 clk.clk
		.reset_n    (~rst_controller_reset_out_reset),               //               reset.reset_n
		.address    (mm_interconnect_0_pio_minutes_0_s1_address),    //                  s1.address
		.write_n    (~mm_interconnect_0_pio_minutes_0_s1_write),     //                    .write_n
		.writedata  (mm_interconnect_0_pio_minutes_0_s1_writedata),  //                    .writedata
		.chipselect (mm_interconnect_0_pio_minutes_0_s1_chipselect), //                    .chipselect
		.readdata   (mm_interconnect_0_pio_minutes_0_s1_readdata),   //                    .readdata
		.out_port   (pio_minutes_0_external_connection_export)       // external_connection.export
	);

	Design1_pio_miliseconds_0 pio_minutes_1 (
		.clk        (clk_clk),                                       //                 clk.clk
		.reset_n    (~rst_controller_reset_out_reset),               //               reset.reset_n
		.address    (mm_interconnect_0_pio_minutes_1_s1_address),    //                  s1.address
		.write_n    (~mm_interconnect_0_pio_minutes_1_s1_write),     //                    .write_n
		.writedata  (mm_interconnect_0_pio_minutes_1_s1_writedata),  //                    .writedata
		.chipselect (mm_interconnect_0_pio_minutes_1_s1_chipselect), //                    .chipselect
		.readdata   (mm_interconnect_0_pio_minutes_1_s1_readdata),   //                    .readdata
		.out_port   (pio_minutes_1_external_connection_export)       // external_connection.export
	);

	Design1_pio_miliseconds_0 pio_seconds_0 (
		.clk        (clk_clk),                                       //                 clk.clk
		.reset_n    (~rst_controller_reset_out_reset),               //               reset.reset_n
		.address    (mm_interconnect_0_pio_seconds_0_s1_address),    //                  s1.address
		.write_n    (~mm_interconnect_0_pio_seconds_0_s1_write),     //                    .write_n
		.writedata  (mm_interconnect_0_pio_seconds_0_s1_writedata),  //                    .writedata
		.chipselect (mm_interconnect_0_pio_seconds_0_s1_chipselect), //                    .chipselect
		.readdata   (mm_interconnect_0_pio_seconds_0_s1_readdata),   //                    .readdata
		.out_port   (pio_seconds_0_external_connection_export)       // external_connection.export
	);

	Design1_pio_miliseconds_0 pio_seconds_1 (
		.clk        (clk_clk),                                       //                 clk.clk
		.reset_n    (~rst_controller_reset_out_reset),               //               reset.reset_n
		.address    (mm_interconnect_0_pio_seconds_1_s1_address),    //                  s1.address
		.write_n    (~mm_interconnect_0_pio_seconds_1_s1_write),     //                    .write_n
		.writedata  (mm_interconnect_0_pio_seconds_1_s1_writedata),  //                    .writedata
		.chipselect (mm_interconnect_0_pio_seconds_1_s1_chipselect), //                    .chipselect
		.readdata   (mm_interconnect_0_pio_seconds_1_s1_readdata),   //                    .readdata
		.out_port   (pio_seconds_1_external_connection_export)       // external_connection.export
	);

	Design1_pio_selectmode_0 pio_selectmode_0 (
		.clk      (clk_clk),                                        //                 clk.clk
		.reset_n  (~rst_controller_reset_out_reset),                //               reset.reset_n
		.address  (mm_interconnect_0_pio_selectmode_0_s1_address),  //                  s1.address
		.readdata (mm_interconnect_0_pio_selectmode_0_s1_readdata), //                    .readdata
		.in_port  (pio_selectmode_0_external_connection_export)     // external_connection.export
	);

	Design1_pio_start_0 pio_start_0 (
		.clk      (clk_clk),                                   //                 clk.clk
		.reset_n  (~rst_controller_reset_out_reset),           //               reset.reset_n
		.address  (mm_interconnect_0_pio_start_0_s1_address),  //                  s1.address
		.readdata (mm_interconnect_0_pio_start_0_s1_readdata), //                    .readdata
		.in_port  (pio_start_0_external_connection_export)     // external_connection.export
	);

	Design1_pio_start_0 pio_stop_0 (
		.clk      (clk_clk),                                  //                 clk.clk
		.reset_n  (~rst_controller_reset_out_reset),          //               reset.reset_n
		.address  (mm_interconnect_0_pio_stop_0_s1_address),  //                  s1.address
		.readdata (mm_interconnect_0_pio_stop_0_s1_readdata), //                    .readdata
		.in_port  (pio_stop_0_external_connection_export)     // external_connection.export
	);

	Design1_ram_0 ram_0 (
		.clk        (clk_clk),                               //   clk1.clk
		.address    (mm_interconnect_0_ram_0_s1_address),    //     s1.address
		.clken      (mm_interconnect_0_ram_0_s1_clken),      //       .clken
		.chipselect (mm_interconnect_0_ram_0_s1_chipselect), //       .chipselect
		.write      (mm_interconnect_0_ram_0_s1_write),      //       .write
		.readdata   (mm_interconnect_0_ram_0_s1_readdata),   //       .readdata
		.writedata  (mm_interconnect_0_ram_0_s1_writedata),  //       .writedata
		.byteenable (mm_interconnect_0_ram_0_s1_byteenable), //       .byteenable
		.reset      (rst_controller_reset_out_reset),        // reset1.reset
		.reset_req  (rst_controller_reset_out_reset_req),    //       .reset_req
		.freeze     (1'b0)                                   // (terminated)
	);

	Design1_rom_0 rom_0 (
		.clk         (clk_clk),                                //   clk1.clk
		.address     (mm_interconnect_1_rom_0_s1_address),     //     s1.address
		.debugaccess (mm_interconnect_1_rom_0_s1_debugaccess), //       .debugaccess
		.clken       (mm_interconnect_1_rom_0_s1_clken),       //       .clken
		.chipselect  (mm_interconnect_1_rom_0_s1_chipselect),  //       .chipselect
		.write       (mm_interconnect_1_rom_0_s1_write),       //       .write
		.readdata    (mm_interconnect_1_rom_0_s1_readdata),    //       .readdata
		.writedata   (mm_interconnect_1_rom_0_s1_writedata),   //       .writedata
		.byteenable  (mm_interconnect_1_rom_0_s1_byteenable),  //       .byteenable
		.reset       (rst_controller_reset_out_reset),         // reset1.reset
		.reset_req   (rst_controller_reset_out_reset_req),     //       .reset_req
		.freeze      (1'b0)                                    // (terminated)
	);

	Design1_timer_0 timer_0 (
		.clk        (clk_clk),                                 //   clk.clk
		.reset_n    (~rst_controller_reset_out_reset),         // reset.reset_n
		.address    (mm_interconnect_0_timer_0_s1_address),    //    s1.address
		.writedata  (mm_interconnect_0_timer_0_s1_writedata),  //      .writedata
		.readdata   (mm_interconnect_0_timer_0_s1_readdata),   //      .readdata
		.chipselect (mm_interconnect_0_timer_0_s1_chipselect), //      .chipselect
		.write_n    (~mm_interconnect_0_timer_0_s1_write),     //      .write_n
		.irq        (irq_mapper_receiver0_irq)                 //   irq.irq
	);

	Design1_mm_interconnect_0 mm_interconnect_0 (
		.clk_0_clk_clk                                  (clk_clk),                                           //                                clk_0_clk.clk
		.nios2_gen2_0_reset_reset_bridge_in_reset_reset (rst_controller_reset_out_reset),                    // nios2_gen2_0_reset_reset_bridge_in_reset.reset
		.nios2_gen2_0_data_master_address               (nios2_gen2_0_data_master_address),                  //                 nios2_gen2_0_data_master.address
		.nios2_gen2_0_data_master_waitrequest           (nios2_gen2_0_data_master_waitrequest),              //                                         .waitrequest
		.nios2_gen2_0_data_master_byteenable            (nios2_gen2_0_data_master_byteenable),               //                                         .byteenable
		.nios2_gen2_0_data_master_read                  (nios2_gen2_0_data_master_read),                     //                                         .read
		.nios2_gen2_0_data_master_readdata              (nios2_gen2_0_data_master_readdata),                 //                                         .readdata
		.nios2_gen2_0_data_master_write                 (nios2_gen2_0_data_master_write),                    //                                         .write
		.nios2_gen2_0_data_master_writedata             (nios2_gen2_0_data_master_writedata),                //                                         .writedata
		.pio_miliseconds_0_s1_address                   (mm_interconnect_0_pio_miliseconds_0_s1_address),    //                     pio_miliseconds_0_s1.address
		.pio_miliseconds_0_s1_write                     (mm_interconnect_0_pio_miliseconds_0_s1_write),      //                                         .write
		.pio_miliseconds_0_s1_readdata                  (mm_interconnect_0_pio_miliseconds_0_s1_readdata),   //                                         .readdata
		.pio_miliseconds_0_s1_writedata                 (mm_interconnect_0_pio_miliseconds_0_s1_writedata),  //                                         .writedata
		.pio_miliseconds_0_s1_chipselect                (mm_interconnect_0_pio_miliseconds_0_s1_chipselect), //                                         .chipselect
		.pio_miliseconds_1_s1_address                   (mm_interconnect_0_pio_miliseconds_1_s1_address),    //                     pio_miliseconds_1_s1.address
		.pio_miliseconds_1_s1_write                     (mm_interconnect_0_pio_miliseconds_1_s1_write),      //                                         .write
		.pio_miliseconds_1_s1_readdata                  (mm_interconnect_0_pio_miliseconds_1_s1_readdata),   //                                         .readdata
		.pio_miliseconds_1_s1_writedata                 (mm_interconnect_0_pio_miliseconds_1_s1_writedata),  //                                         .writedata
		.pio_miliseconds_1_s1_chipselect                (mm_interconnect_0_pio_miliseconds_1_s1_chipselect), //                                         .chipselect
		.pio_minutes_0_s1_address                       (mm_interconnect_0_pio_minutes_0_s1_address),        //                         pio_minutes_0_s1.address
		.pio_minutes_0_s1_write                         (mm_interconnect_0_pio_minutes_0_s1_write),          //                                         .write
		.pio_minutes_0_s1_readdata                      (mm_interconnect_0_pio_minutes_0_s1_readdata),       //                                         .readdata
		.pio_minutes_0_s1_writedata                     (mm_interconnect_0_pio_minutes_0_s1_writedata),      //                                         .writedata
		.pio_minutes_0_s1_chipselect                    (mm_interconnect_0_pio_minutes_0_s1_chipselect),     //                                         .chipselect
		.pio_minutes_1_s1_address                       (mm_interconnect_0_pio_minutes_1_s1_address),        //                         pio_minutes_1_s1.address
		.pio_minutes_1_s1_write                         (mm_interconnect_0_pio_minutes_1_s1_write),          //                                         .write
		.pio_minutes_1_s1_readdata                      (mm_interconnect_0_pio_minutes_1_s1_readdata),       //                                         .readdata
		.pio_minutes_1_s1_writedata                     (mm_interconnect_0_pio_minutes_1_s1_writedata),      //                                         .writedata
		.pio_minutes_1_s1_chipselect                    (mm_interconnect_0_pio_minutes_1_s1_chipselect),     //                                         .chipselect
		.pio_seconds_0_s1_address                       (mm_interconnect_0_pio_seconds_0_s1_address),        //                         pio_seconds_0_s1.address
		.pio_seconds_0_s1_write                         (mm_interconnect_0_pio_seconds_0_s1_write),          //                                         .write
		.pio_seconds_0_s1_readdata                      (mm_interconnect_0_pio_seconds_0_s1_readdata),       //                                         .readdata
		.pio_seconds_0_s1_writedata                     (mm_interconnect_0_pio_seconds_0_s1_writedata),      //                                         .writedata
		.pio_seconds_0_s1_chipselect                    (mm_interconnect_0_pio_seconds_0_s1_chipselect),     //                                         .chipselect
		.pio_seconds_1_s1_address                       (mm_interconnect_0_pio_seconds_1_s1_address),        //                         pio_seconds_1_s1.address
		.pio_seconds_1_s1_write                         (mm_interconnect_0_pio_seconds_1_s1_write),          //                                         .write
		.pio_seconds_1_s1_readdata                      (mm_interconnect_0_pio_seconds_1_s1_readdata),       //                                         .readdata
		.pio_seconds_1_s1_writedata                     (mm_interconnect_0_pio_seconds_1_s1_writedata),      //                                         .writedata
		.pio_seconds_1_s1_chipselect                    (mm_interconnect_0_pio_seconds_1_s1_chipselect),     //                                         .chipselect
		.pio_selectmode_0_s1_address                    (mm_interconnect_0_pio_selectmode_0_s1_address),     //                      pio_selectmode_0_s1.address
		.pio_selectmode_0_s1_readdata                   (mm_interconnect_0_pio_selectmode_0_s1_readdata),    //                                         .readdata
		.pio_start_0_s1_address                         (mm_interconnect_0_pio_start_0_s1_address),          //                           pio_start_0_s1.address
		.pio_start_0_s1_readdata                        (mm_interconnect_0_pio_start_0_s1_readdata),         //                                         .readdata
		.pio_stop_0_s1_address                          (mm_interconnect_0_pio_stop_0_s1_address),           //                            pio_stop_0_s1.address
		.pio_stop_0_s1_readdata                         (mm_interconnect_0_pio_stop_0_s1_readdata),          //                                         .readdata
		.ram_0_s1_address                               (mm_interconnect_0_ram_0_s1_address),                //                                 ram_0_s1.address
		.ram_0_s1_write                                 (mm_interconnect_0_ram_0_s1_write),                  //                                         .write
		.ram_0_s1_readdata                              (mm_interconnect_0_ram_0_s1_readdata),               //                                         .readdata
		.ram_0_s1_writedata                             (mm_interconnect_0_ram_0_s1_writedata),              //                                         .writedata
		.ram_0_s1_byteenable                            (mm_interconnect_0_ram_0_s1_byteenable),             //                                         .byteenable
		.ram_0_s1_chipselect                            (mm_interconnect_0_ram_0_s1_chipselect),             //                                         .chipselect
		.ram_0_s1_clken                                 (mm_interconnect_0_ram_0_s1_clken),                  //                                         .clken
		.timer_0_s1_address                             (mm_interconnect_0_timer_0_s1_address),              //                               timer_0_s1.address
		.timer_0_s1_write                               (mm_interconnect_0_timer_0_s1_write),                //                                         .write
		.timer_0_s1_readdata                            (mm_interconnect_0_timer_0_s1_readdata),             //                                         .readdata
		.timer_0_s1_writedata                           (mm_interconnect_0_timer_0_s1_writedata),            //                                         .writedata
		.timer_0_s1_chipselect                          (mm_interconnect_0_timer_0_s1_chipselect)            //                                         .chipselect
	);

	Design1_mm_interconnect_1 mm_interconnect_1 (
		.clk_0_clk_clk                                  (clk_clk),                                     //                                clk_0_clk.clk
		.nios2_gen2_0_reset_reset_bridge_in_reset_reset (rst_controller_reset_out_reset),              // nios2_gen2_0_reset_reset_bridge_in_reset.reset
		.nios2_gen2_0_instruction_master_address        (nios2_gen2_0_instruction_master_address),     //          nios2_gen2_0_instruction_master.address
		.nios2_gen2_0_instruction_master_waitrequest    (nios2_gen2_0_instruction_master_waitrequest), //                                         .waitrequest
		.nios2_gen2_0_instruction_master_read           (nios2_gen2_0_instruction_master_read),        //                                         .read
		.nios2_gen2_0_instruction_master_readdata       (nios2_gen2_0_instruction_master_readdata),    //                                         .readdata
		.rom_0_s1_address                               (mm_interconnect_1_rom_0_s1_address),          //                                 rom_0_s1.address
		.rom_0_s1_write                                 (mm_interconnect_1_rom_0_s1_write),            //                                         .write
		.rom_0_s1_readdata                              (mm_interconnect_1_rom_0_s1_readdata),         //                                         .readdata
		.rom_0_s1_writedata                             (mm_interconnect_1_rom_0_s1_writedata),        //                                         .writedata
		.rom_0_s1_byteenable                            (mm_interconnect_1_rom_0_s1_byteenable),       //                                         .byteenable
		.rom_0_s1_chipselect                            (mm_interconnect_1_rom_0_s1_chipselect),       //                                         .chipselect
		.rom_0_s1_clken                                 (mm_interconnect_1_rom_0_s1_clken),            //                                         .clken
		.rom_0_s1_debugaccess                           (mm_interconnect_1_rom_0_s1_debugaccess)       //                                         .debugaccess
	);

	Design1_irq_mapper irq_mapper (
		.clk           (clk_clk),                        //       clk.clk
		.reset         (rst_controller_reset_out_reset), // clk_reset.reset
		.receiver0_irq (irq_mapper_receiver0_irq),       // receiver0.irq
		.sender_irq    (nios2_gen2_0_irq_irq)            //    sender.irq
	);

	altera_reset_controller #(
		.NUM_RESET_INPUTS          (1),
		.OUTPUT_RESET_SYNC_EDGES   ("deassert"),
		.SYNC_DEPTH                (2),
		.RESET_REQUEST_PRESENT     (1),
		.RESET_REQ_WAIT_TIME       (1),
		.MIN_RST_ASSERTION_TIME    (3),
		.RESET_REQ_EARLY_DSRT_TIME (1),
		.USE_RESET_REQUEST_IN0     (0),
		.USE_RESET_REQUEST_IN1     (0),
		.USE_RESET_REQUEST_IN2     (0),
		.USE_RESET_REQUEST_IN3     (0),
		.USE_RESET_REQUEST_IN4     (0),
		.USE_RESET_REQUEST_IN5     (0),
		.USE_RESET_REQUEST_IN6     (0),
		.USE_RESET_REQUEST_IN7     (0),
		.USE_RESET_REQUEST_IN8     (0),
		.USE_RESET_REQUEST_IN9     (0),
		.USE_RESET_REQUEST_IN10    (0),
		.USE_RESET_REQUEST_IN11    (0),
		.USE_RESET_REQUEST_IN12    (0),
		.USE_RESET_REQUEST_IN13    (0),
		.USE_RESET_REQUEST_IN14    (0),
		.USE_RESET_REQUEST_IN15    (0),
		.ADAPT_RESET_REQUEST       (0)
	) rst_controller (
		.reset_in0      (~reset_reset_n),                     // reset_in0.reset
		.clk            (clk_clk),                            //       clk.clk
		.reset_out      (rst_controller_reset_out_reset),     // reset_out.reset
		.reset_req      (rst_controller_reset_out_reset_req), //          .reset_req
		.reset_req_in0  (1'b0),                               // (terminated)
		.reset_in1      (1'b0),                               // (terminated)
		.reset_req_in1  (1'b0),                               // (terminated)
		.reset_in2      (1'b0),                               // (terminated)
		.reset_req_in2  (1'b0),                               // (terminated)
		.reset_in3      (1'b0),                               // (terminated)
		.reset_req_in3  (1'b0),                               // (terminated)
		.reset_in4      (1'b0),                               // (terminated)
		.reset_req_in4  (1'b0),                               // (terminated)
		.reset_in5      (1'b0),                               // (terminated)
		.reset_req_in5  (1'b0),                               // (terminated)
		.reset_in6      (1'b0),                               // (terminated)
		.reset_req_in6  (1'b0),                               // (terminated)
		.reset_in7      (1'b0),                               // (terminated)
		.reset_req_in7  (1'b0),                               // (terminated)
		.reset_in8      (1'b0),                               // (terminated)
		.reset_req_in8  (1'b0),                               // (terminated)
		.reset_in9      (1'b0),                               // (terminated)
		.reset_req_in9  (1'b0),                               // (terminated)
		.reset_in10     (1'b0),                               // (terminated)
		.reset_req_in10 (1'b0),                               // (terminated)
		.reset_in11     (1'b0),                               // (terminated)
		.reset_req_in11 (1'b0),                               // (terminated)
		.reset_in12     (1'b0),                               // (terminated)
		.reset_req_in12 (1'b0),                               // (terminated)
		.reset_in13     (1'b0),                               // (terminated)
		.reset_req_in13 (1'b0),                               // (terminated)
		.reset_in14     (1'b0),                               // (terminated)
		.reset_req_in14 (1'b0),                               // (terminated)
		.reset_in15     (1'b0),                               // (terminated)
		.reset_req_in15 (1'b0)                                // (terminated)
	);

endmodule