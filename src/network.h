/*
Authors: Alexandros Tsonis, Sotiris Papatheodorou

This file is part of NeuroticNetwork.

    NeuroticNetwork is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    NeuroticNetwork is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with NeuroticNetwork.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _network_h
#define _network_h
#define _RETURN_SUCCESS 1
#define _CREATION_MEMORY_ERROR 2
#include "neuron.h"
#include <stdlib.h>
#include <stdio.h>


/* 
===========================================================================
                           Still a prototype
                           Subject to change
===========================================================================
*/

/*
===========================================================================
                           Public Data Types
===========================================================================
*/

struct neural_net{                                 //Network Struct
        int                 num_of_inputs;             //Number of inputs of structure
        int                 num_of_layers;             //Number of layers in the neural network
        int                 sum_of_neurons;            //Sum of neurons in network (Inputs are treated as neurons)
        int                 *neurons_per_layer;        //Table of neurons per layer
        neuron              *neuron_table;             //Table of network interconnects (1 dimensional)
};

/*
===========================================================================
                       Public Function Prototypes
===========================================================================
*/
/*Create a network*/
/*Returns address of neural_net struct*/
/*TO-DO: MAKE THIS VARADIC*/
/*NO ERROR CHECKING*/
int create_network         (int                     num_of_inputs,
                            int                     num_of_layers,
                            int                     *neurons_per_layer,//make this argument optional
                            struct neural_net       **network_addr);

/*Change the input vector of the network*/
/*NO ERROR CHECKING*/
void change_input          (double                  *input_vector,
                            struct neural_net       *network_addr);

/* Calculate the output of network */
/* Calculation from the input layers to the output serially */
/* NO ERROR CHECKING*/
void network_activate      (struct neural_net       *network);

/* Add the values of the deltaw array to the weight array of a single neuron */
/* NO ERROR CHECKING */
void network_delta         (struct neural_net       *network,
                            int                     layer_pointer,
                            int                     neuron_pointer,
                            double                  *deltaw);

/* Set the weights of a neuron in the network equal to the deltaw array */
/* NO ERROR CHECKING */
void network_setw          (struct neural_net       *network,
                            int                     layer_pointer,
                            int                     neuron_pointer,
                            double                  *deltaw);

/* Delete the network */
/* NO ERROR CHECKING */
void network_delete          (struct neural_net       *network);


/*Error back propagation*/
/*NO ERROR CHECKING*/
void errorback               (struct neural_net       *network,
                              double                  *intended_output);

void normalize_weights       (struct neural_net       *network);

void print_weights           (struct neural_net       *network);
#endif

