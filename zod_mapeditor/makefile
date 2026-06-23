JOBS=$(shell nproc 2>/dev/null || echo 4)
MAKEFLAGS=-j$(JOBS)

CFLAGS=-g `sdl-config --cflags` -I../zod_engine -D DISABLE_OPENGL -D DISABLE_REGCHECK
LDFLAGS=`sdl-config --libs` -lSDL_image -lSDL_mixer -lSDL_ttf -lm -lmysqlclient
SRC=../zod_engine

CPPFILES = \
	$(SRC)/common.cpp $(SRC)/zsdl.cpp $(SRC)/event_handler.cpp \
	$(SRC)/socket_handler.cpp $(SRC)/server_socket.cpp $(SRC)/client_socket.cpp \
	$(SRC)/zhud.cpp $(SRC)/zfont_engine.cpp $(SRC)/zfont.cpp $(SRC)/zmini_map.cpp \
	$(SRC)/cursor.cpp $(SRC)/zgui_window.cpp $(SRC)/zbuildlist.cpp \
	$(SRC)/zsound_engine.cpp $(SRC)/zmusic_engine.cpp $(SRC)/zcomp_message_engine.cpp \
	$(SRC)/zpath_finding.cpp $(SRC)/zpath_finding_astar.cpp $(SRC)/zsettings.cpp \
	$(SRC)/zsdl_opengl.cpp $(SRC)/zportrait.cpp $(SRC)/zteam.cpp $(SRC)/ztray.cpp \
	$(SRC)/zmysql.cpp $(SRC)/zpsettings.cpp $(SRC)/ztime.cpp $(SRC)/zvote.cpp \
	$(SRC)/zunitrating.cpp $(SRC)/zencrypt_aes.cpp $(SRC)/zolists.cpp \
	$(SRC)/zgui_main_menu_base.cpp $(SRC)/zgui_main_menu_widget.cpp $(SRC)/zgfile.cpp \
	$(SRC)/zcore.cpp $(SRC)/zserver.cpp $(SRC)/zserver_events.cpp $(SRC)/zserver_commands.cpp \
	$(SRC)/zclient.cpp $(SRC)/zplayer.cpp $(SRC)/zplayer_events.cpp $(SRC)/zbot.cpp \
	$(SRC)/zbot_events.cpp $(SRC)/SDL_rotozoom.cpp \
	$(SRC)/ebullet.cpp $(SRC)/elaser.cpp $(SRC)/eflame.cpp $(SRC)/epyrofire.cpp \
	$(SRC)/etoughrocket.cpp $(SRC)/etoughmushroom.cpp $(SRC)/etoughsmoke.cpp \
	$(SRC)/elightrocket.cpp $(SRC)/elightinitfire.cpp $(SRC)/emomissilerockets.cpp \
	$(SRC)/emissilecrockets.cpp $(SRC)/erobotdeath.cpp $(SRC)/edeath.cpp \
	$(SRC)/estandard.cpp $(SRC)/edeathsparks.cpp $(SRC)/eturrentmissile.cpp \
	$(SRC)/esideexplosion.cpp $(SRC)/ecannondeath.cpp $(SRC)/eunitparticle.cpp \
	$(SRC)/erockparticle.cpp $(SRC)/erockturrent.cpp $(SRC)/emapobjectturrent.cpp \
	$(SRC)/ebridgeturrent.cpp $(SRC)/ecraneconco.cpp $(SRC)/erobotturrent.cpp \
	$(SRC)/etrack.cpp $(SRC)/etankdirt.cpp $(SRC)/etanksmoke.cpp $(SRC)/etankoil.cpp \
	$(SRC)/etankspark.cpp \
	$(SRC)/zmap.cpp $(SRC)/zmap_crater_graphics.cpp $(SRC)/zeffect.cpp \
	$(SRC)/zobject.cpp $(SRC)/zrobot.cpp $(SRC)/zbuilding.cpp $(SRC)/zcannon.cpp \
	$(SRC)/zvehicle.cpp $(SRC)/oflag.cpp $(SRC)/orock.cpp $(SRC)/ogrenades.cpp \
	$(SRC)/orockets.cpp $(SRC)/ohut.cpp $(SRC)/omapobject.cpp $(SRC)/abird.cpp \
	$(SRC)/ahutanimal.cpp \
	$(SRC)/rgrunt.cpp $(SRC)/rpsycho.cpp $(SRC)/rtough.cpp $(SRC)/rsniper.cpp \
	$(SRC)/rpyro.cpp $(SRC)/rlaser.cpp \
	$(SRC)/bfort.cpp $(SRC)/brobot.cpp $(SRC)/bvehicle.cpp $(SRC)/bradar.cpp \
	$(SRC)/brepair.cpp $(SRC)/bbridge.cpp \
	$(SRC)/vjeep.cpp $(SRC)/vlight.cpp $(SRC)/vmedium.cpp $(SRC)/vheavy.cpp \
	$(SRC)/vmissilelauncher.cpp $(SRC)/vapc.cpp $(SRC)/vcrane.cpp \
	$(SRC)/cgatling.cpp $(SRC)/cgun.cpp $(SRC)/chowitzer.cpp $(SRC)/cmissilecannon.cpp \
	$(SRC)/gwproduction.cpp $(SRC)/gwproduction_fus.cpp $(SRC)/gwproduction_us.cpp \
	$(SRC)/gwlogin.cpp $(SRC)/gwcreateuser.cpp $(SRC)/gwfactory_list.cpp \
	$(SRC)/gmm_change_teams.cpp $(SRC)/gmm_main_menu.cpp $(SRC)/gmm_manage_bots.cpp \
	$(SRC)/gmm_player_list.cpp $(SRC)/gmm_select_map.cpp $(SRC)/gmm_options.cpp \
	$(SRC)/gmm_warning.cpp $(SRC)/gmmw_button.cpp $(SRC)/gmmw_label.cpp \
	$(SRC)/gmmw_list.cpp $(SRC)/gmmw_team_color.cpp $(SRC)/gmmw_radio.cpp

DATE = `date +%m-%d-%y`

default: zod_map_editor tile_info_editor map_merger

zod_map_editor:
	$(CXX) $(CFLAGS) -o zod_map_editor $(CPPFILES) map_editor.cpp $(LDFLAGS)

tile_info_editor:
	$(CXX) $(CFLAGS) -o tile_info_editor $(CPPFILES) tile_info_editor.cpp $(LDFLAGS)

map_merger:
	$(CXX) $(CFLAGS) -o map_merger $(CPPFILES) map_merger.cpp $(LDFLAGS)

clean:
	rm -f zod_map_editor tile_info_editor map_merger

zip:
	zip zod_map_editor_src_${DATE}.zip *.cpp *.h makefile arial.ttf
