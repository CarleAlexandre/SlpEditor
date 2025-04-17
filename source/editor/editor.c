#define RAYGUI_IMPLEMENTATION
#include "editor.h"

int main_entry(int argc, char** argv) {
	assert(argc > 1);
	context ctx = {0};
	ctx.font_scale = 20;
	ctx.ligature = false;
	ctx.line = false;
	ctx.line_relative = false;

	text txt = {0};
	char* data = LoadFileText(argv[1]);
	assert(data);
	txt.raw = LoadCodepoints(data, &txt.count);
	assert(txt.raw);
	UnloadFileText(data);

	InitWindow(1920, 1080, argv[1]);

	ctx.font = LoadFontEx("firacode.ttf", 36, txt.raw, txt.count);
	SetTextureFilter(ctx.font.texture, TEXTURE_FILTER_TRILINEAR);
	SetTextLineSpacing(0);

	SetTargetFPS(120);
	while (!WindowShouldClose()) {
		BeginDrawing(); {
		ClearBackground(BLACK);
		DrawTextCodepoints(ctx.font, txt.raw, txt.count, (Vector2){0, 0}, ctx.font_scale, 1, WHITE);
		} EndDrawing();
	}

	UnloadCodepoints(txt.raw);
	UnloadFont(ctx.font);
	CloseWindow();
	return (1);
}
