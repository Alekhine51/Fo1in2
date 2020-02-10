/*
	Copyright 1998-2003 Interplay Entertainment Corp.  All rights reserved.
*/

#ifndef CVGENENC_H
#define CVGENENC_H
/*
    This file contains generic information for the cave random encounters
*/

variable
   i,

   encounter_pid1 := 0,
   encounter_pid2 := 0,
   encounter_pid3 := 0,
   encounter_pid4 := 0,
   encounter_pid5 := 0,
   encounter_pid6 := 0,

   encounter_sid1 := 0,
   encounter_sid2 := 0,
   encounter_sid3 := 0,
   encounter_sid4 := 0,
   encounter_sid5 := 0,
   encounter_sid6 := 0,

   active_encounter_pids := 0,
   total_encounter_mobs := 0, //Per area in map

   special_spawn_critters := 1,
   special_spawn_container := 0,

   choose_enc_pid := 0,
   choose_enc_sid := 0,

   Area_List, Chest_List, SceneryPos_List, Items_List,
   Choose_Scenery,
   Scenery_Chance,
   Active_Scenery_List := 1,
   Scenery1_Range, Scenery1_List, Scenery1_Script := -1,
   Scenery2_Range, Scenery2_List, Scenery2_Script := -1,
   Scenery3_Range, Scenery3_List, Scenery3_Script := -1;

procedure Choose_Encounter begin
   variable
      val := Random(1, 4),
      rnd_chest := random(1, 100),
      rnd_critter;

   if (rnd_chest < 60 and (stat_success(dude_obj, STAT_lu, 0))) then
      special_spawn_container := 1;
   else
      special_spawn_container := 0;

   // Geckos
   if (val == 1) then begin
      active_encounter_pids := 1;
      rnd_critter := random(1, 100);
      if (rnd_critter < 65) then begin
         encounter_pid1 := PID_GECKO;
         encounter_sid1 := SCRIPT_ECGECKO;
         if (random(0, 4) == 1) then begin
            encounter_pid2 := PID_GOLDEN_GECKO;
            encounter_sid2 := SCRIPT_ECGECKO;
            active_encounter_pids := 2;
         end
         total_encounter_mobs := Random(1, 3);
      end else if (rnd_critter < 80) then begin
         encounter_pid1 := PID_GOLDEN_GECKO;
         encounter_sid1 := SCRIPT_ECGECKO;
         total_encounter_mobs := Random(2, 3);
      end else begin
         encounter_pid1 := PID_FIRE_GECKO;
         encounter_sid1 := SCRIPT_ECGECKO;
         total_encounter_mobs := Random(2, 4);
      end
   end

   // Radscorpions
   else if (val == 2) then begin
      active_encounter_pids := 1;
      rnd_critter := random(1, 100);
      if (rnd_critter < 50) then begin
         encounter_pid1 := PID_SMALL_RADSCORPION;
         encounter_sid1 := SCRIPT_RADSCORP;
         total_encounter_mobs := Random(3, 5);
      end else if (rnd_critter < 75) then begin
         active_encounter_pids := 1;
         encounter_pid1 := PID_RADSCORPION;
         encounter_sid1 := SCRIPT_RADSCORP;
         total_encounter_mobs := Random(3, 5);
      end else begin
         active_encounter_pids := 2;
         encounter_pid1 := PID_SMALL_RADSCORPION;
         encounter_sid1 := SCRIPT_RADSCORP;
         encounter_pid2 := PID_RADSCORPION;
         encounter_sid2 := SCRIPT_RADSCORP;
         total_encounter_mobs := Random(3, 5);
      end
   end

   // Rats
   else if (val == 3) then begin
      active_encounter_pids := 1;
      rnd_critter := random(1, 100);

      if (rnd_critter < 50) then begin
         encounter_pid1 := PID_RAT_CAVE;
         encounter_sid1 := SCRIPT_WANRATS;
         total_encounter_mobs := Random(3, 5);
      end else if (rnd_critter < 75) then begin
         active_encounter_pids := 1;
         encounter_pid1 := PID_PIGRAT;
         encounter_sid1 := SCRIPT_WANRATS;
         total_encounter_mobs := Random(2, 4);
      end else begin
         active_encounter_pids := 2;
         encounter_pid1 := PID_GREATER_MOLE_RAT;
         encounter_sid1 := SCRIPT_WANRATS;
         encounter_pid2 := PID_PIGRAT;
         encounter_sid2 := SCRIPT_WANRATS;
         total_encounter_mobs := 4;
      end
   end

   // Ants
   else if (val == 4) then begin
      active_encounter_pids := 1;
      encounter_pid1 := PID_ANT;
      encounter_sid1 := SCRIPT_WANRATS;
      total_encounter_mobs := Random(3, 5);
   end
