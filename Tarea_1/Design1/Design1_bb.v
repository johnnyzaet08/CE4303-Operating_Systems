
module Design1 (
	clk_clk,
	pio_miliseconds_0_external_connection_export,
	pio_miliseconds_1_external_connection_export,
	pio_minutes_0_external_connection_export,
	pio_minutes_1_external_connection_export,
	pio_seconds_0_external_connection_export,
	pio_seconds_1_external_connection_export,
	pio_selectmode_0_external_connection_export,
	reset_reset_n,
	pio_stop_0_external_connection_export,
	pio_start_0_external_connection_export);	

	input		clk_clk;
	output	[6:0]	pio_miliseconds_0_external_connection_export;
	output	[6:0]	pio_miliseconds_1_external_connection_export;
	output	[6:0]	pio_minutes_0_external_connection_export;
	output	[6:0]	pio_minutes_1_external_connection_export;
	output	[6:0]	pio_seconds_0_external_connection_export;
	output	[6:0]	pio_seconds_1_external_connection_export;
	input	[1:0]	pio_selectmode_0_external_connection_export;
	input		reset_reset_n;
	input		pio_stop_0_external_connection_export;
	input		pio_start_0_external_connection_export;
endmodule
