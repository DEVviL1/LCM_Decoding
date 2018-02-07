void lcm_set_util_funcs_(LCM_UTIL_FUNCS *utils)
{
  memcpy_(&g_LCM_UTIL_FUNCS, utils, 0x50);
}

void lcm_get_params_(LCM_PARAMS *params)
{
  _memzero_(params, 0x220);
  params->type = 2;
  params->dsi.data_format.format = 2;
  params->dsi.PS = 2;
  params->dsi.vertical_sync_active = 2;
  params->width = 720;
  params->dsi.vertical_backporch = 16;
  params->height = 1280;
  params->dsi.vertical_frontporch = 9;
  params->dsi.mode = 1;
  params->dsi.horizontal_sync_active = 36;
  params->dsi.LANE_NUM = 4;
  params->dsi.vertical_active_line = 1280;
  params->dsi.horizontal_backporch = 90;
  params->dsi.horizontal_frontporch = 90;
  params->dsi.horizontal_active_pixel = 720;
  params->dsi.PLL_CLOCK = 230;
  params->dsi.ssc_disable = 1;
}

void lcm_init_()
{
  int data_array[16]; // [sp+0h] [bp-64h]

  set_reset_pin(1);
  mdelay(5);
  set_reset_pin(0);
  mdelay(10);
  set_reset_pin(1);
  mdelay(180);
  data_array[0] = 0x43902;
  data_array[1] = 0x9483FFB9;
  dsi_set_cmdq(data_array, 2, 1);
  mdelay(5);
  data_array[0] = 0x33902;
  data_array[1] = 0x8373BA;
  dsi_set_cmdq(data_array, 2, 1);
  mdelay(1);
  data_array[0] = 0x103902;
  data_array[1] = 0x12126AB1;
  data_array[2] = 0xF111E424;
  data_array[3] = 0x239DE480;
  data_array[4] = 0x58D2C080;
  dsi_set_cmdq(data_array, 5, 1);
  mdelay(1);
  data_array[0] = 0xC3902;
  data_array[1] = 0x106400B2;
  data_array[2] = 0x81C1207;
  data_array[3] = 0x4D1C08;
  dsi_set_cmdq(data_array, 4, 1);
  mdelay(1);
  data_array[0] = 0xD3902;
  data_array[1] = 0x3FF00B4;
  data_array[2] = 0x35A035A;
  data_array[3] = 0x16A015A;
  data_array[4] = 0x6A;
  dsi_set_cmdq(data_array, 5, 1);
  mdelay(1);
  data_array[1] = 0x55D2;
  data_array[0] = 0x23902;
  dsi_set_cmdq(data_array, 2, 1);
  mdelay(1);
  data_array[0] = 0x43902;
  data_array[1] = 0x10E41BF;
  dsi_set_cmdq(data_array, 2, 1);
  mdelay(1);
  data_array[0] = 0x263902;
  data_array[1] = 0x600D3;
  data_array[2] = 0x81A40;
  data_array[3] = 0x71032;
  data_array[4] = 0xF155407;
  data_array[5] = 0x12020405;
  data_array[6] = 0x33070510;
  data_array[7] = 0x370B0B33;
  data_array[8] = 0x8070710;
  data_array[10] = 0x100;
  data_array[9] = 0xA000000;
  dsi_set_cmdq(data_array, 11, 1);
  mdelay(1);
  data_array[2] = 0x1B1A1A18;
  data_array[4] = 0x2010007;
  data_array[6] = 0x18181818;
  data_array[0] = 0x2D3902;
  data_array[12] = 0x18;
  data_array[1] = 0x181919D5;
  data_array[3] = 0x605041B;
  data_array[5] = 0x18212003;
  data_array[7] = 0x18181818;
  data_array[8] = 0x22181818;
  data_array[10] = 0x18181818;
  data_array[9] = 0x18181823;
  data_array[11] = 0x18181818;
  dsi_set_cmdq(data_array, 13, 1);
  mdelay(1);
  data_array[2] = 0x1B1A1A19;
  data_array[4] = 0x5060700;
  data_array[6] = 0x18181818;
  data_array[0] = 0x2D3902;
  data_array[12] = 0x18;
  data_array[1] = 0x191818D6;
  data_array[3] = 0x102031B;
  data_array[5] = 0x18222304;
  data_array[7] = 0x18181818;
  data_array[8] = 0x21181818;
  data_array[10] = 0x18181818;
  data_array[9] = 0x18181820;
  data_array[11] = 0x18181818;
  dsi_set_cmdq(data_array, 13, 1);
  mdelay(1);
  data_array[0] = 0x2C3902;
  data_array[1] = 0x171204E0;
  data_array[2] = 0x213E3330;
  data_array[3] = 0xC0A073C;
  data_array[4] = 0x13110D17;
  data_array[5] = 0x12081311;
  data_array[6] = 0x12041A16;
  data_array[7] = 0x3E333017;
  data_array[8] = 0xA073C21;
  data_array[9] = 0x110D170C;
  data_array[10] = 0x8131113;
  data_array[11] = 0x1A1612;
  dsi_set_cmdq(data_array, 12, 1);
  mdelay(1);
  data_array[0] = 0x33902;
  data_array[1] = 0x6565B6;
  dsi_set_cmdq(data_array, 2, 1);
  mdelay(1);
  data_array[1] = 0x9CC;
  data_array[0] = 0x23902;
  dsi_set_cmdq(data_array, 2, 1);
  mdelay(1);
  data_array[0] = 0x53902;
  data_array[1] = 0x40C000C7;
  data_array[2] = 0xC0;
  dsi_set_cmdq(data_array, 3, 1);
  mdelay(1);
  data_array[1] = 0x87DF;
  data_array[0] = 0x23902;
  dsi_set_cmdq(data_array, 2, 1);
  mdelay(1);
  data_array[0] = 0x110500;
  dsi_set_cmdq(data_array, 1, 1);
  mdelay(150);
  data_array[0] = 0x290500;
  dsi_set_cmdq(data_array, 1, 1);
  mdelay(20);
}

