SET(SOURCES ui_start_screen.c
    ui_menu.c
    ui_heavyfire.c
    ui_ranking.c
    ui_settings.c
    ui_PROGRAMS.c
    ui_coverfire.c
    ui_dynamic.c
    ui_training.c
    ui_hostage.c
    ui.c
    ui_comp_hook.c
    ui_helpers.c
    ui_events.c
    ui_img_start_screen2_png.c
    ui_img_ranking_png.c
    ui_img_widget_settings_png.c
    ui_img_widget_programs_png.c
    ui_img_mk_png.c
    ui_img_trainig_png.c
    ui_img_cover_fire_png.c
    ui_img_dynamic_png.c
    ui_img_hostage_png.c
    ui_img_heavy_fire_png.c
    fonts/ui_font_tactic16.c
    fonts/ui_font_tactic40.c)

add_library(ui ${SOURCES})
