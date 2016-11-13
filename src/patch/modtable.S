
//Address      Function     Instruction       
//-------      --------     -----------       
//ROM:1005C810 sub_1005C6DC DCD dword_10161890
//ROM:1005CBF0              DCD dword_10161890
//ROM:1005D0A8              DCD dword_10161890
//ROM:10064FBC sub_10064F2C DCD dword_10161890
//ROM:10065438 sub_1006538C DCD dword_10161890

	//这里修改了游戏的升级经验表，改了5处引用指针

	XXPATCH16PTR32(0x1005C810, ExpTableMod)
	XXPATCH16PTR32(0x1005CBF0, ExpTableMod)
	XXPATCH16PTR32(0x1005D0A8, ExpTableMod)
	XXPATCH16PTR32(0x10064FBC, ExpTableMod)
	XXPATCH16PTR32(0x10065438, ExpTableMod)


	//这里修改了游戏的装备属性参数表，改了8处引用指针
	XXPATCH16PTR32(0x10023A90, g_equip_attr_table_mod)
	XXPATCH16PTR32(0x10024014, g_equip_attr_table_mod)
	XXPATCH16PTR32(0x1002C2C0, g_equip_attr_table_mod)
	XXPATCH16PTR32(0x1002C8EC, g_equip_attr_table_mod)
	XXPATCH16PTR32(0x1002CFB0, g_equip_attr_table_mod)
	XXPATCH16PTR32(0x1002D5EC, g_equip_attr_table_mod)
	XXPATCH16PTR32(0x1009CFBC, g_equip_attr_table_mod)
	XXPATCH16PTR32(0x101136B0, g_equip_attr_table_mod)
