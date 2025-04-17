#ifndef EDITOR_H
# define EDITOR_H

#include <raylib.h>
#include <assert.h>
#include <raymath.h>
#include <raygui.h>
#include <stdint.h>
#include <string.h>

typedef struct {
	Font	font;
	bool	ligature;
	bool	line;
	bool	line_relative;
	int	font_scale;
}	context;

typedef struct {
	int*	raw;
	int	count;
	Vector2	cursor_pos;
	bool	synced;
	int*	original;
	int*	edit;
}	text;

typedef struct {
	int	buffer;
	int	index;
	int	length;
}	operation;

typedef operation* table;

#endif

/*
	buffer original [0000000]
	buffer edit [000000]

	table operation []

	list buffer render operation(original + edit)<-- apply lexer and use for render
	on save apply edit to original and clear table
*/