void lcm_suspend_()
{
  int buff[16]; // [sp+0h] [bp-54h]

  buff[0] = 0x280500;
  dsi_set_cmdq(buff);
  mdelay(10);
  buff[0] = 0x100500;
  dsi_set_cmdq(buff);
  mdelay(120);
  set_reset_pin(1);
  mdelay(10);
  set_reset_pin(0);
  mdelay(10);
  set_reset_pin(1);
  mdelay(120);
}

void lcm_resume_()
{
  lcm_init_();
  printk("[KERNEL]---cmd---hx8394a_hd720_dsi_vdo_tianma----%s------\n", 0xC0768474);// ROM:C0768474 aLcmResume      DCB "lcm_resume",0
}

bool lcm_compare_id_()
{
  bool result; // r0
  char buff_2[3]; // [sp+5h] [bp-57h]
  int buff[16]; // [sp+8h] [bp-54h]

  set_reset_pin(1u);
  mdelay(10);
  set_reset_pin(0);
  mdelay(10);
  set_reset_pin(1u);
  mdelay(20);
  buff[0] = 0x43902;
  buff[1] = 0x9483FFB9;
  dsi_set_cmdq(buff, 2, 1);
  mdelay(10);
  buff[0] = 0x33902;
  buff[1] = 0x8373BA;
  dsi_set_cmdq(buff, 2, 1);
  mdelay(5);
  buff[0] = 0x33700;
  dsi_set_cmdq(buff, 1, 1);
  (dsi_dcs_read_lcm_reg_v2)(4, buff_2, 3);
  if ( buff_2[0] == 0x83 )
    result = buff_2[1] - 0x94 <= 0;
  else
    result = 0;
  return result;
}

int lcm_esd_check_()
{
  int result; // r0
  unsigned __int8 buff_3; // [sp+2h] [bp-2Ah]
  char buff_2[5]; // [sp+3h] [bp-29h]
  int buff[4]; // [sp+8h] [bp-24h]

  buff[0] = 0x43902;
  buff[1] = 0x9483FFB9;
  dsi_set_cmdq(buff, 2, 1);
  buff[0] = 0x33902;
  buff[1] = 0x8373BA;
  dsi_set_cmdq(buff, 2, 1);
  buff[0] = 0x43700;
  dsi_set_cmdq(buff, 1, 1);
  (dsi_dcs_read_lcm_reg_v2)(9, &buff_2[1], 4);
  buff[0] = 0x13700;
  dsi_set_cmdq(buff, 1, 1);
  (dsi_dcs_read_lcm_reg_v2)(217, &buff_3, 1);
  buff[0] = 0x13700;
  dsi_set_cmdq(buff, 1, 1);
  (dsi_dcs_read_lcm_reg_v2)(10, buff_2, 1);
  if ( buff_2[1] != 0x80 || buff_2[2] != 0x73 || buff_2[3] != 4 || buff_2[4] || buff_2[0] != 0x1C )
    return 1;
  result = buff_3 - 0x80;
  if ( buff_3 != 0x80 )
    result = 1;
  return result;
}

signed int lcm_esd_recover_()
{
  printk("miles---> [FUNC]:%s [LINE]:%d\n", "lcm_esd_recover", 725);
  lcm_resume_();
  return 1;
}