end

procedure Choose_Pid begin
    variable val;

    val := Random(1, active_encounter_pids);
    if (val == 1) then begin
        choose_enc_pid := encounter_pid1;
        choose_enc_sid := encounter_sid1;
    end else if (val == 2) then begin
        choose_enc_pid := encounter_pid2;
        choose_enc_sid := encounter_sid2;
    end else if (val == 3) then begin
        choose_enc_pid := encounter_pid3;
        choose_enc_sid := encounter_sid3;
    end else if (val == 4) then begin
        choose_enc_pid := encounter_pid4;
        choose_enc_sid := encounter_sid4;
    end else if (val == 5) then begin
        choose_enc_pid := encounter_pid5;
        choose_enc_sid := encounter_sid5;
    end else if (val == 6) then begin
        choose_enc_pid := encounter_pid6;
        choose_enc_sid := encounter_sid6;
    end
    else begin
        choose_enc_pid := encounter_pid6;
        choose_enc_sid := encounter_sid6;
    end
end

procedure placeCritter(variable pid, variable sid, variable baseTile) begin
   variable tile;
   variable obj;
   variable i;

   if (pid >= 1) then begin
      tile := tile_num_in_direction(baseTile, Random(0, 5), Random(1, 3));

      obj := create_object_sid(pid, 0, 0, sid);
      critter_attempt_placement(obj, tile, 1);
      obj_rotate(obj, random(0, 5));

      while ((tile_distance(tile_num(obj),baseTile) > 5) and (i < 4)) do begin
         tile := tile_num_in_direction(baseTile, Random(0, 5), Random(1, 2));
         debug_msg("tile_num == "+tile);
         i+=1;
      end

      if ((i >= 4) and (tile > 0)) then begin
         critter_attempt_placement(obj,baseTile,1);
      end

      if (tile_distance(tile_num(obj),baseTile) > 5) then begin
         destroy_object(obj);
         debug_msg("Couldn't find Safe spot. Destroying Ptr.");
      end
   end
   else begin
      debug_msg("ERROR: Pid < 1. Pid == "+pid+".");
   end
end

procedure placeScenery begin
   // TODO: Improve this shit
   if (Active_Scenery_List >= 1) then begin
      Scenery_Creation := array_random_value(Scenery1_List);
      Scenery_Creation := create_object_sid(Scenery_Creation, 0, 0, Scenery1_Script);
      Scenery_Creation_Hex := tile_num_in_direction(i, random(0, 5), Scenery1_Range);
      critter_attempt_placement(Scenery_Creation, Scenery_Creation_Hex, 1);
   end
   if (Active_Scenery_List >= 2) then begin
      Scenery_Creation := array_random_value(Scenery2_List);
      Scenery_Creation := create_object_sid(Scenery_Creation, 0, 0, Scenery2_Script);
      Scenery_Creation_Hex := tile_num_in_direction(i, random(0, 5), Scenery2_Range);
      critter_attempt_placement(Scenery_Creation, Scenery_Creation_Hex, 1);
   end
   if (Active_Scenery_List >= 3) then begin
      Scenery_Creation := array_random_value(Scenery3_List);
      Scenery_Creation := create_object_sid(Scenery_Creation, 0, 0, Scenery3_Script);
      Scenery_Creation_Hex := tile_num_in_direction(i, random(0, 5), Scenery3_Range);
      critter_attempt_placement(Scenery_Creation, Scenery_Creation_Hex, 1);
   end
