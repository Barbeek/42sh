/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 16:58:11 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/26 20:30:34 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

/*
** Defines
*/

# define SH_NAME		"42sh"
# define DEFAULT_TERM	"xterm-256color"

# define FD_EDL			0
# define FD_PRO			2
# define FD_IN			0
# define FD_OUT			1
# define FD_ERR			2

/*
**	Flag utilise lors de l'expansion des variables
*/

# define STR_FORMAT		0
# define NBR_FORMAT		1

/*
** Options et masques
*/

# define SH_OPTIONS		"d"
# define OP_D			1

# define ALIAS_OPTIONS	"p"
# define AL_OP_P		1

# define HASH_OPTIONS	"r"
# define HA_OP_R		1

/*
** Line editor keys
**
** LINE_UP      Maj + up arrow
** LINE_DOWN    Maj + down arrow
** HOME         Fn + left arrow
** END          Fn + right arrow
** SELECT       alt + v
** COPY         alt + c
** PASTE        alt + p
** CUT          alt + d
** CTRLD        ctrl + d
*/

# define K_ENTER		0x0A
# define K_TAB			0x09
# define K_SHIFT_TAB	0x5A5B1B
# define K_BACKDEL		0x7F
# define K_DEL			0x7E335B1B
# define K_UP			0x415B1B
# define K_DOWN			0x425B1B
# define K_SH_UP		0x41323B315B1B
# define K_SH_DOWN		0x42323B315B1B
# define K_SH_LEFT		0x44323B315B1B
# define K_SH_RIGHT		0x43323B315B1B
# define K_LEFT			0x445B1B
# define K_RIGHT		0x435B1B
# define K_HOME			0x485B1B
# define K_END			0x465B1B
# define K_ALT_X		0x8889E2
# define K_ALT_C		0xA7C3
# define K_ALT_V		0x9A88E2
# define K_CTRL_D		0x04
# define K_ALT_LEFT		0x445B1B1B
# define K_ALT_RIGHT	0x435B1B1B

/*
** TOKENS :
**
** Words
*/

# define WORD					1
# define ASSIGNEMENT			2

# define IO_NUMBER				3

# define TRIPLELESS				0x3C3C3C
# define TRIPLEGREAT			0x3E3E3E
# define DOUBLELESSDASH			0x2D3C3C
# define DOUBLELESSAND			0x263C3C
# define DOUBLEGREATAND			0x263E3E
# define ANDDOUBLEGREAT			0x3E3E26
# define ANDDOUBLELESS			0x3C3C26
# define DOUBLESEMICOLONAND		0x263B3B
# define DOUBLEAND				0x2626
# define DOUBLEPIPE				0x7C7C
# define DOUBLESEMICOLON		0x3B3B
# define DOUBLELESS				0x3C3C
# define DOUBLEGREAT			0x3E3E
# define LESSGREAT				0x3E3C
# define LESSAND				0x263C
# define GREATAND				0x263E
# define ANDGREAT				0x3E26
# define ANDLESS				0x3C26
# define GREATPIPE				0x7C3E
# define PIPEAND				0x267C
# define SEMICOLONAND			0x263B
# define PIPE					0x7C
# define AND					0x26
# define SEMICOLON				0x3B
# define LESS					0x3C
# define GREAT					0x3E
# define OP_PAR					0x28
# define CL_PAR					0x29
# define OP_BRA					0x7B
# define CL_BRA					0x7D
# define BANG					0x21
# define NEWLINE				0xA

/*
** Incomplete command types
*/

# define COMPLETE			0
# define INC_EMPTY			1
# define INC_BKS			2

# define INC_SQT			3
# define INC_DQT			4
# define INC_BTK			5

# define INC_PAR			6
# define INC_BRA			7

# define INC_AND			8
# define INC_OR				9
# define INC_PIP			10

# define INC_HER			11
# define INC_HER_BKS		12

/*
** Prompts
*/

# define TTY_DFLT				" » "
# define TTY_DFLT_L				3

# define TTY_BKS 				"\\n \\ "
# define TTY_BKS_L				5

# define TTY_SQT 				"' \\ "
# define TTY_SQT_L				4
# define TTY_DQT 				"\" \\ "
# define TTY_DQT_L				4
# define TTY_BTK 				"` \\ "
# define TTY_BTK_L				4

# define TTY_PAR				"( \\ "
# define TTY_PAR_L				4
# define TTY_BRA				"{ \\ "
# define TTY_BRA_L				4

# define TTY_AND				"&& \\ "
# define TTY_AND_L				5
# define TTY_OR					"|| \\ "
# define TTY_OR_L				5
# define TTY_PIP				"| \\ "
# define TTY_PIP_L				4

# define TTY_HER 				"here \\ "
# define TTY_HER_L				7

# define TTY_HER_BKS 			"her\\ \\ "
# define TTY_HER_BKS_L			7

/*
** Return / Exit codes
*/

# define OK			            0
# define ERROR		            1
# define MAJOR_ERROR			2
# define PERMISSION_DENIED		126
# define NOT_FOUND				127
# define SYNTAX_ERROR		    258

/*
** Textes
*/

# define TXT_UNEX_WHILE			"unexpected EOF while looking for matching"
# define TXT_SYN_ERR			"syntax error"
# define TXT_UNEX_EOF			"unexpected end of file"

/*
** Arithmetics
*/

# define NUMBER				11
# define VARIABLE			12
# define INVALID			13

# define DOUBLEEQUAL		0x3D3D
# define BANGEQUAL			0x3D21
# define LESSEQUAL			0x3D3C
# define GREATEQUAL			0x3D3E
# define DOUBLEPLUS			0x2B2B
# define DOUBLEMINUS		0x2D2D

# define PLUS				0x2B
# define MINUS				0x2D
# define STAR				0x2A
# define PERCENT			0x25
# define SLASH				0x2F

#endif
