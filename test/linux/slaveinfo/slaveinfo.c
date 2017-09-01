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

    // printf("%d\n",ec_slave[0].lp_advertising);

    // si_map_sii(1);
    

   return (0);
}
