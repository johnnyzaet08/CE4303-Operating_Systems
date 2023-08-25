	component Design1 is
		port (
			clk_clk                                      : in  std_logic                    := 'X';             -- clk
			pio_miliseconds_0_external_connection_export : out std_logic_vector(6 downto 0);                    -- export
			pio_miliseconds_1_external_connection_export : out std_logic_vector(6 downto 0);                    -- export
			pio_minutes_0_external_connection_export     : out std_logic_vector(6 downto 0);                    -- export
			pio_minutes_1_external_connection_export     : out std_logic_vector(6 downto 0);                    -- export
			pio_seconds_0_external_connection_export     : out std_logic_vector(6 downto 0);                    -- export
			pio_seconds_1_external_connection_export     : out std_logic_vector(6 downto 0);                    -- export
			pio_selectmode_0_external_connection_export  : in  std_logic_vector(1 downto 0) := (others => 'X'); -- export
			reset_reset_n                                : in  std_logic                    := 'X';             -- reset_n
			pio_stop_0_external_connection_export        : in  std_logic                    := 'X';             -- export
			pio_start_0_external_connection_export       : in  std_logic                    := 'X'              -- export
		);
	end component Design1;

	u0 : component Design1
		port map (
			clk_clk                                      => CONNECTED_TO_clk_clk,                                      --                                   clk.clk
			pio_miliseconds_0_external_connection_export => CONNECTED_TO_pio_miliseconds_0_external_connection_export, -- pio_miliseconds_0_external_connection.export
			pio_miliseconds_1_external_connection_export => CONNECTED_TO_pio_miliseconds_1_external_connection_export, -- pio_miliseconds_1_external_connection.export
			pio_minutes_0_external_connection_export     => CONNECTED_TO_pio_minutes_0_external_connection_export,     --     pio_minutes_0_external_connection.export
			pio_minutes_1_external_connection_export     => CONNECTED_TO_pio_minutes_1_external_connection_export,     --     pio_minutes_1_external_connection.export
			pio_seconds_0_external_connection_export     => CONNECTED_TO_pio_seconds_0_external_connection_export,     --     pio_seconds_0_external_connection.export
			pio_seconds_1_external_connection_export     => CONNECTED_TO_pio_seconds_1_external_connection_export,     --     pio_seconds_1_external_connection.export
			pio_selectmode_0_external_connection_export  => CONNECTED_TO_pio_selectmode_0_external_connection_export,  --  pio_selectmode_0_external_connection.export
			reset_reset_n                                => CONNECTED_TO_reset_reset_n,                                --                                 reset.reset_n
			pio_stop_0_external_connection_export        => CONNECTED_TO_pio_stop_0_external_connection_export,        --        pio_stop_0_external_connection.export
			pio_start_0_external_connection_export       => CONNECTED_TO_pio_start_0_external_connection_export        --       pio_start_0_external_connection.export
		);

