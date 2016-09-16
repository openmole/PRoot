/* -*- c-set-style: "K&R"; c-basic-offset: 8 -*-
 *
 * This file is part of PRoot.
 *
 * Copyright (C) 2014 STMicroelectronics
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301 USA.
 */

 #ifndef PORTMAP_H
 #define PORTMAP_H

 #include "extension/extension.h"

 #define PORTMAP_SIZE 4096  /* must be a power of 2 */
 #define PORTMAP_DEFAULT_VALUE 0  /* default value that indicates an unused entry */
 #define PORTMAP_VERBOSITY 1

 typedef struct PortMapEntry {
   uint16_t port_in;
   uint16_t port_out;
 } PortMapEntry;

 typedef struct PortMap {
   PortMapEntry map[PORTMAP_SIZE];
   uint16_t table_mask;
 } PortMap;

void initialize_portmap(PortMap *portmap);
uint16_t get_index(PortMap *portmap, uint16_t key);
int add_entry(PortMap *portmap, uint16_t port_in, uint16_t port_out);
uint16_t get_port(PortMap *portmap, uint16_t port_in);

int add_portmap_entry(uint16_t port_in, uint16_t port_out);
int activate_netcoop_mode();

 #endif /* PORTMAP_H */
