//! Operation codes.
typedef enum spc1000_op_e
{
	spc1000_op_standby 	= 0x00,
	spc1000_op_read_indirect,
	spc1000_op_write_indirect,
	spc1000_op_read_eeprom 	= 0x05,
	spc1000_op_write_eeprom,
	spc1000_op_init,
	spc1000_op_high_speed_acq_start 	= 0x09,
	spc1000_op_high_resolution_acq_start,
	spc1000_op_ultra_low_power_acq_start,
	spc1000_op_low_power_acq_start,
	spc1000_op_self_test = 0x0F
} spc1000_op_t;
