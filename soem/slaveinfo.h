void slaveinfo(char *ifname);
int si_map_sdo(int slave);
int si_map_sii(int slave);
int populateSi_map_sii(int slave, ecx_contextt *context);

typedef struct ec_slave_outputs
{
    uint8           SlaveMaster;
    uint16          address;
}ec_slave_outputs;
