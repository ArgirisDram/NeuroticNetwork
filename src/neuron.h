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

#ifndef __neuron_h
#define __neuron_h


/*
===========================================================================
                           Public Data Types
===========================================================================
*/

typedef struct neuron_t						/* Neuron structure */
{
	int				num_inputs;		/* The number of inputs of the neuron */
	struct neuron_t *inputs;		/* Pointers to the input neurons */
	double			*weights;		/* The weights of the inputs */
	double			output;			/* The output of the neuron */
};
typedef struct neuron_t neuron;


/*
===========================================================================
                       Public Function Prototypes
===========================================================================
*/

/* Add the values of the deltaw array to the weights of the target neuron */
/* NO ERROR CHECKING */
void neuron_deltaw		(neuron		*target,
						 double		*deltaw);

/* Set the weights of the target neuron to the values of the deltaw array */
/* NO ERROR CHECKING */
void neuron_setw		(neuron		*target,
						 double		*deltaw);

/* Calculate the output of the neuron */
/* NO ERROR CHECKING */
void neuron_activate	(neuron		*target);


/* Free the memory used by the target neuron */
/* NO ERROR CHECKING */
void neuron_free	(neuron		*target);


/* Initialize the target neuron to zeros and NULL pointers */
/* NO ERROR CHECKING */
void neuron_init	(neuron		*target);
#endif