end

/****************************************
   Define the scenery inside the cavern
****************************************/
procedure Choose_Cave_Type begin
   variable
      count,
      chance;

   if (SceneryPos_List > 0) then begin
      Choose_Scenery := random(1, 10);
      Active_Scenery_List := 1;

      // DEBUG:
      //Choose_Scenery := 2;

      //--- Gold
      if (Choose_Scenery == 1) then begin
         set_gold_mine;

         foreach (i in SceneryPos_List) begin
            if (random(0, 2) == 1) then begin
               count := random(1, 8);
               while (count > 0) do begin
                  count--;
                  Scenery1_Range := random(0, 4);
                  Scenery1_List := [PID_GOLD_NUGGET];

                  Scenery_Chance := random(1, 100);
                  if (Scenery_Chance <= 25) then begin
                     Active_Scenery_List := 2;
                     Scenery2_Range := random(0, 4);
                     Scenery2_List := [PID_ROCK];
                  end

                  if (Scenery_Chance <= 10) then begin
                     Active_Scenery_List := 3;
                     Scenery3_Range := random(0, 4);
                     Scenery3_List := [PID_SHOVEL, PID_FLARE, PID_HUNTING_RIFLE, PID_10MM_PISTOL];
                  end
                  call placeScenery;
               end
            end
         end
      end // GOLD END

      //--- Toxic Barrels
      else if (Choose_Scenery >= 2 and Choose_Scenery <= 3) then begin
         set_toxic_cave;

         foreach (i in SceneryPos_List) begin
            if (random(0, 100) > 15) then begin
               count := random(3, 6);
               while (count > 0) do begin
                  count--;
                  Scenery1_Range := random(0, 2);
                  Scenery1_List := [PID_BARREL_TOXIC_EMPTY, PID_BARREL_TOXIC_EMPTY,
                                    PID_BARREL_TOXIC_FULL, PID_BARREL_TOXIC_FULL, PID_BARREL_TOXIC_FULL, PID_BARREL_TOXIC_FULL,
                                    PID_BARREL_ALT_1,
                                    PID_BARREL_STACK_2];

                  Scenery_Chance := random(1, 100);
                  if (Scenery_Chance <= 85) then begin
                     Active_Scenery_List := 2;
                     Scenery2_Range := random(0, 1);
                     Scenery2_Script := SCRIPT_KTGOO;
                     Scenery2_List := [PID_RAD_GOO_1, PID_RAD_GOO_3, PID_RAD_GOO_3, PID_RAD_GOO_4, PID_RAD_GOO_4];
                  end
                  call placeScenery;
               end
            end
         end

         // Add Mr.Handy
         Scenery_Chance := random(1, 100);
         if (Scenery_Chance <= 15) then begin
            Items_List := [PID_SMALL_ENERGY_CELL, PID_MICRO_FUSION_CELL, PID_FLAMETHROWER_FUEL];
            Scenery_Creation_Hex := array_random_value(SceneryPos_List);

            Critter := create_object(PID_MRHANDY, 0, 0);
            critter_attempt_placement(Critter, Scenery_Creation_Hex, 1);
            obj_rotate(Critter, random(0,5));
            kill_critter(Critter, ANIM_exploded_to_nothing_sf);
            Item := array_random_value(Items_List);
            add_obj_to_inven(Critter, create_object(Item, i, 1));
         end
      end // TOXIC BARRELS END

      // Abandoned hideout
      else if (Choose_Scenery >= 4 and Choose_Scenery <= 5) then begin
         set_hideout_1;

         foreach (i in SceneryPos_List) begin
            if (random(0, 100) > 10) then begin
               count := 1;
               while (count > 0) do begin
                  count--;
                  Scenery1_Range := random(0, 2);
                  Scenery1_List := [PID_MATTRESS_1, PID_MATTRESS_2, PID_BED_1, PID_BED_2];

                  Scenery_Chance := random(1, 100);
                  if (Scenery_Chance <= 15) then begin
                     Active_Scenery_List := 2;
                     Scenery2_Range := random(0, 3);
                     Scenery2_List := [PID_ARMCHAIR_1, PID_ARMCHAIR_2, PID_OLD_CHAIR,
                                       PID_METAL_BARREL_1, PID_TRASH_1, PID_TRASH_2, PID_TRASH_3, PID_TRASH_4,
                                       PID_POT, PID_JUNK, PID_WOODEN_TABLE_1];
                  end
                  call placeScenery;
               end
            end
         end
      end // ABANDONED HIDEOUT END

      // Dead Bodies
      else if (Choose_Scenery == 6) then begin
         set_dead_bodies;

         Critter_spawn_hex := array_random_value(Area_List);
         i := Critter_spawn_hex; // Remember the position for placeScenery()
         Outer_ring := 6;
         Inner_ring := 1;
         Critter_script := -1;
         Scenery1_List := [PID_PEASANT_BLACK, PID_PEASANT_BLACK, PID_MERCHANT, PID_PEASANT_YELLOW_FEMALE, PID_LEATHER_ARMOR_MALE, PID_ZOMBIE_GUARD, PID_MERCHANT];
         foreach (Item in Scenery1_List) begin
            Scenery_Chance := random(1, 100);
            if (Scenery_Chance <= 95) then begin
               spawn_dead_critter(Item, Critter_script, random(48, 57));
               move_to(Critter, tile_num(Critter), 1);
               if (random(0,3) == 1) then item_caps_adjust(Critter, fortune_finder(random(1, 25)));
            end
         end

         Scenery1_List := [PID_BONES_1, PID_BONES_2,
                           PID_SPEAR, PID_KNIFE, PID_KNIFE, PID_SLEDGEHAMMER, PID_CROWBAR,
                           PID_44_FMJ_MAGNUM, PID_10MM_AP, PID_SHOTGUN_SHELLS,
                           PID_DYNAMITE,
                           PID_BOTTLE_CAPS, PID_BOTTLE_CAPS, PID_BOTTLE_CAPS, PID_BOTTLE_CAPS, PID_BOTTLE_CAPS, PID_BOTTLE_CAPS,
                           PID_BEER];
         foreach (Item in Scenery1_List) begin
            Scenery1_Range := random(0, 4);
            Scenery_Chance := random(1, 100);
            if (Scenery_Chance > 50) then call placeScenery;
         end
      end // DEAD BODIES END
   end
