module tarea_1_clock (

	input logic clk,
					reset,
	input logic [1:0] switchSelect,
	input logic start,
					stop,
	output logic [6:0] milisecondsDisplay1,
							  milisecondsDisplay2,
							  secondsDisplay1,
							  secondsDisplay2,
							  minutesDisplay1,
							  minutesDisplay2,
	output logic [1:0] ledSwitch

);
	
	assign ledSwitch = switchSelect;
	
	Design1 desi1 (
		.clk_clk(clk),
		.reset_reset_n(reset),
		.pio_stop_0_external_connection_export(stop),
		.pio_start_0_external_connection_export(start),
		.pio_selectmode_0_external_connection_export(switchSelect),
		.pio_miliseconds_0_external_connection_export(milisecondsDisplay1),
		.pio_miliseconds_1_external_connection_export(milisecondsDisplay2),
		.pio_seconds_0_external_connection_export(secondsDisplay1),
		.pio_seconds_1_external_connection_export(secondsDisplay2),
		.pio_minutes_0_external_connection_export(minutesDisplay1),
		.pio_minutes_1_external_connection_export(minutesDisplay2)
	);
	


endmodule