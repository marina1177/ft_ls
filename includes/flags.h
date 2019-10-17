//
// Created by Buster Charity on 13/10/2019.
//

#ifndef FLAGS_H
#define FLAGS_H


typedef unsigned char	t_1b;
typedef unsigned short	t_2b;
typedef unsigned int	t_4b;
typedef unsigned long	t_8b;

typedef struct				s_flags
{
	t_1b    exist : 1;
	t_2b    f_recur;
	t_2b    f_sort_t;
	t_2b    f_sort_;
	t_2b    f_output1;
	t_2b    f_output2;

}						t_flags;

#define NUMBER_FLAGS    10

/*
 ** output_flgs
 */

# define OUT_LCOL   (t_1b)0b100
# define OUT_CBCOL  (t_1b)0b010
# define OUT_1COL   (t_1b)0b001
//# define OUT_MCOL (t_1b)0b10

/*
 ** recur_flgs
 */

# define DIR_ASFI (t_1b)0b010//d
# define RECUR_LS (t_1b)0b001//R

/*
 ** sort_flgs
 */

# define SORTI_R_ (t_2b)0b10000
# define SORTI_T_ (t_2b)0b01000
# define SORTI_F_ (t_2b)0b00100
# define SORTI_SB (t_2b)0b00010// сортировать по размеру, сначала большие
# define SORTI_A_ (t_2b)0b00001

/*
 ** sort_t_flgs
 */

# define SORTI_U_ (t_1b)0b10
# define SORTI_C_ (t_1b)0b10

#endif