end

/****************************************
   Load random container
****************************************/
procedure LoadChests begin
   variable
      container,
      container_type,
      count;

   Items_List := [ PID_ROCK, PID_ROPE, PID_FLARE, PID_STIMPAK,
                   PID_10MM_JHP, PID_10MM_AP, PID_223_FMJ, PID_44_MAGNUM_JHP, PID_MICRO_FUSION_CELL, PID_SMALL_ENERGY_CELL,
                   PID_SPEAR, PID_KNIFE, PID_THROWING_KNIFE, PID_CATTLE_PROD ];

   i := array_random_value(Chest_List); // Only one random chest for now
   //foreach (i in Chest_List) begin
      container_type := [PID_CHEST, PID_BAG, PID_BACKPACK, PID_BROWN_BAG];
      container_type := array_random_value(container_type);
      container := create_object(container_type, i, 1);
      count := random(1, 4);
      if (container) then begin
         while (count > 0) do begin
            count--;
            Item := array_random_value(Items_List);
            add_obj_to_inven(container, create_object(Item, i, 1));
         end
         if (random(0, 1) == 1) then
            item_caps_adjust(container, fortune_finder(10 * Random(1, dude_luck) + random(0, 9)));
      end

      // Rubber Boots
      if cave_is_toxic then begin
         if (random(0, 2) == 1) then
            add_obj_to_inven(container, create_object(PID_RUBBER_BOOTS, 0, 1));
      end
   //end
end


#endif // CVGENENC_H
