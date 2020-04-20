/***********************************************************
   Copyright 2020 Tallac Networks, Inc.

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

     http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.

************************************************************/
#ifndef TOPO_H
#define TOPO_H

#define P_UPLINK		0
#define P_DOWNLINK		1
#define P_CROSSLINK		2
#define P_UNKNOWN		-1

#define N_BRIDGE        1
#define N_SERVER        2

#define MAX_BRIDGE_PORTS	48

#define MAX_SIM_TIME        100
#define SIM_START_DELAY     10

typedef struct port {
    int 		id;
    void        *node;
    struct port	*peer;
    int		    pattr;
    int         status;         // down = 0, up = 1
    int         last_tx_time;
    int         tx_credit;
    int         tx_fast;
    int         last_peer_node_type;
    int         last_peer_level;
    int         last_peer_pattr;
    int         my_last_pattr;
    void        *next_ev;
} port_t;

typedef struct node {
    struct node *next;
    int		    id;
    int         node_type; 
    port_t		ports[MAX_BRIDGE_PORTS];
    int         port_ct;
    int		    level;
    int         my_last_node_type;
    int         my_last_level;
    int         status;         // down = 0, up = 1
} node_t;


// Global Variables

extern int algorithm;
extern int maxsim;
extern int start_delay;

#endif
