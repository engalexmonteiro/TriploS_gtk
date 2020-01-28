/*
 * midiscovery.h
 *
 *  Created on: 05/03/2013
 *      Author: alex
 */

#ifndef MIDISCOVERY_H_
#define MIDISCOVERY_H_

#include "iwlib.h"
#include <stdio.h>
#include <stdlib.h>

#include <sys/socket.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/hci.h>
#include <bluetooth/hci_lib.h>

#define CANAL 14

typedef struct wireless_scan_mi
{
  /* Linked list */
  struct wireless_scan_mi *	next;

  /* Device identification */
  int 		type;					/* Bluetooth or Wi-fi */
  char		mac_address[50];		/* Access point address */
  char		essid[50];				/* Access point address */
  int		key;
  int 		canal;					/* Channel for wi-fi */
  float 	frequencia;				/* Frequence for wi-fi */
  float		qualidade;				/* Quality for wi-fi */
  int		nivel;					/* Level for bluetooth or wi-fi */
  int 		maxbitrate;				/* Maxbitrate for wi-fi */
  char 		modo[50];				/* Mode for blueooth: slave or master and wi-fi */
  float 	factor_overlap;			/* Factor of Overlap */
  int		score_snr;

} wireless_scan_mi;

/*
 * Context used for non-blocking scan.
 */
typedef struct wireless_scan_mi_list
{
  wireless_scan_mi*		head_list;				/* Result of the scan */
  wireless_scan_mi*		end_list;
  int 					channel_util[CANAL];	/* Canais utilizados 802.11 */
  float 				fator_sobreposicao[CANAL];	/* Canais utilizados 802.11 */
  int					size_list;		        /* Tamanho da lista */
  int 					factor_diversity;

} wireless_scan_mi_list;

int iw_scan_mi(wireless_scan_mi_list* list);  /*Return linked list of All devices wi-fi / bluetooth*/

int iw_scan_wifi(wireless_scan_mi_list* list);

int iw_scan_wifiv2(wireless_scan_mi_list* list);

int score_net_snr(wireless_scan_mi_list* list);

int iw_scan_bluetooth(wireless_scan_mi_list* list);

int print_scan_mi(wireless_scan_mi_list* list);

int print_classi_network(wireless_scan_mi_list* list);

void limpar_scan_mi(wireless_scan_mi_list* list);


#endif /* MIDISCOVERY_H_ */
