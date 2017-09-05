/** \file
 * \brief Example code for Simple Open EtherCAT master
 *
 * Usage : slaveinfo [ifname] [-sdo] [-map]
 * Ifname is NIC interface, f.e. eth0.
 * Optional -sdo to display CoE object dictionary.
 * Optional -map to display slave PDO mapping
 *
 * This shows the configured slave data.
 *
 * (c)Arthur Ketels 2010 - 2011
 */

#include <stdio.h>
#include <string.h>
#include <inttypes.h>

#include "ethercat.h"

char IOmap[4096];
// ec_ODlistt ODlist;
// ec_OElistt OElist;
// boolean printSDO = FALSE;
// boolean printMAP = FALSE;
// char usdo[128];
// char hstr[1024];


char ifbuf[1024];

int main()
{
//    ec_adaptert * adapter = NULL;
    printf("SOEM (Simple Open EtherCAT Master)\nSlaveinfo\n");

    ec_init("enp0s8");
    ec_config_init(FALSE);
    ec_config_map(&IOmap);
    ec_configdc();

    // si_map_sdo(1);
    // slaveinfo("enp0s8");

    printf("Slave test: %s\n", ec_slave[1].name);
    printf("Slave test: %s\n", ec_slave[1].ec_sii[0].ec_sii_variable[0].name);

    // TODO: fix mapoffset bug
    int offset = ec_slave[1].ec_sii[1].Address + ec_slave[1].ec_sii[1].ec_sii_variable[0].abs_offset;

    printf("offset: %d\n", offset);

    int dataout[1];
    dataout[0] = 4;

    int datain[1];
    datain[0] = 0;

    // offset = 5632;

    printf("Bit Length: 0x%2.2X\n", ec_slave[1].ec_sii[1].ec_sii_variable[0].bitlen);

    printf("Output Happened? %d\n", ecx_BWR(&ecx_port,0, offset, ec_slave[1].ec_sii[1].ec_sii_variable[0].bitlen, dataout, 1000));

    printf("Recieve Happened? %d\n", ecx_BRD(&ecx_port, 0, offset, ec_slave[1].ec_sii[1].ec_sii_variable[0].bitlen, datain, 1000));

    printf("DATA: %d\n", datain[0]);

    // printf("%d\n",ec_slave[0].lp_advertising);

    // si_map_sii(1);
    

   return (0);
}
