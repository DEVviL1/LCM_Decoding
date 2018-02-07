void lcm_set_util_funcs_(LCM_UTIL_FUNCS *util)
{
  memcpy(&g_LCM_UTIL_FUNCS, util, 0x58);
}

void lcm_get_params_(LCM_PARAMS *params)
{
  LCM_PARAMS *params;

  _memzero_(params, 0x2B0);
  params->dbi.te_edge_polarity = 0;
  params->dsi.vertical_sync_active = 3;
  params->dsi.vertical_backporch = 14;
  params->dsi.vertical_frontporch = 16;
  params->dsi.horizontal_backporch = 34;
  params->dsi.horizontal_frontporch = 24;
  params->dsi.PLL_CLOCK = 210;
  params->type = 2;
  params->dsi.data_format.format = 2;
  params->dsi.PS = 2;
  params->width = 720;
  params->dsi.horizontal_active_pixel = 720;
  params->height = 1280;
  params->dsi.vertical_active_line = 1280;
  params->dbi.te_mode = 1;
  params->dsi.mode = 1;
  params->dsi.LANE_NUM = 4;
  params->dsi.horizontal_sync_active = 4;
}

void lcm_init_(void)
{
  set_reset_pin(0);
  mdelay(20);
  set_reset_pin(1);
  mdelay(20);
  dsi_set_cmdq_V3();
}

void lcm_suspend_(void)
{
  int buff[16]; 

  buff[0] = 0x280500;
  dsi_set_cmdq(buff, 1, 1);
  buff[0] = 0x100500;
  dsi_set_cmdq(buff, 1, 1);
}

void lcm_resume_(void)
{
  int buff[16];

  buff[0] = 0x290500;
  dsi_set_cmdq(buff, 1, 1);
  buff[0] = 0x110500;
  dsi_set_cmdq(buff, 1, 1);
  printk("[KERNEL]------otm1283a_hd720_dsi_vdo_tcl----%s------\n", "lcm_resume");
}

void lcm_compare_id_(void)
{
  int byte;
  char buff_2[4];
  int buff[4];

  set_reset_pin(1);
  mdelay(5);
  set_reset_pin(0);
  mdelay(30);
  set_reset_pin(1);
  mdelay(50);
  buff[0] = 0x53700;
  dsi_set_cmdq(buff, 1, 1);
  dsi_dcs_read_lcm_reg_v2(161, buff_2, 4);
  byte = buff_2[3] | (buff_2[2] << 8);
  printk("otm1283a kernel %s\n", "lcm_compare_id");
  printk("%s, id = 0x%08x\n", "lcm_compare_id", byte);
  dword_C0B54E0C = byte;
}

void lcm_esd_check_(void)
{
  char buff_2[2];
  int buff[4];

  if ( dword_C0C5B398 )
  {
    dword_C0C5B398 = 0;
  }
  else
  {
    buff[0] = 0x13700;
    dsi_set_cmdq(buff, 1, 1);
    dsi_dcs_read_lcm_reg_v2(10, buff_2, 1);
    if ( buff_2[0] != 0x9C )
    {
      printk("return true %s\n", "lcm_esd_check");
    }
    printk("return false %s\n", "lcm_esd_check");
  }
}

void lcm_esd_recover_(void)
{
  lcm_init_();
  lcm_resume_();
}
